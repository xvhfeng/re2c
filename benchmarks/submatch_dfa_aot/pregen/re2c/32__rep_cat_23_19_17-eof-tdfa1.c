/* Generated by re2c */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/32__rep_cat_23_19_17.re"
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
    
#line 30 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
#line 34 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    
#line 34 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
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
    
#line 48 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
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
    
#line 109 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
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
    
#line 131 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
#line 40 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"

    
#line 135 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
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
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/32__rep_cat_23_19_17.re"


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

#line 209 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
{
	char yych;
yyFillLabel0:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			taglist(&in->yytm3, in->tok, in->tok - 1, &in->tlp);
			taglist(&in->yytm2, in->tok, in->tok - 1, &in->tlp);
			taglist(&in->yytm1, in->tok, in->tok - 1, &in->tlp);
			goto yy3;
		case 'a': goto yy4;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel0;
				goto yy65;
			}
			goto yy1;
	}
yy1:
	++in->cur;
yy2:
#line 32 "../../../benchmarks/submatch_dfa_aot/src/re2c/32__rep_cat_23_19_17.re"
	{ return 1; }
#line 233 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
yy3:
	++in->cur;
	t1 = in->yytm1;
	t2 = in->yytm2;
	t3 = in->yytm3;
#line 33 "../../../benchmarks/submatch_dfa_aot/src/re2c/32__rep_cat_23_19_17.re"
	{
        print(out, in->tok, t1, t2, t3);
        outc(out, '\n');
        taglistpool_clear(&in->tlp, in);
        goto loop;
    }
#line 246 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
yy4:
	in->mar = ++in->cur;
yyFillLabel1:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy5;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel1;
			}
			goto yy2;
	}
yy5:
	++in->cur;
yyFillLabel2:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy7;
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
	++in->cur;
yyFillLabel3:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy8;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel3;
			}
			goto yy6;
	}
yy8:
	++in->cur;
yyFillLabel4:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy9;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel4;
			}
			goto yy6;
	}
yy9:
	++in->cur;
yyFillLabel5:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy10;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel5;
			}
			goto yy6;
	}
yy10:
	++in->cur;
yyFillLabel6:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy11;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel6;
			}
			goto yy6;
	}
yy11:
	++in->cur;
yyFillLabel7:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy12;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel7;
			}
			goto yy6;
	}
yy12:
	++in->cur;
yyFillLabel8:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy13;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel8;
			}
			goto yy6;
	}
yy13:
	++in->cur;
yyFillLabel9:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy14;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel9;
			}
			goto yy6;
	}
yy14:
	++in->cur;
yyFillLabel10:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy15;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel10;
			}
			goto yy6;
	}
yy15:
	++in->cur;
yyFillLabel11:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy16;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel11;
			}
			goto yy6;
	}
yy16:
	++in->cur;
yyFillLabel12:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy17;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel12;
			}
			goto yy6;
	}
yy17:
	++in->cur;
yyFillLabel13:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy18;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel13;
			}
			goto yy6;
	}
yy18:
	++in->cur;
yyFillLabel14:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy19;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel14;
			}
			goto yy6;
	}
yy19:
	++in->cur;
yyFillLabel15:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy20;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel15;
			}
			goto yy6;
	}
yy20:
	++in->cur;
yyFillLabel16:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy21;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel16;
			}
			goto yy6;
	}
yy21:
	++in->cur;
yyFillLabel17:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy22;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel17;
			}
			goto yy6;
	}
yy22:
	++in->cur;
yyFillLabel18:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy23;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel18;
			}
			goto yy6;
	}
yy23:
	++in->cur;
yyFillLabel19:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy24;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel19;
			}
			goto yy6;
	}
yy24:
	++in->cur;
yyFillLabel20:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy25;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel20;
			}
			goto yy6;
	}
yy25:
	++in->cur;
yyFillLabel21:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy26;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel21;
			}
			goto yy6;
	}
yy26:
	++in->cur;
yyFillLabel22:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy27;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel22;
			}
			goto yy6;
	}
yy27:
	++in->cur;
yyFillLabel23:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			taglist(&in->yytm1, in->tok, in->cur, &in->tlp);
			goto yy28;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel23;
			}
			goto yy6;
	}
yy28:
	++in->cur;
yyFillLabel24:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy29;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel24;
			}
			goto yy6;
	}
yy29:
	++in->cur;
yyFillLabel25:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy30;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel25;
			}
			goto yy6;
	}
yy30:
	++in->cur;
yyFillLabel26:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy31;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel26;
			}
			goto yy6;
	}
yy31:
	++in->cur;
yyFillLabel27:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy32;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel27;
			}
			goto yy6;
	}
yy32:
	++in->cur;
yyFillLabel28:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy33;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel28;
			}
			goto yy6;
	}
yy33:
	++in->cur;
yyFillLabel29:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy34;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel29;
			}
			goto yy6;
	}
yy34:
	++in->cur;
yyFillLabel30:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy35;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel30;
			}
			goto yy6;
	}
yy35:
	++in->cur;
yyFillLabel31:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy36;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel31;
			}
			goto yy6;
	}
yy36:
	++in->cur;
yyFillLabel32:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy37;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel32;
			}
			goto yy6;
	}
yy37:
	++in->cur;
yyFillLabel33:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy38;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel33;
			}
			goto yy6;
	}
yy38:
	++in->cur;
yyFillLabel34:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy39;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel34;
			}
			goto yy6;
	}
yy39:
	++in->cur;
yyFillLabel35:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy40;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel35;
			}
			goto yy6;
	}
yy40:
	++in->cur;
yyFillLabel36:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy41;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel36;
			}
			goto yy6;
	}
yy41:
	++in->cur;
yyFillLabel37:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy42;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel37;
			}
			goto yy6;
	}
yy42:
	++in->cur;
yyFillLabel38:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy43;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel38;
			}
			goto yy6;
	}
yy43:
	++in->cur;
yyFillLabel39:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy44;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel39;
			}
			goto yy6;
	}
yy44:
	++in->cur;
yyFillLabel40:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy45;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel40;
			}
			goto yy6;
	}
yy45:
	++in->cur;
yyFillLabel41:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy46;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel41;
			}
			goto yy6;
	}
yy46:
	++in->cur;
yyFillLabel42:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			taglist(&in->yytm2, in->tok, in->cur, &in->tlp);
			goto yy47;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel42;
			}
			goto yy6;
	}
yy47:
	++in->cur;
yyFillLabel43:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy48;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel43;
			}
			goto yy6;
	}
yy48:
	++in->cur;
yyFillLabel44:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy49;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel44;
			}
			goto yy6;
	}
yy49:
	++in->cur;
yyFillLabel45:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy50;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel45;
			}
			goto yy6;
	}
yy50:
	++in->cur;
yyFillLabel46:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy51;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel46;
			}
			goto yy6;
	}
yy51:
	++in->cur;
yyFillLabel47:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy52;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel47;
			}
			goto yy6;
	}
yy52:
	++in->cur;
yyFillLabel48:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy53;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel48;
			}
			goto yy6;
	}
yy53:
	++in->cur;
yyFillLabel49:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy54;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel49;
			}
			goto yy6;
	}
yy54:
	++in->cur;
yyFillLabel50:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy55;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel50;
			}
			goto yy6;
	}
yy55:
	++in->cur;
yyFillLabel51:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy56;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel51;
			}
			goto yy6;
	}
yy56:
	++in->cur;
yyFillLabel52:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy57;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel52;
			}
			goto yy6;
	}
yy57:
	++in->cur;
yyFillLabel53:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy58;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel53;
			}
			goto yy6;
	}
yy58:
	++in->cur;
yyFillLabel54:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy59;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel54;
			}
			goto yy6;
	}
yy59:
	++in->cur;
yyFillLabel55:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy60;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel55;
			}
			goto yy6;
	}
yy60:
	++in->cur;
yyFillLabel56:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy61;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel56;
			}
			goto yy6;
	}
yy61:
	++in->cur;
yyFillLabel57:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy62;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel57;
			}
			goto yy6;
	}
yy62:
	++in->cur;
yyFillLabel58:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy63;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel58;
			}
			goto yy6;
	}
yy63:
	++in->cur;
yyFillLabel59:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			taglist(&in->yytm3, in->tok, in->cur, &in->tlp);
			goto yy3;
		case 'a':
			taglist(&in->yytm3, in->tok, in->cur, &in->tlp);
			goto yy64;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel59;
			}
			goto yy6;
	}
yy64:
	++in->cur;
yyFillLabel60:
	yych = *in->cur;
	switch (yych) {
		case 'a': goto yy5;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel60;
			}
			goto yy6;
	}
yy65:
#line 5 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"
	{ return 0; }
#line 982 "gen/re2c/32__rep_cat_23_19_17-eof-tdfa1.c"
}
#line 39 "../../../benchmarks/submatch_dfa_aot/src/re2c/32__rep_cat_23_19_17.re"

}
