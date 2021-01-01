/* Generated by re2c 2.0.3 */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/cat8_0.re"
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


#define YYMAXFILL 2


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
        *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7,
        *b0, *b1, *b2, *b3, *b4, *b5, *b6, *b7;
loop:
    in->tok = in->cur;

#line 210 "gen/re2c/cat8_0-bc-tdfa0.c"
{
	char yych;
	in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur++;
	switch (yych) {
	case 0x00:	goto yy2;
	case '\n':	goto yy6;
	case 'a':
		in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy8;
	case 'b':
		in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy9;
	default:	goto yy4;
	}
yy2:
#line 3 "../../../benchmarks/submatch_dfa_aot/src/re2c/include_bc/fill.re"
	{ return 0; }
#line 230 "gen/re2c/cat8_0-bc-tdfa0.c"
yy4:
yy5:
#line 11 "../../../benchmarks/submatch_dfa_aot/src/re2c/cat8_0.re"
	{ return 1; }
#line 235 "gen/re2c/cat8_0-bc-tdfa0.c"
yy6:
	a0 = in->yyt1;
	b0 = in->yyt2;
	a1 = in->yyt3;
	b1 = in->yyt4;
	a2 = in->yyt5;
	b2 = in->yyt6;
	a3 = in->yyt7;
	b3 = in->yyt8;
	a4 = in->yyt9;
	b4 = in->yyt10;
	a5 = in->yyt11;
	b5 = in->yyt12;
	a6 = in->yyt13;
	b6 = in->yyt14;
	a7 = in->yyt15;
	b7 = in->yyt16;
#line 21 "../../../benchmarks/submatch_dfa_aot/src/re2c/cat8_0.re"
	{
        outs(out, a0, b0); outc(out, '.'); outs(out, b0, a1); outc(out, '.');
        outs(out, a1, b1); outc(out, '.'); outs(out, b1, a2); outc(out, '.');
        outs(out, a2, b2); outc(out, '.'); outs(out, b2, a3); outc(out, '.');
        outs(out, a3, b3); outc(out, '.'); outs(out, b3, a4); outc(out, '.');
        outs(out, a4, b4); outc(out, '.'); outs(out, b4, a5); outc(out, '.');
        outs(out, a5, b5); outc(out, '.'); outs(out, b5, a6); outc(out, '.');
        outs(out, a6, b6); outc(out, '.'); outs(out, b6, a7); outc(out, '.');
        outs(out, a7, b7); outc(out, '.'); outs(out, b7, in->cur);
        goto loop;
    }
#line 265 "gen/re2c/cat8_0-bc-tdfa0.c"
yy8:
	yych = *(in->mar = in->cur);
	switch (yych) {
	case '\n':
	case 'a':
	case 'b':	goto yy11;
	default:	goto yy5;
	}
yy9:
	yych = *(in->mar = in->cur);
	switch (yych) {
	case '\n':
	case 'a':
	case 'b':	goto yy14;
	default:	goto yy5;
	}
yy10:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
yy11:
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy10;
	case 'b':
		++in->cur;
		in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy13;
	default:	goto yy12;
	}
yy12:
	in->cur = in->mar;
	goto yy5;
yy13:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
yy14:
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy15;
	case 'b':
		++in->cur;
		in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy13;
	default:	goto yy12;
	}
yy15:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy15;
	case 'b':
		++in->cur;
		in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy17;
	default:	goto yy12;
	}
yy17:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy19;
	case 'b':
		++in->cur;
		in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy17;
	default:	goto yy12;
	}
yy19:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy19;
	case 'b':
		++in->cur;
		in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy21;
	default:	goto yy12;
	}
yy21:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy23;
	case 'b':
		++in->cur;
		in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy21;
	default:	goto yy12;
	}
yy23:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy23;
	case 'b':
		++in->cur;
		in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy25;
	default:	goto yy12;
	}
yy25:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy27;
	case 'b':
		++in->cur;
		in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy25;
	default:	goto yy12;
	}
yy27:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy27;
	case 'b':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy29;
	default:	goto yy12;
	}
yy29:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy31;
	case 'b':
		++in->cur;
		in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy29;
	default:	goto yy12;
	}
yy31:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy31;
	case 'b':
		++in->cur;
		in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy33;
	default:	goto yy12;
	}
yy33:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy35;
	case 'b':
		++in->cur;
		in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy33;
	default:	goto yy12;
	}
yy35:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
		goto yy35;
	case 'b':
		++in->cur;
		in->yyt15 = in->yyt16 = in->cur;
		goto yy37;
	default:	goto yy12;
	}
yy37:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt16 = in->cur;
		goto yy39;
	case 'b':
		++in->cur;
		in->yyt15 = in->yyt16 = in->cur;
		goto yy37;
	default:	goto yy12;
	}
yy39:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'a':
		++in->cur;
		in->yyt16 = in->cur;
		goto yy39;
	case 'b':
		++in->cur;
		goto yy41;
	default:	goto yy12;
	}
yy41:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy6;
	case 'b':
		++in->cur;
		goto yy41;
	default:	goto yy12;
	}
}
#line 32 "../../../benchmarks/submatch_dfa_aot/src/re2c/cat8_0.re"

}
