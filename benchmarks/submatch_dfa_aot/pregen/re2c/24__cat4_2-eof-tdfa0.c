/* Generated by re2c */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/24__cat4_2.re"
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
    
#line 30 "gen/re2c/24__cat4_2-eof-tdfa0.c"
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
char *yyt20;
char *yyt21;
char *yyt22;
char *yyt23;
char *yyt24;
char *yyt25;
char *yyt26;
char *yyt27;
char *yyt28;
char *yyt29;
char *yyt3;
char *yyt30;
char *yyt31;
char *yyt32;
char *yyt33;
char *yyt34;
char *yyt35;
char *yyt36;
char *yyt37;
char *yyt4;
char *yyt5;
char *yyt6;
char *yyt7;
char *yyt8;
char *yyt9;
#line 34 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    
#line 71 "gen/re2c/24__cat4_2-eof-tdfa0.c"
#line 35 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    
#line 82 "gen/re2c/24__cat4_2-eof-tdfa0.c"
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
    
#line 140 "gen/re2c/24__cat4_2-eof-tdfa0.c"
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
if (in->yyt20) in->yyt20 -= free;
if (in->yyt21) in->yyt21 -= free;
if (in->yyt22) in->yyt22 -= free;
if (in->yyt23) in->yyt23 -= free;
if (in->yyt24) in->yyt24 -= free;
if (in->yyt25) in->yyt25 -= free;
if (in->yyt26) in->yyt26 -= free;
if (in->yyt27) in->yyt27 -= free;
if (in->yyt28) in->yyt28 -= free;
if (in->yyt29) in->yyt29 -= free;
if (in->yyt3) in->yyt3 -= free;
if (in->yyt30) in->yyt30 -= free;
if (in->yyt31) in->yyt31 -= free;
if (in->yyt32) in->yyt32 -= free;
if (in->yyt33) in->yyt33 -= free;
if (in->yyt34) in->yyt34 -= free;
if (in->yyt35) in->yyt35 -= free;
if (in->yyt36) in->yyt36 -= free;
if (in->yyt37) in->yyt37 -= free;
if (in->yyt4) in->yyt4 -= free;
if (in->yyt5) in->yyt5 -= free;
if (in->yyt6) in->yyt6 -= free;
if (in->yyt7) in->yyt7 -= free;
if (in->yyt8) in->yyt8 -= free;
if (in->yyt9) in->yyt9 -= free;
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
    
#line 199 "gen/re2c/24__cat4_2-eof-tdfa0.c"
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
in->yyt20 = 0;
in->yyt21 = 0;
in->yyt22 = 0;
in->yyt23 = 0;
in->yyt24 = 0;
in->yyt25 = 0;
in->yyt26 = 0;
in->yyt27 = 0;
in->yyt28 = 0;
in->yyt29 = 0;
in->yyt3 = 0;
in->yyt30 = 0;
in->yyt31 = 0;
in->yyt32 = 0;
in->yyt33 = 0;
in->yyt34 = 0;
in->yyt35 = 0;
in->yyt36 = 0;
in->yyt37 = 0;
in->yyt4 = 0;
in->yyt5 = 0;
in->yyt6 = 0;
in->yyt7 = 0;
in->yyt8 = 0;
in->yyt9 = 0;
#line 40 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"

    
#line 240 "gen/re2c/24__cat4_2-eof-tdfa0.c"
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
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/24__cat4_2.re"


static int lex(input_t *in, Output *out)
{
    const char
        *a0, *a1, *a2, *a3,
        *b0, *b1, *b2, *b3;
loop:
    in->tok = in->cur;

#line 292 "gen/re2c/24__cat4_2-eof-tdfa0.c"
{
	char yych;
	in->yyt1 = in->yyt2 = in->cur;
yyFillLabel0:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt15 = in->cur;
			goto yy3;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel0;
				goto yy65;
			}
			++in->cur;
			goto yy1;
	}
yy1:
yy2:
#line 11 "../../../benchmarks/submatch_dfa_aot/src/re2c/24__cat4_2.re"
	{ return 1; }
#line 315 "gen/re2c/24__cat4_2-eof-tdfa0.c"
yy3:
	in->mar = in->cur;
yyFillLabel1:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt3 = in->yyt4 = in->yyt5 = in->cur;
			goto yy4;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel1;
			}
			goto yy2;
	}
yy4:
yyFillLabel2:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel2;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt16 = in->yyt25 = in->yyt26 = in->cur;
			goto yy6;
		default: goto yy8;
	}
yy5:
	in->cur = in->mar;
	goto yy2;
yy6:
yyFillLabel3:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt6 = in->yyt7 = in->yyt35 = in->yyt36 = in->yyt37 = in->cur;
			goto yy9;
		case 'b':
			++in->cur;
			in->yyt2 = in->yyt15;
			in->yyt25 = in->yyt26 = in->cur;
			goto yy7;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel3;
			}
			goto yy5;
	}
yy7:
yyFillLabel4:
	yych = *in->cur;
yy8:
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt15 = in->cur;
			goto yy10;
		case 'b':
			++in->cur;
			in->yyt25 = in->yyt26 = in->cur;
			goto yy7;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel4;
			}
			goto yy5;
	}
yy9:
yyFillLabel5:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel5;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->yyt24 = in->cur;
			goto yy11;
		default: goto yy13;
	}
yy10:
yyFillLabel6:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt6 = in->yyt7 = in->yyt24 = in->cur;
			goto yy14;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel6;
			}
			goto yy5;
	}
yy11:
yyFillLabel7:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt12 = in->yyt13 = in->yyt14 = in->yyt31 = in->yyt32 = in->yyt33 = in->yyt34 = in->cur;
			goto yy15;
		case 'b':
			++in->cur;
			in->yyt2 = in->yyt15;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			in->yyt5 = in->yyt16;
			in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->cur;
			goto yy12;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel7;
			}
			goto yy5;
	}
yy12:
yyFillLabel8:
	yych = *in->cur;
yy13:
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt15 = in->yyt16 = in->cur;
			goto yy16;
		case 'b':
			++in->cur;
			in->yyt8 = in->yyt9 = in->yyt10 = in->yyt11 = in->cur;
			goto yy12;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel8;
			}
			goto yy5;
	}
yy14:
yyFillLabel9:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel9;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt23 = in->yyt31 = in->yyt32 = in->cur;
			goto yy17;
		default: goto yy19;
	}
yy15:
yyFillLabel10:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel10;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt17 = in->yyt18 = in->yyt19 = in->yyt20 = in->yyt21 = in->yyt22 = in->yyt23 = in->cur;
			goto yy20;
		default: goto yy22;
	}
yy16:
yyFillLabel11:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt13 = in->yyt14 = in->yyt24 = in->yyt25 = in->yyt26 = in->cur;
			goto yy23;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel11;
			}
			goto yy5;
	}
yy17:
yyFillLabel12:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt13 = in->yyt14 = in->yyt18 = in->yyt19 = in->yyt20 = in->cur;
			goto yy24;
		case 'b':
			++in->cur;
			in->yyt26 = in->yyt15;
			in->yyt31 = in->yyt32 = in->cur;
			goto yy18;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel12;
			}
			goto yy5;
	}
yy18:
yyFillLabel13:
	yych = *in->cur;
yy19:
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt15 = in->cur;
			goto yy25;
		case 'b':
			++in->cur;
			in->yyt31 = in->yyt32 = in->cur;
			goto yy18;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel13;
			}
			goto yy5;
	}
yy20:
yyFillLabel14:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt27 = in->yyt28 = in->yyt29 = in->yyt30 = in->cur;
			goto yy26;
		case 'b':
			++in->cur;
			in->yyt2 = in->yyt15;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			in->yyt5 = in->yyt16;
			in->yyt6 = in->yyt10;
			in->yyt7 = in->yyt11;
			in->yyt35 = in->yyt24;
			in->yyt36 = in->yyt8;
			in->yyt37 = in->yyt9;
			in->yyt18 = in->yyt19 = in->yyt20 = in->yyt21 = in->yyt22 = in->yyt23 = in->cur;
			goto yy21;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel14;
			}
			goto yy5;
	}
yy21:
yyFillLabel15:
	yych = *in->cur;
yy22:
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
			goto yy27;
		case 'b':
			++in->cur;
			in->yyt18 = in->yyt19 = in->yyt20 = in->yyt21 = in->yyt22 = in->yyt23 = in->cur;
			goto yy21;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel15;
			}
			goto yy5;
	}
yy23:
yyFillLabel16:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel16;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt23 = in->yyt31 = in->yyt32 = in->yyt33 = in->yyt34 = in->cur;
			goto yy28;
		default: goto yy30;
	}
yy24:
yyFillLabel17:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel17;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt21 = in->yyt22 = in->yyt35 = in->yyt36 = in->yyt37 = in->cur;
			goto yy31;
		default: goto yy33;
	}
yy25:
yyFillLabel18:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt13 = in->yyt14 = in->yyt16 = in->cur;
			goto yy34;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel18;
			}
			goto yy5;
	}
yy26:
yyFillLabel19:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt2 = in->yyt15;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			in->yyt6 = in->yyt10;
			in->yyt7 = in->yyt11;
			in->yyt10 = in->yyt34;
			in->yyt11 = in->yyt12;
			in->yyt13 = in->yyt22;
			in->yyt14 = in->yyt23;
			in->yyt15 = in->yyt5;
			in->yyt22 = in->yyt30;
			in->yyt23 = in->yyt30;
			in->yyt25 = in->yyt36;
			in->yyt26 = in->yyt37;
			in->yyt30 = in->cur;
			in->yyt5 = in->yyt16;
			in->yyt12 = in->yyt21;
			in->yyt16 = in->yyt35;
			in->yyt21 = in->yyt29;
			in->yyt34 = in->yyt20;
			in->yyt36 = in->yyt8;
			in->yyt37 = in->yyt9;
			in->yyt8 = in->yyt32;
			in->yyt9 = in->yyt33;
			in->yyt20 = in->yyt29;
			in->yyt29 = in->cur;
			in->yyt32 = in->yyt18;
			in->yyt33 = in->yyt19;
			in->yyt35 = in->yyt24;
			in->yyt18 = in->yyt28;
			in->yyt19 = in->yyt28;
			in->yyt24 = in->yyt31;
			in->yyt28 = in->cur;
			in->yyt31 = in->yyt17;
			in->yyt17 = in->yyt27;
			in->yyt27 = in->cur;
			goto yy26;
		case 'b':
			++in->cur;
			in->yyt18 = in->yyt19 = in->yyt20 = in->yyt21 = in->yyt22 = in->yyt23 = in->cur;
			goto yy36;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel19;
			}
			goto yy5;
	}
yy27:
yyFillLabel20:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt8 = in->yyt13 = in->yyt24 = in->yyt25 = in->yyt26 = in->cur;
			goto yy37;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel20;
			}
			goto yy5;
	}
yy28:
yyFillLabel21:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt6 = in->yyt18 = in->yyt19 = in->yyt20 = in->cur;
			goto yy38;
		case 'b':
			++in->cur;
			in->yyt9 = in->yyt15;
			in->yyt11 = in->yyt16;
			in->yyt31 = in->yyt32 = in->yyt33 = in->yyt34 = in->cur;
			goto yy29;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel21;
			}
			goto yy5;
	}
yy29:
yyFillLabel22:
	yych = *in->cur;
yy30:
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt14 = in->yyt15 = in->cur;
			goto yy39;
		case 'b':
			++in->cur;
			in->yyt31 = in->yyt32 = in->yyt33 = in->yyt34 = in->cur;
			goto yy29;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel22;
			}
			goto yy5;
	}
yy31:
yyFillLabel23:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt3 = in->yyt4 = in->yyt5 = in->cur;
			goto yy40;
		case 'b':
			++in->cur;
			in->yyt6 = in->yyt31;
			in->yyt7 = in->yyt32;
			in->yyt24 = in->yyt23;
			in->yyt26 = in->yyt15;
			in->yyt22 = in->yyt35 = in->yyt36 = in->yyt37 = in->cur;
			goto yy32;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel23;
			}
			goto yy5;
	}
yy32:
yyFillLabel24:
	yych = *in->cur;
yy33:
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt14 = in->yyt15 = in->cur;
			goto yy41;
		case 'b':
			++in->cur;
			in->yyt22 = in->yyt35 = in->yyt36 = in->yyt37 = in->cur;
			goto yy32;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel24;
			}
			goto yy5;
	}
yy34:
yyFillLabel25:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel25;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt18 = in->yyt19 = in->yyt20 = in->cur;
			goto yy42;
		default: goto yy44;
	}
yy35:
	a0 = in->yyt1;
	b0 = in->yyt2;
	a1 = in->yyt3;
	b1 = in->yyt4;
	a2 = in->yyt6;
	b2 = in->yyt7;
	a3 = in->yyt13;
	b3 = in->yyt14;
#line 17 "../../../benchmarks/submatch_dfa_aot/src/re2c/24__cat4_2.re"
	{
        outs(out, a0, b0); outc(out, '.'); outs(out, b0, a1); outc(out, '.');
        outs(out, a1, b1); outc(out, '.'); outs(out, b1, a2); outc(out, '.');
        outs(out, a2, b2); outc(out, '.'); outs(out, b2, a3); outc(out, '.');
        outs(out, a3, b3); outc(out, '.'); outs(out, b3, in->cur);
        goto loop;
    }
#line 811 "gen/re2c/24__cat4_2-eof-tdfa0.c"
yy36:
yyFillLabel26:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt2 = in->yyt5;
			in->yyt3 = in->yyt36;
			in->yyt4 = in->yyt37;
			in->yyt6 = in->yyt34;
			in->yyt7 = in->yyt12;
			in->yyt14 = in->yyt15 = in->yyt16 = in->cur;
			in->yyt5 = in->yyt35;
			in->yyt35 = in->yyt31;
			in->yyt36 = in->yyt32;
			in->yyt37 = in->yyt33;
			goto yy27;
		case 'b':
			++in->cur;
			in->yyt18 = in->yyt19 = in->yyt20 = in->yyt21 = in->yyt22 = in->yyt23 = in->cur;
			goto yy36;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel26;
			}
			goto yy5;
	}
yy37:
yyFillLabel27:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel27;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt23 = in->yyt31 = in->yyt32 = in->yyt33 = in->yyt34 = in->cur;
			goto yy45;
		default: goto yy47;
	}
yy38:
yyFillLabel28:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel28;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt21 = in->yyt22 = in->yyt35 = in->yyt36 = in->yyt37 = in->cur;
			goto yy48;
		default: goto yy50;
	}
yy39:
yyFillLabel29:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt6 = in->yyt13 = in->yyt16 = in->cur;
			goto yy51;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel29;
			}
			goto yy5;
	}
yy40:
yyFillLabel30:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt6 = in->yyt31;
			in->yyt7 = in->yyt32;
			in->yyt13 = in->yyt36;
			in->yyt14 = in->yyt37;
			in->yyt26 = in->yyt15;
			in->yyt31 = in->yyt19;
			in->yyt32 = in->yyt20;
			in->yyt36 = in->yyt5;
			in->yyt37 = in->yyt5;
			in->yyt15 = in->yyt24;
			in->yyt5 = in->cur;
			in->yyt19 = in->yyt22;
			in->yyt20 = in->yyt35;
			in->yyt22 = in->yyt4;
			in->yyt24 = in->yyt23;
			in->yyt35 = in->yyt4;
			in->yyt23 = in->yyt18;
			in->yyt4 = in->cur;
			in->yyt18 = in->yyt21;
			in->yyt21 = in->yyt3;
			in->yyt3 = in->cur;
			goto yy40;
		case 'b':
			++in->cur;
			in->yyt22 = in->yyt35 = in->yyt36 = in->yyt37 = in->cur;
			goto yy52;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel30;
			}
			goto yy5;
	}
yy41:
yyFillLabel31:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt3 = in->yyt13 = in->yyt16 = in->cur;
			goto yy53;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel31;
			}
			goto yy5;
	}
yy42:
yyFillLabel32:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt3 = in->yyt4 = in->cur;
			goto yy54;
		case 'b':
			++in->cur;
			in->yyt32 = in->yyt15;
			in->yyt19 = in->yyt20 = in->cur;
			goto yy43;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel32;
			}
			goto yy5;
	}
yy43:
yyFillLabel33:
	yych = *in->cur;
yy44:
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt3 = in->cur;
			goto yy55;
		case 'b':
			++in->cur;
			in->yyt19 = in->yyt20 = in->cur;
			goto yy43;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel33;
			}
			goto yy5;
	}
yy45:
yyFillLabel34:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt13 = in->yyt22;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt2 = in->yyt5;
			in->yyt3 = in->yyt36;
			in->yyt4 = in->yyt37;
			in->yyt9 = in->yyt19;
			in->yyt10 = in->yyt20;
			in->yyt11 = in->yyt21;
			in->yyt14 = in->yyt8;
			in->yyt8 = in->yyt18;
			in->yyt6 = in->yyt18 = in->yyt19 = in->yyt20 = in->cur;
			in->yyt5 = in->yyt35;
			goto yy38;
		case 'b':
			++in->cur;
			in->yyt19 = in->yyt15;
			in->yyt21 = in->yyt16;
			in->yyt23 = in->yyt14;
			in->yyt31 = in->yyt32 = in->yyt33 = in->yyt34 = in->cur;
			goto yy46;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel34;
			}
			goto yy5;
	}
yy46:
yyFillLabel35:
	yych = *in->cur;
yy47:
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt13 = in->yyt22;
			in->yyt14 = in->yyt23;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt2 = in->yyt5;
			in->yyt3 = in->yyt36;
			in->yyt4 = in->yyt37;
			in->yyt8 = in->yyt18;
			in->yyt9 = in->yyt19;
			in->yyt10 = in->yyt20;
			in->yyt11 = in->yyt21;
			in->yyt14 = in->yyt15 = in->cur;
			in->yyt5 = in->yyt35;
			goto yy39;
		case 'b':
			++in->cur;
			in->yyt31 = in->yyt32 = in->yyt33 = in->yyt34 = in->cur;
			goto yy46;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel35;
			}
			goto yy5;
	}
yy48:
yyFillLabel36:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt6 = in->yyt10;
			in->yyt7 = in->yyt16;
			in->yyt13 = in->yyt33;
			in->yyt14 = in->yyt34;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt2 = in->yyt5;
			in->yyt7 = in->yyt26;
			in->yyt13 = in->yyt6;
			in->yyt14 = in->yyt6;
			in->yyt26 = in->yyt9;
			in->yyt6 = in->yyt25;
			in->yyt25 = in->yyt8;
			in->yyt3 = in->yyt4 = in->yyt5 = in->cur;
			goto yy40;
		case 'b':
			++in->cur;
			in->yyt9 = in->yyt15;
			in->yyt11 = in->yyt16;
			in->yyt13 = in->yyt33;
			in->yyt14 = in->yyt34;
			in->yyt24 = in->yyt23;
			in->yyt25 = in->yyt31;
			in->yyt26 = in->yyt32;
			in->yyt22 = in->yyt35 = in->yyt36 = in->yyt37 = in->cur;
			goto yy49;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel36;
			}
			goto yy5;
	}
yy49:
yyFillLabel37:
	yych = *in->cur;
yy50:
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt6 = in->yyt10;
			in->yyt7 = in->yyt11;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt2 = in->yyt5;
			in->yyt6 = in->yyt25;
			in->yyt7 = in->yyt26;
			in->yyt25 = in->yyt8;
			in->yyt26 = in->yyt9;
			in->yyt14 = in->yyt15 = in->cur;
			goto yy41;
		case 'b':
			++in->cur;
			in->yyt22 = in->yyt35 = in->yyt36 = in->yyt37 = in->cur;
			goto yy49;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel37;
			}
			goto yy5;
	}
yy51:
yyFillLabel38:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel38;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt18 = in->yyt19 = in->yyt20 = in->cur;
			goto yy56;
		default: goto yy58;
	}
yy52:
yyFillLabel39:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt6 = in->yyt19;
			in->yyt7 = in->yyt20;
			in->yyt26 = in->yyt24;
			in->yyt14 = in->yyt15 = in->cur;
			in->yyt24 = in->yyt18;
			goto yy41;
		case 'b':
			++in->cur;
			in->yyt22 = in->yyt35 = in->yyt36 = in->yyt37 = in->cur;
			goto yy52;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel39;
			}
			goto yy5;
	}
yy53:
yyFillLabel40:
	yych = *in->cur;
	switch (yych) {
		case 0x00:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel40;
			}
			goto yy5;
		case 'a':
			++in->cur;
			in->yyt18 = in->yyt19 = in->yyt20 = in->cur;
			goto yy59;
		default: goto yy61;
	}
yy54:
yyFillLabel41:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			in->yyt6 = in->yyt31;
			in->yyt7 = in->yyt32;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt13 = in->yyt19;
			in->yyt14 = in->yyt20;
			in->yyt19 = in->yyt4;
			in->yyt20 = in->yyt4;
			in->yyt32 = in->yyt15;
			in->yyt15 = in->yyt16;
			in->yyt4 = in->cur;
			in->yyt16 = in->yyt18;
			in->yyt18 = in->yyt3;
			in->yyt3 = in->cur;
			goto yy54;
		case 'b':
			++in->cur;
			in->yyt19 = in->yyt20 = in->cur;
			goto yy62;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel41;
			}
			goto yy5;
	}
yy55:
yyFillLabel42:
	yych = *in->cur;
	switch (yych) {
		case 'a':
			++in->cur;
			in->yyt4 = in->cur;
			goto yy63;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel42;
			}
			goto yy5;
	}
yy56:
yyFillLabel43:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt6 = in->yyt10;
			in->yyt7 = in->yyt11;
			in->yyt13 = in->yyt33;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt2 = in->yyt5;
			in->yyt14 = in->yyt6;
			in->yyt25 = in->yyt8;
			in->yyt26 = in->yyt9;
			in->yyt3 = in->yyt4 = in->cur;
			goto yy54;
		case 'b':
			++in->cur;
			in->yyt32 = in->yyt15;
			in->yyt34 = in->yyt14;
			in->yyt19 = in->yyt20 = in->cur;
			goto yy57;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel43;
			}
			goto yy5;
	}
yy57:
yyFillLabel44:
	yych = *in->cur;
yy58:
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt6 = in->yyt10;
			in->yyt7 = in->yyt11;
			in->yyt13 = in->yyt33;
			in->yyt14 = in->yyt34;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt2 = in->yyt5;
			in->yyt25 = in->yyt8;
			in->yyt26 = in->yyt9;
			in->yyt3 = in->cur;
			goto yy55;
		case 'b':
			++in->cur;
			in->yyt19 = in->yyt20 = in->cur;
			goto yy57;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel44;
			}
			goto yy5;
	}
yy59:
yyFillLabel45:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			in->yyt13 = in->yyt36;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt14 = in->yyt3;
			in->yyt26 = in->yyt24;
			in->yyt31 = in->yyt22;
			in->yyt32 = in->yyt35;
			in->yyt3 = in->yyt4 = in->cur;
			goto yy54;
		case 'b':
			++in->cur;
			in->yyt35 = in->yyt15;
			in->yyt37 = in->yyt14;
			in->yyt19 = in->yyt20 = in->cur;
			goto yy60;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel45;
			}
			goto yy5;
	}
yy60:
yyFillLabel46:
	yych = *in->cur;
yy61:
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			in->yyt13 = in->yyt36;
			in->yyt14 = in->yyt37;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt26 = in->yyt24;
			in->yyt31 = in->yyt22;
			in->yyt32 = in->yyt35;
			in->yyt3 = in->cur;
			goto yy55;
		case 'b':
			++in->cur;
			in->yyt19 = in->yyt20 = in->cur;
			goto yy60;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel46;
			}
			goto yy5;
	}
yy62:
yyFillLabel47:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			in->yyt6 = in->yyt31;
			in->yyt7 = in->yyt32;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt32 = in->yyt16;
			in->yyt3 = in->cur;
			goto yy55;
		case 'b':
			++in->cur;
			in->yyt19 = in->yyt20 = in->cur;
			goto yy62;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel47;
			}
			goto yy5;
	}
yy63:
yyFillLabel48:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			in->yyt6 = in->yyt31;
			in->yyt7 = in->yyt32;
			in->yyt13 = in->yyt19;
			in->yyt14 = in->yyt20;
			goto yy35;
		case 'a':
			++in->cur;
			in->yyt20 = in->yyt3;
			in->yyt3 = in->yyt4;
			in->yyt4 = in->cur;
			goto yy63;
		case 'b':
			++in->cur;
			goto yy64;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel48;
			}
			goto yy5;
	}
yy64:
yyFillLabel49:
	yych = *in->cur;
	switch (yych) {
		case '\n':
			++in->cur;
			in->yyt3 = in->yyt25;
			in->yyt4 = in->yyt26;
			in->yyt6 = in->yyt31;
			in->yyt7 = in->yyt32;
			in->yyt13 = in->yyt19;
			in->yyt14 = in->yyt20;
			goto yy35;
		case 'b':
			++in->cur;
			goto yy64;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel49;
			}
			goto yy5;
	}
yy65:
#line 5 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"
	{ return 0; }
#line 1417 "gen/re2c/24__cat4_2-eof-tdfa0.c"
}
#line 24 "../../../benchmarks/submatch_dfa_aot/src/re2c/24__cat4_2.re"

}
