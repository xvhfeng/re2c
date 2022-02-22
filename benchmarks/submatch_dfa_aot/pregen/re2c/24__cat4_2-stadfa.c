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
    
#line 30 "gen/re2c/24__cat4_2-stadfa.c"
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
char *yyt38;
char *yyt39;
char *yyt4;
char *yyt40;
char *yyt41;
char *yyt42;
char *yyt43;
char *yyt44;
char *yyt45;
char *yyt46;
char *yyt47;
char *yyt48;
char *yyt49;
char *yyt5;
char *yyt50;
char *yyt51;
char *yyt52;
char *yyt6;
char *yyt7;
char *yyt8;
char *yyt9;
#line 34 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    
#line 86 "gen/re2c/24__cat4_2-stadfa.c"
#line 35 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"

    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    
#line 97 "gen/re2c/24__cat4_2-stadfa.c"
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


#line 141 "gen/re2c/24__cat4_2-stadfa.c"
#define YYMAXFILL 8
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
    
#line 160 "gen/re2c/24__cat4_2-stadfa.c"
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
if (in->yyt38) in->yyt38 -= free;
if (in->yyt39) in->yyt39 -= free;
if (in->yyt4) in->yyt4 -= free;
if (in->yyt40) in->yyt40 -= free;
if (in->yyt41) in->yyt41 -= free;
if (in->yyt42) in->yyt42 -= free;
if (in->yyt43) in->yyt43 -= free;
if (in->yyt44) in->yyt44 -= free;
if (in->yyt45) in->yyt45 -= free;
if (in->yyt46) in->yyt46 -= free;
if (in->yyt47) in->yyt47 -= free;
if (in->yyt48) in->yyt48 -= free;
if (in->yyt49) in->yyt49 -= free;
if (in->yyt5) in->yyt5 -= free;
if (in->yyt50) in->yyt50 -= free;
if (in->yyt51) in->yyt51 -= free;
if (in->yyt52) in->yyt52 -= free;
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
    
#line 235 "gen/re2c/24__cat4_2-stadfa.c"
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
in->yyt38 = 0;
in->yyt39 = 0;
in->yyt4 = 0;
in->yyt40 = 0;
in->yyt41 = 0;
in->yyt42 = 0;
in->yyt43 = 0;
in->yyt44 = 0;
in->yyt45 = 0;
in->yyt46 = 0;
in->yyt47 = 0;
in->yyt48 = 0;
in->yyt49 = 0;
in->yyt5 = 0;
in->yyt50 = 0;
in->yyt51 = 0;
in->yyt52 = 0;
in->yyt6 = 0;
in->yyt7 = 0;
in->yyt8 = 0;
in->yyt9 = 0;
#line 41 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"

    
#line 291 "gen/re2c/24__cat4_2-stadfa.c"
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
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/24__cat4_2.re"


static int lex(input_t *in, Output *out)
{
    const char
        *a0, *a1, *a2, *a3,
        *b0, *b1, *b2, *b3;
loop:
    in->tok = in->cur;

#line 342 "gen/re2c/24__cat4_2-stadfa.c"
{
	char yych;
	if ((in->lim - in->cur) < 8) if (fill(in, 8) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case 0x00: goto yy1;
		case 'a': goto yy4;
		default: goto yy2;
	}
yy1:
	++in->cur;
#line 3 "../../../benchmarks/submatch_dfa_aot/src/re2c/include/fill.re"
	{ return 0; }
#line 356 "gen/re2c/24__cat4_2-stadfa.c"
yy2:
	++in->cur;
yy3:
#line 11 "../../../benchmarks/submatch_dfa_aot/src/re2c/24__cat4_2.re"
	{ return 1; }
#line 362 "gen/re2c/24__cat4_2-stadfa.c"
yy4:
	yych = *(in->mar = ++in->cur);
	in->yyt9 = in->yyt10 = in->cur - 1;
	switch (yych) {
		case 'a': goto yy5;
		default: goto yy3;
	}
yy5:
	yych = *++in->cur;
	in->yyt14 = in->yyt10;
	in->yyt13 = in->yyt10;
	in->yyt12 = in->yyt9;
	in->yyt11 = in->yyt9;
	in->yyt10 = in->cur - 1;
	switch (yych) {
		case 'a': goto yy7;
		case 'b': goto yy8;
		default: goto yy6;
	}
yy6:
	in->cur = in->mar;
	goto yy3;
yy7:
	yych = *++in->cur;
	in->yyt14 = in->yyt10;
	in->yyt18 = in->yyt13;
	in->yyt12 = in->yyt9;
	in->yyt17 = in->yyt11;
	in->yyt15 = in->yyt16 = in->cur - 1;
	in->yyt13 = in->yyt10;
	in->yyt11 = in->yyt9;
	in->yyt10 = in->cur - 1;
	switch (yych) {
		case 'a': goto yy9;
		case 'b': goto yy8;
		default: goto yy6;
	}
yy8:
	++in->cur;
	if ((in->lim - in->cur) < 6) if (fill(in, 6) != 0) return 1;
	yych = *in->cur;
	in->yyt13 = in->yyt14;
	in->yyt11 = in->yyt12;
	switch (yych) {
		case 'a': goto yy10;
		case 'b': goto yy8;
		default: goto yy6;
	}
yy9:
	yych = *++in->cur;
	in->yyt26 = in->yyt16;
	in->yyt25 = in->yyt16;
	in->yyt24 = in->yyt15;
	in->yyt23 = in->yyt15;
	in->yyt14 = in->yyt10;
	in->yyt22 = in->yyt18;
	in->yyt21 = in->yyt18;
	in->yyt12 = in->yyt9;
	in->yyt20 = in->yyt17;
	in->yyt19 = in->yyt17;
	in->yyt15 = in->yyt16 = in->cur - 1;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt10;
	in->yyt11 = in->yyt9;
	in->yyt10 = in->cur - 1;
	switch (yych) {
		case 'a': goto yy11;
		case 'b': goto yy12;
		default: goto yy6;
	}
yy10:
	yych = *++in->cur;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt9 = in->yyt15 = in->yyt16 = in->cur - 1;
	in->yyt13 = in->yyt14;
	in->yyt11 = in->yyt12;
	switch (yych) {
		case 'a': goto yy13;
		default: goto yy6;
	}
yy11:
	yych = *++in->cur;
	in->yyt26 = in->yyt16;
	in->yyt32 = in->yyt25;
	in->yyt24 = in->yyt15;
	in->yyt31 = in->yyt23;
	in->yyt14 = in->yyt10;
	in->yyt22 = in->yyt18;
	in->yyt30 = in->yyt21;
	in->yyt12 = in->yyt9;
	in->yyt20 = in->yyt17;
	in->yyt29 = in->yyt19;
	in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt15 = in->yyt16 = in->cur - 1;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt10;
	in->yyt11 = in->yyt9;
	in->yyt10 = in->cur - 1;
	switch (yych) {
		case 'a': goto yy14;
		case 'b': goto yy12;
		default: goto yy6;
	}
yy12:
	++in->cur;
	if ((in->lim - in->cur) < 4) if (fill(in, 4) != 0) return 1;
	yych = *in->cur;
	in->yyt25 = in->yyt26;
	in->yyt23 = in->yyt24;
	in->yyt13 = in->yyt14;
	in->yyt21 = in->yyt22;
	in->yyt11 = in->yyt12;
	in->yyt19 = in->yyt20;
	switch (yych) {
		case 'a': goto yy15;
		case 'b': goto yy12;
		default: goto yy6;
	}
yy13:
	yych = *++in->cur;
	in->yyt26 = in->yyt16;
	in->yyt25 = in->yyt16;
	in->yyt24 = in->yyt15;
	in->yyt23 = in->yyt15;
	in->yyt22 = in->yyt18;
	in->yyt21 = in->yyt18;
	in->yyt20 = in->yyt17;
	in->yyt19 = in->yyt17;
	in->yyt16 = in->cur - 1;
	in->yyt15 = in->yyt9;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt14;
	in->yyt11 = in->yyt12;
	switch (yych) {
		case 'a': goto yy16;
		case 'b': goto yy17;
		default: goto yy6;
	}
yy14:
	yych = *++in->cur;
	in->yyt44 = in->yyt28;
	in->yyt43 = in->yyt28;
	in->yyt42 = in->yyt27;
	in->yyt41 = in->yyt27;
	in->yyt26 = in->yyt16;
	in->yyt40 = in->yyt32;
	in->yyt39 = in->yyt32;
	in->yyt24 = in->yyt15;
	in->yyt38 = in->yyt31;
	in->yyt37 = in->yyt31;
	in->yyt14 = in->yyt10;
	in->yyt22 = in->yyt18;
	in->yyt36 = in->yyt30;
	in->yyt35 = in->yyt30;
	in->yyt12 = in->yyt9;
	in->yyt20 = in->yyt17;
	in->yyt34 = in->yyt29;
	in->yyt33 = in->yyt29;
	in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt15 = in->yyt16 = in->cur - 1;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt10;
	in->yyt11 = in->yyt9;
	in->yyt10 = in->cur - 1;
	switch (yych) {
		case 'a': goto yy18;
		case 'b': goto yy19;
		default: goto yy6;
	}
yy15:
	yych = *++in->cur;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt18 = in->yyt13;
	in->yyt30 = in->yyt21;
	in->yyt17 = in->yyt11;
	in->yyt29 = in->yyt19;
	in->yyt9 = in->yyt15 = in->yyt16 = in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt25 = in->yyt26;
	in->yyt23 = in->yyt24;
	in->yyt13 = in->yyt14;
	in->yyt21 = in->yyt22;
	in->yyt11 = in->yyt12;
	in->yyt19 = in->yyt20;
	switch (yych) {
		case 'a': goto yy20;
		default: goto yy6;
	}
yy16:
	yych = *++in->cur;
	in->yyt26 = in->yyt16;
	in->yyt32 = in->yyt25;
	in->yyt24 = in->yyt15;
	in->yyt31 = in->yyt23;
	in->yyt22 = in->yyt18;
	in->yyt30 = in->yyt21;
	in->yyt20 = in->yyt17;
	in->yyt29 = in->yyt19;
	in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt16 = in->cur - 1;
	in->yyt15 = in->yyt9;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt14;
	in->yyt11 = in->yyt12;
	switch (yych) {
		case 'a': goto yy21;
		case 'b': goto yy17;
		default: goto yy6;
	}
yy17:
	++in->cur;
	if ((in->lim - in->cur) < 4) if (fill(in, 4) != 0) return 1;
	yych = *in->cur;
	in->yyt25 = in->yyt26;
	in->yyt23 = in->yyt24;
	in->yyt21 = in->yyt22;
	in->yyt19 = in->yyt20;
	switch (yych) {
		case 'a': goto yy22;
		case 'b': goto yy17;
		default: goto yy6;
	}
yy18:
	yych = *++in->cur;
	in->yyt44 = in->yyt28;
	in->yyt52 = in->yyt43;
	in->yyt42 = in->yyt27;
	in->yyt51 = in->yyt41;
	in->yyt26 = in->yyt16;
	in->yyt40 = in->yyt32;
	in->yyt50 = in->yyt39;
	in->yyt24 = in->yyt15;
	in->yyt38 = in->yyt31;
	in->yyt49 = in->yyt37;
	in->yyt14 = in->yyt10;
	in->yyt22 = in->yyt18;
	in->yyt36 = in->yyt30;
	in->yyt48 = in->yyt35;
	in->yyt12 = in->yyt9;
	in->yyt20 = in->yyt17;
	in->yyt34 = in->yyt29;
	in->yyt47 = in->yyt33;
	in->yyt45 = in->yyt46 = in->cur - 1;
	in->yyt43 = in->yyt28;
	in->yyt41 = in->yyt27;
	in->yyt39 = in->yyt32;
	in->yyt37 = in->yyt31;
	in->yyt35 = in->yyt30;
	in->yyt33 = in->yyt29;
	in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt15 = in->yyt16 = in->cur - 1;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt10;
	in->yyt11 = in->yyt9;
	in->yyt10 = in->cur - 1;
	switch (yych) {
		case 'a': goto yy23;
		case 'b': goto yy19;
		default: goto yy6;
	}
yy19:
	++in->cur;
	if ((in->lim - in->cur) < 3) if (fill(in, 3) != 0) return 1;
	yych = *in->cur;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt25 = in->yyt26;
	in->yyt39 = in->yyt40;
	in->yyt23 = in->yyt24;
	in->yyt37 = in->yyt38;
	in->yyt13 = in->yyt14;
	in->yyt21 = in->yyt22;
	in->yyt35 = in->yyt36;
	in->yyt11 = in->yyt12;
	in->yyt19 = in->yyt20;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case 'a': goto yy24;
		case 'b': goto yy19;
		default: goto yy6;
	}
yy20:
	yych = *++in->cur;
	in->yyt44 = in->yyt28;
	in->yyt43 = in->yyt28;
	in->yyt42 = in->yyt27;
	in->yyt41 = in->yyt27;
	in->yyt26 = in->yyt16;
	in->yyt40 = in->yyt32;
	in->yyt39 = in->yyt32;
	in->yyt24 = in->yyt15;
	in->yyt38 = in->yyt31;
	in->yyt37 = in->yyt31;
	in->yyt22 = in->yyt18;
	in->yyt36 = in->yyt30;
	in->yyt35 = in->yyt30;
	in->yyt20 = in->yyt17;
	in->yyt34 = in->yyt29;
	in->yyt33 = in->yyt29;
	in->yyt28 = in->cur - 1;
	in->yyt27 = in->yyt9;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt16 = in->cur - 1;
	in->yyt15 = in->yyt9;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt14;
	in->yyt11 = in->yyt12;
	switch (yych) {
		case 'a': goto yy25;
		case 'b': goto yy26;
		default: goto yy6;
	}
yy21:
	yych = *++in->cur;
	in->yyt44 = in->yyt28;
	in->yyt43 = in->yyt28;
	in->yyt42 = in->yyt27;
	in->yyt41 = in->yyt27;
	in->yyt26 = in->yyt16;
	in->yyt40 = in->yyt32;
	in->yyt39 = in->yyt32;
	in->yyt24 = in->yyt15;
	in->yyt38 = in->yyt31;
	in->yyt37 = in->yyt31;
	in->yyt22 = in->yyt18;
	in->yyt36 = in->yyt30;
	in->yyt35 = in->yyt30;
	in->yyt20 = in->yyt17;
	in->yyt34 = in->yyt29;
	in->yyt33 = in->yyt29;
	in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt16 = in->cur - 1;
	in->yyt15 = in->yyt9;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt14;
	in->yyt11 = in->yyt12;
	switch (yych) {
		case 'a': goto yy25;
		case 'b': goto yy26;
		default: goto yy6;
	}
yy22:
	yych = *++in->cur;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt9 = in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt25 = in->yyt26;
	in->yyt23 = in->yyt24;
	in->yyt21 = in->yyt22;
	in->yyt19 = in->yyt20;
	switch (yych) {
		case 'a': goto yy27;
		default: goto yy6;
	}
yy23:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	in->yyt8 = in->yyt46;
	in->yyt7 = in->yyt45;
	in->yyt44 = in->yyt28;
	in->yyt6 = in->yyt52;
	in->yyt42 = in->yyt27;
	in->yyt5 = in->yyt51;
	in->yyt26 = in->yyt16;
	in->yyt40 = in->yyt32;
	in->yyt4 = in->yyt50;
	in->yyt24 = in->yyt15;
	in->yyt38 = in->yyt31;
	in->yyt3 = in->yyt49;
	in->yyt14 = in->yyt10;
	in->yyt22 = in->yyt18;
	in->yyt36 = in->yyt30;
	in->yyt2 = in->yyt48;
	in->yyt12 = in->yyt9;
	in->yyt20 = in->yyt17;
	in->yyt34 = in->yyt29;
	in->yyt1 = in->yyt47;
	in->yyt45 = in->yyt46 = in->cur - 1;
	in->yyt52 = in->yyt43;
	in->yyt51 = in->yyt41;
	in->yyt50 = in->yyt39;
	in->yyt49 = in->yyt37;
	in->yyt48 = in->yyt35;
	in->yyt47 = in->yyt33;
	in->yyt43 = in->yyt28;
	in->yyt41 = in->yyt27;
	in->yyt39 = in->yyt32;
	in->yyt37 = in->yyt31;
	in->yyt35 = in->yyt30;
	in->yyt33 = in->yyt29;
	in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt15 = in->yyt16 = in->cur - 1;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt10;
	in->yyt11 = in->yyt9;
	in->yyt10 = in->cur - 1;
	switch (yych) {
		case '\n': goto yy28;
		case 'a': goto yy23;
		case 'b': goto yy29;
		default: goto yy6;
	}
yy24:
	yych = *++in->cur;
	in->yyt52 = in->yyt43;
	in->yyt51 = in->yyt41;
	in->yyt32 = in->yyt25;
	in->yyt50 = in->yyt39;
	in->yyt31 = in->yyt23;
	in->yyt49 = in->yyt37;
	in->yyt18 = in->yyt13;
	in->yyt30 = in->yyt21;
	in->yyt48 = in->yyt35;
	in->yyt17 = in->yyt11;
	in->yyt29 = in->yyt19;
	in->yyt47 = in->yyt33;
	in->yyt9 = in->yyt15 = in->yyt16 = in->yyt27 = in->yyt28 = in->yyt45 = in->yyt46 = in->cur - 1;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt25 = in->yyt26;
	in->yyt39 = in->yyt40;
	in->yyt23 = in->yyt24;
	in->yyt37 = in->yyt38;
	in->yyt13 = in->yyt14;
	in->yyt21 = in->yyt22;
	in->yyt35 = in->yyt36;
	in->yyt11 = in->yyt12;
	in->yyt19 = in->yyt20;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case 'a': goto yy30;
		default: goto yy6;
	}
yy25:
	yych = *++in->cur;
	in->yyt44 = in->yyt28;
	in->yyt52 = in->yyt43;
	in->yyt42 = in->yyt27;
	in->yyt51 = in->yyt41;
	in->yyt26 = in->yyt16;
	in->yyt40 = in->yyt32;
	in->yyt50 = in->yyt39;
	in->yyt24 = in->yyt15;
	in->yyt38 = in->yyt31;
	in->yyt49 = in->yyt37;
	in->yyt22 = in->yyt18;
	in->yyt36 = in->yyt30;
	in->yyt48 = in->yyt35;
	in->yyt20 = in->yyt17;
	in->yyt34 = in->yyt29;
	in->yyt47 = in->yyt33;
	in->yyt45 = in->yyt46 = in->cur - 1;
	in->yyt43 = in->yyt28;
	in->yyt41 = in->yyt27;
	in->yyt39 = in->yyt32;
	in->yyt37 = in->yyt31;
	in->yyt35 = in->yyt30;
	in->yyt33 = in->yyt29;
	in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt16 = in->cur - 1;
	in->yyt15 = in->yyt9;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt14;
	in->yyt11 = in->yyt12;
	switch (yych) {
		case 'a': goto yy31;
		case 'b': goto yy26;
		default: goto yy6;
	}
yy26:
	++in->cur;
	if ((in->lim - in->cur) < 3) if (fill(in, 3) != 0) return 1;
	yych = *in->cur;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt25 = in->yyt26;
	in->yyt39 = in->yyt40;
	in->yyt23 = in->yyt24;
	in->yyt37 = in->yyt38;
	in->yyt21 = in->yyt22;
	in->yyt35 = in->yyt36;
	in->yyt19 = in->yyt20;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case 'a': goto yy32;
		case 'b': goto yy26;
		default: goto yy6;
	}
yy27:
	yych = *++in->cur;
	in->yyt44 = in->yyt28;
	in->yyt43 = in->yyt28;
	in->yyt42 = in->yyt27;
	in->yyt41 = in->yyt27;
	in->yyt40 = in->yyt32;
	in->yyt39 = in->yyt32;
	in->yyt38 = in->yyt31;
	in->yyt37 = in->yyt31;
	in->yyt36 = in->yyt30;
	in->yyt35 = in->yyt30;
	in->yyt34 = in->yyt29;
	in->yyt33 = in->yyt29;
	in->yyt28 = in->cur - 1;
	in->yyt27 = in->yyt9;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt26;
	in->yyt23 = in->yyt24;
	in->yyt21 = in->yyt22;
	in->yyt19 = in->yyt20;
	switch (yych) {
		case 'a': goto yy33;
		case 'b': goto yy34;
		default: goto yy6;
	}
yy28:
	++in->cur;
	a0 = in->yyt1;
	b0 = in->yyt2;
	a1 = in->yyt3;
	b1 = in->yyt4;
	a2 = in->yyt5;
	b2 = in->yyt6;
	a3 = in->yyt7;
	b3 = in->yyt8;
#line 17 "../../../benchmarks/submatch_dfa_aot/src/re2c/24__cat4_2.re"
	{
        outs(out, a0, b0); outc(out, '.'); outs(out, b0, a1); outc(out, '.');
        outs(out, a1, b1); outc(out, '.'); outs(out, b1, a2); outc(out, '.');
        outs(out, a2, b2); outc(out, '.'); outs(out, b2, a3); outc(out, '.');
        outs(out, a3, b3); outc(out, '.'); outs(out, b3, in->cur);
        goto loop;
    }
#line 967 "gen/re2c/24__cat4_2-stadfa.c"
yy29:
	++in->cur;
	if ((in->lim - in->cur) < 3) if (fill(in, 3) != 0) return 1;
	yych = *in->cur;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt25 = in->yyt26;
	in->yyt39 = in->yyt40;
	in->yyt23 = in->yyt24;
	in->yyt37 = in->yyt38;
	in->yyt13 = in->yyt14;
	in->yyt21 = in->yyt22;
	in->yyt35 = in->yyt36;
	in->yyt11 = in->yyt12;
	in->yyt19 = in->yyt20;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case '\n': goto yy28;
		case 'a': goto yy24;
		case 'b': goto yy29;
		default: goto yy6;
	}
yy30:
	yych = *++in->cur;
	in->yyt8 = in->yyt46;
	in->yyt7 = in->yyt45;
	in->yyt44 = in->yyt28;
	in->yyt6 = in->yyt52;
	in->yyt42 = in->yyt27;
	in->yyt5 = in->yyt51;
	in->yyt26 = in->yyt16;
	in->yyt40 = in->yyt32;
	in->yyt4 = in->yyt50;
	in->yyt24 = in->yyt15;
	in->yyt38 = in->yyt31;
	in->yyt3 = in->yyt49;
	in->yyt22 = in->yyt18;
	in->yyt36 = in->yyt30;
	in->yyt2 = in->yyt48;
	in->yyt20 = in->yyt17;
	in->yyt34 = in->yyt29;
	in->yyt1 = in->yyt47;
	in->yyt46 = in->cur - 1;
	in->yyt45 = in->yyt9;
	in->yyt52 = in->yyt43;
	in->yyt51 = in->yyt41;
	in->yyt50 = in->yyt39;
	in->yyt49 = in->yyt37;
	in->yyt48 = in->yyt35;
	in->yyt47 = in->yyt33;
	in->yyt43 = in->yyt28;
	in->yyt41 = in->yyt27;
	in->yyt39 = in->yyt32;
	in->yyt37 = in->yyt31;
	in->yyt35 = in->yyt30;
	in->yyt33 = in->yyt29;
	in->yyt28 = in->cur - 1;
	in->yyt27 = in->yyt9;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt16 = in->cur - 1;
	in->yyt15 = in->yyt9;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt14;
	in->yyt11 = in->yyt12;
	switch (yych) {
		case '\n': goto yy28;
		case 'a': goto yy31;
		case 'b': goto yy35;
		default: goto yy6;
	}
yy31:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	in->yyt8 = in->yyt46;
	in->yyt7 = in->yyt45;
	in->yyt44 = in->yyt28;
	in->yyt6 = in->yyt52;
	in->yyt42 = in->yyt27;
	in->yyt5 = in->yyt51;
	in->yyt26 = in->yyt16;
	in->yyt40 = in->yyt32;
	in->yyt4 = in->yyt50;
	in->yyt24 = in->yyt15;
	in->yyt38 = in->yyt31;
	in->yyt3 = in->yyt49;
	in->yyt22 = in->yyt18;
	in->yyt36 = in->yyt30;
	in->yyt2 = in->yyt48;
	in->yyt20 = in->yyt17;
	in->yyt34 = in->yyt29;
	in->yyt1 = in->yyt47;
	in->yyt45 = in->yyt46 = in->cur - 1;
	in->yyt52 = in->yyt43;
	in->yyt51 = in->yyt41;
	in->yyt50 = in->yyt39;
	in->yyt49 = in->yyt37;
	in->yyt48 = in->yyt35;
	in->yyt47 = in->yyt33;
	in->yyt43 = in->yyt28;
	in->yyt41 = in->yyt27;
	in->yyt39 = in->yyt32;
	in->yyt37 = in->yyt31;
	in->yyt35 = in->yyt30;
	in->yyt33 = in->yyt29;
	in->yyt27 = in->yyt28 = in->cur - 1;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt16;
	in->yyt23 = in->yyt15;
	in->yyt21 = in->yyt18;
	in->yyt19 = in->yyt17;
	in->yyt16 = in->cur - 1;
	in->yyt15 = in->yyt9;
	in->yyt18 = in->yyt13;
	in->yyt17 = in->yyt11;
	in->yyt13 = in->yyt14;
	in->yyt11 = in->yyt12;
	switch (yych) {
		case '\n': goto yy28;
		case 'a': goto yy31;
		case 'b': goto yy35;
		default: goto yy6;
	}
yy32:
	yych = *++in->cur;
	in->yyt52 = in->yyt43;
	in->yyt51 = in->yyt41;
	in->yyt32 = in->yyt25;
	in->yyt50 = in->yyt39;
	in->yyt31 = in->yyt23;
	in->yyt49 = in->yyt37;
	in->yyt30 = in->yyt21;
	in->yyt48 = in->yyt35;
	in->yyt29 = in->yyt19;
	in->yyt47 = in->yyt33;
	in->yyt9 = in->yyt27 = in->yyt28 = in->yyt45 = in->yyt46 = in->cur - 1;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt25 = in->yyt26;
	in->yyt39 = in->yyt40;
	in->yyt23 = in->yyt24;
	in->yyt37 = in->yyt38;
	in->yyt21 = in->yyt22;
	in->yyt35 = in->yyt36;
	in->yyt19 = in->yyt20;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case 'a': goto yy36;
		default: goto yy6;
	}
yy33:
	yych = *++in->cur;
	in->yyt44 = in->yyt28;
	in->yyt52 = in->yyt43;
	in->yyt42 = in->yyt27;
	in->yyt51 = in->yyt41;
	in->yyt40 = in->yyt32;
	in->yyt50 = in->yyt39;
	in->yyt38 = in->yyt31;
	in->yyt49 = in->yyt37;
	in->yyt36 = in->yyt30;
	in->yyt48 = in->yyt35;
	in->yyt34 = in->yyt29;
	in->yyt47 = in->yyt33;
	in->yyt45 = in->yyt46 = in->cur - 1;
	in->yyt43 = in->yyt28;
	in->yyt41 = in->yyt27;
	in->yyt39 = in->yyt32;
	in->yyt37 = in->yyt31;
	in->yyt35 = in->yyt30;
	in->yyt33 = in->yyt29;
	in->yyt28 = in->cur - 1;
	in->yyt27 = in->yyt9;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt26;
	in->yyt23 = in->yyt24;
	in->yyt21 = in->yyt22;
	in->yyt19 = in->yyt20;
	switch (yych) {
		case 'a': goto yy37;
		case 'b': goto yy34;
		default: goto yy6;
	}
yy34:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt39 = in->yyt40;
	in->yyt37 = in->yyt38;
	in->yyt35 = in->yyt36;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case 'a': goto yy38;
		case 'b': goto yy34;
		default: goto yy6;
	}
yy35:
	++in->cur;
	if ((in->lim - in->cur) < 3) if (fill(in, 3) != 0) return 1;
	yych = *in->cur;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt25 = in->yyt26;
	in->yyt39 = in->yyt40;
	in->yyt23 = in->yyt24;
	in->yyt37 = in->yyt38;
	in->yyt21 = in->yyt22;
	in->yyt35 = in->yyt36;
	in->yyt19 = in->yyt20;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case '\n': goto yy28;
		case 'a': goto yy32;
		case 'b': goto yy35;
		default: goto yy6;
	}
yy36:
	yych = *++in->cur;
	in->yyt8 = in->yyt46;
	in->yyt7 = in->yyt45;
	in->yyt44 = in->yyt28;
	in->yyt6 = in->yyt52;
	in->yyt42 = in->yyt27;
	in->yyt5 = in->yyt51;
	in->yyt40 = in->yyt32;
	in->yyt4 = in->yyt50;
	in->yyt38 = in->yyt31;
	in->yyt3 = in->yyt49;
	in->yyt36 = in->yyt30;
	in->yyt2 = in->yyt48;
	in->yyt34 = in->yyt29;
	in->yyt1 = in->yyt47;
	in->yyt46 = in->cur - 1;
	in->yyt45 = in->yyt9;
	in->yyt52 = in->yyt43;
	in->yyt51 = in->yyt41;
	in->yyt50 = in->yyt39;
	in->yyt49 = in->yyt37;
	in->yyt48 = in->yyt35;
	in->yyt47 = in->yyt33;
	in->yyt43 = in->yyt28;
	in->yyt41 = in->yyt27;
	in->yyt39 = in->yyt32;
	in->yyt37 = in->yyt31;
	in->yyt35 = in->yyt30;
	in->yyt33 = in->yyt29;
	in->yyt28 = in->cur - 1;
	in->yyt27 = in->yyt9;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt26;
	in->yyt23 = in->yyt24;
	in->yyt21 = in->yyt22;
	in->yyt19 = in->yyt20;
	switch (yych) {
		case '\n': goto yy28;
		case 'a': goto yy37;
		case 'b': goto yy39;
		default: goto yy6;
	}
yy37:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	in->yyt8 = in->yyt46;
	in->yyt7 = in->yyt45;
	in->yyt44 = in->yyt28;
	in->yyt6 = in->yyt52;
	in->yyt42 = in->yyt27;
	in->yyt5 = in->yyt51;
	in->yyt40 = in->yyt32;
	in->yyt4 = in->yyt50;
	in->yyt38 = in->yyt31;
	in->yyt3 = in->yyt49;
	in->yyt36 = in->yyt30;
	in->yyt2 = in->yyt48;
	in->yyt34 = in->yyt29;
	in->yyt1 = in->yyt47;
	in->yyt45 = in->yyt46 = in->cur - 1;
	in->yyt52 = in->yyt43;
	in->yyt51 = in->yyt41;
	in->yyt50 = in->yyt39;
	in->yyt49 = in->yyt37;
	in->yyt48 = in->yyt35;
	in->yyt47 = in->yyt33;
	in->yyt43 = in->yyt28;
	in->yyt41 = in->yyt27;
	in->yyt39 = in->yyt32;
	in->yyt37 = in->yyt31;
	in->yyt35 = in->yyt30;
	in->yyt33 = in->yyt29;
	in->yyt28 = in->cur - 1;
	in->yyt27 = in->yyt9;
	in->yyt32 = in->yyt25;
	in->yyt31 = in->yyt23;
	in->yyt30 = in->yyt21;
	in->yyt29 = in->yyt19;
	in->yyt25 = in->yyt26;
	in->yyt23 = in->yyt24;
	in->yyt21 = in->yyt22;
	in->yyt19 = in->yyt20;
	switch (yych) {
		case '\n': goto yy28;
		case 'a': goto yy37;
		case 'b': goto yy39;
		default: goto yy6;
	}
yy38:
	yych = *++in->cur;
	in->yyt52 = in->yyt43;
	in->yyt51 = in->yyt41;
	in->yyt50 = in->yyt39;
	in->yyt49 = in->yyt37;
	in->yyt48 = in->yyt35;
	in->yyt47 = in->yyt33;
	in->yyt9 = in->yyt45 = in->yyt46 = in->cur - 1;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt39 = in->yyt40;
	in->yyt37 = in->yyt38;
	in->yyt35 = in->yyt36;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case 'a': goto yy40;
		default: goto yy6;
	}
yy39:
	++in->cur;
	if ((in->lim - in->cur) < 2) if (fill(in, 2) != 0) return 1;
	yych = *in->cur;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt39 = in->yyt40;
	in->yyt37 = in->yyt38;
	in->yyt35 = in->yyt36;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case '\n': goto yy28;
		case 'a': goto yy38;
		case 'b': goto yy39;
		default: goto yy6;
	}
yy40:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	in->yyt8 = in->yyt46;
	in->yyt7 = in->yyt45;
	in->yyt6 = in->yyt52;
	in->yyt5 = in->yyt51;
	in->yyt4 = in->yyt50;
	in->yyt3 = in->yyt49;
	in->yyt2 = in->yyt48;
	in->yyt1 = in->yyt47;
	in->yyt46 = in->cur - 1;
	in->yyt45 = in->yyt9;
	in->yyt52 = in->yyt43;
	in->yyt51 = in->yyt41;
	in->yyt50 = in->yyt39;
	in->yyt49 = in->yyt37;
	in->yyt48 = in->yyt35;
	in->yyt47 = in->yyt33;
	in->yyt43 = in->yyt44;
	in->yyt41 = in->yyt42;
	in->yyt39 = in->yyt40;
	in->yyt37 = in->yyt38;
	in->yyt35 = in->yyt36;
	in->yyt33 = in->yyt34;
	switch (yych) {
		case '\n': goto yy28;
		case 'a': goto yy40;
		case 'b': goto yy41;
		default: goto yy6;
	}
yy41:
	++in->cur;
	if (in->lim <= in->cur) if (fill(in, 1) != 0) return 1;
	yych = *in->cur;
	switch (yych) {
		case '\n': goto yy28;
		case 'b': goto yy41;
		default: goto yy6;
	}
}
#line 24 "../../../benchmarks/submatch_dfa_aot/src/re2c/24__cat4_2.re"

}
