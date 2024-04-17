/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: slider.inl
 *
 */

/* Slider */

#include "gui.ixx"

__EXTERN_C

void _slider_destroy(Slider **slider);

void _slider_dimension(Slider *slider, const uint32_t i, real32_t *dim0, real32_t *dim1);

bool_t _slider_is_horizontal(const Slider *slider);

void _slider_real32(Slider *slider, const real32_t value);

__END_C
