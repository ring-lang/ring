/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bhash.c
 *
 */

/* Hash code from memory block */
/* http://www.azillionmonkeys.com/qed/hash.html */

#include "bhash.h"
#include <sewer/cassert.h>

#define i_GET16BITS(d) (*((const uint16_t *)(d)))

/*---------------------------------------------------------------------------*/

static uint32_t i_incremental_hash(const byte_t *data, const uint32_t size, const uint32_t init_hash)
{
    register uint32_t hash;

    cassert_no_null(data);
    cassert(size > 0);

    hash = init_hash;

    {
        register uint32_t i;
        for (i = (size >> 2); i > 0; --i)
        {
            uint32_t tmp;
            hash += i_GET16BITS(data);
            tmp = (uint32_t)(i_GET16BITS(data + 2) << 11) ^ hash;
            hash = (hash << 16) ^ tmp;
            data += 2 * sizeof(uint16_t);
            hash += hash >> 11;
        }
    }

    {
        register uint32_t rem;
        rem = size & 3;
        switch (rem)
        {
        case 3:
            hash += i_GET16BITS(data);
            hash ^= hash << 16;
            hash ^= (uint32_t)((uint8_t)data[sizeof(uint16_t)]) << 18;
            hash += hash >> 11;
            break;
        case 2:
            hash += i_GET16BITS(data);
            hash ^= hash << 11;
            hash += hash >> 17;
            break;
        case 1:
            hash += (uint8_t)*data;
            hash ^= hash << 10;
            hash += hash >> 1;
            break;
        case 0:
            break;
            cassert_default();
        }
    }

    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;
    return hash;
}

/*---------------------------------------------------------------------------*/

uint32_t bhash_from_block(const byte_t *data, const uint32_t size)
{
    return i_incremental_hash(data, size, size);
}

/*---------------------------------------------------------------------------*/

uint32_t bhash_append_uint32(const uint32_t hash, const uint32_t value)
{
    return i_incremental_hash((const byte_t *)&value, sizeof(uint32_t), hash);
}

/*---------------------------------------------------------------------------*/

uint32_t bhash_append_real32(const uint32_t hash, const real32_t value)
{
    return i_incremental_hash((const byte_t *)&value, sizeof(real32_t), hash);
}
