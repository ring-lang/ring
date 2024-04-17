/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: nfa.c
 *
 */

/* Non-deterministic finite automata */

#include "nfa.inl"
#include "arrpt.h"
#include "arrst.h"
#include "heap.h"
#include "stream.h"
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

typedef struct _ntoken_t NToken;
typedef struct _trans_t Trans;

typedef enum _symbol_t
{
    ekCHAR,
    ekOR,
    ekCONCAT,
    ekCLOSURE,
    ekLEFT_PAR,
    ekRIGH_PAR
} symbol_t;

struct _ntoken_t
{
    symbol_t symbol;
    uint32_t from;
    uint32_t to;
};

struct _trans_t
{
    uint32_t state;
    uint32_t symbol;
    uint32_t extra;
};

struct _nfa_t
{
    ArrSt(Trans) *ttable;
    ArrSt(uint32_t) *current;
    ArrSt(uint32_t) *temp;
};

#define MIN_UNICODE 5
#define MAX_UNICODE 1114112
DeclSt(NToken);
DeclSt(Trans);
DeclSt(symbol_t);

/*---------------------------------------------------------------------------*/

static void i_write_tokens(Stream *stm, const ArrSt(NToken) *tokens)
{
    arrst_foreach_const(token, tokens, NToken)
        switch (token->symbol)
        {
        case ekCHAR:
            if (token->from == MIN_UNICODE && token->to == MAX_UNICODE)
            {
                stm_writef(stm, "[.]");
            }
            else if (token->from == '*' && token->to == '*')
            {
                stm_writef(stm, "[*]");
            }
            else
            {
                if (token->from == '\n')
                    stm_writef(stm, "[\\n]");
                else
                    stm_write_char(stm, token->from);

                if (token->from != token->to)
                {
                    cassert(token->from < token->to);
                    stm_write_char(stm, '-');
                    if (token->to == '\n')
                        stm_writef(stm, "[\\n]");
                    else
                        stm_write_char(stm, token->to);
                }
            }
            break;

        case ekOR:
            stm_write_char(stm, '|');
            break;

        case ekCONCAT:
            stm_write_char(stm, '&');
            break;

        case ekCLOSURE:
            stm_write_char(stm, '*');
            break;

        case ekLEFT_PAR:
        case ekRIGH_PAR:
            stm_write_char(stm, token->from);
            break;

            cassert_default();
        }
    arrst_end()

    stm_write_char(stm, '\n');
    stm_flush(stm);
}

/*---------------------------------------------------------------------------*/

static void i_write_nfa(Stream *stm, const NFA *nfa)
{
    cassert_no_null(nfa);
    arrst_foreach(trans, nfa->ttable, Trans)
        if (trans->symbol != UINT32_MAX)
        {
            if (trans->extra == 0)
            {
                cassert(trans_i == trans_total - 1);
                cassert(trans->state == UINT32_MAX);
                stm_printf(stm, "%d [ACCEPT]\n", trans_i);
            }
            else if (trans->symbol == MIN_UNICODE && trans->extra == MAX_UNICODE)
            {
                stm_printf(stm, "%d [.] --> %d\n", trans_i, trans->state);
            }
            else if (trans->extra > trans->symbol)
            {
                stm_printf(stm, "%d [%c-%c] --> %d\n", trans_i, trans->symbol, trans->extra, trans->state);
            }
            else
            {
                cassert(trans->extra == trans->symbol);
                if (trans->symbol == '\n')
                    stm_printf(stm, "%d [\\n] --> %d\n", trans_i, trans->state);
                else
                    stm_printf(stm, "%d [%c] --> %d\n", trans_i, trans->symbol, trans->state);
            }
        }
        else
        {
            if (trans->extra != UINT32_MAX)
            {
                stm_printf(stm, "%d [ε1] --> %d [ε2] --> %d\n", trans_i, trans->state, trans->extra);
            }
            else
            {
                stm_printf(stm, "%d [ε] --> %d\n", trans_i, trans->state);
            }
        }
    arrst_end()
}

/*---------------------------------------------------------------------------*/

#if defined(__ASSERTS__)

static bool_t i_is_last(const Trans *trans)
{
    cassert_no_null(trans);
    /* Base, Union and Concat NFA */
    if (trans->state == UINT32_MAX)
        return (bool_t)(trans->symbol == 0 && trans->extra == 0);
    /* Closure NFA */
    else
        return (bool_t)(trans->symbol == UINT32_MAX && trans->extra == UINT32_MAX);
}

/*---------------------------------------------------------------------------*/

static bool_t i_check_nfa(const NFA *nfa)
{
    Trans *ltrans = NULL;
    arrst_foreach(trans, nfa->ttable, Trans)
        if (trans->state != UINT32_MAX && trans->state >= trans_total)
            return FALSE;
    arrst_end()

    ltrans = arrst_last(nfa->ttable, Trans);
    return i_is_last(ltrans);
}

#endif

/*---------------------------------------------------------------------------*/

NFA *_nfa_string(const char_t *str)
{
    NFA *nfa = heap_new0(NFA);
    register uint32_t codepoint = unicode_to_u32(str, ekUTF8);
    register uint32_t i = 0;
    Trans *trans = NULL;
    nfa->ttable = arrst_create(Trans);
    while (codepoint != 0)
    {
        trans = arrst_new(nfa->ttable, Trans);
        trans->state = i + 1;
        trans->symbol = codepoint;
        trans->extra = codepoint;
        i += 1;
        str = unicode_next(str, ekUTF8);
        codepoint = unicode_to_u32(str, ekUTF8);
    }

    trans = arrst_new(nfa->ttable, Trans);
    trans->state = UINT32_MAX;
    trans->symbol = 0;
    trans->extra = 0;
    return nfa;
}

/*---------------------------------------------------------------------------*/

void _nfa_destroy(NFA **nfa)
{
    cassert_no_null(nfa);
    cassert_no_null(*nfa);
    arrst_destroy(&(*nfa)->ttable, NULL, Trans);
    if ((*nfa)->current != NULL)
    {
        arrst_destroy(&(*nfa)->current, NULL, uint32_t);
        arrst_destroy(&(*nfa)->temp, NULL, uint32_t);
    }
    else
    {
        cassert((*nfa)->temp == NULL);
    }

    heap_delete(nfa, NFA);
}

/*---------------------------------------------------------------------------*/

static ArrSt(NToken) *i_tokens_unix_regex(const char_t *regex)
{
    bool_t ok = TRUE;
    ArrSt(NToken) *tokens = arrst_create(NToken);
    ArrSt(NToken) *opens = arrst_create(NToken);
    uint32_t codepoint = unicode_to_u32(regex, ekUTF8);
    bool_t backslash = FALSE;
    while (codepoint != 0 && ok)
    {
        NToken token = {(symbol_t)0, 0, 0};

        if (backslash == TRUE)
        {
            token.symbol = ekCHAR;
            token.from = codepoint;
            regex = unicode_next(regex, ekUTF8);
            codepoint = unicode_to_u32(regex, ekUTF8);
            if (codepoint == '-')
            {
                regex = unicode_next(regex, ekUTF8);
                token.to = unicode_to_u32(regex, ekUTF8);
                if (token.to <= token.from)
                    ok = FALSE;
            }
            else
            {
                regex = unicode_back(regex, ekUTF8);
                token.to = token.from;
            }

            backslash = FALSE;
        }
        else
        {
            switch (codepoint)
            {
            case '\\':
                cassert(backslash == FALSE);
                backslash = TRUE;
                break;

            case '[':
                token.symbol = ekLEFT_PAR;
                token.from = '[';
                arrst_append(opens, token, NToken);
                break;

            case ']':
            {
                NToken *last = arrst_last(opens, NToken);
                token.symbol = ekRIGH_PAR;
                token.from = ']';
                if (last != NULL && last->symbol == ekLEFT_PAR && last->from == '[')
                    arrst_pop(opens, NULL, NToken);
                else
                    ok = FALSE;
                break;
            }

            case '(':
                token.symbol = ekLEFT_PAR;
                token.from = '(';
                arrst_append(opens, token, NToken);
                break;

            case ')':
            {
                NToken *last = arrst_last(opens, NToken);
                token.symbol = ekRIGH_PAR;
                token.from = ')';
                if (last != NULL && last->symbol == ekLEFT_PAR && last->from == '(')
                    arrst_pop(opens, NULL, NToken);
                else
                    ok = FALSE;
                break;
            }

            case '*':
                token.symbol = ekCLOSURE;
                break;

            case '.':
                token.symbol = ekCHAR;
                token.from = MIN_UNICODE;
                token.to = MAX_UNICODE;
                break;

            default:
                token.symbol = ekCHAR;
                token.from = codepoint;
                regex = unicode_next(regex, ekUTF8);
                codepoint = unicode_to_u32(regex, ekUTF8);
                if (codepoint == '-')
                {
                    regex = unicode_next(regex, ekUTF8);
                    token.to = unicode_to_u32(regex, ekUTF8);
                    if (token.to <= token.from)
                        ok = FALSE;
                }
                else
                {
                    regex = unicode_back(regex, ekUTF8);
                    token.to = token.from;
                }
                break;
            }
        }

        if (backslash == FALSE)
            arrst_append(tokens, token, NToken);

        regex = unicode_next(regex, ekUTF8);
        codepoint = unicode_to_u32(regex, ekUTF8);
    }

    if (ok == FALSE || arrst_size(opens, NToken) > 0 || arrst_size(tokens, NToken) == 0)
        arrst_destroy(&tokens, NULL, NToken);

    arrst_destroy(&opens, NULL, NToken);
    return tokens;
}

/*---------------------------------------------------------------------------*/

static void i_implicits_unix_regex(ArrSt(NToken) *tokens)
{
    ArrSt(symbol_t) *implicit = arrst_create(symbol_t);
    register uint32_t i = 0, n = arrst_size(tokens, NToken);
    symbol_t prev = ENUM_MAX(symbol_t);
    arrst_append(implicit, ekCONCAT, symbol_t);
    while (i < n)
    {
        NToken token = *arrst_get(tokens, i, NToken);
        switch (token.symbol)
        {
        case ekCHAR:
        case ekLEFT_PAR:
            if (prev == ekCHAR || prev == ekRIGH_PAR || prev == ekCLOSURE)
            {
                NToken ntoken;
                ntoken.symbol = *arrst_last(implicit, symbol_t);
                arrst_insert(tokens, i, ntoken, NToken);
                i += 1;
                n += 1;
            }

            if (token.symbol == ekLEFT_PAR && token.from == '(')
                arrst_append(implicit, ekCONCAT, symbol_t);
            else if (token.symbol == ekLEFT_PAR && token.from == '[')
                arrst_append(implicit, ekOR, symbol_t);
            break;

        case ekRIGH_PAR:
            arrst_pop(implicit, NULL, symbol_t);
            break;

        case ekOR:
        case ekCONCAT:
        case ekCLOSURE:
        default:
            break;
        }

        prev = token.symbol;
        i += 1;
    }

    cassert(arrst_size(implicit, symbol_t) == 1);
    arrst_destroy(&implicit, NULL, symbol_t);
}

/*---------------------------------------------------------------------------*/
/* Shunting-yard algorithm */
static void i_regex_to_infix(ArrSt(NToken) **tokens)
{
    ArrSt(NToken) *output = arrst_create(NToken);
    ArrSt(NToken) *stack = arrst_create(NToken);
    arrst_foreach(token, *tokens, NToken)
        switch (token->symbol)
        {
        /* If the token is a number, then:
            Push it to the output queue. */
        case ekCHAR:
            arrst_append(output, *token, NToken);
            break;

        /* If the token is an operator, then:
           while (there is an operator at the top of the operator stack with greater precedence)
              and (the operator at the top of the operator stack is not a left parenthesis):
            pop operators from the operator stack onto the output queue.
           Push it onto the operator stack. */
        case ekOR:
        case ekCONCAT:
        case ekCLOSURE:
            while (arrst_size(stack, NToken) > 0)
            {
                const NToken *top = arrst_last(stack, NToken);
                if (top->symbol != ekLEFT_PAR && top->symbol >= token->symbol)
                {
                    arrst_append(output, *top, NToken);
                    arrst_pop(stack, NULL, NToken);
                    if (top->symbol == token->symbol)
                        break;
                }
                else
                {
                    break;
                }
            }
            arrst_append(stack, *token, NToken);
            break;

        /* If the token is a left paren (i.e. "("), then:
           Push it onto the operator stack. */
        case ekLEFT_PAR:
            arrst_append(stack, *token, NToken);
            break;

        /* If the token is a right paren (i.e. ")"), then:
            while the operator at the top of the operator stack is not a left paren:
                pop the operator from the operator stack onto the output queue. */
        case ekRIGH_PAR:
            for (;;)
            {
                NToken top = *arrst_last(stack, NToken);
                arrst_pop(stack, NULL, NToken);
                if (top.symbol != ekLEFT_PAR)
                {
                    arrst_append(output, top, NToken);
                }
                else
                {
                    cassert((token->from == ']' && top.from == '[') || (token->from == ')' && top.from == '('));
                    break;
                }
            }
            break;

            cassert_default();
        }
    arrst_end()

    while (arrst_size(stack, NToken) > 0)
    {
        const NToken *top = arrst_last(stack, NToken);
        arrst_append(output, *top, NToken);
        arrst_pop(stack, NULL, NToken);
    }

    arrst_destroy(&stack, NULL, NToken);
    arrst_destroy(tokens, NULL, NToken);
    *tokens = output;
}

/*---------------------------------------------------------------------------*/

static void i_offset(ArrSt(Trans) *ttable, const uint32_t offset)
{
    register uint32_t i, n = arrst_size(ttable, Trans);
    register Trans *trans = arrst_all(ttable, Trans);

    cassert(n >= 2);
    n -= 1;
    for (i = 0; i < n; ++i, ++trans)
    {
        cassert(trans->state != UINT32_MAX);
        trans->state += offset;
        if (trans->symbol == UINT32_MAX)
        {
            if (trans->extra != UINT32_MAX)
                trans->extra += offset;
        }
    }

    /* Last state == Accept state */
    if (trans->state != UINT32_MAX)
    {
        /* Closure last state */
        cassert(trans->symbol == UINT32_MAX);
        cassert(trans->extra == UINT32_MAX);
        trans->state += offset;
    }

    cassert(i_is_last(trans) == TRUE);
}

/*---------------------------------------------------------------------------*/

static NFA *i_nfa_base(const uint32_t from, const uint32_t to)
{
    NFA *nfa = heap_new0(NFA);
    Trans *trans = NULL;
    nfa->ttable = arrst_create(Trans);
    trans = arrst_new(nfa->ttable, Trans);
    trans->state = 1;
    trans->symbol = from;
    trans->extra = to;
    trans = arrst_new(nfa->ttable, Trans);
    trans->state = UINT32_MAX;
    trans->symbol = 0;
    trans->extra = 0;
    return nfa;
}

/*---------------------------------------------------------------------------*/

static void i_nfa_union(NFA *nfa1, NFA *nfa2)
{
    register uint32_t n1, n2;
    register Trans *trans = NULL;
    register Trans *trans2 = NULL;
    cassert_no_null(nfa1);
    cassert_no_null(nfa2);
    n1 = arrst_size(nfa1->ttable, Trans);
    n2 = arrst_size(nfa2->ttable, Trans);

    /* 1) Move one position all states in nfa1 (the new '0' state)  */
    i_offset(nfa1->ttable, 1);

    /* 2) Move 'n1+1' positions all states in nfa2  */
    i_offset(nfa2->ttable, n1 + 1);

    /* 3) Prepends a new '0' state with two epsilon-transitions to nfa1-'0' and nfa2-'0'*/
    trans = arrst_prepend_n(nfa1->ttable, 1, Trans);
    trans->state = 1;
    trans->symbol = UINT32_MAX;
    trans->extra = n1 + 1;

    /* 4) Adds an epsilon-transition from nfa1-'last' to new 'last'  */
    trans = arrst_last(nfa1->ttable, Trans);
    cassert(i_is_last(trans) == TRUE);
    trans->state = n1 + n2 + 1;
    trans->symbol = UINT32_MAX;
    trans->extra = UINT32_MAX;

    /* 5) Adds an epsilon-transition from nfa2-'last' to new 'last'  */
    trans = arrst_last(nfa2->ttable, Trans);
    cassert(i_is_last(trans) == TRUE);
    trans->state = n1 + n2 + 1;
    trans->symbol = UINT32_MAX;
    trans->extra = UINT32_MAX;

    /* 6) Copy all df2 transitions to df1 */
    arrst_grow(nfa1->ttable, n2, Trans);
    trans = arrst_all(nfa1->ttable, Trans);
    trans += n1 + 1;
    trans2 = arrst_all(nfa2->ttable, Trans);
    bmem_copy_n(trans, trans2, n2, Trans);

    /* 7) Add the last state (accept) */
    trans = arrst_new(nfa1->ttable, Trans);
    trans->state = UINT32_MAX;
    trans->symbol = 0;
    trans->extra = 0;
}

/*---------------------------------------------------------------------------*/

static void i_nfa_concat(NFA *nfa1, NFA *nfa2)
{
    register uint32_t n1, n2;
    register Trans *trans = NULL;
    register Trans *trans2 = NULL;
    cassert_no_null(nfa1);
    cassert_no_null(nfa2);
    n1 = arrst_size(nfa1->ttable, Trans);
    n2 = arrst_size(nfa2->ttable, Trans);

    /* 1) Move 'n1' positions all states in nfa2  */
    i_offset(nfa2->ttable, n1);

    /* 2) Adds an epsilon-transition from nfa1-'last' to nfa2-'0' */
    trans = arrst_last(nfa1->ttable, Trans);
    cassert(i_is_last(trans) == TRUE);
    trans->symbol = UINT32_MAX;

    /* Base, Union and Concat NFA */
    if (trans->state == UINT32_MAX)
    {
        trans->state = n1;
        trans->extra = UINT32_MAX;
    }
    /* Closure NFA */
    else
    {
        cassert(trans->extra == UINT32_MAX);
        trans->extra = n1;
    }

    /* 3) Copy all df2 transitions to df1 */
    arrst_grow(nfa1->ttable, n2, Trans);
    trans = arrst_all(nfa1->ttable, Trans);
    trans += n1;
    trans2 = arrst_all(nfa2->ttable, Trans);
    bmem_copy_n(trans, trans2, n2, Trans);
}

/*---------------------------------------------------------------------------*/

static void i_nfa_closure(NFA *nfa1)
{
    register uint32_t n1;
    register Trans *trans = NULL;
    cassert_no_null(nfa1);
    n1 = arrst_size(nfa1->ttable, Trans);

    /* 1) Move one position all states in nfa1 (the new '0' state)  */
    i_offset(nfa1->ttable, 1);

    /* 2) Prepends a new '0' state with two epsilon-transitions to nfa1-'0' and nfa1-'newlast' */
    trans = arrst_prepend_n(nfa1->ttable, 1, Trans);
    trans->state = 1;
    trans->symbol = UINT32_MAX;
    trans->extra = n1 + 1;

    /* 3) Adds an epsilon-transition from nfa1-'last' to nfa1-'newlast' */
    trans = arrst_last(nfa1->ttable, Trans);
    cassert(i_is_last(trans) == TRUE);
    cassert(trans->symbol == 0);
    trans->symbol = UINT32_MAX;

    /* Base, Union and Concat NFA */
    if (trans->state == UINT32_MAX)
    {
        trans->state = n1 + 1;
        trans->extra = UINT32_MAX;
    }
    /* Closure NFA */
    else
    {
        cassert(trans->state == 0);
        cassert(trans->extra == UINT32_MAX);
        trans->extra = n1 + 1;
    }

    /* 4) Adds a nfa1-'newlast' with a transition to nfa1-'0' */
    trans = arrst_new(nfa1->ttable, Trans);
    trans->state = 1;
    trans->symbol = UINT32_MAX;
    trans->extra = UINT32_MAX;
}

/*---------------------------------------------------------------------------*/

static NFA *i_infix_to_NFA(const ArrSt(NToken) *tokens)
{
    ArrPt(NFA) *stack = arrpt_create(NFA);
    NFA *nfa = NULL;

    arrst_foreach_const(token, tokens, NToken)
        switch (token->symbol)
        {
        case ekCHAR:
        {
            NFA *nfa1 = i_nfa_base(token->from, token->to);
            cassert(i_check_nfa(nfa1) == TRUE);
            arrpt_append(stack, nfa1, NFA);
            break;
        }

        case ekOR:
        {
            NFA *nfa1, *nfa2;
            nfa2 = arrpt_last(stack, NFA);
            arrpt_pop(stack, NULL, NFA);
            nfa1 = arrpt_last(stack, NFA);
            i_nfa_union(nfa1, nfa2);
            cassert(i_check_nfa(nfa1) == TRUE);
            _nfa_destroy(&nfa2);
            break;
        }

        case ekCONCAT:
        {
            NFA *nfa1, *nfa2;
            nfa2 = arrpt_last(stack, NFA);
            arrpt_pop(stack, NULL, NFA);
            nfa1 = arrpt_last(stack, NFA);
            i_nfa_concat(nfa1, nfa2);
            cassert(i_check_nfa(nfa1) == TRUE);
            _nfa_destroy(&nfa2);
            break;
        }

        case ekCLOSURE:
        {
            NFA *nfa1 = arrpt_last(stack, NFA);
            i_nfa_closure(nfa1);
            cassert(i_check_nfa(nfa1) == TRUE);
            break;
        }

        case ekLEFT_PAR:
        case ekRIGH_PAR:
            cassert_default();
        }
    arrst_end()

    nfa = arrpt_last(stack, NFA);
    arrpt_pop(stack, NULL, NFA);
    cassert(arrpt_size(stack, NFA) == 0);
    arrpt_destroy(&stack, NULL, NFA);
    return nfa;
}

/*---------------------------------------------------------------------------*/

NFA *_nfa_regex(const char_t *regex, const bool_t verbose)
{
    ArrSt(NToken) *tokens = i_tokens_unix_regex(regex);
    NFA *nfa = NULL;

    /* Bad composed regex */
    if (tokens == NULL)
        return NULL;

    if (verbose == TRUE)
    {
        stm_writef(kSTDOUT, "Tokens: ");
        i_write_tokens(kSTDOUT, tokens);
    }

    i_implicits_unix_regex(tokens);
    if (verbose == TRUE)
    {
        stm_writef(kSTDOUT, "Implic: ");
        i_write_tokens(kSTDOUT, tokens);
    }

    i_regex_to_infix(&tokens);
    if (verbose == TRUE)
    {
        stm_writef(kSTDOUT, "Infix: ");
        i_write_tokens(kSTDOUT, tokens);
    }

    nfa = i_infix_to_NFA(tokens);
    arrst_destroy(&tokens, NULL, NToken);
    cassert(i_check_nfa(nfa) == TRUE);

    if (verbose == TRUE)
    {
        stm_writef(kSTDOUT, "NFA:\n");
        i_write_nfa(kSTDOUT, nfa);
        stm_flush(kSTDOUT);
    }

    return nfa;
}

/*---------------------------------------------------------------------------*/

static void i_add_state(ArrSt(uint32_t) *states, const uint32_t state)
{
    arrst_foreach(cstate, states, uint32_t)
        if (*cstate == state)
            return;

        if (*cstate > state)
        {
            arrst_insert(states, cstate_i, state, uint32_t);
            return;
        }
    arrst_end()

    arrst_append(states, state, uint32_t);
}

/*---------------------------------------------------------------------------*/

static void i_add_closure(const ArrSt(Trans) *ttable, ArrSt(uint32_t) *states, const uint32_t state)
{
    const Trans *trans = arrst_get_const(ttable, state, Trans);

    if (trans->symbol != UINT32_MAX)
    {
        i_add_state(states, state);
    }
    else
    {
        cassert(trans->state != UINT32_MAX);

        /* Closure last state (accept) */
        if (state == arrst_size(ttable, Trans) - 1)
            i_add_state(states, state);

        i_add_closure(ttable, states, trans->state);

        /* Two epsilons */
        if (trans->extra != UINT32_MAX)
            i_add_closure(ttable, states, trans->extra);
    }
}

/*---------------------------------------------------------------------------*/

void _nfa_start(NFA *nfa)
{
    cassert_no_null(nfa);
    if (nfa->current == NULL)
    {
        cassert(nfa->temp == NULL);
        nfa->current = arrst_create(uint32_t);
        nfa->temp = arrst_create(uint32_t);
    }
    else
    {
        arrst_clear(nfa->current, NULL, uint32_t);
    }

    i_add_closure(nfa->ttable, nfa->current, 0);
}

/*---------------------------------------------------------------------------*/

bool_t _nfa_next(NFA *nfa, const uint32_t codepoint)
{
    cassert_no_null(nfa);
    arrst_clear(nfa->temp, NULL, uint32_t);
    arrst_foreach(state, nfa->current, uint32_t)
        const Trans *trans = arrst_get(nfa->ttable, *state, Trans);
        if (codepoint >= trans->symbol && codepoint <= trans->extra)
            i_add_closure(nfa->ttable, nfa->temp, trans->state);
    arrst_end()

    bmem_swap_type(&nfa->current, &nfa->temp, ArrSt(uint32_t) *);
    return (bool_t)(arrst_size(nfa->current, uint32_t) > 0);
}

/*---------------------------------------------------------------------------*/

bool_t _nfa_accept(NFA *nfa)
{
    register uint32_t accept;
    cassert_no_null(nfa);
    accept = arrst_size(nfa->ttable, Trans) - 1;
    arrst_foreach(state, nfa->current, uint32_t)
        if (*state == accept)
            return TRUE;
    arrst_end()
    return FALSE;
}
