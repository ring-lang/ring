/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: buffer.c
 *
 */

/* Fixed size memory buffers */

#include "buffer.h"
#include "heap.h"
#include <sewer/bmem.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

#define i_SIZE(buffer) *((uint32_t *)buffer)
#define i_DATA(buffer) ((byte_t *)((byte_t *)buffer + sizeof(uint32_t)))

/*---------------------------------------------------------------------------*/

Buffer *buffer_create(const uint32_t size)
{
    Buffer *buffer = (Buffer *)heap_malloc(size + sizeof32(uint32_t), "Buffer");
    i_SIZE(buffer) = size;
    return buffer;
}

/*---------------------------------------------------------------------------*/

Buffer *buffer_with_data(const byte_t *data, const uint32_t size)
{
    Buffer *buffer = buffer_create(size);
    bmem_copy(i_DATA(buffer), data, size);
    return buffer;
}

/*---------------------------------------------------------------------------*/

void buffer_destroy(Buffer **buffer)
{
    cassert_no_null(buffer);
    cassert_no_null(*buffer);
    heap_free((byte_t **)buffer, i_SIZE(*buffer) + sizeof32(uint32_t), "Buffer");
}

/*---------------------------------------------------------------------------*/

uint32_t buffer_size(const Buffer *buffer)
{
    cassert_no_null(buffer);
    return i_SIZE(buffer);
}

/*---------------------------------------------------------------------------*/

byte_t *buffer_data(Buffer *buffer)
{
    cassert_no_null(buffer);
    return i_DATA(buffer);
}

/*---------------------------------------------------------------------------*/

const byte_t *buffer_const(const Buffer *buffer)
{
    cassert_no_null(buffer);
    return i_DATA(buffer);
}
