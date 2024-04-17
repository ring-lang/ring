/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bmem_unix.c
 *
 */

/* Operating System memory support */

#include "bmem.h"
#include "bmem.inl"

#if !defined(__UNIX__)
#error This file is for Unix/Unix-like system
#endif

#include "cassert.h"
#include <stdlib.h>
#include <string.h>

/* Posix memalign is available from Snow Leopard */
#if defined(__MACOS__)
#include <AvailabilityMacros.h>
#if defined(MAC_OS_X_VERSION_10_6) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6
#define HAVE_POSIX_MEMALIGN
#endif
#else
#define HAVE_POSIX_MEMALIGN
int posix_memalign(void **memptr, size_t alignment, size_t size);
#endif

/*---------------------------------------------------------------------------*/

void _bmem_start(void)
{
}

/*---------------------------------------------------------------------------*/

void _bmem_finish(void)
{
}

/*---------------------------------------------------------------------------*/

void _bmem_atexit(void)
{
}

/*---------------------------------------------------------------------------*/

byte_t *bmem_aligned_malloc(const uint32_t size, const uint32_t align)
{
    byte_t *mem = NULL;
    /* Align must be power of 2 */
    cassert((align != 0) && (align & (align - 1)) == 0);
#if defined(HAVE_POSIX_MEMALIGN)
    {
        void *mem1 = NULL;
        int ret = 0;
        ret = posix_memalign(&mem1, (size_t)align, (size_t)size);
        mem = (byte_t *)mem1;
        cassert_unref(ret == 0, ret);
    }
#else
    {
        /* Allocates a bigger buffer for alignment purpose, and stores the original allocated
           address just before the aligned buffer for a later call to free */
        void *alloc_mem = malloc((size_t)(size + (align - 1) + sizeofptr));
        mem = ((byte_t *)alloc_mem) + sizeofptr;
        mem += (align - ((size_t)mem & (align - 1)) & (align - 1));
        (void **)mem[-1] = alloc_mem;
    }
#endif

    return mem;
}

/*---------------------------------------------------------------------------*/

byte_t *bmem_aligned_realloc(byte_t *mem, const uint32_t size, const uint32_t new_size, const uint32_t align)
{
    /* Align must be power of 2 */
    cassert_no_null(mem);
    cassert((align != 0) && (align & (align - 1)) == 0);

/* We try 'in place' realloc. */
/* For typical alignments, we can avoid copying. */
#if defined(HAVE_POSIX_MEMALIGN)
    mem = (byte_t *)realloc((byte_t *)mem, (size_t)new_size);
    if (((intptr_t)mem % (intptr_t)align) == 0)
        return mem;
#endif

    /* realloc has not been successful. */
    {
        byte_t *new_mem = bmem_aligned_malloc(new_size, align);
        size_t min_size = size;
        if (new_size < min_size)
            min_size = new_size;
        memcpy((void *)new_mem, (const void *)mem, min_size);
        bmem_free(mem);
        return new_mem;
    }
}

/*---------------------------------------------------------------------------*/

void bmem_free(byte_t *mem)
{
    cassert_no_null(mem);
#if defined(HAVE_POSIX_MEMALIGN)
    free((void *)mem);
#else
    {
        void *memp = (void **)mem[-1];
        free(memp);
    }
#endif
}

/*---------------------------------------------------------------------------*/

void bmem_set1(byte_t *dest, const uint32_t size, const byte_t mask)
{
    cassert_no_null(dest);
    cassert(size > 0);
    memset((void *)dest, (int)mask, (size_t)size);
}

/*---------------------------------------------------------------------------*/

void bmem_set_zero(byte_t *dest, const uint32_t size)
{
    cassert_no_null(dest);
    cassert(size > 0);
    memset((void *)dest, 0, (size_t)size);
}
