// re2v $INPUT -o $OUTPUT

import arrays

const mtag_root = -1
const tag_none = -1

// An m-tag tree is a way to store histories with an O(1) copy operation.
// Histories naturally form a tree, as they have common start and fork at some
// point. The tree is stored as an array of pairs (tag value, link to parent).
// An m-tag is represented with a single link in the tree (array index).
struct MtagElem {
    elem int
    pred int
}
type MtagTrie = []MtagElem

// Append a single value to an m-tag history.
fn add_mtag(mut trie &MtagTrie, mtag int, value int) int {
    trie = arrays.concat(trie, MtagElem{value, mtag})
    return trie.len - 1
}

// Recursively unwind tag histories and collect version components.
fn unwind(trie MtagTrie, x int, y int, str string) []int {
    // Reached the root of the m-tag tree, stop recursion.
    if x == mtag_root && y == mtag_root {
        return []
    }

    // Unwind history further.
    mut result := unwind(trie, trie[x].pred, trie[y].pred, str)

    // Get tag values. Tag histories must have equal length.
    if x == mtag_root || y == mtag_root {
        panic("tag histories have different length")
    }
    ex := trie[x].elem
    ey := trie[y].elem

    if ex != tag_none && ey != tag_none {
        // Both tags are valid string indices, extract component.
        result = arrays.concat(result, s2n(str[ex..ey]))
    } else if !(ex == tag_none && ey == tag_none) {
        panic("both tags should be tag_none")
    }
    return result
}

fn s2n(s string) int { // convert pre-parsed string to number
    mut n := 0
    for c in s { n = n * 10 + int(c - 48) }
    return n
}

fn parse(str string) ?[]int {
    mut cur, mut mar := 0, 0
    mut trie := []MtagElem{}

    // User-defined tag variables that are available in semantic action.
    mut t1, mut t2 := tag_none, tag_none
    mut t3, mut t4 := mtag_root, mtag_root

    // Autogenerated tag variables used by the lexer to track tag values.
    /*!stags:re2c format = 'mut @@ := tag_none'; separator = "\n\t"; */
    /*!mtags:re2c format = "\tmut @@ := mtag_root\n"; */

    /*!re2c
        re2c:tags = 1;
        re2c:yyfill:enable = 0;
        re2c:define:YYCTYPE   = byte;
        re2c:define:YYPEEK    = "str[cur]";
        re2c:define:YYSKIP    = "cur += 1";
        re2c:define:YYBACKUP  = "mar = cur";
        re2c:define:YYRESTORE = "cur = mar";
        re2c:define:YYSTAGP   = "@@ = cur";
        re2c:define:YYSTAGN   = "@@ = tag_none";
        re2c:define:YYMTAGP   = "@@ = add_mtag(mut &trie, @@, cur)";
        re2c:define:YYMTAGN   = "@@ = add_mtag(mut &trie, @@, tag_none)";

        num = [0-9]+;

        @t1 num @t2 ("." #t3 num #t4)* [\x00] {
            mut ver := []int{}
            ver = arrays.concat(ver, s2n(str[t1..t2]))
            ver = arrays.append(ver, unwind(trie, t3, t4, str))
            return ver
        }
        * { return none }
    */
}

fn main() {
    test := fn (result ?[]int, expect ?[]int) {
        if r := result {
            if e := expect { if r != e { panic("expected $e, got $r") } }
        } else {
            if _ := result { panic("expected none") }
        }
    }
    test(parse("1\0"), [1])
    test(parse("1.2.3.4.5.6.7\0"), [1, 2, 3, 4, 5, 6, 7])
    test(parse("1.\0"), none)
}
