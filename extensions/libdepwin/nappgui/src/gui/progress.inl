/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: progress.inl
 *
 */

/* Progress indicator */

#include "gui.ixx"

__EXTERN_C

void _progress_destroy(Progress **progress);

void _progress_dimension(Progress *progress, const uint32_t i, real32_t *dim0, real32_t *dim1);

__END_C
