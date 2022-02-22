/* Generated by re2c */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/33__rep_alt_5_3_2.re"
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
    
#line 30 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
#line 34 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    
#line 34 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
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
    
#line 48 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
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

#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"
#line 6 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"


static inline int fill(input_t *in)
{
    size_t free;
    if (in->eof) return 1;

    free = in->tok - in->buf;
    assert(free > 0);

    memmove(in->buf, in->tok, in->lim - in->tok);
    in->lim -= free;
    in->cur -= free;
    in->mar -= free;
    in->tok -= free;
    
#line 109 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
#line 21 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"


    in->lim += fread(in->lim, 1, free, stdin);
    in->lim[0] = 0;

    if (in->lim < in->buf + SIZE) {
        in->eof = 1;
    }

    return 0;
}

static inline void init_input(input_t *in)
{
    in->buf = (char*) malloc(SIZE + 1);
    in->lim = in->buf + SIZE;
    in->cur = in->lim;
    in->mar = in->lim;
    in->tok = in->lim;
    
#line 131 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
#line 40 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"

    
#line 135 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
in->yytm1 = 0;
in->yytm2 = 0;
in->yytm3 = 0;
#line 41 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"

    taglistpool_init(&in->tlp);
    in->eof = 0;
    fill(in);
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
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/33__rep_alt_5_3_2.re"


static const char *print(Output *out, const char *tok, const taglist_t *t)
{
    if (!t) return tok;

    const char *s = print(out, tok, t->pred);
    const char *e = tok + t->dist;
    outs(out, s, e);
    outc(out, '.');
    return e;
}

static int lex(input_t *in, Output *out)
{
    taglist_t *t = NULL;

loop:
    in->tok = in->cur;

#line 200 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
{
	char yych;
	in->yytm1 = in->yytm2;
	taglist(&in->yytm1, in->tok, in->tok - 1, &in->tlp);
yyFillLabel0:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			goto yy3;
		case 'a':
			++in->cur;
			goto yy4;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel0;
				goto yy11;
			}
			++in->cur;
			goto yy1;
	}
yy1:
yy2:
#line 23 "../../../benchmarks/submatch_dfa_aot/src/re2c/33__rep_alt_5_3_2.re"
	{ return 1; }
#line 226 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
yy3:
	t = in->yytm1;
#line 24 "../../../benchmarks/submatch_dfa_aot/src/re2c/33__rep_alt_5_3_2.re"
	{
        print(out, in->tok, t);
        outc(out, '\n');
        taglistpool_clear(&in->tlp, in);
        goto loop;
    }
#line 236 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
yy4:
	in->mar = in->cur;
yyFillLabel1:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yytm1 = in->yytm2;
			taglist(&in->yytm1, in->tok, in->cur, &in->tlp);
			goto yy5;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel1;
			}
			goto yy2;
	}
yy5:
yyFillLabel2:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			goto yy3;
		case 'a':
			++in->cur;
			in->yytm3 = in->yytm2;
			taglist(&in->yytm3, in->tok, in->cur, &in->tlp);
			goto yy7;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel2;
			}
			goto yy6;
	}
yy6:
	in->cur = in->mar;
	goto yy2;
yy7:
yyFillLabel3:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yytm1 = in->yytm3;
			goto yy3;
		case 'a':
			++in->cur;
			taglist(&in->yytm1, in->tok, in->cur, &in->tlp);
			goto yy8;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel3;
			}
			goto yy6;
	}
yy8:
yyFillLabel4:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			goto yy3;
		case 'a':
			++in->cur;
			taglist(&in->yytm2, in->tok, in->cur, &in->tlp);
			goto yy9;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel4;
			}
			goto yy6;
	}
yy9:
yyFillLabel5:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yytm1 = in->yytm2;
			goto yy3;
		case 'a':
			++in->cur;
			taglist(&in->yytm3, in->tok, in->cur, &in->tlp);
			goto yy10;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel5;
			}
			goto yy6;
	}
yy10:
yyFillLabel6:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yytm1 = in->yytm3;
			goto yy3;
		case 'a':
			++in->cur;
			in->yytm1 = in->yytm2;
			taglist(&in->yytm1, in->tok, in->cur, &in->tlp);
			goto yy5;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel6;
			}
			goto yy6;
	}
yy11:
#line 5 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"
	{ return 0; }
#line 349 "gen/re2c/33__rep_alt_5_3_2-eof-tdfa0.c"
}
#line 30 "../../../benchmarks/submatch_dfa_aot/src/re2c/33__rep_alt_5_3_2.re"

}
