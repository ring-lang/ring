/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: component.inl
 *
 */

/* Gui Component */

#include "gui.ixx"

__EXTERN_C

void _component_init(GuiComponent *component, const GuiCtx *context, const gui_type_t type, void **ositem);

void _component_destroy_imp(GuiComponent *component);

void _component_destroy(GuiComponent **component);

void _component_attach_to_panel(GuiComponent *panel_component, GuiComponent *child_component);

void _component_detach_from_panel(GuiComponent *panel_component, GuiComponent *child_component);

void _component_set_parent_window(GuiComponent *component, Window *parent_window);

void _component_panels(GuiComponent *component, uint32_t *num_panels, Panel **panels);

void _component_dimension(GuiComponent *component, const uint32_t i, real32_t *dim0, real32_t *dim1);

void _component_expand(GuiComponent *component, const uint32_t di, const real32_t current_size, const real32_t required_size, real32_t *final_size);

void _component_locate(GuiComponent *component);

void _component_taborder(GuiComponent *component, Window *window);

void _component_visible(GuiComponent *component, const bool_t visible);

void _component_enabled(GuiComponent *component, const bool_t enabled);

void _component_get_origin(const GuiComponent *component, V2Df *origin);

void _component_get_size(const GuiComponent *component, S2Df *size);

void _component_set_frame(GuiComponent *component, const V2Df *origin, const S2Df *size);

void _component_set_tag(GuiComponent *component, const uint32_t tag);

uint32_t _component_get_tag(const GuiComponent *component);

void _component_locale(GuiComponent *component);

void _component_update_listener_imp(
    GuiComponent *component,
    Listener **listener,
    Listener *new_listener,
    FPtr_event_handler func_event_handler,
    FPtr_gctx_set_listener func_set_listener);

const char_t *_component_type(const GuiComponent *component);

void *_component_ositem(const GuiComponent *component);

Cell *_component_cell(const GuiComponent *component);

Window *_component_window(const GuiComponent *component);

__END_C

#define component_update_listener( \
    component, \
    listener, \
    new_listener, \
    func_event_handler, \
    func_set_listener, \
    type) \
    ( \
        (void)((type *)component == component), \
        FUNC_CHECK_EVENT_HANDLER(func_event_handler, type), \
        _component_update_listener_imp( \
            (GuiComponent *)component, \
            listener, \
            new_listener, \
            (FPtr_event_handler)func_event_handler, \
            func_set_listener))
