//go:generate re2go $INPUT -o $OUTPUT
package main

import "reflect"

// Maximum number of capturing groups among all rules.
/*!maxnmatch:re2c*/

type SemVer struct { major, minor, patch int }

func s2n(s string) int { // convert pre-parsed string to a number
	n := 0
	for _, c := range s { n = n*10 + int(c-'0') }
	return n
}

func parse(str string) *SemVer {
	var cur, mar int

	// Allocate memory for capturing parentheses (twice the number of groups).
	yypmatch := make([]int, YYMAXNMATCH*2)
	var yynmatch int

	// Autogenerated tag variables used by the lexer to track tag values.
	/*!stags:re2c format = '\tvar @@ int\n'; */

	/*!re2c
		re2c:yyfill:enable = 0;
		re2c:define:YYCTYPE     = byte;
		re2c:define:YYPEEK      = "str[cur]";
		re2c:define:YYSKIP      = "cur += 1";
		re2c:define:YYBACKUP    = "mar = cur";
		re2c:define:YYRESTORE   = "cur = mar";
		re2c:define:YYSETSTAGP  = "@@{tag} = cur";
		re2c:define:YYSETSTAGN  = "@@{tag} = -1";
		re2c:define:YYSHIFTSTAG = "@@{tag} += @@{shift}";
		re2c:posix-captures = 1;

		num = [0-9]+;

		(num) "." (num) ("." num)? [\x00] {
			// `yynmatch` is the number of capturing groups
			if yynmatch != 4 { panic("expected 4 submatch groups") }

			// Even `yypmatch` values are for opening parentheses, odd values
			// are for closing parentheses, the first group is the whole match.
			major := s2n(str[yypmatch[2]:yypmatch[3]])
			minor := s2n(str[yypmatch[4]:yypmatch[5]])
			patch := 0
			if yypmatch[6] != -1 { patch = s2n(str[yypmatch[6]+1:yypmatch[7]]) }

			return &SemVer{major, minor, patch}
		}
		* { return nil }
	*/
}

func main() {
	assert_eq := func(x, y *SemVer) {
		if !reflect.DeepEqual(x, y) { panic("error") }
	}
	assert_eq(parse("23.34\000"), &SemVer{23, 34, 0})
	assert_eq(parse("1.2.9999\000"), &SemVer{1, 2, 9999})
	assert_eq(parse("1.a\000"), nil)
}
