/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --flex-syntax --posix-closure gtop

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		yyt1 = YYCURSOR;
		goto yy3;
	default:
		yyt2 = NULL;
		yyt1 = YYCURSOR;
		goto yy2;
	}
yy2:
	yynmatch = 2;
	yypmatch[0] = yyt1;
	yypmatch[2] = yyt2;
	yypmatch[3] = yyt2;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy3;
	default:
		yyt2 = NULL;
		goto yy2;
	}
}

posix_captures/other/07_posix_closure_gtop.re:6:4: warning: rule matches empty string [-Wmatch-empty-string]
posix_captures/other/07_posix_closure_gtop.re:7:7: warning: rule matches empty string [-Wmatch-empty-string]
posix_captures/other/07_posix_closure_gtop.re:7:7: warning: unreachable rule (shadowed by rule at line 6) [-Wunreachable-rules]
