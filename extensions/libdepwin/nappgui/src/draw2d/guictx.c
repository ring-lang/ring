/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: guictx.c
 *
 */

/* Gui rendering context */

#include "guictx.h"
#include <core/heap.h>
#include <sewer/cassert.h>

static const GuiCtx *i_CURRENT_CONTEXT = NULL;

/*---------------------------------------------------------------------------*/

GuiCtx *guictx_create(void)
{
    GuiCtx *context = heap_new0(GuiCtx);
    context->retain_count = 0;
    return context;
}

/*---------------------------------------------------------------------------*/

GuiCtx *guictx_retain(const GuiCtx *context)
{
    cassert_no_null(context);
    ((GuiCtx *)context)->retain_count += 1;
    return (GuiCtx *)context;
}

/*---------------------------------------------------------------------------*/

void guictx_destroy(GuiCtx **context)
{
    cassert_no_null(context);
    cassert_no_null(*context);
    cassert((*context)->retain_count == 0);
    heap_delete(context, GuiCtx);
}

/*---------------------------------------------------------------------------*/

void guictx_release(GuiCtx **context)
{
    cassert_no_null(context);
    cassert_no_null(*context);
    cassert((*context)->retain_count > 0);
    ((GuiCtx *)(*context))->retain_count -= 1;
    *context = NULL;
}

/*---------------------------------------------------------------------------*/

const GuiCtx *guictx_get_current(void)
{
    return i_CURRENT_CONTEXT;
}

/*---------------------------------------------------------------------------*/

void guictx_set_current(const GuiCtx *context)
{
    i_CURRENT_CONTEXT = context;
}

/*---------------------------------------------------------------------------*/

void guictx_append_label_manager_imp(
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
    FPtr_gctx_set4_real32 func_label_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_LABEL] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_LABEL] == NULL);
    cassert(context->func_label_OnClick == NULL);
    cassert(context->func_label_OnMouseEnter == NULL);
    cassert(context->func_label_OnMouseExit == NULL);
    cassert(context->func_label_set_text == NULL);
    cassert(context->func_label_set_font == NULL);
    cassert(context->func_label_set_align == NULL);
    cassert(context->func_label_set_ellipsis == NULL);
    cassert(context->func_label_set_text_color == NULL);
    cassert(context->func_label_set_bg_color == NULL);
    cassert(context->func_label_bounds == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_LABEL] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_LABEL] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_LABEL] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_LABEL] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_LABEL] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_LABEL] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_LABEL] == NULL);
    cassert_no_nullf(func_label_create);
    cassert_no_nullf(func_label_destroy);
    cassert_no_nullf(func_label_OnClick);
    cassert_no_nullf(func_label_OnMouseEnter);
    cassert_no_nullf(func_label_OnMouseExit);
    cassert_no_nullf(func_label_set_text);
    cassert_no_nullf(func_label_set_font);
    cassert_no_nullf(func_label_set_align);
    cassert_no_nullf(func_label_set_ellipsis);
    cassert_no_nullf(func_label_set_text_color);
    cassert_no_nullf(func_label_set_bg_color);
    cassert_no_nullf(func_label_bounds);
    cassert_no_nullf(func_attach_label_to_panel);
    cassert_no_nullf(func_detach_label_from_panel);
    cassert_no_nullf(func_label_set_visible);
    cassert_no_nullf(func_label_set_enabled);
    cassert_no_nullf(func_label_get_size);
    cassert_no_nullf(func_label_get_origin);
    cassert_no_nullf(func_label_set_frame);
    context->func_create[ekGUI_TYPE_LABEL] = func_label_create;
    context->func_destroy[ekGUI_TYPE_LABEL] = func_label_destroy;
    context->func_label_OnClick = func_label_OnClick;
    context->func_label_OnMouseEnter = func_label_OnMouseEnter;
    context->func_label_OnMouseExit = func_label_OnMouseExit;
    context->func_label_set_text = func_label_set_text;
    context->func_label_set_font = func_label_set_font;
    context->func_label_set_align = func_label_set_align;
    context->func_label_set_ellipsis = func_label_set_ellipsis;
    context->func_label_set_text_color = func_label_set_text_color;
    context->func_label_set_bg_color = func_label_set_bg_color;
    context->func_label_bounds = func_label_bounds;
    context->func_attach_to_panel[ekGUI_TYPE_LABEL] = func_attach_label_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_LABEL] = func_detach_label_from_panel;
    context->func_set_visible[ekGUI_TYPE_LABEL] = func_label_set_visible;
    context->func_set_enabled[ekGUI_TYPE_LABEL] = func_label_set_enabled;
    context->func_get_size[ekGUI_TYPE_LABEL] = func_label_get_size;
    context->func_get_origin[ekGUI_TYPE_LABEL] = func_label_get_origin;
    context->func_set_frame[ekGUI_TYPE_LABEL] = func_label_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_button_manager_imp(
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
    FPtr_gctx_set4_real32 func_button_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_BUTTON] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_BUTTON] == NULL);
    cassert(context->func_button_OnClick == NULL);
    cassert(context->func_button_set_text == NULL);
    cassert(context->func_set_tooltip[ekGUI_TYPE_BUTTON] == NULL);
    cassert(context->func_button_set_font == NULL);
    cassert(context->func_button_set_align == NULL);
    cassert(context->func_button_set_image == NULL);
    cassert(context->func_button_set_state == NULL);
    cassert(context->func_button_get_state == NULL);
    cassert(context->func_button_set_vpadding == NULL);
    cassert(context->func_button_bounds == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_BUTTON] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_BUTTON] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_BUTTON] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_BUTTON] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_BUTTON] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_BUTTON] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_BUTTON] == NULL);
    cassert_no_nullf(func_button_create);
    cassert_no_nullf(func_button_destroy);
    cassert_no_nullf(func_button_OnClick);
    cassert_no_nullf(func_button_set_text);
    cassert_no_nullf(func_button_set_tooltip);
    cassert_no_nullf(func_button_set_font);
    cassert_no_nullf(func_button_set_align);
    cassert_no_nullf(func_button_set_image);
    cassert_no_nullf(func_button_set_state);
    cassert_no_nullf(func_button_get_state);
    cassert_no_nullf(func_button_set_vpadding);
    cassert_no_nullf(func_button_bounds);
    cassert_no_nullf(func_attach_button_to_panel);
    cassert_no_nullf(func_detach_button_from_panel);
    cassert_no_nullf(func_button_set_visible);
    cassert_no_nullf(func_button_set_enabled);
    cassert_no_nullf(func_button_get_size);
    cassert_no_nullf(func_button_get_origin);
    cassert_no_nullf(func_button_set_frame);
    context->func_create[ekGUI_TYPE_BUTTON] = func_button_create;
    context->func_destroy[ekGUI_TYPE_BUTTON] = func_button_destroy;
    context->func_button_OnClick = func_button_OnClick;
    context->func_button_set_text = func_button_set_text;
    context->func_set_tooltip[ekGUI_TYPE_BUTTON] = func_button_set_tooltip;
    context->func_button_set_font = func_button_set_font;
    context->func_button_set_align = func_button_set_align;
    context->func_button_set_image = func_button_set_image;
    context->func_button_set_state = func_button_set_state;
    context->func_button_get_state = func_button_get_state;
    context->func_button_set_vpadding = func_button_set_vpadding;
    context->func_button_bounds = func_button_bounds;
    context->func_attach_to_panel[ekGUI_TYPE_BUTTON] = func_attach_button_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_BUTTON] = func_detach_button_from_panel;
    context->func_set_visible[ekGUI_TYPE_BUTTON] = func_button_set_visible;
    context->func_set_enabled[ekGUI_TYPE_BUTTON] = func_button_set_enabled;
    context->func_get_size[ekGUI_TYPE_BUTTON] = func_button_get_size;
    context->func_get_origin[ekGUI_TYPE_BUTTON] = func_button_get_origin;
    context->func_set_frame[ekGUI_TYPE_BUTTON] = func_button_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_popup_manager_imp(
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
    FPtr_gctx_set4_real32 func_popup_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_POPUP] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_POPUP] == NULL);
    cassert(context->func_popup_OnChange == NULL);
    cassert(context->func_popup_set_elem == NULL);
    cassert(context->func_set_tooltip[ekGUI_TYPE_POPUP] == NULL);
    cassert(context->func_popup_set_font == NULL);
    cassert(context->func_popup_list_height == NULL);
    cassert(context->func_popup_set_selected == NULL);
    cassert(context->func_popup_get_selected == NULL);
    cassert(context->func_popup_bounds == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_POPUP] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_POPUP] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_POPUP] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_POPUP] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_POPUP] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_POPUP] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_POPUP] == NULL);
    cassert_no_nullf(func_popup_create);
    cassert_no_nullf(func_popup_destroy);
    cassert_no_nullf(func_popup_OnChange);
    cassert_no_nullf(func_popup_set_elem);
    cassert_no_nullf(func_popup_set_tooltip);
    cassert_no_nullf(func_popup_set_font);
    cassert_no_nullf(func_popup_list_height);
    cassert_no_nullf(func_popup_set_selected);
    cassert_no_nullf(func_popup_get_selected);
    cassert_no_nullf(func_popup_bounds);
    cassert_no_nullf(func_attach_popup_to_panel);
    cassert_no_nullf(func_detach_popup_from_panel);
    cassert_no_nullf(func_popup_set_visible);
    cassert_no_nullf(func_popup_set_enabled);
    cassert_no_nullf(func_popup_get_size);
    cassert_no_nullf(func_popup_get_origin);
    cassert_no_nullf(func_popup_set_frame);
    context->func_create[ekGUI_TYPE_POPUP] = func_popup_create;
    context->func_destroy[ekGUI_TYPE_POPUP] = func_popup_destroy;
    context->func_popup_OnChange = func_popup_OnChange;
    context->func_popup_set_elem = func_popup_set_elem;
    context->func_set_tooltip[ekGUI_TYPE_POPUP] = func_popup_set_tooltip;
    context->func_popup_set_font = func_popup_set_font;
    context->func_popup_list_height = func_popup_list_height;
    context->func_popup_set_selected = func_popup_set_selected;
    context->func_popup_get_selected = func_popup_get_selected;
    context->func_popup_bounds = func_popup_bounds;
    context->func_attach_to_panel[ekGUI_TYPE_POPUP] = func_attach_popup_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_POPUP] = func_detach_popup_from_panel;
    context->func_set_visible[ekGUI_TYPE_POPUP] = func_popup_set_visible;
    context->func_set_enabled[ekGUI_TYPE_POPUP] = func_popup_set_enabled;
    context->func_get_size[ekGUI_TYPE_POPUP] = func_popup_get_size;
    context->func_get_origin[ekGUI_TYPE_POPUP] = func_popup_get_origin;
    context->func_set_frame[ekGUI_TYPE_POPUP] = func_popup_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_edit_manager_imp(
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
    FPtr_gctx_set4_real32 func_edit_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_EDITBOX] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_EDITBOX] == NULL);
    cassert(context->func_edit_OnFilter == NULL);
    cassert(context->func_edit_OnChange == NULL);
    cassert(context->func_edit_OnFocus == NULL);
    cassert(context->func_edit_set_text == NULL);
    cassert(context->func_set_tooltip[ekGUI_TYPE_EDITBOX] == NULL);
    cassert(context->func_edit_set_font == NULL);
    cassert(context->func_edit_set_align == NULL);
    cassert(context->func_edit_set_passmode == NULL);
    cassert(context->func_edit_set_editable == NULL);
    cassert(context->func_edit_set_autoselect == NULL);
    cassert(context->func_edit_set_select == NULL);
    cassert(context->func_edit_set_text_color == NULL);
    cassert(context->func_edit_set_bg_color == NULL);
    cassert(context->func_edit_set_vpadding == NULL);
    cassert(context->func_edit_bounds == NULL);
    cassert(context->func_edit_clipboard == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_EDITBOX] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_EDITBOX] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_EDITBOX] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_EDITBOX] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_EDITBOX] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_EDITBOX] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_EDITBOX] == NULL);
    cassert_no_nullf(func_edit_create);
    cassert_no_nullf(func_edit_destroy);
    cassert_no_nullf(func_edit_OnFilter);
    cassert_no_nullf(func_edit_OnChange);
    cassert_no_nullf(func_edit_OnFocus);
    cassert_no_nullf(func_edit_set_text);
    cassert_no_nullf(func_edit_set_tooltip);
    cassert_no_nullf(func_edit_set_font);
    cassert_no_nullf(func_edit_set_align);
    cassert_no_nullf(func_edit_set_passmode);
    cassert_no_nullf(func_edit_set_editable);
    cassert_no_nullf(func_edit_set_autoselect);
    cassert_no_nullf(func_edit_set_select);
    cassert_no_nullf(func_edit_set_text_color);
    cassert_no_nullf(func_edit_set_bg_color);
    cassert_no_nullf(func_edit_set_vpadding);
    cassert_no_nullf(func_edit_bounds);
    cassert_no_nullf(func_edit_clipboard);
    cassert_no_nullf(func_attach_edit_to_panel);
    cassert_no_nullf(func_detach_edit_from_panel);
    cassert_no_nullf(func_edit_set_visible);
    cassert_no_nullf(func_edit_set_enabled);
    cassert_no_nullf(func_edit_get_size);
    cassert_no_nullf(func_edit_get_origin);
    cassert_no_nullf(func_edit_set_frame);
    context->func_create[ekGUI_TYPE_EDITBOX] = func_edit_create;
    context->func_destroy[ekGUI_TYPE_EDITBOX] = func_edit_destroy;
    context->func_edit_OnFilter = func_edit_OnFilter;
    context->func_edit_OnChange = func_edit_OnChange;
    context->func_edit_OnFocus = func_edit_OnFocus;
    context->func_edit_set_text = func_edit_set_text;
    context->func_set_tooltip[ekGUI_TYPE_EDITBOX] = func_edit_set_tooltip;
    context->func_edit_set_font = func_edit_set_font;
    context->func_edit_set_align = func_edit_set_align;
    context->func_edit_set_passmode = func_edit_set_passmode;
    context->func_edit_set_editable = func_edit_set_editable;
    context->func_edit_set_autoselect = func_edit_set_autoselect;
    context->func_edit_set_select = func_edit_set_select;
    context->func_edit_set_text_color = func_edit_set_text_color;
    context->func_edit_set_bg_color = func_edit_set_bg_color;
    context->func_edit_set_vpadding = func_edit_set_vpadding;
    context->func_edit_bounds = func_edit_bounds;
    context->func_edit_clipboard = func_edit_clipboard;
    context->func_attach_to_panel[ekGUI_TYPE_EDITBOX] = func_attach_edit_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_EDITBOX] = func_detach_edit_from_panel;
    context->func_set_visible[ekGUI_TYPE_EDITBOX] = func_edit_set_visible;
    context->func_set_enabled[ekGUI_TYPE_EDITBOX] = func_edit_set_enabled;
    context->func_get_size[ekGUI_TYPE_EDITBOX] = func_edit_get_size;
    context->func_get_origin[ekGUI_TYPE_EDITBOX] = func_edit_get_origin;
    context->func_set_frame[ekGUI_TYPE_EDITBOX] = func_edit_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_combo_manager_imp(
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
    FPtr_gctx_set4_real32 func_combo_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert(context->func_combo_OnFilter == NULL);
    cassert(context->func_combo_OnChange == NULL);
    cassert(context->func_combo_OnFocus == NULL);
    cassert(context->func_combo_OnSelect == NULL);
    cassert(context->func_combo_set_text == NULL);
    cassert(context->func_set_tooltip[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert(context->func_combo_set_font == NULL);
    cassert(context->func_combo_set_align == NULL);
    cassert(context->func_combo_set_passmode == NULL);
    cassert(context->func_combo_set_text_color == NULL);
    cassert(context->func_combo_set_bg_color == NULL);
    cassert(context->func_combo_set_elem == NULL);
    cassert(context->func_combo_set_selected == NULL);
    cassert(context->func_combo_get_selected == NULL);
    cassert(context->func_combo_bounds == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_COMBOBOX] == NULL);
    cassert_no_nullf(func_combo_create);
    cassert_no_nullf(func_combo_destroy);
    cassert_no_nullf(func_combo_OnFilter);
    cassert_no_nullf(func_combo_OnChange);
    cassert_no_nullf(func_combo_OnFocus);
    cassert_no_nullf(func_combo_OnSelect);
    cassert_no_nullf(func_combo_set_text);
    cassert_no_nullf(func_combo_set_tooltip);
    cassert_no_nullf(func_combo_set_font);
    cassert_no_nullf(func_combo_set_align);
    cassert_no_nullf(func_combo_set_passmode);
    cassert_no_nullf(func_combo_set_text_color);
    cassert_no_nullf(func_combo_set_bg_color);
    cassert_no_nullf(func_combo_set_elem);
    cassert_no_nullf(func_combo_set_selected);
    cassert_no_nullf(func_combo_get_selected);
    cassert_no_nullf(func_combo_bounds);
    cassert_no_nullf(func_attach_combo_to_panel);
    cassert_no_nullf(func_detach_combo_from_panel);
    cassert_no_nullf(func_combo_set_visible);
    cassert_no_nullf(func_combo_set_enabled);
    cassert_no_nullf(func_combo_get_size);
    cassert_no_nullf(func_combo_get_origin);
    cassert_no_nullf(func_combo_set_frame);
    context->func_create[ekGUI_TYPE_COMBOBOX] = func_combo_create;
    context->func_destroy[ekGUI_TYPE_COMBOBOX] = func_combo_destroy;
    context->func_combo_OnFilter = func_combo_OnFilter;
    context->func_combo_OnChange = func_combo_OnChange;
    context->func_combo_OnFocus = func_combo_OnFocus;
    context->func_combo_OnSelect = func_combo_OnSelect;
    context->func_combo_set_text = func_combo_set_text;
    context->func_set_tooltip[ekGUI_TYPE_COMBOBOX] = func_combo_set_tooltip;
    context->func_combo_set_font = func_combo_set_font;
    context->func_combo_set_align = func_combo_set_align;
    context->func_combo_set_passmode = func_combo_set_passmode;
    context->func_combo_set_text_color = func_combo_set_text_color;
    context->func_combo_set_bg_color = func_combo_set_bg_color;
    context->func_combo_set_elem = func_combo_set_elem;
    context->func_combo_set_selected = func_combo_set_selected;
    context->func_combo_get_selected = func_combo_get_selected;
    context->func_combo_bounds = func_combo_bounds;
    context->func_attach_to_panel[ekGUI_TYPE_COMBOBOX] = func_attach_combo_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_COMBOBOX] = func_detach_combo_from_panel;
    context->func_set_visible[ekGUI_TYPE_COMBOBOX] = func_combo_set_visible;
    context->func_set_enabled[ekGUI_TYPE_COMBOBOX] = func_combo_set_enabled;
    context->func_get_size[ekGUI_TYPE_COMBOBOX] = func_combo_get_size;
    context->func_get_origin[ekGUI_TYPE_COMBOBOX] = func_combo_get_origin;
    context->func_set_frame[ekGUI_TYPE_COMBOBOX] = func_combo_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_updown_manager_imp(
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
    FPtr_gctx_set4_real32 func_updown_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_UPDOWN] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_UPDOWN] == NULL);
    cassert(context->func_updown_OnClick == NULL);
    cassert(context->func_set_tooltip[ekGUI_TYPE_UPDOWN] == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_UPDOWN] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_UPDOWN] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_UPDOWN] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_UPDOWN] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_UPDOWN] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_UPDOWN] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_UPDOWN] == NULL);
    cassert_no_nullf(func_updown_create);
    cassert_no_nullf(func_updown_destroy);
    cassert_no_nullf(func_updown_OnClick);
    cassert_no_nullf(func_updown_set_tooltip);
    cassert_no_nullf(func_attach_updown_to_panel);
    cassert_no_nullf(func_detach_updown_from_panel);
    cassert_no_nullf(func_updown_set_visible);
    cassert_no_nullf(func_updown_set_enabled);
    cassert_no_nullf(func_updown_get_size);
    cassert_no_nullf(func_updown_get_origin);
    cassert_no_nullf(func_updown_set_frame);
    context->func_create[ekGUI_TYPE_UPDOWN] = func_updown_create;
    context->func_destroy[ekGUI_TYPE_UPDOWN] = func_updown_destroy;
    context->func_updown_OnClick = func_updown_OnClick;
    context->func_set_tooltip[ekGUI_TYPE_UPDOWN] = func_updown_set_tooltip;
    context->func_attach_to_panel[ekGUI_TYPE_UPDOWN] = func_attach_updown_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_UPDOWN] = func_detach_updown_from_panel;
    context->func_set_visible[ekGUI_TYPE_UPDOWN] = func_updown_set_visible;
    context->func_set_enabled[ekGUI_TYPE_UPDOWN] = func_updown_set_enabled;
    context->func_get_size[ekGUI_TYPE_UPDOWN] = func_updown_get_size;
    context->func_get_origin[ekGUI_TYPE_UPDOWN] = func_updown_get_origin;
    context->func_set_frame[ekGUI_TYPE_UPDOWN] = func_updown_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_slider_manager_imp(
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
    FPtr_gctx_set4_real32 func_slider_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_SLIDER] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_SLIDER] == NULL);
    cassert(context->func_slider_OnMoved == NULL);
    cassert(context->func_set_tooltip[ekGUI_TYPE_SLIDER] == NULL);
    cassert(context->func_slider_set_tickmarks == NULL);
    cassert(context->func_slider_get_position == NULL);
    cassert(context->func_slider_set_position == NULL);
    cassert(context->func_slider_bounds == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_SLIDER] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_SLIDER] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_SLIDER] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_SLIDER] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_SLIDER] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_SLIDER] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_SLIDER] == NULL);
    cassert_no_nullf(func_slider_create);
    cassert_no_nullf(func_slider_destroy);
    cassert_no_nullf(func_slider_OnMoved);
    cassert_no_nullf(func_slider_set_tooltip);
    cassert_no_nullf(func_slider_set_tickmarks);
    cassert_no_nullf(func_slider_get_position);
    cassert_no_nullf(func_slider_set_position);
    cassert_no_nullf(func_slider_bounds);
    cassert_no_nullf(func_attach_slider_to_panel);
    cassert_no_nullf(func_detach_slider_from_panel);
    cassert_no_nullf(func_slider_set_visible);
    cassert_no_nullf(func_slider_set_enabled);
    cassert_no_nullf(func_slider_get_size);
    cassert_no_nullf(func_slider_get_origin);
    cassert_no_nullf(func_slider_set_frame);
    context->func_create[ekGUI_TYPE_SLIDER] = func_slider_create;
    context->func_destroy[ekGUI_TYPE_SLIDER] = func_slider_destroy;
    context->func_slider_OnMoved = func_slider_OnMoved;
    context->func_set_tooltip[ekGUI_TYPE_SLIDER] = func_slider_set_tooltip;
    context->func_slider_set_tickmarks = func_slider_set_tickmarks;
    context->func_slider_get_position = func_slider_get_position;
    context->func_slider_set_position = func_slider_set_position;
    context->func_slider_bounds = func_slider_bounds;
    context->func_attach_to_panel[ekGUI_TYPE_SLIDER] = func_attach_slider_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_SLIDER] = func_detach_slider_from_panel;
    context->func_set_visible[ekGUI_TYPE_SLIDER] = func_slider_set_visible;
    context->func_set_enabled[ekGUI_TYPE_SLIDER] = func_slider_set_enabled;
    context->func_get_size[ekGUI_TYPE_SLIDER] = func_slider_get_size;
    context->func_get_origin[ekGUI_TYPE_SLIDER] = func_slider_get_origin;
    context->func_set_frame[ekGUI_TYPE_SLIDER] = func_slider_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_progress_manager_imp(
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
    FPtr_gctx_set4_real32 func_progress_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_PROGRESS] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_PROGRESS] == NULL);
    cassert(context->func_progress_set_position == NULL);
    cassert(context->func_progress_get_thickness == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_PROGRESS] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_PROGRESS] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_PROGRESS] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_PROGRESS] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_PROGRESS] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_PROGRESS] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_PROGRESS] == NULL);
    cassert_no_nullf(func_progress_create);
    cassert_no_nullf(func_progress_destroy);
    cassert_no_nullf(func_progress_set_position);
    cassert_no_nullf(func_progress_get_thickness);
    cassert_no_nullf(func_attach_progress_to_panel);
    cassert_no_nullf(func_detach_progress_from_panel);
    cassert_no_nullf(func_progress_set_visible);
    cassert_no_nullf(func_progress_set_enabled);
    cassert_no_nullf(func_progress_get_size);
    cassert_no_nullf(func_progress_get_origin);
    cassert_no_nullf(func_progress_set_frame);
    context->func_create[ekGUI_TYPE_PROGRESS] = func_progress_create;
    context->func_destroy[ekGUI_TYPE_PROGRESS] = func_progress_destroy;
    context->func_progress_set_position = func_progress_set_position;
    context->func_progress_get_thickness = func_progress_get_thickness;
    context->func_attach_to_panel[ekGUI_TYPE_PROGRESS] = func_attach_progress_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_PROGRESS] = func_detach_progress_from_panel;
    context->func_set_visible[ekGUI_TYPE_PROGRESS] = func_progress_set_visible;
    context->func_set_enabled[ekGUI_TYPE_PROGRESS] = func_progress_set_enabled;
    context->func_get_size[ekGUI_TYPE_PROGRESS] = func_progress_get_size;
    context->func_get_origin[ekGUI_TYPE_PROGRESS] = func_progress_get_origin;
    context->func_set_frame[ekGUI_TYPE_PROGRESS] = func_progress_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_text_manager_imp(
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
    FPtr_gctx_set4_real32 func_text_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_TEXTVIEW] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_TEXTVIEW] == NULL);
    cassert(context->func_text_OnFilter == NULL);
    cassert(context->func_text_OnFocus == NULL);
    cassert(context->func_text_insert_text == NULL);
    cassert(context->func_text_set_text == NULL);
    cassert(context->func_text_set_rtf == NULL);
    cassert(context->func_text_set_prop == NULL);
    cassert(context->func_text_set_editable == NULL);
    cassert(context->func_text_get_text == NULL);
    cassert(context->func_text_scroller_visible == NULL);
    cassert(context->func_text_set_need_display == NULL);
    cassert(context->func_text_clipboard == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_TEXTVIEW] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_TEXTVIEW] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_TEXTVIEW] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_TEXTVIEW] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_TEXTVIEW] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_TEXTVIEW] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_TEXTVIEW] == NULL);
    cassert_no_nullf(func_text_create);
    cassert_no_nullf(func_text_destroy);
    cassert_no_nullf(func_text_OnFilter);
    cassert_no_nullf(func_text_OnFocus);
    cassert_no_nullf(func_text_insert_text);
    cassert_no_nullf(func_text_set_text);
    cassert_no_nullf(func_text_set_rtf);
    cassert_no_nullf(func_text_set_prop);
    cassert_no_nullf(func_text_set_editable);
    cassert_no_nullf(func_text_get_text);
    cassert_no_nullf(func_text_scroller_visible);
    cassert_no_nullf(func_text_set_need_display);
    cassert_no_nullf(func_text_clipboard);
    cassert_no_nullf(func_attach_text_to_panel);
    cassert_no_nullf(func_detach_text_from_panel);
    cassert_no_nullf(func_text_set_visible);
    cassert_no_nullf(func_text_set_enabled);
    cassert_no_nullf(func_text_get_size);
    cassert_no_nullf(func_text_get_origin);
    cassert_no_nullf(func_text_set_frame);
    context->func_create[ekGUI_TYPE_TEXTVIEW] = func_text_create;
    context->func_destroy[ekGUI_TYPE_TEXTVIEW] = func_text_destroy;
    context->func_text_OnFilter = func_text_OnFilter;
    context->func_text_OnFocus = func_text_OnFocus;
    context->func_text_insert_text = func_text_insert_text;
    context->func_text_set_text = func_text_set_text;
    context->func_text_set_rtf = func_text_set_rtf;
    context->func_text_set_prop = func_text_set_prop;
    context->func_text_set_editable = func_text_set_editable;
    context->func_text_get_text = func_text_get_text;
    context->func_text_scroller_visible = func_text_scroller_visible;
    context->func_text_set_need_display = func_text_set_need_display;
    context->func_text_clipboard = func_text_clipboard;
    context->func_attach_to_panel[ekGUI_TYPE_TEXTVIEW] = func_attach_text_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_TEXTVIEW] = func_detach_text_from_panel;
    context->func_set_visible[ekGUI_TYPE_TEXTVIEW] = func_text_set_visible;
    context->func_set_enabled[ekGUI_TYPE_TEXTVIEW] = func_text_set_enabled;
    context->func_get_size[ekGUI_TYPE_TEXTVIEW] = func_text_get_size;
    context->func_get_origin[ekGUI_TYPE_TEXTVIEW] = func_text_get_origin;
    context->func_set_frame[ekGUI_TYPE_TEXTVIEW] = func_text_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_split_manager_imp(
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
    FPtr_gctx_set4_real32 func_split_set_frame)
{
    cassert_no_null(gui_context);
    cassert(gui_context->func_create[ekGUI_TYPE_SPLITVIEW] == NULL);
    cassert(gui_context->func_destroy[ekGUI_TYPE_SPLITVIEW] == NULL);
    cassert(gui_context->func_split_attach_control == NULL);
    cassert(gui_context->func_split_detach_control == NULL);
    cassert(gui_context->func_split_OnDrag == NULL);
    cassert(gui_context->func_split_track_area == NULL);
    cassert(gui_context->func_attach_to_panel[ekGUI_TYPE_SPLITVIEW] == NULL);
    cassert(gui_context->func_detach_from_panel[ekGUI_TYPE_SPLITVIEW] == NULL);
    cassert(gui_context->func_set_visible[ekGUI_TYPE_SPLITVIEW] == NULL);
    cassert(gui_context->func_set_enabled[ekGUI_TYPE_SPLITVIEW] == NULL);
    cassert(gui_context->func_get_size[ekGUI_TYPE_SPLITVIEW] == NULL);
    cassert(gui_context->func_get_origin[ekGUI_TYPE_SPLITVIEW] == NULL);
    cassert(gui_context->func_set_frame[ekGUI_TYPE_SPLITVIEW] == NULL);
    cassert_no_nullf(func_split_create);
    cassert_no_nullf(func_split_destroy);
    cassert_no_nullf(func_split_attach_control);
    cassert_no_nullf(func_split_attach_control);
    cassert_no_nullf(func_split_OnDrag);
    cassert_no_nullf(func_split_track_area);
    cassert_no_nullf(func_attach_split_to_panel);
    cassert_no_nullf(func_detach_split_from_panel);
    cassert_no_nullf(func_split_set_visible);
    cassert_no_nullf(func_split_set_enabled);
    cassert_no_nullf(func_split_get_size);
    cassert_no_nullf(func_split_get_origin);
    cassert_no_nullf(func_split_set_frame);
    gui_context->func_create[ekGUI_TYPE_SPLITVIEW] = func_split_create;
    gui_context->func_destroy[ekGUI_TYPE_SPLITVIEW] = func_split_destroy;
    gui_context->func_split_attach_control = func_split_attach_control;
    gui_context->func_split_detach_control = func_split_detach_control;
    gui_context->func_split_OnDrag = func_split_OnDrag;
    gui_context->func_split_track_area = func_split_track_area;
    gui_context->func_attach_to_panel[ekGUI_TYPE_SPLITVIEW] = func_attach_split_to_panel;
    gui_context->func_detach_from_panel[ekGUI_TYPE_SPLITVIEW] = func_detach_split_from_panel;
    gui_context->func_set_visible[ekGUI_TYPE_SPLITVIEW] = func_split_set_visible;
    gui_context->func_set_enabled[ekGUI_TYPE_SPLITVIEW] = func_split_set_enabled;
    gui_context->func_get_size[ekGUI_TYPE_SPLITVIEW] = func_split_get_size;
    gui_context->func_get_origin[ekGUI_TYPE_SPLITVIEW] = func_split_get_origin;
    gui_context->func_set_frame[ekGUI_TYPE_SPLITVIEW] = func_split_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_view_manager_imp(
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
    FPtr_gctx_set4_real32 func_view_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert(context->func_view_OnDraw == NULL);
    cassert(context->func_view_OnOverlay == NULL);
    cassert(context->func_view_OnEnter == NULL);
    cassert(context->func_view_OnExit == NULL);
    cassert(context->func_view_OnMoved == NULL);
    cassert(context->func_view_OnDown == NULL);
    cassert(context->func_view_OnUp == NULL);
    cassert(context->func_view_OnClick == NULL);
    cassert(context->func_view_OnDrag == NULL);
    cassert(context->func_view_OnWheel == NULL);
    cassert(context->func_view_OnKeyDown == NULL);
    cassert(context->func_view_OnKeyUp == NULL);
    cassert(context->func_view_OnFocus == NULL);
    cassert(context->func_view_OnResignFocus == NULL);
    cassert(context->func_view_OnAcceptFocus == NULL);
    cassert(context->func_view_OnScroll == NULL);
    cassert(context->func_view_OnTouchTap == NULL);
    cassert(context->func_view_OnTouchStartDrag == NULL);
    cassert(context->func_view_OnTouchDragging == NULL);
    cassert(context->func_view_OnTouchEndDrag == NULL);
    cassert(context->func_view_OnTouchStartPinch == NULL);
    cassert(context->func_view_OnTouchPinching == NULL);
    cassert(context->func_view_OnTouchEndPinch == NULL);
    cassert(context->func_view_scroll == NULL);
    cassert(context->func_view_scroll_get == NULL);
    cassert(context->func_view_scroller_size == NULL);
    cassert(context->func_view_scroller_visible == NULL);
    cassert(context->func_view_content_size == NULL);
    cassert(context->func_view_scale_factor == NULL);
    cassert(context->func_view_set_need_display == NULL);
    cassert(context->func_view_set_drawable == NULL);
    cassert(context->func_view_get_native_view == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_CUSTOMVIEW] == NULL);
    cassert_no_nullf(func_view_create);
    cassert_no_nullf(func_view_destroy);
    cassert_no_nullf(func_view_OnDraw);
    cassert_no_nullf(func_view_OnOverlay);
    cassert_no_nullf(func_view_OnEnter);
    cassert_no_nullf(func_view_OnExit);
    cassert_no_nullf(func_view_OnMoved);
    cassert_no_nullf(func_view_OnDown);
    cassert_no_nullf(func_view_OnUp);
    cassert_no_nullf(func_view_OnClick);
    cassert_no_nullf(func_view_OnDrag);
    cassert_no_nullf(func_view_OnWheel);
    cassert_no_nullf(func_view_OnKeyDown);
    cassert_no_nullf(func_view_OnKeyUp);
    cassert_no_nullf(func_view_OnScroll);
    cassert_no_nullf(func_view_OnFocus);
    cassert_no_nullf(func_view_OnResignFocus);
    cassert_no_nullf(func_view_OnAcceptFocus);
    cassert_no_nullf(func_view_scroll);
    cassert_no_nullf(func_view_scroll_get);
    cassert_no_nullf(func_view_scroller_size);
    cassert_no_nullf(func_view_scroller_visible);
    cassert_no_nullf(func_view_content_size);
    cassert_no_nullf(func_view_scale_factor);
    cassert_no_nullf(func_view_set_need_display);
    cassert_no_nullf(func_view_get_native_view);
    cassert_no_nullf(func_attach_view_to_panel);
    cassert_no_nullf(func_detach_view_from_panel);
    cassert_no_nullf(func_view_set_visible);
    cassert_no_nullf(func_view_set_enabled);
    cassert_no_nullf(func_view_get_size);
    cassert_no_nullf(func_view_get_origin);
    cassert_no_nullf(func_view_set_frame);
    context->func_create[ekGUI_TYPE_CUSTOMVIEW] = func_view_create;
    context->func_destroy[ekGUI_TYPE_CUSTOMVIEW] = func_view_destroy;
    context->func_view_OnDraw = func_view_OnDraw;
    context->func_view_OnOverlay = func_view_OnOverlay;
    context->func_view_OnEnter = func_view_OnEnter;
    context->func_view_OnExit = func_view_OnExit;
    context->func_view_OnMoved = func_view_OnMoved;
    context->func_view_OnDown = func_view_OnDown;
    context->func_view_OnUp = func_view_OnUp;
    context->func_view_OnClick = func_view_OnClick;
    context->func_view_OnDrag = func_view_OnDrag;
    context->func_view_OnWheel = func_view_OnWheel;
    context->func_view_OnKeyDown = func_view_OnKeyDown;
    context->func_view_OnKeyUp = func_view_OnKeyUp;
    context->func_view_OnFocus = func_view_OnFocus;
    context->func_view_OnResignFocus = func_view_OnResignFocus;
    context->func_view_OnAcceptFocus = func_view_OnAcceptFocus;
    context->func_view_OnScroll = func_view_OnScroll;
    context->func_view_OnTouchTap = func_view_OnTouchTap;
    context->func_view_OnTouchStartDrag = func_view_OnTouchStartDrag;
    context->func_view_OnTouchDragging = func_view_OnTouchDragging;
    context->func_view_OnTouchEndDrag = func_view_OnTouchEndDrag;
    context->func_view_OnTouchStartPinch = func_view_OnTouchStartPinch;
    context->func_view_OnTouchPinching = func_view_OnTouchPinching;
    context->func_view_OnTouchEndPinch = func_view_OnTouchEndPinch;
    context->func_view_scroll = func_view_scroll;
    context->func_view_scroll_get = func_view_scroll_get;
    context->func_view_scroller_size = func_view_scroller_size;
    context->func_view_scroller_visible = func_view_scroller_visible;
    context->func_view_content_size = func_view_content_size;
    context->func_view_scale_factor = func_view_scale_factor;
    context->func_view_set_need_display = func_view_set_need_display;
    context->func_view_set_drawable = func_view_set_drawable;
    context->func_view_get_native_view = func_view_get_native_view;
    context->func_attach_to_panel[ekGUI_TYPE_CUSTOMVIEW] = func_attach_view_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_CUSTOMVIEW] = func_detach_view_from_panel;
    context->func_set_visible[ekGUI_TYPE_CUSTOMVIEW] = func_view_set_visible;
    context->func_set_enabled[ekGUI_TYPE_CUSTOMVIEW] = func_view_set_enabled;
    context->func_get_size[ekGUI_TYPE_CUSTOMVIEW] = func_view_get_size;
    context->func_get_origin[ekGUI_TYPE_CUSTOMVIEW] = func_view_get_origin;
    context->func_set_frame[ekGUI_TYPE_CUSTOMVIEW] = func_view_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_panel_manager_imp(
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
    FPtr_gctx_set4_real32 func_panel_set_frame)
{
    cassert_no_null(context);
    cassert(context->func_create[ekGUI_TYPE_PANEL] == NULL);
    cassert(context->func_destroy[ekGUI_TYPE_PANEL] == NULL);
    cassert(context->func_panel_area == NULL);
    cassert(context->func_panel_scroller_size == NULL);
    cassert(context->func_panel_content_size == NULL);
    cassert(context->func_panel_set_need_display == NULL);
    cassert(context->func_attach_to_panel[ekGUI_TYPE_PANEL] == NULL);
    cassert(context->func_detach_from_panel[ekGUI_TYPE_PANEL] == NULL);
    cassert(context->func_set_visible[ekGUI_TYPE_PANEL] == NULL);
    cassert(context->func_set_enabled[ekGUI_TYPE_PANEL] == NULL);
    cassert(context->func_get_size[ekGUI_TYPE_PANEL] == NULL);
    cassert(context->func_get_origin[ekGUI_TYPE_PANEL] == NULL);
    cassert(context->func_set_frame[ekGUI_TYPE_PANEL] == NULL);
    cassert_no_nullf(func_panel_create);
    cassert_no_nullf(func_panel_destroy);
    cassert_no_nullf(func_panel_area);
    cassert_no_nullf(func_panel_scroller_size);
    cassert_no_nullf(func_panel_content_size);
    cassert_no_nullf(func_panel_set_need_display);
    cassert_no_nullf(func_attach_panel_to_panel);
    cassert_no_nullf(func_detach_panel_from_panel);
    cassert_no_nullf(func_panel_set_visible);
    cassert_no_nullf(func_panel_set_enabled);
    cassert_no_nullf(func_panel_get_size);
    cassert_no_nullf(func_panel_get_origin);
    cassert_no_nullf(func_panel_set_frame);
    context->func_create[ekGUI_TYPE_PANEL] = func_panel_create;
    context->func_destroy[ekGUI_TYPE_PANEL] = func_panel_destroy;
    context->func_panel_area = func_panel_area;
    context->func_panel_scroller_size = func_panel_scroller_size;
    context->func_panel_content_size = func_panel_content_size;
    context->func_panel_set_need_display = func_panel_set_need_display;
    context->func_attach_to_panel[ekGUI_TYPE_PANEL] = func_attach_panel_to_panel;
    context->func_detach_from_panel[ekGUI_TYPE_PANEL] = func_detach_panel_from_panel;
    context->func_set_visible[ekGUI_TYPE_PANEL] = func_panel_set_visible;
    context->func_set_enabled[ekGUI_TYPE_PANEL] = func_panel_set_enabled;
    context->func_get_size[ekGUI_TYPE_PANEL] = func_panel_get_size;
    context->func_get_origin[ekGUI_TYPE_PANEL] = func_panel_get_origin;
    context->func_set_frame[ekGUI_TYPE_PANEL] = func_panel_set_frame;
}

/*---------------------------------------------------------------------------*/

void guictx_append_menu_manager_imp(
    GuiCtx *context,
    FPtr_gctx_create func_menu_create,
    FPtr_gctx_destroy func_menu_destroy,
    FPtr_gctx_set_ptr func_attach_menuitem_to_menu,
    FPtr_gctx_set_ptr func_detach_menuitem_from_menu,
    FPtr_gctx_menu func_menu_launch_popup,
    FPtr_gctx_call func_menu_hide_popup)
{
    cassert_no_null(context);
    cassert(context->func_menu_create == NULL);
    cassert(context->func_menu_destroy == NULL);
    cassert(context->func_attach_menuitem_to_menu == NULL);
    cassert(context->func_detach_menuitem_from_menu == NULL);
    cassert(context->func_menu_launch_popup == NULL);
    cassert(context->func_menu_hide_popup == NULL);
    cassert_no_nullf(func_menu_create);
    cassert_no_nullf(func_menu_destroy);
    cassert_no_nullf(func_attach_menuitem_to_menu);
    cassert_no_nullf(func_detach_menuitem_from_menu);
    cassert_no_nullf(func_menu_launch_popup);
    cassert_no_nullf(func_menu_hide_popup);
    context->func_menu_create = func_menu_create;
    context->func_menu_destroy = func_menu_destroy;
    context->func_attach_menuitem_to_menu = func_attach_menuitem_to_menu;
    context->func_detach_menuitem_from_menu = func_detach_menuitem_from_menu;
    context->func_menu_launch_popup = func_menu_launch_popup;
    context->func_menu_hide_popup = func_menu_hide_popup;
}

/*---------------------------------------------------------------------------*/

void guictx_append_menuitem_manager_imp(
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
    FPtr_gctx_set_ptr func_detach_menu_from_menu_item)
{
    cassert_no_null(context);
    cassert(context->func_menuitem_create == NULL);
    cassert(context->func_menuitem_destroy == NULL);
    cassert(context->func_menuitem_OnClick == NULL);
    cassert(context->func_menuitem_set_enabled == NULL);
    cassert(context->func_menuitem_set_visible == NULL);
    cassert(context->func_menuitem_set_text == NULL);
    cassert(context->func_menuitem_set_image == NULL);
    cassert(context->func_menuitem_set_key_equivalent == NULL);
    cassert(context->func_menuitem_set_state == NULL);
    cassert(context->func_attach_menu_to_menu_item == NULL);
    cassert(context->func_detach_menu_from_menu_item == NULL);
    cassert_no_nullf(func_menuitem_create);
    cassert_no_nullf(func_menuitem_destroy);
    cassert_no_nullf(func_menuitem_OnClick);
    cassert_no_nullf(func_menuitem_set_enabled);
    cassert_no_nullf(func_menuitem_set_visible);
    cassert_no_nullf(func_menuitem_set_text);
    cassert_no_nullf(func_menuitem_set_image);
    cassert_no_nullf(func_menuitem_set_key_equivalent);
    cassert_no_nullf(func_menuitem_set_state);
    cassert_no_nullf(func_attach_menu_to_menu_item);
    cassert_no_nullf(func_detach_menu_from_menu_item);
    context->func_menuitem_create = func_menuitem_create;
    context->func_menuitem_destroy = func_menuitem_destroy;
    context->func_menuitem_OnClick = func_menuitem_OnClick;
    context->func_menuitem_set_enabled = func_menuitem_set_enabled;
    context->func_menuitem_set_visible = func_menuitem_set_visible;
    context->func_menuitem_set_text = func_menuitem_set_text;
    context->func_menuitem_set_image = func_menuitem_set_image;
    context->func_menuitem_set_key_equivalent = func_menuitem_set_key_equivalent;
    context->func_menuitem_set_state = func_menuitem_set_state;
    context->func_attach_menu_to_menu_item = func_attach_menu_to_menu_item;
    context->func_detach_menu_from_menu_item = func_detach_menu_from_menu_item;
}

/*---------------------------------------------------------------------------*/

void guictx_append_window_manager_imp(
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
    FPtr_gctx_set_property func_window_set_property)
{
    cassert_no_null(context);
    cassert(context->func_window_create == NULL);
    cassert(context->func_window_managed == NULL);
    cassert(context->func_window_destroy == NULL);
    cassert(context->func_window_OnMoved == NULL);
    cassert(context->func_window_OnResize == NULL);
    cassert(context->func_window_OnClose == NULL);
    cassert(context->func_window_set_title == NULL);
    cassert(context->func_window_set_edited == NULL);
    cassert(context->func_window_set_movable == NULL);
    cassert(context->func_window_set_z_order == NULL);
    cassert(context->func_window_set_alpha == NULL);
    cassert(context->func_window_enable_mouse_events == NULL);
    cassert(context->func_window_hotkey == NULL);
    cassert(context->func_window_set_taborder == NULL);
    cassert(context->func_window_tabcycle == NULL);
    cassert(context->func_window_tabstop == NULL);
    cassert(context->func_window_set_focus == NULL);
    cassert(context->func_window_get_focus == NULL);
    cassert(context->func_window_info_focus == NULL);
    cassert(context->func_attach_main_panel_to_window == NULL);
    cassert(context->func_detach_main_panel_from_window == NULL);
    cassert(context->func_attach_window_to_window == NULL);
    cassert(context->func_detach_window_from_window == NULL);
    cassert(context->func_window_launch == NULL);
    cassert(context->func_window_hide == NULL);
    cassert(context->func_window_launch_modal == NULL);
    cassert(context->func_window_stop_modal == NULL);
    cassert(context->func_window_get_origin_in_screen_coordinates == NULL);
    cassert(context->func_window_set_origin_in_screen_coordinates == NULL);
    cassert(context->func_window_get_size == NULL);
    cassert(context->func_window_set_size == NULL);
    cassert(context->func_window_set_default_pushbutton == NULL);
    cassert(context->func_window_set_cursor == NULL);
    cassert(context->func_window_set_property == NULL);
    cassert_no_nullf(func_window_create);
    cassert_no_nullf(func_window_managed);
    cassert_no_nullf(func_window_destroy);
    cassert_no_nullf(func_window_OnMoved);
    cassert_no_nullf(func_window_OnResize);
    cassert_no_nullf(func_window_OnClose);
    cassert_no_nullf(func_window_set_title);
    cassert_no_nullf(func_window_set_edited);
    cassert_no_nullf(func_window_set_movable);
    cassert_no_nullf(func_window_set_z_order);
    cassert_no_nullf(func_window_set_alpha);
    cassert_no_nullf(func_window_enable_mouse_events);
    cassert_no_nullf(func_window_hotkey);
    cassert_no_nullf(func_window_set_taborder);
    cassert_no_nullf(func_window_tabcycle);
    cassert_no_nullf(func_window_tabstop);
    cassert_no_nullf(func_window_set_focus);
    cassert_no_nullf(func_window_get_focus);
    cassert_no_nullf(func_window_info_focus);
    cassert_no_nullf(func_attach_main_panel_to_window);
    cassert_no_nullf(func_detach_main_panel_from_window);
    cassert_no_nullf(func_attach_window_to_window);
    cassert_no_nullf(func_detach_window_from_window);
    cassert_no_nullf(func_window_launch);
    cassert_no_nullf(func_window_hide);
    cassert_no_nullf(func_window_launch_modal);
    cassert_no_nullf(func_window_stop_modal);
    cassert_no_nullf(func_window_get_origin_in_screen_coordinates);
    cassert_no_nullf(func_window_set_origin_in_screen_coordinates);
    cassert_no_nullf(func_window_get_size);
    cassert_no_nullf(func_window_set_size);
    cassert_no_nullf(func_window_set_default_pushbutton);
    cassert_no_nullf(func_window_set_cursor);
    cassert_no_nullf(func_window_set_property);
    context->func_window_create = func_window_create;
    context->func_window_managed = func_window_managed;
    context->func_window_destroy = func_window_destroy;
    context->func_window_OnMoved = func_window_OnMoved;
    context->func_window_OnResize = func_window_OnResize;
    context->func_window_OnClose = func_window_OnClose;
    context->func_window_set_title = func_window_set_title;
    context->func_window_set_edited = func_window_set_edited;
    context->func_window_set_movable = func_window_set_movable;
    context->func_window_set_z_order = func_window_set_z_order;
    context->func_window_set_alpha = func_window_set_alpha;
    context->func_window_enable_mouse_events = func_window_enable_mouse_events;
    context->func_window_hotkey = func_window_hotkey;
    context->func_window_set_taborder = func_window_set_taborder;
    context->func_window_tabcycle = func_window_tabcycle;
    context->func_window_tabstop = func_window_tabstop;
    context->func_window_set_focus = func_window_set_focus;
    context->func_window_get_focus = func_window_get_focus;
    context->func_window_info_focus = func_window_info_focus;
    context->func_attach_main_panel_to_window = func_attach_main_panel_to_window;
    context->func_detach_main_panel_from_window = func_detach_main_panel_from_window;
    context->func_attach_window_to_window = func_attach_window_to_window;
    context->func_detach_window_from_window = func_detach_window_from_window;
    context->func_window_launch = func_window_launch;
    context->func_window_hide = func_window_hide;
    context->func_window_launch_modal = func_window_launch_modal;
    context->func_window_stop_modal = func_window_stop_modal;
    context->func_window_get_origin_in_screen_coordinates = func_window_get_origin_in_screen_coordinates;
    context->func_window_set_origin_in_screen_coordinates = func_window_set_origin_in_screen_coordinates;
    context->func_window_get_size = func_window_get_size;
    context->func_window_set_size = func_window_set_size;
    context->func_window_set_default_pushbutton = func_window_set_default_pushbutton;
    context->func_window_set_cursor = func_window_set_cursor;
    context->func_window_set_property = func_window_set_property;
}

/*---------------------------------------------------------------------------*/

void guictx_append_comwin_manager_imp(
    GuiCtx *context,
    FPtr_gctx_win_file func_comwin_file,
    FPtr_gctx_win_color func_comwin_color)
{
    cassert_no_null(context);
    cassert(context->func_comwin_file == NULL);
    cassert(context->func_comwin_color == NULL);
    cassert_no_nullf(func_comwin_file);
    cassert_no_nullf(func_comwin_color);
    context->func_comwin_file = func_comwin_file;
    context->func_comwin_color = func_comwin_color;
}

/*---------------------------------------------------------------------------*/

void guictx_append_globals_manager_imp(
    GuiCtx *context,
    FPtr_gctx_get_enum func_globals_device,
    FPtr_gctx_get_enum func_globals_color,
    FPtr_gctx_get2_real32 func_globals_resolution,
    FPtr_gctx_get2_real32 func_globals_mouse_position,
    FPtr_gctx_cursor func_globals_cursor,
    FPtr_gctx_destroy func_globals_cursor_destroy,
    FPtr_gctx_get_indexed func_globals_value,
    FPtr_gctx_set2_real64 func_globals_transitions,
    FPtr_gctx_set_listener func_globals_OnIdle)
{
    cassert_no_null(context);
    cassert(context->func_globals_device == NULL);
    cassert(context->func_globals_color == NULL);
    cassert(context->func_globals_resolution == NULL);
    cassert(context->func_globals_mouse_position == NULL);
    cassert(context->func_globals_cursor == NULL);
    cassert(context->func_globals_cursor_destroy == NULL);
    cassert(context->func_globals_value == NULL);
    cassert(context->func_globals_transitions == NULL);
    cassert(context->func_globals_OnIdle == NULL);
    cassert_no_nullf(func_globals_device);
    cassert_no_nullf(func_globals_color);
    cassert_no_nullf(func_globals_resolution);
    cassert_no_nullf(func_globals_mouse_position);
    cassert_no_nullf(func_globals_cursor);
    cassert_no_nullf(func_globals_cursor_destroy);
    cassert_no_nullf(func_globals_value);
    cassert_no_nullf(func_globals_transitions);
    cassert_no_nullf(func_globals_OnIdle);
    context->func_globals_device = func_globals_device;
    context->func_globals_color = func_globals_color;
    context->func_globals_resolution = func_globals_resolution;
    context->func_globals_mouse_position = func_globals_mouse_position;
    context->func_globals_cursor = func_globals_cursor;
    context->func_globals_cursor_destroy = func_globals_cursor_destroy;
    context->func_globals_value = func_globals_value;
    context->func_globals_transitions = func_globals_transitions;
    context->func_globals_OnIdle = func_globals_OnIdle;
}

/*---------------------------------------------------------------------------*/

void guictx_append_drawctrl_manager_imp(
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
    FPtr_gctx_draw_rect func_drawctrl_uncheckbox)
{
    cassert_no_null(context);
    cassert(context->func_drawctrl_font == NULL);
    cassert(context->func_drawctrl_row_padding == NULL);
    cassert(context->func_drawctrl_check_width == NULL);
    cassert(context->func_drawctrl_check_height == NULL);
    cassert(context->func_drawctrl_multisel == NULL);
    cassert(context->func_drawctrl_clear == NULL);
    cassert(context->func_drawctrl_header == NULL);
    cassert(context->func_drawctrl_indicator == NULL);
    cassert(context->func_drawctrl_fill == NULL);
    cassert(context->func_drawctrl_focus == NULL);
    cassert(context->func_drawctrl_line == NULL);
    cassert(context->func_drawctrl_text == NULL);
    cassert(context->func_drawctrl_image == NULL);
    cassert(context->func_drawctrl_checkbox == NULL);
    cassert(context->func_drawctrl_uncheckbox == NULL);
    cassert_no_nullf(func_drawctrl_font);
    cassert_no_nullf(func_drawctrl_row_padding);
    cassert_no_nullf(func_drawctrl_check_width);
    cassert_no_nullf(func_drawctrl_check_height);
    cassert_no_nullf(func_drawctrl_multisel);
    cassert_no_nullf(func_drawctrl_clear);
    cassert_no_nullf(func_drawctrl_header);
    cassert_no_nullf(func_drawctrl_indicator);
    cassert_no_nullf(func_drawctrl_fill);
    cassert_no_nullf(func_drawctrl_focus);
    cassert_no_nullf(func_drawctrl_line);
    cassert_no_nullf(func_drawctrl_text);
    cassert_no_nullf(func_drawctrl_image);
    cassert_no_nullf(func_drawctrl_checkbox);
    cassert_no_nullf(func_drawctrl_uncheckbox);
    context->func_drawctrl_font = func_drawctrl_font;
    context->func_drawctrl_row_padding = func_drawctrl_row_padding;
    context->func_drawctrl_check_width = func_drawctrl_check_width;
    context->func_drawctrl_check_height = func_drawctrl_check_height;
    context->func_drawctrl_multisel = func_drawctrl_multisel;
    context->func_drawctrl_clear = func_drawctrl_clear;
    context->func_drawctrl_header = func_drawctrl_header;
    context->func_drawctrl_indicator = func_drawctrl_indicator;
    context->func_drawctrl_fill = func_drawctrl_fill;
    context->func_drawctrl_focus = func_drawctrl_focus;
    context->func_drawctrl_line = func_drawctrl_line;
    context->func_drawctrl_text = func_drawctrl_text;
    context->func_drawctrl_image = func_drawctrl_image;
    context->func_drawctrl_checkbox = func_drawctrl_checkbox;
    context->func_drawctrl_uncheckbox = func_drawctrl_uncheckbox;
}