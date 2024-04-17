/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: guictx.h
 *
 */

/* Gui rendering context */

#include "guictx.hxx"

__EXTERN_C

_draw2d_api GuiCtx *guictx_create(void);

_draw2d_api GuiCtx *guictx_retain(const GuiCtx *context);

_draw2d_api void guictx_destroy(GuiCtx **context);

_draw2d_api void guictx_release(GuiCtx **context);

_draw2d_api const GuiCtx *guictx_get_current(void);

_draw2d_api void guictx_set_current(const GuiCtx *context);

_draw2d_api void guictx_append_label_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_label_create,
    FPtr_gctx_destroy func_label_destroy,
    FPtr_gctx_set_listener func_label_OnClick,
    FPtr_gctx_set_listener func_label_OnMouseEnter,
    FPtr_gctx_set_listener func_label_OnMouseExit,
    FPtr_gctx_set_text func_label_set_text,
    FPtr_gctx_set_cptr func_label_set_font,
    FPtr_gctx_set_enum func_label_set_align,
    FPtr_gctx_set_enum func_label_set_ellipsis,
    FPtr_gctx_set_uint32 func_label_set_text_color,
    FPtr_gctx_set_uint32 func_label_set_bg_color,
    FPtr_gctx_bounds1 func_label_bounds,
    FPtr_gctx_set_ptr func_attach_label_to_panel,
    FPtr_gctx_set_ptr func_detach_label_from_panel,
    FPtr_gctx_set_bool func_label_set_visible,
    FPtr_gctx_set_bool func_label_set_enabled,
    FPtr_gctx_get2_real32 func_label_get_size,
    FPtr_gctx_get2_real32 func_label_get_origin,
    FPtr_gctx_set4_real32 func_label_set_frame);
#define guictx_append_label_manager( \
    context, \
    func_label_create, \
    func_label_destroy, \
    func_label_OnClick, \
    func_label_OnMouseEnter, \
    func_label_OnMouseExit, \
    func_label_set_text, \
    func_label_set_font, \
    func_label_set_align, \
    func_label_set_ellipsis, \
    func_label_set_text_color, \
    func_label_set_bg_color, \
    func_label_bounds, \
    func_attach_label_to_panel, \
    func_detach_label_from_panel, \
    func_label_set_visible, \
    func_label_set_enabled, \
    func_label_get_size, \
    func_label_get_origin, \
    func_label_set_frame, \
    label_type, panel_type, font_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_label_create, label_type), \
        FUNC_CHECK_GCTX_DESTROY(func_label_destroy, label_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_label_OnClick, label_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_label_OnMouseEnter, label_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_label_OnMouseExit, label_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_label_set_text, label_type), \
        FUNC_CHECK_GCTX_SET_CPTR(func_label_set_font, label_type, font_type), \
        FUNC_CHECK_GCTX_SET_ENUM(func_label_set_align, label_type, align_t), \
        FUNC_CHECK_GCTX_SET_ENUM(func_label_set_ellipsis, label_type, ellipsis_t), \
        FUNC_CHECK_GCTX_SET_UINT32(func_label_set_text_color, label_type), \
        FUNC_CHECK_GCTX_SET_UINT32(func_label_set_bg_color, label_type), \
        FUNC_CHECK_GCTX_BOUNDS1(func_label_bounds, label_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_label_to_panel, label_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_label_from_panel, label_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_label_set_visible, label_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_label_set_enabled, label_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_label_get_size, label_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_label_get_origin, label_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_label_set_frame, label_type), \
        guictx_append_label_manager_imp( \
            context, \
            (FPtr_gctx_create)func_label_create, \
            (FPtr_gctx_destroy)func_label_destroy, \
            (FPtr_gctx_set_listener)func_label_OnClick, \
            (FPtr_gctx_set_listener)func_label_OnMouseEnter, \
            (FPtr_gctx_set_listener)func_label_OnMouseExit, \
            (FPtr_gctx_set_text)func_label_set_text, \
            (FPtr_gctx_set_cptr)func_label_set_font, \
            (FPtr_gctx_set_enum)func_label_set_align, \
            (FPtr_gctx_set_enum)func_label_set_ellipsis, \
            (FPtr_gctx_set_uint32)func_label_set_text_color, \
            (FPtr_gctx_set_uint32)func_label_set_bg_color, \
            (FPtr_gctx_bounds1)func_label_bounds, \
            (FPtr_gctx_set_ptr)func_attach_label_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_label_from_panel, \
            (FPtr_gctx_set_bool)func_label_set_visible, \
            (FPtr_gctx_set_bool)func_label_set_enabled, \
            (FPtr_gctx_get2_real32)func_label_get_size, \
            (FPtr_gctx_get2_real32)func_label_get_origin, \
            (FPtr_gctx_set4_real32)func_label_set_frame))

_draw2d_api void guictx_append_button_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_button_create,
    FPtr_gctx_destroy func_button_destroy,
    FPtr_gctx_set_listener func_button_OnClick,
    FPtr_gctx_set_text func_button_set_text,
    FPtr_gctx_set_text func_button_set_tooltip,
    FPtr_gctx_set_cptr func_button_set_font,
    FPtr_gctx_set_enum func_button_set_align,
    FPtr_gctx_set_cptr func_button_set_image,
    FPtr_gctx_set_enum func_button_set_state,
    FPtr_gctx_get_enum func_button_get_state,
    FPtr_gctx_set_real32 func_button_set_vpadding,
    FPtr_gctx_bounds2 func_button_bounds,
    FPtr_gctx_set_ptr func_attach_button_to_panel,
    FPtr_gctx_set_ptr func_detach_button_from_panel,
    FPtr_gctx_set_bool func_button_set_visible,
    FPtr_gctx_set_bool func_button_set_enabled,
    FPtr_gctx_get2_real32 func_button_get_size,
    FPtr_gctx_get2_real32 func_button_get_origin,
    FPtr_gctx_set4_real32 func_button_set_frame);
#define guictx_append_button_manager( \
    context, \
    func_button_create, \
    func_button_destroy, \
    func_button_OnClick, \
    func_button_set_text, \
    func_button_set_tooltip, \
    func_button_set_font, \
    func_button_set_align, \
    func_button_set_image, \
    func_button_set_state, \
    func_button_get_state, \
    func_button_set_vpadding, \
    func_button_bounds, \
    func_attach_button_to_panel, \
    func_detach_button_from_panel, \
    func_button_set_visible, \
    func_button_set_enabled, \
    func_button_get_size, \
    func_button_get_origin, \
    func_button_set_frame, \
    button_type, panel_type, image_type, font_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_button_create, button_type), \
        FUNC_CHECK_GCTX_DESTROY(func_button_destroy, button_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_button_OnClick, button_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_button_set_text, button_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_button_set_tooltip, button_type), \
        FUNC_CHECK_GCTX_SET_CPTR(func_button_set_font, button_type, font_type), \
        FUNC_CHECK_GCTX_SET_ENUM(func_button_set_align, button_type, align_t), \
        FUNC_CHECK_GCTX_SET_CPTR(func_button_set_image, button_type, image_type), \
        FUNC_CHECK_GCTX_SET_ENUM(func_button_set_state, button_type, gui_state_t), \
        FUNC_CHECK_GCTX_GET_ENUM(func_button_get_state, button_type, gui_state_t), \
        FUNC_CHECK_GCTX_SET_REAL32(func_button_set_vpadding, button_type), \
        FUNC_CHECK_GCTX_BOUNDS2(func_button_bounds, button_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_button_to_panel, button_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_button_from_panel, button_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_button_set_visible, button_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_button_set_enabled, button_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_button_get_size, button_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_button_get_origin, button_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_button_set_frame, button_type), \
        guictx_append_button_manager_imp( \
            context, \
            (FPtr_gctx_create)func_button_create, \
            (FPtr_gctx_destroy)func_button_destroy, \
            (FPtr_gctx_set_listener)func_button_OnClick, \
            (FPtr_gctx_set_text)func_button_set_text, \
            (FPtr_gctx_set_text)func_button_set_tooltip, \
            (FPtr_gctx_set_cptr)func_button_set_font, \
            (FPtr_gctx_set_enum)func_button_set_align, \
            (FPtr_gctx_set_cptr)func_button_set_image, \
            (FPtr_gctx_set_enum)func_button_set_state, \
            (FPtr_gctx_get_enum)func_button_get_state, \
            (FPtr_gctx_set_real32)func_button_set_vpadding, \
            (FPtr_gctx_bounds2)func_button_bounds, \
            (FPtr_gctx_set_ptr)func_attach_button_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_button_from_panel, \
            (FPtr_gctx_set_bool)func_button_set_visible, \
            (FPtr_gctx_set_bool)func_button_set_enabled, \
            (FPtr_gctx_get2_real32)func_button_get_size, \
            (FPtr_gctx_get2_real32)func_button_get_origin, \
            (FPtr_gctx_set4_real32)func_button_set_frame))

_draw2d_api void guictx_append_popup_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_popup_create,
    FPtr_gctx_destroy func_popup_destroy,
    FPtr_gctx_set_listener func_popup_OnChange,
    FPtr_gctx_set_elem func_popup_set_elem,
    FPtr_gctx_set_text func_popup_set_tooltip,
    FPtr_gctx_set_cptr func_popup_set_font,
    FPtr_gctx_set_uint32 func_popup_list_height,
    FPtr_gctx_set_uint32 func_popup_set_selected,
    FPtr_gctx_get_uint32 func_popup_get_selected,
    FPtr_gctx_bounds3 func_popup_bounds,
    FPtr_gctx_set_ptr func_attach_popup_to_panel,
    FPtr_gctx_set_ptr func_detach_popup_from_panel,
    FPtr_gctx_set_bool func_popup_set_visible,
    FPtr_gctx_set_bool func_popup_set_enabled,
    FPtr_gctx_get2_real32 func_popup_get_size,
    FPtr_gctx_get2_real32 func_popup_get_origin,
    FPtr_gctx_set4_real32 func_popup_set_frame);
#define guictx_append_popup_manager( \
    context, \
    func_popup_create, \
    func_popup_destroy, \
    func_popup_OnChange, \
    func_popup_set_elem, \
    func_popup_set_tooltip, \
    func_popup_set_font, \
    func_popup_list_height, \
    func_popup_set_selected, \
    func_popup_get_selected, \
    func_popup_bounds, \
    func_attach_popup_to_panel, \
    func_detach_popup_from_panel, \
    func_popup_set_visible, \
    func_popup_set_enabled, \
    func_popup_get_size, \
    func_popup_get_origin, \
    func_popup_set_frame, \
    popup_type, panel_type, image_type, font_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_popup_create, popup_type), \
        FUNC_CHECK_GCTX_DESTROY(func_popup_destroy, popup_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_popup_OnChange, popup_type), \
        FUNC_CHECK_GCTX_SET_ELEM(func_popup_set_elem, popup_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_popup_set_tooltip, popup_type), \
        FUNC_CHECK_GCTX_SET_CPTR(func_popup_set_font, popup_type, font_type), \
        FUNC_CHECK_GCTX_SET_UINT32(func_popup_list_height, popup_type), \
        FUNC_CHECK_GCTX_SET_UINT32(func_popup_set_selected, popup_type), \
        FUNC_CHECK_GCTX_GET_UINT32(func_popup_get_selected, popup_type), \
        FUNC_CHECK_GCTX_BOUNDS3(func_popup_bounds, popup_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_popup_to_panel, popup_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_popup_from_panel, popup_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_popup_set_visible, popup_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_popup_set_enabled, popup_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_popup_get_size, popup_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_popup_get_origin, popup_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_popup_set_frame, popup_type), \
        guictx_append_popup_manager_imp( \
            context, \
            (FPtr_gctx_create)func_popup_create, \
            (FPtr_gctx_destroy)func_popup_destroy, \
            (FPtr_gctx_set_listener)func_popup_OnChange, \
            (FPtr_gctx_set_elem)func_popup_set_elem, \
            (FPtr_gctx_set_text)func_popup_set_tooltip, \
            (FPtr_gctx_set_cptr)func_popup_set_font, \
            (FPtr_gctx_set_uint32)func_popup_list_height, \
            (FPtr_gctx_set_uint32)func_popup_set_selected, \
            (FPtr_gctx_get_uint32)func_popup_get_selected, \
            (FPtr_gctx_bounds3)func_popup_bounds, \
            (FPtr_gctx_set_ptr)func_attach_popup_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_popup_from_panel, \
            (FPtr_gctx_set_bool)func_popup_set_visible, \
            (FPtr_gctx_set_bool)func_popup_set_enabled, \
            (FPtr_gctx_get2_real32)func_popup_get_size, \
            (FPtr_gctx_get2_real32)func_popup_get_origin, \
            (FPtr_gctx_set4_real32)func_popup_set_frame))

_draw2d_api void guictx_append_edit_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_edit_create,
    FPtr_gctx_destroy func_edit_destroy,
    FPtr_gctx_set_listener func_edit_OnFilter,
    FPtr_gctx_set_listener func_edit_OnChange,
    FPtr_gctx_set_listener func_edit_OnFocus,
    FPtr_gctx_set_text func_edit_set_text,
    FPtr_gctx_set_text func_edit_set_tooltip,
    FPtr_gctx_set_cptr func_edit_set_font,
    FPtr_gctx_set_enum func_edit_set_align,
    FPtr_gctx_set_bool func_edit_set_passmode,
    FPtr_gctx_set_bool func_edit_set_editable,
    FPtr_gctx_set_bool func_edit_set_autoselect,
    FPtr_gctx_set2_int32 func_edit_set_select,
    FPtr_gctx_set_uint32 func_edit_set_text_color,
    FPtr_gctx_set_uint32 func_edit_set_bg_color,
    FPtr_gctx_set_real32 func_edit_set_vpadding,
    FPtr_gctx_bounds4 func_edit_bounds,
    FPtr_gctx_clipboard func_edit_clipboard,
    FPtr_gctx_set_ptr func_attach_edit_to_panel,
    FPtr_gctx_set_ptr func_detach_edit_from_panel,
    FPtr_gctx_set_bool func_edit_set_visible,
    FPtr_gctx_set_bool func_edit_set_enabled,
    FPtr_gctx_get2_real32 func_edit_get_size,
    FPtr_gctx_get2_real32 func_edit_get_origin,
    FPtr_gctx_set4_real32 func_edit_set_frame);
#define guictx_append_edit_manager( \
    context, \
    func_edit_create, \
    func_edit_destroy, \
    func_edit_OnFilter, \
    func_edit_OnChange, \
    func_edit_OnFocus, \
    func_edit_set_text, \
    func_edit_set_tooltip, \
    func_edit_set_font, \
    func_edit_set_align, \
    func_edit_set_passmode, \
    func_edit_set_editable, \
    func_edit_set_autoselect, \
    func_edit_set_select, \
    func_edit_set_text_color, \
    func_edit_set_bg_color, \
    func_edit_set_vpadding, \
    func_edit_bounds, \
    func_edit_clipboard, \
    func_attach_edit_to_panel, \
    func_detach_edit_from_panel, \
    func_edit_set_visible, \
    func_edit_set_enabled, \
    func_edit_get_size, \
    func_edit_get_origin, \
    func_edit_set_frame, \
    edit_type, panel_type, font_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_edit_create, edit_type), \
        FUNC_CHECK_GCTX_DESTROY(func_edit_destroy, edit_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_edit_OnFilter, edit_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_edit_OnChange, edit_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_edit_OnFocus, edit_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_edit_set_text, edit_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_edit_set_tooltip, edit_type), \
        FUNC_CHECK_GCTX_SET_CPTR(func_edit_set_font, edit_type, font_type), \
        FUNC_CHECK_GCTX_SET_ENUM(func_edit_set_align, edit_type, align_t), \
        FUNC_CHECK_GCTX_SET_BOOL(func_edit_set_passmode, edit_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_edit_set_editable, edit_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_edit_set_autoselect, edit_type), \
        FUNC_CHECK_GCTX_SET2_INT32(func_edit_set_select, edit_type), \
        FUNC_CHECK_GCTX_SET_UINT32(func_edit_set_text_color, edit_type), \
        FUNC_CHECK_GCTX_SET_UINT32(func_edit_set_bg_color, edit_type), \
        FUNC_CHECK_GCTX_SET_REAL32(func_edit_set_vpadding, edit_type), \
        FUNC_CHECK_GCTX_BOUNDS4(func_edit_bounds, edit_type), \
        FUNC_CHECK_GCTX_CLIPBOARD(func_edit_clipboard, edit_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_edit_to_panel, edit_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_edit_from_panel, edit_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_edit_set_visible, edit_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_edit_set_enabled, edit_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_edit_get_size, edit_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_edit_get_origin, edit_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_edit_set_frame, edit_type), \
        guictx_append_edit_manager_imp( \
            context, \
            (FPtr_gctx_create)func_edit_create, \
            (FPtr_gctx_destroy)func_edit_destroy, \
            (FPtr_gctx_set_listener)func_edit_OnFilter, \
            (FPtr_gctx_set_listener)func_edit_OnChange, \
            (FPtr_gctx_set_listener)func_edit_OnFocus, \
            (FPtr_gctx_set_text)func_edit_set_text, \
            (FPtr_gctx_set_text)func_edit_set_tooltip, \
            (FPtr_gctx_set_cptr)func_edit_set_font, \
            (FPtr_gctx_set_enum)func_edit_set_align, \
            (FPtr_gctx_set_bool)func_edit_set_passmode, \
            (FPtr_gctx_set_bool)func_edit_set_editable, \
            (FPtr_gctx_set_bool)func_edit_set_autoselect, \
            (FPtr_gctx_set2_int32)func_edit_set_select, \
            (FPtr_gctx_set_uint32)func_edit_set_text_color, \
            (FPtr_gctx_set_uint32)func_edit_set_bg_color, \
            (FPtr_gctx_set_real32)func_edit_set_vpadding, \
            (FPtr_gctx_bounds4)func_edit_bounds, \
            (FPtr_gctx_clipboard)func_edit_clipboard, \
            (FPtr_gctx_set_ptr)func_attach_edit_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_edit_from_panel, \
            (FPtr_gctx_set_bool)func_edit_set_visible, \
            (FPtr_gctx_set_bool)func_edit_set_enabled, \
            (FPtr_gctx_get2_real32)func_edit_get_size, \
            (FPtr_gctx_get2_real32)func_edit_get_origin, \
            (FPtr_gctx_set4_real32)func_edit_set_frame))

_draw2d_api void guictx_append_combo_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_combo_create,
    FPtr_gctx_destroy func_combo_destroy,
    FPtr_gctx_set_listener func_combo_OnFilter,
    FPtr_gctx_set_listener func_combo_OnChange,
    FPtr_gctx_set_listener func_combo_OnFocus,
    FPtr_gctx_set_listener func_combo_OnSelect,
    FPtr_gctx_set_text func_combo_set_text,
    FPtr_gctx_set_text func_combo_set_tooltip,
    FPtr_gctx_set_cptr func_combo_set_font,
    FPtr_gctx_set_enum func_combo_set_align,
    FPtr_gctx_set_bool func_combo_set_passmode,
    FPtr_gctx_set_uint32 func_combo_set_text_color,
    FPtr_gctx_set_uint32 func_combo_set_bg_color,
    FPtr_gctx_set_elem func_combo_set_elem,
    FPtr_gctx_set_uint32 func_combo_set_selected,
    FPtr_gctx_get_uint32 func_combo_get_selected,
    FPtr_gctx_bounds5 func_combo_bounds,
    FPtr_gctx_set_ptr func_attach_combo_to_panel,
    FPtr_gctx_set_ptr func_detach_combo_from_panel,
    FPtr_gctx_set_bool func_combo_set_visible,
    FPtr_gctx_set_bool func_combo_set_enabled,
    FPtr_gctx_get2_real32 func_combo_get_size,
    FPtr_gctx_get2_real32 func_combo_get_origin,
    FPtr_gctx_set4_real32 func_combo_set_frame);
#define guictx_append_combo_manager( \
    context, \
    func_combo_create, \
    func_combo_destroy, \
    func_combo_OnFilter, \
    func_combo_OnChange, \
    func_combo_OnFocus, \
    func_combo_OnSelect, \
    func_combo_set_text, \
    func_combo_set_tooltip, \
    func_combo_set_font, \
    func_combo_set_align, \
    func_combo_set_passmode, \
    func_combo_set_text_color, \
    func_combo_set_bg_color, \
    func_combo_set_elem, \
    func_combo_set_selected, \
    func_combo_get_selected, \
    func_combo_bounds, \
    func_attach_combo_to_panel, \
    func_detach_combo_from_panel, \
    func_combo_set_visible, \
    func_combo_set_enabled, \
    func_combo_get_size, \
    func_combo_get_origin, \
    func_combo_set_frame, \
    combo_type, panel_type, image_type, font_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_combo_create, combo_type), \
        FUNC_CHECK_GCTX_DESTROY(func_combo_destroy, combo_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_combo_OnFilter, combo_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_combo_OnChange, combo_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_combo_OnFocus, combo_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_combo_OnSelect, combo_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_combo_set_text, combo_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_combo_set_tooltip, combo_type), \
        FUNC_CHECK_GCTX_SET_CPTR(func_combo_set_font, combo_type, font_type), \
        FUNC_CHECK_GCTX_SET_ENUM(func_combo_set_align, combo_type, align_t), \
        FUNC_CHECK_GCTX_SET_BOOL(func_combo_set_passmode, combo_type), \
        FUNC_CHECK_GCTX_SET_UINT32(func_combo_set_text_color, combo_type), \
        FUNC_CHECK_GCTX_SET_UINT32(func_combo_set_bg_color, combo_type), \
        FUNC_CHECK_GCTX_SET_ELEM(func_combo_set_elem, combo_type), \
        FUNC_CHECK_GCTX_SET_UINT32(func_combo_set_selected, combo_type), \
        FUNC_CHECK_GCTX_GET_UINT32(func_combo_get_selected, combo_type), \
        FUNC_CHECK_GCTX_BOUNDS5(func_combo_bounds, combo_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_combo_to_panel, combo_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_combo_from_panel, combo_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_combo_set_visible, combo_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_combo_set_enabled, combo_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_combo_get_size, combo_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_combo_get_origin, combo_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_combo_set_frame, combo_type), \
        guictx_append_combo_manager_imp( \
            context, \
            (FPtr_gctx_create)func_combo_create, \
            (FPtr_gctx_destroy)func_combo_destroy, \
            (FPtr_gctx_set_listener)func_combo_OnFilter, \
            (FPtr_gctx_set_listener)func_combo_OnChange, \
            (FPtr_gctx_set_listener)func_combo_OnFocus, \
            (FPtr_gctx_set_listener)func_combo_OnSelect, \
            (FPtr_gctx_set_text)func_combo_set_text, \
            (FPtr_gctx_set_text)func_combo_set_tooltip, \
            (FPtr_gctx_set_cptr)func_combo_set_font, \
            (FPtr_gctx_set_enum)func_combo_set_align, \
            (FPtr_gctx_set_bool)func_combo_set_passmode, \
            (FPtr_gctx_set_uint32)func_combo_set_text_color, \
            (FPtr_gctx_set_uint32)func_combo_set_bg_color, \
            (FPtr_gctx_set_elem)func_combo_set_elem, \
            (FPtr_gctx_set_uint32)func_combo_set_selected, \
            (FPtr_gctx_get_uint32)func_combo_get_selected, \
            (FPtr_gctx_bounds5)func_combo_bounds, \
            (FPtr_gctx_set_ptr)func_attach_combo_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_combo_from_panel, \
            (FPtr_gctx_set_bool)func_combo_set_visible, \
            (FPtr_gctx_set_bool)func_combo_set_enabled, \
            (FPtr_gctx_get2_real32)func_combo_get_size, \
            (FPtr_gctx_get2_real32)func_combo_get_origin, \
            (FPtr_gctx_set4_real32)func_combo_set_frame))

_draw2d_api void guictx_append_updown_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_updown_create,
    FPtr_gctx_destroy func_updown_destroy,
    FPtr_gctx_set_listener func_updown_OnClick,
    FPtr_gctx_set_text func_updown_set_tooltip,
    FPtr_gctx_set_ptr func_attach_updown_to_panel,
    FPtr_gctx_set_ptr func_detach_updown_from_panel,
    FPtr_gctx_set_bool func_updown_set_visible,
    FPtr_gctx_set_bool func_updown_set_enabled,
    FPtr_gctx_get2_real32 func_updown_get_size,
    FPtr_gctx_get2_real32 func_updown_get_origin,
    FPtr_gctx_set4_real32 func_updown_set_frame);
#define guictx_append_updown_manager( \
    context, \
    func_updown_create, \
    func_updown_destroy, \
    func_updown_OnClick, \
    func_updown_set_tooltip, \
    func_attach_updown_to_panel, \
    func_detach_updown_from_panel, \
    func_updown_set_visible, \
    func_updown_set_enabled, \
    func_updown_get_size, \
    func_updown_get_origin, \
    func_updown_set_frame, \
    updown_type, panel_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_updown_create, updown_type), \
        FUNC_CHECK_GCTX_DESTROY(func_updown_destroy, updown_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_updown_OnClick, updown_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_updown_set_tooltip, updown_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_updown_to_panel, updown_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_updown_from_panel, updown_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_updown_set_visible, updown_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_updown_set_enabled, updown_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_updown_get_size, updown_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_updown_get_origin, updown_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_updown_set_frame, updown_type), \
        guictx_append_updown_manager_imp( \
            context, \
            (FPtr_gctx_create)func_updown_create, \
            (FPtr_gctx_destroy)func_updown_destroy, \
            (FPtr_gctx_set_listener)func_updown_OnClick, \
            (FPtr_gctx_set_text)func_updown_set_tooltip, \
            (FPtr_gctx_set_ptr)func_attach_updown_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_updown_from_panel, \
            (FPtr_gctx_set_bool)func_updown_set_visible, \
            (FPtr_gctx_set_bool)func_updown_set_enabled, \
            (FPtr_gctx_get2_real32)func_updown_get_size, \
            (FPtr_gctx_get2_real32)func_updown_get_origin, \
            (FPtr_gctx_set4_real32)func_updown_set_frame))

_draw2d_api void guictx_append_slider_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_slider_create,
    FPtr_gctx_destroy func_slider_destroy,
    FPtr_gctx_set_listener func_slider_OnMoved,
    FPtr_gctx_set_text func_slider_set_tooltip,
    FPtr_gctx_tickmarks func_slider_set_tickmarks,
    FPtr_gctx_get_real32 func_slider_get_position,
    FPtr_gctx_set_real32 func_slider_set_position,
    FPtr_gctx_bounds6 func_slider_bounds,
    FPtr_gctx_set_ptr func_attach_slider_to_panel,
    FPtr_gctx_set_ptr func_detach_slider_from_panel,
    FPtr_gctx_set_bool func_slider_set_visible,
    FPtr_gctx_set_bool func_slider_set_enabled,
    FPtr_gctx_get2_real32 func_slider_get_size,
    FPtr_gctx_get2_real32 func_slider_get_origin,
    FPtr_gctx_set4_real32 func_slider_set_frame);
#define guictx_append_slider_manager( \
    context, \
    func_slider_create, \
    func_slider_destroy, \
    func_slider_OnMoved, \
    func_slider_set_tooltip, \
    func_slider_set_tickmarks, \
    func_slider_get_position, \
    func_slider_set_position, \
    func_slider_bounds, \
    func_attach_slider_to_panel, \
    func_detach_slider_from_panel, \
    func_slider_set_visible, \
    func_slider_set_enabled, \
    func_slider_get_size, \
    func_slider_get_origin, \
    func_slider_set_frame, \
    slider_type, panel_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_slider_create, slider_type), \
        FUNC_CHECK_GCTX_DESTROY(func_slider_destroy, slider_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_slider_OnMoved, slider_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_slider_set_tooltip, slider_type), \
        FUNC_CHECK_GCTX_TICKMARKS(func_slider_set_tickmarks, slider_type), \
        FUNC_CHECK_GCTX_GET_REAL32(func_slider_get_position, slider_type), \
        FUNC_CHECK_GCTX_SET_REAL32(func_slider_set_position, slider_type), \
        FUNC_CHECK_GCTX_BOUNDS6(func_slider_bounds, slider_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_slider_to_panel, slider_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_slider_from_panel, slider_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_slider_set_visible, slider_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_slider_set_enabled, slider_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_slider_get_size, slider_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_slider_get_origin, slider_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_slider_set_frame, slider_type), \
        guictx_append_slider_manager_imp( \
            context, \
            (FPtr_gctx_create)func_slider_create, \
            (FPtr_gctx_destroy)func_slider_destroy, \
            (FPtr_gctx_set_listener)func_slider_OnMoved, \
            (FPtr_gctx_set_text)func_slider_set_tooltip, \
            (FPtr_gctx_tickmarks)func_slider_set_tickmarks, \
            (FPtr_gctx_get_real32)func_slider_get_position, \
            (FPtr_gctx_set_real32)func_slider_set_position, \
            (FPtr_gctx_bounds6)func_slider_bounds, \
            (FPtr_gctx_set_ptr)func_attach_slider_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_slider_from_panel, \
            (FPtr_gctx_set_bool)func_slider_set_visible, \
            (FPtr_gctx_set_bool)func_slider_set_enabled, \
            (FPtr_gctx_get2_real32)func_slider_get_size, \
            (FPtr_gctx_get2_real32)func_slider_get_origin, \
            (FPtr_gctx_set4_real32)func_slider_set_frame))

_draw2d_api void guictx_append_progress_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_progress_create,
    FPtr_gctx_destroy func_progress_destroy,
    FPtr_gctx_set_real32 func_progress_set_position,
    FPtr_gctx_get_real32e func_progress_get_thickness,
    FPtr_gctx_set_ptr func_attach_progress_to_panel,
    FPtr_gctx_set_ptr func_detach_progress_from_panel,
    FPtr_gctx_set_bool func_progress_set_visible,
    FPtr_gctx_set_bool func_progress_set_enabled,
    FPtr_gctx_get2_real32 func_progress_get_size,
    FPtr_gctx_get2_real32 func_progress_get_origin,
    FPtr_gctx_set4_real32 func_progress_set_frame);
#define guictx_append_progress_manager( \
    context, \
    func_progress_create, \
    func_progress_destroy, \
    func_progress_set_position, \
    func_progress_get_thickness, \
    func_attach_progress_to_panel, \
    func_detach_progress_from_panel, \
    func_progress_set_visible, \
    func_progress_set_enabled, \
    func_progress_get_size, \
    func_progress_get_origin, \
    func_progress_set_frame, \
    progress_type, panel_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_progress_create, progress_type), \
        FUNC_CHECK_GCTX_DESTROY(func_progress_destroy, progress_type), \
        FUNC_CHECK_GCTX_SET_REAL32(func_progress_set_position, progress_type), \
        FUNC_CHECK_GCTX_GET_REAL32E(func_progress_get_thickness, progress_type, gui_size_t), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_progress_to_panel, progress_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_progress_from_panel, progress_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_progress_set_visible, progress_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_progress_set_enabled, progress_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_progress_get_size, progress_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_progress_get_origin, progress_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_progress_set_frame, progress_type), \
        guictx_append_progress_manager_imp( \
            context, \
            (FPtr_gctx_create)func_progress_create, \
            (FPtr_gctx_destroy)func_progress_destroy, \
            (FPtr_gctx_set_real32)func_progress_set_position, \
            (FPtr_gctx_get_real32e)func_progress_get_thickness, \
            (FPtr_gctx_set_ptr)func_attach_progress_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_progress_from_panel, \
            (FPtr_gctx_set_bool)func_progress_set_visible, \
            (FPtr_gctx_set_bool)func_progress_set_enabled, \
            (FPtr_gctx_get2_real32)func_progress_get_size, \
            (FPtr_gctx_get2_real32)func_progress_get_origin, \
            (FPtr_gctx_set4_real32)func_progress_set_frame))

_draw2d_api void guictx_append_text_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_text_create,
    FPtr_gctx_destroy func_text_destroy,
    FPtr_gctx_set_listener func_text_OnFilter,
    FPtr_gctx_set_listener func_text_OnFocus,
    FPtr_gctx_set_text func_text_insert_text,
    FPtr_gctx_set_text func_text_set_text,
    FPtr_gctx_set_ptr func_text_set_rtf,
    FPtr_gctx_set_property func_text_set_prop,
    FPtr_gctx_set_bool func_text_set_editable,
    FPtr_gctx_get_text func_text_get_text,
    FPtr_gctx_set2_bool func_text_scroller_visible,
    FPtr_gctx_call func_text_set_need_display,
    FPtr_gctx_clipboard func_text_clipboard,
    FPtr_gctx_set_ptr func_attach_text_to_panel,
    FPtr_gctx_set_ptr func_detach_text_from_panel,
    FPtr_gctx_set_bool func_text_set_visible,
    FPtr_gctx_set_bool func_text_set_enabled,
    FPtr_gctx_get2_real32 func_text_get_size,
    FPtr_gctx_get2_real32 func_text_get_origin,
    FPtr_gctx_set4_real32 func_text_set_frame);
#define guictx_append_text_manager( \
    context, \
    func_text_create, \
    func_text_destroy, \
    func_text_OnFilter, \
    func_text_OnFocus, \
    func_text_insert_text, \
    func_text_set_text, \
    func_text_set_rtf, \
    func_text_set_prop, \
    func_text_set_editable, \
    func_text_get_text, \
    func_text_scroller_visible, \
    func_text_set_need_display, \
    func_text_clipboard, \
    func_attach_text_to_panel, \
    func_detach_text_from_panel, \
    func_text_set_visible, \
    func_text_set_enabled, \
    func_text_get_size, \
    func_text_get_origin, \
    func_text_set_frame, \
    text_type, panel_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_text_create, text_type), \
        FUNC_CHECK_GCTX_DESTROY(func_text_destroy, text_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_text_OnFilter, text_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_text_OnFocus, text_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_text_insert_text, text_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_text_set_text, text_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_text_set_rtf, text_type, Stream), \
        FUNC_CHECK_GCTX_SET_PROPERTY(func_text_set_prop, text_type, gui_text_t), \
        FUNC_CHECK_GCTX_SET_BOOL(func_text_set_editable, text_type), \
        FUNC_CHECK_GCTX_GET_TEXT(func_text_get_text, text_type), \
        FUNC_CHECK_GCTX_SET2_BOOL(func_text_scroller_visible, text_type), \
        FUNC_CHECK_GCTX_CALL(func_text_set_need_display, text_type), \
        FUNC_CHECK_GCTX_CLIPBOARD(func_text_clipboard, text_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_text_to_panel, text_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_text_from_panel, text_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_text_set_visible, text_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_text_set_enabled, text_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_text_get_size, text_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_text_get_origin, text_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_text_set_frame, text_type), \
        guictx_append_text_manager_imp( \
            context, \
            (FPtr_gctx_create)func_text_create, \
            (FPtr_gctx_destroy)func_text_destroy, \
            (FPtr_gctx_set_listener)func_text_OnFilter, \
            (FPtr_gctx_set_listener)func_text_OnFocus, \
            (FPtr_gctx_set_text)func_text_insert_text, \
            (FPtr_gctx_set_text)func_text_set_text, \
            (FPtr_gctx_set_ptr)func_text_set_rtf, \
            (FPtr_gctx_set_property)func_text_set_prop, \
            (FPtr_gctx_set_bool)func_text_set_editable, \
            (FPtr_gctx_get_text)func_text_get_text, \
            (FPtr_gctx_set2_bool)func_text_scroller_visible, \
            (FPtr_gctx_call)func_text_set_need_display, \
            (FPtr_gctx_clipboard)func_text_clipboard, \
            (FPtr_gctx_set_ptr)func_attach_text_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_text_from_panel, \
            (FPtr_gctx_set_bool)func_text_set_visible, \
            (FPtr_gctx_set_bool)func_text_set_enabled, \
            (FPtr_gctx_get2_real32)func_text_get_size, \
            (FPtr_gctx_get2_real32)func_text_get_origin, \
            (FPtr_gctx_set4_real32)func_text_set_frame))

_draw2d_api void guictx_append_split_manager_imp(
    GuiCtx *gui_context,
    FPtr_gctx_create func_split_create,
    FPtr_gctx_destroy func_split_destroy,
    FPtr_gctx_set_ptr func_split_attach_control,
    FPtr_gctx_set_ptr func_split_detach_control,
    FPtr_gctx_set_listener func_split_OnDrag,
    FPtr_gctx_set4_real32 func_split_track_area,
    FPtr_gctx_set_ptr func_attach_split_to_panel,
    FPtr_gctx_set_ptr func_detach_split_from_panel,
    FPtr_gctx_set_bool func_split_set_visible,
    FPtr_gctx_set_bool func_split_set_enabled,
    FPtr_gctx_get2_real32 func_split_get_size,
    FPtr_gctx_get2_real32 func_split_get_origin,
    FPtr_gctx_set4_real32 func_split_set_frame);
#define guictx_append_split_manager( \
    gui_context, \
    func_split_create, \
    func_split_destroy, \
    func_split_attach_control, \
    func_split_detach_control, \
    func_split_OnDrag, \
    func_split_track_area, \
    func_attach_split_to_panel, \
    func_detach_split_from_panel, \
    func_split_set_visible, \
    func_split_set_enabled, \
    func_split_get_size, \
    func_split_get_origin, \
    func_split_set_frame, \
    splitv_type, panel_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_split_create, splitv_type), \
        FUNC_CHECK_GCTX_DESTROY(func_split_destroy, splitv_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_split_attach_control, splitv_type, OSControl), \
        FUNC_CHECK_GCTX_SET_PTR(func_split_detach_control, splitv_type, OSControl), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_split_OnDrag, splitv_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_split_track_area, splitv_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_split_to_panel, splitv_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_split_from_panel, splitv_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_split_set_visible, splitv_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_split_set_enabled, splitv_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_split_get_size, splitv_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_split_get_origin, splitv_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_split_set_frame, splitv_type), \
        guictx_append_split_manager_imp( \
            gui_context, \
            (FPtr_gctx_create)func_split_create, \
            (FPtr_gctx_destroy)func_split_destroy, \
            (FPtr_gctx_set_ptr)func_split_attach_control, \
            (FPtr_gctx_set_ptr)func_split_detach_control, \
            (FPtr_gctx_set_listener)func_split_OnDrag, \
            (FPtr_gctx_set4_real32)func_split_track_area, \
            (FPtr_gctx_set_ptr)func_attach_split_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_split_from_panel, \
            (FPtr_gctx_set_bool)func_split_set_visible, \
            (FPtr_gctx_set_bool)func_split_set_enabled, \
            (FPtr_gctx_get2_real32)func_split_get_size, \
            (FPtr_gctx_get2_real32)func_split_get_origin, \
            (FPtr_gctx_set4_real32)func_split_set_frame))

_draw2d_api void guictx_append_view_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_view_create,
    FPtr_gctx_destroy func_view_destroy,
    FPtr_gctx_set_listener func_view_OnDraw,
    FPtr_gctx_set_listener func_view_OnOverlay,
    FPtr_gctx_set_listener func_view_OnEnter,
    FPtr_gctx_set_listener func_view_OnExit,
    FPtr_gctx_set_listener func_view_OnMoved,
    FPtr_gctx_set_listener func_view_OnDown,
    FPtr_gctx_set_listener func_view_OnUp,
    FPtr_gctx_set_listener func_view_OnClick,
    FPtr_gctx_set_listener func_view_OnDrag,
    FPtr_gctx_set_listener func_view_OnWheel,
    FPtr_gctx_set_listener func_view_OnKeyDown,
    FPtr_gctx_set_listener func_view_OnKeyUp,
    FPtr_gctx_set_listener func_view_OnFocus,
    FPtr_gctx_set_listener func_view_OnResignFocus,
    FPtr_gctx_set_listener func_view_OnAcceptFocus,
    FPtr_gctx_set_listener func_view_OnScroll,
    FPtr_gctx_set_listener func_view_OnTouchTap,
    FPtr_gctx_set_listener func_view_OnTouchStartDrag,
    FPtr_gctx_set_listener func_view_OnTouchDragging,
    FPtr_gctx_set_listener func_view_OnTouchEndDrag,
    FPtr_gctx_set_listener func_view_OnTouchStartPinch,
    FPtr_gctx_set_listener func_view_OnTouchPinching,
    FPtr_gctx_set_listener func_view_OnTouchEndPinch,
    FPtr_gctx_set2_real32 func_view_scroll,
    FPtr_gctx_get2_real32 func_view_scroll_get,
    FPtr_gctx_get2_real32 func_view_scroller_size,
    FPtr_gctx_set2_bool func_view_scroller_visible,
    FPtr_gctx_set4_real32 func_view_content_size,
    FPtr_gctx_get_real32 func_view_scale_factor,
    FPtr_gctx_call func_view_set_need_display,
    FPtr_gctx_set_bool func_view_set_drawable,
    FPtr_gctx_get_ptr func_view_get_native_view,
    FPtr_gctx_set_ptr func_attach_view_to_panel,
    FPtr_gctx_set_ptr func_detach_view_from_panel,
    FPtr_gctx_set_bool func_view_set_visible,
    FPtr_gctx_set_bool func_view_set_enabled,
    FPtr_gctx_get2_real32 func_view_get_size,
    FPtr_gctx_get2_real32 func_view_get_origin,
    FPtr_gctx_set4_real32 func_view_set_frame);
#define guictx_append_view_manager( \
    context, \
    func_view_create, \
    func_view_destroy, \
    func_view_OnDraw, \
    func_view_OnOverlay, \
    func_view_OnEnter, \
    func_view_OnExit, \
    func_view_OnMoved, \
    func_view_OnDown, \
    func_view_OnUp, \
    func_view_OnClick, \
    func_view_OnDrag, \
    func_view_OnWheel, \
    func_view_OnKeyDown, \
    func_view_OnKeyUp, \
    func_view_OnFocus, \
    func_view_OnResignFocus, \
    func_view_OnAcceptFocus, \
    func_view_OnScroll, \
    func_view_OnTouchTap, \
    func_view_OnTouchStartDrag, \
    func_view_OnTouchDragging, \
    func_view_OnTouchEndDrag, \
    func_view_OnTouchStartPinch, \
    func_view_OnTouchPinching, \
    func_view_OnTouchEndPinch, \
    func_view_scroll, \
    func_view_scroll_get, \
    func_view_scroller_size, \
    func_view_scroller_visible, \
    func_view_content_size, \
    func_view_scale_factor, \
    func_view_set_need_display, \
    func_view_set_drawable, \
    func_view_get_native_view, \
    func_attach_view_to_panel, \
    func_detach_view_from_panel, \
    func_view_set_visible, \
    func_view_set_enabled, \
    func_view_get_size, \
    func_view_get_origin, \
    func_view_set_frame, \
    view_type, panel_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_view_create, view_type), \
        FUNC_CHECK_GCTX_DESTROY(func_view_destroy, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnDraw, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnOverlay, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnEnter, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnExit, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnMoved, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnDown, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnUp, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnClick, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnDrag, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnWheel, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnKeyDown, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnKeyUp, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnFocus, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnResignFocus, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnAcceptFocus, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnScroll, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnTouchTap, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnTouchStartDrag, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnTouchDragging, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnTouchEndDrag, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnTouchStartPinch, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnTouchPinching, view_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_view_OnTouchEndPinch, view_type), \
        FUNC_CHECK_GCTX_SET2_REAL32(func_view_scroll, view_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_view_scroll_get, view_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_view_scroller_size, view_type), \
        FUNC_CHECK_GCTX_SET2_BOOL(func_view_scroller_visible, view_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_view_content_size, view_type), \
        FUNC_CHECK_GCTX_GET_REAL32(func_view_scale_factor, view_type), \
        FUNC_CHECK_GCTX_CALL(func_view_set_need_display, view_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_view_set_drawable, view_type), \
        FUNC_CHECK_GCTX_GET_PTR(func_view_get_native_view, view_type, void), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_view_to_panel, view_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_view_from_panel, view_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_view_set_visible, view_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_view_set_enabled, view_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_view_get_size, view_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_view_get_origin, view_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_view_set_frame, view_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_view_set_frame, view_type), \
        guictx_append_view_manager_imp( \
            context, \
            (FPtr_gctx_create)func_view_create, \
            (FPtr_gctx_destroy)func_view_destroy, \
            (FPtr_gctx_set_listener)func_view_OnDraw, \
            (FPtr_gctx_set_listener)func_view_OnOverlay, \
            (FPtr_gctx_set_listener)func_view_OnEnter, \
            (FPtr_gctx_set_listener)func_view_OnExit, \
            (FPtr_gctx_set_listener)func_view_OnMoved, \
            (FPtr_gctx_set_listener)func_view_OnDown, \
            (FPtr_gctx_set_listener)func_view_OnUp, \
            (FPtr_gctx_set_listener)func_view_OnClick, \
            (FPtr_gctx_set_listener)func_view_OnDrag, \
            (FPtr_gctx_set_listener)func_view_OnWheel, \
            (FPtr_gctx_set_listener)func_view_OnKeyDown, \
            (FPtr_gctx_set_listener)func_view_OnKeyUp, \
            (FPtr_gctx_set_listener)func_view_OnFocus, \
            (FPtr_gctx_set_listener)func_view_OnResignFocus, \
            (FPtr_gctx_set_listener)func_view_OnAcceptFocus, \
            (FPtr_gctx_set_listener)func_view_OnScroll, \
            (FPtr_gctx_set_listener)func_view_OnTouchTap, \
            (FPtr_gctx_set_listener)func_view_OnTouchStartDrag, \
            (FPtr_gctx_set_listener)func_view_OnTouchDragging, \
            (FPtr_gctx_set_listener)func_view_OnTouchEndDrag, \
            (FPtr_gctx_set_listener)func_view_OnTouchStartPinch, \
            (FPtr_gctx_set_listener)func_view_OnTouchPinching, \
            (FPtr_gctx_set_listener)func_view_OnTouchEndPinch, \
            (FPtr_gctx_set2_real32)func_view_scroll, \
            (FPtr_gctx_get2_real32)func_view_scroll_get, \
            (FPtr_gctx_get2_real32)func_view_scroller_size, \
            (FPtr_gctx_set2_bool)func_view_scroller_visible, \
            (FPtr_gctx_set4_real32)func_view_content_size, \
            (FPtr_gctx_get_real32)func_view_scale_factor, \
            (FPtr_gctx_call)func_view_set_need_display, \
            (FPtr_gctx_set_bool)func_view_set_drawable, \
            (FPtr_gctx_get_ptr)func_view_get_native_view, \
            (FPtr_gctx_set_ptr)func_attach_view_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_view_from_panel, \
            (FPtr_gctx_set_bool)func_view_set_visible, \
            (FPtr_gctx_set_bool)func_view_set_enabled, \
            (FPtr_gctx_get2_real32)func_view_get_size, \
            (FPtr_gctx_get2_real32)func_view_get_origin, \
            (FPtr_gctx_set4_real32)func_view_set_frame))

_draw2d_api void guictx_append_panel_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_panel_create,
    FPtr_gctx_destroy func_panel_destroy,
    FPtr_gctx_set_area func_panel_area,
    FPtr_gctx_get2_real32 func_panel_scroller_size,
    FPtr_gctx_set4_real32 func_panel_content_size,
    FPtr_gctx_call func_panel_set_need_display,
    FPtr_gctx_set_ptr func_attach_panel_to_panel,
    FPtr_gctx_set_ptr func_detach_panel_from_panel,
    FPtr_gctx_set_bool func_panel_set_visible,
    FPtr_gctx_set_bool func_panel_set_enabled,
    FPtr_gctx_get2_real32 func_panel_get_size,
    FPtr_gctx_get2_real32 func_panel_get_origin,
    FPtr_gctx_set4_real32 func_panel_set_frame);
#define guictx_append_panel_manager( \
    context, \
    func_panel_create, \
    func_panel_destroy, \
    func_panel_area, \
    func_panel_scroller_size, \
    func_panel_content_size, \
    func_panel_set_need_display, \
    func_attach_panel_to_panel, \
    func_detach_panel_from_panel, \
    func_panel_set_visible, \
    func_panel_set_enabled, \
    func_panel_get_size, \
    func_panel_get_origin, \
    func_panel_set_frame, \
    panel_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_panel_create, panel_type), \
        FUNC_CHECK_GCTX_DESTROY(func_panel_destroy, panel_type), \
        FUNC_CHECK_GCTX_SET_AREA(func_panel_area, panel_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_panel_scroller_size, panel_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_panel_content_size, panel_type), \
        FUNC_CHECK_GCTX_CALL(func_panel_set_need_display, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_panel_to_panel, panel_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_panel_from_panel, panel_type, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_panel_set_visible, panel_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_panel_set_enabled, panel_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_panel_get_size, panel_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_panel_get_origin, panel_type), \
        FUNC_CHECK_GCTX_SET4_REAL32(func_panel_set_frame, panel_type), \
        guictx_append_panel_manager_imp( \
            context, \
            (FPtr_gctx_create)func_panel_create, \
            (FPtr_gctx_destroy)func_panel_destroy, \
            (FPtr_gctx_set_area)func_panel_area, \
            (FPtr_gctx_get2_real32)func_panel_scroller_size, \
            (FPtr_gctx_set4_real32)func_panel_content_size, \
            (FPtr_gctx_call)func_panel_set_need_display, \
            (FPtr_gctx_set_ptr)func_attach_panel_to_panel, \
            (FPtr_gctx_set_ptr)func_detach_panel_from_panel, \
            (FPtr_gctx_set_bool)func_panel_set_visible, \
            (FPtr_gctx_set_bool)func_panel_set_enabled, \
            (FPtr_gctx_get2_real32)func_panel_get_size, \
            (FPtr_gctx_get2_real32)func_panel_get_origin, \
            (FPtr_gctx_set4_real32)func_panel_set_frame))

_draw2d_api void guictx_append_window_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_window_create,
    FPtr_gctx_create2 func_window_managed,
    FPtr_gctx_destroy func_window_destroy,
    FPtr_gctx_set_listener func_window_OnMoved,
    FPtr_gctx_set_listener func_window_OnResize,
    FPtr_gctx_set_listener func_window_OnClose,
    FPtr_gctx_set_text func_window_set_title,
    FPtr_gctx_set_bool func_window_set_edited,
    FPtr_gctx_set_bool func_window_set_movable,
    FPtr_gctx_set_ptr func_window_set_z_order,
    FPtr_gctx_set_real32 func_window_set_alpha,
    FPtr_gctx_set_bool func_window_enable_mouse_events,
    FPtr_gctx_set_hotkey func_window_hotkey,
    FPtr_gctx_set_ptr func_window_set_taborder,
    FPtr_gctx_set_bool func_window_tabcycle,
    FPtr_gctx_set_enum2 func_window_tabstop,
    FPtr_gctx_set_ptr3 func_window_set_focus,
    FPtr_gctx_get_ptr func_window_get_focus,
    FPtr_gctx_get_enum3 func_window_info_focus,
    FPtr_gctx_set_ptr func_attach_main_panel_to_window,
    FPtr_gctx_set_ptr func_detach_main_panel_from_window,
    FPtr_gctx_set_ptr func_attach_window_to_window,
    FPtr_gctx_set_ptr func_detach_window_from_window,
    FPtr_gctx_set_ptr func_window_launch,
    FPtr_gctx_set_ptr func_window_hide,
    FPtr_gctx_set_ptr2 func_window_launch_modal,
    FPtr_gctx_set_uint32 func_window_stop_modal,
    FPtr_gctx_get2_real32 func_window_get_origin_in_screen_coordinates,
    FPtr_gctx_set2_real32 func_window_set_origin_in_screen_coordinates,
    FPtr_gctx_get2_real32 func_window_get_size,
    FPtr_gctx_set2_real32 func_window_set_size,
    FPtr_gctx_set_ptr func_window_set_default_pushbutton,
    FPtr_gctx_set_ptr func_window_set_cursor,
    FPtr_gctx_set_property func_window_set_property);
#define guictx_append_window_manager( \
    context, \
    func_window_create, \
    func_window_managed, \
    func_window_destroy, \
    func_window_OnMoved, \
    func_window_OnResize, \
    func_window_OnClose, \
    func_window_set_title, \
    func_window_set_edited, \
    func_window_set_movable, \
    func_window_set_z_order, \
    func_window_set_alpha, \
    func_window_enable_mouse_events, \
    func_window_hotkey, \
    func_window_set_taborder, \
    func_window_tabcycle, \
    func_window_tabstop, \
    func_window_set_focus, \
    func_window_get_focus, \
    func_window_info_focus, \
    func_attach_main_panel_to_window, \
    func_detach_main_panel_from_window, \
    func_attach_window_to_window, \
    func_detach_window_from_window, \
    func_window_launch, \
    func_window_hide, \
    func_window_launch_modal, \
    func_window_stop_modal, \
    func_window_get_origin_in_screen_coordinates, \
    func_window_set_origin_in_screen_coordinates, \
    func_window_get_size, \
    func_window_set_size, \
    func_window_set_default_pushbutton, \
    func_window_set_cursor, \
    func_window_set_property, \
    window_type, panel_type, button_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_window_create, window_type), \
        FUNC_CHECK_GCTX_CREATE2(func_window_managed, window_type), \
        FUNC_CHECK_GCTX_DESTROY(func_window_destroy, window_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_window_OnMoved, window_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_window_OnResize, window_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_window_OnClose, window_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_window_set_title, window_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_window_set_edited, window_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_window_set_movable, window_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_window_set_z_order, window_type, window_type), \
        FUNC_CHECK_GCTX_SET_REAL32(func_window_set_alpha, window_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_window_enable_mouse_events, window_type), \
        FUNC_CHECK_GCTX_SET_HOTKEY(func_window_hotkey, window_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_window_set_taborder, window_type, OSControl), \
        FUNC_CHECK_GCTX_SET_BOOL(func_window_tabcycle, window_type), \
        FUNC_CHECK_GCTX_SET_ENUM2(func_window_tabstop, window_type, gui_focus_t), \
        FUNC_CHECK_GCTX_SET_PTR3(func_window_set_focus, window_type, OSControl, gui_focus_t), \
        FUNC_CHECK_GCTX_GET_PTR(func_window_get_focus, window_type, OSControl), \
        FUNC_CHECK_GCTX_GET_ENUM3(func_window_info_focus, window_type, gui_tab_t), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_main_panel_to_window, window_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_main_panel_from_window, window_type, panel_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_window_to_window, window_type, window_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_window_from_window, window_type, window_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_window_launch, window_type, window_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_window_hide, window_type, window_type), \
        FUNC_CHECK_GCTX_SET_PTR2(func_window_launch_modal, window_type, window_type), \
        FUNC_CHECK_GCTX_SET_UINT32(func_window_stop_modal, window_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_window_get_origin_in_screen_coordinates, window_type), \
        FUNC_CHECK_GCTX_SET2_REAL32(func_window_set_origin_in_screen_coordinates, window_type), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_window_get_size, window_type), \
        FUNC_CHECK_GCTX_SET2_REAL32(func_window_set_size, window_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_window_set_default_pushbutton, window_type, button_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_window_set_cursor, window_type, Cursor), \
        FUNC_CHECK_GCTX_SET_PROPERTY(func_window_set_property, window_type, gui_prop_t), \
        guictx_append_window_manager_imp( \
            context, \
            (FPtr_gctx_create)func_window_create, \
            (FPtr_gctx_create2)func_window_managed, \
            (FPtr_gctx_destroy)func_window_destroy, \
            (FPtr_gctx_set_listener)func_window_OnMoved, \
            (FPtr_gctx_set_listener)func_window_OnResize, \
            (FPtr_gctx_set_listener)func_window_OnClose, \
            (FPtr_gctx_set_text)func_window_set_title, \
            (FPtr_gctx_set_bool)func_window_set_edited, \
            (FPtr_gctx_set_bool)func_window_set_movable, \
            (FPtr_gctx_set_ptr)func_window_set_z_order, \
            (FPtr_gctx_set_real32)func_window_set_alpha, \
            (FPtr_gctx_set_bool)func_window_enable_mouse_events, \
            (FPtr_gctx_set_hotkey)func_window_hotkey, \
            (FPtr_gctx_set_ptr)func_window_set_taborder, \
            (FPtr_gctx_set_bool)func_window_tabcycle, \
            (FPtr_gctx_set_enum2)func_window_tabstop, \
            (FPtr_gctx_set_ptr3)func_window_set_focus, \
            (FPtr_gctx_get_ptr)func_window_get_focus, \
            (FPtr_gctx_get_enum3)func_window_info_focus, \
            (FPtr_gctx_set_ptr)func_attach_main_panel_to_window, \
            (FPtr_gctx_set_ptr)func_detach_main_panel_from_window, \
            (FPtr_gctx_set_ptr)func_attach_window_to_window, \
            (FPtr_gctx_set_ptr)func_detach_window_from_window, \
            (FPtr_gctx_set_ptr)func_window_launch, \
            (FPtr_gctx_set_ptr)func_window_hide, \
            (FPtr_gctx_set_ptr2)func_window_launch_modal, \
            (FPtr_gctx_set_uint32)func_window_stop_modal, \
            (FPtr_gctx_get2_real32)func_window_get_origin_in_screen_coordinates, \
            (FPtr_gctx_set2_real32)func_window_set_origin_in_screen_coordinates, \
            (FPtr_gctx_get2_real32)func_window_get_size, \
            (FPtr_gctx_set2_real32)func_window_set_size, \
            (FPtr_gctx_set_ptr)func_window_set_default_pushbutton, \
            (FPtr_gctx_set_ptr)func_window_set_cursor, \
            (FPtr_gctx_set_property)func_window_set_property))

_draw2d_api void guictx_append_menu_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_menu_create,
    FPtr_gctx_destroy func_menu_destroy,
    FPtr_gctx_set_ptr func_attach_menuitem_to_menu,
    FPtr_gctx_set_ptr func_detach_menuitem_from_menu,
    FPtr_gctx_menu func_menu_launch_popup,
    FPtr_gctx_call func_menu_hide_popup);
#define guictx_append_menu_manager( \
    context, \
    func_menu_create, \
    func_menu_destroy, \
    func_attach_menuitem_to_menu, \
    func_detach_menuitem_from_menu, \
    func_menu_launch_popup, \
    func_menu_hide_popup, \
    menu_type, menuitem_type, window_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_menu_create, menu_type), \
        FUNC_CHECK_GCTX_DESTROY(func_menu_destroy, menu_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_menuitem_to_menu, menu_type, menuitem_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_menuitem_from_menu, menu_type, menuitem_type), \
        FUNC_CHECK_GCTX_MENU(func_menu_launch_popup, menu_type, window_type), \
        FUNC_CHECK_GCTX_CALL(func_menu_hide_popup, menu_type), \
        guictx_append_menu_manager_imp( \
            context, \
            (FPtr_gctx_create)func_menu_create, \
            (FPtr_gctx_destroy)func_menu_destroy, \
            (FPtr_gctx_set_ptr)func_attach_menuitem_to_menu, \
            (FPtr_gctx_set_ptr)func_detach_menuitem_from_menu, \
            (FPtr_gctx_menu)func_menu_launch_popup, \
            (FPtr_gctx_call)func_menu_hide_popup))

_draw2d_api void guictx_append_menuitem_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_menuitem_create,
    FPtr_gctx_destroy func_menuitem_destroy,
    FPtr_gctx_set_listener func_menuitem_OnClick,
    FPtr_gctx_set_bool func_menuitem_set_enabled,
    FPtr_gctx_set_bool func_menuitem_set_visible,
    FPtr_gctx_set_text func_menuitem_set_text,
    FPtr_gctx_set_cptr func_menuitem_set_image,
    FPtr_gctx_set_key func_menuitem_set_key_equivalent,
    FPtr_gctx_set_enum func_menuitem_set_state,
    FPtr_gctx_set_ptr func_attach_menu_to_menu_item,
    FPtr_gctx_set_ptr func_detach_menu_from_menu_item);
#define guictx_append_menuitem_manager( \
    context, \
    func_menuitem_create, \
    func_menuitem_destroy, \
    func_menuitem_OnClick, \
    func_menuitem_set_enabled, \
    func_menuitem_set_visible, \
    func_menuitem_set_text, \
    func_menuitem_set_image, \
    func_menuitem_set_key_equivalent, \
    func_menuitem_set_state, \
    func_attach_menu_to_menu_item, \
    func_detach_menu_from_menu_item, \
    menuitem_type, menu_type, image_type) \
    ( \
        FUNC_CHECK_GCTX_CREATE(func_menuitem_create, menuitem_type), \
        FUNC_CHECK_GCTX_DESTROY(func_menuitem_destroy, menuitem_type), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_menuitem_OnClick, menuitem_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_menuitem_set_enabled, menuitem_type), \
        FUNC_CHECK_GCTX_SET_BOOL(func_menuitem_set_visible, menuitem_type), \
        FUNC_CHECK_GCTX_SET_TEXT(func_menuitem_set_text, menuitem_type), \
        FUNC_CHECK_GCTX_SET_CPTR(func_menuitem_set_image, menuitem_type, image_type), \
        FUNC_CHECK_GCTX_SET_KEY(func_menuitem_set_key_equivalent, menuitem_type), \
        FUNC_CHECK_GCTX_SET_ENUM(func_menuitem_set_state, menuitem_type, gui_state_t), \
        FUNC_CHECK_GCTX_SET_PTR(func_attach_menu_to_menu_item, menuitem_type, menu_type), \
        FUNC_CHECK_GCTX_SET_PTR(func_detach_menu_from_menu_item, menuitem_type, menu_type), \
        guictx_append_menuitem_manager_imp( \
            context, \
            (FPtr_gctx_create)func_menuitem_create, \
            (FPtr_gctx_destroy)func_menuitem_destroy, \
            (FPtr_gctx_set_listener)func_menuitem_OnClick, \
            (FPtr_gctx_set_bool)func_menuitem_set_enabled, \
            (FPtr_gctx_set_bool)func_menuitem_set_visible, \
            (FPtr_gctx_set_text)func_menuitem_set_text, \
            (FPtr_gctx_set_cptr)func_menuitem_set_image, \
            (FPtr_gctx_set_key)func_menuitem_set_key_equivalent, \
            (FPtr_gctx_set_enum)func_menuitem_set_state, \
            (FPtr_gctx_set_ptr)func_attach_menu_to_menu_item, \
            (FPtr_gctx_set_ptr)func_detach_menu_from_menu_item))

_draw2d_api void guictx_append_comwin_manager_imp(
    GuiCtx *context,
    FPtr_gctx_win_file func_comwin_file,
    FPtr_gctx_win_color func_comwin_color);
#define guictx_append_comwin_manager( \
    context, \
    func_comwin_file, \
    func_comwin_color, \
    window_type) \
    ( \
        FUNC_CHECK_GCTX_WIN_FILE(func_comwin_file, window_type), \
        FUNC_CHECK_GCTX_WIN_COLOR(func_comwin_color, window_type), \
        guictx_append_comwin_manager_imp( \
            context, \
            (FPtr_gctx_win_file)func_comwin_file, \
            (FPtr_gctx_win_color)func_comwin_color))

_draw2d_api void guictx_append_globals_manager_imp(
    GuiCtx *context,
    FPtr_gctx_get_enum func_globals_device,
    FPtr_gctx_get_enum func_globals_color,
    FPtr_gctx_get2_real32 func_globals_resolution,
    FPtr_gctx_get2_real32 func_globals_mouse_position,
    FPtr_gctx_cursor func_globals_cursor,
    FPtr_gctx_destroy func_globals_cursor_destroy,
    FPtr_gctx_get_indexed func_globals_value,
    FPtr_gctx_set2_real64 func_globals_transitions,
    FPtr_gctx_set_listener func_globals_OnIdle);
#define guictx_append_globals_manager( \
    context, \
    func_globals_device, \
    func_globals_color, \
    func_globals_resolution, \
    func_globals_mouse_position, \
    func_globals_cursor, \
    func_globals_cursor_destroy, \
    func_globals_value, \
    func_globals_transitions, \
    func_globals_OnIdle, \
    image_type) \
    ( \
        FUNC_CHECK_GCTX_GET_ENUM(func_globals_device, void, device_t), \
        FUNC_CHECK_GCTX_GET_ENUM(func_globals_color, syscolor_t, color_t), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_globals_resolution, void), \
        FUNC_CHECK_GCTX_GET2_REAL32(func_globals_mouse_position, void), \
        FUNC_CHECK_GCTX_CURSOR(func_globals_cursor), \
        FUNC_CHECK_GCTX_DESTROY(func_globals_cursor_destroy, Cursor), \
        FUNC_CHECK_GCTX_GET_INDEXED(func_globals_value), \
        FUNC_CHECK_GCTX_SET2_REAL64(func_globals_transitions, void), \
        FUNC_CHECK_GCTX_SET_LISTENER(func_globals_OnIdle, void), \
        guictx_append_globals_manager_imp( \
            context, \
            (FPtr_gctx_get_enum)func_globals_device, \
            cast_func_ptr(func_globals_color, FPtr_gctx_get_enum), \
            (FPtr_gctx_get2_real32)func_globals_resolution, \
            (FPtr_gctx_get2_real32)func_globals_mouse_position, \
            (FPtr_gctx_cursor)func_globals_cursor, \
            (FPtr_gctx_destroy)func_globals_cursor_destroy, \
            (FPtr_gctx_get_indexed)func_globals_value, \
            (FPtr_gctx_set2_real64)func_globals_transitions, \
            (FPtr_gctx_set_listener)func_globals_OnIdle))

_draw2d_api void guictx_append_drawctrl_manager_imp(
    GuiCtx *context,
    FPtr_gctx_get_ptr func_drawctrl_font,
    FPtr_gctx_get_uint32 func_drawctrl_row_padding,
    FPtr_gctx_get_uint32 func_drawctrl_check_width,
    FPtr_gctx_get_uint32 func_drawctrl_check_height,
    FPtr_gctx_get_enum2 func_drawctrl_multisel,
    FPtr_gctx_draw_rect func_drawctrl_clear,
    FPtr_gctx_draw_rect func_drawctrl_header,
    FPtr_gctx_draw_rect func_drawctrl_indicator,
    FPtr_gctx_draw_rect func_drawctrl_fill,
    FPtr_gctx_draw_rect func_drawctrl_focus,
    FPtr_gctx_draw_line func_drawctrl_line,
    FPtr_gctx_draw_text func_drawctrl_text,
    FPtr_gctx_draw_image func_drawctrl_image,
    FPtr_gctx_draw_rect func_drawctrl_checkbox,
    FPtr_gctx_draw_rect func_drawctrl_uncheckbox);
#define guictx_append_drawctrl_manager( \
    context, \
    func_drawctrl_font, \
    func_drawctrl_row_padding, \
    func_drawctrl_check_width, \
    func_drawctrl_check_height, \
    func_drawctrl_multisel, \
    func_drawctrl_clear, \
    func_drawctrl_header, \
    func_drawctrl_indicator, \
    func_drawctrl_fill, \
    func_drawctrl_focus, \
    func_drawctrl_line, \
    func_drawctrl_text, \
    func_drawctrl_image, \
    func_drawctrl_checkbox, \
    func_drawctrl_uncheckbox, \
    context_type) \
    ( \
        FUNC_CHECK_GCTX_GET_PTR(func_drawctrl_font, context_type, Font), \
        FUNC_CHECK_GCTX_GET_UINT32(func_drawctrl_row_padding, context_type), \
        FUNC_CHECK_GCTX_GET_UINT32(func_drawctrl_check_width, context_type), \
        FUNC_CHECK_GCTX_GET_UINT32(func_drawctrl_check_height, context_type), \
        FUNC_CHECK_GCTX_GET_ENUM2(func_drawctrl_multisel, context_type, ctrl_msel_t, vkey_t), \
        FUNC_CHECK_GCTX_DRAW_RECT(func_drawctrl_clear, context_type, enum_t), \
        FUNC_CHECK_GCTX_DRAW_RECT(func_drawctrl_header, context_type, ctrl_state_t), \
        FUNC_CHECK_GCTX_DRAW_RECT(func_drawctrl_indicator, context_type, indicator_t), \
        FUNC_CHECK_GCTX_DRAW_RECT(func_drawctrl_fill, context_type, ctrl_state_t), \
        FUNC_CHECK_GCTX_DRAW_RECT(func_drawctrl_focus, context_type, ctrl_state_t), \
        FUNC_CHECK_GCTX_DRAW_LINE(func_drawctrl_line, context_type), \
        FUNC_CHECK_GCTX_DRAW_TEXT(func_drawctrl_text, context_type, ctrl_state_t), \
        FUNC_CHECK_GCTX_DRAW_IMAGE(func_drawctrl_image, context_type, ctrl_state_t), \
        FUNC_CHECK_GCTX_DRAW_RECT(func_drawctrl_checkbox, context_type, ctrl_state_t), \
        FUNC_CHECK_GCTX_DRAW_RECT(func_drawctrl_uncheckbox, context_type, ctrl_state_t), \
        guictx_append_drawctrl_manager_imp( \
            context, \
            (FPtr_gctx_get_ptr)func_drawctrl_font, \
            (FPtr_gctx_get_uint32)func_drawctrl_row_padding, \
            (FPtr_gctx_get_uint32)func_drawctrl_check_width, \
            (FPtr_gctx_get_uint32)func_drawctrl_check_height, \
            (FPtr_gctx_get_enum2)func_drawctrl_multisel, \
            (FPtr_gctx_draw_rect)func_drawctrl_clear, \
            (FPtr_gctx_draw_rect)func_drawctrl_header, \
            (FPtr_gctx_draw_rect)func_drawctrl_indicator, \
            (FPtr_gctx_draw_rect)func_drawctrl_fill, \
            (FPtr_gctx_draw_rect)func_drawctrl_focus, \
            (FPtr_gctx_draw_line)func_drawctrl_line, \
            (FPtr_gctx_draw_text)func_drawctrl_text, \
            (FPtr_gctx_draw_image)func_drawctrl_image, \
            (FPtr_gctx_draw_rect)func_drawctrl_checkbox, \
            (FPtr_gctx_draw_rect)func_drawctrl_uncheckbox))

__END_C
