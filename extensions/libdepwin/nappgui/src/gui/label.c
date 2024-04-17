/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: label.c
 *
 */

/* Label control */

#include "label.h"
#include "label.inl"
#include "component.inl"
#include "gui.h"
#include "gui.inl"
#include "panel.inl"
#include <draw2d/color.h>
#include <draw2d/font.h>
#include <draw2d/guictx.h>
#include <geom2d/s2d.h>
#include <core/event.h>
#include <core/objh.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _label_t
{
    GuiComponent component;
    S2Df size;
    ResId textid;
    String *size_text;
    String *text;
    uint32_t flags;
    align_t halign;
    Font *font;
    Font *over_font;
    color_t color;
    color_t over_color;
    color_t bg_color;
    color_t bg_over_color;
    Listener *OnClick;
};

/*---------------------------------------------------------------------------*/

void _label_destroy(Label **label)
{
    cassert_no_null(label);
    cassert_no_null(*label);
    _component_destroy_imp(&(*label)->component);
    listener_destroy(&(*label)->OnClick);
    str_destroy(&(*label)->text);
    str_destopt(&(*label)->size_text);
    font_destroy(&(*label)->font);
    ptr_destopt(font_destroy, &(*label)->over_font, Font);
    obj_delete(label, Label);
}

/*---------------------------------------------------------------------------*/

static Label *i_create(const uint32_t flags, const align_t halign, const ellipsis_t ellipsis)
{
    const GuiCtx *context = guictx_get_current();
    Label *label = obj_new0(Label);
    void *ositem = NULL;
    label->font = _gui_create_default_font();
    label->text = str_c("");
    label->flags = flags;
    label->halign = halign;
    label->color = gui_label_color();
    label->over_color = gui_label_color();
    label->bg_color = kCOLOR_TRANSPARENT;
    label->bg_over_color = kCOLOR_TRANSPARENT;
    ositem = context->func_create[ekGUI_TYPE_LABEL](flags);
    context->func_label_set_font(ositem, label->font);
    context->func_label_set_align(ositem, (enum_t)halign);
    context->func_label_set_ellipsis(ositem, (enum_t)ellipsis);
    _component_init(&label->component, context, PARAM(type, ekGUI_TYPE_LABEL), &ositem);
    return label;
}

/*---------------------------------------------------------------------------*/

Label *label_create(void)
{
    return i_create(ekLABEL_SINGLE, PARAM(halign, ekLEFT), PARAM(ellipsis, ekELLIPEND));
}

/*---------------------------------------------------------------------------*/

Label *label_multiline(void)
{
    return i_create(ekLABEL_MULTI, PARAM(halign, ekLEFT), PARAM(ellipsis, ekELLIPMLINE));
}

/*---------------------------------------------------------------------------*/

static void i_OnClick(Label *label, Event *event)
{
    EvText *params = NULL;
    cassert_no_null(label);
    cassert_no_null(label->OnClick);
    params = (EvText *)event_params(event, EvText);
    cassert(params->text == NULL);
    params->text = tc(label->text);
    params->cpos = 0;
    params->len = 0;
    listener_pass_event(label->OnClick, event, label, Label);
}

/*---------------------------------------------------------------------------*/

static void i_OnMouseEnter(Label *label, Event *event)
{
    cassert_no_null(label);
    unref(event);
    if (label->over_color != kCOLOR_DEFAULT)
        label->component.context->func_label_set_text_color(label->component.ositem, label->over_color);
    if (label->bg_over_color != kCOLOR_TRANSPARENT)
        label->component.context->func_label_set_bg_color(label->component.ositem, label->bg_over_color);
    if (_gui_effective_alt_font(label->font, label->over_font) == TRUE)
        label->component.context->func_label_set_font(label->component.ositem, label->over_font);
}

/*---------------------------------------------------------------------------*/

static void i_OnMouseExit(Label *label, Event *event)
{
    cassert_no_null(label);
    unref(event);
    label->component.context->func_label_set_text_color(label->component.ositem, label->color);
    label->component.context->func_label_set_bg_color(label->component.ositem, label->bg_color);
    if (_gui_effective_alt_font(label->font, label->over_font) == TRUE)
        label->component.context->func_label_set_font(label->component.ositem, label->font);
}

/*---------------------------------------------------------------------------*/

void label_OnClick(Label *label, Listener *listener)
{
    cassert_no_null(label);
    listener_update(&label->OnClick, listener);
    if (label->OnClick != NULL)
        label->component.context->func_label_OnClick(label->component.ositem, obj_listener(label, i_OnClick, Label));
    else
        label->component.context->func_label_OnClick(label->component.ositem, NULL);
}

/*---------------------------------------------------------------------------*/

static bool_t i_is_mouse_sensible(Label *label)
{
    cassert_no_null(label);
    if (label->over_color != kCOLOR_DEFAULT)
        return TRUE;
    if (label->bg_over_color != kCOLOR_TRANSPARENT)
        return TRUE;
    return _gui_effective_alt_font(label->font, label->over_font);
}

/*---------------------------------------------------------------------------*/

static void i_update_mouse_listeners(Label *label)
{
    cassert_no_null(label);
    if (i_is_mouse_sensible(label) == TRUE)
    {
        label->component.context->func_label_OnMouseEnter(label->component.ositem, obj_listener(label, i_OnMouseEnter, Label));
        label->component.context->func_label_OnMouseExit(label->component.ositem, obj_listener(label, i_OnMouseExit, Label));
    }
    else
    {
        label->component.context->func_label_OnMouseEnter(label->component.ositem, NULL);
        label->component.context->func_label_OnMouseExit(label->component.ositem, NULL);
    }
}

/*---------------------------------------------------------------------------*/

void label_text(Label *label, const char_t *text)
{
    const char_t *ltext;
    cassert_no_null(label);
    ltext = _gui_respack_text(text, &label->textid);
    str_upd(&label->text, ltext);
    label->component.context->func_label_set_text(label->component.ositem, ltext);
}

/*---------------------------------------------------------------------------*/

void label_size_text(Label *label, const char_t *text)
{
    cassert_no_null(label);
    str_upd(&label->size_text, text);
}

/*---------------------------------------------------------------------------*/

void label_font(Label *label, const Font *font)
{
    cassert_no_null(label);
    if (_gui_update_font(&label->font, &label->over_font, font) == TRUE)
        label->component.context->func_label_set_font(label->component.ositem, label->font);
}

/*---------------------------------------------------------------------------*/

void label_style_over(Label *label, const uint32_t fstyle)
{
    cassert_no_null(label);
    ptr_destopt(font_destroy, &label->over_font, Font);
    if (fstyle != font_style(label->font))
        label->over_font = font_with_style(label->font, fstyle);
    i_update_mouse_listeners(label);
}

/*---------------------------------------------------------------------------*/

void label_align(Label *label, const align_t align)
{
    cassert_no_null(label);
    label->component.context->func_label_set_align(label->component.ositem, (enum_t)align);
}

/*---------------------------------------------------------------------------*/

void label_color(Label *label, const color_t color)
{
    cassert_no_null(label);
    label->color = color;
    label->component.context->func_label_set_text_color(label->component.ositem, color);
}

/*---------------------------------------------------------------------------*/

void label_color_over(Label *label, const color_t color)
{
    cassert_no_null(label);
    label->over_color = color;
    i_update_mouse_listeners(label);
}

/*---------------------------------------------------------------------------*/

void label_bgcolor(Label *label, const color_t color)
{
    cassert_no_null(label);
    label->bg_color = color;
    label->component.context->func_label_set_bg_color(label->component.ositem, color);
}

/*---------------------------------------------------------------------------*/

void label_bgcolor_over(Label *label, const color_t color)
{
    cassert_no_null(label);
    label->bg_over_color = color;
    i_update_mouse_listeners(label);
}

/*---------------------------------------------------------------------------*/

void _label_dimension(Label *label, const uint32_t i, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(label);
    cassert_no_null(dim0);
    cassert_no_null(dim1);
    if (i == 0)
    {
        const char_t *size_text = str_empty(label->size_text) ? tc(label->text) : tc(label->size_text);
        label->component.context->func_label_bounds(label->component.ositem, size_text, -1.f, &label->size.width, &label->size.height);
        *dim0 = label->size.width;
    }
    else
    {
        cassert(i == 1);
        switch (label_get_type(label->flags))
        {
        case ekLABEL_SINGLE:
            *dim1 = label->size.height;
            break;
        case ekLABEL_MULTI:
        {
            real32_t width = 0.f;
            const char_t *size_text = str_empty(label->size_text) ? tc(label->text) : tc(label->size_text);
            label->component.context->func_label_bounds(label->component.ositem, size_text, *dim0, &width, dim1);
            break;
        }
            cassert_default();
        }
    }
}

/*---------------------------------------------------------------------------*/

void _label_locale(Label *label)
{
    cassert_no_null(label);
    if (label->textid != NULL)
    {
        const char_t *text = _gui_respack_text(label->textid, NULL);
        str_upd(&label->text, text);
        label->component.context->func_label_set_text(label->component.ositem, text);
    }
}

/*---------------------------------------------------------------------------*/

void _label_text(Label *label, const char_t *text)
{
    cassert_no_null(label);
    label->component.context->func_label_set_text(label->component.ositem, text);
}

/*---------------------------------------------------------------------------*/

bool_t _label_is_multiline(const Label *label)
{
    cassert_no_null(label);
    return (bool_t)(label_get_type(label->flags) == ekLABEL_MULTI);
}
