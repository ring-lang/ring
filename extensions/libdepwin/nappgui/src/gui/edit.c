/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: edit.c
 *
 */

/* Edit Box */

#include "edit.h"
#include "edit.inl"
#include "cell.inl"
#include "component.inl"
#include "gui.inl"
#include "panel.inl"
#include "window.inl"
#include <geom2d/s2d.h>
#include <draw2d/color.h>
#include <draw2d/font.h>
#include <draw2d/guictx.h>
#include <core/event.h>
#include <core/objh.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

struct _edit_t
{
    GuiComponent component;
    uint32_t flags;
    S2Df size;
    bool_t is_focused;
    bool_t is_placeholder_active;
    ResId ttipid;
    ResId placid;
    String *placeholder;
    String *text;
    Font *font;
    Font *placeholder_font;
    color_t color;
    color_t focus_color;
    color_t bg_color;
    color_t bg_focus_color;
    color_t placeholder_color;
    Listener *OnFilter;
    Listener *OnChange;
    Listener *OnFocus;
};

/*---------------------------------------------------------------------------*/

void _edit_destroy(Edit **edit)
{
    cassert_no_null(edit);
    cassert_no_null(*edit);
    _component_destroy_imp(&(*edit)->component);
    listener_destroy(&(*edit)->OnFilter);
    listener_destroy(&(*edit)->OnChange);
    listener_destroy(&(*edit)->OnFocus);
    ptr_destopt(str_destroy, &(*edit)->placeholder, String);
    str_destroy(&(*edit)->text);
    font_destroy(&(*edit)->font);
    ptr_destopt(font_destroy, &(*edit)->placeholder_font, Font);
    obj_delete(edit, Edit);
}

/*---------------------------------------------------------------------------*/

static int32_t i_text_diff(const char_t *ctext, const char_t *ntext)
{
    int32_t n1 = (int32_t)unicode_nchars(ctext, ekUTF8);
    int32_t n2 = (int32_t)unicode_nchars(ntext, ekUTF8);
    return n2 - n1;
}

/*---------------------------------------------------------------------------*/

static void i_OnFilter(Edit *edit, Event *e)
{
    EvTextFilter *res = event_result(e, EvTextFilter);
    const EvText *p = event_params(e, EvText);
    Cell *cell = NULL;

    cassert_no_null(edit);
    cell = _component_cell(&edit->component);
    res->apply = FALSE;

    /* Native edit doesn't known exactly the inserted or deleted text size */
    if (p->len == INT32_MAX)
        ((EvText *)p)->len = i_text_diff(tc(edit->text), p->text);

    if (cell != NULL)
        res->apply = _cell_filter_str(cell, p->text, res->text, sizeof(res->text));

    if (res->apply == FALSE)
    {
        if (cell != NULL)
            _cell_upd_string(cell, p->text);

        if (edit->OnFilter != NULL)
            listener_pass_event(edit->OnFilter, e, edit, Edit);
    }

    if (res->apply == TRUE)
        str_upd(&edit->text, res->text);
    else
        str_upd(&edit->text, p->text);
}

/*---------------------------------------------------------------------------*/

static void i_OnChange(Edit *edit, Event *e)
{
    const EvText *p = event_params(e, EvText);
    Cell *cell = NULL;
    cassert_no_null(edit);
    cassert_no_null(p);
    cassert(event_type(e) == ekGUI_EVENT_TXTCHANGE);
    cassert(event_sender_imp(e, NULL) == edit->component.ositem);
    cell = _component_cell(&edit->component);
    str_upd(&edit->text, p->text);

    if (cell != NULL)
        _cell_upd_string(cell, p->text);

    if (edit->OnChange != NULL)
        listener_pass_event(edit->OnChange, e, edit, Edit);
}

/*---------------------------------------------------------------------------*/

static void i_update_placeholder(Edit *edit)
{
    cassert_no_null(edit);
    if (edit->placeholder != NULL && edit->is_focused == FALSE && str_equ(edit->text, "") == TRUE)
    {
        if (_gui_effective_alt_font(edit->font, edit->placeholder_font) == TRUE)
            edit->component.context->func_edit_set_font(edit->component.ositem, edit->placeholder_font);
        if (edit->placeholder_color != kCOLOR_DEFAULT)
            edit->component.context->func_edit_set_text_color(edit->component.ositem, edit->placeholder_color);
        edit->component.context->func_edit_set_text(edit->component.ositem, tc(edit->placeholder));
        edit->is_placeholder_active = TRUE;
    }
    else if (edit->is_placeholder_active == TRUE)
    {
        if (_gui_effective_alt_font(edit->font, edit->placeholder_font) == TRUE)
            edit->component.context->func_edit_set_font(edit->component.ositem, edit->font);

        if (edit->placeholder_color != kCOLOR_DEFAULT)
        {
            if (edit->is_focused == TRUE && edit->focus_color != kCOLOR_DEFAULT)
                edit->component.context->func_edit_set_text_color(edit->component.ositem, edit->focus_color);
            else
                edit->component.context->func_edit_set_text_color(edit->component.ositem, edit->color);
        }

        edit->component.context->func_edit_set_text(edit->component.ositem, tc(edit->text));
        edit->is_placeholder_active = FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnFocus(Edit *edit, Event *e)
{
    const bool_t *p = event_params(e, bool_t);
    cassert_no_null(edit);
    cassert_no_null(p);
    if (*p == TRUE)
    {
        Cell *cell = _component_cell(&edit->component);
        char_t filter[128];

        if (edit->focus_color != kCOLOR_DEFAULT)
            edit->component.context->func_edit_set_text_color(edit->component.ositem, edit->focus_color);

        if (edit->bg_focus_color != kCOLOR_DEFAULT)
            edit->component.context->func_edit_set_bg_color(edit->component.ositem, edit->bg_focus_color);

        if (cell != NULL)
        {
            if (_cell_filter_str(cell, tc(edit->text), filter, sizeof(filter)) == TRUE)
                edit->component.context->func_edit_set_text(edit->component.ositem, filter);
        }
    }
    else
    {
        if (edit->focus_color != kCOLOR_DEFAULT)
            edit->component.context->func_edit_set_text_color(edit->component.ositem, edit->color);

        if (edit->bg_focus_color != kCOLOR_DEFAULT)
            edit->component.context->func_edit_set_bg_color(edit->component.ositem, edit->bg_color);
    }

    edit->is_focused = *p;
    i_update_placeholder(edit);

    if (*p == TRUE && BIT_TEST(edit->flags, ekEDIT_AUTOSEL) == TRUE)
        edit_select(edit, 0, -1);

    if (edit->OnFocus != NULL)
        listener_pass_event(edit->OnFocus, e, edit, Edit);
}

/*---------------------------------------------------------------------------*/

static Edit *i_create(const align_t halign, const uint32_t flags)
{
    const GuiCtx *context = guictx_get_current();
    Edit *edit = obj_new0(Edit);
    void *ositem = NULL;
    edit->flags = flags;
    edit->text = str_c("");
    edit->font = _gui_create_default_font();
    edit->color = kCOLOR_DEFAULT;
    edit->focus_color = kCOLOR_DEFAULT;
    edit->bg_color = kCOLOR_DEFAULT;
    edit->bg_focus_color = kCOLOR_DEFAULT;
    edit->placeholder_color = kCOLOR_DEFAULT;
    ositem = context->func_create[ekGUI_TYPE_EDITBOX](flags);
    context->func_edit_set_font(ositem, edit->font);
    context->func_edit_set_align(ositem, (enum_t)halign);
    _component_init(&edit->component, context, PARAM(type, ekGUI_TYPE_EDITBOX), &ositem);
    context->func_edit_OnFilter(edit->component.ositem, obj_listener(edit, i_OnFilter, Edit));
    context->func_edit_OnChange(edit->component.ositem, obj_listener(edit, i_OnChange, Edit));
    context->func_edit_OnFocus(edit->component.ositem, obj_listener(edit, i_OnFocus, Edit));
    return edit;
}

/*---------------------------------------------------------------------------*/

Edit *edit_create(void)
{
    return i_create(ekLEFT, ekEDIT_SINGLE);
}

/*---------------------------------------------------------------------------*/

Edit *edit_multiline(void)
{
    return i_create(ekLEFT, ekEDIT_MULTI);
}

/*---------------------------------------------------------------------------*/

void edit_OnFilter(Edit *edit, Listener *listener)
{
    cassert_no_null(edit);
    listener_update(&edit->OnFilter, listener);
}

/*---------------------------------------------------------------------------*/

void edit_OnChange(Edit *edit, Listener *listener)
{
    cassert_no_null(edit);
    listener_update(&edit->OnChange, listener);
}

/*---------------------------------------------------------------------------*/

void edit_OnFocus(Edit *edit, Listener *listener)
{
    cassert_no_null(edit);
    listener_update(&edit->OnFocus, listener);
}

/*---------------------------------------------------------------------------*/

void edit_text(Edit *edit, const char_t *text)
{
    cassert_no_null(edit);
    str_upd(&edit->text, text);
    edit->component.context->func_edit_set_text(edit->component.ositem, text);
    i_update_placeholder(edit);
}

/*---------------------------------------------------------------------------*/

void edit_font(Edit *edit, const Font *font)
{
    cassert_no_null(edit);
    if (_gui_update_font(&edit->font, &edit->placeholder_font, font) == TRUE)
    {
        edit->component.context->func_edit_set_font(edit->component.ositem, edit->font);
        i_update_placeholder(edit);
    }
}

/*---------------------------------------------------------------------------*/

void edit_align(Edit *edit, const align_t align)
{
    cassert_no_null(edit);
    edit->component.context->func_edit_set_align(edit->component.ositem, (enum_t)align);
}

/*---------------------------------------------------------------------------*/

void edit_passmode(Edit *edit, const bool_t passmode)
{
    cassert_no_null(edit);
    edit->component.context->func_edit_set_passmode(edit->component.ositem, passmode);
}

/*---------------------------------------------------------------------------*/

void edit_editable(Edit *edit, const bool_t is_editable)
{
    cassert_no_null(edit);
    edit->component.context->func_edit_set_editable(edit->component.ositem, is_editable);
}

/*---------------------------------------------------------------------------*/

void edit_autoselect(Edit *edit, const bool_t autoselect)
{
    cassert_no_null(edit);
    edit->component.context->func_edit_set_autoselect(edit->component.ositem, autoselect);
}

/*---------------------------------------------------------------------------*/

void edit_select(Edit *edit, const int32_t start, const int32_t end)
{
    cassert_no_null(edit);
    edit->component.context->func_edit_set_select(edit->component.ositem, start, end);
}

/*---------------------------------------------------------------------------*/

void edit_tooltip(Edit *edit, const char_t *text)
{
    const char_t *ltext = NULL;
    cassert_no_null(edit);
    if (text != NULL)
        ltext = _gui_respack_text(text, &edit->ttipid);
    edit->component.context->func_set_tooltip[ekGUI_TYPE_EDITBOX](edit->component.ositem, ltext);
}

/*---------------------------------------------------------------------------*/

void edit_color(Edit *edit, const color_t color)
{
    cassert_no_null(edit);
    edit->color = color;
    edit->component.context->func_edit_set_text_color(edit->component.ositem, color);
    i_update_placeholder(edit);
}

/*---------------------------------------------------------------------------*/

void edit_color_focus(Edit *edit, const color_t color)
{
    cassert_no_null(edit);
    edit->focus_color = color;
}

/*---------------------------------------------------------------------------*/

void edit_bgcolor(Edit *edit, const color_t color)
{
    cassert_no_null(edit);
    edit->bg_color = color;
    edit->component.context->func_edit_set_bg_color(edit->component.ositem, color);
}

/*---------------------------------------------------------------------------*/

void edit_bgcolor_focus(Edit *edit, const color_t color)
{
    cassert_no_null(edit);
    edit->bg_focus_color = color;
    if (edit->is_focused)
        edit->component.context->func_edit_set_bg_color(edit->component.ositem, color);
}

/*---------------------------------------------------------------------------*/

void edit_phtext(Edit *edit, const char_t *text)
{
    const char_t *ltext = NULL;
    cassert_no_null(edit);
    if (text != NULL)
        ltext = _gui_respack_text(text, &edit->placid);
    str_upd(&edit->placeholder, ltext);
    i_update_placeholder(edit);
}

/*---------------------------------------------------------------------------*/

void edit_phcolor(Edit *edit, const color_t color)
{
    cassert_no_null(edit);
    edit->placeholder_color = color;
    i_update_placeholder(edit);
}

/*---------------------------------------------------------------------------*/

void edit_phstyle(Edit *edit, const uint32_t fstyle)
{
    cassert_no_null(edit);
    ptr_destopt(font_destroy, &edit->placeholder_font, Font);
    if (fstyle != font_style(edit->font))
        edit->placeholder_font = font_with_style(edit->font, fstyle);
    i_update_placeholder(edit);
}

/*---------------------------------------------------------------------------*/

void edit_vpadding(Edit *edit, const real32_t padding)
{
    cassert_no_null(edit);
    cassert_no_nullf(edit->component.context->func_edit_set_vpadding);
    edit->component.context->func_edit_set_vpadding(edit->component.ositem, padding);
}

/*---------------------------------------------------------------------------*/

const char_t *edit_get_text(const Edit *edit)
{
    cassert_no_null(edit);
    return tc(edit->text);
}

/*---------------------------------------------------------------------------*/

real32_t edit_get_height(const Edit *edit)
{
    real32_t width, height;
    cassert_no_null(edit);
    _edit_dimension((Edit *)edit, 0, &width, &height);
    _edit_dimension((Edit *)edit, 1, &width, &height);
    return height;
}

/*---------------------------------------------------------------------------*/

void edit_copy(const Edit *edit)
{
    cassert_no_null(edit);
    cassert_no_nullf(edit->component.context->func_edit_clipboard);
    edit->component.context->func_edit_clipboard(edit->component.ositem, ekCLIPBOARD_COPY);
}

/*---------------------------------------------------------------------------*/

void edit_cut(Edit *edit)
{
    cassert_no_null(edit);
    cassert_no_nullf(edit->component.context->func_edit_clipboard);
    edit->component.context->func_edit_clipboard(edit->component.ositem, ekCLIPBOARD_CUT);
}

/*---------------------------------------------------------------------------*/

void edit_paste(Edit *edit)
{
    cassert_no_null(edit);
    cassert_no_nullf(edit->component.context->func_edit_clipboard);
    edit->component.context->func_edit_clipboard(edit->component.ositem, ekCLIPBOARD_PASTE);
}

/*---------------------------------------------------------------------------*/

void _edit_dimension(Edit *edit, const uint32_t i, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(edit);
    cassert_no_null(dim0);
    cassert_no_null(dim1);
    if (i == 0)
    {
        edit->component.context->func_edit_bounds(edit->component.ositem, 100.f, 1, &edit->size.width, &edit->size.height);
        *dim0 = edit->size.width;
    }
    else
    {
        cassert(i == 1);
        *dim1 = edit->size.height;
    }
}

/*---------------------------------------------------------------------------*/

void _edit_locale(Edit *edit)
{
    cassert_no_null(edit);
    if (edit->placid != NULL)
    {
        const char_t *text = _gui_respack_text(edit->placid, NULL);
        str_upd(&edit->placeholder, text);
        i_update_placeholder(edit);
    }

    if (edit->ttipid != NULL)
    {
        const char_t *text = _gui_respack_text(edit->ttipid, NULL);
        edit->component.context->func_set_tooltip[ekGUI_TYPE_EDITBOX](edit->component.ositem, text);
    }
}

/*---------------------------------------------------------------------------*/

bool_t _edit_is_multiline(const Edit *edit)
{
    cassert_no_null(edit);
    if (edit_get_type(edit->flags) == ekEDIT_MULTI)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

void _edit_text(Edit *edit, const char_t *text)
{
    edit_text(edit, text);
}
