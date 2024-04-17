/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osguictx.c
 *
 */

/* Native Gui Context */

#include "osguictx.h"
#include "oslabel.h"
#include "osbutton.h"
#include "ospopup.h"
#include "osedit.h"
#include "oscombo.h"
#include "osupdown.h"
#include "osslider.h"
#include "osprogress.h"
#include "osview.h"
#include "ostext.h"
#include "ossplit.h"
#include "ospanel.h"
#include "oswindow.h"
#include "osmenu.h"
#include "osmenuitem.h"
#include "oscomwin.h"
#include "osglobals.h"
#include "osdrawctrl.h"
#include "osgui.h"
#include <draw2d/guictx.h>

/*---------------------------------------------------------------------------*/

GuiCtx *osguictx(void)
{
    GuiCtx *context = guictx_create();

    guictx_append_label_manager(
        context,
        oslabel_create,
        oslabel_destroy,
        oslabel_OnClick,
        oslabel_OnEnter,
        oslabel_OnExit,
        oslabel_text,
        oslabel_font,
        oslabel_align,
        oslabel_ellipsis,
        oslabel_color,
        oslabel_bgcolor,
        oslabel_bounds,
        oslabel_attach,
        oslabel_detach,
        oslabel_visible,
        oslabel_enabled,
        oslabel_size,
        oslabel_origin,
        oslabel_frame,
        OSLabel, OSPanel, Font);

    guictx_append_button_manager(
        context,
        osbutton_create,
        osbutton_destroy,
        osbutton_OnClick,
        osbutton_text,
        osbutton_tooltip,
        osbutton_font,
        osbutton_align,
        osbutton_image,
        osbutton_state,
        osbutton_get_state,
        osbutton_vpadding,
        osbutton_bounds,
        osbutton_attach,
        osbutton_detach,
        osbutton_visible,
        osbutton_enabled,
        osbutton_size,
        osbutton_origin,
        osbutton_frame,
        OSButton, OSPanel, Image, Font);

    guictx_append_popup_manager(
        context,
        ospopup_create,
        ospopup_destroy,
        ospopup_OnSelect,
        ospopup_elem,
        ospopup_tooltip,
        ospopup_font,
        ospopup_list_height,
        ospopup_selected,
        ospopup_get_selected,
        ospopup_bounds,
        ospopup_attach,
        ospopup_detach,
        ospopup_visible,
        ospopup_enabled,
        ospopup_size,
        ospopup_origin,
        ospopup_frame,
        OSPopUp, OSPanel, Image, Font);

    guictx_append_edit_manager(
        context,
        osedit_create,
        osedit_destroy,
        osedit_OnFilter,
        osedit_OnChange,
        osedit_OnFocus,
        osedit_text,
        osedit_tooltip,
        osedit_font,
        osedit_align,
        osedit_passmode,
        osedit_editable,
        osedit_autoselect,
        osedit_select,
        osedit_color,
        osedit_bgcolor,
        osedit_vpadding,
        osedit_bounds,
        osedit_clipboard,
        osedit_attach,
        osedit_detach,
        osedit_visible,
        osedit_enabled,
        osedit_size,
        osedit_origin,
        osedit_frame,
        OSEdit, OSPanel, Font);

    guictx_append_combo_manager(
        context,
        oscombo_create,
        oscombo_destroy,
        oscombo_OnFilter,
        oscombo_OnChange,
        oscombo_OnFocus,
        oscombo_OnSelect,
        oscombo_text,
        oscombo_tooltip,
        oscombo_font,
        oscombo_align,
        oscombo_passmode,
        oscombo_color,
        oscombo_bgcolor,
        oscombo_elem,
        oscombo_selected,
        oscombo_get_selected,
        oscombo_bounds,
        oscombo_attach,
        oscombo_detach,
        oscombo_visible,
        oscombo_enabled,
        oscombo_size,
        oscombo_origin,
        oscombo_frame,
        OSCombo, OSPanel, Image, Font);

    guictx_append_updown_manager(
        context,
        osupdown_create,
        osupdown_destroy,
        osupdown_OnClick,
        osupdown_tooltip,
        osupdown_attach,
        osupdown_detach,
        osupdown_visible,
        osupdown_enabled,
        osupdown_size,
        osupdown_origin,
        osupdown_frame,
        OSUpDown, OSPanel);

    guictx_append_slider_manager(
        context,
        osslider_create,
        osslider_destroy,
        osslider_OnMoved,
        osslider_tooltip,
        osslider_tickmarks,
        osslider_get_position,
        osslider_position,
        osslider_bounds,
        osslider_attach,
        osslider_detach,
        osslider_visible,
        osslider_enabled,
        osslider_size,
        osslider_origin,
        osslider_frame,
        OSSlider, OSPanel);

    guictx_append_progress_manager(
        context,
        osprogress_create,
        osprogress_destroy,
        osprogress_position,
        osprogress_thickness,
        osprogress_attach,
        osprogress_detach,
        osprogress_visible,
        osprogress_enabled,
        osprogress_size,
        osprogress_origin,
        osprogress_frame,
        OSProgress, OSPanel);

    guictx_append_view_manager(
        context,
        osview_create,
        osview_destroy,
        osview_OnDraw,
        osview_OnOverlay,
        osview_OnEnter,
        osview_OnExit,
        osview_OnMoved,
        osview_OnDown,
        osview_OnUp,
        osview_OnClick,
        osview_OnDrag,
        osview_OnWheel,
        osview_OnKeyDown,
        osview_OnKeyUp,
        osview_OnFocus,
        osview_OnResignFocus,
        osview_OnAcceptFocus,
        osview_OnScroll,
        NULL, /* osview_OnTouchTap, */
        NULL, /* osview_OnTouchStartDrag, */
        NULL, /* osview_OnTouchDragging, */
        NULL, /* osview_OnTouchEndDrag, */
        NULL, /* osview_OnTouchStartPinch, */
        NULL, /* osview_OnTouchPinching, */
        NULL, /* osview_OnTouchEndPinch, */
        osview_scroll,
        osview_scroll_get,
        osview_scroller_size,
        osview_scroller_visible,
        osview_content_size,
        osview_scale_factor,
        osview_set_need_display,
        NULL, /* osview_set_drawable */
        osview_get_native_view,
        osview_attach,
        osview_detach,
        osview_visible,
        osview_enabled,
        osview_size,
        osview_origin,
        osview_frame,
        OSView, OSPanel);

    guictx_append_text_manager(
        context,
        ostext_create,
        ostext_destroy,
        ostext_OnFilter,
        ostext_OnFocus,
        ostext_insert_text,
        ostext_set_text,
        ostext_set_rtf,
        ostext_property,
        ostext_editable,
        ostext_get_text,
        ostext_scroller_visible,
        ostext_set_need_display,
        ostext_clipboard,
        ostext_attach,
        ostext_detach,
        ostext_visible,
        ostext_enabled,
        ostext_size,
        ostext_origin,
        ostext_frame,
        OSText, OSPanel);

    guictx_append_split_manager(
        context,
        ossplit_create,
        ossplit_destroy,
        ossplit_attach_control,
        ossplit_detach_control,
        ossplit_OnDrag,
        ossplit_track_area,
        ossplit_attach,
        ossplit_detach,
        ossplit_visible,
        ossplit_enabled,
        ossplit_size,
        ossplit_origin,
        ossplit_frame,
        OSSplit, OSPanel);

    guictx_append_panel_manager(
        context,
        ospanel_create,
        ospanel_destroy,
        ospanel_area,
        ospanel_scroller_size,
        ospanel_content_size,
        ospanel_display,
        ospanel_attach,
        ospanel_detach,
        ospanel_visible,
        ospanel_enabled,
        ospanel_size,
        ospanel_origin,
        ospanel_frame,
        OSPanel);

    guictx_append_window_manager(
        context,
        oswindow_create,
        oswindow_managed,
        oswindow_destroy,
        oswindow_OnMoved,
        oswindow_OnResize,
        oswindow_OnClose,
        oswindow_title,
        oswindow_edited,
        oswindow_movable,
        oswindow_z_order,
        oswindow_alpha,
        oswindow_enable_mouse_events,
        oswindow_hotkey,
        oswindow_taborder,
        oswindow_tabcycle,
        oswindow_tabstop,
        oswindow_focus,
        oswindow_get_focus,
        oswindow_info_focus,
        oswindow_attach_panel,
        oswindow_detach_panel,
        oswindow_attach_window,
        oswindow_detach_window,
        oswindow_launch,
        oswindow_hide,
        oswindow_launch_modal,
        oswindow_stop_modal,
        oswindow_get_origin,
        oswindow_origin,
        oswindow_get_size,
        oswindow_size,
        oswindow_set_default_pushbutton,
        oswindow_set_cursor,
        oswindow_property,
        OSWindow, OSPanel, OSButton);

    guictx_append_menu_manager(
        context,
        osmenu_create,
        osmenu_destroy,
        osmenu_add_item,
        osmenu_delete_item,
        osmenu_launch,
        osmenu_hide,
        OSMenu, OSMenuItem, OSWindow);

    guictx_append_menuitem_manager(
        context,
        osmenuitem_create,
        osmenuitem_destroy,
        osmenuitem_OnClick,
        osmenuitem_enabled,
        osmenuitem_visible,
        osmenuitem_text,
        osmenuitem_image,
        osmenuitem_key,
        osmenuitem_state,
        osmenuitem_submenu,
        osmenuitem_unset_submenu,
        OSMenuItem, OSMenu, Image);

    guictx_append_comwin_manager(
        context,
        oscomwin_file,
        oscomwin_color,
        OSWindow);

    guictx_append_globals_manager(
        context,
        osglobals_device,
        osglobals_color,
        osglobals_resolution,
        osglobals_mouse_position,
        osglobals_cursor,
        osglobals_cursor_destroy,
        osglobals_value,
        osglobals_transitions,
        osglobals_OnIdle,
        Image);

    guictx_append_drawctrl_manager(
        context,
        osdrawctrl_font,
        osdrawctrl_row_padding,
        osdrawctrl_check_width,
        osdrawctrl_check_height,
        osdrawctrl_multisel,
        osdrawctrl_clear,
        osdrawctrl_header,
        osdrawctrl_indicator,
        osdrawctrl_fill,
        osdrawctrl_focus,
        osdrawctrl_line,
        osdrawctrl_text,
        osdrawctrl_image,
        osdrawctrl_checkbox,
        osdrawctrl_uncheckbox,
        DCtx);

    return context;
}
