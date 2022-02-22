/* Generated by re2c */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/31__rep_cat_13_11_7.re"
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
    
#line 30 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
#line 34 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    
#line 34 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
taglist_t *yytm1;
taglist_t *yytm2;
taglist_t *yytm3;
#line 35 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    
#line 48 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
in->yytm1 = 0;
in->yytm2 = 0;
in->yytm3 = 0;
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


#line 95 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
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
    
#line 114 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
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
    
#line 137 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
#line 41 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"

    
#line 141 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
in->yytm1 = 0;
in->yytm2 = 0;
in->yytm3 = 0;
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
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/31__rep_cat_13_11_7.re"


static const char *print(Output *out, const char *tok,
    const taglist_t *t1, const taglist_t *t2, const taglist_t *t3)
{
    if (!t1) return tok;

    const char *p0 = print(out, tok, t1->pred, t2->pred, t3->pred);
    const char *p1 = tok + t1->dist;
    const char *p2 = tok + t2->dist;
    const char *p3 = tok + t3->dist;

    outs(out, p0, p1);
    outc(out, '.');
    outs(out, p1, p2);
    outc(out, '.');
    outs(out, p2, p3);
    outc(out, ';');

    return p3;
}

static int lex(input_t *in, Output *out)
{
    taglist_t *t1 = NULL, *t2 = NULL, *t3 = NULL;

loop:
    in->tok = in->cur;

#line 214 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
{
	char yych;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 0x00: goto yy1;
		case '\n':
			taglist(&in->yytm3, in->tok, in->tok - 1, &in->tlp);
			taglist(&in->yytm2, in->tok, in->tok - 1, &in->tlp);
			taglist(&in->yytm1, in->tok, in->tok - 1, &in->tlp);
			goto yy4;
		case 'a': goto yy5;
		default: goto yy2;
	}
yy1:
	++in->cur;
#line 3 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"
	{ return 0; }
#line 233 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
yy2:
	++in->cur;
yy3:
#line 32 "../../../benchmarks/submatch_dfa_aot/src/re2c/31__rep_cat_13_11_7.re"
	{ return 1; }
#line 239 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
yy4:
	++in->cur;
	t1 = in->yytm1;
	t2 = in->yytm2;
	t3 = in->yytm3;
#line 33 "../../../benchmarks/submatch_dfa_aot/src/re2c/31__rep_cat_13_11_7.re"
	{
        print(out, in->tok, t1, t2, t3);
        outc(out, '\n');
        taglistpool_clear(&in->tlp, in);
        goto loop;
    }
#line 252 "gen/re2c/31__rep_cat_13_11_7-tdfa1.c"
yy5:
	yych = *(in->mar = ++in->cur);
	switch (yych) {
		case 'a': goto yy6;
		default: goto yy3;
	}
yy6:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy8;
		default: goto yy7;
	}
yy7:
	in->cur = in->mar;
	goto yy3;
yy8:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy9;
		default: goto yy7;
	}
yy9:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy10;
		default: goto yy7;
	}
yy10:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy11;
		default: goto yy7;
	}
yy11:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy12;
		default: goto yy7;
	}
yy12:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy13;
		default: goto yy7;
	}
yy13:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy14;
		default: goto yy7;
	}
yy14:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy15;
		default: goto yy7;
	}
yy15:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy16;
		default: goto yy7;
	}
yy16:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy17;
		default: goto yy7;
	}
yy17:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy18;
		default: goto yy7;
	}
yy18:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a':
			taglist(&in->yytm1, in->tok, in->cur, &in->tlp);
			goto yy19;
		default: goto yy7;
	}
yy19:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy20;
		default: goto yy7;
	}
yy20:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy21;
		default: goto yy7;
	}
yy21:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy22;
		default: goto yy7;
	}
yy22:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy23;
		default: goto yy7;
	}
yy23:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy24;
		default: goto yy7;
	}
yy24:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy25;
		default: goto yy7;
	}
yy25:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy26;
		default: goto yy7;
	}
yy26:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy27;
		default: goto yy7;
	}
yy27:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy28;
		default: goto yy7;
	}
yy28:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy29;
		default: goto yy7;
	}
yy29:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a':
			taglist(&in->yytm2, in->tok, in->cur, &in->tlp);
			goto yy30;
		default: goto yy7;
	}
yy30:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy31;
		default: goto yy7;
	}
yy31:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy32;
		default: goto yy7;
	}
yy32:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy33;
		default: goto yy7;
	}
yy33:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy34;
		default: goto yy7;
	}
yy34:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy35;
		default: goto yy7;
	}
yy35:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy36;
		default: goto yy7;
	}
yy36:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n':
			taglist(&in->yytm3, in->tok, in->cur, &in->tlp);
			goto yy4;
		case 'a':
			taglist(&in->yytm3, in->tok, in->cur, &in->tlp);
			goto yy37;
		default: goto yy7;
	}
yy37:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy6;
		default: goto yy7;
	}
}
#line 39 "../../../benchmarks/submatch_dfa_aot/src/re2c/31__rep_cat_13_11_7.re"

}
