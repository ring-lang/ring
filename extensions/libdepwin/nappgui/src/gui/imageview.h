/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: imageview.h
 * https://nappgui.com/en/gui/imageview.html
 *
 */

/* Image view */

#include "gui.hxx"

__EXTERN_C

_gui_api ImageView *imageview_create(void);

_gui_api void imageview_size(ImageView *view, S2Df size);

_gui_api void imageview_scale(ImageView *view, const gui_scale_t scale);

_gui_api void imageview_image(ImageView *view, const Image *image);

_gui_api void imageview_OnClick(ImageView *view, Listener *listener);

_gui_api void imageview_OnOverDraw(ImageView *view, Listener *listener);

__END_C
