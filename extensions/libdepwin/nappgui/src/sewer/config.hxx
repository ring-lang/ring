/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: config.hxx
 *
 */

/* Project build config */

#ifndef __BASECONFIG_H__
#define __BASECONFIG_H__

/* clang-format off */

/* Architectures */
#include "arch.hxx"

/* Portable basic types */
#include "types.hxx"

#if defined(CMAKE_DEBUG)
    #define __DEBUG__
    #define __ASSERTS__
    #define __MEMORY_AUDITOR__

#elif defined(CMAKE_RELEASE)
    #define __RELEASE__

#elif defined(CMAKE_RELEASEWITHASSERT)
    #define __RELEASE__
    #define __ASSERTS__
    #define __MEMORY_AUDITOR__

#else
    /* Used from exported precompiled package */

#endif

#if defined(__ASSERTS__)
    #define __DEBUG_PARAM(expr)         expr
    #define __DEBUG_PARAMC(expr)        expr,
#else
    #define __DEBUG_PARAM(expr)
    #define __DEBUG_PARAMC(expr)
#endif

#undef PRIu64
#undef PRId64
#if defined (__x86__)
    #if defined (__LINUX__)
        #define PRIu64          "llu"
        #define PRId64          "lld"
    #else
        #define PRIu64          "llu"
        #define PRId64          "lld"
    #endif
#elif defined (__x64__)
    #if defined (__LINUX__)
        #define PRIu64          "lu"
        #define PRId64          "ld"
    #else
        #define PRIu64          "llu"
        #define PRId64          "lld"
    #endif
#elif defined (__ARM__)
    #define PRIu64              "llu"
    #define PRId64              "lld"
#elif defined (__ARM64__)
    #if defined (__LINUX__)
        #define PRIu64          "lu"
        #define PRId64          "ld"
    #else
        #define PRIu64          "llu"
        #define PRId64          "lld"
    #endif
#endif

/*! <Compiler> */
#if defined(__GNUC__) || defined(__clang__)

    #if (__GNUC__ < 4) || (__GNUC__ == 4 && __GNUC_MINOR__ < 2)
        #error At least gcc 4.2 is required
    #endif

    #if defined (__DEPRECATED)
        #undef __DEPRECATED
    #endif

    /*! <Function attributes> */
    #define __CDECL
    #define __MALLOC                        __attribute__((__malloc__))
    #define __PURE                          __attribute__((__pure__))
    #define __CONST                         __attribute__((__const__))
    #define __INLINE                        inline
    #define __DEPRECATED                    __attribute__((__deprecated__))
    #define __SENTINEL                      __attribute__((__sentinel__))

#if (__GNUC__ > 4 || defined(__clang__))
    #define __PRINTF(format_idx, arg_idx)   __attribute__((__format__ (__printf__, format_idx, arg_idx)))
#else
    #define __PRINTF(format_idx, arg_idx)
#endif

    #define __SCANF(format_idx, arg_idx)    __attribute__((__format__ (__scanf__, format_idx, arg_idx)))
    #define __TYPECHECK                     __attribute__((unused))

#if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3) || defined(__clang__)
    #define __ALLOC_SIZE(x)                 __attribute__((__alloc_size__(x)))
    #define __ALLOC_SIZE2(x,y)              __attribute__((__alloc_size__(x,y)))
#else
    #define __ALLOC_SIZE(x)
    #define __ALLOC_SIZE2(x,y)
#endif

    /*! <Optimization Macros> */
    #define __TRUE_EXPECTED(expr)           (__builtin_expect(expr, 1))
    #define __FALSE_EXPECTED(expr)          (__builtin_expect(expr, 0))

#elif defined(_MSC_VER)
    #define __CDECL                         _cdecl
    #define __MALLOC
    #define __PURE
    #define __CONST
    #define __INLINE                        _inline
    #define __DEPRECATED                    _declspec(deprecated)
    #define __SENTINEL
    #define __PRINTF(format_idx, arg_idx)
    #define __SCANF(format_idx, arg_idx)
    #define __TYPECHECK                     _inline
    #define __ALLOC_SIZE(x)
    #define __ALLOC_SIZE2(x,y)
    #define __TRUE_EXPECTED(expr)           (expr)
    #define __FALSE_EXPECTED(expr)          (expr)
#else
    #error Unknown compiler
#endif

#if defined (__UNIX__)
    #define DIR_SEPARATOR   '/'
#elif defined (__WINDOWS__)
    #define DIR_SEPARATOR   '\\'
#else
    #error Unknown Platform
#endif

/*! <32bits sizeof> */
#define sizeof32(x) (uint32_t)sizeof(x)

/*! <Pointer sizeof> */
#define sizeofptr   sizeof(void*)

/*! <Struct Access> */
#if defined (__clang__)
    /* Avoid Warn Using extended field designator is an extension */
    #define STRUCT_MEMBER_OFFSET(type, member) offsetof(type, member)
    /* #define STRUCT_MEMBER_OFFSET(type, member) ((size_t)((char*)&((type*)0)->member - (char*)0))*/
#else
    #define STRUCT_MEMBER_OFFSET(type, member) offsetof(type, member)
#endif

#define STRUCT_MEMBER_SIZE(type, member) sizeof(((type*)0)->member)

#define CHECK_STRUCT_MEMBER_TYPE(type, member, mtype)\
    (void)(&((type*)0)->member == (mtype*)&((type*)0)->member)

/*! <Assigments> */
#define unref(x) (void)(x)
#define PARAM(name, value) (value)

/*! <Bit manipulation> */
#define BIT_SET(data, nbit) ((data) |= (1u << (nbit)))
#define BIT_CLEAR(data, nbit) ((data) &= ~(1u << (nbit)))
#define BIT_TOGGLE(data, nbit) ((data) ^= (1u << (nbit)))
#define BIT_TEST(data, nbit) (bool_t)(((data) >> (nbit)) & 1u)

/*! <Function pointer cast> */
#ifdef  __cplusplus
    #if defined (_MSC_VER)
        #define cast_func_ptr(fptr, type) ((type)(void*)fptr)
        /* #define cast_func_ptr(fptr, type) ((type)(fptr)) // VS2008 */
    #else
        #define cast_func_ptr(fptr, type) ((type)(fptr))
    #endif

#else /* C Compiler */
    #if defined (_MSC_VER) && _MSC_VER >= 1935 /* Visual Studio 2022 version 17.5.0 */
        #define cast_func_ptr(fptr, type) ((type)(void*)fptr)
    #else
        #define cast_func_ptr(fptr, type) ((type)fptr)
    #endif

#endif

#endif
