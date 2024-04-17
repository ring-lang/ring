/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: gui.h
 * https://nappgui.com/en/gui/gui.html
 *
 */

/* Graphics User Interface */

#include "gui.hxx"

__EXTERN_C

_gui_api void gui_start(void);

_gui_api void gui_finish(void);

_gui_api void gui_respack(FPtr_respack func_respack);

_gui_api void gui_language(const char_t *lang);

_gui_api const char_t *gui_text(const ResId id);

_gui_api const Image *gui_image(const ResId id);

_gui_api const byte_t *gui_file(const ResId id, uint32_t *size);

_gui_api bool_t gui_dark_mode(void);

_gui_api color_t gui_alt_color(const color_t light_color, const color_t dark_color);

_gui_api color_t gui_label_color(void);

_gui_api color_t gui_view_color(void);

_gui_api color_t gui_line_color(void);

_gui_api color_t gui_link_color(void);

_gui_api color_t gui_border_color(void);

_gui_api S2Df gui_resolution(void);

_gui_api V2Df gui_mouse_pos(void);

_gui_api void gui_update(void);

_gui_api void gui_OnThemeChanged(Listener *listener);

_gui_api void gui_update_transitions(const real64_t prtime, const real64_t crtime);

_gui_api void gui_OnNotification(Listener *listener);

_gui_api void gui_OnIdle(Listener *listener);

_gui_api uint32_t gui_info_window(const bool_t fatal, const char_t *msg, const char_t *caption, const char_t *detail, const char_t *file, const uint32_t line, const ArrPt(String) *buttons, const uint32_t defindex);

_gui_api void *evbind_object_imp(Event *e, const char_t *type);

_gui_api bool_t evbind_modify_imp(Event *e, const char_t *type, const uint16_t size, const char_t *mname, const char_t *mtype, const uint16_t moffset, const uint16_t msize);

__END_C

#define evbind_object(e, type) \
    (type *)evbind_object_imp(e, (const char_t *)#type)

#define evbind_modify(e, type, mtype, mname) \
    ( \
        CHECK_STRUCT_MEMBER_TYPE(type, mname, mtype), \
        evbind_modify_imp( \
            e, \
            (const char_t *)#type, \
            (uint16_t)sizeof(type), \
            (const char_t *)#mname, \
            (const char_t *)#mtype, \
            (uint16_t)STRUCT_MEMBER_OFFSET(type, mname), \
            (uint16_t)STRUCT_MEMBER_SIZE(type, mname)))
