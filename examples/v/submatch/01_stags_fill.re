// re2v $INPUT -o $OUTPUT

import arrays
import os
import strings

const bufsize = 4096
const tag_none = -1

struct State {
    file os.File
mut:
    buf  []u8
    cur  int
    mar  int
    tok  int
    lim  int
    // Tag variables must be part of the lexer state passed to YYFILL.
    // They don't correspond to tags and should be autogenerated by re2c.
    /*!stags:re2c format = "\t@@ int\n"; */
    eof  bool
}

struct SemVer {
    major int
    minor int
    patch int
}

fn s2n(s []u8) int { // convert pre-parsed string to number
    mut n := 0
    for c in s { n = n * 10 + int(c - 48) }
    return n
}

fn fill(mut st &State) int {
    if st.eof { return -1 } // unexpected EOF

    // Error: lexeme too long. In real life can reallocate a larger buffer.
    if st.tok < 1 { return -2 }

    // Shift buffer contents (discard everything up to the current token).
    copy(mut &st.buf, st.buf[st.tok..st.lim])
    st.cur -= st.tok
    st.mar -= st.tok
    st.lim -= st.tok
    // Tag variables need to be shifted like other input positions. The check
    // for -1 is only needed if some tags are nested inside of alternative or
    // repetition, so that they can have -1 value.
    /*!stags:re2c format = "\tif st.@@ != -1 { st.@@ -= st.tok }\n"; */
    st.tok = 0

    // Fill free space at the end of buffer with new data from file.
    pos := st.file.tell() or { 0 }
    if n := st.file.read_bytes_into(u64(pos), mut st.buf[st.lim..bufsize]) {
        st.lim += n
    }
    st.buf[st.lim] = 0 // append sentinel symbol

    // If read less than expected, this is the end of input.
    st.eof = st.lim < bufsize

    return 0
}

fn parse(mut st &State) ?[]SemVer {
    // User-defined local variables that store final tag values. They are
    // different from tag variables autogenerated with `stags:re2c`, as
    // they are set at the end of match and used only in semantic actions.
    mut t1, mut t2, mut t3, mut t4 := tag_none, tag_none, tag_none, tag_none
    mut vers := []SemVer{}
loop:
    st.tok = st.cur
    /*!re2c
        re2c:define:YYCTYPE     = u8;
        re2c:define:YYPEEK      = "st.buf[st.cur]";
        re2c:define:YYSKIP      = "st.cur += 1";
        re2c:define:YYBACKUP    = "st.mar = st.cur";
        re2c:define:YYRESTORE   = "st.cur = st.mar";
        re2c:define:YYLESSTHAN  = "st.lim <= st.cur";
        re2c:define:YYFILL      = "fill(mut st) == 0";
        re2c:define:YYSTAGP     = "@@{tag} = st.cur";
        re2c:define:YYSTAGN     = "@@{tag} = -1";
        re2c:define:YYSHIFTSTAG = "@@{tag} += @@{shift}";
        re2c:tags = 1;
        re2c:tags:expression = "st.@@";
        re2c:eof = 0;

        num = [0-9]+;

        num @t1 "." @t2 num @t3 ("." @t4 num)? [\n] {
            ver := SemVer {
                major: s2n(st.buf[st.tok..t1]),
                minor: s2n(st.buf[t2..t3]),
                patch: if t4 == -1 { 0 } else { s2n(st.buf[t4..st.cur - 1]) }
            }
            vers = arrays.concat(vers, ver)
            unsafe { goto loop }
        }
        $ { return vers }
        * { return none }
    */
}

fn main() {
    fname := "input"
    content := "1.22.333\n";

    // Prepare input file: a few times the size of the buffer, containing
    // strings with zeroes and escaped quotes.
    mut fw := os.create(fname)!
    fw.write_string(strings.repeat_string(content, bufsize))!
    fw.close()

    // Prepare lexer state: all offsets are at the end of buffer.
    mut fr := os.open(fname)!
    mut st := &State{
        file: fr,
        // Sentinel at `lim` offset is set to zero, which triggers YYFILL.
        buf:  []u8{len: bufsize + 1},
        cur:  bufsize,
        mar:  bufsize,
        tok:  bufsize,
        lim:  bufsize,
        eof:  false,
    }

    // Run the lexer.
    expect := []SemVer{len: bufsize, init: SemVer{1, 22, 333}}
    result := parse(mut st) or { panic("parse failed") }
    if result != expect { panic("error") }

    // Cleanup: remove input file.
    fr.close()
    os.rm(fname)!
}
