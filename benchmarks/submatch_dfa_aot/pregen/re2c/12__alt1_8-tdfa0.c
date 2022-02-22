/* Generated by re2c */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/12__alt1_8.re"
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"
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
    
#line 30 "gen/re2c/12__alt1_8-tdfa0.c"
char *yyt1;
char *yyt10;
char *yyt11;
char *yyt12;
char *yyt13;
char *yyt14;
char *yyt15;
char *yyt16;
char *yyt17;
char *yyt2;
char *yyt3;
char *yyt4;
char *yyt5;
char *yyt6;
char *yyt7;
char *yyt8;
char *yyt9;
#line 34 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    
#line 51 "gen/re2c/12__alt1_8-tdfa0.c"
#line 35 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    
#line 62 "gen/re2c/12__alt1_8-tdfa0.c"
#line 43 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

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

#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"
#line 4 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"


#line 106 "gen/re2c/12__alt1_8-tdfa0.c"
#define YYMAXFILL 2
#line 6 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"


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
    
#line 125 "gen/re2c/12__alt1_8-tdfa0.c"
if (in->yyt1) in->yyt1 -= free;
if (in->yyt10) in->yyt10 -= free;
if (in->yyt11) in->yyt11 -= free;
if (in->yyt12) in->yyt12 -= free;
if (in->yyt13) in->yyt13 -= free;
if (in->yyt14) in->yyt14 -= free;
if (in->yyt15) in->yyt15 -= free;
if (in->yyt16) in->yyt16 -= free;
if (in->yyt17) in->yyt17 -= free;
if (in->yyt2) in->yyt2 -= free;
if (in->yyt3) in->yyt3 -= free;
if (in->yyt4) in->yyt4 -= free;
if (in->yyt5) in->yyt5 -= free;
if (in->yyt6) in->yyt6 -= free;
if (in->yyt7) in->yyt7 -= free;
if (in->yyt8) in->yyt8 -= free;
if (in->yyt9) in->yyt9 -= free;
#line 21 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"


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
    
#line 165 "gen/re2c/12__alt1_8-tdfa0.c"
in->yyt1 = 0;
in->yyt10 = 0;
in->yyt11 = 0;
in->yyt12 = 0;
in->yyt13 = 0;
in->yyt14 = 0;
in->yyt15 = 0;
in->yyt16 = 0;
in->yyt17 = 0;
in->yyt2 = 0;
in->yyt3 = 0;
in->yyt4 = 0;
in->yyt5 = 0;
in->yyt6 = 0;
in->yyt7 = 0;
in->yyt8 = 0;
in->yyt9 = 0;
#line 41 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"

    
#line 186 "gen/re2c/12__alt1_8-tdfa0.c"
#line 42 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"

    taglistpool_init(&in->tlp);
    in->eof = 0;
}
#line 81 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"


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
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/12__alt1_8.re"


static int lex(input_t *in, Output *out)
{
    const char
        *a1, *b1, *c1, *d1, *e1, *f1, *g1, *h1,
        *a2, *b2, *c2, *d2, *e2, *f2, *g2, *h2;
loop:
    in->tok = in->cur;

#line 237 "gen/re2c/12__alt1_8-tdfa0.c"
{
	char yych;
	in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
	in->yyt1 = in->yyt2 = in->yyt17 = in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur++;
	switch (yych) {
		case 0x00: goto yy1;
		case '\n': goto yy4;
		case 'a':
			in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt2 = in->cur;
			goto yy5;
		case 'b':
			in->yyt1 = in->yyt2 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt4 = in->cur;
			goto yy6;
		case 'c':
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt6 = in->cur;
			goto yy7;
		case 'd':
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt8 = in->cur;
			goto yy8;
		case 'e':
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt10 = in->cur;
			goto yy9;
		case 'f':
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt12 = in->cur;
			goto yy10;
		case 'g':
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt15 = in->yyt16 = NULL;
			in->yyt14 = in->cur;
			goto yy11;
		case 'h':
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
			in->yyt16 = in->cur;
			goto yy12;
		default: goto yy2;
	}
yy1:
#line 3 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"
	{ return 0; }
#line 284 "gen/re2c/12__alt1_8-tdfa0.c"
yy2:
yy3:
#line 11 "../../../benchmarks/submatch_dfa_aot/src/re2c/12__alt1_8.re"
	{ return 1; }
#line 289 "gen/re2c/12__alt1_8-tdfa0.c"
yy4:
	a1 = in->yyt1;
	a2 = in->yyt2;
	b1 = in->yyt3;
	b2 = in->yyt4;
	c1 = in->yyt5;
	c2 = in->yyt6;
	d1 = in->yyt7;
	d2 = in->yyt8;
	e1 = in->yyt9;
	e2 = in->yyt10;
	f1 = in->yyt11;
	f2 = in->yyt12;
	g1 = in->yyt13;
	g2 = in->yyt14;
	h1 = in->yyt15;
	h2 = in->yyt16;
#line 22 "../../../benchmarks/submatch_dfa_aot/src/re2c/12__alt1_8.re"
	{
        if (a1)      { outc(out, 'A'); outs(out, a1, a2); }
        else if (b1) { outc(out, 'B'); outs(out, b1, b2); }
        else if (c1) { outc(out, 'C'); outs(out, c1, c2); }
        else if (d1) { outc(out, 'D'); outs(out, d1, d2); }
        else if (e1) { outc(out, 'E'); outs(out, e1, e2); }
        else if (f1) { outc(out, 'F'); outs(out, f1, f2); }
        else if (g1) { outc(out, 'G'); outs(out, g1, g2); }
        else if (h1) { outc(out, 'H'); outs(out, h1, h2); }
        outc(out, '\n');
        goto loop;
    }
#line 320 "gen/re2c/12__alt1_8-tdfa0.c"
yy5:
	yych = *(in->mar = in->cur);
	switch (yych) {
		case '\n':
			++in->cur;
			goto yy4;
		case 'a':
			++in->cur;
			in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt2 = in->cur;
			goto yy13;
		default: goto yy3;
	}
yy6:
	yych = *(in->mar = in->cur);
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt17;
			goto yy4;
		case 'b':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt4 = in->cur;
			goto yy15;
		default: goto yy3;
	}
yy7:
	yych = *(in->mar = in->cur);
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt5 = in->yyt17;
			goto yy4;
		case 'c':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt6 = in->cur;
			goto yy16;
		default: goto yy3;
	}
yy8:
	yych = *(in->mar = in->cur);
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt7 = in->yyt17;
			goto yy4;
		case 'd':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt8 = in->cur;
			goto yy17;
		default: goto yy3;
	}
yy9:
	yych = *(in->mar = in->cur);
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt9 = in->yyt17;
			goto yy4;
		case 'e':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt10 = in->cur;
			goto yy18;
		default: goto yy3;
	}
yy10:
	yych = *(in->mar = in->cur);
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt11 = in->yyt17;
			goto yy4;
		case 'f':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt12 = in->cur;
			goto yy19;
		default: goto yy3;
	}
yy11:
	yych = *(in->mar = in->cur);
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt13 = in->yyt17;
			goto yy4;
		case 'g':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt15 = in->yyt16 = NULL;
			in->yyt14 = in->cur;
			goto yy20;
		default: goto yy3;
	}
yy12:
	yych = *(in->mar = in->cur);
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt15 = in->yyt17;
			goto yy4;
		case 'h':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
			in->yyt16 = in->cur;
			goto yy21;
		default: goto yy3;
	}
yy13:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			goto yy4;
		case 'a':
			++in->cur;
			in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt2 = in->cur;
			goto yy13;
		default: goto yy14;
	}
yy14:
	in->cur = in->mar;
	goto yy3;
yy15:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt17;
			goto yy4;
		case 'b':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt4 = in->cur;
			goto yy15;
		default: goto yy14;
	}
yy16:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt5 = in->yyt17;
			goto yy4;
		case 'c':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt6 = in->cur;
			goto yy16;
		default: goto yy14;
	}
yy17:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt7 = in->yyt17;
			goto yy4;
		case 'd':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt8 = in->cur;
			goto yy17;
		default: goto yy14;
	}
yy18:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt9 = in->yyt17;
			goto yy4;
		case 'e':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt10 = in->cur;
			goto yy18;
		default: goto yy14;
	}
yy19:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt11 = in->yyt17;
			goto yy4;
		case 'f':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt13 = in->yyt14 = in->yyt15 = in->yyt16 = NULL;
			in->yyt12 = in->cur;
			goto yy19;
		default: goto yy14;
	}
yy20:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt13 = in->yyt17;
			goto yy4;
		case 'g':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt15 = in->yyt16 = NULL;
			in->yyt14 = in->cur;
			goto yy20;
		default: goto yy14;
	}
yy21:
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt15 = in->yyt17;
			goto yy4;
		case 'h':
			++in->cur;
			in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->yyt5 = in->yyt6 = in->yyt7 = in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt12 = in->yyt13 = in->yyt14 = NULL;
			in->yyt16 = in->cur;
			goto yy21;
		default: goto yy14;
	}
}
#line 34 "../../../benchmarks/submatch_dfa_aot/src/re2c/12__alt1_8.re"

}
