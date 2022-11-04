// re2c $INPUT -o $OUTPUT -8 --encoding-policy substitute
#include <stdio.h>
#include "utf8.h"
#define YYCTYPE unsigned char
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
So:
	/*!re2c
		re2c:yyfill:enable = 0;
		So = [\xa6-\xa6\xa9-\xa9\xae-\xae\xb0-\xb0\u0482-\u0482\u058d-\u058e\u060e-\u060f\u06de-\u06de\u06e9-\u06e9\u06fd-\u06fe\u07f6-\u07f6\u09fa-\u09fa\u0b70-\u0b70\u0bf3-\u0bf8\u0bfa-\u0bfa\u0c7f-\u0c7f\u0d4f-\u0d4f\u0d79-\u0d79\u0f01-\u0f03\u0f13-\u0f13\u0f15-\u0f17\u0f1a-\u0f1f\u0f34-\u0f34\u0f36-\u0f36\u0f38-\u0f38\u0fbe-\u0fc5\u0fc7-\u0fcc\u0fce-\u0fcf\u0fd5-\u0fd8\u109e-\u109f\u1390-\u1399\u166d-\u166d\u1940-\u1940\u19de-\u19ff\u1b61-\u1b6a\u1b74-\u1b7c\u2100-\u2101\u2103-\u2106\u2108-\u2109\u2114-\u2114\u2116-\u2117\u211e-\u2123\u2125-\u2125\u2127-\u2127\u2129-\u2129\u212e-\u212e\u213a-\u213b\u214a-\u214a\u214c-\u214d\u214f-\u214f\u218a-\u218b\u2195-\u2199\u219c-\u219f\u21a1-\u21a2\u21a4-\u21a5\u21a7-\u21ad\u21af-\u21cd\u21d0-\u21d1\u21d3-\u21d3\u21d5-\u21f3\u2300-\u2307\u230c-\u231f\u2322-\u2328\u232b-\u237b\u237d-\u239a\u23b4-\u23db\u23e2-\u2426\u2440-\u244a\u249c-\u24e9\u2500-\u25b6\u25b8-\u25c0\u25c2-\u25f7\u2600-\u266e\u2670-\u2767\u2794-\u27bf\u2800-\u28ff\u2b00-\u2b2f\u2b45-\u2b46\u2b4d-\u2b73\u2b76-\u2b95\u2b98-\u2bff\u2ce5-\u2cea\u2e80-\u2e99\u2e9b-\u2ef3\u2f00-\u2fd5\u2ff0-\u2ffb\u3004-\u3004\u3012-\u3013\u3020-\u3020\u3036-\u3037\u303e-\u303f\u3190-\u3191\u3196-\u319f\u31c0-\u31e3\u3200-\u321e\u322a-\u3247\u3250-\u3250\u3260-\u327f\u328a-\u32b0\u32c0-\u33ff\u4dc0-\u4dff\ua490-\ua4c6\ua828-\ua82b\ua836-\ua837\ua839-\ua839\uaa77-\uaa79\ufdfd-\ufdfd\uffe4-\uffe4\uffe8-\uffe8\uffed-\uffee\ufffc-\ufffd\U00010137-\U0001013f\U00010179-\U00010189\U0001018c-\U0001018e\U00010190-\U0001019b\U000101a0-\U000101a0\U000101d0-\U000101fc\U00010877-\U00010878\U00010ac8-\U00010ac8\U0001173f-\U0001173f\U00011fd5-\U00011fdc\U00011fe1-\U00011ff1\U00016b3c-\U00016b3f\U00016b45-\U00016b45\U0001bc9c-\U0001bc9c\U0001d000-\U0001d0f5\U0001d100-\U0001d126\U0001d129-\U0001d164\U0001d16a-\U0001d16c\U0001d183-\U0001d184\U0001d18c-\U0001d1a9\U0001d1ae-\U0001d1e8\U0001d200-\U0001d241\U0001d245-\U0001d245\U0001d300-\U0001d356\U0001d800-\U0001d9ff\U0001da37-\U0001da3a\U0001da6d-\U0001da74\U0001da76-\U0001da83\U0001da85-\U0001da86\U0001e14f-\U0001e14f\U0001ecac-\U0001ecac\U0001ed2e-\U0001ed2e\U0001f000-\U0001f02b\U0001f030-\U0001f093\U0001f0a0-\U0001f0ae\U0001f0b1-\U0001f0bf\U0001f0c1-\U0001f0cf\U0001f0d1-\U0001f0f5\U0001f110-\U0001f16c\U0001f170-\U0001f1ac\U0001f1e6-\U0001f202\U0001f210-\U0001f23b\U0001f240-\U0001f248\U0001f250-\U0001f251\U0001f260-\U0001f265\U0001f300-\U0001f3fa\U0001f400-\U0001f6d5\U0001f6e0-\U0001f6ec\U0001f6f0-\U0001f6fa\U0001f700-\U0001f773\U0001f780-\U0001f7d8\U0001f7e0-\U0001f7eb\U0001f800-\U0001f80b\U0001f810-\U0001f847\U0001f850-\U0001f859\U0001f860-\U0001f887\U0001f890-\U0001f8ad\U0001f900-\U0001f90b\U0001f90d-\U0001f971\U0001f973-\U0001f976\U0001f97a-\U0001f9a2\U0001f9a5-\U0001f9aa\U0001f9ae-\U0001f9ca\U0001f9cd-\U0001fa53\U0001fa60-\U0001fa6d\U0001fa70-\U0001fa73\U0001fa78-\U0001fa7a\U0001fa80-\U0001fa82\U0001fa90-\U0001fa95];
		So { goto So; }
		* { return YYCURSOR == limit; }
	*/
}
static const unsigned int chars_So [] = {0xa6,0xa6,  0xa9,0xa9,  0xae,0xae,  0xb0,0xb0,  0x482,0x482,  0x58d,0x58e,  0x60e,0x60f,  0x6de,0x6de,  0x6e9,0x6e9,  0x6fd,0x6fe,  0x7f6,0x7f6,  0x9fa,0x9fa,  0xb70,0xb70,  0xbf3,0xbf8,  0xbfa,0xbfa,  0xc7f,0xc7f,  0xd4f,0xd4f,  0xd79,0xd79,  0xf01,0xf03,  0xf13,0xf13,  0xf15,0xf17,  0xf1a,0xf1f,  0xf34,0xf34,  0xf36,0xf36,  0xf38,0xf38,  0xfbe,0xfc5,  0xfc7,0xfcc,  0xfce,0xfcf,  0xfd5,0xfd8,  0x109e,0x109f,  0x1390,0x1399,  0x166d,0x166d,  0x1940,0x1940,  0x19de,0x19ff,  0x1b61,0x1b6a,  0x1b74,0x1b7c,  0x2100,0x2101,  0x2103,0x2106,  0x2108,0x2109,  0x2114,0x2114,  0x2116,0x2117,  0x211e,0x2123,  0x2125,0x2125,  0x2127,0x2127,  0x2129,0x2129,  0x212e,0x212e,  0x213a,0x213b,  0x214a,0x214a,  0x214c,0x214d,  0x214f,0x214f,  0x218a,0x218b,  0x2195,0x2199,  0x219c,0x219f,  0x21a1,0x21a2,  0x21a4,0x21a5,  0x21a7,0x21ad,  0x21af,0x21cd,  0x21d0,0x21d1,  0x21d3,0x21d3,  0x21d5,0x21f3,  0x2300,0x2307,  0x230c,0x231f,  0x2322,0x2328,  0x232b,0x237b,  0x237d,0x239a,  0x23b4,0x23db,  0x23e2,0x2426,  0x2440,0x244a,  0x249c,0x24e9,  0x2500,0x25b6,  0x25b8,0x25c0,  0x25c2,0x25f7,  0x2600,0x266e,  0x2670,0x2767,  0x2794,0x27bf,  0x2800,0x28ff,  0x2b00,0x2b2f,  0x2b45,0x2b46,  0x2b4d,0x2b73,  0x2b76,0x2b95,  0x2b98,0x2bff,  0x2ce5,0x2cea,  0x2e80,0x2e99,  0x2e9b,0x2ef3,  0x2f00,0x2fd5,  0x2ff0,0x2ffb,  0x3004,0x3004,  0x3012,0x3013,  0x3020,0x3020,  0x3036,0x3037,  0x303e,0x303f,  0x3190,0x3191,  0x3196,0x319f,  0x31c0,0x31e3,  0x3200,0x321e,  0x322a,0x3247,  0x3250,0x3250,  0x3260,0x327f,  0x328a,0x32b0,  0x32c0,0x33ff,  0x4dc0,0x4dff,  0xa490,0xa4c6,  0xa828,0xa82b,  0xa836,0xa837,  0xa839,0xa839,  0xaa77,0xaa79,  0xfdfd,0xfdfd,  0xffe4,0xffe4,  0xffe8,0xffe8,  0xffed,0xffee,  0xfffc,0xfffd,  0x10137,0x1013f,  0x10179,0x10189,  0x1018c,0x1018e,  0x10190,0x1019b,  0x101a0,0x101a0,  0x101d0,0x101fc,  0x10877,0x10878,  0x10ac8,0x10ac8,  0x1173f,0x1173f,  0x11fd5,0x11fdc,  0x11fe1,0x11ff1,  0x16b3c,0x16b3f,  0x16b45,0x16b45,  0x1bc9c,0x1bc9c,  0x1d000,0x1d0f5,  0x1d100,0x1d126,  0x1d129,0x1d164,  0x1d16a,0x1d16c,  0x1d183,0x1d184,  0x1d18c,0x1d1a9,  0x1d1ae,0x1d1e8,  0x1d200,0x1d241,  0x1d245,0x1d245,  0x1d300,0x1d356,  0x1d800,0x1d9ff,  0x1da37,0x1da3a,  0x1da6d,0x1da74,  0x1da76,0x1da83,  0x1da85,0x1da86,  0x1e14f,0x1e14f,  0x1ecac,0x1ecac,  0x1ed2e,0x1ed2e,  0x1f000,0x1f02b,  0x1f030,0x1f093,  0x1f0a0,0x1f0ae,  0x1f0b1,0x1f0bf,  0x1f0c1,0x1f0cf,  0x1f0d1,0x1f0f5,  0x1f110,0x1f16c,  0x1f170,0x1f1ac,  0x1f1e6,0x1f202,  0x1f210,0x1f23b,  0x1f240,0x1f248,  0x1f250,0x1f251,  0x1f260,0x1f265,  0x1f300,0x1f3fa,  0x1f400,0x1f6d5,  0x1f6e0,0x1f6ec,  0x1f6f0,0x1f6fa,  0x1f700,0x1f773,  0x1f780,0x1f7d8,  0x1f7e0,0x1f7eb,  0x1f800,0x1f80b,  0x1f810,0x1f847,  0x1f850,0x1f859,  0x1f860,0x1f887,  0x1f890,0x1f8ad,  0x1f900,0x1f90b,  0x1f90d,0x1f971,  0x1f973,0x1f976,  0x1f97a,0x1f9a2,  0x1f9a5,0x1f9aa,  0x1f9ae,0x1f9ca,  0x1f9cd,0x1fa53,  0x1fa60,0x1fa6d,  0x1fa70,0x1fa73,  0x1fa78,0x1fa7a,  0x1fa80,0x1fa82,  0x1fa90,0x1fa95,  0x0,0x0};
static unsigned int encode_utf8 (const unsigned int * ranges, unsigned int ranges_count, unsigned int * s)
{
	unsigned int * const s_start = s;
	for (unsigned int i = 0; i < ranges_count - 2; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
			s += re2c::utf8::rune_to_bytes (s, j);
	re2c::utf8::rune_to_bytes (s, ranges[ranges_count - 1]);
	return s - s_start + 1;
}

int main ()
{
	unsigned int * buffer_So = new unsigned int [24648];
	YYCTYPE * s = (YYCTYPE *) buffer_So;
	unsigned int buffer_len = encode_utf8 (chars_So, sizeof (chars_So) / sizeof (unsigned int), buffer_So);
	/* convert 32-bit code units to YYCTYPE; reuse the same buffer */
	for (unsigned int i = 0; i < buffer_len; ++i) s[i] = buffer_So[i];
	if (!scan (s, s + buffer_len))
		printf("test 'So' failed\n");
	delete [] buffer_So;
	return 0;
}
