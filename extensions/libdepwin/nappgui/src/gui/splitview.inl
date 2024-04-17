/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: splitview.inl
 *
 */

/* Split view */

#include "gui.ixx"

__EXTERN_C

void _splitview_destroy(SplitView **split);

void _splitview_dimension(SplitView *split, const uint32_t di, real32_t *dim0, real32_t *dim1);

void _splitview_expand(SplitView *split, const uint32_t di, const real32_t current_size, const real32_t required_size, real32_t *final_size);

void _splitview_taborder(const SplitView *split, Window *window);

void _splitview_OnResize(SplitView *split, const S2Df *size);

void _splitview_panels(const SplitView *split, uint32_t *num_panels, Panel **panels);

__END_C
