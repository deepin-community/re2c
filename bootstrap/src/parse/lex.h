/* Generated by re2c 2.1.1 on Fri Jul 16 08:52:38 2021 */

#ifndef _RE2C_PARSE_LEX_
#define _RE2C_PARSE_LEX_

#include <stddef.h>
#include <string.h>
#include "src/util/forbid_copy.h"

namespace re2c {

#line 13 "src/parse/lex.h"
#define YYMAXFILL 18
#line 76 "../src/parse/lex.re"


struct ScannerState
{
    enum lexer_state_t {LEX_NORMAL, LEX_FLEX_NAME};
    lexer_state_t lexer_state;

    size_t BSIZE;
    char *bot, *lim, *cur, *mar, *ctx, *tok, *ptr, *pos, *eof;
    
#line 26 "src/parse/lex.h"
char *yyt1;char *yyt2;char *yyt3;
#line 85 "../src/parse/lex.re"


    inline ScannerState()
        : lexer_state (LEX_NORMAL)
        , BSIZE(8192)
        , bot(new char[BSIZE + YYMAXFILL])
        , lim(bot + BSIZE)
        , cur(lim)
        , mar(lim)
        , ctx(lim)
        , tok(lim)
        , ptr(lim)
        , pos(lim)
        , eof(NULL)
        
#line 44 "src/parse/lex.h"
, yyt1(lim), yyt2(lim), yyt3(lim)
#line 99 "../src/parse/lex.re"

    {
        memset(lim, 0, YYMAXFILL);
    }

    inline ~ScannerState() { delete[] bot; }

    inline void shift_ptrs(ptrdiff_t offs)
    {
        lim += offs;
        cur += offs;
        mar += offs;
        ctx += offs;
        tok += offs;
        ptr += offs;
        pos += offs;
        
#line 64 "src/parse/lex.h"
if (yyt1) { yyt1 += offs; }if (yyt2) { yyt2 += offs; }if (yyt3) { yyt3 += offs; }
#line 115 "../src/parse/lex.re"

    }

    FORBID_COPY(ScannerState);
};
} // namespace re2c

#endif // _RE2C_PARSE_LEX_