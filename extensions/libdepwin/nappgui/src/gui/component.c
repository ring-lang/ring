/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: component.c
 *
 */

/* Gui Component */

#include "component.inl"
#include "button.inl"
#include "cell.inl"
#include "combo.inl"
#include "view.inl"
#include "edit.inl"
#include "gui.inl"
#include "label.inl"
#include "layout.inl"
#include "panel.inl"
#include "popup.inl"
#include "progress.inl"
#include "slider.inl"
#include "textview.inl"
#include "splitview.inl"
#include "updown.inl"
#include "window.inl"
#include <draw2d/guictx.h>
#include <core/event.h>
#include <core/objh.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/types.h>

/*---------------------------------------------------------------------------*/

static const FPtr_gctx_set_bool i_FUNC_SET_VISIBLE[GUI_CONTEXT_NUM_COMPONENTS] = {
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_LABEL */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_BUTTON */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_POPUP */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_EDITBOX */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_COMBOBOX */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_SLIDER */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_UPDOWN */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_PROGRESS */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_TEXTVIEW */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_TABLEVIEW */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_TREEVIEW */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_BOXVIEW */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_SPLITVIEW */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_CUSTOMVIEW */
    (FPtr_gctx_set_bool)NULL,  /* ekGUI_TYPE_PANEL */
    (FPtr_gctx_set_bool)NULL}; /* ekGUI_TYPE_LINE */

static const FPtr_panels i_FUNC_PANELS[GUI_CONTEXT_NUM_COMPONENTS] = {
    (FPtr_panels)NULL,              /* ekGUI_TYPE_LABEL */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_BUTTON */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_POPUP */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_EDITBOX */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_COMBOBOX */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_SLIDER */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_UPDOWN */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_PROGRESS */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_TEXTVIEW */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_TABLEVIEW */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_TREEVIEW */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_BOXVIEW */
    (FPtr_panels)_splitview_panels, /* ekGUI_TYPE_SPLITVIEW */
    (FPtr_panels)NULL,              /* ekGUI_TYPE_CUSTOMVIEW */
    (FPtr_panels)_panel_panels,     /* ekGUI_TYPE_PANEL */
    (FPtr_panels)NULL};             /* ekGUI_TYPE_LINE */

static const FPtr_dimension i_FUNC_DIMENSION[GUI_CONTEXT_NUM_COMPONENTS] = {
    (FPtr_dimension)_label_dimension,     /* ekGUI_TYPE_LABEL */
    (FPtr_dimension)_button_dimension,    /* ekGUI_TYPE_BUTTON */
    (FPtr_dimension)_popup_dimension,     /* ekGUI_TYPE_POPUP */
    (FPtr_dimension)_edit_dimension,      /* ekGUI_TYPE_EDITBOX */
    (FPtr_dimension)_combo_dimension,     /* ekGUI_TYPE_COMBOBOX */
    (FPtr_dimension)_slider_dimension,    /* ekGUI_TYPE_SLIDER */
    (FPtr_dimension)_updown_dimension,    /* ekGUI_TYPE_UPDOWN */
    (FPtr_dimension)_progress_dimension,  /* ekGUI_TYPE_PROGRESS */
    (FPtr_dimension)_textview_dimension,  /* ekGUI_TYPE_TEXTVIEW */
    (FPtr_dimension)NULL,                 /* ekGUI_TYPE_TABLEVIEW */
    (FPtr_dimension)NULL,                 /* ekGUI_TYPE_TREEVIEW */
    (FPtr_dimension)NULL,                 /* ekGUI_TYPE_BOXVIEW */
    (FPtr_dimension)_splitview_dimension, /* ekGUI_TYPE_SPLITVIEW */
    (FPtr_dimension)_view_dimension,      /* ekGUI_TYPE_CUSTOMVIEW */
    (FPtr_dimension)_panel_dimension,     /* ekGUI_TYPE_PANEL */
    (FPtr_dimension)NULL};                /* ekGUI_TYPE_LINE */

static const FPtr_expand i_FUNC_EXPAND[GUI_CONTEXT_NUM_COMPONENTS] = {
    (FPtr_expand)NULL,              /* ekGUI_TYPE_LABEL */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_BUTTON */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_POPUP */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_EDITBOX */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_COMBOBOX */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_SLIDER */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_UPDOWN */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_PROGRESS */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_TEXTVIEW */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_TABLEVIEW */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_TREEVIEW */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_BOXVIEW */
    (FPtr_expand)_splitview_expand, /* ekGUI_TYPE_SPLITVIEW */
    (FPtr_expand)NULL,              /* ekGUI_TYPE_CUSTOMVIEW */
    (FPtr_expand)_panel_expand,     /* ekGUI_TYPE_PANEL */
    (FPtr_expand)NULL};             /* ekGUI_TYPE_LINE */

static const FPtr_set_size i_FUNC_ON_RESIZE[GUI_CONTEXT_NUM_COMPONENTS] = {
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_LABEL */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_BUTTON */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_POPUP */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_EDITBOX */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_COMBOBOX */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_SLIDER */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_UPDOWN */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_PROGRESS */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_TEXTVIEW */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_TABLEVIEW */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_TREEVIEW */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_BOXVIEW */
    (FPtr_set_size)_splitview_OnResize, /* ekGUI_TYPE_SPLITVIEW */
    (FPtr_set_size)_view_OnResize,      /* ekGUI_TYPE_CUSTOMVIEW */
    (FPtr_set_size)NULL,                /* ekGUI_TYPE_PANEL */
    (FPtr_set_size)NULL};               /* ekGUI_TYPE_LINE */

static const FPtr_gctx_call i_FUNC_LOCALE[GUI_CONTEXT_NUM_COMPONENTS] = {
    (FPtr_gctx_call)_label_locale,  /* ekGUI_TYPE_LABEL */
    (FPtr_gctx_call)_button_locale, /* ekGUI_TYPE_BUTTON */
    (FPtr_gctx_call)_popup_locale,  /* ekGUI_TYPE_POPUP */
    (FPtr_gctx_call)_edit_locale,   /* ekGUI_TYPE_EDITBOX */
    (FPtr_gctx_call)_combo_locale,  /* ekGUI_TYPE_COMBOBOX */
    (FPtr_gctx_call)NULL,           /* ekGUI_TYPE_SLIDER */
    (FPtr_gctx_call)NULL,           /* ekGUI_TYPE_UPDOWN */
    (FPtr_gctx_call)NULL,           /* ekGUI_TYPE_PROGRESS */
    (FPtr_gctx_call)NULL,           /* ekGUI_TYPE_TEXTVIEW */
    (FPtr_gctx_call)NULL,           /* ekGUI_TYPE_TABLEVIEW */
    (FPtr_gctx_call)NULL,           /* ekGUI_TYPE_TREEVIEW */
    (FPtr_gctx_call)NULL,           /* ekGUI_TYPE_BOXVIEW */
    (FPtr_gctx_call)NULL,           /* ekGUI_TYPE_SPLITVIEW */
    (FPtr_gctx_call)NULL,           /* ekGUI_TYPE_CUSTOMVIEW */
    (FPtr_gctx_call)_panel_locale,  /* ekGUI_TYPE_PANEL */
    (FPtr_gctx_call)NULL};          /* ekGUI_TYPE_LINE */

static const FPtr_destroy i_FUNC_DESTROY[GUI_CONTEXT_NUM_COMPONENTS] = {
    (FPtr_destroy)_label_destroy,     /* ekGUI_TYPE_LABEL */
    (FPtr_destroy)_button_destroy,    /* ekGUI_TYPE_BUTTON */
    (FPtr_destroy)_popup_destroy,     /* ekGUI_TYPE_POPUP */
    (FPtr_destroy)_edit_destroy,      /* ekGUI_TYPE_EDITBOX */
    (FPtr_destroy)_combo_destroy,     /* ekGUI_TYPE_COMBOBOX */
    (FPtr_destroy)_slider_destroy,    /* ekGUI_TYPE_SLIDER */
    (FPtr_destroy)_updown_destroy,    /* ekGUI_TYPE_UPDOWN */
    (FPtr_destroy)_progress_destroy,  /* ekGUI_TYPE_PROGRESS */
    (FPtr_destroy)_textview_destroy,  /* ekGUI_TYPE_TEXTVIEW */
    (FPtr_destroy)NULL,               /* ekGUI_TYPE_TABLEVIEW */
    (FPtr_destroy)NULL,               /* ekGUI_TYPE_TREEVIEW */
    (FPtr_destroy)NULL,               /* ekGUI_TYPE_BOXVIEW */
    (FPtr_destroy)_splitview_destroy, /* ekGUI_TYPE_SPLITVIEW */
    (FPtr_destroy)_view_destroy,      /* ekGUI_TYPE_CUSTOMVIEW */
    (FPtr_destroy)_panel_destroy_all, /* ekGUI_TYPE_PANEL */
    (FPtr_destroy)NULL};              /* ekGUI_TYPE_LINE */

/*---------------------------------------------------------------------------*/

void _component_init(GuiComponent *component, const GuiCtx *context, const gui_type_t type, void **ositem)
{
    cassert_no_null(component);
    obj_init(&component->object);
    component->context = guictx_retain(context);
    component->type = type;
    component->panel = NULL;
    component->tag.tag_uint32 = UINT32_MAX;
    component->ositem = ptr_dget_no_null(ositem, void);
}

/*---------------------------------------------------------------------------*/

void _component_destroy_imp(GuiComponent *component)
{
    cassert_no_null(component);
    cassert_no_null(component->context);
    cassert_no_nullf(component->context->func_destroy[component->type]);
    component->context->func_destroy[component->type](&component->ositem);
}

/*---------------------------------------------------------------------------*/

void _component_destroy(GuiComponent **component)
{
    GuiCtx *context = NULL;
    cassert_no_null(component);
    cassert_no_null(*component);
    cassert((*component)->type < GUI_CONTEXT_NUM_COMPONENTS);
    cassert_no_nullf(i_FUNC_DESTROY[(*component)->type]);
    context = (*component)->context;
    i_FUNC_DESTROY[(*component)->type]((void **)component);
    guictx_release(&context);
}

/*---------------------------------------------------------------------------*/

void _component_attach_to_panel(GuiComponent *panel_component, GuiComponent *child_component)
{
    cassert_no_null(panel_component);
    cassert(panel_component->type == ekGUI_TYPE_PANEL);
    cassert_no_null(child_component);
    cassert_no_null(child_component->context);
    cassert_no_nullf(child_component->context->func_attach_to_panel[child_component->type]);
    cassert(child_component->panel == NULL);
    child_component->panel = (Panel *)panel_component;
    child_component->context->func_attach_to_panel[child_component->type](child_component->ositem, panel_component->ositem);
}

/*---------------------------------------------------------------------------*/

void _component_detach_from_panel(GuiComponent *panel_component, GuiComponent *child_component)
{
    cassert_no_null(panel_component);
    cassert(panel_component->type == ekGUI_TYPE_PANEL);
    cassert_no_null(child_component);
    cassert_no_null(child_component->context);
    cassert_no_nullf(child_component->context->func_detach_from_panel[child_component->type]);
    cassert(child_component->panel == (Panel *)panel_component);
    child_component->panel = NULL;
    child_component->context->func_detach_from_panel[child_component->type](child_component->ositem, panel_component->ositem);
}

/*---------------------------------------------------------------------------*/

void _component_set_parent_window(GuiComponent *component, Window *parent_window)
{
    Panel *panels[GUI_COMPONENT_MAX_PANELS];
    uint32_t j, num_panels;
    _component_panels(component, &num_panels, panels);
    for (j = 0; j < num_panels; ++j)
        _panel_window(panels[j], parent_window);
}

/*---------------------------------------------------------------------------*/

void _component_panels(GuiComponent *component, uint32_t *num_panels, Panel **panels)
{
    cassert_no_null(component);
    if (i_FUNC_PANELS[component->type] != NULL)
    {
        i_FUNC_PANELS[component->type](component, num_panels, panels);
    }
    else
    {
        cassert_no_null(num_panels);
        cassert_no_null(panels);
        *num_panels = 0;
        panels[0] = NULL;
    }
}

/*---------------------------------------------------------------------------*/

void _component_dimension(GuiComponent *component, const uint32_t i, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(component);
    cassert_no_nullf(i_FUNC_DIMENSION[component->type]);
    i_FUNC_DIMENSION[component->type](component, i, dim0, dim1);
}

/*---------------------------------------------------------------------------*/

void _component_expand(GuiComponent *component, const uint32_t di, const real32_t current_size, const real32_t required_size, real32_t *final_size)
{
    cassert_no_null(component);
    if (i_FUNC_EXPAND[component->type] != NULL)
    {
        i_FUNC_EXPAND[component->type](component, di, current_size, required_size, final_size);
    }
    else
    {
        cassert_no_null(final_size);
        *final_size = max_r32(required_size, 5.f);
    }
}

/*---------------------------------------------------------------------------*/

void _component_locate(GuiComponent *component)
{
    Panel *panels[GUI_COMPONENT_MAX_PANELS];
    uint32_t i, num_panels;
    _component_panels(component, &num_panels, panels);
    for (i = 0; i < num_panels; ++i)
        _panel_locate(panels[i]);
}

/*---------------------------------------------------------------------------*/

void _component_taborder(GuiComponent *component, Window *window)
{
    cassert_no_null(component);
    switch (component->type)
    {
    case ekGUI_TYPE_PANEL:
        _panel_taborder((Panel *)component, window);
        break;

    case ekGUI_TYPE_SPLITVIEW:
        _splitview_taborder((SplitView *)component, window);
        break;

    case ekGUI_TYPE_LABEL:
    case ekGUI_TYPE_BUTTON:
    case ekGUI_TYPE_POPUP:
    case ekGUI_TYPE_EDITBOX:
    case ekGUI_TYPE_COMBOBOX:
    case ekGUI_TYPE_SLIDER:
    case ekGUI_TYPE_UPDOWN:
    case ekGUI_TYPE_PROGRESS:
    case ekGUI_TYPE_TEXTVIEW:
    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_CUSTOMVIEW:
        _window_taborder(window, component->ositem);
        break;

    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void _component_visible(GuiComponent *component, const bool_t visible)
{
    cassert_no_null(component);
    cassert_no_null(component->context);
    cassert_no_nullf(component->context->func_set_visible[component->type]);
    component->context->func_set_visible[component->type](component->ositem, visible);
    if (i_FUNC_SET_VISIBLE[component->type] != NULL)
        i_FUNC_SET_VISIBLE[component->type](component, visible);
}

/*---------------------------------------------------------------------------*/

void _component_enabled(GuiComponent *component, const bool_t enabled)
{
    cassert_no_null(component);
    cassert_no_null(component->context);
    cassert_no_nullf(component->context->func_set_enabled[component->type]);
    component->context->func_set_enabled[component->type](component->ositem, enabled);
}

/*---------------------------------------------------------------------------*/

/*
bool_t component_is_attached(const GuiComponent *component);
bool_t component_is_attached(const GuiComponent *component)
{
    cassert_no_null(component);
    return (bool_t)(component->owner != NULL);
}
*/

/*---------------------------------------------------------------------------*/

void _component_get_origin(const GuiComponent *component, V2Df *origin)
{
    cassert_no_null(component);
    cassert_no_null(component->context);
    cassert_no_nullf(component->context->func_get_origin[component->type]);
    cassert_no_null(origin);
    origin->x = 1;
    origin->y = 1;
    component->context->func_get_origin[component->type](component->ositem, &origin->x, &origin->y);
}

/*---------------------------------------------------------------------------*/

void _component_get_size(const GuiComponent *component, S2Df *size)
{
    cassert_no_null(component);
    cassert_no_null(component->context);
    cassert_no_nullf(component->context->func_get_size[component->type]);
    cassert_no_null(size);
    component->context->func_get_size[component->type](component->ositem, &size->width, &size->height);
}

/*---------------------------------------------------------------------------*/

void _component_set_frame(GuiComponent *component, const V2Df *origin, const S2Df *size)
{
    cassert_no_null(component);
    cassert_no_null(component->context);
    cassert_no_nullf(component->context->func_set_frame[component->type]);
    cassert_no_null(origin);
    cassert_no_null(size);
    component->context->func_set_frame[component->type](component->ositem, origin->x, origin->y, size->width, size->height);
    if (i_FUNC_ON_RESIZE[component->type] != NULL)
        i_FUNC_ON_RESIZE[component->type](component, size);
}

/*---------------------------------------------------------------------------*/

void _component_set_tag(GuiComponent *component, const uint32_t tag)
{
    cassert_no_null(component);
    component->tag.tag_uint32 = tag;
}

/*---------------------------------------------------------------------------*/

uint32_t _component_get_tag(const GuiComponent *component)
{
    cassert_no_null(component);
    return component->tag.tag_uint32;
}

/*---------------------------------------------------------------------------*/

void _component_locale(GuiComponent *component)
{
    cassert_no_null(component);
    if (i_FUNC_LOCALE[component->type] != NULL)
        i_FUNC_LOCALE[component->type]((void *)component);
}

/*---------------------------------------------------------------------------*/

void _component_update_listener_imp(
    GuiComponent *component,
    Listener **listener,
    Listener *new_listener,
    FPtr_event_handler func_event_handler,
    FPtr_gctx_set_listener func_set_listener)
{
    Listener *renderable_listener = NULL;
    cassert_no_null(component);
    cassert_no_null(listener);
    cassert_no_nullf(func_set_listener);

    if (new_listener != NULL)
    {
        cassert_no_nullf(func_event_handler);
        renderable_listener = obj_listener_imp(component, func_event_handler);
    }

    func_set_listener(component->ositem, renderable_listener);
    listener_update(listener, new_listener);
}

/*---------------------------------------------------------------------------*/

const char_t *_component_type(const GuiComponent *component)
{
    cassert_no_null(component);
    switch (component->type)
    {
    case ekGUI_TYPE_LABEL:
        return "Label";
    case ekGUI_TYPE_BUTTON:
        return "Button";
    case ekGUI_TYPE_POPUP:
        return "PopUp";
    case ekGUI_TYPE_EDITBOX:
        return "Edit";
    case ekGUI_TYPE_COMBOBOX:
        return "Combo";
    case ekGUI_TYPE_SLIDER:
        return "Slider";
    case ekGUI_TYPE_UPDOWN:
        return "UpDown";
    case ekGUI_TYPE_PROGRESS:
        return "Progress";
    case ekGUI_TYPE_CUSTOMVIEW:
        return _view_subtype((View *)component);
    case ekGUI_TYPE_TEXTVIEW:
        return "TextView";
    case ekGUI_TYPE_TABLEVIEW:
        return "TableView";
    case ekGUI_TYPE_TREEVIEW:
        return "TreeView";
    case ekGUI_TYPE_BOXVIEW:
        return "BoxView";
    case ekGUI_TYPE_SPLITVIEW:
        return "SplitView";
    case ekGUI_TYPE_PANEL:
        return "Panel";
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_TOOLBAR:
    case ekGUI_TYPE_WINDOW:
        cassert_default();
    }

    return "";
}

/*---------------------------------------------------------------------------*/

void *_component_ositem(const GuiComponent *component)
{
    cassert_no_null(component);
    return component->ositem;
}

/*---------------------------------------------------------------------------*/

Cell *_component_cell(const GuiComponent *component)
{
    cassert_no_null(component);
    if (component->panel != NULL)
        return _panel_get_component_cell(component->panel, component);
    return NULL;
}

/*---------------------------------------------------------------------------*/

Window *_component_window(const GuiComponent *component)
{
    cassert_no_null(component);
    return _panel_get_window(component->panel);
}
