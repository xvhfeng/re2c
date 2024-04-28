// re2d $INPUT -o $OUTPUT
module main;

// Maximum number of capturing groups among all rules.
/*!maxnmatch:re2c*/

struct SemVer { int major, minor, patch; };

private int s2n(const(char)* s, const(char)* e) { // pre-parsed string to number
    int n = 0;
    for (; s < e; ++s) n = n * 10 + (*s - '0');
    return n;
}

private bool lex(const(char)* str, ref SemVer ver) {
    const(char)* cur = str, mar;

    // Allocate memory for capturing parentheses (twice the number of groups).
    const(char)*[YYMAXNMATCH * 2] yypmatch;
    size_t yynmatch;

    // Autogenerated tag variables used by the lexer to track tag values.
    /*!stags:re2c format = 'const(char)* @@;\n'; */

    /*!re2c
        re2c:yyfill:enable = 0;
        re2c:posix-captures = 1;
        re2c:define:YYCTYPE     = "char";
        re2c:define:YYPEEK      = "*cur";
        re2c:define:YYSKIP      = "++cur;";
        re2c:define:YYBACKUP    = "mar = cur;";
        re2c:define:YYRESTORE   = "cur = mar;";
        re2c:define:YYSTAGP     = "@@{tag} = cur;";
        re2c:define:YYSTAGN     = "@@{tag} = null;";
        re2c:define:YYSHIFTSTAG = "@@{tag} += @@{shift};";

        num = [0-9]+;

        (num) "." (num) ("." num)? [\x00] {
            // `yynmatch` is the number of capturing groups
            assert(yynmatch == 4);
            // Even `yypmatch` values are for opening parentheses, odd values
            // are for closing parentheses, the first group is the whole match.
            ver.major = s2n(yypmatch[2], yypmatch[3]);
            ver.minor = s2n(yypmatch[4], yypmatch[5]);
            ver.patch = yypmatch[6] ? s2n(yypmatch[6] + 1, yypmatch[7]) : 0;
            return true;
        }
        * { return false; }
    */
}

void main() {
    SemVer v;
    assert(lex("23.34", v) && v.major == 23 && v.minor == 34 && v.patch == 0);
    assert(lex("1.2.999", v) && v.major == 1 && v.minor == 2 && v.patch == 999);
    assert(!lex("1.a", v));
}
