/* Generated by re2c */

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		yyt1 = YYCURSOR;
		goto yy3;
	default:	goto yy2;
	}
yy2:
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':
		yyt2 = YYCURSOR;
		goto yy5;
	default:
		yyt2 = yyt3 = NULL;
		goto yy4;
	}
yy4:
	yynmatch = 3;
	yypmatch[0] = yypmatch[2] = yyt1;
	yypmatch[4] = yyt2;
	yypmatch[5] = yyt3;
	yypmatch[1] = yypmatch[3] = YYCURSOR;
	{}
yy5:
	++YYCURSOR;
	yyt3 = YYCURSOR;
	goto yy4;
}

posix_captures/glennfowler/34.i--flex-syntax.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]