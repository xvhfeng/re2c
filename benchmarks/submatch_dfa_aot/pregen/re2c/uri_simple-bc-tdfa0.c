/* Generated by re2c 2.0.3 */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/uri_simple.re"
#include <assert.h>
#include <stdlib.h>
#include "common.h"

#line 15 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"


typedef struct taglist_t {
    struct taglist_t *pred;
    long dist;
} taglist_t;

typedef struct taglistpool_t {
    taglist_t *head;
    taglist_t *next;
    taglist_t *last;
} taglistpool_t;

typedef struct {
    char *buf;
    char *lim;
    char *cur;
    char *mar;
    char *tok;
    char *yyt1;
char *yyt10;
char *yyt11;
char *yyt12;
char *yyt13;
char *yyt14;
char *yyt15;
char *yyt16;
char *yyt17;
char *yyt18;
char *yyt19;
char *yyt2;
char *yyt3;
char *yyt4;
char *yyt5;
char *yyt6;
char *yyt7;
char *yyt8;
char *yyt9;

    
    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    
}

static inline void taglistpool_init(taglistpool_t *tlp)
{
    static const unsigned size = 1024 * 1024;
    tlp->head = (taglist_t*)malloc(size * sizeof(taglist_t));
    tlp->next = tlp->head;
    tlp->last = tlp->head + size;
}

static inline void taglistpool_free(taglistpool_t *tlp)
{
    free(tlp->head);
    tlp->head = tlp->next = tlp->last = NULL;
}

static inline void taglist(taglist_t **ptl, const char *b, const char *t, taglistpool_t *tlp)
{
#ifdef GROW_MTAG_LIST
    if (tlp->next >= tlp->last) {
        const unsigned size = tlp->last - tlp->head;
        taglist_t *head = (taglist_t*)malloc(2 * size * sizeof(taglist_t));
        memcpy(head, tlp->head, size * sizeof(taglist_t));
        free(tlp->head);
        tlp->head = head;
        tlp->next = head + size;
        tlp->last = head + size * 2;
    }
#else
    assert(tlp->next < tlp->last);
#endif
    taglist_t *tl = tlp->next++;
    tl->pred = *ptl;
    tl->dist = t - b;
    *ptl = tl;
}

#line 4 "../../../benchmarks/submatch_dfa_aot/src/re2c/include_bc/fill.re"


#define YYMAXFILL 5


static inline int fill(input_t *in, size_t need)
{
    size_t free;
    if (in->eof) return 1;

    free = in->tok - in->buf;
    assert(free >= need);

    memmove(in->buf, in->tok, in->lim - in->tok);
    in->lim -= free;
    in->cur -= free;
    in->mar -= free;
    in->tok -= free;
    if (in->yyt1) in->yyt1 -= free;
if (in->yyt10) in->yyt10 -= free;
if (in->yyt11) in->yyt11 -= free;
if (in->yyt12) in->yyt12 -= free;
if (in->yyt13) in->yyt13 -= free;
if (in->yyt14) in->yyt14 -= free;
if (in->yyt15) in->yyt15 -= free;
if (in->yyt16) in->yyt16 -= free;
if (in->yyt17) in->yyt17 -= free;
if (in->yyt18) in->yyt18 -= free;
if (in->yyt19) in->yyt19 -= free;
if (in->yyt2) in->yyt2 -= free;
if (in->yyt3) in->yyt3 -= free;
if (in->yyt4) in->yyt4 -= free;
if (in->yyt5) in->yyt5 -= free;
if (in->yyt6) in->yyt6 -= free;
if (in->yyt7) in->yyt7 -= free;
if (in->yyt8) in->yyt8 -= free;
if (in->yyt9) in->yyt9 -= free;


    in->lim += fread(in->lim, 1, free, stdin);

    if (in->lim < in->buf + SIZE) {
        in->eof = 1;
        memset(in->lim, 0, YYMAXFILL);
        in->lim += YYMAXFILL;
    }

    return 0;
}

static inline void init_input(input_t *in)
{
    in->buf = (char*) malloc(SIZE + YYMAXFILL);
    in->lim = in->buf + SIZE;
    in->cur = in->lim;
    in->mar = in->lim;
    in->tok = in->lim;
    in->yyt1 = 0;
in->yyt10 = 0;
in->yyt11 = 0;
in->yyt12 = 0;
in->yyt13 = 0;
in->yyt14 = 0;
in->yyt15 = 0;
in->yyt16 = 0;
in->yyt17 = 0;
in->yyt18 = 0;
in->yyt19 = 0;
in->yyt2 = 0;
in->yyt3 = 0;
in->yyt4 = 0;
in->yyt5 = 0;
in->yyt6 = 0;
in->yyt7 = 0;
in->yyt8 = 0;
in->yyt9 = 0;

    
    taglistpool_init(&in->tlp);
    in->eof = 0;
}


static inline void free_input(input_t *in)
{
    free(in->buf);
    taglistpool_free(&in->tlp);
}

static int lex(input_t *in, Output *out);

int main(int argc, char **argv)
{
    PRE;
    input_t in;
    Output out;

    init_input(&in);
    init_output(&out);

    switch (lex(&in, &out)) {
        case 0:  break;
        case 1:  fprintf(stderr, "*** %s: syntax error\n", argv[0]); break;
        case 2:  fprintf(stderr, "*** %s: yyfill error\n", argv[0]); break;
        default: fprintf(stderr, "*** %s: panic\n", argv[0]); break;
    }

    flush(&out);
    free_output(&out);
    free_input(&in);

    POST;
    return 0;
}


static int lex(input_t *in, Output *out)
{
    const char
        *s1, *u1, *h1, *r1, *p1, *q1, *f1,
        *s2, *u2, *h2, *r2, *p2, *q2, *f2;

loop:
    in->tok = in->cur;

#line 220 "gen/re2c/uri_simple-bc-tdfa0.c"
{
	char yych;
	in->yyt1 = in->cur;
	if ((in->lim - in->cur) < 5) if (fill(in, 5) != 0) return 1;
	yych = *in->cur++;
	switch (yych) {
	case 0x00:	goto yy2;
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
		in->yyt5 = in->cur;
		goto yy6;
	default:	goto yy4;
	}
yy2:
#line 3 "../../../benchmarks/submatch_dfa_aot/src/re2c/include_bc/fill.re"
	{ return 0; }
#line 300 "gen/re2c/uri_simple-bc-tdfa0.c"
yy4:
yy5:
#line 25 "../../../benchmarks/submatch_dfa_aot/src/re2c/uri_simple.re"
	{ return 1; }
#line 305 "gen/re2c/uri_simple-bc-tdfa0.c"
yy6:
	yych = *(in->mar = in->cur);
	switch (yych) {
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy8;
	default:	goto yy5;
	}
yy7:
	if ((in->lim - in->cur) < 4) if (fill(in, 4) != 0) return 1;
	yych = *in->cur;
yy8:
	switch (yych) {
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
		++in->cur;
		in->yyt5 = in->cur;
		goto yy7;
	case ':':
		++in->cur;
		in->yyt2 = in->yyt3 = in->yyt4 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt9 = in->yyt10 = in->cur;
		goto yy10;
	default:	goto yy9;
	}
yy9:
	in->cur = in->mar;
	goto yy5;
yy10:
	yych = *in->cur;
	switch (yych) {
	case '/':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->cur;
		goto yy17;
	default:	goto yy14;
	}
yy11:
	s1 = in->yyt1;
	s2 = in->yyt5;
	u1 = in->yyt2;
	u2 = in->yyt3;
	h1 = in->yyt4;
	h2 = in->yyt6;
	r1 = in->yyt7;
	r2 = in->yyt8;
	p1 = in->yyt9;
	p2 = in->yyt10;
	q1 = in->yyt11;
	q2 = in->yyt12;
	f1 = in->yyt13;
	f2 = in->yyt14;
#line 26 "../../../benchmarks/submatch_dfa_aot/src/re2c/uri_simple.re"
	{
        OUT("scheme: ", s1, s2);
        if (u1) OUT("user: ", u1, u2);
        if (h1) OUT("host: ", h1, h2);
        if (r1) OUT("port: ", r1, r2);
        OUT("path: ", p1, p2);
        if (q1) OUT("query: ", q1, q2);
        if (f1) OUT("fragment: ", f1, f2);
        outc(out, '\n');
        goto loop;
    }
#line 497 "gen/re2c/uri_simple-bc-tdfa0.c"
yy13:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
yy14:
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy11;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case '@':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->cur;
		goto yy13;
	case '#':
		++in->cur;
		in->yyt13 = in->yyt14 = in->cur;
		goto yy15;
	case '?':
		++in->cur;
		in->yyt13 = in->yyt14 = NULL;
		in->yyt11 = in->yyt12 = in->cur;
		goto yy18;
	default:	goto yy9;
	}
yy15:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy11;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case '?':
	case '@':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		in->yyt14 = in->cur;
		goto yy15;
	default:	goto yy9;
	}
yy17:
	yych = *in->cur;
	switch (yych) {
	case '/':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt16 = in->yyt17 = NULL;
		in->yyt10 = in->yyt15 = in->yyt18 = in->cur;
		goto yy20;
	default:	goto yy14;
	}
yy18:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy11;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case '?':
	case '@':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		in->yyt13 = in->yyt14 = NULL;
		in->yyt12 = in->cur;
		goto yy18;
	case '#':
		++in->cur;
		in->yyt13 = in->yyt14 = in->cur;
		goto yy15;
	default:	goto yy9;
	}
yy20:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy11;
	case '#':
		++in->cur;
		in->yyt13 = in->yyt14 = in->cur;
		goto yy15;
	case '/':
	case '@':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->cur;
		goto yy13;
	case ':':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->yyt19 = in->cur;
		goto yy23;
	case '?':
		++in->cur;
		in->yyt13 = in->yyt14 = NULL;
		in->yyt11 = in->yyt12 = in->cur;
		goto yy18;
	default:	goto yy22;
	}
yy21:
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
yy22:
	switch (yych) {
	case '\n':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		goto yy11;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		in->yyt7 = in->yyt8 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt6 = in->yyt9 = in->yyt10 = in->yyt19 = in->cur;
		goto yy21;
	case '#':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt13 = in->yyt14 = in->cur;
		goto yy15;
	case '/':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->cur;
		goto yy13;
	case ':':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt19 = in->cur;
		goto yy27;
	case '?':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt13 = in->yyt14 = NULL;
		in->yyt11 = in->yyt12 = in->cur;
		goto yy18;
	case '@':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt2 = in->yyt10 = in->cur;
		goto yy29;
	case '[':
		++in->cur;
		goto yy25;
	default:	goto yy9;
	}
yy23:
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy11;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->yyt19 = in->cur;
		goto yy23;
	case '#':
		++in->cur;
		in->yyt13 = in->yyt14 = in->cur;
		goto yy15;
	case '/':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->cur;
		goto yy13;
	case '?':
		++in->cur;
		in->yyt13 = in->yyt14 = NULL;
		in->yyt11 = in->yyt12 = in->cur;
		goto yy18;
	case '@':
		++in->cur;
		in->yyt16 = in->yyt2;
		in->yyt17 = in->yyt3;
		in->yyt18 = in->yyt4;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt2 = in->yyt10 = in->cur;
		goto yy29;
	default:	goto yy9;
	}
yy25:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		goto yy25;
	case ']':
		++in->cur;
		in->yyt7 = in->yyt8 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt6 = in->yyt9 = in->yyt10 = in->cur;
		goto yy30;
	default:	goto yy9;
	}
yy27:
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		goto yy11;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case ':':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->yyt19 = in->cur;
		goto yy23;
	case '#':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt13 = in->yyt14 = in->cur;
		goto yy15;
	case '/':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->cur;
		goto yy13;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt8 = in->yyt9 = in->yyt10 = in->yyt19 = in->cur;
		goto yy27;
	case '?':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt13 = in->yyt14 = NULL;
		in->yyt11 = in->yyt12 = in->cur;
		goto yy18;
	case '@':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt2 = in->yyt10 = in->cur;
		goto yy29;
	default:	goto yy9;
	}
yy29:
	yych = *in->cur;
	switch (yych) {
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		in->yyt16 = in->yyt15;
		in->yyt17 = in->yyt19;
		in->yyt18 = in->yyt2;
		in->yyt7 = in->yyt8 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt6 = in->yyt9 = in->yyt10 = in->cur;
		goto yy30;
	case ':':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->cur;
		goto yy13;
	case '[':
		++in->cur;
		in->yyt16 = in->yyt15;
		in->yyt17 = in->yyt19;
		in->yyt18 = in->yyt2;
		goto yy25;
	default:	goto yy31;
	}
yy30:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
yy31:
	switch (yych) {
	case '\n':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		goto yy11;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		in->yyt7 = in->yyt8 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt6 = in->yyt9 = in->yyt10 = in->cur;
		goto yy30;
	case '#':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt13 = in->yyt14 = in->cur;
		goto yy15;
	case '/':
	case '@':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->cur;
		goto yy13;
	case ':':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->cur;
		goto yy32;
	case '?':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt13 = in->yyt14 = NULL;
		in->yyt11 = in->yyt12 = in->cur;
		goto yy18;
	case '[':
		++in->cur;
		goto yy25;
	default:	goto yy9;
	}
yy32:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		goto yy11;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '/':
	case ':':
	case ';':
	case '=':
	case '@':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '~':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt10 = in->cur;
		goto yy13;
	case '#':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt13 = in->yyt14 = in->cur;
		goto yy15;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
		in->yyt8 = in->yyt9 = in->yyt10 = in->cur;
		goto yy32;
	case '?':
		++in->cur;
		in->yyt2 = in->yyt16;
		in->yyt3 = in->yyt17;
		in->yyt4 = in->yyt18;
		in->yyt13 = in->yyt14 = NULL;
		in->yyt11 = in->yyt12 = in->cur;
		goto yy18;
	default:	goto yy9;
	}
}
#line 37 "../../../benchmarks/submatch_dfa_aot/src/re2c/uri_simple.re"

}
