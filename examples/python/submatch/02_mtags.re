# re2py $INPUT -o $OUTPUT

NONE = -1

def parse(str):
    cur = 0
    /*!mtags:re2c format = '\n    @@ = []'; */ # autogenerated tag variables
    /*!re2c
        re2c:define:YYPEEK     = "str[cur]";
        re2c:define:YYSKIP     = "cur += 1";
        re2c:define:YYBACKUP   = "mar = cur";
        re2c:define:YYRESTORE  = "cur = mar";
        re2c:define:YYSETSTAGP = "@@ = cur";
        re2c:define:YYSETSTAGN = "@@ = NONE";
        re2c:define:YYSETMTAGP = "@@.append(cur)";
        re2c:define:YYSETMTAGN = ""; // do nothing
        re2c:yyfill:enable = 0;
        re2c:tags = 1;
        re2c:indent:top = 1;

        num = [0-9]+;

        @t1 num @t2 ("." #t3 num #t4)* [\x00] {
            vers = [int(str[t1:t2])]
            for i in range(len(t3)):
                vers.append(int(str[t3[i]:t4[i]]))
            return vers
        }
        * { return None }
    */

assert parse(b"1\0") == [1]
assert parse(b"1.2.3.4.5.6.7\0") == [1, 2, 3, 4, 5, 6, 7]
assert parse(b"1.2.\0") == None
