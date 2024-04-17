/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: progress.h
 * https://nappgui.com/en/gui/progress.html
 *
 */

/* Progress bars */

#include "gui.hxx"

__EXTERN_C

_gui_api Progress *progress_create(void);

_gui_api void progress_undefined(Progress *progress, const bool_t running);

_gui_api void progress_value(Progress *progress, const real32_t value);

__END_C
