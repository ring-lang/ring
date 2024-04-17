/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: respack.h
 * https://nappgui.com/en/core/respack.html
 *
 */

/* Resource Packages */

#include "core.hxx"

__EXTERN_C

_core_api void respack_destroy(ResPack **pack);

_core_api const char_t *respack_text(const ResPack *pack, const ResId id);

_core_api const byte_t *respack_file(const ResPack *pack, const ResId id, uint32_t *size);

__END_C
