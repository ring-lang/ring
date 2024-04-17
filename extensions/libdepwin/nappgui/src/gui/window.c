/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: window.c
 *
 */

/* Windows */

#include "window.h"
#include "window.inl"
#include "gui.inl"
#include "guicontrol.h"
#include "button.inl"
#include "cell.inl"
#include "component.inl"
#include "layout.inl"
#include "layout.h"
#include "panel.inl"
#include "panel.h"
#include <draw2d/guictx.h>
#include <geom2d/s2d.h>
#include <geom2d/v2d.h>
#include <core/event.h>
#include <core/objh.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _window_t
{
    Object object;
    const GuiCtx *context;
    bool_t in_will_close_event;
    bool_t is_destroyed;
    bool_t visible;
    uint32_t flags;
    gui_role_t role;
    void *ositem;
    ResId titleid;
    Layout *main_layout;
    Listener *OnMoved;
    Listener *OnResize;
    Listener *OnClose;
};

/*---------------------------------------------------------------------------*/

static void i_detach_main_panel(Panel *main_panel, void *window_renderable_item, FPtr_gctx_set_ptr func_detach_main_panel_from_window)
{
    GuiComponent *panel_component;
    cassert_no_nullf(func_detach_main_panel_from_window);
    panel_component = _panel_get_component(main_panel);
    cassert_no_null(panel_component);
    func_detach_main_panel_from_window(window_renderable_item, panel_component->ositem);
    _panel_window(main_panel, NULL);
}

/*---------------------------------------------------------------------------*/

static __INLINE Panel *i_main_panel(const Window *window)
{
    GuiControl *control = NULL;
    cassert_no_null(window);
    control = layout_control(window->main_layout, 0, 0);
    return guicontrol_panel(control);
}

/*---------------------------------------------------------------------------*/

static void i_destroy(Window **window)
{
    cassert_no_null(window);
    cassert_no_null(*window);
    cassert((*window)->in_will_close_event == FALSE);
    cassert_no_null((*window)->context);
    cassert_no_nullf((*window)->context->func_window_destroy);

    if ((*window)->visible == TRUE)
        window_hide(*window);

    if ((*window)->role == ekGUI_ROLE_MODAL)
        window_stop_modal(*window, 0);

    if ((*window)->main_layout != NULL)
    {
        Panel *main_panel = i_main_panel(*window);

/* Prevent flickering in Windows because the main panel new parent will be
        set to NULL (Desktop HWND) when is detached from this window. */
#if defined(__WINDOWS__)
        _panel_hide_all(main_panel);
#endif

        i_detach_main_panel(main_panel, (*window)->ositem, (*window)->context->func_detach_main_panel_from_window);
        _layout_destroy(&(*window)->main_layout);
        _panel_destroy(&main_panel);
    }

    (*window)->context->func_window_destroy(&(*window)->ositem);
    listener_destroy(&(*window)->OnMoved);
    listener_destroy(&(*window)->OnResize);
    listener_destroy(&(*window)->OnClose);
    guictx_release((GuiCtx **)(&(*window)->context));
    obj_delete(window, Window);
}

/*---------------------------------------------------------------------------*/

void window_destroy(Window **window)
{
    cassert_no_null(window);
    cassert_no_null(*window);
    cassert((*window)->is_destroyed == FALSE);
    _gui_delete_window(*window);
    if ((*window)->in_will_close_event == TRUE)
    {
        (*window)->is_destroyed = TRUE;
        *window = NULL;
    }
    else
    {
        i_destroy(window);
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnWindowMoved(Window *window, Event *event)
{
    cassert_no_null(window);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_WND_MOVED);
    cassert(event_sender_imp(event, NULL) == window->ositem);
    if (window->visible == TRUE && window->OnMoved != NULL)
        listener_pass_event(window->OnMoved, event, window, Window);
}

/*---------------------------------------------------------------------------*/

static void i_OnWindowResize(Window *window, Event *e)
{
    const EvSize *params = NULL;
    cassert_no_null(window);
    cassert(window->visible == TRUE);
    cassert_no_null(window->context);
    cassert(event_sender_imp(e, NULL) == window->ositem);
    params = event_params(e, EvSize);
    cassert_no_null(params);

    switch (event_type(e))
    {
    case ekGUI_EVENT_WND_SIZING:
    {
        S2Df reqsize;
        S2Df finsize;
        EvSize *result = event_result(e, EvSize);
        cassert_no_null(result);
        reqsize.width = params->width;
        reqsize.height = params->height;
        _layout_compose(window->main_layout, &reqsize, &finsize);
        result->width = finsize.width;
        result->height = finsize.height;
        break;
    }

    case ekGUI_EVENT_WND_SIZE:
    {
        _layout_locate(window->main_layout);
        if (window->OnResize != NULL)
            listener_pass_event(window->OnResize, e, window, Window);
        break;
    }

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnWindowClose(Window *window, Event *event)
{
    const EvWinClose *params = event_params(event, EvWinClose);
    bool_t closed = TRUE;
    cassert_no_null(window);
    cassert(window->in_will_close_event == FALSE);
    cassert(window->is_destroyed == FALSE);
    cassert_no_null(event);
    cassert(event_type(event) == ekGUI_EVENT_WND_CLOSE);
    cassert(event_sender_imp(event, NULL) == window->ositem);

    window->in_will_close_event = TRUE;

    switch (params->origin)
    {
    case ekGUI_CLOSE_BUTTON:
        if (window->OnClose != NULL)
        {
            listener_pass_event(window->OnClose, event, window, Window);
            closed = *event_result(event, bool_t);
        }
        else
        {
            switch (window->role)
            {
            case ekGUI_ROLE_MAIN:
                closed = FALSE;
                break;
            case ekGUI_ROLE_OVERLAY:
            case ekGUI_ROLE_MODAL:
                closed = TRUE;
                break;
            case ekGUI_ROLE_MANAGED:
                cassert(FALSE);
                closed = FALSE;
                break;
                cassert_default();
            }
        }

        break;

    case ekGUI_CLOSE_ESC:
        if (window->flags & ekWINDOW_ESC)
        {
            *event_result(event, bool_t) = TRUE;
            if (window->OnClose != NULL)
                listener_pass_event(window->OnClose, event, window, Window);
            closed = *event_result(event, bool_t);
        }
        else
        {
            closed = FALSE;
        }
        break;

    case ekGUI_CLOSE_INTRO:
        if (window->flags & ekWINDOW_RETURN)
        {
            *event_result(event, bool_t) = TRUE;
            if (window->OnClose != NULL)
                listener_pass_event(window->OnClose, event, window, Window);
            closed = *event_result(event, bool_t);
        }
        else
        {
            closed = FALSE;
        }
        break;

    case ekGUI_CLOSE_DEACT:
        *event_result(event, bool_t) = TRUE;
        if (window->OnClose != NULL)
            listener_pass_event(window->OnClose, event, window, Window);
        closed = *event_result(event, bool_t);
        break;

        cassert_default();
    }

    if (closed == TRUE)
    {
        if (!(window->flags & ekWINDOW_MODAL_NOHIDE) && window->visible == TRUE)
            window_hide(window);

        if (window->role == ekGUI_ROLE_MODAL)
            window_stop_modal(window, (uint32_t)params->origin);

        cassert(window->visible == FALSE);
        window->in_will_close_event = FALSE;

        if (window->is_destroyed == TRUE)
            i_destroy(&window);
    }
    else
    {
        window->in_will_close_event = FALSE;
    }

    *event_result(event, bool_t) = closed;
}

/*---------------------------------------------------------------------------*/

static Window *i_create_window(const uint32_t flags)
{
    Window *window = obj_new0(Window);
    window->context = guictx_retain(guictx_get_current());
    window->ositem = window->context->func_window_create(flags);
    window->flags = flags;
    window->role = ENUM_MAX(gui_role_t);
    window->context->func_window_OnResize(window->ositem, obj_listener(window, i_OnWindowResize, Window));
    window->context->func_window_OnClose(window->ositem, obj_listener(window, i_OnWindowClose, Window));
    window->context->func_window_set_property(window->ositem, ekGUI_PROP_CHILDREN, NULL);
    _gui_add_window(window);
    return window;
}

/*---------------------------------------------------------------------------*/

static void i_main_layout_compose(Window *window, const S2Df *content_required_size)
{
    S2Df main_layout_size;
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_set_taborder);
    cassert_no_nullf(window->context->func_window_set_size);
    _layout_compose(window->main_layout, content_required_size, &main_layout_size);
    window->context->func_window_set_taborder(window->ositem, NULL);
    _layout_taborder(window->main_layout, window);
    window->context->func_window_set_size(window->ositem, main_layout_size.width, main_layout_size.height);
    _layout_locate(window->main_layout);
}

/*---------------------------------------------------------------------------*/

static void i_attach_main_layout(Window *window, const S2Df *content_size, Layout **layout)
{
    Panel *main_panel = NULL;
    GuiComponent *panel_component = NULL;
    cassert_no_null(window);
    cassert(window->main_layout == NULL);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_attach_main_panel_to_window);
    cassert_no_null(layout);
    window->main_layout = *layout;
    main_panel = i_main_panel(window);
    _panel_window(main_panel, window);
    panel_component = _panel_get_component(main_panel);
    cassert_no_null(panel_component);
    window->context->func_attach_main_panel_to_window(window->ositem, panel_component->ositem);
    i_main_layout_compose(window, content_size);
    _component_visible(panel_component, TRUE);
}

/*---------------------------------------------------------------------------*/

Window *window_create(const uint32_t flags)
{
    Window *window = i_create_window(flags);
    window->context->func_window_set_size(window->ositem, 320, 200);
    return window;
}

/*---------------------------------------------------------------------------*/

void window_panel(Window *window, Panel *panel)
{
    Layout *layout = layout_create(1, 1);
    layout_panel(layout, panel, 0, 0);
    i_attach_main_layout(window, NULL, &layout);
}

/*---------------------------------------------------------------------------*/

static void i_update_listener(
    Window *window,
    Listener **listener,
    Listener *new_listener,
    FPtr_event_handler func_event_handler,
    FPtr_gctx_set_listener func_set_listener)
{
    Listener *renderable_listener = NULL;
    cassert_no_null(window);
    cassert_no_null(listener);
    cassert_no_nullf(func_set_listener);

    if (new_listener != NULL)
    {
        cassert_no_nullf(func_event_handler);
        renderable_listener = obj_listener_imp(window, func_event_handler);
    }

    func_set_listener(window->ositem, renderable_listener);
    listener_update(listener, new_listener);
}

/*---------------------------------------------------------------------------*/

void window_OnMoved(Window *window, Listener *listener)
{
    i_update_listener(
        window, &window->OnMoved, listener,
        (FPtr_event_handler)i_OnWindowMoved,
        window->context->func_window_OnMoved);
}

/*---------------------------------------------------------------------------*/

void window_OnResize(Window *window, Listener *listener)
{
    cassert_no_null(window);
    listener_update(&window->OnResize, listener);
}

/*---------------------------------------------------------------------------*/

void window_OnClose(Window *window, Listener *listener)
{
    cassert_no_null(window);
    listener_update(&window->OnClose, listener);
}

/*---------------------------------------------------------------------------*/

/*
Panel *window_get_main_panel(Window *window);
Panel *window_get_main_panel(Window *window)
{
    cassert_no_null(window);
    return window->main_panel;
}*/

/*---------------------------------------------------------------------------*/

/*
void window_set_edited(Window *window, const bool_t is_edited);
void window_set_edited(Window *window, const bool_t is_edited)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_set_edited);
    window->context->func_window_set_edited(window->ositem, is_edited);
}
*/

/*---------------------------------------------------------------------------*/

/*
void window_set_alpha(Window *window, const real32_t alpha);
void window_set_alpha(Window *window, const real32_t alpha)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_set_alpha);
    window->context->func_window_set_alpha(window->ositem, alpha);
}*/

/*---------------------------------------------------------------------------*/

/*void window_enabled_mouse_events(Window *window, const bool_t enabled);
void window_enabled_mouse_events(Window *window, const bool_t enabled)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_enable_mouse_events);
    window->context->func_window_enable_mouse_events(window->ositem, enabled);
}*/

/*---------------------------------------------------------------------------*/

void window_title(Window *window, const char_t *text)
{
    const char_t *ltext;
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_set_title);
    ltext = _gui_respack_text(text, &window->titleid);
    window->context->func_window_set_title(window->ositem, ltext);
}

/*---------------------------------------------------------------------------*/

void window_show(Window *window)
{
    cassert_no_null(window);
    if (window->visible == FALSE)
    {
        cassert_no_null(window->context);
        cassert_no_nullf(window->context->func_window_launch);
        window->visible = TRUE;
        if (window->role == ENUM_MAX(gui_role_t))
            window->role = ekGUI_ROLE_MAIN;
        window->context->func_window_launch(window->ositem, NULL);
    }
}

/*---------------------------------------------------------------------------*/

void window_hide(Window *window)
{
    cassert_no_null(window);
    cassert(window->visible == TRUE);
    if (window->visible == TRUE)
    {
        cassert_no_null(window->context);
        cassert_no_nullf(window->context->func_window_hide);
        window->context->func_window_hide(window->ositem, NULL);
        window->visible = FALSE;
    }
}

/*---------------------------------------------------------------------------*/

void window_overlay(Window *window, Window *parent)
{
    if (window->visible == FALSE)
    {
        cassert_no_null(window->context);
        cassert_no_nullf(window->context->func_window_launch);
        cassert_no_null(parent);
        window->visible = TRUE;
        window->role = ekGUI_ROLE_OVERLAY;
        window->context->func_window_launch(window->ositem, parent->ositem);
    }
}

/*---------------------------------------------------------------------------*/

uint32_t window_modal(Window *window, Window *parent)
{
    cassert_no_null(window);
    if (window->role != ekGUI_ROLE_MODAL)
    {
        window->role = ekGUI_ROLE_MODAL;
        window->visible = TRUE;
        cassert_no_null(window->context);
        cassert_no_nullf(window->context->func_window_launch_modal);
        return window->context->func_window_launch_modal(window->ositem, (parent != NULL) ? parent->ositem : NULL);
    }
    else
    {
        return UINT32_MAX;
    }
}

/*---------------------------------------------------------------------------*/

void window_stop_modal(Window *window, const uint32_t return_value)
{
    cassert_no_null(window);
    if (window->role == ekGUI_ROLE_MODAL)
    {
        cassert_no_null(window->context);
        cassert_no_nullf(window->context->func_window_stop_modal);
        window->context->func_window_stop_modal(window->ositem, return_value);
        window->visible = FALSE;
        window->role = ENUM_MAX(gui_role_t);
    }
}

/*---------------------------------------------------------------------------*/

void window_hotkey(Window *window, const vkey_t key, const uint32_t modifiers, Listener *listener)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_hotkey);
    window->context->func_window_hotkey(window->ositem, key, modifiers, listener);
}

/*---------------------------------------------------------------------------*/

void window_clear_hotkeys(Window *window)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_hotkey);
    window->context->func_window_hotkey(window->ositem, ENUM_MAX(vkey_t), 0, NULL);
}

/*---------------------------------------------------------------------------*/

void window_cycle_tabstop(Window *window, const bool_t cycle)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_tabcycle);
    window->context->func_window_tabcycle(window->ositem, cycle);
}

/*---------------------------------------------------------------------------*/

gui_focus_t window_next_tabstop(Window *window)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_tabstop);
    return (gui_focus_t)window->context->func_window_tabstop(window->ositem, TRUE);
}

/*---------------------------------------------------------------------------*/

gui_focus_t window_previous_tabstop(Window *window)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_tabstop);
    return (gui_focus_t)window->context->func_window_tabstop(window->ositem, FALSE);
}

/*---------------------------------------------------------------------------*/

gui_focus_t window_focus(Window *window, GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    cassert_no_null(component);
    cassert_no_null(component->context);
    return (gui_focus_t)component->context->func_window_set_focus(window->ositem, component->ositem);
}

/*---------------------------------------------------------------------------*/

GuiControl *window_get_focus(Window *window)
{
    void *ositem = NULL;
    GuiComponent *component = NULL;
    cassert_no_null(window);
    cassert_no_null(window->context);
    ositem = window->context->func_window_get_focus(window->ositem);

    if (ositem != NULL)
    {
        Panel *main_panel = i_main_panel(window);
        component = _panel_find_component(main_panel, ositem);
    }

    return (GuiControl *)component;
}

/*---------------------------------------------------------------------------*/

void window_focus_info(const Window *window, FocusInfo *info)
{
    void *next = NULL;
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_null(info);
    info->action = (gui_tab_t)window->context->func_window_info_focus(window->ositem, &next);

    if (next != NULL)
    {
        Panel *panel = i_main_panel(window);
        info->next = (GuiControl *)_panel_find_component(panel, next);
        cassert_no_null(info->next);
    }
    else
    {
        info->next = NULL;
    }
}

/*---------------------------------------------------------------------------*/

void window_update(Window *window)
{
    _window_update(window);
}

/*---------------------------------------------------------------------------*/

/*
void window_launch_sheet(Window *window, Window *owner_window);
void window_launch_sheet(Window *window, Window *owner_window)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_null(owner_window);
    cassert_no_nullf(window->context->func_window_launch_sheet);
    cassert_no_nullf(window->context->func_window_set_z_order);
    cassert(FALSE);
    window->context->func_window_launch_sheet(window->ositem, owner_window->ositem);
    window->context->func_window_set_z_order(window->ositem, NULL);
}*/

/*---------------------------------------------------------------------------*/

/*
void window_stop_sheet(Window *window, Window *owner_window);
void window_stop_sheet(Window *window, Window *owner_window)
{
    cassert_no_null(window);
    cassert_no_null(owner_window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_stop_sheet);
    cassert(FALSE);
    window->context->func_window_stop_sheet(window->ositem, owner_window->ositem);
}
*/

/*---------------------------------------------------------------------------*/

/*
void window_set_origin_in_screen_center(Window *window);
void window_set_origin_in_screen_center(Window *window)
{
    real32_t screen_width, screen_height;
    real32_t window_width, window_height;
    real32_t x, y;
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_globals_resolution);
    cassert_no_nullf(window->context->func_window_get_size);
    cassert_no_nullf(window->context->func_window_set_origin_in_screen_coordinates);
    window->context->func_globals_resolution(NULL, &screen_width, &screen_height);
    window->context->func_window_get_size(window->ositem, &window_width, &window_height);
    x = .5f * (screen_width - window_width);
    y = .5f * (screen_height - window_height);
    window->context->func_window_set_origin_in_screen_coordinates(window->ositem, x, y);
}*/

/*---------------------------------------------------------------------------*/

/*
void window_set_origin_in_screen_width_center(Window *window, const real32_t y);
void window_set_origin_in_screen_width_center(Window *window, const real32_t y)
{
    real32_t screen_width, screen_height;
    real32_t window_width, window_height;
    real32_t x;
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_globals_resolution);
    cassert_no_nullf(window->context->func_window_get_size);
    cassert_no_nullf(window->context->func_window_set_origin_in_screen_coordinates);
    window->context->func_globals_resolution(NULL, &screen_width, &screen_height);
    window->context->func_window_get_size(window->ositem, &window_width, &window_height);
    x = .5f * (screen_width - window_width);
    window->context->func_window_set_origin_in_screen_coordinates(window->ositem, x, y);
}*/

/*---------------------------------------------------------------------------*/

/*
void window_set_origin_in_screen_width_right(Window *window, const real32_t offset_x, const real32_t y);
void window_set_origin_in_screen_width_right(Window *window, const real32_t offset_x, const real32_t y)
{
    real32_t screen_width, screen_height;
    real32_t window_width, window_height;
    real32_t x;
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_globals_resolution);
    cassert_no_nullf(window->context->func_window_get_size);
    cassert_no_nullf(window->context->func_window_set_origin_in_screen_coordinates);
    window->context->func_globals_resolution(NULL, &screen_width, &screen_height);
    window->context->func_window_get_size(window->ositem, &window_width, &window_height);
    x = screen_width - window_width - offset_x;
    window->context->func_window_set_origin_in_screen_coordinates(window->ositem, x, y);
}*/

/*---------------------------------------------------------------------------*/

void window_origin(Window *window, const V2Df origin)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_set_origin_in_screen_coordinates);
    window->context->func_window_set_origin_in_screen_coordinates(window->ositem, origin.x, origin.y);
}

/*---------------------------------------------------------------------------*/

void window_size(Window *window, const S2Df size)
{
    cassert_no_null(window);
    cassert(window->flags & ekWINDOW_RESIZE);
    i_main_layout_compose(window, &size);
}

/*---------------------------------------------------------------------------*/

V2Df window_get_origin(const Window *window)
{
    V2Df origin;
    origin.x = REAL32_MAX;
    origin.y = REAL32_MAX;
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_get_origin_in_screen_coordinates);
    window->context->func_window_get_origin_in_screen_coordinates(window->ositem, &origin.x, &origin.y);
    return origin;
}

/*---------------------------------------------------------------------------*/

S2Df window_get_size(const Window *window)
{
    S2Df size;
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_get_size);
    window->context->func_window_get_size(window->ositem, &size.width, &size.height);
    return size;
}

/*---------------------------------------------------------------------------*/

S2Df window_get_client_size(const Window *window)
{
    Panel *panel = NULL;
    GuiComponent *component = NULL;
    S2Df size;
    cassert_no_null(window);
    panel = i_main_panel(window);
    component = _panel_get_component(panel);
    window->context->func_get_size[ekGUI_TYPE_PANEL](component->ositem, &size.width, &size.height);
    return size;
}

/*---------------------------------------------------------------------------*/

#if defined __ASSERTS__
static bool_t i_in_active_layout(const Window *window, const GuiComponent *component)
{
    Panel *panel = i_main_panel(window);
    return _panel_in_active_layout(panel, component);
}
#endif

/*---------------------------------------------------------------------------*/

R2Df window_control_frame(const Window *window, const GuiControl *control)
{
    R2Df r2d;
    GuiComponent *component = (GuiComponent *)control;
    Cell *cell = NULL;
    cassert_no_null(window);
    cassert_no_null(component);
    cassert(_component_window(component) == window);
    cassert(i_in_active_layout(window, component) == TRUE);
    _component_get_origin(component, &r2d.pos);
    _component_get_size(component, &r2d.size);
    cell = _component_cell(component);
    for (; cell != NULL;)
    {
        V2Df panel_pos;
        Layout *layout = _cell_parent(cell);
        Panel *panel = _layout_panel(layout);
        if (panel != NULL)
        {
            GuiComponent *panel_component = (GuiComponent *)panel;
            _component_get_origin(panel_component, &panel_pos);
            r2d.pos.x += panel_pos.x;
            r2d.pos.y += panel_pos.y;
            cell = _component_cell(panel_component);
        }
        else
        {
            cell = NULL;
        }
    }

    return r2d;
}

/*---------------------------------------------------------------------------*/

V2Df window_client_to_screen(const Window *window, const V2Df point)
{
    V2Df origin = point;
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_get_origin_in_screen_coordinates);
    window->context->func_window_get_origin_in_screen_coordinates(window->ositem, &origin.x, &origin.y);
    return origin;
}

/*---------------------------------------------------------------------------*/

void window_defbutton(Window *window, Button *button)
{
    cassert_no_null(window);
    if (button != NULL)
    {
        cassert(_button_is_pushbutton(button) == TRUE);
        window->context->func_window_set_default_pushbutton(window->ositem, ((GuiComponent *)button)->ositem);
    }
    else
    {
        window->context->func_window_set_default_pushbutton(window->ositem, NULL);
    }
}

/*---------------------------------------------------------------------------*/

void window_cursor(Window *window, const gui_cursor_t cursor, const Image *image, const real32_t hot_x, const real32_t hot_y)
{
    cassert_no_null(window);
    if (cursor != ekGUI_CURSOR_ARROW)
    {
        const Cursor *oscursor = _gui_cursor(cursor, image, hot_x, hot_y);
        window->context->func_window_set_cursor(window->ositem, (Cursor *)oscursor);
    }
    else
    {
        window->context->func_window_set_cursor(window->ositem, NULL);
    }
}

/*---------------------------------------------------------------------------*/

void *window_imp(const Window *window)
{
    cassert_no_null(window);
    return window->ositem;
}

/*---------------------------------------------------------------------------*/

void _window_locale(Window *window)
{
    Panel *main_panel = NULL;
    cassert_no_null(window);
    main_panel = i_main_panel(window);
    _panel_locale(main_panel);
    if (window->titleid != NULL)
    {
        const char_t *text = _gui_respack_text(window->titleid, NULL);
        window->context->func_window_set_title(window->ositem, text);
    }

    _window_update(window);
}

/*---------------------------------------------------------------------------*/

gui_role_t _window_role(const Window *window)
{
    cassert_no_null(window);
    return window->role;
}

/*---------------------------------------------------------------------------*/

void _window_update(Window *window)
{
    cassert_no_null(window);
    if (window->flags & ekWINDOW_RESIZE)
    {
        S2Df current_panel_size;
        Panel *main_panel = i_main_panel(window);
        GuiComponent *component = _panel_get_component(main_panel);
        window->context->func_get_size[ekGUI_TYPE_PANEL](component->ositem, &current_panel_size.width, &current_panel_size.height);
        i_main_layout_compose(window, &current_panel_size);
    }
    else
    {
        i_main_layout_compose(window, NULL);
    }
}

/*---------------------------------------------------------------------------*/

void *_window_ositem(Window *window)
{
    cassert_no_null(window);
    return window->ositem;
}

/*---------------------------------------------------------------------------*/

bool_t _window_is_visible(const Window *window)
{
    cassert_no_null(window);
    return (bool_t)window->visible;
}

/*---------------------------------------------------------------------------*/

Panel *_window_main_panel(Window *window)
{
    return i_main_panel(window);
}

/*---------------------------------------------------------------------------*/

void _window_taborder(Window *window, void *ositem)
{
    cassert_no_null(window);
    cassert_no_null(window->context);
    cassert_no_nullf(window->context->func_window_set_taborder);
    window->context->func_window_set_taborder(window->ositem, ositem);
}
