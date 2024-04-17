/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: textview.inl
 *
 */

/* Text view */

#include "gui.ixx"

__EXTERN_C

void _textview_destroy(TextView **view);

void _textview_dimension(TextView *view, const uint32_t i, real32_t *dim0, real32_t *dim1);

__END_C
