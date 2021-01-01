/* Generated by re2c 2.0.3 */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/iter_a_4.re"
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
    
    taglist_t *yyt1;

    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    in->yyt1 = 0;

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

#line 6 "../../../benchmarks/submatch_dfa_aot/src/re2c/include_eof/fill.re"


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
    
    in->yyt1 = 0;

    taglistpool_init(&in->tlp);
    in->eof = 0;
    fill(in);
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

#line 172 "gen/re2c/iter_a_4-eof-tdfa1.c"
{
	char yych;
yyFillLabel3_0:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt1, in->tok, in->tok - 1, &in->tlp);
		goto yy4;
	case 'a':	goto yy6;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_0;
			goto yy12;
		}
		goto yy2;
	}
yy2:
	++in->cur;
yy3:
#line 23 "../../../benchmarks/submatch_dfa_aot/src/re2c/iter_a_4.re"
	{ return 1; }
#line 194 "gen/re2c/iter_a_4-eof-tdfa1.c"
yy4:
	++in->cur;
	t = in->yyt1;
#line 24 "../../../benchmarks/submatch_dfa_aot/src/re2c/iter_a_4.re"
	{
        print(out, in->tok, t);
        outc(out, '\n');
        taglistpool_clear(&in->tlp, in);
        goto loop;
    }
#line 205 "gen/re2c/iter_a_4-eof-tdfa1.c"
yy6:
	in->mar = ++in->cur;
yyFillLabel3_1:
	yych = *in->cur;
	switch (yych) {
	case 'a':	goto yy7;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_1;
		}
		goto yy3;
	}
yy7:
	++in->cur;
yyFillLabel3_2:
	yych = *in->cur;
	switch (yych) {
	case 'a':	goto yy9;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_2;
		}
		goto yy8;
	}
yy8:
	in->cur = in->mar;
	goto yy3;
yy9:
	++in->cur;
yyFillLabel3_3:
	yych = *in->cur;
	switch (yych) {
	case 'a':	goto yy10;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_3;
		}
		goto yy8;
	}
yy10:
	++in->cur;
yyFillLabel3_4:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt1, in->tok, in->cur, &in->tlp);
		goto yy4;
	case 'a':
		taglist(&in->yyt1, in->tok, in->cur, &in->tlp);
		goto yy11;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_4;
		}
		goto yy8;
	}
yy11:
	++in->cur;
yyFillLabel3_5:
	yych = *in->cur;
	switch (yych) {
	case 'a':	goto yy7;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_5;
		}
		goto yy8;
	}
yy12:
#line 5 "../../../benchmarks/submatch_dfa_aot/src/re2c/include_eof/fill.re"
	{ return 0; }
#line 277 "gen/re2c/iter_a_4-eof-tdfa1.c"
}
#line 30 "../../../benchmarks/submatch_dfa_aot/src/re2c/iter_a_4.re"

}
