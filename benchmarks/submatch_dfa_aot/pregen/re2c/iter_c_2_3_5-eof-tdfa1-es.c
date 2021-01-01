/* Generated by re2c 2.0.3 */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/iter_c_2_3_5.re"
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
taglist_t *yyt2;
taglist_t *yyt3;
taglist_t *yyt4;
taglist_t *yyt5;
taglist_t *yyt6;
taglist_t *yyt7;

    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    in->yyt1 = 0;
in->yyt2 = 0;
in->yyt3 = 0;
in->yyt4 = 0;
in->yyt5 = 0;
in->yyt6 = 0;
in->yyt7 = 0;

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
in->yyt2 = 0;
in->yyt3 = 0;
in->yyt4 = 0;
in->yyt5 = 0;
in->yyt6 = 0;
in->yyt7 = 0;

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


static const char *print(Output *out, const char *tok, const char *start,
    const taglist_t *t)
{
    if (!t) return start;

    const char *s = print(out, tok, start, t->pred);
    if (t->dist > 0) {
        const char *e = tok + t->dist;
        outs(out, s, e);
        outc(out, '.');
        return e;
    } else {
        return s;
    }
}

static int lex(input_t *in, Output *out)
{
    taglist_t *t1 = NULL, *t2 = NULL, *t3 = NULL;

loop:
    in->tok = in->cur;

#line 195 "gen/re2c/iter_c_2_3_5-eof-tdfa1-es.c"
{
	char yych;
yyFillLabel3_0:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt4, in->tok, in->tok - 1, &in->tlp);
		in->yyt3 = in->yyt1;
		taglist(&in->yyt3, in->tok, in->tok - 1, &in->tlp);
		in->yyt2 = in->yyt6;
		taglist(&in->yyt2, in->tok, in->tok - 1, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt3 = in->yyt1;
		taglist(&in->yyt3, in->tok, in->tok - 1, &in->tlp);
		in->yyt2 = in->yyt6;
		taglist(&in->yyt2, in->tok, in->tok - 1, &in->tlp);
		++in->cur;
		goto yy6;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_0;
			goto yy21;
		}
		++in->cur;
		goto yy2;
	}
yy2:
yy3:
#line 28 "../../../benchmarks/submatch_dfa_aot/src/re2c/iter_c_2_3_5.re"
	{ return 1; }
#line 228 "gen/re2c/iter_c_2_3_5-eof-tdfa1-es.c"
yy4:
	t1 = in->yyt2;
	t2 = in->yyt3;
	t3 = in->yyt4;
#line 29 "../../../benchmarks/submatch_dfa_aot/src/re2c/iter_c_2_3_5.re"
	{
        const char *p = in->tok;
        p = print(out, in->tok, p, t1);
        p = print(out, in->tok, p, t2);
        p = print(out, in->tok, p, t3);
        outc(out, '\n');
        taglistpool_clear(&in->tlp, in);
        goto loop;
    }
#line 243 "gen/re2c/iter_c_2_3_5-eof-tdfa1-es.c"
yy6:
	in->mar = in->cur;
yyFillLabel3_1:
	yych = *in->cur;
	switch (yych) {
	case 'a':
		++in->cur;
		goto yy7;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_1;
		}
		goto yy3;
	}
yy7:
yyFillLabel3_2:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt4, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt7 = in->yyt4;
		taglist(&in->yyt7, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy9;
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
yyFillLabel3_3:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt4, in->tok, in->tok - 1, &in->tlp);
		in->yyt3 = in->yyt1;
		taglist(&in->yyt3, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt5 = in->yyt1;
		taglist(&in->yyt5, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy10;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_3;
		}
		goto yy8;
	}
yy10:
yyFillLabel3_4:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		in->yyt4 = in->yyt7;
		taglist(&in->yyt4, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		++in->cur;
		goto yy11;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_4;
		}
		goto yy8;
	}
yy11:
yyFillLabel3_5:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt4, in->tok, in->tok - 1, &in->tlp);
		in->yyt3 = in->yyt1;
		taglist(&in->yyt3, in->tok, in->tok - 1, &in->tlp);
		in->yyt2 = in->yyt6;
		taglist(&in->yyt2, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt3 = in->yyt1;
		taglist(&in->yyt3, in->tok, in->tok - 1, &in->tlp);
		taglist(&in->yyt6, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy12;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_5;
		}
		goto yy8;
	}
yy12:
yyFillLabel3_6:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt4, in->tok, in->tok - 1, &in->tlp);
		in->yyt3 = in->yyt5;
		taglist(&in->yyt3, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		++in->cur;
		goto yy13;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_6;
		}
		goto yy8;
	}
yy13:
yyFillLabel3_7:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		in->yyt2 = in->yyt6;
		taglist(&in->yyt4, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt5 = in->yyt4;
		taglist(&in->yyt5, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy14;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_7;
		}
		goto yy8;
	}
yy14:
yyFillLabel3_8:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		in->yyt2 = in->yyt6;
		taglist(&in->yyt4, in->tok, in->tok - 1, &in->tlp);
		in->yyt3 = in->yyt1;
		taglist(&in->yyt3, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt7 = in->yyt1;
		taglist(&in->yyt7, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy15;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_8;
		}
		goto yy8;
	}
yy15:
yyFillLabel3_9:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		in->yyt2 = in->yyt6;
		in->yyt4 = in->yyt5;
		taglist(&in->yyt4, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		++in->cur;
		goto yy16;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_9;
		}
		goto yy8;
	}
yy16:
yyFillLabel3_10:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt4, in->tok, in->tok - 1, &in->tlp);
		in->yyt3 = in->yyt1;
		taglist(&in->yyt3, in->tok, in->tok - 1, &in->tlp);
		in->yyt2 = in->yyt6;
		taglist(&in->yyt2, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt3 = in->yyt1;
		taglist(&in->yyt3, in->tok, in->tok - 1, &in->tlp);
		in->yyt2 = in->yyt6;
		taglist(&in->yyt2, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy17;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_10;
		}
		goto yy8;
	}
yy17:
yyFillLabel3_11:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		in->yyt2 = in->yyt6;
		taglist(&in->yyt4, in->tok, in->tok - 1, &in->tlp);
		in->yyt3 = in->yyt7;
		taglist(&in->yyt3, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		++in->cur;
		goto yy18;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_11;
		}
		goto yy8;
	}
yy18:
yyFillLabel3_12:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt4, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt5 = in->yyt4;
		taglist(&in->yyt5, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy19;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_12;
		}
		goto yy8;
	}
yy19:
yyFillLabel3_13:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		taglist(&in->yyt4, in->tok, in->tok - 1, &in->tlp);
		in->yyt3 = in->yyt1;
		taglist(&in->yyt3, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt7 = in->yyt1;
		taglist(&in->yyt7, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy20;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_13;
		}
		goto yy8;
	}
yy20:
yyFillLabel3_14:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		in->yyt4 = in->yyt5;
		taglist(&in->yyt4, in->tok, in->cur, &in->tlp);
		++in->cur;
		goto yy4;
	case 'a':
		in->yyt6 = in->yyt2;
		++in->cur;
		goto yy16;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_14;
		}
		goto yy8;
	}
yy21:
#line 5 "../../../benchmarks/submatch_dfa_aot/src/re2c/include_eof/fill.re"
	{ return 0; }
#line 530 "gen/re2c/iter_c_2_3_5-eof-tdfa1-es.c"
}
#line 38 "../../../benchmarks/submatch_dfa_aot/src/re2c/iter_c_2_3_5.re"

}
