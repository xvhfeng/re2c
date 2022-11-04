// re2c $INPUT -o $OUTPUT -u --encoding-policy substitute
#include <stdio.h>

#define YYCTYPE unsigned int
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
M:
	/*!re2c
		re2c:yyfill:enable = 0;
		M = [\u0300-\u036f\u0483-\u0489\u0591-\u05bd\u05bf-\u05bf\u05c1-\u05c2\u05c4-\u05c5\u05c7-\u05c7\u0610-\u061a\u064b-\u065f\u0670-\u0670\u06d6-\u06dc\u06df-\u06e4\u06e7-\u06e8\u06ea-\u06ed\u0711-\u0711\u0730-\u074a\u07a6-\u07b0\u07eb-\u07f3\u07fd-\u07fd\u0816-\u0819\u081b-\u0823\u0825-\u0827\u0829-\u082d\u0859-\u085b\u08d3-\u08e1\u08e3-\u0903\u093a-\u093c\u093e-\u094f\u0951-\u0957\u0962-\u0963\u0981-\u0983\u09bc-\u09bc\u09be-\u09c4\u09c7-\u09c8\u09cb-\u09cd\u09d7-\u09d7\u09e2-\u09e3\u09fe-\u09fe\u0a01-\u0a03\u0a3c-\u0a3c\u0a3e-\u0a42\u0a47-\u0a48\u0a4b-\u0a4d\u0a51-\u0a51\u0a70-\u0a71\u0a75-\u0a75\u0a81-\u0a83\u0abc-\u0abc\u0abe-\u0ac5\u0ac7-\u0ac9\u0acb-\u0acd\u0ae2-\u0ae3\u0afa-\u0aff\u0b01-\u0b03\u0b3c-\u0b3c\u0b3e-\u0b44\u0b47-\u0b48\u0b4b-\u0b4d\u0b56-\u0b57\u0b62-\u0b63\u0b82-\u0b82\u0bbe-\u0bc2\u0bc6-\u0bc8\u0bca-\u0bcd\u0bd7-\u0bd7\u0c00-\u0c04\u0c3e-\u0c44\u0c46-\u0c48\u0c4a-\u0c4d\u0c55-\u0c56\u0c62-\u0c63\u0c81-\u0c83\u0cbc-\u0cbc\u0cbe-\u0cc4\u0cc6-\u0cc8\u0cca-\u0ccd\u0cd5-\u0cd6\u0ce2-\u0ce3\u0d00-\u0d03\u0d3b-\u0d3c\u0d3e-\u0d44\u0d46-\u0d48\u0d4a-\u0d4d\u0d57-\u0d57\u0d62-\u0d63\u0d82-\u0d83\u0dca-\u0dca\u0dcf-\u0dd4\u0dd6-\u0dd6\u0dd8-\u0ddf\u0df2-\u0df3\u0e31-\u0e31\u0e34-\u0e3a\u0e47-\u0e4e\u0eb1-\u0eb1\u0eb4-\u0ebc\u0ec8-\u0ecd\u0f18-\u0f19\u0f35-\u0f35\u0f37-\u0f37\u0f39-\u0f39\u0f3e-\u0f3f\u0f71-\u0f84\u0f86-\u0f87\u0f8d-\u0f97\u0f99-\u0fbc\u0fc6-\u0fc6\u102b-\u103e\u1056-\u1059\u105e-\u1060\u1062-\u1064\u1067-\u106d\u1071-\u1074\u1082-\u108d\u108f-\u108f\u109a-\u109d\u135d-\u135f\u1712-\u1714\u1732-\u1734\u1752-\u1753\u1772-\u1773\u17b4-\u17d3\u17dd-\u17dd\u180b-\u180d\u1885-\u1886\u18a9-\u18a9\u1920-\u192b\u1930-\u193b\u1a17-\u1a1b\u1a55-\u1a5e\u1a60-\u1a7c\u1a7f-\u1a7f\u1ab0-\u1abe\u1b00-\u1b04\u1b34-\u1b44\u1b6b-\u1b73\u1b80-\u1b82\u1ba1-\u1bad\u1be6-\u1bf3\u1c24-\u1c37\u1cd0-\u1cd2\u1cd4-\u1ce8\u1ced-\u1ced\u1cf4-\u1cf4\u1cf7-\u1cf9\u1dc0-\u1df9\u1dfb-\u1dff\u20d0-\u20f0\u2cef-\u2cf1\u2d7f-\u2d7f\u2de0-\u2dff\u302a-\u302f\u3099-\u309a\ua66f-\ua672\ua674-\ua67d\ua69e-\ua69f\ua6f0-\ua6f1\ua802-\ua802\ua806-\ua806\ua80b-\ua80b\ua823-\ua827\ua880-\ua881\ua8b4-\ua8c5\ua8e0-\ua8f1\ua8ff-\ua8ff\ua926-\ua92d\ua947-\ua953\ua980-\ua983\ua9b3-\ua9c0\ua9e5-\ua9e5\uaa29-\uaa36\uaa43-\uaa43\uaa4c-\uaa4d\uaa7b-\uaa7d\uaab0-\uaab0\uaab2-\uaab4\uaab7-\uaab8\uaabe-\uaabf\uaac1-\uaac1\uaaeb-\uaaef\uaaf5-\uaaf6\uabe3-\uabea\uabec-\uabed\ufb1e-\ufb1e\ufe00-\ufe0f\ufe20-\ufe2f\U000101fd-\U000101fd\U000102e0-\U000102e0\U00010376-\U0001037a\U00010a01-\U00010a03\U00010a05-\U00010a06\U00010a0c-\U00010a0f\U00010a38-\U00010a3a\U00010a3f-\U00010a3f\U00010ae5-\U00010ae6\U00010d24-\U00010d27\U00010f46-\U00010f50\U00011000-\U00011002\U00011038-\U00011046\U0001107f-\U00011082\U000110b0-\U000110ba\U00011100-\U00011102\U00011127-\U00011134\U00011145-\U00011146\U00011173-\U00011173\U00011180-\U00011182\U000111b3-\U000111c0\U000111c9-\U000111cc\U0001122c-\U00011237\U0001123e-\U0001123e\U000112df-\U000112ea\U00011300-\U00011303\U0001133b-\U0001133c\U0001133e-\U00011344\U00011347-\U00011348\U0001134b-\U0001134d\U00011357-\U00011357\U00011362-\U00011363\U00011366-\U0001136c\U00011370-\U00011374\U00011435-\U00011446\U0001145e-\U0001145e\U000114b0-\U000114c3\U000115af-\U000115b5\U000115b8-\U000115c0\U000115dc-\U000115dd\U00011630-\U00011640\U000116ab-\U000116b7\U0001171d-\U0001172b\U0001182c-\U0001183a\U000119d1-\U000119d7\U000119da-\U000119e0\U000119e4-\U000119e4\U00011a01-\U00011a0a\U00011a33-\U00011a39\U00011a3b-\U00011a3e\U00011a47-\U00011a47\U00011a51-\U00011a5b\U00011a8a-\U00011a99\U00011c2f-\U00011c36\U00011c38-\U00011c3f\U00011c92-\U00011ca7\U00011ca9-\U00011cb6\U00011d31-\U00011d36\U00011d3a-\U00011d3a\U00011d3c-\U00011d3d\U00011d3f-\U00011d45\U00011d47-\U00011d47\U00011d8a-\U00011d8e\U00011d90-\U00011d91\U00011d93-\U00011d97\U00011ef3-\U00011ef6\U00016af0-\U00016af4\U00016b30-\U00016b36\U00016f4f-\U00016f4f\U00016f51-\U00016f87\U00016f8f-\U00016f92\U0001bc9d-\U0001bc9e\U0001d165-\U0001d169\U0001d16d-\U0001d172\U0001d17b-\U0001d182\U0001d185-\U0001d18b\U0001d1aa-\U0001d1ad\U0001d242-\U0001d244\U0001da00-\U0001da36\U0001da3b-\U0001da6c\U0001da75-\U0001da75\U0001da84-\U0001da84\U0001da9b-\U0001da9f\U0001daa1-\U0001daaf\U0001e000-\U0001e006\U0001e008-\U0001e018\U0001e01b-\U0001e021\U0001e023-\U0001e024\U0001e026-\U0001e02a\U0001e130-\U0001e136\U0001e2ec-\U0001e2ef\U0001e8d0-\U0001e8d6\U0001e944-\U0001e94a\U000e0100-\U000e01ef];
		M { goto M; }
		* { return YYCURSOR == limit; }
	*/
}
static const unsigned int chars_M [] = {0x300,0x36f,  0x483,0x489,  0x591,0x5bd,  0x5bf,0x5bf,  0x5c1,0x5c2,  0x5c4,0x5c5,  0x5c7,0x5c7,  0x610,0x61a,  0x64b,0x65f,  0x670,0x670,  0x6d6,0x6dc,  0x6df,0x6e4,  0x6e7,0x6e8,  0x6ea,0x6ed,  0x711,0x711,  0x730,0x74a,  0x7a6,0x7b0,  0x7eb,0x7f3,  0x7fd,0x7fd,  0x816,0x819,  0x81b,0x823,  0x825,0x827,  0x829,0x82d,  0x859,0x85b,  0x8d3,0x8e1,  0x8e3,0x903,  0x93a,0x93c,  0x93e,0x94f,  0x951,0x957,  0x962,0x963,  0x981,0x983,  0x9bc,0x9bc,  0x9be,0x9c4,  0x9c7,0x9c8,  0x9cb,0x9cd,  0x9d7,0x9d7,  0x9e2,0x9e3,  0x9fe,0x9fe,  0xa01,0xa03,  0xa3c,0xa3c,  0xa3e,0xa42,  0xa47,0xa48,  0xa4b,0xa4d,  0xa51,0xa51,  0xa70,0xa71,  0xa75,0xa75,  0xa81,0xa83,  0xabc,0xabc,  0xabe,0xac5,  0xac7,0xac9,  0xacb,0xacd,  0xae2,0xae3,  0xafa,0xaff,  0xb01,0xb03,  0xb3c,0xb3c,  0xb3e,0xb44,  0xb47,0xb48,  0xb4b,0xb4d,  0xb56,0xb57,  0xb62,0xb63,  0xb82,0xb82,  0xbbe,0xbc2,  0xbc6,0xbc8,  0xbca,0xbcd,  0xbd7,0xbd7,  0xc00,0xc04,  0xc3e,0xc44,  0xc46,0xc48,  0xc4a,0xc4d,  0xc55,0xc56,  0xc62,0xc63,  0xc81,0xc83,  0xcbc,0xcbc,  0xcbe,0xcc4,  0xcc6,0xcc8,  0xcca,0xccd,  0xcd5,0xcd6,  0xce2,0xce3,  0xd00,0xd03,  0xd3b,0xd3c,  0xd3e,0xd44,  0xd46,0xd48,  0xd4a,0xd4d,  0xd57,0xd57,  0xd62,0xd63,  0xd82,0xd83,  0xdca,0xdca,  0xdcf,0xdd4,  0xdd6,0xdd6,  0xdd8,0xddf,  0xdf2,0xdf3,  0xe31,0xe31,  0xe34,0xe3a,  0xe47,0xe4e,  0xeb1,0xeb1,  0xeb4,0xebc,  0xec8,0xecd,  0xf18,0xf19,  0xf35,0xf35,  0xf37,0xf37,  0xf39,0xf39,  0xf3e,0xf3f,  0xf71,0xf84,  0xf86,0xf87,  0xf8d,0xf97,  0xf99,0xfbc,  0xfc6,0xfc6,  0x102b,0x103e,  0x1056,0x1059,  0x105e,0x1060,  0x1062,0x1064,  0x1067,0x106d,  0x1071,0x1074,  0x1082,0x108d,  0x108f,0x108f,  0x109a,0x109d,  0x135d,0x135f,  0x1712,0x1714,  0x1732,0x1734,  0x1752,0x1753,  0x1772,0x1773,  0x17b4,0x17d3,  0x17dd,0x17dd,  0x180b,0x180d,  0x1885,0x1886,  0x18a9,0x18a9,  0x1920,0x192b,  0x1930,0x193b,  0x1a17,0x1a1b,  0x1a55,0x1a5e,  0x1a60,0x1a7c,  0x1a7f,0x1a7f,  0x1ab0,0x1abe,  0x1b00,0x1b04,  0x1b34,0x1b44,  0x1b6b,0x1b73,  0x1b80,0x1b82,  0x1ba1,0x1bad,  0x1be6,0x1bf3,  0x1c24,0x1c37,  0x1cd0,0x1cd2,  0x1cd4,0x1ce8,  0x1ced,0x1ced,  0x1cf4,0x1cf4,  0x1cf7,0x1cf9,  0x1dc0,0x1df9,  0x1dfb,0x1dff,  0x20d0,0x20f0,  0x2cef,0x2cf1,  0x2d7f,0x2d7f,  0x2de0,0x2dff,  0x302a,0x302f,  0x3099,0x309a,  0xa66f,0xa672,  0xa674,0xa67d,  0xa69e,0xa69f,  0xa6f0,0xa6f1,  0xa802,0xa802,  0xa806,0xa806,  0xa80b,0xa80b,  0xa823,0xa827,  0xa880,0xa881,  0xa8b4,0xa8c5,  0xa8e0,0xa8f1,  0xa8ff,0xa8ff,  0xa926,0xa92d,  0xa947,0xa953,  0xa980,0xa983,  0xa9b3,0xa9c0,  0xa9e5,0xa9e5,  0xaa29,0xaa36,  0xaa43,0xaa43,  0xaa4c,0xaa4d,  0xaa7b,0xaa7d,  0xaab0,0xaab0,  0xaab2,0xaab4,  0xaab7,0xaab8,  0xaabe,0xaabf,  0xaac1,0xaac1,  0xaaeb,0xaaef,  0xaaf5,0xaaf6,  0xabe3,0xabea,  0xabec,0xabed,  0xfb1e,0xfb1e,  0xfe00,0xfe0f,  0xfe20,0xfe2f,  0x101fd,0x101fd,  0x102e0,0x102e0,  0x10376,0x1037a,  0x10a01,0x10a03,  0x10a05,0x10a06,  0x10a0c,0x10a0f,  0x10a38,0x10a3a,  0x10a3f,0x10a3f,  0x10ae5,0x10ae6,  0x10d24,0x10d27,  0x10f46,0x10f50,  0x11000,0x11002,  0x11038,0x11046,  0x1107f,0x11082,  0x110b0,0x110ba,  0x11100,0x11102,  0x11127,0x11134,  0x11145,0x11146,  0x11173,0x11173,  0x11180,0x11182,  0x111b3,0x111c0,  0x111c9,0x111cc,  0x1122c,0x11237,  0x1123e,0x1123e,  0x112df,0x112ea,  0x11300,0x11303,  0x1133b,0x1133c,  0x1133e,0x11344,  0x11347,0x11348,  0x1134b,0x1134d,  0x11357,0x11357,  0x11362,0x11363,  0x11366,0x1136c,  0x11370,0x11374,  0x11435,0x11446,  0x1145e,0x1145e,  0x114b0,0x114c3,  0x115af,0x115b5,  0x115b8,0x115c0,  0x115dc,0x115dd,  0x11630,0x11640,  0x116ab,0x116b7,  0x1171d,0x1172b,  0x1182c,0x1183a,  0x119d1,0x119d7,  0x119da,0x119e0,  0x119e4,0x119e4,  0x11a01,0x11a0a,  0x11a33,0x11a39,  0x11a3b,0x11a3e,  0x11a47,0x11a47,  0x11a51,0x11a5b,  0x11a8a,0x11a99,  0x11c2f,0x11c36,  0x11c38,0x11c3f,  0x11c92,0x11ca7,  0x11ca9,0x11cb6,  0x11d31,0x11d36,  0x11d3a,0x11d3a,  0x11d3c,0x11d3d,  0x11d3f,0x11d45,  0x11d47,0x11d47,  0x11d8a,0x11d8e,  0x11d90,0x11d91,  0x11d93,0x11d97,  0x11ef3,0x11ef6,  0x16af0,0x16af4,  0x16b30,0x16b36,  0x16f4f,0x16f4f,  0x16f51,0x16f87,  0x16f8f,0x16f92,  0x1bc9d,0x1bc9e,  0x1d165,0x1d169,  0x1d16d,0x1d172,  0x1d17b,0x1d182,  0x1d185,0x1d18b,  0x1d1aa,0x1d1ad,  0x1d242,0x1d244,  0x1da00,0x1da36,  0x1da3b,0x1da6c,  0x1da75,0x1da75,  0x1da84,0x1da84,  0x1da9b,0x1da9f,  0x1daa1,0x1daaf,  0x1e000,0x1e006,  0x1e008,0x1e018,  0x1e01b,0x1e021,  0x1e023,0x1e024,  0x1e026,0x1e02a,  0x1e130,0x1e136,  0x1e2ec,0x1e2ef,  0x1e8d0,0x1e8d6,  0x1e944,0x1e94a,  0xe0100,0xe01ef,  0x0,0x0};
static unsigned int encode_utf32 (const unsigned int * ranges, unsigned int ranges_count, unsigned int * s)
{
	unsigned int * const s_start = s;
	for (unsigned int i = 0; i < ranges_count; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
			*s++ = j;
	return s - s_start;
}

int main ()
{
	unsigned int * buffer_M = new unsigned int [2269];
	YYCTYPE * s = (YYCTYPE *) buffer_M;
	unsigned int buffer_len = encode_utf32 (chars_M, sizeof (chars_M) / sizeof (unsigned int), buffer_M);
	/* convert 32-bit code units to YYCTYPE; reuse the same buffer */
	for (unsigned int i = 0; i < buffer_len; ++i) s[i] = buffer_M[i];
	if (!scan (s, s + buffer_len))
		printf("test 'M' failed\n");
	delete [] buffer_M;
	return 0;
}
