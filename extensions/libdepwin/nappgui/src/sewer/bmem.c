/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bmem.c
 *
 */

/* Basic memory system */

#include "bmem.h"
#include "cassert.h"
#include "bmath.h"
#include "nowarn.hxx"
#include <string.h>
#include "warn.hxx"

/*---------------------------------------------------------------------------*/

void bmem_set4(byte_t *dest, const uint32_t size, const byte_t *mask)
{
    cassert_no_null(dest);
    cassert_no_null(mask);
    cassert(size > 0);
#if defined(__MACOS__)
    memset_pattern4((void *)dest, (const void *)mask, (size_t)size);
#else
    {
        register uint32_t i, blocks = size / 4;
        for (i = 0; i < blocks; ++i)
        {
            *dest++ = mask[0];
            *dest++ = mask[1];
            *dest++ = mask[2];
            *dest++ = mask[3];
        }
    }

    {
        register uint32_t i, rest = size % 4;
        for (i = 0; i < rest; ++i)
            *dest++ = mask[i];
    }
#endif
}

/*---------------------------------------------------------------------------*/

void bmem_set8(byte_t *dest, const uint32_t size, const byte_t *mask)
{
    cassert_no_null(dest);
    cassert_no_null(mask);
    cassert(size > 0);
#if defined(__MACOS__)
    memset_pattern8((void *)dest, (const void *)mask, (size_t)size);
#else
    {
        register uint32_t i, blocks = size / 8;
        for (i = 0; i < blocks; ++i)
        {
            *dest++ = mask[0];
            *dest++ = mask[1];
            *dest++ = mask[2];
            *dest++ = mask[3];
            *dest++ = mask[4];
            *dest++ = mask[5];
            *dest++ = mask[6];
            *dest++ = mask[7];
        }
    }

    {
        register uint32_t i, rest = size % 8;
        for (i = 0; i < rest; ++i)
            *dest++ = mask[i];
    }
#endif
}

/*---------------------------------------------------------------------------*/

void bmem_set16(byte_t *dest, const uint32_t size, const byte_t *mask)
{
    cassert_no_null(dest);
    cassert_no_null(mask);
    cassert(size > 0);
#if defined(__MACOS__)
    memset_pattern16((void *)dest, (const void *)mask, (size_t)size);
#else
    {
        register uint32_t i, blocks = size / 16;
        for (i = 0; i < blocks; ++i)
        {
            *dest++ = mask[0];
            *dest++ = mask[1];
            *dest++ = mask[2];
            *dest++ = mask[3];
            *dest++ = mask[4];
            *dest++ = mask[5];
            *dest++ = mask[6];
            *dest++ = mask[7];
            *dest++ = mask[8];
            *dest++ = mask[9];
            *dest++ = mask[10];
            *dest++ = mask[11];
            *dest++ = mask[12];
            *dest++ = mask[13];
            *dest++ = mask[14];
            *dest++ = mask[15];
        }
    }

    {
        register uint32_t i, rest = size % 16;
        for (i = 0; i < rest; ++i)
            *dest++ = mask[i];
    }
#endif
}

/*---------------------------------------------------------------------------*/

int bmem_cmp(const byte_t *mem1, const byte_t *mem2, const uint32_t size)
{
    return memcmp((const void *)mem1, (const void *)mem2, (size_t)size);
}

/*---------------------------------------------------------------------------*/

bool_t bmem_is_zero(const byte_t *mem, const uint32_t size)
{
    uint32_t i;
    for (i = 0; i < size; ++i, ++mem)
    {
        if (*mem != 0)
            return FALSE;
    }
    return TRUE;
}

/*---------------------------------------------------------------------------*/

void bmem_copy(byte_t *dest, const byte_t *src, const uint32_t size)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    cassert(size > 0);
    memcpy((void *)dest, (const void *)src, (size_t)size);
}

/*---------------------------------------------------------------------------*/

void bmem_move(byte_t *dest, const byte_t *src, const uint32_t size)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    cassert(size > 0);
    memmove((void *)dest, (const void *)src, (size_t)size);
}

/*---------------------------------------------------------------------------*/

bool_t bmem_overlaps(const byte_t *mem1, const byte_t *mem2, const uint32_t size1, const uint32_t size2)
{
    cassert_no_null(mem1);
    cassert_no_null(mem2);
    cassert(size1 > 0);
    cassert(size2 > 0);
    if (mem1 > mem2)
    {
        if (mem2 + size2 > mem1)
            return TRUE;
        else
            return FALSE;
    }
    else if (mem2 > mem1)
    {
        if (mem1 + size1 > mem2)
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        return TRUE;
    }
}

/*---------------------------------------------------------------------------*/

void bmem_rev(byte_t *mem, const uint32_t size)
{
    register uint32_t i, m;
    register byte_t *end, t;
    cassert_no_null(mem);
    end = mem + size - 1;
    m = size / 2;
    for (i = 0; i < m; ++i, ++mem, --end)
    {
        t = *mem;
        *mem = *end;
        *end = t;
    }
}

/*---------------------------------------------------------------------------*/

void bmem_rev2(byte_t *mem)
{
    byte_t t;
    cassert_no_null(mem);
    t = mem[0];
    mem[0] = mem[1];
    mem[1] = t;
}

/*---------------------------------------------------------------------------*/

void bmem_rev4(byte_t *mem)
{
    byte_t t;
    cassert_no_null(mem);
    t = mem[0];
    mem[0] = mem[3];
    mem[3] = t;
    t = mem[1];
    mem[1] = mem[2];
    mem[2] = t;
}

/*---------------------------------------------------------------------------*/

void bmem_rev8(byte_t *mem)
{
    byte_t t;
    cassert_no_null(mem);
    t = mem[0];
    mem[0] = mem[7];
    mem[7] = t;
    t = mem[1];
    mem[1] = mem[6];
    mem[6] = t;
    t = mem[2];
    mem[2] = mem[5];
    mem[5] = t;
    t = mem[3];
    mem[3] = mem[4];
    mem[4] = t;
}

/*---------------------------------------------------------------------------*/

void bmem_revcopy(byte_t *dest, const byte_t *src, const uint32_t size)
{
    register uint32_t i;
    dest += size - 1;
    for (i = 0; i < size; ++i, src++, dest--)
        *dest = *src;
}

/*---------------------------------------------------------------------------*/

void bmem_rev_elems_imp(byte_t *data, const uint32_t num_elems, const uint32_t elem_size)
{
    register uint32_t i, j, m;
    register byte_t *end = NULL, t;
    cassert_no_null(data);
    cassert(num_elems > 0);
    end = data + (num_elems - 1) * elem_size;
    m = num_elems / 2;
    for (i = 0; i < m; ++i, data += elem_size, end -= elem_size)
    {
        for (j = 0; j < elem_size; ++j)
        {
            t = data[j];
            data[j] = end[j];
            end[j] = t;
        }
    }
}

/*---------------------------------------------------------------------------*/

void bmem_swap(byte_t *mem1, byte_t *mem2, const uint32_t size)
{
    register uint32_t sizep = size;
    register byte_t *mem1p = mem1;
    register byte_t *mem2p = mem2;
    do
    {
        byte_t tmp = *mem1p;
        *mem1p++ = *mem2p;
        *mem2p++ = tmp;
    } while (--sizep > 0);
}

/*---------------------------------------------------------------------------*/

void bmem_shuffle(byte_t *mem, const uint32_t size, const uint32_t esize)
{
    register uint32_t i;
    for (i = 0; i < size; ++i)
    {
        register uint32_t j = bmath_randi(0, size - 1);
        bmem_swap(mem + i * esize, mem + j * esize, esize);
    }
}
