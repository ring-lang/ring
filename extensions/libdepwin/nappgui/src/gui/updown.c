/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: updown.c
 *
 */

/* Up Down */

#include "updown.h"
#include "updown.inl"
#include "cell.inl"
#include "component.inl"
#include "gui.inl"
#include <draw2d/guictx.h>
#include <core/event.h>
#include <core/objh.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _updown_t
{
    GuiComponent component;
    S2Df size;
    ResId ttipid;
    Listener *OnClick;
};

/*---------------------------------------------------------------------------*/

static void i_OnClick(UpDown *updown, Event *e)
{
    const EvButton *params = event_params(e, EvButton);
    cassert_no_null(updown);

    {
        Cell *cell = _component_cell(&updown->component);
        if (cell != NULL)
            _cell_upd_increment(cell, params->index == 0 ? TRUE : FALSE);
    }

    if (updown->OnClick != NULL)
        listener_pass_event(updown->OnClick, e, updown, UpDown);
}

/*---------------------------------------------------------------------------*/

UpDown *updown_create(void)
{
    const GuiCtx *context = guictx_get_current();
    void *ositem = context->func_create[ekGUI_TYPE_UPDOWN](ekUPDOWN_FLAG);
    UpDown *updown = obj_new0(UpDown);
    _component_init(&updown->component, context, PARAM(type, ekGUI_TYPE_UPDOWN), &ositem);
    _component_get_size(&updown->component, &updown->size);
    context->func_updown_OnClick(updown->component.ositem, obj_listener(updown, i_OnClick, UpDown));
    return updown;
}

/*---------------------------------------------------------------------------*/

void _updown_destroy(UpDown **updown)
{
    cassert_no_null(updown);
    cassert_no_null(*updown);
    _component_destroy_imp(&(*updown)->component);
    listener_destroy(&(*updown)->OnClick);
    obj_delete(updown, UpDown);
}

/*---------------------------------------------------------------------------*/

void updown_OnClick(UpDown *updown, Listener *listener)
{
    cassert_no_null(updown);
    listener_update(&updown->OnClick, listener);
}

/*---------------------------------------------------------------------------*/

void updown_tooltip(UpDown *updown, const char_t *text)
{
    const char_t *ltext = NULL;
    cassert_no_null(updown);
    if (text != NULL)
        ltext = _gui_respack_text(text, &updown->ttipid);
    updown->component.context->func_set_tooltip[ekGUI_TYPE_UPDOWN](updown->component.ositem, ltext);
}

/*---------------------------------------------------------------------------*/

void _updown_dimension(UpDown *updown, const uint32_t i, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(updown);
    cassert_no_null(dim0);
    cassert_no_null(dim1);
    if (i == 0)
    {
        *dim0 = updown->size.width;
    }
    else
    {
        cassert(i == 1);
        *dim1 = updown->size.height;
    }
}
