/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: buffer.h
 * https://nappgui.com/en/core/buffer.html
 *
 */

/* Fixed size memory buffers */

#include "core.hxx"

__EXTERN_C

_core_api Buffer *buffer_create(const uint32_t size);

_core_api Buffer *buffer_with_data(const byte_t *data, const uint32_t size);

_core_api void buffer_destroy(Buffer **buffer);

_core_api uint32_t buffer_size(const Buffer *buffer);

_core_api byte_t *buffer_data(Buffer *buffer);

_core_api const byte_t *buffer_const(const Buffer *buffer);

__END_C
