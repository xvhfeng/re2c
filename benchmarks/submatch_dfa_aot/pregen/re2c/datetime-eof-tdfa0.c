/* Generated by re2c 2.0.3 */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/datetime.re"
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
char *yyt2;

    
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
    if (in->yyt1) in->yyt1 -= free;
if (in->yyt2) in->yyt2 -= free;


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


static int lex(input_t *in, Output *out)
{
    const char
        *s1, *y1, *h1, *m1, *d1, *M1, *z1,
        *s2, *y2, *h2, *m2, *d2, *M2, *z2;
loop:
    in->tok = in->cur;

#line 165 "gen/re2c/datetime-eof-tdfa0.c"
{
	char yych;
	in->yyt1 = in->cur;
yyFillLabel3_0:
	yych = *in->cur;
	switch (yych) {
	case '0':
		++in->cur;
		goto yy4;
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
		goto yy5;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_0;
			goto yy42;
		}
		++in->cur;
		goto yy2;
	}
yy2:
yy3:
#line 20 "../../../benchmarks/submatch_dfa_aot/src/re2c/datetime.re"
	{ return 1; }
#line 198 "gen/re2c/datetime-eof-tdfa0.c"
yy4:
	in->mar = in->cur;
yyFillLabel3_1:
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
	case '9':
		++in->cur;
		goto yy6;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_1;
		}
		goto yy3;
	}
yy5:
	in->mar = in->cur;
yyFillLabel3_2:
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
	case '9':
		++in->cur;
		goto yy8;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_2;
		}
		goto yy3;
	}
yy6:
yyFillLabel3_3:
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
	case '9':
		++in->cur;
		goto yy9;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_3;
		}
		goto yy7;
	}
yy7:
	in->cur = in->mar;
	goto yy3;
yy8:
yyFillLabel3_4:
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
	case '9':
		++in->cur;
		goto yy10;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_4;
		}
		goto yy7;
	}
yy9:
yyFillLabel3_5:
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
	case '9':
		++in->cur;
		goto yy11;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_5;
		}
		goto yy7;
	}
yy10:
yyFillLabel3_6:
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
	case '9':
		++in->cur;
		goto yy12;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_6;
		}
		goto yy7;
	}
yy11:
yyFillLabel3_7:
	yych = *in->cur;
	switch (yych) {
	case '-':
		++in->cur;
		goto yy14;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_7;
		}
		goto yy7;
	}
yy12:
yyFillLabel3_8:
	yych = *in->cur;
	switch (yych) {
	case '-':
		++in->cur;
		goto yy14;
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
		goto yy12;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_8;
		}
		goto yy7;
	}
yy14:
yyFillLabel3_9:
	yych = *in->cur;
	switch (yych) {
	case '0':
		++in->cur;
		goto yy15;
	case '1':
		++in->cur;
		goto yy16;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_9;
		}
		goto yy7;
	}
yy15:
yyFillLabel3_10:
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
	case '9':
		++in->cur;
		goto yy17;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_10;
		}
		goto yy7;
	}
yy16:
yyFillLabel3_11:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
		++in->cur;
		goto yy17;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_11;
		}
		goto yy7;
	}
yy17:
yyFillLabel3_12:
	yych = *in->cur;
	switch (yych) {
	case '-':
		++in->cur;
		goto yy18;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_12;
		}
		goto yy7;
	}
yy18:
yyFillLabel3_13:
	yych = *in->cur;
	switch (yych) {
	case '0':
		++in->cur;
		goto yy19;
	case '1':
	case '2':
		++in->cur;
		goto yy20;
	case '3':
		++in->cur;
		goto yy21;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_13;
		}
		goto yy7;
	}
yy19:
yyFillLabel3_14:
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
	case '9':
		++in->cur;
		goto yy22;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_14;
		}
		goto yy7;
	}
yy20:
yyFillLabel3_15:
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
	case '9':
		++in->cur;
		goto yy22;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_15;
		}
		goto yy7;
	}
yy21:
yyFillLabel3_16:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
		++in->cur;
		goto yy22;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_16;
		}
		goto yy7;
	}
yy22:
yyFillLabel3_17:
	yych = *in->cur;
	switch (yych) {
	case 'T':
		++in->cur;
		goto yy23;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_17;
		}
		goto yy7;
	}
yy23:
yyFillLabel3_18:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
		++in->cur;
		goto yy24;
	case '2':
		++in->cur;
		goto yy25;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_18;
		}
		goto yy7;
	}
yy24:
yyFillLabel3_19:
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
	case '9':
		++in->cur;
		goto yy26;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_19;
		}
		goto yy7;
	}
yy25:
yyFillLabel3_20:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
		++in->cur;
		goto yy26;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_20;
		}
		goto yy7;
	}
yy26:
yyFillLabel3_21:
	yych = *in->cur;
	switch (yych) {
	case ':':
		++in->cur;
		goto yy27;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_21;
		}
		goto yy7;
	}
yy27:
yyFillLabel3_22:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
		++in->cur;
		goto yy28;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_22;
		}
		goto yy7;
	}
yy28:
yyFillLabel3_23:
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
	case '9':
		++in->cur;
		goto yy29;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_23;
		}
		goto yy7;
	}
yy29:
yyFillLabel3_24:
	yych = *in->cur;
	switch (yych) {
	case ':':
		++in->cur;
		goto yy30;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_24;
		}
		goto yy7;
	}
yy30:
yyFillLabel3_25:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
		++in->cur;
		goto yy31;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_25;
		}
		goto yy7;
	}
yy31:
yyFillLabel3_26:
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
	case '9':
		++in->cur;
		in->yyt2 = in->cur;
		goto yy32;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_26;
		}
		goto yy7;
	}
yy32:
yyFillLabel3_27:
	yych = *in->cur;
	switch (yych) {
	case '+':
	case '-':
		++in->cur;
		goto yy33;
	case 'Z':
		++in->cur;
		goto yy34;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_27;
		}
		goto yy7;
	}
yy33:
yyFillLabel3_28:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
		++in->cur;
		goto yy35;
	case '2':
		++in->cur;
		goto yy36;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_28;
		}
		goto yy7;
	}
yy34:
yyFillLabel3_29:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy37;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_29;
		}
		goto yy7;
	}
yy35:
yyFillLabel3_30:
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
	case '9':
		++in->cur;
		goto yy39;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_30;
		}
		goto yy7;
	}
yy36:
yyFillLabel3_31:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
		++in->cur;
		goto yy39;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_31;
		}
		goto yy7;
	}
yy37:
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
#line 21 "../../../benchmarks/submatch_dfa_aot/src/re2c/datetime.re"
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
#line 803 "gen/re2c/datetime-eof-tdfa0.c"
yy39:
yyFillLabel3_32:
	yych = *in->cur;
	switch (yych) {
	case ':':
		++in->cur;
		goto yy40;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_32;
		}
		goto yy7;
	}
yy40:
yyFillLabel3_33:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
		++in->cur;
		goto yy41;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_33;
		}
		goto yy7;
	}
yy41:
yyFillLabel3_34:
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
	case '9':
		++in->cur;
		goto yy34;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_34;
		}
		goto yy7;
	}
yy42:
#line 5 "../../../benchmarks/submatch_dfa_aot/src/re2c/include_eof/fill.re"
	{ return 0; }
#line 860 "gen/re2c/datetime-eof-tdfa0.c"
}
#line 32 "../../../benchmarks/submatch_dfa_aot/src/re2c/datetime.re"

}
