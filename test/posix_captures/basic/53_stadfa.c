/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --flex-syntax --stadfa

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 'a':	goto yy3;
	default:	goto yy2;
	}
yy2:
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	yych = *++YYCURSOR;
	yyt1 = YYCURSOR - 1;
	switch (yych) {
	case 'b':	goto yy5;
	case 'c':	goto yy6;
	default:	goto yy4;
	}
yy4:
	YYCURSOR = YYMARKER;
	goto yy2;
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':	goto yy8;
	case 'c':	goto yy6;
	default:	goto yy4;
	}
yy6:
	++YYCURSOR;
	yyt2 = YYCURSOR - 1;
yy7:
	yynmatch = 2;
	yypmatch[2] = yyt1;
	yypmatch[3] = yyt2;
	yypmatch[0] = yyt1;
	yypmatch[1] = YYCURSOR;
	{}
yy8:
	yych = *++YYCURSOR;
	yyt2 = YYCURSOR - 1;
	switch (yych) {
	case 'b':	goto yy9;
	case 'c':	goto yy11;
	default:	goto yy4;
	}
yy9:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy9;
	case 'c':	goto yy11;
	default:	goto yy4;
	}
yy11:
	++YYCURSOR;
	goto yy7;
}

posix_captures/basic/53_stadfa.re:7:7: warning: rule matches empty string [-Wmatch-empty-string]