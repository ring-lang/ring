/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: view.c
 *
 */

/* Custom view */

#include "view.h"
#include "view.inl"
#include "cell.inl"
#include "component.inl"
#include "gui.inl"
#include "panel.inl"
#include "window.inl"
#include <draw2d/guictx.h>
#include <geom2d/s2d.h>
#include <geom2d/v2d.h>
#include <core/event.h>
#include <core/keybuf.h>
#include <core/objh.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _view_t
{
    GuiComponent component;
    String *subtype;
    S2Df size;
    Listener *OnDraw;
    Listener *OnOverlay;
    Listener *OnResize;
    Listener *OnEnter;
    Listener *OnExit;
    Listener *OnMoved;
    Listener *OnDown;
    Listener *OnUp;
    Listener *OnClick;
    Listener *OnDrag;
    Listener *OnWheel;
    Listener *OnKeyDown;
    Listener *OnKeyUp;
    Listener *OnFocus;
    Listener *OnResignFocus;
    Listener *OnAcceptFocus;
    Listener *OnScroll;
    KeyBuf *keybuf;
    void *data;
    FPtr_destroy func_destroy_data;
    FPtr_gctx_call func_empty;
    FPtr_gctx_set_uint32 func_uint32;
    FPtr_set_image func_image;
};

/*---------------------------------------------------------------------------*/

static void i_OnDraw(View *view, Event *event)
{
    cassert_no_null(view);
    cassert(event_type(event) == ekGUI_EVENT_DRAW);
    listener_pass_event(view->OnDraw, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnOverlay(View *view, Event *event)
{
    cassert_no_null(view);
    cassert(event_type(event) == ekGUI_EVENT_OVERLAY);
    listener_pass_event(view->OnOverlay, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnEnter(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_ENTER);
    listener_pass_event(view->OnEnter, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnExit(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_EXIT);
    listener_pass_event(view->OnExit, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnMoved(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_MOVED);
    listener_pass_event(view->OnMoved, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnDown(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_DOWN);
    listener_pass_event(view->OnDown, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnUp(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_UP);
    listener_pass_event(view->OnUp, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnClick(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_CLICK);
    listener_pass_event(view->OnClick, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnDrag(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_DRAG);
    listener_pass_event(view->OnDrag, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnWheel(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_WHEEL);
    listener_pass_event(view->OnWheel, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnKeyDown(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_KEYDOWN);
    if (view->keybuf != NULL)
    {
        const EvKey *p = event_params(event, EvKey);
        keybuf_OnDown(view->keybuf, p->key);
    }

    if (view->OnKeyDown != NULL)
        listener_pass_event(view->OnKeyDown, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnKeyUp(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_KEYUP);
    if (view->keybuf != NULL)
    {
        const EvKey *p = event_params(event, EvKey);
        keybuf_OnUp(view->keybuf, p->key);
    }

    if (view->OnKeyUp != NULL)
        listener_pass_event(view->OnKeyUp, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnFocus(View *view, Event *event)
{
    cassert_no_null(view);
    cassert_no_null(event);
    if (view->keybuf != NULL)
        keybuf_clear(view->keybuf);
    listener_pass_event(view->OnFocus, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnResignFocus(View *view, Event *event)
{
    cassert_no_null(view);
    listener_pass_event(view->OnResignFocus, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnAcceptFocus(View *view, Event *event)
{
    cassert_no_null(view);
    listener_pass_event(view->OnAcceptFocus, event, view, View);
}

/*---------------------------------------------------------------------------*/

static void i_OnScroll(View *view, Event *event)
{
    cassert_no_null(view);
    listener_pass_event(view->OnScroll, event, view, View);
}

/*---------------------------------------------------------------------------*/

static View *i_create(const uint32_t flags)
{
    const GuiCtx *context = guictx_get_current();
    void *ositem = context->func_create[ekGUI_TYPE_CUSTOMVIEW](flags);

    if (ositem != NULL)
    {
        View *view = obj_new0(View);
        view->size = s2df(128, 128);
        view->data = NULL;
        view->func_destroy_data = NULL;
        _component_init(&view->component, context, PARAM(type, ekGUI_TYPE_CUSTOMVIEW), &ositem);
        return view;
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

View *view_create(void)
{
    return i_create(0);
}

/*---------------------------------------------------------------------------*/

View *view_scroll(void)
{
    return i_create(ekVIEW_HSCROLL | ekVIEW_VSCROLL);
}

/*---------------------------------------------------------------------------*/

View *view_custom(const bool_t scroll, const bool_t border)
{
    uint32_t flags = 0;
    if (scroll == TRUE)
        flags |= ekVIEW_HSCROLL | ekVIEW_VSCROLL;
    if (border == TRUE)
        flags |= ekVIEW_BORDER;
    return i_create(flags);
}

/*---------------------------------------------------------------------------*/

View *_view_create(const uint32_t flags)
{
    return i_create(flags);
}

/*---------------------------------------------------------------------------*/

void view_data_imp(View *view, void **data, FPtr_destroy func_destroy_data)
{
    cassert_no_null(view);

    if (view->data != NULL && view->func_destroy_data != NULL)
        view->func_destroy_data(&view->data);

    view->data = ptr_dget_no_null(data, void);
    view->func_destroy_data = func_destroy_data;
}

/*---------------------------------------------------------------------------*/

void *view_get_data_imp(const View *view)
{
    cassert_no_null(view);
    return view->data;
}

/*---------------------------------------------------------------------------*/

void _view_destroy(View **view)
{
    cassert_no_null(view);
    cassert_no_null(*view);

    if ((*view)->data != NULL && (*view)->func_destroy_data != NULL)
        (*view)->func_destroy_data(&(*view)->data);

    _component_destroy_imp(&(*view)->component);
    str_destopt(&(*view)->subtype);
    listener_destroy(&(*view)->OnDraw);
    listener_destroy(&(*view)->OnOverlay);
    listener_destroy(&(*view)->OnResize);
    listener_destroy(&(*view)->OnEnter);
    listener_destroy(&(*view)->OnExit);
    listener_destroy(&(*view)->OnMoved);
    listener_destroy(&(*view)->OnDown);
    listener_destroy(&(*view)->OnUp);
    listener_destroy(&(*view)->OnClick);
    listener_destroy(&(*view)->OnDrag);
    listener_destroy(&(*view)->OnWheel);
    listener_destroy(&(*view)->OnKeyDown);
    listener_destroy(&(*view)->OnKeyUp);
    listener_destroy(&(*view)->OnFocus);
    listener_destroy(&(*view)->OnResignFocus);
    listener_destroy(&(*view)->OnAcceptFocus);
    listener_destroy(&(*view)->OnScroll);
    _gui_delete_transition(*view, View);
    obj_delete(view, View);
}

/*---------------------------------------------------------------------------*/

void view_size(View *view, const S2Df size)
{
    cassert_no_null(view);
    view->size = size;
}

/*---------------------------------------------------------------------------*/

void view_OnDraw(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnDraw, listener, i_OnDraw, view->component.context->func_view_OnDraw, View);
}

/*---------------------------------------------------------------------------*/

void view_OnOverlay(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnOverlay, listener, i_OnOverlay, view->component.context->func_view_OnOverlay, View);
}

/*---------------------------------------------------------------------------*/

void view_OnSize(View *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->OnResize, listener);
}

/*---------------------------------------------------------------------------*/

void view_OnEnter(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnEnter, listener, i_OnEnter, view->component.context->func_view_OnEnter, View);
}

/*---------------------------------------------------------------------------*/

void view_OnExit(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnExit, listener, i_OnExit, view->component.context->func_view_OnExit, View);
}

/*---------------------------------------------------------------------------*/

void view_OnMove(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnMoved, listener, i_OnMoved, view->component.context->func_view_OnMoved, View);
}

/*---------------------------------------------------------------------------*/

void view_OnDown(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnDown, listener, i_OnDown, view->component.context->func_view_OnDown, View);
}

/*---------------------------------------------------------------------------*/

void view_OnUp(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnUp, listener, i_OnUp, view->component.context->func_view_OnUp, View);
}

/*---------------------------------------------------------------------------*/

void view_OnClick(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnClick, listener, i_OnClick, view->component.context->func_view_OnClick, View);
}

/*---------------------------------------------------------------------------*/

void view_OnDrag(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnDrag, listener, i_OnDrag, view->component.context->func_view_OnDrag, View);
}

/*---------------------------------------------------------------------------*/

void view_OnWheel(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnWheel, listener, i_OnWheel, view->component.context->func_view_OnWheel, View);
}

/*---------------------------------------------------------------------------*/

void view_OnKeyDown(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnKeyDown, listener, i_OnKeyDown, view->component.context->func_view_OnKeyDown, View);
    if (view->keybuf != NULL && view->OnKeyDown == NULL)
        view->component.context->func_view_OnKeyDown(view->component.ositem, listener(view, i_OnKeyDown, View));
}

/*---------------------------------------------------------------------------*/

void view_OnKeyUp(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnKeyUp, listener, i_OnKeyUp, view->component.context->func_view_OnKeyUp, View);
    if (view->keybuf != NULL && view->OnKeyUp == NULL)
        view->component.context->func_view_OnKeyUp(view->component.ositem, listener(view, i_OnKeyUp, View));
}

/*---------------------------------------------------------------------------*/

void view_OnFocus(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnFocus, listener, i_OnFocus, view->component.context->func_view_OnFocus, View);
}

/*---------------------------------------------------------------------------*/

void view_OnResignFocus(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnResignFocus, listener, i_OnResignFocus, view->component.context->func_view_OnResignFocus, View);
}

/*---------------------------------------------------------------------------*/

void view_OnAcceptFocus(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnAcceptFocus, listener, i_OnAcceptFocus, view->component.context->func_view_OnAcceptFocus, View);
}

/*---------------------------------------------------------------------------*/

void view_OnScroll(View *view, Listener *listener)
{
    component_update_listener(view, &view->OnScroll, listener, i_OnScroll, view->component.context->func_view_OnScroll, View);
}

/*---------------------------------------------------------------------------*/

void view_keybuf(View *view, KeyBuf *buffer)
{
    cassert_no_null(view);
    view->keybuf = buffer;

    if (view->keybuf != NULL && view->OnKeyDown == NULL)
        view->component.context->func_view_OnKeyDown(view->component.ositem, listener(view, i_OnKeyDown, View));

    if (view->keybuf != NULL && view->OnKeyUp == NULL)
        view->component.context->func_view_OnKeyUp(view->component.ositem, listener(view, i_OnKeyUp, View));
}

/*---------------------------------------------------------------------------*/

void _view_set_subtype(View *view, const char_t *subtype)
{
    cassert_no_null(view);
    cassert(view->subtype == NULL);
    view->subtype = str_c(subtype);
}

/*---------------------------------------------------------------------------*/

const char_t *_view_subtype(const View *view)
{
    cassert_no_null(view);
    if (view->subtype != NULL)
        return tc(view->subtype);
    return "View";
}

/*---------------------------------------------------------------------------*/

void _view_dimension(View *view, const uint32_t i, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(view);
    cassert_no_null(dim0);
    cassert_no_null(dim1);
    if (i == 0)
    {
        *dim0 = view->size.width;
    }
    else
    {
        cassert(i == 1);
        *dim1 = view->size.height;
    }
}

/*---------------------------------------------------------------------------*/

void _view_OnResize(View *view, const S2Df *size)
{
    cassert_no_null(view);
    cassert_no_null(size);
    if (view->OnResize != NULL)
    {
        EvSize params;
        params.width = size->width;
        params.height = size->height;
        listener_event(view->OnResize, ekGUI_EVENT_RESIZE, view, &params, NULL, View, EvSize, void);
    }

    view->component.context->func_view_set_need_display(view->component.ositem);
}

/*---------------------------------------------------------------------------*/

Cell *_view_cell(View *view)
{
    cassert_no_null(view);
    return _component_cell(&view->component);
}

/*---------------------------------------------------------------------------*/

void *_view_get_native_imp(View *view)
{
    cassert_no_null(view);
    return view->component.ositem;
}

/*---------------------------------------------------------------------------*/

void view_OnEmpty(View *view, FPtr_gctx_call func_empty)
{
    cassert_no_null(view);
    view->func_empty = func_empty;
}

/*---------------------------------------------------------------------------*/

void view_OnUInt32(View *view, FPtr_gctx_set_uint32 func_uint32)
{
    cassert_no_null(view);
    view->func_uint32 = func_uint32;
}

/*---------------------------------------------------------------------------*/

void view_OnImage(View *view, FPtr_set_image func_image)
{
    cassert_no_null(view);
    view->func_image = func_image;
}

/*---------------------------------------------------------------------------*/

void _view_empty(View *view)
{
    cassert_no_null(view);
    if (view->func_empty != NULL)
        view->func_empty(view);
}

/*---------------------------------------------------------------------------*/

void _view_uint32(View *view, const uint32_t value)
{
    cassert_no_null(view);
    if (view->func_uint32 != NULL)
        view->func_uint32(view, value);
}

/*---------------------------------------------------------------------------*/

void _view_image(View *view, const Image *image)
{
    cassert_no_null(view);
    if (view->func_image != NULL)
        view->func_image(view, image);
}

/*---------------------------------------------------------------------------*/

void view_get_size(const View *view, S2Df *size)
{
    cassert_no_null(view);
    cassert_no_null(size);
    view->component.context->func_get_size[ekGUI_TYPE_CUSTOMVIEW](view->component.ositem, &size->width, &size->height);
}

/*---------------------------------------------------------------------------*/

void view_content_size(View *view, const S2Df size, const S2Df line)
{
    cassert_no_null(view);
    view->component.context->func_view_content_size(view->component.ositem, size.width, size.height, line.width, line.height);
}

/*---------------------------------------------------------------------------*/

void view_scroll_x(View *view, const real32_t pos)
{
    cassert_no_null(view);
    view->component.context->func_view_scroll(view->component.ositem, pos, -1);
}

/*---------------------------------------------------------------------------*/

void view_scroll_y(View *view, const real32_t pos)
{
    cassert_no_null(view);
    view->component.context->func_view_scroll(view->component.ositem, -1, pos);
}

/*---------------------------------------------------------------------------*/

void view_scroll_size(const View *view, real32_t *width, real32_t *height)
{
    cassert_no_null(view);
    view->component.context->func_view_scroller_size(view->component.ositem, width, height);
}

/*---------------------------------------------------------------------------*/

void view_scroll_visible(View *view, const bool_t horizontal, const bool_t vertical)
{
    cassert_no_null(view);
    view->component.context->func_view_scroller_visible(view->component.ositem, horizontal, vertical);
}

/*---------------------------------------------------------------------------*/

void view_viewport(const View *view, V2Df *pos, S2Df *size)
{
    cassert_no_null(view);
    if (pos != NULL)
        view->component.context->func_view_scroll_get(view->component.ositem, &pos->x, &pos->y);

    if (size != NULL)
        view->component.context->func_get_size[ekGUI_TYPE_CUSTOMVIEW](view->component.ositem, &size->width, &size->height);
}

/*---------------------------------------------------------------------------*/

void view_point_scale(const View *view, real32_t *scale)
{
    cassert_no_null(view);
    cassert_no_null(scale);
    *scale = view->component.context->func_view_scale_factor(view->component.ositem);
}

/*---------------------------------------------------------------------------*/

void view_update(View *view)
{
    cassert_no_null(view);
    view->component.context->func_view_set_need_display(view->component.ositem);
    /*if (view->component.owner != NULL)
    {
        Window *window = NULL;
        cassert_no_null(view->component.context);
        cassert_no_nullf(view->component.context->func_view_set_need_display);
        window = _panel_get_window(view->component.owner);
        if (window && _window_is_visible(window) == TRUE)
            view->component.context->func_view_set_need_display(view->component.ositem);
    }*/
}

/*---------------------------------------------------------------------------*/

void *view_native(View *view)
{
    /* Get the native view */
    cassert_no_null(view);
    return view->component.context->func_view_get_native_view(view->component.ositem);
}

/*---------------------------------------------------------------------------*/

void view_add_transition(View *view, Listener *listener)
{
    cassert_no_null(view);
    _gui_add_transition(view, listener, View);
}

/*---------------------------------------------------------------------------*/

void view_delete_transition(View *view)
{
    _gui_delete_transition(view, View);
}
