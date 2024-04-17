/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: core.ixx
 *
 */

/* Core library */

#ifndef __CORE_IXX__
#define __CORE_IXX__

#include "core.hxx"

typedef struct _nfa_t NFA;
typedef struct _evassert_t EvAssert;
typedef struct _lexscn_t LexScn;

typedef void *(*FPtr_retain)(const void *item);
#define FUNC_CHECK_RETAIN(func, type) \
    (void)((type * (*)(const type *)) func == func)

typedef void (*FPtr_release)(void **item);
#define FUNC_CHECK_RELEASE(func, type) \
    (void)((void (*)(type **))func == func)

struct _evassert_t
{
    uint32_t group;
    const char_t *caption;
    const char_t *detail;
    const char_t *file;
    uint32_t line;
};

DeclPt(NFA);

#endif
