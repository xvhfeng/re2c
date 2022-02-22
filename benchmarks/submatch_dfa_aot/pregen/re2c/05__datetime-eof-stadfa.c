/* Generated by re2c */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/05__datetime.re"
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
    
#line 30 "gen/re2c/05__datetime-eof-stadfa.c"
char *yyt1;
char *yyt2;
char *yyt3;
char *yyt4;
char *yyt5;
#line 34 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    
#line 39 "gen/re2c/05__datetime-eof-stadfa.c"
#line 35 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    
#line 50 "gen/re2c/05__datetime-eof-stadfa.c"
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
    
#line 108 "gen/re2c/05__datetime-eof-stadfa.c"
if (in->yyt1) in->yyt1 -= free;
if (in->yyt2) in->yyt2 -= free;
if (in->yyt3) in->yyt3 -= free;
if (in->yyt4) in->yyt4 -= free;
if (in->yyt5) in->yyt5 -= free;
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
    
#line 135 "gen/re2c/05__datetime-eof-stadfa.c"
in->yyt1 = 0;
in->yyt2 = 0;
in->yyt3 = 0;
in->yyt4 = 0;
in->yyt5 = 0;
#line 40 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"

    
#line 144 "gen/re2c/05__datetime-eof-stadfa.c"
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
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/05__datetime.re"


static int lex(input_t *in, Output *out)
{
    const char
        *s1, *y1, *h1, *m1, *d1, *M1, *z1,
        *s2, *y2, *h2, *m2, *d2, *M2, *z2;
loop:
    in->tok = in->cur;

#line 196 "gen/re2c/05__datetime-eof-stadfa.c"
{
	char yych;
yyFillLabel0:
	yych = *in->cur;
	switch (yych) {
		case '0': goto yy3;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy4;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel0;
				goto yy40;
			}
			goto yy1;
	}
yy1:
	++in->cur;
yy2:
#line 20 "../../../benchmarks/submatch_dfa_aot/src/re2c/05__datetime.re"
	{ return 1; }
#line 224 "gen/re2c/05__datetime-eof-stadfa.c"
yy3:
	in->mar = ++in->cur;
	in->yyt2 = in->cur - 1;
yyFillLabel1:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy5;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel1;
			}
			goto yy2;
	}
yy4:
	in->mar = ++in->cur;
	in->yyt1 = in->yyt2 = in->cur - 1;
yyFillLabel2:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy7;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel2;
			}
			goto yy2;
	}
yy5:
	++in->cur;
	in->yyt3 = in->yyt2;
yyFillLabel3:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy8;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel3;
			}
			goto yy6;
	}
yy6:
	in->cur = in->mar;
	goto yy2;
yy7:
	++in->cur;
	in->yyt3 = in->yyt2;
	in->yyt2 = in->yyt1;
yyFillLabel4:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy9;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel4;
			}
			goto yy6;
	}
yy8:
	++in->cur;
	in->yyt4 = in->yyt3;
yyFillLabel5:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy10;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel5;
			}
			goto yy6;
	}
yy9:
	++in->cur;
	in->yyt4 = in->yyt3;
	in->yyt3 = in->yyt2;
	in->yyt2 = in->yyt1;
yyFillLabel6:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy11;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel6;
			}
			goto yy6;
	}
yy10:
	++in->cur;
	in->yyt5 = in->yyt4;
yyFillLabel7:
	yych = *in->cur;
	switch (yych) {
		case '-': goto yy12;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel7;
			}
			goto yy6;
	}
yy11:
	++in->cur;
	in->yyt5 = in->yyt4;
	in->yyt4 = in->yyt3;
	in->yyt3 = in->yyt2;
	in->yyt2 = in->yyt1;
yyFillLabel8:
	yych = *in->cur;
	switch (yych) {
		case '-': goto yy12;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy11;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel8;
			}
			goto yy6;
	}
yy12:
	++in->cur;
yyFillLabel9:
	yych = *in->cur;
	switch (yych) {
		case '0': goto yy13;
		case '1': goto yy14;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel9;
			}
			goto yy6;
	}
yy13:
	++in->cur;
yyFillLabel10:
	yych = *in->cur;
	switch (yych) {
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy15;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel10;
			}
			goto yy6;
	}
yy14:
	++in->cur;
yyFillLabel11:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2': goto yy15;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel11;
			}
			goto yy6;
	}
yy15:
	++in->cur;
yyFillLabel12:
	yych = *in->cur;
	switch (yych) {
		case '-': goto yy16;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel12;
			}
			goto yy6;
	}
yy16:
	++in->cur;
yyFillLabel13:
	yych = *in->cur;
	switch (yych) {
		case '0': goto yy17;
		case '1':
		case '2': goto yy18;
		case '3': goto yy19;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel13;
			}
			goto yy6;
	}
yy17:
	++in->cur;
yyFillLabel14:
	yych = *in->cur;
	switch (yych) {
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy20;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel14;
			}
			goto yy6;
	}
yy18:
	++in->cur;
yyFillLabel15:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy20;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel15;
			}
			goto yy6;
	}
yy19:
	++in->cur;
yyFillLabel16:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1': goto yy20;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel16;
			}
			goto yy6;
	}
yy20:
	++in->cur;
yyFillLabel17:
	yych = *in->cur;
	switch (yych) {
		case 'T': goto yy21;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel17;
			}
			goto yy6;
	}
yy21:
	++in->cur;
yyFillLabel18:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1': goto yy22;
		case '2': goto yy23;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel18;
			}
			goto yy6;
	}
yy22:
	++in->cur;
yyFillLabel19:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy24;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel19;
			}
			goto yy6;
	}
yy23:
	++in->cur;
yyFillLabel20:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3': goto yy24;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel20;
			}
			goto yy6;
	}
yy24:
	++in->cur;
yyFillLabel21:
	yych = *in->cur;
	switch (yych) {
		case ':': goto yy25;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel21;
			}
			goto yy6;
	}
yy25:
	++in->cur;
yyFillLabel22:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5': goto yy26;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel22;
			}
			goto yy6;
	}
yy26:
	++in->cur;
yyFillLabel23:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy27;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel23;
			}
			goto yy6;
	}
yy27:
	++in->cur;
yyFillLabel24:
	yych = *in->cur;
	switch (yych) {
		case ':': goto yy28;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel24;
			}
			goto yy6;
	}
yy28:
	++in->cur;
yyFillLabel25:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5': goto yy29;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel25;
			}
			goto yy6;
	}
yy29:
	++in->cur;
yyFillLabel26:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy30;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel26;
			}
			goto yy6;
	}
yy30:
	++in->cur;
yyFillLabel27:
	yych = *in->cur;
	switch (yych) {
		case '+':
		case '-': goto yy31;
		case 'Z': goto yy32;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel27;
			}
			goto yy6;
	}
yy31:
	++in->cur;
	in->yyt1 = in->cur - 1;
yyFillLabel28:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1': goto yy33;
		case '2': goto yy34;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel28;
			}
			goto yy6;
	}
yy32:
	++in->cur;
	in->yyt1 = in->cur - 1;
yyFillLabel29:
	yych = *in->cur;
	switch (yych) {
		case '\n': goto yy35;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel29;
			}
			goto yy6;
	}
yy33:
	++in->cur;
yyFillLabel30:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy36;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel30;
			}
			goto yy6;
	}
yy34:
	++in->cur;
yyFillLabel31:
	yych = *in->cur;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3': goto yy36;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel31;
			}
			goto yy6;
	}
yy35:
	++in->cur;
	in->yyt2 = in->yyt1;
	in->yyt1 = in->yyt5;
	y1 = in->yyt1;
	z1 = in->yyt2;
	y2 = in->yyt2 - 15;
	m1 = in->yyt2 - 14;
	m2 = in->yyt2 - 12;
	d1 = in->yyt2 - 11;
	d2 = in->yyt2 - 9;
	h1 = in->yyt2 - 8;
	h2 = in->yyt2 - 6;
	M1 = in->yyt2 - 5;
	M2 = in->yyt2 - 3;
	s1 = in->yyt2 - 2;
	s2 = in->yyt2;
	z2 = in->cur - 1;
#line 21 "../../../benchmarks/submatch_dfa_aot/src/re2c/05__datetime.re"
	{
        OUT("year: ",    y1, y2);
        OUT("month: ",   m1, m2);
        OUT("day: ",     d1, d2);
        OUT("hours: ",   h1, h2);
        OUT("minutes: ", M1, M2);
        OUT("seconds: ", s1, s2);
        OUT("tz: ",      z1, z2);
        outc(out, '\n');
        goto loop;
    }
#line 800 "gen/re2c/05__datetime-eof-stadfa.c"
yy36:
	++in->cur;
yyFillLabel32:
	yych = *in->cur;
	switch (yych) {
		case ':': goto yy37;
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
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5': goto yy38;
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
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy39;
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
		case '\n': goto yy35;
		default:
			if (in->lim <= in->cur) {
				if (fill(in) == 0) goto yyFillLabel35;
			}
			goto yy6;
	}
yy40:
#line 5 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"
	{ return 0; }
#line 866 "gen/re2c/05__datetime-eof-stadfa.c"
}
#line 32 "../../../benchmarks/submatch_dfa_aot/src/re2c/05__datetime.re"

}
