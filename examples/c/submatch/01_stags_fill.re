// re2c $INPUT -o $OUTPUT --tags
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#define SIZE 4096

typedef struct {
    FILE *file;
    char buf[SIZE + 1], *lim, *cur, *mar, *tok;
    // Tag variables must be part of the lexer state passed to YYFILL.
    // They don't correspond to tags and should be autogenerated by re2c.
    /*!stags:re2c format = 'const char *@@;'; */
    int eof;
} Input;

static int fill(Input *in)
{
    if (in->eof) return 1;

    const size_t free = in->tok - in->buf;
    if (free < 1) return 2;

    memmove(in->buf, in->tok, in->lim - in->tok);

    in->lim -= free;
    in->cur -= free;
    in->mar -= free;
    in->tok -= free;
    // Tag variables need to be shifted like other input positions. The check
    // for non-NULL is only needed if some tags are nested inside of alternative
    // or repetition, so that they can have NULL value.
    /*!stags:re2c format = "if (in->@@) in->@@ -= free;\n"; */

    in->lim += fread(in->lim, 1, free, in->file);
    in->lim[0] = 0;
    in->eof |= in->lim < in->buf + SIZE;

    return 0;
}

static void init(Input *in, FILE *file)
{
    in->file = file;
    in->cur = in->mar = in->tok = in->lim = in->buf + SIZE;
    // Initialization is only needed to avoid "use of uninitialized" warnings
    // when shifting tags in YYFILL. In the lexer tags are guaranteed to be
    // set before they are used (either to a valid input position, or NULL).
    /*!stags:re2c format = "in->@@ = in->lim;\n"; */
    in->eof = 0;
    fill(in);
}

static uint32_t num(const char *s, const char *e)
{
    uint32_t n = 0;
    for (; s < e; ++s) n = n * 10 + (*s - '0');
    return n;
}

static bool lex(Input *in, std::vector<uint32_t> &ips)
{
    // User-defined local variables that store final tag values.
    // They are different from tag variables autogenerated with `stags:re2c`,
    // as they are set at the end of match and used only in semantic actions.
    const char *o1, *o2, *o3, *o4;
loop:
    in->tok = in->cur;
    /*!re2c
    re2c:eof = 0;
    re2c:api:style = free-form;
    re2c:define:YYCTYPE  = char;
    re2c:define:YYCURSOR = in->cur;
    re2c:define:YYMARKER = in->mar;
    re2c:define:YYLIMIT  = in->lim;
    re2c:define:YYFILL   = "fill(in) == 0";

    // The way tag variables are accessed from the lexer (not needed if tag
    // variables are defined as local variables).
    re2c:tags:expression = "in->@@";

    octet = [0-9] | [1-9][0-9] | [1][0-9][0-9] | [2][0-4][0-9] | [2][5][0-5];
    dot = [.];
    eol = [\n];

    @o1 octet dot @o2 octet dot @o3 octet dot @o4 octet eol {
        ips.push_back(num(o4, in->cur - 1)
            + (num(o3, o4 - 1) << 8)
            + (num(o2, o3 - 1) << 16)
            + (num(o1, o2 - 1) << 24));
        goto loop;
    }
    $ { return true; }
    * { return false; }
    */
}

int main()
{
    const char *fname = "input";
    FILE *f;
    Input in;
    std::vector<uint32_t> have, want;

    // Write a few IPv4 addresses to the input file and save them to compare
    // against parse results.
    f = fopen(fname, "w");
    for (int i = 0; i < 256; ++i) {
        fprintf(f, "%d.%d.%d.%d\n", i, i, i, i);
        want.push_back(i + (i << 8) + (i << 16) + (i << 24));
    }
    fclose(f);

    f = fopen(fname, "r");
    init(&in, f);

    assert(lex(&in, have) && have == want);

    fclose(f);
    remove(fname);
    return 0;
}
