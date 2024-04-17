/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: lex.c
 *
 */

/* Lexical scanner */

#include "lex.inl"
#include "stream.inl"
#include "heap.h"
#include "stream.h"
#include "strings.h"
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

#define DISCARD_CHAR 0
#define VALID_CHAR 1
#define STORE_CHAR 2

typedef struct _lexopts_t LexOpts;

typedef enum _state_t
{
    stSTART,
    stSPACES,
    stSLASH,
    stSL_COMMENT,
    stML_COMMENT,
    stML_COMMENT2,
    stPERIOD,
    stIDENTIFIER,
    stSTRING,
    stSTRING_SCAPE,
    stSTRING_OCTAL,
    stSTRING_HEX,
    stSTRING_UNICODE4,
    stSTRING_UNICODE8,
    stZERO,
    stINT,
    stHEX,
    stREAL,
    stEXP,
    stEXP1,
    stEND
} gui_state_t;

struct _lexopts_t
{
    bool_t spaces;
    bool_t newlines;
    bool_t escapes;
    bool_t comments;
};

struct _lexscn_t
{
    LexOpts opts;
    uint32_t pcol;
    uint32_t prow;
    uint32_t tcol;
    uint32_t trow;
    uint32_t lexsize;
    uint32_t lexi;
    char_t *lexeme;
};

/*---------------------------------------------------------------------------*/

LexScn *_lexscn_create(void)
{
    LexScn *lex = heap_new0(LexScn);
    lex->lexsize = 256;
    lex->lexeme = (char_t *)heap_malloc(lex->lexsize, "LexLexeme");
    return lex;
}

/*---------------------------------------------------------------------------*/

void _lexscn_destroy(LexScn **lex)
{
    cassert_no_null(lex);
    cassert_no_null(*lex);
    heap_free((byte_t **)&(*lex)->lexeme, (*lex)->lexsize, "LexLexeme");
    heap_delete(lex, LexScn);
}

/*---------------------------------------------------------------------------*/

void _lexscn_spaces(LexScn *lex, const bool_t activate)
{
    cassert_no_null(lex);
    lex->opts.spaces = activate;
}

/*---------------------------------------------------------------------------*/

void _lexscn_newlines(LexScn *lex, const bool_t activate)
{
    cassert_no_null(lex);
    lex->opts.newlines = activate;
}

/*---------------------------------------------------------------------------*/

void _lexscn_escapes(LexScn *lex, const bool_t activate)
{
    cassert_no_null(lex);
    lex->opts.escapes = activate;
}

/*---------------------------------------------------------------------------*/

void _lexscn_comments(LexScn *lex, const bool_t activate)
{
    cassert_no_null(lex);
    lex->opts.comments = activate;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_get_char(LexScn *lex, Stream *stm)
{
    uint32_t col = stm_col(stm);
    uint32_t row = stm_row(stm);
    uint32_t code = stm_read_char(stm);
    cassert_no_null(lex);

    if (__TRUE_EXPECTED(code != UINT32_MAX))
    {
        lex->pcol = col;
        lex->prow = row;
    }

    return code;
}

/*---------------------------------------------------------------------------*/

static void i_store_char(LexScn *lex, Stream *stm, const uint32_t code)
{
    char_t data[5];
    uint32_t size;
    cassert_no_null(lex);
    size = unicode_to_char(code, data, ekUTF8);
    cassert(size >= 1 && size <= 4);
    _stm_restore(stm, (const byte_t *)data, size);
    _stm_restore_col(stm, lex->pcol);
    _stm_restore_row(stm, lex->prow);
}

/*---------------------------------------------------------------------------*/

static void i_add_lexeme(LexScn *lex, const uint32_t code)
{
    uint32_t csize;
    cassert_no_null(lex);

    if (code == UINT32_MAX)
        return;

    if (lex->lexi + 4 > lex->lexsize)
    {
        lex->lexeme = (char_t *)heap_realloc((byte_t *)lex->lexeme, lex->lexsize, lex->lexsize * 2, "LexLexeme");
        lex->lexsize *= 2;
    }

    csize = unicode_to_char(code, lex->lexeme + lex->lexi, ekUTF8);
    lex->lexi += csize;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_START(const uint32_t code, ltoken_t *token)
{
    cassert_no_null(token);
    switch (code)
    {
    case '<':
        *token = ekTLESS;
        return stEND;
    case '>':
        *token = ekTGREAT;
        return stEND;
    case ',':
        *token = ekTCOMMA;
        return stEND;
    case ';':
        *token = ekTSCOLON;
        return stEND;
    case ':':
        *token = ekTCOLON;
        return stEND;
    case '(':
        *token = ekTOPENPAR;
        return stEND;
    case ')':
        *token = ekTCLOSPAR;
        return stEND;
    case '[':
        *token = ekTOPENBRAC;
        return stEND;
    case ']':
        *token = ekTCLOSBRAC;
        return stEND;
    case '{':
        *token = ekTOPENCURL;
        return stEND;
    case '}':
        *token = ekTCLOSCURL;
        return stEND;
    case '+':
        *token = ekTPLUS;
        return stEND;
    case '-':
        *token = ekTMINUS;
        return stEND;
    case '*':
        *token = ekTASTERK;
        return stEND;
    case '=':
        *token = ekTEQUALS;
        return stEND;
    case '$':
        *token = ekTDOLLAR;
        return stEND;
    case '%':
        *token = ekTPERCENT;
        return stEND;
    case '#':
        *token = ekTPOUND;
        return stEND;
    case '&':
        *token = ekTAMPER;
        return stEND;
    case '\'':
        *token = ekTAPOST;
        return stEND;
    case '^':
        *token = ekTCIRCUM;
        return stEND;
    case '~':
        *token = ekTTILDE;
        return stEND;
    case '!':
        *token = ekTEXCLA;
        return stEND;
    case '?':
        *token = ekTQUEST;
        return stEND;
    case '|':
        *token = ekTVLINE;
        return stEND;
    case '\\':
        *token = ekTBSLASH;
        return stEND;
    case '@':
        *token = ekTAT;
        return stEND;

    case '/':
        return stSLASH;
    case '.':
        return stPERIOD;
    case '_':
        return stIDENTIFIER;
    case '"':
        return stSTRING;
    }

    if (code == ' ' || code == '\t' || code == '\v' || code == '\f' || code == '\r')
        return stSPACES;

    if (code == '\n')
    {
        *token = ekTEOL;
        return stEND;
    }

    if ((code >= 'a' && code <= 'z') || (code >= 'A' && code <= 'Z'))
        return stIDENTIFIER;

    if (code == '0')
        return stZERO;

    if (code >= '1' && code <= '9')
        return stINT;

    *token = ekTUNDEF;
    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_SPACES(const uint32_t code, ltoken_t *token, uint8_t *charst)
{
    if (code == ' ' || code == '\t' || code == '\v' || code == '\f' || code == '\r')
        return stSPACES;

    *token = ekTSPACE;
    *charst = STORE_CHAR;
    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_SLASH(const uint32_t code, ltoken_t *token, uint8_t *charst)
{
    if (code == '/')
        return stSL_COMMENT;
    if (code == '*')
        return stML_COMMENT;

    *token = ekTSLASH;
    *charst = STORE_CHAR;
    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_SL_COMMENT(const uint32_t code, ltoken_t *token)
{
    if (code == '\n')
    {
        *token = ekTSLCOM;
        return stEND;
    }
    return stSL_COMMENT;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_ML_COMMENT(const uint32_t code)
{
    if (code == '*')
        return stML_COMMENT2;
    return stML_COMMENT;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_ML_COMMENT2(const uint32_t code, ltoken_t *token)
{
    if (code == '/')
    {
        *token = ekTMLCOM;
        return stEND;
    }

    if (code == '*')
        return stML_COMMENT2;

    return stML_COMMENT;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_PERIOD(const uint32_t code, ltoken_t *token, uint8_t *charst)
{
    if (code >= '0' && code <= '9')
        return stREAL;

    *charst = STORE_CHAR;
    *token = ekTPERIOD;
    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_IDENTIFIER(const uint32_t code, ltoken_t *token, uint8_t *charst)
{
    if (code >= 'a' && code <= 'z')
        return stIDENTIFIER;
    if (code >= 'A' && code <= 'Z')
        return stIDENTIFIER;
    if (code >= '0' && code <= '9')
        return stIDENTIFIER;
    if (code == '_')
        return stIDENTIFIER;

    *token = ekTIDENT;
    *charst = STORE_CHAR;
    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_STRING(const uint32_t code, const bool_t escapes, ltoken_t *token, uint8_t *charst)
{
    if (code == '\\')
    {
        *charst = escapes ? DISCARD_CHAR : VALID_CHAR;
        return stSTRING_SCAPE;
    }

    if (code == '\"')
    {
        *token = ekTSTRING;
        return stEND;
    }

    return stSTRING;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_STRING_ESCAPE(uint32_t *code, const bool_t escapes, uint32_t *ci, char_t *c, uint8_t *charst)
{
    if (escapes == FALSE)
    {
        *charst = VALID_CHAR;
        return stSTRING;
    }

    switch (*code)
    {
    case 'a':
        *code = 0x07;
        return stSTRING;

    case 'b':
        *code = 0x08;
        return stSTRING;

    case 'f':
        *code = 0x0C;
        return stSTRING;

    case 'n':
        *code = 0x0A;
        return stSTRING;

    case 'r':
        *code = 0x0D;
        return stSTRING;

    case 't':
        *code = 0x09;
        return stSTRING;

    case 'v':
        *code = 0x0B;
        return stSTRING;

    case '\\':
        return stSTRING;

    case '/':
        return stSTRING;

    case '\'':
        return stSTRING;

    case '\"':
        return stSTRING;

    case '?':
        return stSTRING;
    }

    /* Octal char */
    if (*code >= '0' && *code <= '7')
    {
        cassert(*ci == 0);
        *charst = DISCARD_CHAR;
        c[0] = (char_t)*code;
        *ci = 1;
        return stSTRING_OCTAL;
    }

    /* Hex char */
    if (*code == 'x')
    {
        cassert(*ci == 0);
        *charst = DISCARD_CHAR;
        return stSTRING_HEX;
    }

    /* Unicode BMP */
    if (*code == 'u')
    {
        cassert(*ci == 0);
        *charst = DISCARD_CHAR;
        return stSTRING_UNICODE4;
    }

    /* Unicode 32bits */
    if (*code == 'U')
    {
        cassert(*ci == 0);
        *charst = DISCARD_CHAR;
        return stSTRING_UNICODE8;
    }

    /* Ignored escape sequence */
    cassert(*ci == 0);
    *charst = DISCARD_CHAR;
    return stSTRING;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_STRING_OCTAL(uint32_t *code, uint32_t *ci, char_t *c, uint8_t *charst)
{
    if (*code >= '0' && *code <= '7')
    {
        c[*ci] = (char_t)*code;
        if (*ci == 2)
        {
            c[3] = '\0';
            *code = str_to_u32(c, 8, NULL);
            *ci = 0;
            return stSTRING;
        }
        else
        {
            *ci += 1;
            *charst = DISCARD_CHAR;
            return stSTRING_OCTAL;
        }
    }

    c[*ci] = '\0';
    *ci = 0;
    *code = str_to_u32(c, 8, NULL);
    return stSTRING;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_STRING_HEX(uint32_t *code, uint32_t *ci, char_t *c, uint8_t *charst)
{
    if ((*code >= 'a' && *code <= 'f') || (*code >= 'A' && *code <= 'F'))
    {
        c[*ci] = (char_t)*code;
        if (*ci == 1)
        {
            c[2] = '\0';
            *code = str_to_u32(c, 16, NULL);
            *ci = 0;
            return stSTRING;
        }
        else
        {
            cassert(*ci == 0);
            *ci += 1;
            *charst = DISCARD_CHAR;
            return stSTRING_HEX;
        }
    }

    /* '\xhh' with 0 or 1 hex char --> discart */
    *ci = 0;
    *charst = DISCARD_CHAR;
    return stSTRING;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_STRING_UNICODE4(uint32_t *code, uint32_t *ci, char_t *c, uint8_t *charst)
{
    if ((*code >= 'a' && *code <= 'f') || (*code >= 'A' && *code <= 'F'))
    {
        c[*ci] = (char_t)*code;
        if (*ci == 3)
        {
            c[4] = '\0';
            *code = str_to_u32(c, 16, NULL);
            *ci = 0;
            return stSTRING;
        }
        else
        {
            cassert(*ci == 0);
            *ci += 1;
            *charst = DISCARD_CHAR;
            return stSTRING_UNICODE4;
        }
    }

    /* '\uhhhh' with 0, 1, 2 or 3 hex char --> discart */
    *charst = DISCARD_CHAR;
    return stSTRING;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_STRING_UNICODE8(uint32_t *code, uint32_t *ci, char_t *c, uint8_t *charst)
{
    if ((*code >= 'a' && *code <= 'f') || (*code >= 'A' && *code <= 'F'))
    {
        c[*ci] = (char_t)*code;
        if (*ci == 7)
        {
            c[8] = '\0';
            *code = str_to_u32(c, 16, NULL);
            *ci = 0;
            return stSTRING;
        }
        else
        {
            cassert(*ci == 0);
            *ci += 1;
            *charst = DISCARD_CHAR;
            return stSTRING_UNICODE8;
        }
    }

    /* '\Uhhhhhhhh' with (0-7) hex char --> discart */
    *charst = DISCARD_CHAR;
    return stSTRING;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_ZERO(const uint32_t code, ltoken_t *token, uint8_t *charst)
{
    if (code == 'x' || code == 'X')
        return stHEX;
    if (code == '.')
        return stREAL;
    if (code >= '0' && code <= '9')
        return stINT;

    *token = ekTINTEGER;
    *charst = STORE_CHAR;
    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_INT(const uint32_t code, ltoken_t *token, uint8_t *charst)
{
    if (code >= '0' && code <= '9')
        return stINT;
    if (code == '.')
        return stREAL;
    if ((code >= 'a' && code <= 'z') || (code >= 'A' && code <= 'Z'))
    {
        *token = ekTUNDEF;
    }
    else
    {
        *token = ekTINTEGER;
        *charst = STORE_CHAR;
    }

    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_HEX(const uint32_t code, ltoken_t *token, uint8_t *charst)
{
    if (code >= '0' && code <= '9')
        return stHEX;

    if (code >= 'a' && code <= 'f')
        return stHEX;

    if (code >= 'A' && code <= 'F')
        return stHEX;

    if ((code >= 'a' && code <= 'z') || (code >= 'A' && code <= 'Z'))
    {
        *token = ekTUNDEF;
    }
    else
    {
        *token = ekTHEX;
        *charst = STORE_CHAR;
    }

    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_REAL(const uint32_t code, ltoken_t *token, uint8_t *charst)
{
    if (code >= '0' && code <= '9')
        return stREAL;

    if (code == 'e' || code == 'E')
        return stEXP;

    if ((code >= 'a' && code <= 'z') || (code >= 'A' && code <= 'Z'))
    {
        *token = ekTUNDEF;
    }
    else
    {
        *token = ekTREAL;
        *charst = STORE_CHAR;
    }

    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_EXP(const uint32_t code, ltoken_t *token)
{
    if (code >= '0' && code <= '9')
        return stEXP1;

    if (code == '-' || code == '+')
        return stEXP1;

    *token = ekTUNDEF;
    return stEND;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_EXP1(const uint32_t code, ltoken_t *token, uint8_t *charst)
{
    if (code >= '0' && code <= '9')
        return stEXP1;

    if (code == '-' || code == '+')
        return stEXP1;

    if ((code >= 'a' && code <= 'z') || (code >= 'A' && code <= 'Z'))
    {
        *token = ekTUNDEF;
    }
    else
    {
        *token = ekTREAL;
        *charst = STORE_CHAR;
    }

    return stEND;
}

/*---------------------------------------------------------------------------*/

ltoken_t _lexscn_token(LexScn *lex, Stream *stm)
{
    ltoken_t token = ENUM_MAX(ltoken_t);

    for (;;)
    {
        uint32_t code = 0;
        uint32_t ci = 0;
        char_t c[10];
        gui_state_t state = stSTART;
        cassert_no_null(lex);
        lex->tcol = stm_col(stm);
        lex->trow = stm_row(stm);
        lex->lexi = 0;
        code = i_get_char(lex, stm);

        if (code == 0)
        {
            token = ekTEOF;
            break;
        }

        for (;;)
        {
            uint8_t charst = VALID_CHAR;

            if (code == UINT32_MAX)
            {
                token = ekTCORRUP;
                break;
            }

            token = ENUM_MAX(ltoken_t);
            switch (state)
            {
            case stSTART:
                state = i_START(code, &token);
                break;
            case stSPACES:
                state = i_SPACES(code, &token, &charst);
                break;
            case stSLASH:
                state = i_SLASH(code, &token, &charst);
                break;
            case stSL_COMMENT:
                state = i_SL_COMMENT(code, &token);
                break;
            case stML_COMMENT:
                state = i_ML_COMMENT(code);
                break;
            case stML_COMMENT2:
                state = i_ML_COMMENT2(code, &token);
                break;
            case stPERIOD:
                state = i_PERIOD(code, &token, &charst);
                break;
            case stIDENTIFIER:
                state = i_IDENTIFIER(code, &token, &charst);
                break;
            case stSTRING:
                state = i_STRING(code, lex->opts.escapes, &token, &charst);
                break;
            case stSTRING_SCAPE:
                state = i_STRING_ESCAPE(&code, lex->opts.escapes, &ci, c, &charst);
                break;
            case stSTRING_OCTAL:
                state = i_STRING_OCTAL(&code, &ci, c, &charst);
                break;
            case stSTRING_HEX:
                state = i_STRING_HEX(&code, &ci, c, &charst);
                break;
            case stSTRING_UNICODE4:
                state = i_STRING_UNICODE4(&code, &ci, c, &charst);
                break;
            case stSTRING_UNICODE8:
                state = i_STRING_UNICODE8(&code, &ci, c, &charst);
                break;
            case stZERO:
                state = i_ZERO(code, &token, &charst);
                break;
            case stINT:
                state = i_INT(code, &token, &charst);
                break;
            case stHEX:
                state = i_HEX(code, &token, &charst);
                break;
            case stREAL:
                state = i_REAL(code, &token, &charst);
                break;
            case stEXP:
                state = i_EXP(code, &token);
                break;
            case stEXP1:
                state = i_EXP1(code, &token, &charst);
                break;
            case stEND:
                cassert_default();
            }

            if (charst == VALID_CHAR)
                i_add_lexeme(lex, code);
            else if (charst == STORE_CHAR)
                i_store_char(lex, stm, code);
            else
            {
                cassert(charst == DISCARD_CHAR);
            }

            if (state == stEND)
                break;

            if (code == 0)
                break;

            code = i_get_char(lex, stm);
        }

        if (token == ekTMLCOM || token == ekTSLCOM)
        {
            if (lex->opts.comments)
                break;
        }
        else if (token == ekTSPACE)
        {
            if (lex->opts.spaces)
                break;
        }
        else if (token == ekTEOL)
        {
            if (lex->opts.spaces | lex->opts.newlines)
                break;
        }
        else
        {
            break;
        }
    }

    lex->lexeme[lex->lexi] = '\0';
    return token;
}

/*---------------------------------------------------------------------------*/

uint32_t _lexscn_row(const LexScn *lex)
{
    cassert_no_null(lex);
    return lex->trow;
}

/*---------------------------------------------------------------------------*/

uint32_t _lexscn_col(const LexScn *lex)
{
    cassert_no_null(lex);
    return lex->tcol;
}

/*---------------------------------------------------------------------------*/

const char_t *_lexscn_lexeme(const LexScn *lex, uint32_t *size)
{
    cassert_no_null(lex);
    ptr_assign(size, lex->lexi);
    return lex->lexeme;
}

/*---------------------------------------------------------------------------*/

const char_t *_lexscn_string(const ltoken_t token)
{
    switch (token)
    {
    case ekTSLCOM:
    case ekTMLCOM:
        return "comment";
    case ekTSPACE:
        return "spaces";
    case ekTEOL:
        return "newline";
    case ekTLESS:
        return "<";
    case ekTGREAT:
        return ">";
    case ekTCOMMA:
        return ",";
    case ekTPERIOD:
        return ".";
    case ekTSCOLON:
        return ";";
    case ekTCOLON:
        return ":";
    case ekTOPENPAR:
        return "(";
    case ekTCLOSPAR:
        return ")";
    case ekTOPENBRAC:
        return "[";
    case ekTCLOSBRAC:
        return "]";
    case ekTOPENCURL:
        return "{";
    case ekTCLOSCURL:
        return "}";
    case ekTPLUS:
        return "+";
    case ekTMINUS:
        return "-";
    case ekTASTERK:
        return "*";
    case ekTEQUALS:
        return "=";
    case ekTDOLLAR:
        return "$";
    case ekTPERCENT:
        return "%";
    case ekTPOUND:
        return "#";
    case ekTAMPER:
        return "&";
    case ekTAPOST:
        return "'";
    case ekTQUOTE:
        return "\"";
    case ekTCIRCUM:
        return "^";
    case ekTTILDE:
        return "~";
    case ekTEXCLA:
        return "!";
    case ekTQUEST:
        return "?";
    case ekTVLINE:
        return "|";
    case ekTSLASH:
        return "/";
    case ekTBSLASH:
        return "\\";
    case ekTAT:
        return "@";
    case ekTINTEGER:
        return "integer";
    case ekTOCTAL:
        return "octal";
    case ekTHEX:
        return "hex";
    case ekTREAL:
        return "real";
    case ekTSTRING:
        return "string";
    case ekTIDENT:
        return "identifier";
    case ekTUNDEF:
        return "undef";
    case ekTCORRUP:
        return "corrupt";
    case ekTEOF:
        return "eof";
    case ekTRESERVED:
        return "reserved";
        cassert_default();
    }

    return "--";
}
