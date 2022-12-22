/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i
#include <stdio.h>
#include <string.h>

static const size_t SIZE = 4096;

struct input_t {
    char buf[SIZE + 1];
    char *lim;
    char *cur;
    char *tok;
    bool eof;

    input_t()
        : buf()
        , lim(buf + SIZE)
        , cur(lim)
        , tok(lim)
        , eof(false)
    {
        fill();
    }
    int fill()
    {
        if (eof) {
            return 1;
        }
        const size_t free = tok - buf;
        if (free < 1) {
            return 2;
        }
        memmove(buf, tok, lim - tok);
        lim -= free;
        cur -= free;
        tok -= free;
        lim += fread(lim, 1, free, stdin);
        lim[0] = 254;
        if (lim < buf + SIZE) {
            eof = true;
        }
        return 0;
    }
};

static bool lex(input_t & in, unsigned int &count)
{
    for (count = 0;;) {
        in.tok = in.cur;
        
{
	char yych;
yyFillLabel0:
	yych = *in.cur;
	switch (yych) {
	case '\n':	goto yy4;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy7;
	default:
		if (in.lim <= in.cur) {
			if (in.fill() == 0) goto yyFillLabel0;
			goto yy10;
		}
		goto yy2;
	}
yy2:
	++in.cur;
	{ return false; }
yy4:
	++in.cur;
yyFillLabel1:
	yych = *in.cur;
	switch (yych) {
	case '\n':	goto yy4;
	default:
		if (in.lim <= in.cur) {
			if (in.fill() == 0) goto yyFillLabel1;
		}
		goto yy6;
	}
yy6:
	{ continue; }
yy7:
	++in.cur;
yyFillLabel2:
	yych = *in.cur;
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
	case '9':	goto yy7;
	default:
		if (in.lim <= in.cur) {
			if (in.fill() == 0) goto yyFillLabel2;
		}
		goto yy9;
	}
yy9:
	{ ++count; continue; }
yy10:
	{ return true; }
}

    }
}

int main()
{
    input_t in;
    unsigned int count;
    if (lex(in, count)) {
        printf("glorious %u numbers!\n", count);
    } else {
        printf("error\n");
    }

    return 0;
}
