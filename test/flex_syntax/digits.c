/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --flex-syntax


{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case '0': goto yy2;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy4;
		default: goto yy1;
	}
yy1:
	++YYCURSOR;
	{ error }
yy2:
	++YYCURSOR;
yy3:
	{ number }
yy4:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
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
		case '9': goto yy4;
		default: goto yy3;
	}
}
