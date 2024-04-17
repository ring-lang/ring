/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: combo.c
 *
 */

/* Combo box */

#include "combo.h"
#include "combo.inl"
#include "component.inl"
#include "gui.inl"
#include <draw2d/font.h>
#include <draw2d/guictx.h>
#include <draw2d/image.h>
#include <geom2d/s2d.h>
#include <geom2d/v2d.h>
#include <core/arrpt.h>
#include <core/event.h>
#include <core/objh.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _combo_t
{
    GuiComponent component;
    S2Df size;
    bool_t duplicates;
    bool_t is_focused;
    bool_t is_placeholder_active;
    ResId ttipid;
    ResId placid;
    String *placeholder;
    String *text;
    ArrPt(String) *texts;
    ArrPt(Image) *images;
    Font *font;
    Font *placeholder_font;
    uint32_t color;
    uint32_t focus_color;
    uint32_t bg_color;
    uint32_t bg_focus_color;
    uint32_t placeholder_color;
    Listener *OnFilter;
    Listener *OnChange;
    Listener *OnSelect;
};

/*---------------------------------------------------------------------------*/

static void i_update_placeholder(Combo *combo);

/*---------------------------------------------------------------------------*/

void _combo_destroy(Combo **combo)
{
    cassert_no_null(combo);
    cassert_no_null(*combo);
    _component_destroy_imp(&(*combo)->component);
    listener_destroy(&(*combo)->OnFilter);
    listener_destroy(&(*combo)->OnChange);
    listener_destroy(&(*combo)->OnSelect);
    ptr_destopt(str_destroy, &(*combo)->placeholder, String);
    str_destroy(&(*combo)->text);
    arrpt_destroy(&(*combo)->texts, str_destroy, String);
    arrpt_destroy(&(*combo)->images, image_destroy, Image);
    font_destroy(&(*combo)->font);
    ptr_destopt(font_destroy, &(*combo)->placeholder_font, Font);
    obj_delete(combo, Combo);
}

/*---------------------------------------------------------------------------*/

static void i_OnFilter(Combo *combo, Event *event)
{
    cassert_no_null(combo);
    if (combo->OnFilter != NULL)
        listener_pass_event(combo->OnFilter, event, combo, Combo);
}

/*---------------------------------------------------------------------------*/

static void i_OnChange(Combo *combo, Event *event)
{
    const EvText *params = event_params(event, EvText);
    cassert_no_null(combo);
    cassert_no_null(params);
    cassert(event_type(event) == ekGUI_EVENT_TXTCHANGE);
    cassert(combo->component.ositem == event_sender_imp(event, NULL));
    str_upd(&combo->text, params->text);
    if (combo->OnChange != NULL)
        listener_pass_event(combo->OnChange, event, combo, Combo);
}

/*---------------------------------------------------------------------------*/

/*
static void i_OnSelect(Combo *combo, Event *event)
{
    const EvButton *params = event_params(event, EvButton);
    const String *str = NULL;
    cassert_no_null(combo);
    cassert_no_null(event);
    cassert_no_null(params);
    cassert(event_type(event) == ekGUI_EVENT_BUTTON_PUSH);
    cassert(event->sender1 == combo->component.ositem);
    cassert(params->text == NULL);
    str = arrptr_get_c(combo->texts, params->index, String);
    str_upd(&combo->text, tc(str));
    if (combo->OnSelect.object != NULL)
    {
        ((EvButton*)params)->text = tc(str);
        listener_pass_event(&combo->OnSelect, combo, event, Combo);
    }
}*/

/*---------------------------------------------------------------------------*/

static void i_OnFocus(Combo *combo, Event *event)
{
    const bool_t *params = event_params(event, bool_t);
    cassert_no_null(combo);
    cassert_no_null(params);
    if (*params == TRUE)
    {
        if (combo->focus_color != UINT32_MAX || combo->placeholder_color != UINT32_MAX)
            combo->component.context->func_combo_set_text_color(combo->component.ositem, combo->focus_color);
        if (combo->bg_focus_color != UINT32_MAX)
            combo->component.context->func_combo_set_bg_color(combo->component.ositem, combo->bg_focus_color);
    }
    else
    {
        if (combo->focus_color != UINT32_MAX)
            combo->component.context->func_combo_set_text_color(combo->component.ositem, combo->color);
        if (combo->bg_focus_color != UINT32_MAX)
            combo->component.context->func_combo_set_bg_color(combo->component.ositem, combo->bg_color);
    }

    combo->is_focused = *params;
    i_update_placeholder(combo);
}

/*---------------------------------------------------------------------------*/

Combo *combo_create(void)
{
    const GuiCtx *context = guictx_get_current();
    Combo *combo = obj_new0(Combo);
    void *ositem = NULL;
    combo->text = str_c("");
    combo->font = _gui_create_default_font();
    combo->texts = arrpt_create(String);
    combo->images = arrpt_create(Image);
    combo->color = UINT32_MAX;
    combo->focus_color = UINT32_MAX;
    combo->bg_color = UINT32_MAX;
    combo->bg_focus_color = UINT32_MAX;
    combo->placeholder_color = UINT32_MAX;
    ositem = context->func_create[ekGUI_TYPE_COMBOBOX](ekCOMBO_FLAG);
    context->func_combo_set_font(ositem, combo->font);
    _component_init(&combo->component, context, PARAM(type, ekGUI_TYPE_COMBOBOX), &ositem);
    context->func_combo_OnFilter(combo->component.ositem, obj_listener(combo, i_OnFilter, Combo));
    context->func_combo_OnChange(combo->component.ositem, obj_listener(combo, i_OnChange, Combo));
    /* context->func_combo_set_OnSelect(combo->component.ositem, obj_listener(combo, i_OnSelect, Combo)); */
    return combo;
}

/*---------------------------------------------------------------------------*/

void combo_OnFilter(Combo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnFilter, listener);
}

/*---------------------------------------------------------------------------*/

void combo_OnChange(Combo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnChange, listener);
}

/*---------------------------------------------------------------------------*/

/*
void combo_OnSelect(Combo *combo, Listener listener);
void combo_OnSelect(Combo *combo, Listener listener)
{
    cassert_no_null(combo);
    listener_destroy(&combo->OnSelect);
    combo->OnSelect = listener;
}*/

/*---------------------------------------------------------------------------*/

/*
static bool_t i_update_selection(GuiComponent *component, ArrPt(String) *texts, const char_t *edit_text)
{
    cassert_no_null(component);
    cassert_no_null(component->context);
    cassert_no_nullf(component->context->func_combo_set_selected);
    arrptr_foreach(text, texts, String)
        if (str_equ_sc(*text, edit_text) == TRUE)
        {
            component->context->func_combo_set_selected(component->ositem, text_i);
            return TRUE;
        }
    arrptr_end();
    return FALSE;
}*/

/*---------------------------------------------------------------------------*/

static void i_update_placeholder(Combo *combo)
{
    cassert_no_null(combo);
    if (combo->placeholder != NULL && combo->is_focused == FALSE && str_equ(combo->text, "") == TRUE)
    {
        if (_gui_effective_alt_font(combo->font, combo->placeholder_font) == TRUE)
            combo->component.context->func_combo_set_font(combo->component.ositem, combo->placeholder_font);
        if (combo->placeholder_color != UINT32_MAX)
            combo->component.context->func_combo_set_text_color(combo->component.ositem, combo->placeholder_color);
        combo->component.context->func_combo_set_text(combo->component.ositem, tc(combo->placeholder));
        combo->is_placeholder_active = TRUE;
    }
    else if (combo->is_placeholder_active == TRUE)
    {
        if (_gui_effective_alt_font(combo->font, combo->placeholder_font) == TRUE)
            combo->component.context->func_combo_set_font(combo->component.ositem, combo->font);

        if (combo->placeholder_color != UINT32_MAX)
        {
            if (combo->is_focused == TRUE && combo->focus_color != UINT32_MAX)
                combo->component.context->func_combo_set_text_color(combo->component.ositem, combo->focus_color);
            else
                combo->component.context->func_combo_set_text_color(combo->component.ositem, combo->color);
        }

        combo->component.context->func_combo_set_text(combo->component.ositem, tc(combo->text));
        combo->is_placeholder_active = FALSE;
    }
}

/*---------------------------------------------------------------------------*/

void combo_text(Combo *combo, const char_t *text)
{
    cassert_no_null(combo);
    str_upd(&combo->text, text);
    combo->component.context->func_combo_set_text(combo->component.ositem, text);
    /*if (i_update_selection(&combo->component, combo->texts, text) == FALSE)
    {
        combo->component.context->func_combo_set_selected(combo->component.ositem, UINT32_MAX);
    }*/

    i_update_placeholder(combo);
}

/*---------------------------------------------------------------------------*/

void combo_align(Combo *combo, const align_t align)
{
    unref(combo);
    unref(align);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void combo_duplicates(Combo *combo, const bool_t duplicates)
{
    cassert_no_null(combo);
    combo->duplicates = duplicates;
}

/*---------------------------------------------------------------------------*/

void combo_tooltip(Combo *combo, const char_t *text)
{
    const char_t *ltext = NULL;
    cassert_no_null(combo);
    if (text != NULL)
        ltext = _gui_respack_text(text, &combo->ttipid);
    combo->component.context->func_set_tooltip[ekGUI_TYPE_COMBOBOX](combo->component.ositem, ltext);
}

/*---------------------------------------------------------------------------*/

void combo_color(Combo *combo, const color_t color)
{
    cassert_no_null(combo);
    combo->color = color;
    combo->component.context->func_combo_set_text_color(combo->component.ositem, color);
}

/*---------------------------------------------------------------------------*/

static void i_update_focus_listener(Combo *combo)
{
    cassert_no_null(combo);
    if (combo->focus_color != UINT32_MAX || combo->bg_focus_color != UINT32_MAX || combo->placeholder != NULL)
    {
        combo->component.context->func_combo_OnFocus(combo->component.ositem, obj_listener(combo, i_OnFocus, Combo));
    }
    else
    {
        combo->component.context->func_combo_OnFocus(combo->component.ositem, NULL);
    }
}

/*---------------------------------------------------------------------------*/

void combo_color_focus(Combo *combo, const color_t color)
{
    cassert_no_null(combo);
    combo->focus_color = color;
    i_update_focus_listener(combo);
}

/*---------------------------------------------------------------------------*/

void combo_bgcolor(Combo *combo, const color_t color)
{
    cassert_no_null(combo);
    combo->bg_color = color;
    combo->component.context->func_combo_set_bg_color(combo->component.ositem, color);
}

/*---------------------------------------------------------------------------*/

void combo_bgcolor_focus(Combo *combo, const color_t color)
{
    cassert_no_null(combo);
    combo->bg_focus_color = color;
    i_update_focus_listener(combo);
    if (combo->is_focused)
        combo->component.context->func_combo_set_bg_color(combo->component.ositem, color);
}

/*---------------------------------------------------------------------------*/

void combo_phtext(Combo *combo, const char_t *text)
{
    const char_t *ltext = NULL;
    cassert_no_null(combo);
    if (text != NULL)
        ltext = _gui_respack_text(text, &combo->placid);
    str_upd(&combo->placeholder, ltext);
    i_update_focus_listener(combo);
    i_update_placeholder(combo);
}

/*---------------------------------------------------------------------------*/

void combo_phcolor(Combo *combo, const color_t color)
{
    cassert_no_null(combo);
    combo->placeholder_color = color;
    i_update_placeholder(combo);
}

/*---------------------------------------------------------------------------*/

void combo_phstyle(Combo *combo, const uint32_t fstyle)
{
    cassert_no_null(combo);
    ptr_destopt(font_destroy, &combo->placeholder_font, Font);
    if (fstyle != font_style(combo->font))
        combo->placeholder_font = font_with_style(combo->font, fstyle);
    i_update_placeholder(combo);
}

/*---------------------------------------------------------------------------*/

const char_t *combo_get_text(const Combo *combo, const uint32_t index)
{
    cassert_no_null(combo);
    if (index != UINT32_MAX)
    {
        const String *str = arrpt_get(combo->texts, index, String);
        return tc(str);
    }
    else
    {
        return tc(combo->text);
    }
}

/*---------------------------------------------------------------------------*/

static void i_delete_duplicates(GuiComponent *component, ArrPt(String) *texts, ArrPt(Image) *images, const char_t *text)
{
    register uint32_t i = 0, num_elems = 0;
    cassert_no_null(component);
    num_elems = arrpt_size(texts, String);
    cassert(num_elems == arrpt_size(images, Image));
    for (i = 0; i < num_elems;)
    {
        const String *str = arrpt_get(texts, i, String);
        if (str_str(text, tc(str)) != NULL)
        {
            arrpt_delete(texts, i, str_destroy, String);
            arrpt_delete(images, i, image_destroy, Image);
            component->context->func_combo_set_elem(component->ositem, ekCTRL_OP_DEL, i, NULL, NULL);
            num_elems--;
        }
        else
        {
            i++;
        }
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_exists_substring(ArrPt(String) *texts, const char_t *subtext)
{
    arrpt_foreach(text, texts, String)
        if (str_str(tc(text), subtext) != NULL)
            return TRUE;
    arrpt_end()
    return FALSE;
}

/*---------------------------------------------------------------------------*/

uint32_t combo_count(const Combo *combo)
{
    register uint32_t num_elems = 0;
    cassert_no_null(combo);
    num_elems = arrpt_size(combo->texts, String);
    cassert(num_elems == arrpt_size(combo->images, Image));
    return num_elems;
}

/*---------------------------------------------------------------------------*/

void combo_add_elem(Combo *combo, const char_t *text, const Image *image)
{
    bool_t exists = FALSE;
    cassert_no_null(combo);
    if (combo->duplicates == FALSE)
    {
        i_delete_duplicates(&combo->component, combo->texts, combo->images, text);
        exists = i_exists_substring(combo->texts, text);
    }

    if (exists == FALSE)
    {
        String *ltext = NULL;
        const Image *limage = NULL;
        Image *cimage;
        ltext = str_c(text);
        limage = _gui_respack_image((ResId)image, NULL);
        cimage = limage ? image_copy(limage) : NULL;
        arrpt_append(combo->texts, ltext, String);
        arrpt_append(combo->images, cimage, Image);
        combo->component.context->func_combo_set_elem(combo->component.ositem, ekCTRL_OP_ADD, UINT32_MAX, text, cimage);
        /* i_update_selection(&combo->component, combo->texts, tc(combo->text)); */
    }
}

/*---------------------------------------------------------------------------*/

void combo_set_elem(Combo *combo, const uint32_t index, const char_t *text, const Image *image)
{
    String **ltext = NULL;
    Image **limage = NULL;
    cassert_no_null(combo);
    cassert(index < arrpt_size(combo->texts, String));
    ltext = arrpt_all(combo->texts, String) + index;
    limage = arrpt_all(combo->images, Image) + index;
    str_destroy(ltext);
    ptr_destopt(image_destroy, limage, Image);
    *ltext = str_c(text);
    *limage = ptr_copyopt(image_copy, image, Image);
    combo->component.context->func_combo_set_elem(combo->component.ositem, ekCTRL_OP_SET, index, text, image);
    /* i_update_selection(&combo->component, combo->texts, tc(combo->text)); */
}

/*---------------------------------------------------------------------------*/

void combo_ins_elem(Combo *combo, const uint32_t index, const char_t *text, const Image *image)
{
    bool_t exists = FALSE;
    cassert_no_null(combo);
    cassert(index <= arrpt_size(combo->texts, String));

    if (combo->duplicates == FALSE)
    {
        i_delete_duplicates(&combo->component, combo->texts, combo->images, text);
        exists = i_exists_substring(combo->texts, text);
    }

    if (exists == FALSE)
    {
        String *ltext = NULL;
        Image *limage = NULL;
        ctrl_op_t op;
        uint32_t lindex;
        ltext = str_c(text);
        limage = ptr_copyopt(image_copy, image, Image);

        if (index < arrpt_size(combo->texts, String))
        {
            op = ekCTRL_OP_INS;
            lindex = index;
            arrpt_insert(combo->texts, index, ltext, String);
            arrpt_insert(combo->images, index, limage, Image);
        }
        else
        {
            op = ekCTRL_OP_ADD;
            lindex = UINT32_MAX;
            arrpt_append(combo->texts, ltext, String);
            arrpt_append(combo->images, limage, Image);
        }

        combo->component.context->func_combo_set_elem(combo->component.ositem, op, lindex, text, image);
        /* i_update_selection(&combo->component, combo->texts, tc(combo->text)); */
    }
}

/*---------------------------------------------------------------------------*/

void combo_del_elem(Combo *combo, const uint32_t index)
{
    cassert_no_null(combo);
    arrpt_delete(combo->texts, index, str_destroy, String);
    arrpt_delete(combo->images, index, image_destroy, Image);
    combo->component.context->func_combo_set_elem(combo->component.ositem, ekCTRL_OP_DEL, index, NULL, NULL);
    /* i_update_selection(&combo->component, combo->texts, tc(combo->text)); */
}

/*---------------------------------------------------------------------------*/

/*
void combo_set_font(Combo *combo, const Font *font);
void combo_set_font(Combo *combo, const Font *font)
{
    cassert_no_null(combo);
    cassert_no_null(combo->component.context);
    cassert_no_nullf(combo->component.context->func_combo_set_font);
    combo->component.context->func_combo_set_font(combo->component.ositem, font, _gui_font_family(font));
}*/

/*---------------------------------------------------------------------------*/

/*
uint32_t combo_get_selected(const Combo *combo);
uint32_t combo_get_selected(const Combo *combo)
{
    cassert_no_null(combo);
    cassert_no_null(combo->component.context);
    cassert_no_nullf(combo->component.context->func_combo_get_selected);
    return combo->component.context->func_combo_get_selected(combo->component.ositem);
}
*/

/*---------------------------------------------------------------------------*/

/*
void combo_set_selected(Combo *combo, const uint32_t index);
void combo_set_selected(Combo *combo, const uint32_t index)
{
    const String *str = NULL;
    cassert_no_null(combo);
    cassert_no_null(combo->component.context);
    cassert_no_nullf(combo->component.context->func_combo_set_selected);
    str = arrptr_get_c(combo->texts, index, String);
    str_upd(&combo->text, str);
    combo->component.context->func_combo_set_selected(combo->component.ositem, index);
}*/

/*---------------------------------------------------------------------------*/

void _combo_dimension(Combo *combo, const uint32_t i, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(combo);
    cassert_no_null(dim0);
    cassert_no_null(dim1);
    if (i == 0)
    {
        combo->component.context->func_combo_bounds(combo->component.ositem, 100.f, &combo->size.width, &combo->size.height);
        *dim0 = combo->size.width;
    }
    else
    {
        cassert(i == 1);
        *dim1 = combo->size.height;
    }
}

/*---------------------------------------------------------------------------*/

void _combo_locale(Combo *combo)
{
    cassert_no_null(combo);
    if (combo->placid != NULL)
    {
        const char_t *text = _gui_respack_text(combo->placid, NULL);
        str_upd(&combo->placeholder, text);
        i_update_placeholder(combo);
    }

    if (combo->ttipid != NULL)
    {
        const char_t *text = _gui_respack_text(combo->ttipid, NULL);
        combo->component.context->func_set_tooltip[ekGUI_TYPE_COMBOBOX](combo->component.ositem, text);
    }
}
