/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: button.c
 *
 */

/* Button */

#include "button.h"
#include "button.inl"
#include "component.inl"
#include "cell.inl"
#include "gui.inl"
#include "gbind.inl"
#include "panel.inl"
#include <draw2d/font.h>
#include <draw2d/guictx.h>
#include <draw2d/image.h>
#include <geom2d/s2d.h>
#include <geom2d/v2d.h>
#include <core/event.h>
#include <core/objh.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _button_t
{
    GuiComponent component;
    uint32_t flags;
    S2Df size;
    ResId textid;
    ResId taltid;
    ResId ttipid;
    String *text;
    String *talt;
    Image *image;
    Image *imalt;
    Listener *OnClick;
};

/*---------------------------------------------------------------------------*/

void _button_destroy(Button **button)
{
    cassert_no_null(button);
    cassert_no_null(*button);
    _component_destroy_imp(&(*button)->component);
    listener_destroy(&(*button)->OnClick);
    str_destroy(&(*button)->text);
    ptr_destopt(str_destroy, &(*button)->talt, String);
    ptr_destopt(image_destroy, &(*button)->image, Image);
    ptr_destopt(image_destroy, &(*button)->imalt, Image);
    obj_delete(button, Button);
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_update_button(Button *button, const gui_state_t state)
{
    cassert_no_null(button);
    if (button_get_type(button->flags) == ekBUTTON_FLATGLE)
    {
        if (button->talt != NULL)
        {
            if (state == ekGUI_ON)
            {
                button->component.context->func_set_tooltip[ekGUI_TYPE_BUTTON](button->component.ositem, tc(button->talt));
            }
            else
            {
                cassert(state == ekGUI_OFF);
                button->component.context->func_set_tooltip[ekGUI_TYPE_BUTTON](button->component.ositem, tc(button->text));
            }
        }

        if (button->imalt != NULL)
        {
            if (state == ekGUI_ON)
            {
                button->component.context->func_button_set_image(button->component.ositem, button->imalt);
            }
            else
            {
                cassert(state == ekGUI_OFF);
                button->component.context->func_button_set_image(button->component.ositem, button->image);
            }
        }
    }
    else if (button_get_type(button->flags) == ekBUTTON_RADIO)
    {
        Cell *cell = _component_cell(&button->component);
        if (cell != NULL)
            _cell_set_radio(cell);
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnClick(Button *button, Event *event)
{
    EvButton *params = NULL;
    Button *sender = button;

    cassert_no_null(button);
    cassert(button->component.ositem == event_sender_imp(event, NULL));
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_BUTTON);
    params = event_params(event, EvButton);
    cassert_no_null(params);
    cassert(params->index == 0);

    i_update_button(button, params->state);

    switch (button_get_type(button->flags))
    {
    case ekBUTTON_RADIO:
    {
        Cell *ccell = _component_cell(&button->component);
        if (ccell != NULL)
        {
            Cell *cell = _cell_radio_dbind_cell(ccell);
            params->index = _cell_radio_index(ccell);

            if (cell != NULL)
                _cell_upd_uint32(cell, params->index);

            if (button->OnClick == NULL)
                sender = _cell_radio_listener(ccell);
        }
        break;
    }

    case ekBUTTON_CHECK2:
    case ekBUTTON_FLATGLE:
    {
        Cell *cell = _component_cell(&button->component);
        if (cell != NULL)
            _cell_upd_bool(cell, params->state == ekGUI_OFF ? FALSE : TRUE);
        break;
    }

    case ekBUTTON_CHECK3:
    {
        Cell *cell = _component_cell(&button->component);
        if (cell != NULL)
        {
            uint32_t v = 0;
            switch (params->state)
            {
            case ekGUI_OFF:
                v = 0;
                break;
            case ekGUI_ON:
                v = 1;
                break;
            case ekGUI_MIXED:
                v = 2;
                break;
                cassert_default();
            }

            _cell_upd_uint32(cell, v);
        }
        break;
    }
    }

    if (sender && sender->OnClick)
    {
        cassert(params->text == NULL);
        if (button_get_type(button->flags) == ekBUTTON_FLATGLE && params->state == ekGUI_ON && button->talt != NULL)
            ((EvButton *)params)->text = tc(button->talt);
        else
            ((EvButton *)params)->text = tc(button->text);

        listener_pass_event(sender->OnClick, event, sender, Button);
    }
}

/*---------------------------------------------------------------------------*/

static Button *i_create(const uint32_t flags, const align_t halign)
{
    const GuiCtx *context = guictx_get_current();
    Button *button = obj_new0(Button);
    void *ositem = context->func_create[ekGUI_TYPE_BUTTON](flags);
    _component_init(&button->component, context, PARAM(type, ekGUI_TYPE_BUTTON), &ositem);
    button->flags = flags;
    button->text = str_c("");

    if (button_get_type(flags) != ekBUTTON_FLAT && button_get_type(flags) != ekBUTTON_FLATGLE)
        context->func_button_set_align(button->component.ositem, (enum_t)halign);

    context->func_button_OnClick(button->component.ositem, obj_listener(button, i_OnClick, Button));
    return button;
}

/*---------------------------------------------------------------------------*/

Button *button_push(void)
{
    return i_create(ekBUTTON_PUSH, ekCENTER);
}

/*---------------------------------------------------------------------------*/

Button *button_check(void)
{
    return i_create(ekBUTTON_CHECK2, ekLEFT);
}

/*---------------------------------------------------------------------------*/

Button *button_check3(void)
{
    return i_create(ekBUTTON_CHECK3, ekLEFT);
}

/*---------------------------------------------------------------------------*/

Button *button_radio(void)
{
    return i_create(ekBUTTON_RADIO, ekLEFT);
}

/*---------------------------------------------------------------------------*/

Button *button_flat(void)
{
    return i_create(ekBUTTON_FLAT, ekLEFT);
}

/*---------------------------------------------------------------------------*/

Button *button_flatgle(void)
{
    return i_create(ekBUTTON_FLATGLE, ekCENTER);
}

/*---------------------------------------------------------------------------*/

void button_OnClick(Button *button, Listener *listener)
{
    cassert_no_null(button);
    listener_update(&button->OnClick, listener);
}

/*---------------------------------------------------------------------------*/

static void i_update_text(Button *button)
{
    switch (button_get_type(button->flags))
    {
    case ekBUTTON_PUSH:
    case ekBUTTON_HEADER:
    case ekBUTTON_CHECK2:
    case ekBUTTON_CHECK3:
    case ekBUTTON_RADIO:
        button->component.context->func_button_set_text(button->component.ositem, tc(button->text));
        break;
    case ekBUTTON_FLAT:
    case ekBUTTON_FLATGLE:
        button->component.context->func_set_tooltip[ekGUI_TYPE_BUTTON](button->component.ositem, tc(button->text));
        break;
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void button_text(Button *button, const char_t *text)
{
    const char_t *ltext;
    cassert_no_null(button);
    ltext = _gui_respack_text(text, &button->textid);
    str_upd(&button->text, ltext);
    i_update_text(button);
}

/*---------------------------------------------------------------------------*/

void button_text_alt(Button *button, const char_t *text)
{
    const char_t *ltext;
    cassert_no_null(button);
    cassert(button_get_type(button->flags) == ekBUTTON_FLATGLE);
    ltext = _gui_respack_text(text, &button->taltid);
    str_upd(&button->talt, ltext);
}

/*---------------------------------------------------------------------------*/

void button_tooltip(Button *button, const char_t *text)
{
    const char_t *ltext = NULL;
    cassert_no_null(button);
    if (text != NULL)
        ltext = _gui_respack_text(text, &button->ttipid);
    button->component.context->func_set_tooltip[ekGUI_TYPE_BUTTON](button->component.ositem, ltext);
}

/*---------------------------------------------------------------------------*/

void button_font(Button *button, const Font *font)
{
    cassert_no_null(button);
    button->component.context->func_button_set_font(button->component.ositem, font);
}

/*---------------------------------------------------------------------------*/

void button_image(Button *button, const Image *image)
{
    const Image *limage = _gui_respack_image((ResId)image, NULL);
    cassert_no_null(button);
    cassert(button_get_type(button->flags) == ekBUTTON_PUSH || button_get_type(button->flags) == ekBUTTON_FLAT || button_get_type(button->flags) == ekBUTTON_FLATGLE);
    ptr_destopt(image_destroy, &button->image, Image);
    button->image = ptr_copyopt(image_copy, limage, Image);
    button->component.context->func_button_set_image(button->component.ositem, limage);
}

/*---------------------------------------------------------------------------*/

void button_image_alt(Button *button, const Image *image)
{
    const Image *limage = _gui_respack_image((ResId)image, NULL);
    cassert_no_null(button);
    cassert(button_get_type(button->flags) == ekBUTTON_FLATGLE);
    ptr_destopt(image_destroy, &button->imalt, Image);
    button->imalt = ptr_copyopt(image_copy, limage, Image);
}

/*---------------------------------------------------------------------------*/

void button_state(Button *button, const gui_state_t state)
{
    cassert_no_null(button);
    if (button_get_type(button->flags) != ekBUTTON_RADIO)
    {
        button->component.context->func_button_set_state(button->component.ositem, (enum_t)state);
    }
    else
    {
        if (state == ekGUI_ON)
        {
            Cell *cell = _component_cell(&button->component);
            button->component.context->func_button_set_state(button->component.ositem, (enum_t)state);
            if (cell != NULL)
                _cell_set_radio(cell);
        }
    }
}

/*---------------------------------------------------------------------------*/

void button_tag(Button *button, const uint32_t tag)
{
    cassert_no_null(button);
    _component_set_tag(&button->component, tag);
}

/*---------------------------------------------------------------------------*/

void button_vpadding(Button *button, const real32_t padding)
{
    cassert_no_null(button);
    cassert_no_nullf(button->component.context->func_button_set_vpadding);
    button->component.context->func_button_set_vpadding(button->component.ositem, padding);
}

/*---------------------------------------------------------------------------*/

gui_state_t button_get_state(const Button *button)
{
    cassert_no_null(button);
    return (gui_state_t)button->component.context->func_button_get_state(button->component.ositem);
}

/*---------------------------------------------------------------------------*/

uint32_t button_get_tag(const Button *button)
{
    cassert_no_null(button);
    return _component_get_tag(&button->component);
}

/*---------------------------------------------------------------------------*/

real32_t button_get_height(const Button *button)
{
    real32_t width, height;
    cassert_no_null(button);
    _button_dimension((Button *)button, 0, &width, &height);
    _button_dimension((Button *)button, 1, &width, &height);
    return height;
}

/*---------------------------------------------------------------------------*/

void _button_dimension(Button *button, const uint32_t i, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(button);
    cassert_no_null(dim0);
    cassert_no_null(dim1);
    if (i == 0)
    {
        if (button_get_type(button->flags) != ekBUTTON_FLAT && button_get_type(button->flags) != ekBUTTON_FLATGLE)
        {
            real32_t width = -1, height = -1;
            if (button->image != NULL)
            {
                width = (real32_t)image_width(button->image);
                height = (real32_t)image_height(button->image);
            }

            button->component.context->func_button_bounds(button->component.ositem, tc(button->text), width, height, &button->size.width, &button->size.height);
        }
        else
        {
            real32_t width = (real32_t)image_width(button->image);
            real32_t height = (real32_t)image_height(button->image);
            button->component.context->func_button_bounds(button->component.ositem, NULL, width, height, &button->size.width, &button->size.height);
        }

        *dim0 = button->size.width;
    }
    else
    {
        cassert(i == 1);
        *dim1 = button->size.height;
    }
}

/*---------------------------------------------------------------------------*/

void _button_locale(Button *button)
{
    cassert_no_null(button);
    if (button->textid != NULL)
    {
        const char_t *text = _gui_respack_text(button->textid, NULL);
        str_upd(&button->text, text);
    }

    if (button->taltid != NULL)
    {
        const char_t *text = _gui_respack_text(button->taltid, NULL);
        str_upd(&button->talt, text);
    }

    i_update_text(button);

    if (button->ttipid != NULL)
    {
        const char_t *text = _gui_respack_text(button->ttipid, NULL);
        button->component.context->func_set_tooltip[ekGUI_TYPE_BUTTON](button->component.ositem, text);
    }
}

/*---------------------------------------------------------------------------*/

uint32_t _button_flags(const Button *button)
{
    cassert_no_null(button);
    return button->flags;
}

/*---------------------------------------------------------------------------*/

bool_t _button_is_pushbutton(const Button *button)
{
    cassert_no_null(button);
    return (bool_t)(button_get_type(button->flags) == ekBUTTON_PUSH);
}

/*---------------------------------------------------------------------------*/

bool_t _button_is_radio(const Button *button)
{
    cassert_no_null(button);
    return (bool_t)(button_get_type(button->flags) == ekBUTTON_RADIO);
}

/*---------------------------------------------------------------------------*/

Listener *_button_radio_listener(const Button *button)
{
    cassert_no_null(button);
    if (button_get_type(button->flags) == ekBUTTON_RADIO)
        return button->OnClick;
    return NULL;
}

/*---------------------------------------------------------------------------*/

void _button_radio_state(Button *button, const gui_state_t state)
{
    cassert_no_null(button);
    cassert(button_get_type(button->flags) == ekBUTTON_RADIO);
    button->component.context->func_button_set_state(button->component.ositem, (enum_t)state);
}

/*---------------------------------------------------------------------------*/

void _button_bool(Button *button, const bool_t value)
{
    _button_uint32(button, (uint32_t)value);
}

/*---------------------------------------------------------------------------*/

void _button_uint32(Button *button, const uint32_t value)
{
    cassert_no_null(button);
    switch (button_get_type(button->flags))
    {
    case ekBUTTON_RADIO:
    {
        Cell *cell = _component_cell(&button->component);
        if (cell != NULL)
            _cell_set_radio_index(cell, value);
        break;
    }
    case ekBUTTON_FLATGLE:
    case ekBUTTON_CHECK2:
        button_state(button, value == 0 ? ekGUI_OFF : ekGUI_ON);
        break;

    case ekBUTTON_CHECK3:
    {
        gui_state_t st = ekGUI_MIXED;
        if (value == 0)
            st = ekGUI_OFF;
        else if (value == 1)
            st = ekGUI_ON;
        button_state(button, st);
        break;
    }

        cassert_default();
    }
}
