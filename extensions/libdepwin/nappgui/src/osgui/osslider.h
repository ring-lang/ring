/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osslider.h
 *
 */

/* Operating System native slider */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSSlider *osslider_create(const uint32_t flags);

_osgui_api void osslider_destroy(OSSlider **slider);

_osgui_api void osslider_OnMoved(OSSlider *slider, Listener *listener);

_osgui_api void osslider_tooltip(OSSlider *slider, const char_t *text);

_osgui_api void osslider_tickmarks(OSSlider *slider, const uint32_t num_tickmarks, const bool_t tickmarks_at_left_top);

_osgui_api void osslider_position(OSSlider *slider, const real32_t position);

_osgui_api real32_t osslider_get_position(const OSSlider *slider);

_osgui_api void osslider_bounds(const OSSlider *slider, const real32_t length, const gui_size_t knob_size, real32_t *width, real32_t *height);

_osgui_api void osslider_attach(OSSlider *slider, OSPanel *panel);

_osgui_api void osslider_detach(OSSlider *slider, OSPanel *panel);

_osgui_api void osslider_visible(OSSlider *slider, const bool_t visible);

_osgui_api void osslider_enabled(OSSlider *slider, const bool_t enabled);

_osgui_api void osslider_size(const OSSlider *slider, real32_t *width, real32_t *height);

_osgui_api void osslider_origin(const OSSlider *slider, real32_t *x, real32_t *y);

_osgui_api void osslider_frame(OSSlider *slider, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
