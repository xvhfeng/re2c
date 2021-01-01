/* Generated by re2c 2.0.3 */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/apache_log.re"
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
        *h1, *i1, *a1, *d1, *r1, *s1, *z1, *u1, *g1,
        *h2, *i2, *a2, *d2, *r2, *s2, *z2, *u2, *g2;

loop:
    in->tok = in->cur;

#line 208 "gen/re2c/apache_log-bc-tdfa1.c"
{
	char yych;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case 0x00:	goto yy2;
	case '.':
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
		in->yyt1 = in->cur;
		goto yy6;
	default:	goto yy4;
	}
yy2:
	++in->cur;
#line 3 "../../../benchmarks/submatch_dfa_aot/src/re2c/include_bc/fill.re"
	{ return 0; }
#line 234 "gen/re2c/apache_log-bc-tdfa1.c"
yy4:
	++in->cur;
yy5:
#line 33 "../../../benchmarks/submatch_dfa_aot/src/re2c/apache_log.re"
	{ return 1; }
#line 240 "gen/re2c/apache_log-bc-tdfa1.c"
yy6:
	yych = *(in->mar = ++in->cur);
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt2 = in->cur;
		goto yy7;
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy10;
	default:	goto yy5;
	}
yy7:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':	goto yy7;
	case '-':	goto yy12;
	default:	goto yy9;
	}
yy9:
	in->cur = in->mar;
	goto yy5;
yy10:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt2 = in->cur;
		goto yy7;
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy10;
	default:	goto yy9;
	}
yy12:
	yych = *++in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt3 = in->cur;
		goto yy13;
	default:	goto yy9;
	}
yy13:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':	goto yy13;
	case '-':	goto yy15;
	default:	goto yy9;
	}
yy15:
	yych = *++in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt4 = in->cur;
		goto yy16;
	default:	goto yy9;
	}
yy16:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':	goto yy16;
	case '[':
		in->yyt5 = in->cur;
		goto yy18;
	default:	goto yy9;
	}
yy18:
	yych = *++in->cur;
	switch (yych) {
	case ']':	goto yy9;
	default:	goto yy20;
	}
yy19:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
yy20:
	switch (yych) {
	case '\n':	goto yy9;
	case ']':	goto yy21;
	default:	goto yy19;
	}
yy21:
	yych = *++in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt6 = in->cur;
		goto yy22;
	default:	goto yy9;
	}
yy22:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':	goto yy22;
	case '"':
		in->yyt7 = in->cur;
		goto yy24;
	default:	goto yy9;
	}
yy24:
	yych = *++in->cur;
	switch (yych) {
	case '"':	goto yy9;
	default:	goto yy26;
	}
yy25:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
yy26:
	switch (yych) {
	case '\n':	goto yy9;
	case '"':	goto yy27;
	default:	goto yy25;
	}
yy27:
	yych = *++in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt8 = in->cur;
		goto yy28;
	default:	goto yy9;
	}
yy28:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':	goto yy28;
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
		in->yyt9 = in->cur;
		goto yy30;
	default:	goto yy9;
	}
yy30:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt10 = in->cur;
		goto yy32;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy30;
	default:	goto yy9;
	}
yy32:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':	goto yy32;
	case '-':
		in->yyt11 = in->cur;
		goto yy34;
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
		in->yyt11 = in->cur;
		goto yy35;
	default:	goto yy9;
	}
yy34:
	yych = *++in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt12 = in->cur;
		goto yy37;
	default:	goto yy9;
	}
yy35:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt12 = in->cur;
		goto yy37;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy35;
	default:	goto yy9;
	}
yy37:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':	goto yy37;
	case '"':
		in->yyt13 = in->cur;
		goto yy39;
	default:	goto yy9;
	}
yy39:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':	goto yy9;
	case '"':	goto yy41;
	default:	goto yy39;
	}
yy41:
	yych = *++in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		in->yyt14 = in->cur;
		goto yy42;
	default:	goto yy9;
	}
yy42:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':	goto yy42;
	case '"':
		in->yyt15 = in->cur;
		goto yy44;
	default:	goto yy9;
	}
yy44:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
	case '\n':	goto yy9;
	case '"':	goto yy46;
	default:	goto yy44;
	}
yy46:
	yych = *++in->cur;
	switch (yych) {
	case '\n':	goto yy47;
	default:	goto yy9;
	}
yy47:
	++in->cur;
	h1 = in->yyt1;
	h2 = in->yyt2;
	i2 = in->yyt3;
	a2 = in->yyt4;
	d1 = in->yyt5;
	d2 = in->yyt6;
	r1 = in->yyt7;
	r2 = in->yyt8;
	s1 = in->yyt9;
	s2 = in->yyt10;
	z1 = in->yyt11;
	z2 = in->yyt12;
	u1 = in->yyt13;
	u2 = in->yyt14;
	g1 = in->yyt15;
	i1 = in->yyt3 - 1;
	a1 = in->yyt4 - 1;
	g2 = in->cur - 1;
#line 34 "../../../benchmarks/submatch_dfa_aot/src/re2c/apache_log.re"
	{
        OUT("host: ",     h1, h2);
        OUT("userid: ",   i1, i2);
        OUT("authuser: ", a1, a2);
        OUT("date: ",     d1, d2);
        OUT("request: ",  r1, r2);
        OUT("status: ",   s1, s2);
        OUT("size: ",     z1, z2);
        OUT("url: ",      u1, u2);
        OUT("agent: ",    g1, g2);
        outc(out, '\n');
        goto loop;
    }
#line 585 "gen/re2c/apache_log-bc-tdfa1.c"
}
#line 47 "../../../benchmarks/submatch_dfa_aot/src/re2c/apache_log.re"

}
