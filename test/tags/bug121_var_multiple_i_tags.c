/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --tags
// overlapping trailing contexts of variable length:
// we need multiple tags and we cannot deduplicate them


{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy4;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
	{ d }
yy4:
	yych = *++YYCURSOR;
	yyt2 = YYCURSOR;
	switch (yych) {
	case 'b':	goto yy6;
	default:	goto yy5;
	}
yy5:
	YYCURSOR = yyt2;
	{ 1 }
yy6:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'c':
		yyt1 = YYCURSOR;
		goto yy9;
	default:	goto yy8;
	}
yy7:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy8:
	switch (yych) {
	case 'b':	goto yy7;
	default:	goto yy5;
	}
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy11;
	default:	goto yy10;
	}
yy10:
	YYCURSOR = YYMARKER;
	goto yy5;
yy11:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'c':	goto yy11;
	default:	goto yy13;
	}
yy13:
	YYCURSOR = yyt1;
	{ 0 }
}

