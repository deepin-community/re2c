/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --flex-syntax

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych >= 0x01) {
		yyt1 = yyt2 = YYCURSOR;
		goto yy3;
	}
	yyt1 = yyt2 = yyt3 = YYCURSOR;
yy2:
	yynmatch = 2;
	yypmatch[0] = yyt1;
	yypmatch[2] = yyt2;
	yypmatch[3] = yyt3;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 0x00) {
		yyt3 = YYCURSOR;
		goto yy2;
	}
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 0x00) {
		yyt3 = YYCURSOR;
		goto yy2;
	}
	yyt2 = YYCURSOR;
	goto yy3;
}

posix_captures/glennfowler/16.re:6:4: warning: rule matches empty string [-Wmatch-empty-string]
posix_captures/glennfowler/16.re:7:7: warning: rule matches empty string [-Wmatch-empty-string]
posix_captures/glennfowler/16.re:7:7: warning: unreachable rule (shadowed by rule at line 6) [-Wunreachable-rules]
