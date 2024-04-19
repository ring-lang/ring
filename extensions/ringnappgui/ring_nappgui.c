
#define _WINDOWS 1

#include "inet/inet.h"
#include "osapp/osmain.h"
#include "osgui/osgui.h"
#include "nappgui.h"

#define String RingString
#include "ring.h"

VM *pVM;

List *pEventsList;

void *i_create(void)
{
	ring_vm_runcode(pVM,"createGUI()");
	return NULL;
}

void i_destroy(void **app)
{
	return;
}

void i_OnEvent(void *app, Event *e)
{
	ring_vm_runcode(pVM,(char *) app);
}


RING_FUNC(ring_osmain) {

	pVM = (VM *) pPointer;

	pEventsList = ring_list_new(0);

	osmain_imp(pVM->pRingState->nArgc,pVM->pRingState->pArgv,
		   NULL,0,i_create,NULL,i_destroy,NULL);

}

RING_FUNC(ring_guievent) {

	Listener *pListener;
	char *cEvent;

	// Check parameters count
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	// Check parameters type
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	// Check string size
	cEvent = RING_API_GETSTRING(1);
	if ( RING_API_GETSTRINGSIZE(1) > 255 ) {
		RING_API_ERROR("The event code must be <= 255 characters");
		return;
	}

	ring_list_addstring(pEventsList,cEvent);
	void *object = (void *) ring_list_getstring(pEventsList,ring_list_getsize(pEventsList));

	pListener = listener_imp(object, (FPtr_event_handler) i_OnEvent);
	RING_API_RETCPOINTER(pListener,"Listener *");
}

RING_FUNC(ring_cleanguievents) {
	if (pEventsList == NULL) return ;
	pEventsList = ring_list_delete(pEventsList);
}

RING_FUNC(ring_get_ekgui_horizontal)
{
	RING_API_RETNUMBER(ekGUI_HORIZONTAL);
}

RING_FUNC(ring_get_ekgui_vertical)
{
	RING_API_RETNUMBER(ekGUI_VERTICAL);
}

RING_FUNC(ring_get_ekgui_off)
{
	RING_API_RETNUMBER(ekGUI_OFF);
}

RING_FUNC(ring_get_ekgui_on)
{
	RING_API_RETNUMBER(ekGUI_ON);
}

RING_FUNC(ring_get_ekgui_mixed)
{
	RING_API_RETNUMBER(ekGUI_MIXED);
}

RING_FUNC(ring_get_ekgui_mouse_left)
{
	RING_API_RETNUMBER(ekGUI_MOUSE_LEFT);
}

RING_FUNC(ring_get_ekgui_mouse_right)
{
	RING_API_RETNUMBER(ekGUI_MOUSE_RIGHT);
}

RING_FUNC(ring_get_ekgui_mouse_middle)
{
	RING_API_RETNUMBER(ekGUI_MOUSE_MIDDLE);
}

RING_FUNC(ring_get_ekgui_cursor_arrow)
{
	RING_API_RETNUMBER(ekGUI_CURSOR_ARROW);
}

RING_FUNC(ring_get_ekgui_cursor_hand)
{
	RING_API_RETNUMBER(ekGUI_CURSOR_HAND);
}

RING_FUNC(ring_get_ekgui_cursor_ibeam)
{
	RING_API_RETNUMBER(ekGUI_CURSOR_IBEAM);
}

RING_FUNC(ring_get_ekgui_cursor_cross)
{
	RING_API_RETNUMBER(ekGUI_CURSOR_CROSS);
}

RING_FUNC(ring_get_ekgui_cursor_sizewe)
{
	RING_API_RETNUMBER(ekGUI_CURSOR_SIZEWE);
}

RING_FUNC(ring_get_ekgui_cursor_sizens)
{
	RING_API_RETNUMBER(ekGUI_CURSOR_SIZENS);
}

RING_FUNC(ring_get_ekgui_cursor_user)
{
	RING_API_RETNUMBER(ekGUI_CURSOR_USER);
}

RING_FUNC(ring_get_ekgui_close_esc)
{
	RING_API_RETNUMBER(ekGUI_CLOSE_ESC);
}

RING_FUNC(ring_get_ekgui_close_intro)
{
	RING_API_RETNUMBER(ekGUI_CLOSE_INTRO);
}

RING_FUNC(ring_get_ekgui_close_button)
{
	RING_API_RETNUMBER(ekGUI_CLOSE_BUTTON);
}

RING_FUNC(ring_get_ekgui_close_deact)
{
	RING_API_RETNUMBER(ekGUI_CLOSE_DEACT);
}

RING_FUNC(ring_get_ekgui_scale_auto)
{
	RING_API_RETNUMBER(ekGUI_SCALE_AUTO);
}

RING_FUNC(ring_get_ekgui_scale_none)
{
	RING_API_RETNUMBER(ekGUI_SCALE_NONE);
}

RING_FUNC(ring_get_ekgui_scale_aspect)
{
	RING_API_RETNUMBER(ekGUI_SCALE_ASPECT);
}

RING_FUNC(ring_get_ekgui_scale_aspectdw)
{
	RING_API_RETNUMBER(ekGUI_SCALE_ASPECTDW);
}

RING_FUNC(ring_get_ekgui_scroll_begin)
{
	RING_API_RETNUMBER(ekGUI_SCROLL_BEGIN);
}

RING_FUNC(ring_get_ekgui_scroll_end)
{
	RING_API_RETNUMBER(ekGUI_SCROLL_END);
}

RING_FUNC(ring_get_ekgui_scroll_step_left)
{
	RING_API_RETNUMBER(ekGUI_SCROLL_STEP_LEFT);
}

RING_FUNC(ring_get_ekgui_scroll_step_right)
{
	RING_API_RETNUMBER(ekGUI_SCROLL_STEP_RIGHT);
}

RING_FUNC(ring_get_ekgui_scroll_page_left)
{
	RING_API_RETNUMBER(ekGUI_SCROLL_PAGE_LEFT);
}

RING_FUNC(ring_get_ekgui_scroll_page_right)
{
	RING_API_RETNUMBER(ekGUI_SCROLL_PAGE_RIGHT);
}

RING_FUNC(ring_get_ekgui_scroll_thumb)
{
	RING_API_RETNUMBER(ekGUI_SCROLL_THUMB);
}

RING_FUNC(ring_get_ekgui_focus_changed)
{
	RING_API_RETNUMBER(ekGUI_FOCUS_CHANGED);
}

RING_FUNC(ring_get_ekgui_focus_keep)
{
	RING_API_RETNUMBER(ekGUI_FOCUS_KEEP);
}

RING_FUNC(ring_get_ekgui_focus_no_next)
{
	RING_API_RETNUMBER(ekGUI_FOCUS_NO_NEXT);
}

RING_FUNC(ring_get_ekgui_focus_no_resign)
{
	RING_API_RETNUMBER(ekGUI_FOCUS_NO_RESIGN);
}

RING_FUNC(ring_get_ekgui_focus_no_accept)
{
	RING_API_RETNUMBER(ekGUI_FOCUS_NO_ACCEPT);
}

RING_FUNC(ring_get_ekgui_tab_key)
{
	RING_API_RETNUMBER(ekGUI_TAB_KEY);
}

RING_FUNC(ring_get_ekgui_tab_backkey)
{
	RING_API_RETNUMBER(ekGUI_TAB_BACKKEY);
}

RING_FUNC(ring_get_ekgui_tab_next)
{
	RING_API_RETNUMBER(ekGUI_TAB_NEXT);
}

RING_FUNC(ring_get_ekgui_tab_prev)
{
	RING_API_RETNUMBER(ekGUI_TAB_PREV);
}

RING_FUNC(ring_get_ekgui_tab_move)
{
	RING_API_RETNUMBER(ekGUI_TAB_MOVE);
}

RING_FUNC(ring_get_ekgui_tab_click)
{
	RING_API_RETNUMBER(ekGUI_TAB_CLICK);
}

RING_FUNC(ring_get_ekgui_event_label)
{
	RING_API_RETNUMBER(ekGUI_EVENT_LABEL);
}

RING_FUNC(ring_get_ekgui_event_button)
{
	RING_API_RETNUMBER(ekGUI_EVENT_BUTTON);
}

RING_FUNC(ring_get_ekgui_event_popup)
{
	RING_API_RETNUMBER(ekGUI_EVENT_POPUP);
}

RING_FUNC(ring_get_ekgui_event_listbox)
{
	RING_API_RETNUMBER(ekGUI_EVENT_LISTBOX);
}

RING_FUNC(ring_get_ekgui_event_slider)
{
	RING_API_RETNUMBER(ekGUI_EVENT_SLIDER);
}

RING_FUNC(ring_get_ekgui_event_updown)
{
	RING_API_RETNUMBER(ekGUI_EVENT_UPDOWN);
}

RING_FUNC(ring_get_ekgui_event_txtfilter)
{
	RING_API_RETNUMBER(ekGUI_EVENT_TXTFILTER);
}

RING_FUNC(ring_get_ekgui_event_txtchange)
{
	RING_API_RETNUMBER(ekGUI_EVENT_TXTCHANGE);
}

RING_FUNC(ring_get_ekgui_event_focus_resign)
{
	RING_API_RETNUMBER(ekGUI_EVENT_FOCUS_RESIGN);
}

RING_FUNC(ring_get_ekgui_event_focus_accept)
{
	RING_API_RETNUMBER(ekGUI_EVENT_FOCUS_ACCEPT);
}

RING_FUNC(ring_get_ekgui_event_focus)
{
	RING_API_RETNUMBER(ekGUI_EVENT_FOCUS);
}

RING_FUNC(ring_get_ekgui_event_menu)
{
	RING_API_RETNUMBER(ekGUI_EVENT_MENU);
}

RING_FUNC(ring_get_ekgui_event_draw)
{
	RING_API_RETNUMBER(ekGUI_EVENT_DRAW);
}

RING_FUNC(ring_get_ekgui_event_overlay)
{
	RING_API_RETNUMBER(ekGUI_EVENT_OVERLAY);
}

RING_FUNC(ring_get_ekgui_event_resize)
{
	RING_API_RETNUMBER(ekGUI_EVENT_RESIZE);
}

RING_FUNC(ring_get_ekgui_event_enter)
{
	RING_API_RETNUMBER(ekGUI_EVENT_ENTER);
}

RING_FUNC(ring_get_ekgui_event_exit)
{
	RING_API_RETNUMBER(ekGUI_EVENT_EXIT);
}

RING_FUNC(ring_get_ekgui_event_moved)
{
	RING_API_RETNUMBER(ekGUI_EVENT_MOVED);
}

RING_FUNC(ring_get_ekgui_event_down)
{
	RING_API_RETNUMBER(ekGUI_EVENT_DOWN);
}

RING_FUNC(ring_get_ekgui_event_up)
{
	RING_API_RETNUMBER(ekGUI_EVENT_UP);
}

RING_FUNC(ring_get_ekgui_event_click)
{
	RING_API_RETNUMBER(ekGUI_EVENT_CLICK);
}

RING_FUNC(ring_get_ekgui_event_drag)
{
	RING_API_RETNUMBER(ekGUI_EVENT_DRAG);
}

RING_FUNC(ring_get_ekgui_event_wheel)
{
	RING_API_RETNUMBER(ekGUI_EVENT_WHEEL);
}

RING_FUNC(ring_get_ekgui_event_keydown)
{
	RING_API_RETNUMBER(ekGUI_EVENT_KEYDOWN);
}

RING_FUNC(ring_get_ekgui_event_keyup)
{
	RING_API_RETNUMBER(ekGUI_EVENT_KEYUP);
}

RING_FUNC(ring_get_ekgui_event_scroll)
{
	RING_API_RETNUMBER(ekGUI_EVENT_SCROLL);
}

RING_FUNC(ring_get_ekgui_event_wnd_moved)
{
	RING_API_RETNUMBER(ekGUI_EVENT_WND_MOVED);
}

RING_FUNC(ring_get_ekgui_event_wnd_sizing)
{
	RING_API_RETNUMBER(ekGUI_EVENT_WND_SIZING);
}

RING_FUNC(ring_get_ekgui_event_wnd_size)
{
	RING_API_RETNUMBER(ekGUI_EVENT_WND_SIZE);
}

RING_FUNC(ring_get_ekgui_event_wnd_close)
{
	RING_API_RETNUMBER(ekGUI_EVENT_WND_CLOSE);
}

RING_FUNC(ring_get_ekgui_event_color)
{
	RING_API_RETNUMBER(ekGUI_EVENT_COLOR);
}

RING_FUNC(ring_get_ekgui_event_theme)
{
	RING_API_RETNUMBER(ekGUI_EVENT_THEME);
}

RING_FUNC(ring_get_ekgui_event_objchange)
{
	RING_API_RETNUMBER(ekGUI_EVENT_OBJCHANGE);
}

RING_FUNC(ring_get_ekgui_event_tbl_nrows)
{
	RING_API_RETNUMBER(ekGUI_EVENT_TBL_NROWS);
}

RING_FUNC(ring_get_ekgui_event_tbl_begin)
{
	RING_API_RETNUMBER(ekGUI_EVENT_TBL_BEGIN);
}

RING_FUNC(ring_get_ekgui_event_tbl_end)
{
	RING_API_RETNUMBER(ekGUI_EVENT_TBL_END);
}

RING_FUNC(ring_get_ekgui_event_tbl_cell)
{
	RING_API_RETNUMBER(ekGUI_EVENT_TBL_CELL);
}

RING_FUNC(ring_get_ekgui_event_tbl_sel)
{
	RING_API_RETNUMBER(ekGUI_EVENT_TBL_SEL);
}

RING_FUNC(ring_get_ekgui_event_tbl_headclick)
{
	RING_API_RETNUMBER(ekGUI_EVENT_TBL_HEADCLICK);
}

RING_FUNC(ring_get_ekgui_event_tbl_rowclick)
{
	RING_API_RETNUMBER(ekGUI_EVENT_TBL_ROWCLICK);
}

RING_FUNC(ring_get_ekgui_event_idle)
{
	RING_API_RETNUMBER(ekGUI_EVENT_IDLE);
}

RING_FUNC(ring_get_ekgui_type_label)
{
	RING_API_RETNUMBER(ekGUI_TYPE_LABEL);
}

RING_FUNC(ring_get_ekgui_type_button)
{
	RING_API_RETNUMBER(ekGUI_TYPE_BUTTON);
}

RING_FUNC(ring_get_ekgui_type_popup)
{
	RING_API_RETNUMBER(ekGUI_TYPE_POPUP);
}

RING_FUNC(ring_get_ekgui_type_editbox)
{
	RING_API_RETNUMBER(ekGUI_TYPE_EDITBOX);
}

RING_FUNC(ring_get_ekgui_type_combobox)
{
	RING_API_RETNUMBER(ekGUI_TYPE_COMBOBOX);
}

RING_FUNC(ring_get_ekgui_type_slider)
{
	RING_API_RETNUMBER(ekGUI_TYPE_SLIDER);
}

RING_FUNC(ring_get_ekgui_type_updown)
{
	RING_API_RETNUMBER(ekGUI_TYPE_UPDOWN);
}

RING_FUNC(ring_get_ekgui_type_progress)
{
	RING_API_RETNUMBER(ekGUI_TYPE_PROGRESS);
}

RING_FUNC(ring_get_ekgui_type_textview)
{
	RING_API_RETNUMBER(ekGUI_TYPE_TEXTVIEW);
}

RING_FUNC(ring_get_ekgui_type_tableview)
{
	RING_API_RETNUMBER(ekGUI_TYPE_TABLEVIEW);
}

RING_FUNC(ring_get_ekgui_type_treeview)
{
	RING_API_RETNUMBER(ekGUI_TYPE_TREEVIEW);
}

RING_FUNC(ring_get_ekgui_type_boxview)
{
	RING_API_RETNUMBER(ekGUI_TYPE_BOXVIEW);
}

RING_FUNC(ring_get_ekgui_type_splitview)
{
	RING_API_RETNUMBER(ekGUI_TYPE_SPLITVIEW);
}

RING_FUNC(ring_get_ekgui_type_customview)
{
	RING_API_RETNUMBER(ekGUI_TYPE_CUSTOMVIEW);
}

RING_FUNC(ring_get_ekgui_type_panel)
{
	RING_API_RETNUMBER(ekGUI_TYPE_PANEL);
}

RING_FUNC(ring_get_ekgui_type_line)
{
	RING_API_RETNUMBER(ekGUI_TYPE_LINE);
}

RING_FUNC(ring_get_ekgui_type_header)
{
	RING_API_RETNUMBER(ekGUI_TYPE_HEADER);
}

RING_FUNC(ring_get_ekgui_type_window)
{
	RING_API_RETNUMBER(ekGUI_TYPE_WINDOW);
}

RING_FUNC(ring_get_ekgui_type_toolbar)
{
	RING_API_RETNUMBER(ekGUI_TYPE_TOOLBAR);
}

RING_FUNC(ring_get_ekgui_size_mini)
{
	RING_API_RETNUMBER(ekGUI_SIZE_MINI);
}

RING_FUNC(ring_get_ekgui_size_small)
{
	RING_API_RETNUMBER(ekGUI_SIZE_SMALL);
}

RING_FUNC(ring_get_ekgui_size_regular)
{
	RING_API_RETNUMBER(ekGUI_SIZE_REGULAR);
}

RING_FUNC(ring_get_ekgui_role_main)
{
	RING_API_RETNUMBER(ekGUI_ROLE_MAIN);
}

RING_FUNC(ring_get_ekgui_role_overlay)
{
	RING_API_RETNUMBER(ekGUI_ROLE_OVERLAY);
}

RING_FUNC(ring_get_ekgui_role_modal)
{
	RING_API_RETNUMBER(ekGUI_ROLE_MODAL);
}

RING_FUNC(ring_get_ekgui_role_managed)
{
	RING_API_RETNUMBER(ekGUI_ROLE_MANAGED);
}

RING_FUNC(ring_get_ekgui_prop_resize)
{
	RING_API_RETNUMBER(ekGUI_PROP_RESIZE);
}

RING_FUNC(ring_get_ekgui_prop_children)
{
	RING_API_RETNUMBER(ekGUI_PROP_CHILDREN);
}

RING_FUNC(ring_get_ekgui_text_family)
{
	RING_API_RETNUMBER(ekGUI_TEXT_FAMILY);
}

RING_FUNC(ring_get_ekgui_text_units)
{
	RING_API_RETNUMBER(ekGUI_TEXT_UNITS);
}

RING_FUNC(ring_get_ekgui_text_size)
{
	RING_API_RETNUMBER(ekGUI_TEXT_SIZE);
}

RING_FUNC(ring_get_ekgui_text_style)
{
	RING_API_RETNUMBER(ekGUI_TEXT_STYLE);
}

RING_FUNC(ring_get_ekgui_text_color)
{
	RING_API_RETNUMBER(ekGUI_TEXT_COLOR);
}

RING_FUNC(ring_get_ekgui_text_bgcolor)
{
	RING_API_RETNUMBER(ekGUI_TEXT_BGCOLOR);
}

RING_FUNC(ring_get_ekgui_text_pgcolor)
{
	RING_API_RETNUMBER(ekGUI_TEXT_PGCOLOR);
}

RING_FUNC(ring_get_ekgui_text_paralign)
{
	RING_API_RETNUMBER(ekGUI_TEXT_PARALIGN);
}

RING_FUNC(ring_get_ekgui_text_lspacing)
{
	RING_API_RETNUMBER(ekGUI_TEXT_LSPACING);
}

RING_FUNC(ring_get_ekgui_text_bfparspace)
{
	RING_API_RETNUMBER(ekGUI_TEXT_BFPARSPACE);
}

RING_FUNC(ring_get_ekgui_text_afparspace)
{
	RING_API_RETNUMBER(ekGUI_TEXT_AFPARSPACE);
}

RING_FUNC(ring_get_ekgui_text_select)
{
	RING_API_RETNUMBER(ekGUI_TEXT_SELECT);
}

RING_FUNC(ring_get_ekgui_text_scroll)
{
	RING_API_RETNUMBER(ekGUI_TEXT_SCROLL);
}

RING_FUNC(ring_get_ekclipboard_copy)
{
	RING_API_RETNUMBER(ekCLIPBOARD_COPY);
}

RING_FUNC(ring_get_ekclipboard_cut)
{
	RING_API_RETNUMBER(ekCLIPBOARD_CUT);
}

RING_FUNC(ring_get_ekclipboard_paste)
{
	RING_API_RETNUMBER(ekCLIPBOARD_PASTE);
}

RING_FUNC(ring_get_eklabel_flag)
{
	RING_API_RETNUMBER(ekLABEL_FLAG);
}

RING_FUNC(ring_get_eklabel_single)
{
	RING_API_RETNUMBER(ekLABEL_SINGLE);
}

RING_FUNC(ring_get_eklabel_multi)
{
	RING_API_RETNUMBER(ekLABEL_MULTI);
}

RING_FUNC(ring_get_eklabel_type)
{
	RING_API_RETNUMBER(ekLABEL_TYPE);
}

RING_FUNC(ring_get_ekbutton_flag)
{
	RING_API_RETNUMBER(ekBUTTON_FLAG);
}

RING_FUNC(ring_get_ekbutton_push)
{
	RING_API_RETNUMBER(ekBUTTON_PUSH);
}

RING_FUNC(ring_get_ekbutton_check2)
{
	RING_API_RETNUMBER(ekBUTTON_CHECK2);
}

RING_FUNC(ring_get_ekbutton_check3)
{
	RING_API_RETNUMBER(ekBUTTON_CHECK3);
}

RING_FUNC(ring_get_ekbutton_radio)
{
	RING_API_RETNUMBER(ekBUTTON_RADIO);
}

RING_FUNC(ring_get_ekbutton_flat)
{
	RING_API_RETNUMBER(ekBUTTON_FLAT);
}

RING_FUNC(ring_get_ekbutton_flatgle)
{
	RING_API_RETNUMBER(ekBUTTON_FLATGLE);
}

RING_FUNC(ring_get_ekbutton_header)
{
	RING_API_RETNUMBER(ekBUTTON_HEADER);
}

RING_FUNC(ring_get_ekbutton_type)
{
	RING_API_RETNUMBER(ekBUTTON_TYPE);
}

RING_FUNC(ring_get_ekpopup_flag)
{
	RING_API_RETNUMBER(ekPOPUP_FLAG);
}

RING_FUNC(ring_get_ekedit_flag)
{
	RING_API_RETNUMBER(ekEDIT_FLAG);
}

RING_FUNC(ring_get_ekedit_single)
{
	RING_API_RETNUMBER(ekEDIT_SINGLE);
}

RING_FUNC(ring_get_ekedit_multi)
{
	RING_API_RETNUMBER(ekEDIT_MULTI);
}

RING_FUNC(ring_get_ekedit_type)
{
	RING_API_RETNUMBER(ekEDIT_TYPE);
}

RING_FUNC(ring_get_ekedit_autosel)
{
	RING_API_RETNUMBER(ekEDIT_AUTOSEL);
}

RING_FUNC(ring_get_ekcombo_flag)
{
	RING_API_RETNUMBER(ekCOMBO_FLAG);
}

RING_FUNC(ring_get_ekslider_flag)
{
	RING_API_RETNUMBER(ekSLIDER_FLAG);
}

RING_FUNC(ring_get_ekslider_horz)
{
	RING_API_RETNUMBER(ekSLIDER_HORZ);
}

RING_FUNC(ring_get_ekslider_vert)
{
	RING_API_RETNUMBER(ekSLIDER_VERT);
}

RING_FUNC(ring_get_ekslider_type)
{
	RING_API_RETNUMBER(ekSLIDER_TYPE);
}

RING_FUNC(ring_get_ekupdown_flag)
{
	RING_API_RETNUMBER(ekUPDOWN_FLAG);
}

RING_FUNC(ring_get_ekprogress_flag)
{
	RING_API_RETNUMBER(ekPROGRESS_FLAG);
}

RING_FUNC(ring_get_ekprogress_horz)
{
	RING_API_RETNUMBER(ekPROGRESS_HORZ);
}

RING_FUNC(ring_get_ekprogress_vert)
{
	RING_API_RETNUMBER(ekPROGRESS_VERT);
}

RING_FUNC(ring_get_ekprogress_type)
{
	RING_API_RETNUMBER(ekPROGRESS_TYPE);
}

RING_FUNC(ring_get_ekview_opengl)
{
	RING_API_RETNUMBER(ekVIEW_OPENGL);
}

RING_FUNC(ring_get_ekview_hscroll)
{
	RING_API_RETNUMBER(ekVIEW_HSCROLL);
}

RING_FUNC(ring_get_ekview_vscroll)
{
	RING_API_RETNUMBER(ekVIEW_VSCROLL);
}

RING_FUNC(ring_get_ekview_border)
{
	RING_API_RETNUMBER(ekVIEW_BORDER);
}

RING_FUNC(ring_get_ekview_noerase)
{
	RING_API_RETNUMBER(ekVIEW_NOERASE);
}

RING_FUNC(ring_get_ekview_control)
{
	RING_API_RETNUMBER(ekVIEW_CONTROL);
}

RING_FUNC(ring_get_ektext_flag)
{
	RING_API_RETNUMBER(ekTEXT_FLAG);
}

RING_FUNC(ring_get_ektable_flag)
{
	RING_API_RETNUMBER(ekTABLE_FLAG);
}

RING_FUNC(ring_get_ektable_text)
{
	RING_API_RETNUMBER(ekTABLE_TEXT);
}

RING_FUNC(ring_get_ektable_icon16)
{
	RING_API_RETNUMBER(ekTABLE_ICON16);
}

RING_FUNC(ring_get_ektable_edit)
{
	RING_API_RETNUMBER(ekTABLE_EDIT);
}

RING_FUNC(ring_get_ektable_combo)
{
	RING_API_RETNUMBER(ekTABLE_COMBO);
}

RING_FUNC(ring_get_ektable_popup)
{
	RING_API_RETNUMBER(ekTABLE_POPUP);
}

RING_FUNC(ring_get_ektable_radio)
{
	RING_API_RETNUMBER(ekTABLE_RADIO);
}

RING_FUNC(ring_get_ektable_check)
{
	RING_API_RETNUMBER(ekTABLE_CHECK);
}

RING_FUNC(ring_get_ektable_tooltip)
{
	RING_API_RETNUMBER(ekTABLE_TOOLTIP);
}

RING_FUNC(ring_get_ektable_bgcolor)
{
	RING_API_RETNUMBER(ekTABLE_BGCOLOR);
}

RING_FUNC(ring_get_ektable_rowalt)
{
	RING_API_RETNUMBER(ekTABLE_ROWALT);
}

RING_FUNC(ring_get_ektable_rowpresel)
{
	RING_API_RETNUMBER(ekTABLE_ROWPRESEL);
}

RING_FUNC(ring_get_eksplit_flag)
{
	RING_API_RETNUMBER(ekSPLIT_FLAG);
}

RING_FUNC(ring_get_eksplit_vert)
{
	RING_API_RETNUMBER(ekSPLIT_VERT);
}

RING_FUNC(ring_get_eksplit_horz)
{
	RING_API_RETNUMBER(ekSPLIT_HORZ);
}

RING_FUNC(ring_get_eksplit_type)
{
	RING_API_RETNUMBER(ekSPLIT_TYPE);
}

RING_FUNC(ring_get_eksplit_prop)
{
	RING_API_RETNUMBER(ekSPLIT_PROP);
}

RING_FUNC(ring_get_eksplit_left)
{
	RING_API_RETNUMBER(ekSPLIT_LEFT);
}

RING_FUNC(ring_get_eksplit_right)
{
	RING_API_RETNUMBER(ekSPLIT_RIGHT);
}

RING_FUNC(ring_get_ekwindow_flag)
{
	RING_API_RETNUMBER(ekWINDOW_FLAG);
}

RING_FUNC(ring_get_ekwindow_edge)
{
	RING_API_RETNUMBER(ekWINDOW_EDGE);
}

RING_FUNC(ring_get_ekwindow_title)
{
	RING_API_RETNUMBER(ekWINDOW_TITLE);
}

RING_FUNC(ring_get_ekwindow_max)
{
	RING_API_RETNUMBER(ekWINDOW_MAX);
}

RING_FUNC(ring_get_ekwindow_min)
{
	RING_API_RETNUMBER(ekWINDOW_MIN);
}

RING_FUNC(ring_get_ekwindow_close)
{
	RING_API_RETNUMBER(ekWINDOW_CLOSE);
}

RING_FUNC(ring_get_ekwindow_resize)
{
	RING_API_RETNUMBER(ekWINDOW_RESIZE);
}

RING_FUNC(ring_get_ekwindow_return)
{
	RING_API_RETNUMBER(ekWINDOW_RETURN);
}

RING_FUNC(ring_get_ekwindow_esc)
{
	RING_API_RETNUMBER(ekWINDOW_ESC);
}

RING_FUNC(ring_get_ekwindow_offscreen)
{
	RING_API_RETNUMBER(ekWINDOW_OFFSCREEN);
}

RING_FUNC(ring_get_ekwindow_modal_nohide)
{
	RING_API_RETNUMBER(ekWINDOW_MODAL_NOHIDE);
}

RING_FUNC(ring_get_ekwindow_std)
{
	RING_API_RETNUMBER(ekWINDOW_STD);
}

RING_FUNC(ring_get_ekwindow_stdres)
{
	RING_API_RETNUMBER(ekWINDOW_STDRES);
}

RING_FUNC(ring_get_ekmenu_flag)
{
	RING_API_RETNUMBER(ekMENU_FLAG);
}

RING_FUNC(ring_get_ekmenu_item)
{
	RING_API_RETNUMBER(ekMENU_ITEM);
}

RING_FUNC(ring_get_ekmenu_separator)
{
	RING_API_RETNUMBER(ekMENU_SEPARATOR);
}

RING_FUNC(ring_get_ekctrl_state_normal)
{
	RING_API_RETNUMBER(ekCTRL_STATE_NORMAL);
}

RING_FUNC(ring_get_ekctrl_state_hot)
{
	RING_API_RETNUMBER(ekCTRL_STATE_HOT);
}

RING_FUNC(ring_get_ekctrl_state_pressed)
{
	RING_API_RETNUMBER(ekCTRL_STATE_PRESSED);
}

RING_FUNC(ring_get_ekctrl_state_bknormal)
{
	RING_API_RETNUMBER(ekCTRL_STATE_BKNORMAL);
}

RING_FUNC(ring_get_ekctrl_state_bkhot)
{
	RING_API_RETNUMBER(ekCTRL_STATE_BKHOT);
}

RING_FUNC(ring_get_ekctrl_state_bkpressed)
{
	RING_API_RETNUMBER(ekCTRL_STATE_BKPRESSED);
}

RING_FUNC(ring_get_ekctrl_state_disabled)
{
	RING_API_RETNUMBER(ekCTRL_STATE_DISABLED);
}

RING_FUNC(ring_get_ekctrl_msel_no)
{
	RING_API_RETNUMBER(ekCTRL_MSEL_NO);
}

RING_FUNC(ring_get_ekctrl_msel_single)
{
	RING_API_RETNUMBER(ekCTRL_MSEL_SINGLE);
}

RING_FUNC(ring_get_ekctrl_msel_burst)
{
	RING_API_RETNUMBER(ekCTRL_MSEL_BURST);
}

RING_FUNC(ring_get_ekctrl_op_add)
{
	RING_API_RETNUMBER(ekCTRL_OP_ADD);
}

RING_FUNC(ring_get_ekctrl_op_del)
{
	RING_API_RETNUMBER(ekCTRL_OP_DEL);
}

RING_FUNC(ring_get_ekctrl_op_ins)
{
	RING_API_RETNUMBER(ekCTRL_OP_INS);
}

RING_FUNC(ring_get_ekctrl_op_set)
{
	RING_API_RETNUMBER(ekCTRL_OP_SET);
}

RING_FUNC(ring_get_eksyscolor_darkmode)
{
	RING_API_RETNUMBER(ekSYSCOLOR_DARKMODE);
}

RING_FUNC(ring_get_eksyscolor_label)
{
	RING_API_RETNUMBER(ekSYSCOLOR_LABEL);
}

RING_FUNC(ring_get_eksyscolor_view)
{
	RING_API_RETNUMBER(ekSYSCOLOR_VIEW);
}

RING_FUNC(ring_get_eksyscolor_line)
{
	RING_API_RETNUMBER(ekSYSCOLOR_LINE);
}

RING_FUNC(ring_get_eksyscolor_link)
{
	RING_API_RETNUMBER(ekSYSCOLOR_LINK);
}

RING_FUNC(ring_get_eksyscolor_border)
{
	RING_API_RETNUMBER(ekSYSCOLOR_BORDER);
}


RING_FUNC(ring_unicode_convers)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_convers(RING_API_GETSTRING(1),RING_API_GETSTRING(2),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t"),* (const unicode_t  *) RING_API_GETCPOINTER(4,"const unicode_t"), (const uint32_t ) RING_API_GETNUMBER(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"unicode_t"));
}


RING_FUNC(ring_unicode_convers_n)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_convers_n(RING_API_GETSTRING(1),RING_API_GETSTRING(2),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t"),* (const unicode_t  *) RING_API_GETCPOINTER(4,"const unicode_t"), (const uint32_t ) RING_API_GETNUMBER(5), (const uint32_t ) RING_API_GETNUMBER(6)));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"unicode_t"));
}


RING_FUNC(ring_unicode_convers_nbytes)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_convers_nbytes(RING_API_GETSTRING(1),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t"),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
}


RING_FUNC(ring_unicode_nbytes)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_nbytes(RING_API_GETSTRING(1),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_nchars)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_nchars(RING_API_GETSTRING(1),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_to_u32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_to_u32(RING_API_GETSTRING(1),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_to_u32b)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_to_u32b(RING_API_GETSTRING(1),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t"),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_to_char)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_to_char( (const uint32_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
}


RING_FUNC(ring_unicode_valid_str)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_valid_str(RING_API_GETSTRING(1),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_valid_str_n)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_valid_str_n(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
}


RING_FUNC(ring_unicode_valid)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_valid( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_next)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(unicode_next(RING_API_GETSTRING(1),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_back)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(unicode_back(RING_API_GETSTRING(1),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_isascii)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_isascii( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_isalnum)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_isalnum( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_isalpha)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_isalpha( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_iscntrl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_iscntrl( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_isdigit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_isdigit( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_isgraph)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_isgraph( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_isprint)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_isprint( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_ispunct)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_ispunct( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_isspace)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_isspace( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_isxdigit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_isxdigit( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_islower)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_islower( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_isupper)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_isupper( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_tolower)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_tolower( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_unicode_toupper)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_toupper( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_min_u32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(min_u32( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_min_r32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(min_r32( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_min_r64)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(min_r64( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_max_u32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(max_u32( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_max_r32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(max_r32( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_max_r64)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(max_r64( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_abs_r32)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(abs_r32( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_to_u8)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(to_u8( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_sewer_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	sewer_start();
}


RING_FUNC(ring_sewer_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	sewer_finish();
}


RING_FUNC(ring_sewer_nappgui_major)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(sewer_nappgui_major());
}


RING_FUNC(ring_sewer_nappgui_minor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(sewer_nappgui_minor());
}


RING_FUNC(ring_sewer_nappgui_patch)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(sewer_nappgui_patch());
}


RING_FUNC(ring_sewer_nappgui_build)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(sewer_nappgui_build());
}


RING_FUNC(ring_sewer_nappgui_version)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(sewer_nappgui_version( (const bool_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_ptr_dget_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ptr_dget_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void")),"void");
}


RING_FUNC(ring_ptr_dget_no_null_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ptr_dget_no_null_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void")),"void");
}


RING_FUNC(ring_ptr_destopt_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ptr_destopt_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void"),* (FPtr_destroy  *) RING_API_GETCPOINTER(2,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_destroy"));
}


RING_FUNC(ring_ptr_copyopt_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ptr_copyopt_imp((void *) RING_API_GETCPOINTER(1,"void"),* (FPtr_copy  *) RING_API_GETCPOINTER(2,"FPtr_copy")),"void");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_copy"));
}


RING_FUNC(ring_cassert_set_func)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_set_func((void *) RING_API_GETCPOINTER(1,"void"),* (FPtr_assert  *) RING_API_GETCPOINTER(2,"FPtr_assert"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_assert"));
}


RING_FUNC(ring_cassert_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_imp( (bool_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_cassert_fatal_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_fatal_imp( (bool_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_cassert_no_null_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_no_null_imp((void *) RING_API_GETCPOINTER(1,"void"),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_cassert_default_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_default_imp(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_bstd_vsprintf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bstd_vsprintf(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3),* (va_list  *) RING_API_GETCPOINTER(4,"va_list")));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"va_list"));
}


RING_FUNC(ring_bstd_writef)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bstd_writef(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_bstd_ewritef)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bstd_ewritef(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_bstd_read)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bstd_read(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t")));
}


RING_FUNC(ring_bstd_write)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bstd_write(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t")));
}


RING_FUNC(ring_bstd_ewrite)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bstd_ewrite(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t")));
}


RING_FUNC(ring_bmem_aligned_malloc)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(bmem_aligned_malloc( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmem_aligned_realloc)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(bmem_aligned_realloc(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_bmem_free)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_free(RING_API_GETSTRING(1));
}


RING_FUNC(ring_bmem_set1)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set1(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),* (const byte_t  *) RING_API_GETCPOINTER(3,"const byte_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"byte_t"));
}


RING_FUNC(ring_bmem_set4)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set4(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_bmem_set8)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set8(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_bmem_set16)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set16(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_bmem_cmp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmem_cmp(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_bmem_is_zero)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmem_is_zero(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmem_set_zero)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set_zero(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_bmem_copy)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_copy(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_bmem_move)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_move(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_bmem_overlaps)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmem_overlaps(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_bmem_rev)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_bmem_rev2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev2(RING_API_GETSTRING(1));
}


RING_FUNC(ring_bmem_rev4)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev4(RING_API_GETSTRING(1));
}


RING_FUNC(ring_bmem_rev8)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev8(RING_API_GETSTRING(1));
}


RING_FUNC(ring_bmem_revcopy)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_revcopy(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_bmem_rev_elems_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev_elems_imp(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_bmem_swap)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_swap(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_bmem_shuffle)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_shuffle(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_bmath_cosf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_cosf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_cosd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_cosd( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_sinf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_sinf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_sind)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_sind( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_tanf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_tanf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_tand)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_tand( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_acosf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_acosf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_acosd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_acosd( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_asinf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_asinf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_asind)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_asind( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_atan2f)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_atan2f( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_atan2d)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_atan2d( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_norm_anglef)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_norm_anglef( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_norm_angled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_norm_angled( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_sqrtf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_sqrtf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_sqrtd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_sqrtd( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_isqrtf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_isqrtf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_isqrtd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_isqrtd( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_logf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_logf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_logd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_logd( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_log10f)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_log10f( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_log10d)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_log10d( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_expf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_expf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_expd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_expd( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_powf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_powf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_powd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_powd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_absf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_absf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_absd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_absd( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_maxf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_maxf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_maxd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_maxd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_minf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_minf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_mind)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_mind( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_clampf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_clampf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_bmath_clampd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_clampd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_bmath_modf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_modf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_modd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_modd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_modff)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_modff( (const real32_t ) RING_API_GETNUMBER(1),(real32_t *) RING_API_GETCPOINTER(2,"real32_t")));
}


RING_FUNC(ring_bmath_modfd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_modfd( (const real64_t ) RING_API_GETNUMBER(1),(real64_t *) RING_API_GETCPOINTER(2,"real64_t")));
}


RING_FUNC(ring_bmath_precf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_precf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_precd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_precd( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_roundf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_roundf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_roundd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_roundd( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_round_stepf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_round_stepf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_round_stepd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_round_stepd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_floorf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_floorf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_floord)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_floord( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_ceilf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_ceilf( (const real32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_ceild)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_ceild( (const real64_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bmath_rand_seed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmath_rand_seed( (const uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_bmath_randf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_randf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_randd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_randd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_randi)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_randi( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bmath_rand_env)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bmath_rand_env( (const uint32_t ) RING_API_GETNUMBER(1)),"REnv");
}


RING_FUNC(ring_bmath_rand_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmath_rand_destroy((REnv **) RING_API_GETCPOINTER2POINTER(1,"REnv"));
}


RING_FUNC(ring_bmath_rand_mtf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_rand_mtf((REnv *) RING_API_GETCPOINTER(1,"REnv"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_bmath_rand_mtd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_rand_mtd((REnv *) RING_API_GETCPOINTER(1,"REnv"), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_bmath_rand_mti)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_rand_mti((REnv *) RING_API_GETCPOINTER(1,"REnv"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_blib_strlen)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strlen(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_blib_strstr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(blib_strstr(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_blib_strcpy)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	blib_strcpy(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_blib_strncpy)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	blib_strncpy(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_blib_strcat)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	blib_strcat(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_blib_strcmp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strcmp(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_blib_strncmp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strncmp(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_blib_strftime)
{
	if ( RING_API_PARACOUNT != 10 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strftime(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (const int16_t ) RING_API_GETNUMBER(4), (const uint8_t ) RING_API_GETNUMBER(5), (const uint8_t ) RING_API_GETNUMBER(6), (const uint8_t ) RING_API_GETNUMBER(7), (const uint8_t ) RING_API_GETNUMBER(8), (const uint8_t ) RING_API_GETNUMBER(9), (const uint8_t ) RING_API_GETNUMBER(10)));
}


RING_FUNC(ring_blib_strtol)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strtol(RING_API_GETSTRING(1),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"), (uint32_t ) RING_API_GETNUMBER(3),(bool_t *) RING_API_GETCPOINTER(4,"bool_t")));
}


RING_FUNC(ring_blib_strtoul)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strtoul(RING_API_GETSTRING(1),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"), (uint32_t ) RING_API_GETNUMBER(3),(bool_t *) RING_API_GETCPOINTER(4,"bool_t")));
}


RING_FUNC(ring_blib_strtof)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strtof(RING_API_GETSTRING(1),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_blib_strtod)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strtod(RING_API_GETSTRING(1),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_blib_qsort)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	blib_qsort(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3),* (FPtr_compare  *) RING_API_GETCPOINTER(4,"FPtr_compare"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_compare"));
}


RING_FUNC(ring_blib_qsort_ex)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	blib_qsort_ex(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3),* (FPtr_compare_ex  *) RING_API_GETCPOINTER(4,"FPtr_compare_ex"),RING_API_GETSTRING(5));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_compare_ex"));
}


RING_FUNC(ring_blib_bsearch)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_bsearch(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4),* (FPtr_compare  *) RING_API_GETCPOINTER(5,"FPtr_compare"),(uint32_t *) RING_API_GETCPOINTER(6,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"FPtr_compare"));
}


RING_FUNC(ring_blib_bsearch_ex)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_bsearch_ex(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4),* (FPtr_compare_ex  *) RING_API_GETCPOINTER(5,"FPtr_compare_ex"),RING_API_GETSTRING(6),(uint32_t *) RING_API_GETCPOINTER(7,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"FPtr_compare_ex"));
}


RING_FUNC(ring_blib_getenv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(blib_getenv(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_blib_abort)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	blib_abort();
}


RING_FUNC(ring_blib_exit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	blib_exit( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_blib_debug_break)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	blib_debug_break();
}


RING_FUNC(ring_oswindow_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(oswindow_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSWindow");
}


RING_FUNC(ring_oswindow_managed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(oswindow_managed((void *) RING_API_GETCPOINTER(1,"void")),"OSWindow");
}


RING_FUNC(ring_oswindow_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_destroy((OSWindow **) RING_API_GETCPOINTER2POINTER(1,"OSWindow"));
}


RING_FUNC(ring_oswindow_OnMoved)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_OnMoved((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oswindow_OnResize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_OnResize((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oswindow_OnClose)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_OnClose((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oswindow_title)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_title((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_oswindow_edited)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_edited((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oswindow_movable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_movable((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oswindow_z_order)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_z_order((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_alpha)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_alpha((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oswindow_enable_mouse_events)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_enable_mouse_events((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oswindow_hotkey)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_hotkey((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"), (const uint32_t ) RING_API_GETNUMBER(3),(Listener *) RING_API_GETCPOINTER(4,"Listener"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
}


RING_FUNC(ring_oswindow_taborder)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_taborder((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSControl *) RING_API_GETCPOINTER(2,"OSControl"));
}


RING_FUNC(ring_oswindow_tabcycle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_tabcycle((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oswindow_tabstop)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		gui_focus_t *pValue ; 
		pValue = (gui_focus_t *) RING_API_MALLOC(sizeof(gui_focus_t)) ;
		*pValue = oswindow_tabstop((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"), (const bool_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_oswindow_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		gui_focus_t *pValue ; 
		pValue = (gui_focus_t *) RING_API_MALLOC(sizeof(gui_focus_t)) ;
		*pValue = oswindow_focus((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSControl *) RING_API_GETCPOINTER(2,"OSControl"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_oswindow_get_focus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(oswindow_get_focus((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow")),"OSControl");
}


RING_FUNC(ring_oswindow_info_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		gui_tab_t *pValue ; 
		pValue = (gui_tab_t *) RING_API_MALLOC(sizeof(gui_tab_t)) ;
		*pValue = oswindow_info_focus((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(void **) RING_API_GETCPOINTER2POINTER(2,"void"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_tab_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_oswindow_attach_panel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_attach_panel((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oswindow_detach_panel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_detach_panel((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oswindow_attach_window)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_attach_window((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_detach_window)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_detach_window((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_launch)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_launch((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_hide)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_hide((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_launch_modal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(oswindow_launch_modal((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow")));
}


RING_FUNC(ring_oswindow_stop_modal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_stop_modal((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oswindow_get_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_get_origin((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oswindow_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_origin((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_oswindow_get_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_get_size((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oswindow_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_size((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_oswindow_set_default_pushbutton)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_set_default_pushbutton((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSButton *) RING_API_GETCPOINTER(2,"OSButton"));
}


RING_FUNC(ring_oswindow_set_cursor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_set_cursor((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(Cursor *) RING_API_GETCPOINTER(2,"Cursor"));
}


RING_FUNC(ring_oswindow_property)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_property((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const gui_prop_t  *) RING_API_GETCPOINTER(2,"const gui_prop_t"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_prop_t"));
}


RING_FUNC(ring_osview_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osview_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSView");
}


RING_FUNC(ring_osview_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_destroy((OSView **) RING_API_GETCPOINTER2POINTER(1,"OSView"));
}


RING_FUNC(ring_osview_OnDraw)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnDraw((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnOverlay)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnOverlay((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnEnter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnEnter((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnExit)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnExit((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnMoved)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnMoved((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnDown)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnDown((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnUp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnUp((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnClick((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnDrag)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnDrag((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnWheel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnWheel((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnKeyDown)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnKeyDown((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnKeyUp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnKeyUp((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnFocus((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnResignFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnResignFocus((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnAcceptFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnAcceptFocus((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnScroll)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_OnScroll((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_scroll)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_scroll((OSView *) RING_API_GETCPOINTER(1,"OSView"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_osview_scroll_get)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_scroll_get((OSView *) RING_API_GETCPOINTER(1,"OSView"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osview_scroller_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_scroller_size((OSView *) RING_API_GETCPOINTER(1,"OSView"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osview_scroller_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_scroller_visible((OSView *) RING_API_GETCPOINTER(1,"OSView"), (const bool_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_osview_content_size)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_content_size((OSView *) RING_API_GETCPOINTER(1,"OSView"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osview_scale_factor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(osview_scale_factor((OSView *) RING_API_GETCPOINTER(1,"OSView")));
}


RING_FUNC(ring_osview_set_need_display)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_set_need_display((OSView *) RING_API_GETCPOINTER(1,"OSView"));
}


RING_FUNC(ring_osview_get_native_view)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osview_get_native_view((OSView *) RING_API_GETCPOINTER(1,"OSView")),"void");
}


RING_FUNC(ring_osview_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_attach((OSView *) RING_API_GETCPOINTER(1,"OSView"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osview_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_detach((OSView *) RING_API_GETCPOINTER(1,"OSView"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osview_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_visible((OSView *) RING_API_GETCPOINTER(1,"OSView"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osview_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_enabled((OSView *) RING_API_GETCPOINTER(1,"OSView"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osview_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_size((OSView *) RING_API_GETCPOINTER(1,"OSView"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osview_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_origin((OSView *) RING_API_GETCPOINTER(1,"OSView"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osview_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_frame((OSView *) RING_API_GETCPOINTER(1,"OSView"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osupdown_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osupdown_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSUpDown");
}


RING_FUNC(ring_osupdown_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_destroy((OSUpDown **) RING_API_GETCPOINTER2POINTER(1,"OSUpDown"));
}


RING_FUNC(ring_osupdown_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_OnClick((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osupdown_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_tooltip((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_osupdown_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_attach((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osupdown_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_detach((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osupdown_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_visible((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osupdown_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_enabled((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osupdown_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_size((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osupdown_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_origin((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osupdown_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_frame((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_ostext_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ostext_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSText");
}


RING_FUNC(ring_ostext_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_destroy((OSText **) RING_API_GETCPOINTER2POINTER(1,"OSText"));
}


RING_FUNC(ring_ostext_OnFilter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_OnFilter((OSText *) RING_API_GETCPOINTER(1,"OSText"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_ostext_OnFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_OnFocus((OSText *) RING_API_GETCPOINTER(1,"OSText"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_ostext_insert_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_insert_text((OSText *) RING_API_GETCPOINTER(1,"OSText"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_ostext_set_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_set_text((OSText *) RING_API_GETCPOINTER(1,"OSText"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_ostext_set_rtf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_set_rtf((OSText *) RING_API_GETCPOINTER(1,"OSText"),(Stream *) RING_API_GETCPOINTER(2,"Stream"));
}


RING_FUNC(ring_ostext_property)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_property((OSText *) RING_API_GETCPOINTER(1,"OSText"),* (const gui_text_t  *) RING_API_GETCPOINTER(2,"const gui_text_t"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_text_t"));
}


RING_FUNC(ring_ostext_editable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_editable((OSText *) RING_API_GETCPOINTER(1,"OSText"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ostext_get_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(ostext_get_text((OSText *) RING_API_GETCPOINTER(1,"OSText")));
}


RING_FUNC(ring_ostext_scroller_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_scroller_visible((OSText *) RING_API_GETCPOINTER(1,"OSText"), (const bool_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_ostext_set_need_display)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_set_need_display((OSText *) RING_API_GETCPOINTER(1,"OSText"));
}


RING_FUNC(ring_ostext_clipboard)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_clipboard((OSText *) RING_API_GETCPOINTER(1,"OSText"),* (const clipboard_t  *) RING_API_GETCPOINTER(2,"const clipboard_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"clipboard_t"));
}


RING_FUNC(ring_ostext_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_attach((OSText *) RING_API_GETCPOINTER(1,"OSText"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ostext_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_detach((OSText *) RING_API_GETCPOINTER(1,"OSText"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ostext_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_visible((OSText *) RING_API_GETCPOINTER(1,"OSText"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ostext_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_enabled((OSText *) RING_API_GETCPOINTER(1,"OSText"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ostext_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_size((OSText *) RING_API_GETCPOINTER(1,"OSText"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ostext_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_origin((OSText *) RING_API_GETCPOINTER(1,"OSText"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ostext_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_frame((OSText *) RING_API_GETCPOINTER(1,"OSText"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_ossplit_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ossplit_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSSplit");
}


RING_FUNC(ring_ossplit_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_destroy((OSSplit **) RING_API_GETCPOINTER2POINTER(1,"OSSplit"));
}


RING_FUNC(ring_ossplit_attach_control)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_attach_control((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(OSControl *) RING_API_GETCPOINTER(2,"OSControl"));
}


RING_FUNC(ring_ossplit_detach_control)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_detach_control((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(OSControl *) RING_API_GETCPOINTER(2,"OSControl"));
}


RING_FUNC(ring_ossplit_OnDrag)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_OnDrag((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_ossplit_track_area)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_track_area((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_ossplit_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_attach((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ossplit_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_detach((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ossplit_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_visible((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ossplit_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_enabled((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ossplit_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_size((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ossplit_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_origin((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ossplit_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_frame((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osslider_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osslider_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSSlider");
}


RING_FUNC(ring_osslider_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_destroy((OSSlider **) RING_API_GETCPOINTER2POINTER(1,"OSSlider"));
}


RING_FUNC(ring_osslider_OnMoved)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_OnMoved((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osslider_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_tooltip((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_osslider_tickmarks)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_tickmarks((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"), (const uint32_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_osslider_position)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_position((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osslider_get_position)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(osslider_get_position((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider")));
}


RING_FUNC(ring_osslider_bounds)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_bounds((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"), (const real32_t ) RING_API_GETNUMBER(2),* (const gui_size_t  *) RING_API_GETCPOINTER(3,"const gui_size_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"gui_size_t"));
}


RING_FUNC(ring_osslider_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_attach((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osslider_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_detach((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osslider_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_visible((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osslider_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_enabled((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osslider_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_size((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osslider_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_origin((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osslider_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_frame((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osprogress_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osprogress_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSProgress");
}


RING_FUNC(ring_osprogress_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_destroy((OSProgress **) RING_API_GETCPOINTER2POINTER(1,"OSProgress"));
}


RING_FUNC(ring_osprogress_position)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_position((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osprogress_thickness)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(osprogress_thickness((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),* (const gui_size_t  *) RING_API_GETCPOINTER(2,"const gui_size_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_size_t"));
}


RING_FUNC(ring_osprogress_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_attach((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osprogress_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_detach((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osprogress_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_visible((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osprogress_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_enabled((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osprogress_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_size((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osprogress_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_origin((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osprogress_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_frame((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_ospopup_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ospopup_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSPopUp");
}


RING_FUNC(ring_ospopup_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_destroy((OSPopUp **) RING_API_GETCPOINTER2POINTER(1,"OSPopUp"));
}


RING_FUNC(ring_ospopup_OnSelect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_OnSelect((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_ospopup_elem)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_elem((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),* (const ctrl_op_t  *) RING_API_GETCPOINTER(2,"const ctrl_op_t"), (const uint32_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4),(Image *) RING_API_GETCPOINTER(5,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ctrl_op_t"));
}


RING_FUNC(ring_ospopup_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_tooltip((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_ospopup_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_font((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_ospopup_list_height)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_list_height((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ospopup_selected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_selected((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ospopup_get_selected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(ospopup_get_selected((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp")));
}


RING_FUNC(ring_ospopup_bounds)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_bounds((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),RING_API_GETSTRING(2),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"));
}


RING_FUNC(ring_ospopup_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_attach((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ospopup_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_detach((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ospopup_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_visible((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ospopup_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_enabled((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ospopup_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_size((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospopup_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_origin((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospopup_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_frame((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_ospanel_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ospanel_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSPanel");
}


RING_FUNC(ring_ospanel_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_destroy((OSPanel **) RING_API_GETCPOINTER2POINTER(1,"OSPanel"));
}


RING_FUNC(ring_ospanel_area)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_area((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(void *) RING_API_GETCPOINTER(2,"void"),* (const color_t  *) RING_API_GETCPOINTER(3,"const color_t"),* (const color_t  *) RING_API_GETCPOINTER(4,"const color_t"), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6), (const real32_t ) RING_API_GETNUMBER(7), (const real32_t ) RING_API_GETNUMBER(8));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"color_t"));
}


RING_FUNC(ring_ospanel_scroller_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_scroller_size((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospanel_content_size)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_content_size((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_ospanel_display)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_display((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"));
}


RING_FUNC(ring_ospanel_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_attach((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ospanel_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_detach((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ospanel_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_visible((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ospanel_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_enabled((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ospanel_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_size((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospanel_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_origin((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospanel_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_frame((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osmenuitem_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osmenuitem_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSMenuItem");
}


RING_FUNC(ring_osmenuitem_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_destroy((OSMenuItem **) RING_API_GETCPOINTER2POINTER(1,"OSMenuItem"));
}


RING_FUNC(ring_osmenuitem_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_OnClick((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osmenuitem_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_enabled((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osmenuitem_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_visible((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osmenuitem_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_text((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_osmenuitem_image)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_image((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_osmenuitem_key)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_key((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_osmenuitem_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_state((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),* (const gui_state_t  *) RING_API_GETCPOINTER(2,"const gui_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_state_t"));
}


RING_FUNC(ring_osmenuitem_submenu)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_submenu((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),(OSMenu *) RING_API_GETCPOINTER(2,"OSMenu"));
}


RING_FUNC(ring_osmenuitem_unset_submenu)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_unset_submenu((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),(OSMenu *) RING_API_GETCPOINTER(2,"OSMenu"));
}


RING_FUNC(ring_osmenu_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osmenu_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSMenu");
}


RING_FUNC(ring_osmenu_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenu_destroy((OSMenu **) RING_API_GETCPOINTER2POINTER(1,"OSMenu"));
}


RING_FUNC(ring_osmenu_add_item)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenu_add_item((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSMenuItem *) RING_API_GETCPOINTER(2,"OSMenuItem"));
}


RING_FUNC(ring_osmenu_delete_item)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenu_delete_item((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSMenuItem *) RING_API_GETCPOINTER(2,"OSMenuItem"));
}


RING_FUNC(ring_osmenu_launch)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenu_launch((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_osmenu_hide)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenu_hide((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"));
}


RING_FUNC(ring_oslabel_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(oslabel_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSLabel");
}


RING_FUNC(ring_oslabel_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_destroy((OSLabel **) RING_API_GETCPOINTER2POINTER(1,"OSLabel"));
}


RING_FUNC(ring_oslabel_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_OnClick((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oslabel_OnEnter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_OnEnter((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oslabel_OnExit)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_OnExit((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oslabel_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_text((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_oslabel_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_font((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_oslabel_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_align((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_oslabel_ellipsis)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_ellipsis((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const ellipsis_t  *) RING_API_GETCPOINTER(2,"const ellipsis_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ellipsis_t"));
}


RING_FUNC(ring_oslabel_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_color((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_oslabel_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_bgcolor((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_oslabel_bounds)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_bounds((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),RING_API_GETSTRING(2), (const real32_t ) RING_API_GETNUMBER(3),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_oslabel_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_attach((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oslabel_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_detach((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oslabel_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_visible((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oslabel_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_enabled((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oslabel_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_size((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oslabel_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_origin((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oslabel_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_frame((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osguictx)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(osguictx(),"GuiCtx");
}


RING_FUNC(ring_osgui_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	osgui_start();
}


RING_FUNC(ring_osgui_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	osgui_finish();
}


RING_FUNC(ring_osgui_set_menubar)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osgui_set_menubar((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_osgui_unset_menubar)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osgui_unset_menubar((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_osgui_redraw_menubar)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	osgui_redraw_menubar();
}


RING_FUNC(ring_osgui_message_loop)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	osgui_message_loop();
}


RING_FUNC(ring_osgui_is_initialized)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(osgui_is_initialized());
}


RING_FUNC(ring_osgui_initialize)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	osgui_initialize();
}


RING_FUNC(ring_osgui_terminate)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	osgui_terminate();
}


RING_FUNC(ring_osgui_set_app)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osgui_set_app((void *) RING_API_GETCPOINTER(1,"void"),(void *) RING_API_GETCPOINTER(2,"void"));
}


RING_FUNC(ring_osglobals_device)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		device_t *pValue ; 
		pValue = (device_t *) RING_API_MALLOC(sizeof(device_t)) ;
		*pValue = osglobals_device((void *) RING_API_GETCPOINTER(1,"void"));
		RING_API_RETMANAGEDCPOINTER(pValue,"device_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osglobals_color)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = osglobals_color((syscolor_t *) RING_API_GETCPOINTER(1,"syscolor_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osglobals_resolution)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osglobals_resolution((void *) RING_API_GETCPOINTER(1,"void"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osglobals_mouse_position)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osglobals_mouse_position((void *) RING_API_GETCPOINTER(1,"void"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osglobals_cursor)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osglobals_cursor(* (const gui_cursor_t  *) RING_API_GETCPOINTER(1,"const gui_cursor_t"),(Image *) RING_API_GETCPOINTER(2,"Image"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4)),"Cursor");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"gui_cursor_t"));
}


RING_FUNC(ring_osglobals_cursor_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osglobals_cursor_destroy((Cursor **) RING_API_GETCPOINTER2POINTER(1,"Cursor"));
}


RING_FUNC(ring_osglobals_value)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osglobals_value( (const uint32_t ) RING_API_GETNUMBER(1),(void *) RING_API_GETCPOINTER(2,"void"));
}


RING_FUNC(ring_osglobals_transitions)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osglobals_transitions((void *) RING_API_GETCPOINTER(1,"void"), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_osglobals_OnIdle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osglobals_OnIdle((void *) RING_API_GETCPOINTER(1,"void"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osedit_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osedit_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSEdit");
}


RING_FUNC(ring_osedit_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_destroy((OSEdit **) RING_API_GETCPOINTER2POINTER(1,"OSEdit"));
}


RING_FUNC(ring_osedit_OnFilter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_OnFilter((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osedit_OnChange)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_OnChange((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osedit_OnFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_OnFocus((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osedit_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_text((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_osedit_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_tooltip((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_osedit_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_font((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_osedit_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_align((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_osedit_passmode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_passmode((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osedit_editable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_editable((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osedit_autoselect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_autoselect((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osedit_select)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_select((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_osedit_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_color((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_osedit_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_bgcolor((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_osedit_vpadding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_vpadding((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osedit_bounds)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_bounds((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"), (const real32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osedit_clipboard)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_clipboard((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const clipboard_t  *) RING_API_GETCPOINTER(2,"const clipboard_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"clipboard_t"));
}


RING_FUNC(ring_osedit_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_attach((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osedit_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_detach((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osedit_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_visible((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osedit_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_enabled((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osedit_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_size((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osedit_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_origin((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osedit_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_frame((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osdrawctrl_font)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osdrawctrl_font((DCtx *) RING_API_GETCPOINTER(1,"DCtx")),"Font");
}


RING_FUNC(ring_osdrawctrl_row_padding)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(osdrawctrl_row_padding((DCtx *) RING_API_GETCPOINTER(1,"DCtx")));
}


RING_FUNC(ring_osdrawctrl_check_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(osdrawctrl_check_width((DCtx *) RING_API_GETCPOINTER(1,"DCtx")));
}


RING_FUNC(ring_osdrawctrl_check_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(osdrawctrl_check_height((DCtx *) RING_API_GETCPOINTER(1,"DCtx")));
}


RING_FUNC(ring_osdrawctrl_multisel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ctrl_msel_t *pValue ; 
		pValue = (ctrl_msel_t *) RING_API_MALLOC(sizeof(ctrl_msel_t)) ;
		*pValue = osdrawctrl_multisel((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"ctrl_msel_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osdrawctrl_clear)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_clear((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const uint32_t ) RING_API_GETNUMBER(5),* (const enum_t  *) RING_API_GETCPOINTER(6,"const enum_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"enum_t"));
}


RING_FUNC(ring_osdrawctrl_header)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_header((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const uint32_t ) RING_API_GETNUMBER(5),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_indicator)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_indicator((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const uint32_t ) RING_API_GETNUMBER(5),* (const indicator_t  *) RING_API_GETCPOINTER(6,"const indicator_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"indicator_t"));
}


RING_FUNC(ring_osdrawctrl_fill)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_fill((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const uint32_t ) RING_API_GETNUMBER(5),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_focus)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_focus((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const uint32_t ) RING_API_GETNUMBER(5),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_line)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_line((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3), (const int32_t ) RING_API_GETNUMBER(4), (const int32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osdrawctrl_text)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_text((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),RING_API_GETSTRING(2), (const int32_t ) RING_API_GETNUMBER(3), (const int32_t ) RING_API_GETNUMBER(4),* (const ctrl_state_t  *) RING_API_GETCPOINTER(5,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_image)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_image((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(Image *) RING_API_GETCPOINTER(2,"Image"), (const int32_t ) RING_API_GETNUMBER(3), (const int32_t ) RING_API_GETNUMBER(4),* (const ctrl_state_t  *) RING_API_GETCPOINTER(5,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_checkbox)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_checkbox((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const uint32_t ) RING_API_GETNUMBER(5),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_uncheckbox)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_uncheckbox((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const uint32_t ) RING_API_GETNUMBER(5),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_oscomwin_file)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(oscomwin_file((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"), (const uint32_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (const bool_t ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_oscomwin_color)
{
	if ( RING_API_PARACOUNT != 10 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscomwin_color((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),RING_API_GETSTRING(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4),* (const align_t  *) RING_API_GETCPOINTER(5,"const align_t"),* (const align_t  *) RING_API_GETCPOINTER(6,"const align_t"),* (const color_t  *) RING_API_GETCPOINTER(7,"const color_t"),(color_t *) RING_API_GETCPOINTER(8,"color_t"), (const uint32_t ) RING_API_GETNUMBER(9),(Listener *) RING_API_GETCPOINTER(10,"Listener"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"color_t"));
}


RING_FUNC(ring_oscombo_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(oscombo_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSCombo");
}


RING_FUNC(ring_oscombo_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_destroy((OSCombo **) RING_API_GETCPOINTER2POINTER(1,"OSCombo"));
}


RING_FUNC(ring_oscombo_OnFilter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_OnFilter((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oscombo_OnChange)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_OnChange((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oscombo_OnFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_OnFocus((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oscombo_OnSelect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_OnSelect((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oscombo_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_text((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_oscombo_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_tooltip((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_oscombo_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_font((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_oscombo_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_align((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_oscombo_passmode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_passmode((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oscombo_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_color((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_oscombo_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_bgcolor((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_oscombo_elem)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_elem((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const ctrl_op_t  *) RING_API_GETCPOINTER(2,"const ctrl_op_t"), (const uint32_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4),(Image *) RING_API_GETCPOINTER(5,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ctrl_op_t"));
}


RING_FUNC(ring_oscombo_selected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_selected((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oscombo_get_selected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(oscombo_get_selected((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo")));
}


RING_FUNC(ring_oscombo_bounds)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_bounds((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"), (const real32_t ) RING_API_GETNUMBER(2),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"));
}


RING_FUNC(ring_oscombo_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_attach((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oscombo_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_detach((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oscombo_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_visible((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oscombo_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_enabled((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_oscombo_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_size((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oscombo_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_origin((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oscombo_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_frame((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osbutton_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osbutton_create( (const uint32_t ) RING_API_GETNUMBER(1)),"OSButton");
}


RING_FUNC(ring_osbutton_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_destroy((OSButton **) RING_API_GETCPOINTER2POINTER(1,"OSButton"));
}


RING_FUNC(ring_osbutton_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_OnClick((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osbutton_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_text((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_osbutton_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_tooltip((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_osbutton_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_font((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_osbutton_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_align((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_osbutton_image)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_image((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_osbutton_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_state((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),* (const gui_state_t  *) RING_API_GETCPOINTER(2,"const gui_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_state_t"));
}


RING_FUNC(ring_osbutton_get_state)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		gui_state_t *pValue ; 
		pValue = (gui_state_t *) RING_API_MALLOC(sizeof(gui_state_t)) ;
		*pValue = osbutton_get_state((OSButton *) RING_API_GETCPOINTER(1,"OSButton"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_state_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osbutton_vpadding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_vpadding((OSButton *) RING_API_GETCPOINTER(1,"OSButton"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osbutton_bounds)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_bounds((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),RING_API_GETSTRING(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"),(real32_t *) RING_API_GETCPOINTER(6,"real32_t"));
}


RING_FUNC(ring_osbutton_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_attach((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osbutton_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_detach((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osbutton_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_visible((OSButton *) RING_API_GETCPOINTER(1,"OSButton"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osbutton_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_enabled((OSButton *) RING_API_GETCPOINTER(1,"OSButton"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_osbutton_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_size((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osbutton_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_origin((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osbutton_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_frame((OSButton *) RING_API_GETCPOINTER(1,"OSButton"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_osbs_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	osbs_start();
}


RING_FUNC(ring_osbs_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	osbs_finish();
}


RING_FUNC(ring_osbs_platform)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		platform_t *pValue ; 
		pValue = (platform_t *) RING_API_MALLOC(sizeof(platform_t)) ;
		*pValue = osbs_platform();
		RING_API_RETMANAGEDCPOINTER(pValue,"platform_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osbs_windows)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		win_t *pValue ; 
		pValue = (win_t *) RING_API_MALLOC(sizeof(win_t)) ;
		*pValue = osbs_windows();
		RING_API_RETMANAGEDCPOINTER(pValue,"win_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osbs_endian)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		endian_t *pValue ; 
		pValue = (endian_t *) RING_API_MALLOC(sizeof(endian_t)) ;
		*pValue = osbs_endian();
		RING_API_RETMANAGEDCPOINTER(pValue,"endian_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_log_output)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	log_output( (const bool_t ) RING_API_GETNUMBER(1), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_log_file)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	log_file(RING_API_GETSTRING(1));
}


RING_FUNC(ring_log_get_file)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETSTRING(log_get_file());
}


RING_FUNC(ring_dlib_open)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(dlib_open(RING_API_GETSTRING(1),RING_API_GETSTRING(2)),"DLib");
}


RING_FUNC(ring_dlib_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dlib_close((DLib **) RING_API_GETCPOINTER2POINTER(1,"DLib"));
}


RING_FUNC(ring_dlib_proc_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		FPtr_libproc *pValue ; 
		pValue = (FPtr_libproc *) RING_API_MALLOC(sizeof(FPtr_libproc)) ;
		*pValue = dlib_proc_imp((DLib *) RING_API_GETCPOINTER(1,"DLib"),RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"FPtr_libproc",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_dlib_var_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(dlib_var_imp((DLib *) RING_API_GETCPOINTER(1,"DLib"),RING_API_GETSTRING(2)),"void");
}


RING_FUNC(ring_btime_now)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(btime_now());
}


RING_FUNC(ring_btime_date)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	btime_date((Date *) RING_API_GETCPOINTER(1,"Date"));
}


RING_FUNC(ring_btime_to_micro)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(btime_to_micro((Date *) RING_API_GETCPOINTER(1,"Date")));
}


RING_FUNC(ring_btime_to_date)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	btime_to_date( (const uint64_t ) RING_API_GETNUMBER(1),(Date *) RING_API_GETCPOINTER(2,"Date"));
}


RING_FUNC(ring_bthread_create_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bthread_create_imp(* (FPtr_thread_main  *) RING_API_GETCPOINTER(1,"FPtr_thread_main"),(void *) RING_API_GETCPOINTER(2,"void")),"Thread");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"FPtr_thread_main"));
}


RING_FUNC(ring_bthread_current_id)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(bthread_current_id());
}


RING_FUNC(ring_bthread_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bthread_close((Thread **) RING_API_GETCPOINTER2POINTER(1,"Thread"));
}


RING_FUNC(ring_bthread_cancel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bthread_cancel((Thread *) RING_API_GETCPOINTER(1,"Thread")));
}


RING_FUNC(ring_bthread_wait)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bthread_wait((Thread *) RING_API_GETCPOINTER(1,"Thread")));
}


RING_FUNC(ring_bthread_finish)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bthread_finish((Thread *) RING_API_GETCPOINTER(1,"Thread"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t")));
}


RING_FUNC(ring_bthread_sleep)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bthread_sleep( (const uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_bsocket_connect)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bsocket_connect( (const uint32_t ) RING_API_GETNUMBER(1), (const uint16_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3),(serror_t *) RING_API_GETCPOINTER(4,"serror_t")),"Socket");
}


RING_FUNC(ring_bsocket_server)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bsocket_server( (const uint16_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2),(serror_t *) RING_API_GETCPOINTER(3,"serror_t")),"Socket");
}


RING_FUNC(ring_bsocket_accept)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bsocket_accept((Socket *) RING_API_GETCPOINTER(1,"Socket"), (const uint32_t ) RING_API_GETNUMBER(2),(serror_t *) RING_API_GETCPOINTER(3,"serror_t")),"Socket");
}


RING_FUNC(ring_bsocket_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_close((Socket **) RING_API_GETCPOINTER2POINTER(1,"Socket"));
}


RING_FUNC(ring_bsocket_local_ip)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_local_ip((Socket *) RING_API_GETCPOINTER(1,"Socket"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"),(uint16_t *) RING_API_GETCPOINTER(3,"uint16_t"));
}


RING_FUNC(ring_bsocket_remote_ip)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_remote_ip((Socket *) RING_API_GETCPOINTER(1,"Socket"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"),(uint16_t *) RING_API_GETCPOINTER(3,"uint16_t"));
}


RING_FUNC(ring_bsocket_read_timeout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_read_timeout((Socket *) RING_API_GETCPOINTER(1,"Socket"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_bsocket_write_timeout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_write_timeout((Socket *) RING_API_GETCPOINTER(1,"Socket"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_bsocket_read)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bsocket_read((Socket *) RING_API_GETCPOINTER(1,"Socket"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(serror_t *) RING_API_GETCPOINTER(5,"serror_t")));
}


RING_FUNC(ring_bsocket_write)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bsocket_write((Socket *) RING_API_GETCPOINTER(1,"Socket"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(serror_t *) RING_API_GETCPOINTER(5,"serror_t")));
}


RING_FUNC(ring_bsocket_url_ip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bsocket_url_ip(RING_API_GETSTRING(1),(serror_t *) RING_API_GETCPOINTER(2,"serror_t")));
}


RING_FUNC(ring_bsocket_str_ip)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bsocket_str_ip(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_bsocket_host_name)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(bsocket_host_name(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bsocket_host_name_ip)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(bsocket_host_name_ip( (const uint32_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_bsocket_ip_str)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(bsocket_ip_str( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_bsocket_hton2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_hton2(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_bsocket_hton4)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_hton4(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_bsocket_hton8)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_hton8(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_bsocket_ntoh2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_ntoh2(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_bsocket_ntoh4)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_ntoh4(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_bsocket_ntoh8)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_ntoh8(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_bproc_exec)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bproc_exec(RING_API_GETSTRING(1),(perror_t *) RING_API_GETCPOINTER(2,"perror_t")),"Proc");
}


RING_FUNC(ring_bproc_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bproc_close((Proc **) RING_API_GETCPOINTER2POINTER(1,"Proc"));
}


RING_FUNC(ring_bproc_cancel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_cancel((Proc *) RING_API_GETCPOINTER(1,"Proc")));
}


RING_FUNC(ring_bproc_wait)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_wait((Proc *) RING_API_GETCPOINTER(1,"Proc")));
}


RING_FUNC(ring_bproc_finish)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_finish((Proc *) RING_API_GETCPOINTER(1,"Proc"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t")));
}


RING_FUNC(ring_bproc_read)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_read((Proc *) RING_API_GETCPOINTER(1,"Proc"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(perror_t *) RING_API_GETCPOINTER(5,"perror_t")));
}


RING_FUNC(ring_bproc_eread)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_eread((Proc *) RING_API_GETCPOINTER(1,"Proc"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(perror_t *) RING_API_GETCPOINTER(5,"perror_t")));
}


RING_FUNC(ring_bproc_write)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_write((Proc *) RING_API_GETCPOINTER(1,"Proc"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(perror_t *) RING_API_GETCPOINTER(5,"perror_t")));
}


RING_FUNC(ring_bproc_read_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_read_close((Proc *) RING_API_GETCPOINTER(1,"Proc")));
}


RING_FUNC(ring_bproc_eread_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_eread_close((Proc *) RING_API_GETCPOINTER(1,"Proc")));
}


RING_FUNC(ring_bproc_write_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_write_close((Proc *) RING_API_GETCPOINTER(1,"Proc")));
}


RING_FUNC(ring_bproc_exit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bproc_exit( (const uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_bmutex_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(bmutex_create(),"Mutex");
}


RING_FUNC(ring_bmutex_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmutex_close((Mutex **) RING_API_GETCPOINTER2POINTER(1,"Mutex"));
}


RING_FUNC(ring_bmutex_lock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmutex_lock((Mutex *) RING_API_GETCPOINTER(1,"Mutex"));
}


RING_FUNC(ring_bmutex_unlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmutex_unlock((Mutex *) RING_API_GETCPOINTER(1,"Mutex"));
}


RING_FUNC(ring_bfile_dir_work)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_work(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bfile_dir_set_work)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_set_work(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")));
}


RING_FUNC(ring_bfile_dir_home)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_home(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bfile_dir_data)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_data(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bfile_dir_exec)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_exec(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bfile_dir_create)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_create(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")));
}


RING_FUNC(ring_bfile_dir_open)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bfile_dir_open(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"Dir");
}


RING_FUNC(ring_bfile_dir_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bfile_dir_close((Dir **) RING_API_GETCPOINTER2POINTER(1,"Dir"));
}


RING_FUNC(ring_bfile_dir_get)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_get((Dir *) RING_API_GETCPOINTER(1,"Dir"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),(file_type_t *) RING_API_GETCPOINTER(4,"file_type_t"),(uint64_t *) RING_API_GETCPOINTER(5,"uint64_t"),(Date *) RING_API_GETCPOINTER(6,"Date"),(ferror_t *) RING_API_GETCPOINTER(7,"ferror_t")));
}


RING_FUNC(ring_bfile_dir_delete)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_delete(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")));
}


RING_FUNC(ring_bfile_create)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bfile_create(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"File");
}


RING_FUNC(ring_bfile_open)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bfile_open(RING_API_GETSTRING(1),* (const file_mode_t  *) RING_API_GETCPOINTER(2,"const file_mode_t"),(ferror_t *) RING_API_GETCPOINTER(3,"ferror_t")),"File");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"file_mode_t"));
}


RING_FUNC(ring_bfile_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bfile_close((File **) RING_API_GETCPOINTER2POINTER(1,"File"));
}


RING_FUNC(ring_bfile_lstat)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_lstat(RING_API_GETSTRING(1),(file_type_t *) RING_API_GETCPOINTER(2,"file_type_t"),(uint64_t *) RING_API_GETCPOINTER(3,"uint64_t"),(Date *) RING_API_GETCPOINTER(4,"Date"),(ferror_t *) RING_API_GETCPOINTER(5,"ferror_t")));
}


RING_FUNC(ring_bfile_fstat)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_fstat((File *) RING_API_GETCPOINTER(1,"File"),(file_type_t *) RING_API_GETCPOINTER(2,"file_type_t"),(uint64_t *) RING_API_GETCPOINTER(3,"uint64_t"),(Date *) RING_API_GETCPOINTER(4,"Date"),(ferror_t *) RING_API_GETCPOINTER(5,"ferror_t")));
}


RING_FUNC(ring_bfile_read)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_read((File *) RING_API_GETCPOINTER(1,"File"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(ferror_t *) RING_API_GETCPOINTER(5,"ferror_t")));
}


RING_FUNC(ring_bfile_write)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_write((File *) RING_API_GETCPOINTER(1,"File"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(ferror_t *) RING_API_GETCPOINTER(5,"ferror_t")));
}


RING_FUNC(ring_bfile_seek)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_seek((File *) RING_API_GETCPOINTER(1,"File"), (const int64_t ) RING_API_GETNUMBER(2),* (const file_seek_t  *) RING_API_GETCPOINTER(3,"const file_seek_t"),(ferror_t *) RING_API_GETCPOINTER(4,"ferror_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"file_seek_t"));
}


RING_FUNC(ring_bfile_pos)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_pos((File *) RING_API_GETCPOINTER(1,"File")));
}


RING_FUNC(ring_bfile_delete)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_delete(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")));
}


RING_FUNC(ring_osapp_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	osapp_finish();
}


RING_FUNC(ring_osapp_task_imp)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osapp_task_imp((void *) RING_API_GETCPOINTER(1,"void"), (const real32_t ) RING_API_GETNUMBER(2),* (FPtr_task_main  *) RING_API_GETCPOINTER(3,"FPtr_task_main"),* (FPtr_task_update  *) RING_API_GETCPOINTER(4,"FPtr_task_update"),* (FPtr_task_end  *) RING_API_GETCPOINTER(5,"FPtr_task_end"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_task_main"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_task_update"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"FPtr_task_end"));
}


RING_FUNC(ring_osapp_menubar)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osapp_menubar((Menu *) RING_API_GETCPOINTER(1,"Menu"),(Window *) RING_API_GETCPOINTER(2,"Window"));
}


RING_FUNC(ring_osapp_open_url)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osapp_open_url(RING_API_GETSTRING(1));
}


RING_FUNC(ring_url_parse)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_parse(RING_API_GETSTRING(1)),"Url");
}


RING_FUNC(ring_url_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	url_destroy((Url **) RING_API_GETCPOINTER2POINTER(1,"Url"));
}


RING_FUNC(ring_url_scheme)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(url_scheme((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_url_user)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(url_user((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_url_pass)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(url_pass((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_url_host)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(url_host((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_url_path)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(url_path((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_url_params)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(url_params((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_url_query)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(url_query((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_url_fragment)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(url_fragment((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_url_resource)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_resource((Url *) RING_API_GETCPOINTER(1,"Url")),"String");
}


RING_FUNC(ring_url_port)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(url_port((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_json_read_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(json_read_imp((Stream *) RING_API_GETCPOINTER(1,"Stream"),(JsonOpts *) RING_API_GETCPOINTER(2,"JsonOpts"),RING_API_GETSTRING(3)),"void");
}


RING_FUNC(ring_json_write_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	json_write_imp((Stream *) RING_API_GETCPOINTER(1,"Stream"),(void *) RING_API_GETCPOINTER(2,"void"),(JsonOpts *) RING_API_GETCPOINTER(3,"JsonOpts"),RING_API_GETSTRING(4));
}


RING_FUNC(ring_json_destroy_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	json_destroy_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_json_destopt_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	json_destopt_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_inet_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	inet_start();
}


RING_FUNC(ring_inet_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	inet_finish();
}


RING_FUNC(ring_http_create)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(http_create(RING_API_GETSTRING(1), (const uint16_t ) RING_API_GETNUMBER(2)),"Http");
}


RING_FUNC(ring_http_secure)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(http_secure(RING_API_GETSTRING(1), (const uint16_t ) RING_API_GETNUMBER(2)),"Http");
}


RING_FUNC(ring_http_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	http_destroy((Http **) RING_API_GETCPOINTER2POINTER(1,"Http"));
}


RING_FUNC(ring_http_clear_headers)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	http_clear_headers((Http *) RING_API_GETCPOINTER(1,"Http"));
}


RING_FUNC(ring_http_add_header)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	http_add_header((Http *) RING_API_GETCPOINTER(1,"Http"),RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_http_get)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(http_get((Http *) RING_API_GETCPOINTER(1,"Http"),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (const uint32_t ) RING_API_GETNUMBER(4),(ierror_t *) RING_API_GETCPOINTER(5,"ierror_t")));
}


RING_FUNC(ring_http_post)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(http_post((Http *) RING_API_GETCPOINTER(1,"Http"),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (const uint32_t ) RING_API_GETNUMBER(4),(ierror_t *) RING_API_GETCPOINTER(5,"ierror_t")));
}


RING_FUNC(ring_http_response_status)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(http_response_status((Http *) RING_API_GETCPOINTER(1,"Http")));
}


RING_FUNC(ring_http_response_protocol)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(http_response_protocol((Http *) RING_API_GETCPOINTER(1,"Http")));
}


RING_FUNC(ring_http_response_message)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(http_response_message((Http *) RING_API_GETCPOINTER(1,"Http")));
}


RING_FUNC(ring_http_response_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(http_response_size((Http *) RING_API_GETCPOINTER(1,"Http")));
}


RING_FUNC(ring_http_response_name)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(http_response_name((Http *) RING_API_GETCPOINTER(1,"Http"), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_http_response_value)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(http_response_value((Http *) RING_API_GETCPOINTER(1,"Http"), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_http_response_header)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(http_response_header((Http *) RING_API_GETCPOINTER(1,"Http"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_http_response_body)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(http_response_body((Http *) RING_API_GETCPOINTER(1,"Http"),(Stream *) RING_API_GETCPOINTER(2,"Stream"),(ierror_t *) RING_API_GETCPOINTER(3,"ierror_t")));
}


RING_FUNC(ring_http_dget)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(http_dget(RING_API_GETSTRING(1),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"),(ierror_t *) RING_API_GETCPOINTER(3,"ierror_t")),"Stream");
}


RING_FUNC(ring_http_exists)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(http_exists(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_b64_encoded_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(b64_encoded_size( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_b64_decoded_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(b64_decoded_size( (const uint32_t ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_b64_encode)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(b64_encode(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (const uint32_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_b64_decode)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(b64_decode(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_window_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(window_create( (const uint32_t ) RING_API_GETNUMBER(1)),"Window");
}


RING_FUNC(ring_window_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_destroy((Window **) RING_API_GETCPOINTER2POINTER(1,"Window"));
}


RING_FUNC(ring_window_panel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_panel((Window *) RING_API_GETCPOINTER(1,"Window"),(Panel *) RING_API_GETCPOINTER(2,"Panel"));
}


RING_FUNC(ring_window_OnClose)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_OnClose((Window *) RING_API_GETCPOINTER(1,"Window"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_window_OnMoved)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_OnMoved((Window *) RING_API_GETCPOINTER(1,"Window"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_window_OnResize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_OnResize((Window *) RING_API_GETCPOINTER(1,"Window"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_window_title)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_title((Window *) RING_API_GETCPOINTER(1,"Window"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_window_show)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_show((Window *) RING_API_GETCPOINTER(1,"Window"));
}


RING_FUNC(ring_window_hide)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_hide((Window *) RING_API_GETCPOINTER(1,"Window"));
}


RING_FUNC(ring_window_overlay)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_overlay((Window *) RING_API_GETCPOINTER(1,"Window"),(Window *) RING_API_GETCPOINTER(2,"Window"));
}


RING_FUNC(ring_window_modal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(window_modal((Window *) RING_API_GETCPOINTER(1,"Window"),(Window *) RING_API_GETCPOINTER(2,"Window")));
}


RING_FUNC(ring_window_stop_modal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_stop_modal((Window *) RING_API_GETCPOINTER(1,"Window"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_window_hotkey)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_hotkey((Window *) RING_API_GETCPOINTER(1,"Window"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"), (const uint32_t ) RING_API_GETNUMBER(3),(Listener *) RING_API_GETCPOINTER(4,"Listener"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
}


RING_FUNC(ring_window_clear_hotkeys)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_clear_hotkeys((Window *) RING_API_GETCPOINTER(1,"Window"));
}


RING_FUNC(ring_window_cycle_tabstop)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_cycle_tabstop((Window *) RING_API_GETCPOINTER(1,"Window"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_window_next_tabstop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		gui_focus_t *pValue ; 
		pValue = (gui_focus_t *) RING_API_MALLOC(sizeof(gui_focus_t)) ;
		*pValue = window_next_tabstop((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_previous_tabstop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		gui_focus_t *pValue ; 
		pValue = (gui_focus_t *) RING_API_MALLOC(sizeof(gui_focus_t)) ;
		*pValue = window_previous_tabstop((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		gui_focus_t *pValue ; 
		pValue = (gui_focus_t *) RING_API_MALLOC(sizeof(gui_focus_t)) ;
		*pValue = window_focus((Window *) RING_API_GETCPOINTER(1,"Window"),(GuiControl *) RING_API_GETCPOINTER(2,"GuiControl"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_get_focus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(window_get_focus((Window *) RING_API_GETCPOINTER(1,"Window")),"GuiControl");
}


RING_FUNC(ring_window_focus_info)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_focus_info((Window *) RING_API_GETCPOINTER(1,"Window"),(FocusInfo *) RING_API_GETCPOINTER(2,"FocusInfo"));
}


RING_FUNC(ring_window_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_update((Window *) RING_API_GETCPOINTER(1,"Window"));
}


RING_FUNC(ring_window_origin)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_origin((Window *) RING_API_GETCPOINTER(1,"Window"),* (const V2Df  *) RING_API_GETCPOINTER(2,"const V2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"V2Df"));
}


RING_FUNC(ring_window_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_size((Window *) RING_API_GETCPOINTER(1,"Window"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_window_get_origin)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = window_get_origin((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_get_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		S2Df *pValue ; 
		pValue = (S2Df *) RING_API_MALLOC(sizeof(S2Df)) ;
		*pValue = window_get_size((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"S2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_get_client_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		S2Df *pValue ; 
		pValue = (S2Df *) RING_API_MALLOC(sizeof(S2Df)) ;
		*pValue = window_get_client_size((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"S2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_control_frame)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		R2Df *pValue ; 
		pValue = (R2Df *) RING_API_MALLOC(sizeof(R2Df)) ;
		*pValue = window_control_frame((Window *) RING_API_GETCPOINTER(1,"Window"),(GuiControl *) RING_API_GETCPOINTER(2,"GuiControl"));
		RING_API_RETMANAGEDCPOINTER(pValue,"R2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_client_to_screen)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = window_client_to_screen((Window *) RING_API_GETCPOINTER(1,"Window"),* (const V2Df  *) RING_API_GETCPOINTER(2,"const V2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_defbutton)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_defbutton((Window *) RING_API_GETCPOINTER(1,"Window"),(Button *) RING_API_GETCPOINTER(2,"Button"));
}


RING_FUNC(ring_window_cursor)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_cursor((Window *) RING_API_GETCPOINTER(1,"Window"),* (const gui_cursor_t  *) RING_API_GETCPOINTER(2,"const gui_cursor_t"),(Image *) RING_API_GETCPOINTER(3,"Image"), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_cursor_t"));
}


RING_FUNC(ring_window_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(window_imp((Window *) RING_API_GETCPOINTER(1,"Window")),"void");
}


RING_FUNC(ring_view_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(view_create(),"View");
}


RING_FUNC(ring_view_scroll)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(view_scroll(),"View");
}


RING_FUNC(ring_view_custom)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(view_custom( (const bool_t ) RING_API_GETNUMBER(1), (const bool_t ) RING_API_GETNUMBER(2)),"View");
}


RING_FUNC(ring_view_data_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_data_imp((View *) RING_API_GETCPOINTER(1,"View"),(void **) RING_API_GETCPOINTER2POINTER(2,"void"),* (FPtr_destroy  *) RING_API_GETCPOINTER(3,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_destroy"));
}


RING_FUNC(ring_view_get_data_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(view_get_data_imp((View *) RING_API_GETCPOINTER(1,"View")),"void");
}


RING_FUNC(ring_view_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_size((View *) RING_API_GETCPOINTER(1,"View"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_view_OnDraw)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnDraw((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnOverlay)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnOverlay((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnSize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnSize((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnEnter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnEnter((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnExit)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnExit((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnMove)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnMove((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnDown)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnDown((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnUp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnUp((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnClick((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnDrag)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnDrag((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnWheel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnWheel((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnKeyDown)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnKeyDown((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnKeyUp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnKeyUp((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnFocus((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnResignFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnResignFocus((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnAcceptFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnAcceptFocus((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnScroll)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_OnScroll((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_keybuf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_keybuf((View *) RING_API_GETCPOINTER(1,"View"),(KeyBuf *) RING_API_GETCPOINTER(2,"KeyBuf"));
}


RING_FUNC(ring_view_get_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_get_size((View *) RING_API_GETCPOINTER(1,"View"),(S2Df *) RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_view_content_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_content_size((View *) RING_API_GETCPOINTER(1,"View"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"),* (const S2Df  *) RING_API_GETCPOINTER(3,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"S2Df"));
}


RING_FUNC(ring_view_scroll_x)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_scroll_x((View *) RING_API_GETCPOINTER(1,"View"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_view_scroll_y)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_scroll_y((View *) RING_API_GETCPOINTER(1,"View"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_view_scroll_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_scroll_size((View *) RING_API_GETCPOINTER(1,"View"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_view_scroll_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_scroll_visible((View *) RING_API_GETCPOINTER(1,"View"), (const bool_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_view_viewport)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_viewport((View *) RING_API_GETCPOINTER(1,"View"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(S2Df *) RING_API_GETCPOINTER(3,"S2Df"));
}


RING_FUNC(ring_view_point_scale)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_point_scale((View *) RING_API_GETCPOINTER(1,"View"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_view_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_update((View *) RING_API_GETCPOINTER(1,"View"));
}


RING_FUNC(ring_view_native)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(view_native((View *) RING_API_GETCPOINTER(1,"View")),"void");
}


RING_FUNC(ring_updown_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(updown_create(),"UpDown");
}


RING_FUNC(ring_updown_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	updown_OnClick((UpDown *) RING_API_GETCPOINTER(1,"UpDown"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_updown_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	updown_tooltip((UpDown *) RING_API_GETCPOINTER(1,"UpDown"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_textview_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(textview_create(),"TextView");
}


RING_FUNC(ring_textview_OnFilter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_OnFilter((TextView *) RING_API_GETCPOINTER(1,"TextView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_textview_OnFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_OnFocus((TextView *) RING_API_GETCPOINTER(1,"TextView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_textview_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_size((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_textview_clear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_clear((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_textview_writef)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_writef((TextView *) RING_API_GETCPOINTER(1,"TextView"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_textview_rtf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_rtf((TextView *) RING_API_GETCPOINTER(1,"TextView"),(Stream *) RING_API_GETCPOINTER(2,"Stream"));
}


RING_FUNC(ring_textview_units)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_units((TextView *) RING_API_GETCPOINTER(1,"TextView"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_textview_family)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_family((TextView *) RING_API_GETCPOINTER(1,"TextView"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_textview_fsize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_fsize((TextView *) RING_API_GETCPOINTER(1,"TextView"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_textview_fstyle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_fstyle((TextView *) RING_API_GETCPOINTER(1,"TextView"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_textview_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_color((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_textview_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_bgcolor((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_textview_pgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_pgcolor((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_textview_halign)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_halign((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_textview_lspacing)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_lspacing((TextView *) RING_API_GETCPOINTER(1,"TextView"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_textview_bfspace)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_bfspace((TextView *) RING_API_GETCPOINTER(1,"TextView"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_textview_afspace)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_afspace((TextView *) RING_API_GETCPOINTER(1,"TextView"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_textview_scroll_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_scroll_visible((TextView *) RING_API_GETCPOINTER(1,"TextView"), (const bool_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_textview_editable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_editable((TextView *) RING_API_GETCPOINTER(1,"TextView"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_textview_select)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_select((TextView *) RING_API_GETCPOINTER(1,"TextView"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_textview_scroll_caret)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_scroll_caret((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_textview_get_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(textview_get_text((TextView *) RING_API_GETCPOINTER(1,"TextView")));
}


RING_FUNC(ring_textview_copy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_copy((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_textview_cut)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_cut((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_textview_paste)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_paste((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_tableview_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(tableview_create(),"TableView");
}


RING_FUNC(ring_tableview_OnData)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_OnData((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_tableview_OnSelect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_OnSelect((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_tableview_OnRowClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_OnRowClick((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_tableview_OnHeaderClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_OnHeaderClick((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_tableview_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_font((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_tableview_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_size((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (S2Df  *) RING_API_GETCPOINTER(2,"S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_tableview_new_column_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(tableview_new_column_text((TableView *) RING_API_GETCPOINTER(1,"TableView")));
}


RING_FUNC(ring_tableview_column_width)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_column_width((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const uint32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_tableview_column_limits)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_column_limits((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const uint32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_tableview_column_resizable)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_column_resizable((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const uint32_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_tableview_column_freeze)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_column_freeze((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_tableview_header_title)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_title((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_tableview_header_align)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_align((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const uint32_t ) RING_API_GETNUMBER(2),* (const align_t  *) RING_API_GETCPOINTER(3,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"align_t"));
}


RING_FUNC(ring_tableview_header_indicator)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_indicator((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_tableview_header_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_visible((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_tableview_header_clickable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_clickable((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_tableview_header_resizable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_resizable((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_tableview_header_height)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_height((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_tableview_row_height)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_row_height((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_tableview_hkey_scroll)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_hkey_scroll((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const bool_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_tableview_multisel)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_multisel((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const bool_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_tableview_grid)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_grid((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const bool_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_tableview_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_update((TableView *) RING_API_GETCPOINTER(1,"TableView"));
}


RING_FUNC(ring_tableview_select)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_select((TableView *) RING_API_GETCPOINTER(1,"TableView"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_tableview_deselect)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_deselect((TableView *) RING_API_GETCPOINTER(1,"TableView"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_tableview_deselect_all)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_deselect_all((TableView *) RING_API_GETCPOINTER(1,"TableView"));
}


RING_FUNC(ring_tableview_focus_row)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_focus_row((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const uint32_t ) RING_API_GETNUMBER(2),* (const align_t  *) RING_API_GETCPOINTER(3,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"align_t"));
}


RING_FUNC(ring_tableview_get_focus_row)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(tableview_get_focus_row((TableView *) RING_API_GETCPOINTER(1,"TableView")));
}


RING_FUNC(ring_tableview_scroll_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_scroll_visible((TableView *) RING_API_GETCPOINTER(1,"TableView"), (const bool_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_splitview_horizontal)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(splitview_horizontal(),"SplitView");
}


RING_FUNC(ring_splitview_vertical)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(splitview_vertical(),"SplitView");
}


RING_FUNC(ring_splitview_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	splitview_size((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_splitview_view)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	splitview_view((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),(View *) RING_API_GETCPOINTER(2,"View"), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_splitview_text)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	splitview_text((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),(TextView *) RING_API_GETCPOINTER(2,"TextView"), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_splitview_split)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	splitview_split((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),(SplitView *) RING_API_GETCPOINTER(2,"SplitView"));
}


RING_FUNC(ring_splitview_panel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	splitview_panel((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),(Panel *) RING_API_GETCPOINTER(2,"Panel"));
}


RING_FUNC(ring_splitview_pos)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	splitview_pos((SplitView *) RING_API_GETCPOINTER(1,"SplitView"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_slider_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(slider_create(),"Slider");
}


RING_FUNC(ring_slider_vertical)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(slider_vertical(),"Slider");
}


RING_FUNC(ring_slider_OnMoved)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	slider_OnMoved((Slider *) RING_API_GETCPOINTER(1,"Slider"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_slider_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	slider_tooltip((Slider *) RING_API_GETCPOINTER(1,"Slider"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_slider_steps)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	slider_steps((Slider *) RING_API_GETCPOINTER(1,"Slider"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_slider_value)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	slider_value((Slider *) RING_API_GETCPOINTER(1,"Slider"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_slider_get_value)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(slider_get_value((Slider *) RING_API_GETCPOINTER(1,"Slider")));
}


RING_FUNC(ring_res_gui_respack)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(res_gui_respack(RING_API_GETSTRING(1)),"ResPack");
}


RING_FUNC(ring_progress_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(progress_create(),"Progress");
}


RING_FUNC(ring_progress_undefined)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	progress_undefined((Progress *) RING_API_GETCPOINTER(1,"Progress"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_progress_value)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	progress_value((Progress *) RING_API_GETCPOINTER(1,"Progress"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_popup_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(popup_create(),"PopUp");
}


RING_FUNC(ring_popup_OnSelect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_OnSelect((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_popup_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_tooltip((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_popup_add_elem)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_add_elem((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),RING_API_GETSTRING(2),(Image *) RING_API_GETCPOINTER(3,"Image"));
}


RING_FUNC(ring_popup_set_elem)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_set_elem((PopUp *) RING_API_GETCPOINTER(1,"PopUp"), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3),(Image *) RING_API_GETCPOINTER(4,"Image"));
}


RING_FUNC(ring_popup_clear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_clear((PopUp *) RING_API_GETCPOINTER(1,"PopUp"));
}


RING_FUNC(ring_popup_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(popup_count((PopUp *) RING_API_GETCPOINTER(1,"PopUp")));
}


RING_FUNC(ring_popup_list_height)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_list_height((PopUp *) RING_API_GETCPOINTER(1,"PopUp"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_popup_selected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_selected((PopUp *) RING_API_GETCPOINTER(1,"PopUp"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_popup_get_selected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(popup_get_selected((PopUp *) RING_API_GETCPOINTER(1,"PopUp")));
}


RING_FUNC(ring_popup_get_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(popup_get_text((PopUp *) RING_API_GETCPOINTER(1,"PopUp"), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_panel_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(panel_create(),"Panel");
}


RING_FUNC(ring_panel_scroll)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(panel_scroll( (const bool_t ) RING_API_GETNUMBER(1), (const bool_t ) RING_API_GETNUMBER(2)),"Panel");
}


RING_FUNC(ring_panel_custom)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(panel_custom( (const bool_t ) RING_API_GETNUMBER(1), (const bool_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3)),"Panel");
}


RING_FUNC(ring_panel_data_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	panel_data_imp((Panel *) RING_API_GETCPOINTER(1,"Panel"),(void **) RING_API_GETCPOINTER2POINTER(2,"void"),* (FPtr_destroy  *) RING_API_GETCPOINTER(3,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_destroy"));
}


RING_FUNC(ring_panel_get_data_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(panel_get_data_imp((Panel *) RING_API_GETCPOINTER(1,"Panel")),"void");
}


RING_FUNC(ring_panel_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	panel_size((Panel *) RING_API_GETCPOINTER(1,"Panel"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_panel_layout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(panel_layout((Panel *) RING_API_GETCPOINTER(1,"Panel"),(Layout *) RING_API_GETCPOINTER(2,"Layout")));
}


RING_FUNC(ring_panel_get_layout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(panel_get_layout((Panel *) RING_API_GETCPOINTER(1,"Panel"), (const uint32_t ) RING_API_GETNUMBER(2)),"Layout");
}


RING_FUNC(ring_panel_visible_layout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	panel_visible_layout((Panel *) RING_API_GETCPOINTER(1,"Panel"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_panel_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	panel_update((Panel *) RING_API_GETCPOINTER(1,"Panel"));
}


RING_FUNC(ring_panel_scroll_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(panel_scroll_width((Panel *) RING_API_GETCPOINTER(1,"Panel")));
}


RING_FUNC(ring_panel_scroll_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(panel_scroll_height((Panel *) RING_API_GETCPOINTER(1,"Panel")));
}


RING_FUNC(ring_menuitem_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(menuitem_create(),"MenuItem");
}


RING_FUNC(ring_menuitem_separator)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(menuitem_separator(),"MenuItem");
}


RING_FUNC(ring_menuitem_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_OnClick((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_menuitem_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_enabled((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_menuitem_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_visible((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_menuitem_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_text((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_menuitem_image)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_image((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_menuitem_key)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_key((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"), (const uint32_t ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
}


RING_FUNC(ring_menuitem_submenu)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_submenu((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),(Menu **) RING_API_GETCPOINTER2POINTER(2,"Menu"));
}


RING_FUNC(ring_menuitem_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_state((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),* (const gui_state_t  *) RING_API_GETCPOINTER(2,"const gui_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_state_t"));
}


RING_FUNC(ring_menu_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(menu_create(),"Menu");
}


RING_FUNC(ring_menu_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menu_destroy((Menu **) RING_API_GETCPOINTER2POINTER(1,"Menu"));
}


RING_FUNC(ring_menu_item)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menu_item((Menu *) RING_API_GETCPOINTER(1,"Menu"),(MenuItem *) RING_API_GETCPOINTER(2,"MenuItem"));
}


RING_FUNC(ring_menu_launch)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menu_launch((Menu *) RING_API_GETCPOINTER(1,"Menu"),* (const V2Df  *) RING_API_GETCPOINTER(2,"const V2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"V2Df"));
}


RING_FUNC(ring_menu_hide)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menu_hide((Menu *) RING_API_GETCPOINTER(1,"Menu"));
}


RING_FUNC(ring_menu_off_items)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menu_off_items((Menu *) RING_API_GETCPOINTER(1,"Menu"));
}


RING_FUNC(ring_menu_get_item)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(menu_get_item((Menu *) RING_API_GETCPOINTER(1,"Menu"), (const uint32_t ) RING_API_GETNUMBER(2)),"MenuItem");
}


RING_FUNC(ring_menu_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(menu_size((Menu *) RING_API_GETCPOINTER(1,"Menu")));
}


RING_FUNC(ring_menu_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(menu_imp((Menu *) RING_API_GETCPOINTER(1,"Menu")),"void");
}


RING_FUNC(ring_listbox_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(listbox_create(),"ListBox");
}


RING_FUNC(ring_listbox_OnDown)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_OnDown((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_listbox_OnSelect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_OnSelect((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_listbox_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_size((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),* (S2Df  *) RING_API_GETCPOINTER(2,"S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_listbox_checkbox)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_checkbox((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_listbox_multisel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_multisel((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_listbox_add_elem)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_add_elem((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),RING_API_GETSTRING(2),(Image *) RING_API_GETCPOINTER(3,"Image"));
}


RING_FUNC(ring_listbox_set_elem)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_set_elem((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3),(Image *) RING_API_GETCPOINTER(4,"Image"));
}


RING_FUNC(ring_listbox_clear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_clear((ListBox *) RING_API_GETCPOINTER(1,"ListBox"));
}


RING_FUNC(ring_listbox_color)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_color((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (const uint32_t ) RING_API_GETNUMBER(2),* (const color_t  *) RING_API_GETCPOINTER(3,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"color_t"));
}


RING_FUNC(ring_listbox_select)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_select((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (const uint32_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_listbox_check)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_check((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (const uint32_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_listbox_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(listbox_count((ListBox *) RING_API_GETCPOINTER(1,"ListBox")));
}


RING_FUNC(ring_listbox_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(listbox_text((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_listbox_selected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(listbox_selected((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_listbox_checked)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(listbox_checked((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_layout_create)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_create( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2)),"Layout");
}


RING_FUNC(ring_layout_cell)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_cell((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Cell");
}


RING_FUNC(ring_layout_control)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_control((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"GuiControl");
}


RING_FUNC(ring_layout_label)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_label((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Label *) RING_API_GETCPOINTER(2,"Label"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_button)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_button((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Button *) RING_API_GETCPOINTER(2,"Button"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_popup)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_popup((Layout *) RING_API_GETCPOINTER(1,"Layout"),(PopUp *) RING_API_GETCPOINTER(2,"PopUp"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_edit)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_edit((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Edit *) RING_API_GETCPOINTER(2,"Edit"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_combo)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_combo((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Combo *) RING_API_GETCPOINTER(2,"Combo"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_listbox)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_listbox((Layout *) RING_API_GETCPOINTER(1,"Layout"),(ListBox *) RING_API_GETCPOINTER(2,"ListBox"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_updown)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_updown((Layout *) RING_API_GETCPOINTER(1,"Layout"),(UpDown *) RING_API_GETCPOINTER(2,"UpDown"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_slider)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_slider((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Slider *) RING_API_GETCPOINTER(2,"Slider"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_progress)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_progress((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Progress *) RING_API_GETCPOINTER(2,"Progress"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_view)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_view((Layout *) RING_API_GETCPOINTER(1,"Layout"),(View *) RING_API_GETCPOINTER(2,"View"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_textview)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_textview((Layout *) RING_API_GETCPOINTER(1,"Layout"),(TextView *) RING_API_GETCPOINTER(2,"TextView"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_imageview)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_imageview((Layout *) RING_API_GETCPOINTER(1,"Layout"),(ImageView *) RING_API_GETCPOINTER(2,"ImageView"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_tableview)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_tableview((Layout *) RING_API_GETCPOINTER(1,"Layout"),(TableView *) RING_API_GETCPOINTER(2,"TableView"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_splitview)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_splitview((Layout *) RING_API_GETCPOINTER(1,"Layout"),(SplitView *) RING_API_GETCPOINTER(2,"SplitView"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_panel)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_panel((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Panel *) RING_API_GETCPOINTER(2,"Panel"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_panel_replace)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_panel_replace((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Panel *) RING_API_GETCPOINTER(2,"Panel"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_layout)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_layout((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Layout *) RING_API_GETCPOINTER(2,"Layout"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_get_label)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_label((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Label");
}


RING_FUNC(ring_layout_get_button)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_button((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Button");
}


RING_FUNC(ring_layout_get_popup)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_popup((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"PopUp");
}


RING_FUNC(ring_layout_get_edit)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_edit((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Edit");
}


RING_FUNC(ring_layout_get_combo)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_combo((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Combo");
}


RING_FUNC(ring_layout_get_listbox)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_listbox((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"ListBox");
}


RING_FUNC(ring_layout_get_updown)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_updown((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"UpDown");
}


RING_FUNC(ring_layout_get_slider)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_slider((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Slider");
}


RING_FUNC(ring_layout_get_progress)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_progress((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Progress");
}


RING_FUNC(ring_layout_get_view)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_view((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"View");
}


RING_FUNC(ring_layout_get_textview)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_textview((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"TextView");
}


RING_FUNC(ring_layout_get_imageview)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_imageview((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"ImageView");
}


RING_FUNC(ring_layout_get_tableview)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_tableview((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"TableView");
}


RING_FUNC(ring_layout_get_splitview)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_splitview((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"SplitView");
}


RING_FUNC(ring_layout_get_panel)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_panel((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Panel");
}


RING_FUNC(ring_layout_get_layout)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_layout((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Layout");
}


RING_FUNC(ring_layout_ncols)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(layout_ncols((Layout *) RING_API_GETCPOINTER(1,"Layout")));
}


RING_FUNC(ring_layout_nrows)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(layout_nrows((Layout *) RING_API_GETCPOINTER(1,"Layout")));
}


RING_FUNC(ring_layout_insert_col)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_insert_col((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_layout_insert_row)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_insert_row((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_layout_remove_col)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_remove_col((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_layout_remove_row)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_remove_row((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_layout_taborder)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_taborder((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const gui_orient_t  *) RING_API_GETCPOINTER(2,"const gui_orient_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_orient_t"));
}


RING_FUNC(ring_layout_tabstop)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_tabstop((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const bool_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_hsize)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hsize((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_layout_vsize)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vsize((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_layout_hmargin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hmargin((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_layout_vmargin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vmargin((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_layout_hexpand)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hexpand((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_layout_hexpand2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hexpand2((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_hexpand3)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hexpand3((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_layout_vexpand)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vexpand((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_layout_vexpand2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vexpand2((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_vexpand3)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vexpand3((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_layout_halign)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_halign((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3),* (const align_t  *) RING_API_GETCPOINTER(4,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"align_t"));
}


RING_FUNC(ring_layout_valign)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_valign((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3),* (const align_t  *) RING_API_GETCPOINTER(4,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"align_t"));
}


RING_FUNC(ring_layout_show_col)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_show_col((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_layout_show_row)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_show_row((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const uint32_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_layout_margin)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_margin((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_layout_margin2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_margin2((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_layout_margin4)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_margin4((Layout *) RING_API_GETCPOINTER(1,"Layout"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_layout_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_bgcolor((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_layout_skcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_skcolor((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_layout_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_update((Layout *) RING_API_GETCPOINTER(1,"Layout"));
}


RING_FUNC(ring_layout_dbind_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_dbind_imp((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Listener *) RING_API_GETCPOINTER(2,"Listener"),RING_API_GETSTRING(3), (const uint16_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_layout_dbind_obj_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_dbind_obj_imp((Layout *) RING_API_GETCPOINTER(1,"Layout"),(void *) RING_API_GETCPOINTER(2,"void"),RING_API_GETSTRING(3));
}


RING_FUNC(ring_layout_dbind_update_imp)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_dbind_update_imp((Layout *) RING_API_GETCPOINTER(1,"Layout"),RING_API_GETSTRING(2), (const uint16_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5), (const uint16_t ) RING_API_GETNUMBER(6), (const uint16_t ) RING_API_GETNUMBER(7));
}


RING_FUNC(ring_label_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(label_create(),"Label");
}


RING_FUNC(ring_label_multiline)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(label_multiline(),"Label");
}


RING_FUNC(ring_label_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_OnClick((Label *) RING_API_GETCPOINTER(1,"Label"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_label_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_text((Label *) RING_API_GETCPOINTER(1,"Label"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_label_size_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_size_text((Label *) RING_API_GETCPOINTER(1,"Label"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_label_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_font((Label *) RING_API_GETCPOINTER(1,"Label"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_label_style_over)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_style_over((Label *) RING_API_GETCPOINTER(1,"Label"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_label_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_align((Label *) RING_API_GETCPOINTER(1,"Label"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_label_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_color((Label *) RING_API_GETCPOINTER(1,"Label"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_label_color_over)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_color_over((Label *) RING_API_GETCPOINTER(1,"Label"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_label_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_bgcolor((Label *) RING_API_GETCPOINTER(1,"Label"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_label_bgcolor_over)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_bgcolor_over((Label *) RING_API_GETCPOINTER(1,"Label"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_imageview_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(imageview_create(),"ImageView");
}


RING_FUNC(ring_imageview_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	imageview_size((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),* (S2Df  *) RING_API_GETCPOINTER(2,"S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_imageview_scale)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	imageview_scale((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),* (const gui_scale_t  *) RING_API_GETCPOINTER(2,"const gui_scale_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_scale_t"));
}


RING_FUNC(ring_imageview_image)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	imageview_image((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_imageview_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	imageview_OnClick((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_imageview_OnOverDraw)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	imageview_OnOverDraw((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_guicontrol_label)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_label((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Label");
}


RING_FUNC(ring_guicontrol_button)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_button((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Button");
}


RING_FUNC(ring_guicontrol_popup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_popup((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"PopUp");
}


RING_FUNC(ring_guicontrol_edit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_edit((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Edit");
}


RING_FUNC(ring_guicontrol_combo)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_combo((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Combo");
}


RING_FUNC(ring_guicontrol_listbox)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_listbox((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"ListBox");
}


RING_FUNC(ring_guicontrol_updown)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_updown((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"UpDown");
}


RING_FUNC(ring_guicontrol_slider)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_slider((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Slider");
}


RING_FUNC(ring_guicontrol_progress)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_progress((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Progress");
}


RING_FUNC(ring_guicontrol_view)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_view((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"View");
}


RING_FUNC(ring_guicontrol_textview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_textview((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"TextView");
}


RING_FUNC(ring_guicontrol_imageview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_imageview((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"ImageView");
}


RING_FUNC(ring_guicontrol_tableview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_tableview((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"TableView");
}


RING_FUNC(ring_guicontrol_splitview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_splitview((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"SplitView");
}


RING_FUNC(ring_guicontrol_panel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_panel((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Panel");
}


RING_FUNC(ring_guicontrol_tag)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	guicontrol_tag((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_guicontrol_get_tag)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(guicontrol_get_tag((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")));
}


RING_FUNC(ring_gui_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	gui_start();
}


RING_FUNC(ring_gui_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	gui_finish();
}


RING_FUNC(ring_gui_respack)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	gui_respack(* (FPtr_respack  *) RING_API_GETCPOINTER(1,"FPtr_respack"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"FPtr_respack"));
}


RING_FUNC(ring_gui_language)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gui_language(RING_API_GETSTRING(1));
}


RING_FUNC(ring_gui_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETSTRING(gui_text(* (const ResId  *) RING_API_GETCPOINTER(1,"const ResId")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ResId"));
}


RING_FUNC(ring_gui_image)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(gui_image(* (const ResId  *) RING_API_GETCPOINTER(1,"const ResId")),"Image");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ResId"));
}


RING_FUNC(ring_gui_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(gui_file(* (const ResId  *) RING_API_GETCPOINTER(1,"const ResId"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ResId"));
}


RING_FUNC(ring_gui_dark_mode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(gui_dark_mode());
}


RING_FUNC(ring_gui_alt_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_alt_color(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_label_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_label_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_view_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_view_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_line_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_line_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_link_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_link_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_border_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_border_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_resolution)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		S2Df *pValue ; 
		pValue = (S2Df *) RING_API_MALLOC(sizeof(S2Df)) ;
		*pValue = gui_resolution();
		RING_API_RETMANAGEDCPOINTER(pValue,"S2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_mouse_pos)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = gui_mouse_pos();
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_update)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	gui_update();
}


RING_FUNC(ring_gui_OnThemeChanged)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gui_OnThemeChanged((Listener *) RING_API_GETCPOINTER(1,"Listener"));
}


RING_FUNC(ring_gui_update_transitions)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gui_update_transitions( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gui_OnNotification)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gui_OnNotification((Listener *) RING_API_GETCPOINTER(1,"Listener"));
}


RING_FUNC(ring_gui_OnIdle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gui_OnIdle((Listener *) RING_API_GETCPOINTER(1,"Listener"));
}


RING_FUNC(ring_gui_info_window)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gui_info_window( (const bool_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5), (const uint32_t ) RING_API_GETNUMBER(6),(ArrPt(String) *) RING_API_GETCPOINTER(7,"ArrPt(String)"), (const uint32_t ) RING_API_GETNUMBER(8)));
}


RING_FUNC(ring_evbind_object_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(evbind_object_imp((Event *) RING_API_GETCPOINTER(1,"Event"),RING_API_GETSTRING(2)),"void");
}


RING_FUNC(ring_evbind_modify_imp)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(evbind_modify_imp((Event *) RING_API_GETCPOINTER(1,"Event"),RING_API_GETSTRING(2), (const uint16_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5), (const uint16_t ) RING_API_GETNUMBER(6), (const uint16_t ) RING_API_GETNUMBER(7)));
}


RING_FUNC(ring_globals_device)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		device_t *pValue ; 
		pValue = (device_t *) RING_API_MALLOC(sizeof(device_t)) ;
		*pValue = globals_device();
		RING_API_RETMANAGEDCPOINTER(pValue,"device_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_globals_resolution)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	globals_resolution((S2Df *) RING_API_GETCPOINTER(1,"S2Df"));
}


RING_FUNC(ring_globals_mouse_position)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = globals_mouse_position();
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_edit_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(edit_create(),"Edit");
}


RING_FUNC(ring_edit_multiline)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(edit_multiline(),"Edit");
}


RING_FUNC(ring_edit_OnFilter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_OnFilter((Edit *) RING_API_GETCPOINTER(1,"Edit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_edit_OnChange)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_OnChange((Edit *) RING_API_GETCPOINTER(1,"Edit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_edit_OnFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_OnFocus((Edit *) RING_API_GETCPOINTER(1,"Edit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_edit_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_text((Edit *) RING_API_GETCPOINTER(1,"Edit"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_edit_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_font((Edit *) RING_API_GETCPOINTER(1,"Edit"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_edit_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_align((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_edit_passmode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_passmode((Edit *) RING_API_GETCPOINTER(1,"Edit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_edit_editable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_editable((Edit *) RING_API_GETCPOINTER(1,"Edit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_edit_autoselect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_autoselect((Edit *) RING_API_GETCPOINTER(1,"Edit"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_edit_select)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_select((Edit *) RING_API_GETCPOINTER(1,"Edit"), (const int32_t ) RING_API_GETNUMBER(2), (const int32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_edit_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_tooltip((Edit *) RING_API_GETCPOINTER(1,"Edit"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_edit_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_color((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_color_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_color_focus((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_bgcolor((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_bgcolor_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_bgcolor_focus((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_phtext)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_phtext((Edit *) RING_API_GETCPOINTER(1,"Edit"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_edit_phcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_phcolor((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_phstyle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_phstyle((Edit *) RING_API_GETCPOINTER(1,"Edit"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_edit_vpadding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_vpadding((Edit *) RING_API_GETCPOINTER(1,"Edit"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_edit_get_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(edit_get_text((Edit *) RING_API_GETCPOINTER(1,"Edit")));
}


RING_FUNC(ring_edit_get_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(edit_get_height((Edit *) RING_API_GETCPOINTER(1,"Edit")));
}


RING_FUNC(ring_edit_copy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_copy((Edit *) RING_API_GETCPOINTER(1,"Edit"));
}


RING_FUNC(ring_edit_cut)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_cut((Edit *) RING_API_GETCPOINTER(1,"Edit"));
}


RING_FUNC(ring_edit_paste)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_paste((Edit *) RING_API_GETCPOINTER(1,"Edit"));
}


RING_FUNC(ring_comwin_open_file)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(comwin_open_file((Window *) RING_API_GETCPOINTER(1,"Window"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"), (const uint32_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4)));
}


RING_FUNC(ring_comwin_save_file)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(comwin_save_file((Window *) RING_API_GETCPOINTER(1,"Window"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"), (const uint32_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4)));
}


RING_FUNC(ring_comwin_color)
{
	if ( RING_API_PARACOUNT != 10 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	comwin_color((Window *) RING_API_GETCPOINTER(1,"Window"),RING_API_GETSTRING(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4),* (const align_t  *) RING_API_GETCPOINTER(5,"const align_t"),* (const align_t  *) RING_API_GETCPOINTER(6,"const align_t"),* (const color_t  *) RING_API_GETCPOINTER(7,"const color_t"),(color_t *) RING_API_GETCPOINTER(8,"color_t"), (const uint32_t ) RING_API_GETNUMBER(9),(Listener *) RING_API_GETCPOINTER(10,"Listener"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"color_t"));
}


RING_FUNC(ring_combo_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(combo_create(),"Combo");
}


RING_FUNC(ring_combo_OnFilter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_OnFilter((Combo *) RING_API_GETCPOINTER(1,"Combo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_combo_OnChange)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_OnChange((Combo *) RING_API_GETCPOINTER(1,"Combo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_combo_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_text((Combo *) RING_API_GETCPOINTER(1,"Combo"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_combo_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_align((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_combo_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_tooltip((Combo *) RING_API_GETCPOINTER(1,"Combo"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_combo_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_color((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_color_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_color_focus((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_bgcolor((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_bgcolor_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_bgcolor_focus((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_phtext)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_phtext((Combo *) RING_API_GETCPOINTER(1,"Combo"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_combo_phcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_phcolor((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_phstyle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_phstyle((Combo *) RING_API_GETCPOINTER(1,"Combo"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_combo_get_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(combo_get_text((Combo *) RING_API_GETCPOINTER(1,"Combo"), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_combo_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(combo_count((Combo *) RING_API_GETCPOINTER(1,"Combo")));
}


RING_FUNC(ring_combo_add_elem)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_add_elem((Combo *) RING_API_GETCPOINTER(1,"Combo"),RING_API_GETSTRING(2),(Image *) RING_API_GETCPOINTER(3,"Image"));
}


RING_FUNC(ring_combo_set_elem)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_set_elem((Combo *) RING_API_GETCPOINTER(1,"Combo"), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3),(Image *) RING_API_GETCPOINTER(4,"Image"));
}


RING_FUNC(ring_combo_ins_elem)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_ins_elem((Combo *) RING_API_GETCPOINTER(1,"Combo"), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3),(Image *) RING_API_GETCPOINTER(4,"Image"));
}


RING_FUNC(ring_combo_del_elem)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_del_elem((Combo *) RING_API_GETCPOINTER(1,"Combo"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_combo_duplicates)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_duplicates((Combo *) RING_API_GETCPOINTER(1,"Combo"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_cell_empty)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cell_empty((Cell *) RING_API_GETCPOINTER(1,"Cell")));
}


RING_FUNC(ring_cell_control)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_control((Cell *) RING_API_GETCPOINTER(1,"Cell")),"GuiControl");
}


RING_FUNC(ring_cell_label)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_label((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Label");
}


RING_FUNC(ring_cell_button)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_button((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Button");
}


RING_FUNC(ring_cell_popup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_popup((Cell *) RING_API_GETCPOINTER(1,"Cell")),"PopUp");
}


RING_FUNC(ring_cell_edit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_edit((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Edit");
}


RING_FUNC(ring_cell_combo)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_combo((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Combo");
}


RING_FUNC(ring_cell_listbox)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_listbox((Cell *) RING_API_GETCPOINTER(1,"Cell")),"ListBox");
}


RING_FUNC(ring_cell_updown)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_updown((Cell *) RING_API_GETCPOINTER(1,"Cell")),"UpDown");
}


RING_FUNC(ring_cell_slider)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_slider((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Slider");
}


RING_FUNC(ring_cell_progress)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_progress((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Progress");
}


RING_FUNC(ring_cell_view)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_view((Cell *) RING_API_GETCPOINTER(1,"Cell")),"View");
}


RING_FUNC(ring_cell_textview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_textview((Cell *) RING_API_GETCPOINTER(1,"Cell")),"TextView");
}


RING_FUNC(ring_cell_imageview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_imageview((Cell *) RING_API_GETCPOINTER(1,"Cell")),"ImageView");
}


RING_FUNC(ring_cell_tableview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_tableview((Cell *) RING_API_GETCPOINTER(1,"Cell")),"TableView");
}


RING_FUNC(ring_cell_splitview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_splitview((Cell *) RING_API_GETCPOINTER(1,"Cell")),"SplitView");
}


RING_FUNC(ring_cell_panel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_panel((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Panel");
}


RING_FUNC(ring_cell_layout)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_layout((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Layout");
}


RING_FUNC(ring_cell_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_enabled((Cell *) RING_API_GETCPOINTER(1,"Cell"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_cell_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_visible((Cell *) RING_API_GETCPOINTER(1,"Cell"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_cell_padding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_padding((Cell *) RING_API_GETCPOINTER(1,"Cell"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_cell_padding2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_padding2((Cell *) RING_API_GETCPOINTER(1,"Cell"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_cell_padding4)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_padding4((Cell *) RING_API_GETCPOINTER(1,"Cell"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_cell_dbind_imp)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_dbind_imp((Cell *) RING_API_GETCPOINTER(1,"Cell"),RING_API_GETSTRING(2), (const uint16_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5), (const uint16_t ) RING_API_GETNUMBER(6), (const uint16_t ) RING_API_GETNUMBER(7));
}


RING_FUNC(ring_button_push)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(button_push(),"Button");
}


RING_FUNC(ring_button_check)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(button_check(),"Button");
}


RING_FUNC(ring_button_check3)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(button_check3(),"Button");
}


RING_FUNC(ring_button_radio)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(button_radio(),"Button");
}


RING_FUNC(ring_button_flat)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(button_flat(),"Button");
}


RING_FUNC(ring_button_flatgle)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(button_flatgle(),"Button");
}


RING_FUNC(ring_button_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_OnClick((Button *) RING_API_GETCPOINTER(1,"Button"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_button_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_text((Button *) RING_API_GETCPOINTER(1,"Button"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_button_text_alt)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_text_alt((Button *) RING_API_GETCPOINTER(1,"Button"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_button_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_tooltip((Button *) RING_API_GETCPOINTER(1,"Button"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_button_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_font((Button *) RING_API_GETCPOINTER(1,"Button"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_button_image)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_image((Button *) RING_API_GETCPOINTER(1,"Button"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_button_image_alt)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_image_alt((Button *) RING_API_GETCPOINTER(1,"Button"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_button_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_state((Button *) RING_API_GETCPOINTER(1,"Button"),* (const gui_state_t  *) RING_API_GETCPOINTER(2,"const gui_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_state_t"));
}


RING_FUNC(ring_button_tag)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_tag((Button *) RING_API_GETCPOINTER(1,"Button"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_button_vpadding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_vpadding((Button *) RING_API_GETCPOINTER(1,"Button"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_button_get_state)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		gui_state_t *pValue ; 
		pValue = (gui_state_t *) RING_API_MALLOC(sizeof(gui_state_t)) ;
		*pValue = button_get_state((Button *) RING_API_GETCPOINTER(1,"Button"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_state_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_button_get_tag)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(button_get_tag((Button *) RING_API_GETCPOINTER(1,"Button")));
}


RING_FUNC(ring_button_get_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(button_get_height((Button *) RING_API_GETCPOINTER(1,"Button")));
}


RING_FUNC(ring_v2df)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2df( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2dd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2dd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_tof)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_tof((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_tod)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_tod((V2Df *) RING_API_GETCPOINTER(1,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_tofn)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	v2d_tofn((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_v2d_todn)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	v2d_todn((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_v2d_addf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_addf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_addd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_addd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_subf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_subf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_subd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_subd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_mulf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_mulf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"), (const real32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_muld)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_muld((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"), (const real64_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_fromf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_fromf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"), (const real32_t ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_fromd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_fromd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"), (const real64_t ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_midf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_midf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_midd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_midd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_unitf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_unitf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_unitd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_unitd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(real64_t *) RING_API_GETCPOINTER(3,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_unit_xyf)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_unit_xyf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_unit_xyd)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_unit_xyd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3), (const real64_t ) RING_API_GETNUMBER(4),(real64_t *) RING_API_GETCPOINTER(5,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_perp_posf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_perp_posf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_perp_posd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_perp_posd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_perp_negf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_perp_negf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_perp_negd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_perp_negd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_from_anglef)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_from_anglef( (const real32_t ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_from_angled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_from_angled( (const real64_t ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_normf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_normf((V2Df *) RING_API_GETCPOINTER(1,"V2Df")));
}


RING_FUNC(ring_v2d_normd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_normd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd")));
}


RING_FUNC(ring_v2d_lengthf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_lengthf((V2Df *) RING_API_GETCPOINTER(1,"V2Df")));
}


RING_FUNC(ring_v2d_lengthd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_lengthd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd")));
}


RING_FUNC(ring_v2d_sqlengthf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_sqlengthf((V2Df *) RING_API_GETCPOINTER(1,"V2Df")));
}


RING_FUNC(ring_v2d_sqlengthd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_sqlengthd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd")));
}


RING_FUNC(ring_v2d_dotf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_dotf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df")));
}


RING_FUNC(ring_v2d_dotd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_dotd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd")));
}


RING_FUNC(ring_v2d_distf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_distf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df")));
}


RING_FUNC(ring_v2d_distd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_distd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd")));
}


RING_FUNC(ring_v2d_sqdistf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_sqdistf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df")));
}


RING_FUNC(ring_v2d_sqdistd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_sqdistd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd")));
}


RING_FUNC(ring_v2d_anglef)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_anglef((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df")));
}


RING_FUNC(ring_v2d_angled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(v2d_angled((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd")));
}


RING_FUNC(ring_v2d_rotatef)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	v2d_rotatef((V2Df *) RING_API_GETCPOINTER(1,"V2Df"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_v2d_rotated)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	v2d_rotated((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"), (const real64_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_tri2df)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Tri2Df *pValue ; 
		pValue = (Tri2Df *) RING_API_MALLOC(sizeof(Tri2Df)) ;
		*pValue = tri2df( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6));
		RING_API_RETMANAGEDCPOINTER(pValue,"Tri2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2dd)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Tri2Dd *pValue ; 
		pValue = (Tri2Dd *) RING_API_MALLOC(sizeof(Tri2Dd)) ;
		*pValue = tri2dd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3), (const real64_t ) RING_API_GETNUMBER(4), (const real64_t ) RING_API_GETNUMBER(5), (const real64_t ) RING_API_GETNUMBER(6));
		RING_API_RETMANAGEDCPOINTER(pValue,"Tri2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_vf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Tri2Df *pValue ; 
		pValue = (Tri2Df *) RING_API_MALLOC(sizeof(Tri2Df)) ;
		*pValue = tri2d_vf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(V2Df *) RING_API_GETCPOINTER(3,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Tri2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_vd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Tri2Dd *pValue ; 
		pValue = (Tri2Dd *) RING_API_MALLOC(sizeof(Tri2Dd)) ;
		*pValue = tri2d_vd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(3,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Tri2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_transformf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tri2d_transformf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_tri2d_transformd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tri2d_transformd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"));
}


RING_FUNC(ring_tri2d_areaf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(tri2d_areaf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df")));
}


RING_FUNC(ring_tri2d_aread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(tri2d_aread((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd")));
}


RING_FUNC(ring_tri2d_ccwf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(tri2d_ccwf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df")));
}


RING_FUNC(ring_tri2d_ccwd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(tri2d_ccwd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd")));
}


RING_FUNC(ring_tri2d_centroidf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = tri2d_centroidf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_centroidd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = tri2d_centroidd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_t2d_tof)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_tof((T2Df *) RING_API_GETCPOINTER(1,"T2Df"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"));
}


RING_FUNC(ring_t2d_tod)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_tod((T2Dd *) RING_API_GETCPOINTER(1,"T2Dd"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_t2d_movef)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_movef((T2Df *) RING_API_GETCPOINTER(1,"T2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_t2d_moved)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_moved((T2Dd *) RING_API_GETCPOINTER(1,"T2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"), (const real64_t ) RING_API_GETNUMBER(3), (const real64_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_t2d_rotatef)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_rotatef((T2Df *) RING_API_GETCPOINTER(1,"T2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_t2d_rotated)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_rotated((T2Dd *) RING_API_GETCPOINTER(1,"T2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"), (const real64_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_t2d_scalef)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_scalef((T2Df *) RING_API_GETCPOINTER(1,"T2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_t2d_scaled)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_scaled((T2Dd *) RING_API_GETCPOINTER(1,"T2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"), (const real64_t ) RING_API_GETNUMBER(3), (const real64_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_t2d_invfastf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_invfastf((T2Df *) RING_API_GETCPOINTER(1,"T2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_t2d_invfastd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_invfastd((T2Dd *) RING_API_GETCPOINTER(1,"T2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"));
}


RING_FUNC(ring_t2d_inversef)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_inversef((T2Df *) RING_API_GETCPOINTER(1,"T2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_t2d_inversed)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_inversed((T2Dd *) RING_API_GETCPOINTER(1,"T2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"));
}


RING_FUNC(ring_t2d_multf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_multf((T2Df *) RING_API_GETCPOINTER(1,"T2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"),(T2Df *) RING_API_GETCPOINTER(3,"T2Df"));
}


RING_FUNC(ring_t2d_multd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_multd((T2Dd *) RING_API_GETCPOINTER(1,"T2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"),(T2Dd *) RING_API_GETCPOINTER(3,"T2Dd"));
}


RING_FUNC(ring_t2d_vmultf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_vmultf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"),(V2Df *) RING_API_GETCPOINTER(3,"V2Df"));
}


RING_FUNC(ring_t2d_vmultd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_vmultd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"),(V2Dd *) RING_API_GETCPOINTER(3,"V2Dd"));
}


RING_FUNC(ring_t2d_vmultnf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_vmultnf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"),(V2Df *) RING_API_GETCPOINTER(3,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_t2d_vmultnd)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_vmultnd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"),(V2Dd *) RING_API_GETCPOINTER(3,"V2Dd"), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_t2d_decomposef)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_decomposef((T2Df *) RING_API_GETCPOINTER(1,"T2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"),(V2Df *) RING_API_GETCPOINTER(4,"V2Df"));
}


RING_FUNC(ring_t2d_decomposed)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	t2d_decomposed((T2Dd *) RING_API_GETCPOINTER(1,"T2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(real64_t *) RING_API_GETCPOINTER(3,"real64_t"),(V2Dd *) RING_API_GETCPOINTER(4,"V2Dd"));
}


RING_FUNC(ring_seg2df)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Seg2Df *pValue ; 
		pValue = (Seg2Df *) RING_API_MALLOC(sizeof(Seg2Df)) ;
		*pValue = seg2df( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Seg2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_seg2dd)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Seg2Dd *pValue ; 
		pValue = (Seg2Dd *) RING_API_MALLOC(sizeof(Seg2Dd)) ;
		*pValue = seg2dd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3), (const real64_t ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Seg2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_seg2d_vf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Seg2Df *pValue ; 
		pValue = (Seg2Df *) RING_API_MALLOC(sizeof(Seg2Df)) ;
		*pValue = seg2d_vf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Seg2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_seg2d_vd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Seg2Dd *pValue ; 
		pValue = (Seg2Dd *) RING_API_MALLOC(sizeof(Seg2Dd)) ;
		*pValue = seg2d_vd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Seg2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_seg2d_lengthf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_lengthf((Seg2Df *) RING_API_GETCPOINTER(1,"Seg2Df")));
}


RING_FUNC(ring_seg2d_lengthd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_lengthd((Seg2Dd *) RING_API_GETCPOINTER(1,"Seg2Dd")));
}


RING_FUNC(ring_seg2d_sqlengthf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_sqlengthf((Seg2Df *) RING_API_GETCPOINTER(1,"Seg2Df")));
}


RING_FUNC(ring_seg2d_sqlengthd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_sqlengthd((Seg2Dd *) RING_API_GETCPOINTER(1,"Seg2Dd")));
}


RING_FUNC(ring_seg2d_evalf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = seg2d_evalf((Seg2Df *) RING_API_GETCPOINTER(1,"Seg2Df"), (const real32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_seg2d_evald)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = seg2d_evald((Seg2Dd *) RING_API_GETCPOINTER(1,"Seg2Dd"), (const real64_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_seg2d_close_paramf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_close_paramf((Seg2Df *) RING_API_GETCPOINTER(1,"Seg2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df")));
}


RING_FUNC(ring_seg2d_close_paramd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_close_paramd((Seg2Dd *) RING_API_GETCPOINTER(1,"Seg2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd")));
}


RING_FUNC(ring_seg2d_point_sqdistf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_point_sqdistf((Seg2Df *) RING_API_GETCPOINTER(1,"Seg2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t")));
}


RING_FUNC(ring_seg2d_point_sqdistd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_point_sqdistd((Seg2Dd *) RING_API_GETCPOINTER(1,"Seg2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(real64_t *) RING_API_GETCPOINTER(3,"real64_t")));
}


RING_FUNC(ring_seg2d_sqdistf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_sqdistf((Seg2Df *) RING_API_GETCPOINTER(1,"Seg2Df"),(Seg2Df *) RING_API_GETCPOINTER(2,"Seg2Df"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t")));
}


RING_FUNC(ring_seg2d_sqdistd)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(seg2d_sqdistd((Seg2Dd *) RING_API_GETCPOINTER(1,"Seg2Dd"),(Seg2Dd *) RING_API_GETCPOINTER(2,"Seg2Dd"),(real64_t *) RING_API_GETCPOINTER(3,"real64_t"),(real64_t *) RING_API_GETCPOINTER(4,"real64_t")));
}


RING_FUNC(ring_r2df)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		R2Df *pValue ; 
		pValue = (R2Df *) RING_API_MALLOC(sizeof(R2Df)) ;
		*pValue = r2df( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"R2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_r2dd)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		R2Dd *pValue ; 
		pValue = (R2Dd *) RING_API_MALLOC(sizeof(R2Dd)) ;
		*pValue = r2dd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3), (const real64_t ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"R2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_r2d_centerf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = r2d_centerf((R2Df *) RING_API_GETCPOINTER(1,"R2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_r2d_centerd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = r2d_centerd((R2Dd *) RING_API_GETCPOINTER(1,"R2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_r2d_collidef)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(r2d_collidef((R2Df *) RING_API_GETCPOINTER(1,"R2Df"),(R2Df *) RING_API_GETCPOINTER(2,"R2Df")));
}


RING_FUNC(ring_r2d_collided)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(r2d_collided((R2Dd *) RING_API_GETCPOINTER(1,"R2Dd"),(R2Dd *) RING_API_GETCPOINTER(2,"R2Dd")));
}


RING_FUNC(ring_r2d_containsf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(r2d_containsf((R2Df *) RING_API_GETCPOINTER(1,"R2Df"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_r2d_containsd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(r2d_containsd((R2Dd *) RING_API_GETCPOINTER(1,"R2Dd"), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_r2d_clipf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(r2d_clipf((R2Df *) RING_API_GETCPOINTER(1,"R2Df"),(R2Df *) RING_API_GETCPOINTER(2,"R2Df")));
}


RING_FUNC(ring_r2d_clipd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(r2d_clipd((R2Dd *) RING_API_GETCPOINTER(1,"R2Dd"),(R2Dd *) RING_API_GETCPOINTER(2,"R2Dd")));
}


RING_FUNC(ring_r2d_joinf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	r2d_joinf((R2Df *) RING_API_GETCPOINTER(1,"R2Df"),(R2Df *) RING_API_GETCPOINTER(2,"R2Df"));
}


RING_FUNC(ring_r2d_joind)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	r2d_joind((R2Dd *) RING_API_GETCPOINTER(1,"R2Dd"),(R2Dd *) RING_API_GETCPOINTER(2,"R2Dd"));
}


RING_FUNC(ring_pol2d_createf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pol2d_createf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(2)),"Pol2Df");
}


RING_FUNC(ring_pol2d_created)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pol2d_created((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"), (const uint32_t ) RING_API_GETNUMBER(2)),"Pol2Dd");
}


RING_FUNC(ring_pol2d_convex_hullf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pol2d_convex_hullf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(2)),"Pol2Df");
}


RING_FUNC(ring_pol2d_convex_hulld)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pol2d_convex_hulld((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"), (const uint32_t ) RING_API_GETNUMBER(2)),"Pol2Dd");
}


RING_FUNC(ring_pol2d_copyf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pol2d_copyf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df")),"Pol2Df");
}


RING_FUNC(ring_pol2d_copyd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pol2d_copyd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd")),"Pol2Dd");
}


RING_FUNC(ring_pol2d_destroyf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pol2d_destroyf((Pol2Df **) RING_API_GETCPOINTER2POINTER(1,"Pol2Df"));
}


RING_FUNC(ring_pol2d_destroyd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pol2d_destroyd((Pol2Dd **) RING_API_GETCPOINTER2POINTER(1,"Pol2Dd"));
}


RING_FUNC(ring_pol2d_transformf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pol2d_transformf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_pol2d_transformd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pol2d_transformd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"));
}


RING_FUNC(ring_pol2d_pointsf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pol2d_pointsf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df")),"V2Df");
}


RING_FUNC(ring_pol2d_pointsd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pol2d_pointsd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd")),"V2Dd");
}


RING_FUNC(ring_pol2d_nf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pol2d_nf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df")));
}


RING_FUNC(ring_pol2d_nd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pol2d_nd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd")));
}


RING_FUNC(ring_pol2d_areaf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pol2d_areaf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df")));
}


RING_FUNC(ring_pol2d_aread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pol2d_aread((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd")));
}


RING_FUNC(ring_pol2d_boxf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Box2Df *pValue ; 
		pValue = (Box2Df *) RING_API_MALLOC(sizeof(Box2Df)) ;
		*pValue = pol2d_boxf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Box2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_pol2d_boxd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Box2Dd *pValue ; 
		pValue = (Box2Dd *) RING_API_MALLOC(sizeof(Box2Dd)) ;
		*pValue = pol2d_boxd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Box2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_pol2d_ccwf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pol2d_ccwf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df")));
}


RING_FUNC(ring_pol2d_ccwd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pol2d_ccwd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd")));
}


RING_FUNC(ring_pol2d_convexf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pol2d_convexf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df")));
}


RING_FUNC(ring_pol2d_convexd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pol2d_convexd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd")));
}


RING_FUNC(ring_pol2d_centroidf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = pol2d_centroidf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_pol2d_centroidd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = pol2d_centroidd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_pol2d_visual_centerf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = pol2d_visual_centerf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"), (const real32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_pol2d_visual_centerd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = pol2d_visual_centerd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"), (const real64_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_obb2d_createf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_createf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4)),"OBB2Df");
}


RING_FUNC(ring_obb2d_created)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_created((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3), (const real64_t ) RING_API_GETNUMBER(4)),"OBB2Dd");
}


RING_FUNC(ring_obb2d_from_linef)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_from_linef((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"), (const real32_t ) RING_API_GETNUMBER(3)),"OBB2Df");
}


RING_FUNC(ring_obb2d_from_lined)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_from_lined((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"), (const real64_t ) RING_API_GETNUMBER(3)),"OBB2Dd");
}


RING_FUNC(ring_obb2d_from_pointsf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_from_pointsf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(2)),"OBB2Df");
}


RING_FUNC(ring_obb2d_from_pointsd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_from_pointsd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"), (const uint32_t ) RING_API_GETNUMBER(2)),"OBB2Dd");
}


RING_FUNC(ring_obb2d_copyf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_copyf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df")),"OBB2Df");
}


RING_FUNC(ring_obb2d_copyd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_copyd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd")),"OBB2Dd");
}


RING_FUNC(ring_obb2d_destroyf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obb2d_destroyf((OBB2Df **) RING_API_GETCPOINTER2POINTER(1,"OBB2Df"));
}


RING_FUNC(ring_obb2d_destroyd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obb2d_destroyd((OBB2Dd **) RING_API_GETCPOINTER2POINTER(1,"OBB2Dd"));
}


RING_FUNC(ring_obb2d_updatef)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obb2d_updatef((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_obb2d_updated)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obb2d_updated((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"), (const real64_t ) RING_API_GETNUMBER(3), (const real64_t ) RING_API_GETNUMBER(4), (const real64_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_obb2d_movef)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obb2d_movef((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_obb2d_moved)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obb2d_moved((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_obb2d_transformf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obb2d_transformf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_obb2d_transformd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obb2d_transformd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"));
}


RING_FUNC(ring_obb2d_cornersf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_cornersf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df")),"V2Df");
}


RING_FUNC(ring_obb2d_cornersd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obb2d_cornersd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd")),"V2Dd");
}


RING_FUNC(ring_obb2d_centerf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = obb2d_centerf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_obb2d_centerd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = obb2d_centerd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_obb2d_widthf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(obb2d_widthf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df")));
}


RING_FUNC(ring_obb2d_widthd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(obb2d_widthd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd")));
}


RING_FUNC(ring_obb2d_heightf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(obb2d_heightf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df")));
}


RING_FUNC(ring_obb2d_heightd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(obb2d_heightd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd")));
}


RING_FUNC(ring_obb2d_anglef)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(obb2d_anglef((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df")));
}


RING_FUNC(ring_obb2d_angled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(obb2d_angled((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd")));
}


RING_FUNC(ring_obb2d_areaf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(obb2d_areaf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df")));
}


RING_FUNC(ring_obb2d_aread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(obb2d_aread((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd")));
}


RING_FUNC(ring_obb2d_boxf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Box2Df *pValue ; 
		pValue = (Box2Df *) RING_API_MALLOC(sizeof(Box2Df)) ;
		*pValue = obb2d_boxf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Box2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_obb2d_boxd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Box2Dd *pValue ; 
		pValue = (Box2Dd *) RING_API_MALLOC(sizeof(Box2Dd)) ;
		*pValue = obb2d_boxd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Box2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_col2d_point_pointf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_point_pointf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"), (const real32_t ) RING_API_GETNUMBER(3),(Col2Df *) RING_API_GETCPOINTER(4,"Col2Df")));
}


RING_FUNC(ring_col2d_point_pointd)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_point_pointd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"), (const real64_t ) RING_API_GETNUMBER(3),(Col2Dd *) RING_API_GETCPOINTER(4,"Col2Dd")));
}


RING_FUNC(ring_col2d_segment_pointf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_segment_pointf((Seg2Df *) RING_API_GETCPOINTER(1,"Seg2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"), (const real32_t ) RING_API_GETNUMBER(3),(Col2Df *) RING_API_GETCPOINTER(4,"Col2Df")));
}


RING_FUNC(ring_col2d_segment_pointd)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_segment_pointd((Seg2Dd *) RING_API_GETCPOINTER(1,"Seg2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"), (const real64_t ) RING_API_GETNUMBER(3),(Col2Dd *) RING_API_GETCPOINTER(4,"Col2Dd")));
}


RING_FUNC(ring_col2d_segment_segmentf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_segment_segmentf((Seg2Df *) RING_API_GETCPOINTER(1,"Seg2Df"),(Seg2Df *) RING_API_GETCPOINTER(2,"Seg2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_segment_segmentd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_segment_segmentd((Seg2Dd *) RING_API_GETCPOINTER(1,"Seg2Dd"),(Seg2Dd *) RING_API_GETCPOINTER(2,"Seg2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_circle_pointf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_circle_pointf((Cir2Df *) RING_API_GETCPOINTER(1,"Cir2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_circle_pointd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_circle_pointd((Cir2Dd *) RING_API_GETCPOINTER(1,"Cir2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_circle_segmentf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_circle_segmentf((Cir2Df *) RING_API_GETCPOINTER(1,"Cir2Df"),(Seg2Df *) RING_API_GETCPOINTER(2,"Seg2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_circle_segmentd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_circle_segmentd((Cir2Dd *) RING_API_GETCPOINTER(1,"Cir2Dd"),(Seg2Dd *) RING_API_GETCPOINTER(2,"Seg2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_circle_circlef)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_circle_circlef((Cir2Df *) RING_API_GETCPOINTER(1,"Cir2Df"),(Cir2Df *) RING_API_GETCPOINTER(2,"Cir2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_circle_circled)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_circle_circled((Cir2Dd *) RING_API_GETCPOINTER(1,"Cir2Dd"),(Cir2Dd *) RING_API_GETCPOINTER(2,"Cir2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_box_pointf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_box_pointf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_box_pointd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_box_pointd((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_box_segmentf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_box_segmentf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"),(Seg2Df *) RING_API_GETCPOINTER(2,"Seg2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_box_segmentd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_box_segmentd((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"),(Seg2Dd *) RING_API_GETCPOINTER(2,"Seg2Dd"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_box_circlef)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_box_circlef((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"),(Cir2Df *) RING_API_GETCPOINTER(2,"Cir2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_box_circled)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_box_circled((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"),(Cir2Dd *) RING_API_GETCPOINTER(2,"Cir2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_box_boxf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_box_boxf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"),(Box2Df *) RING_API_GETCPOINTER(2,"Box2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_box_boxd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_box_boxd((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"),(Box2Dd *) RING_API_GETCPOINTER(2,"Box2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_obb_pointf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_pointf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_obb_pointd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_pointd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_obb_segmentf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_segmentf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"),(Seg2Df *) RING_API_GETCPOINTER(2,"Seg2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_obb_segmentd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_segmentd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"),(Seg2Dd *) RING_API_GETCPOINTER(2,"Seg2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_obb_circlef)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_circlef((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"),(Cir2Df *) RING_API_GETCPOINTER(2,"Cir2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_obb_circled)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_circled((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"),(Cir2Dd *) RING_API_GETCPOINTER(2,"Cir2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_obb_boxf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_boxf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"),(Box2Df *) RING_API_GETCPOINTER(2,"Box2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_obb_boxd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_boxd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"),(Box2Dd *) RING_API_GETCPOINTER(2,"Box2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_obb_obbf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_obbf((OBB2Df *) RING_API_GETCPOINTER(1,"OBB2Df"),(OBB2Df *) RING_API_GETCPOINTER(2,"OBB2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_obb_obbd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_obb_obbd((OBB2Dd *) RING_API_GETCPOINTER(1,"OBB2Dd"),(OBB2Dd *) RING_API_GETCPOINTER(2,"OBB2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_tri_pointf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_pointf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_tri_pointd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_pointd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_tri_segmentf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_segmentf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"),(Seg2Df *) RING_API_GETCPOINTER(2,"Seg2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_tri_segmentd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_segmentd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"),(Seg2Dd *) RING_API_GETCPOINTER(2,"Seg2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_tri_circlef)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_circlef((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"),(Cir2Df *) RING_API_GETCPOINTER(2,"Cir2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_tri_circled)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_circled((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"),(Cir2Df *) RING_API_GETCPOINTER(2,"Cir2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_tri_boxf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_boxf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"),(Box2Df *) RING_API_GETCPOINTER(2,"Box2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_tri_boxd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_boxd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"),(Box2Df *) RING_API_GETCPOINTER(2,"Box2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_tri_obbf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_obbf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"),(OBB2Df *) RING_API_GETCPOINTER(2,"OBB2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_tri_obbd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_obbd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"),(OBB2Dd *) RING_API_GETCPOINTER(2,"OBB2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_tri_trif)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_trif((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"),(Tri2Df *) RING_API_GETCPOINTER(2,"Tri2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_tri_trid)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_tri_trid((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"),(Tri2Dd *) RING_API_GETCPOINTER(2,"Tri2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_poly_pointf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_pointf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_poly_pointd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_pointd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_poly_segmentf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_segmentf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"),(Seg2Df *) RING_API_GETCPOINTER(2,"Seg2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_poly_segmentd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_segmentd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"),(Seg2Dd *) RING_API_GETCPOINTER(2,"Seg2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_poly_circlef)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_circlef((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"),(Cir2Df *) RING_API_GETCPOINTER(2,"Cir2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_poly_circled)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_circled((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"),(Cir2Dd *) RING_API_GETCPOINTER(2,"Cir2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_poly_boxf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_boxf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"),(Box2Df *) RING_API_GETCPOINTER(2,"Box2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_poly_boxd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_boxd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"),(Box2Dd *) RING_API_GETCPOINTER(2,"Box2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_poly_obbf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_obbf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"),(OBB2Df *) RING_API_GETCPOINTER(2,"OBB2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_poly_obbd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_obbd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"),(OBB2Dd *) RING_API_GETCPOINTER(2,"OBB2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_poly_trif)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_trif((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"),(Tri2Df *) RING_API_GETCPOINTER(2,"Tri2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_poly_trid)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_trid((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"),(Tri2Dd *) RING_API_GETCPOINTER(2,"Tri2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_col2d_poly_polyf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_polyf((Pol2Df *) RING_API_GETCPOINTER(1,"Pol2Df"),(Pol2Df *) RING_API_GETCPOINTER(2,"Pol2Df"),(Col2Df *) RING_API_GETCPOINTER(3,"Col2Df")));
}


RING_FUNC(ring_col2d_poly_polyd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(col2d_poly_polyd((Pol2Dd *) RING_API_GETCPOINTER(1,"Pol2Dd"),(Pol2Dd *) RING_API_GETCPOINTER(2,"Pol2Dd"),(Col2Dd *) RING_API_GETCPOINTER(3,"Col2Dd")));
}


RING_FUNC(ring_cir2df)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Cir2Df *pValue ; 
		pValue = (Cir2Df *) RING_API_MALLOC(sizeof(Cir2Df)) ;
		*pValue = cir2df( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Cir2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_cir2dd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Cir2Dd *pValue ; 
		pValue = (Cir2Dd *) RING_API_MALLOC(sizeof(Cir2Dd)) ;
		*pValue = cir2dd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Cir2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_cir2d_from_boxf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Cir2Df *pValue ; 
		pValue = (Cir2Df *) RING_API_MALLOC(sizeof(Cir2Df)) ;
		*pValue = cir2d_from_boxf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Cir2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_cir2d_from_boxd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Cir2Dd *pValue ; 
		pValue = (Cir2Dd *) RING_API_MALLOC(sizeof(Cir2Dd)) ;
		*pValue = cir2d_from_boxd((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Cir2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_cir2d_from_pointsf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Cir2Df *pValue ; 
		pValue = (Cir2Df *) RING_API_MALLOC(sizeof(Cir2Df)) ;
		*pValue = cir2d_from_pointsf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Cir2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_cir2d_from_pointsd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Cir2Dd *pValue ; 
		pValue = (Cir2Dd *) RING_API_MALLOC(sizeof(Cir2Dd)) ;
		*pValue = cir2d_from_pointsd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"), (const uint32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Cir2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_cir2d_minimumf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Cir2Df *pValue ; 
		pValue = (Cir2Df *) RING_API_MALLOC(sizeof(Cir2Df)) ;
		*pValue = cir2d_minimumf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Cir2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_cir2d_minimumd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Cir2Dd *pValue ; 
		pValue = (Cir2Dd *) RING_API_MALLOC(sizeof(Cir2Dd)) ;
		*pValue = cir2d_minimumd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"), (const uint32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Cir2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_cir2d_areaf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cir2d_areaf((Cir2Df *) RING_API_GETCPOINTER(1,"Cir2Df")));
}


RING_FUNC(ring_cir2d_aread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cir2d_aread((Cir2Dd *) RING_API_GETCPOINTER(1,"Cir2Dd")));
}


RING_FUNC(ring_cir2d_is_nullf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cir2d_is_nullf((Cir2Df *) RING_API_GETCPOINTER(1,"Cir2Df")));
}


RING_FUNC(ring_cir2d_is_nulld)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(cir2d_is_nulld((Cir2Dd *) RING_API_GETCPOINTER(1,"Cir2Dd")));
}


RING_FUNC(ring_box2df)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Box2Df *pValue ; 
		pValue = (Box2Df *) RING_API_MALLOC(sizeof(Box2Df)) ;
		*pValue = box2df( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Box2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_box2dd)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Box2Dd *pValue ; 
		pValue = (Box2Dd *) RING_API_MALLOC(sizeof(Box2Dd)) ;
		*pValue = box2dd( (const real64_t ) RING_API_GETNUMBER(1), (const real64_t ) RING_API_GETNUMBER(2), (const real64_t ) RING_API_GETNUMBER(3), (const real64_t ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Box2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_box2d_from_pointsf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Box2Df *pValue ; 
		pValue = (Box2Df *) RING_API_MALLOC(sizeof(Box2Df)) ;
		*pValue = box2d_from_pointsf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Box2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_box2d_from_pointsd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Box2Dd *pValue ; 
		pValue = (Box2Dd *) RING_API_MALLOC(sizeof(Box2Dd)) ;
		*pValue = box2d_from_pointsd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"), (const uint32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Box2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_box2d_centerf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = box2d_centerf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_box2d_centerd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = box2d_centerd((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_box2d_addf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_addf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
}


RING_FUNC(ring_box2d_addd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_addd((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
}


RING_FUNC(ring_box2d_addnf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_addnf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_box2d_addnd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_addnd((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_box2d_add_circlef)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_add_circlef((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"),(Cir2Df *) RING_API_GETCPOINTER(2,"Cir2Df"));
}


RING_FUNC(ring_box2d_add_circled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_add_circled((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"),(Cir2Dd *) RING_API_GETCPOINTER(2,"Cir2Dd"));
}


RING_FUNC(ring_box2d_mergef)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_mergef((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"),(Box2Df *) RING_API_GETCPOINTER(2,"Box2Df"));
}


RING_FUNC(ring_box2d_merged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_merged((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"),(Box2Dd *) RING_API_GETCPOINTER(2,"Box2Dd"));
}


RING_FUNC(ring_box2d_segmentsf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_segmentsf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df"),(Seg2Df *) RING_API_GETCPOINTER(2,"Seg2Df"));
}


RING_FUNC(ring_box2d_segmentsd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	box2d_segmentsd((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd"),(Seg2Dd *) RING_API_GETCPOINTER(2,"Seg2Dd"));
}


RING_FUNC(ring_box2d_areaf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(box2d_areaf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df")));
}


RING_FUNC(ring_box2d_aread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(box2d_aread((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd")));
}


RING_FUNC(ring_box2d_is_nullf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(box2d_is_nullf((Box2Df *) RING_API_GETCPOINTER(1,"Box2Df")));
}


RING_FUNC(ring_box2d_is_nulld)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(box2d_is_nulld((Box2Dd *) RING_API_GETCPOINTER(1,"Box2Dd")));
}


RING_FUNC(ring_pixbuf_create)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pixbuf_create( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2),* (const pixformat_t  *) RING_API_GETCPOINTER(3,"const pixformat_t")),"Pixbuf");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"pixformat_t"));
}


RING_FUNC(ring_pixbuf_copy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pixbuf_copy((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf")),"Pixbuf");
}


RING_FUNC(ring_pixbuf_trim)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pixbuf_trim((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const uint32_t ) RING_API_GETNUMBER(5)),"Pixbuf");
}


RING_FUNC(ring_pixbuf_convert)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pixbuf_convert((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf"),(Palette *) RING_API_GETCPOINTER(2,"Palette"),* (const pixformat_t  *) RING_API_GETCPOINTER(3,"const pixformat_t")),"Pixbuf");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"pixformat_t"));
}


RING_FUNC(ring_pixbuf_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pixbuf_destroy((Pixbuf **) RING_API_GETCPOINTER2POINTER(1,"Pixbuf"));
}


RING_FUNC(ring_pixbuf_format)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		pixformat_t *pValue ; 
		pValue = (pixformat_t *) RING_API_MALLOC(sizeof(pixformat_t)) ;
		*pValue = pixbuf_format((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf"));
		RING_API_RETMANAGEDCPOINTER(pValue,"pixformat_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_pixbuf_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pixbuf_width((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf")));
}


RING_FUNC(ring_pixbuf_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pixbuf_height((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf")));
}


RING_FUNC(ring_pixbuf_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pixbuf_size((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf")));
}


RING_FUNC(ring_pixbuf_dsize)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pixbuf_dsize((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf")));
}


RING_FUNC(ring_pixbuf_cdata)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pixbuf_cdata((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf")));
}


RING_FUNC(ring_pixbuf_data)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pixbuf_data((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf")));
}


RING_FUNC(ring_pixbuf_format_bpp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(pixbuf_format_bpp(* (const pixformat_t  *) RING_API_GETCPOINTER(1,"const pixformat_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"pixformat_t"));
}


RING_FUNC(ring_pixbuf_get)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pixbuf_get((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_pixbuf_set)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pixbuf_set((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_palette_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(palette_create( (const uint32_t ) RING_API_GETNUMBER(1)),"Palette");
}


RING_FUNC(ring_palette_cga2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(palette_cga2( (const bool_t ) RING_API_GETNUMBER(1), (const bool_t ) RING_API_GETNUMBER(2)),"Palette");
}


RING_FUNC(ring_palette_ega4)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(palette_ega4(),"Palette");
}


RING_FUNC(ring_palette_rgb8)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(palette_rgb8(),"Palette");
}


RING_FUNC(ring_palette_gray1)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(palette_gray1(),"Palette");
}


RING_FUNC(ring_palette_gray2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(palette_gray2(),"Palette");
}


RING_FUNC(ring_palette_gray4)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(palette_gray4(),"Palette");
}


RING_FUNC(ring_palette_gray8)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(palette_gray8(),"Palette");
}


RING_FUNC(ring_palette_binary)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(palette_binary(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t")),"Palette");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_palette_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	palette_destroy((Palette **) RING_API_GETCPOINTER2POINTER(1,"Palette"));
}


RING_FUNC(ring_palette_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(palette_size((Palette *) RING_API_GETCPOINTER(1,"Palette")));
}


RING_FUNC(ring_palette_colors)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(palette_colors((Palette *) RING_API_GETCPOINTER(1,"Palette")),"color_t");
}


RING_FUNC(ring_palette_ccolors)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(palette_ccolors((Palette *) RING_API_GETCPOINTER(1,"Palette")),"color_t");
}


RING_FUNC(ring_image_from_pixels)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_from_pixels( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2),* (const pixformat_t  *) RING_API_GETCPOINTER(3,"const pixformat_t"),RING_API_GETSTRING(4),(color_t *) RING_API_GETCPOINTER(5,"color_t"), (const uint32_t ) RING_API_GETNUMBER(6)),"Image");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"pixformat_t"));
}


RING_FUNC(ring_image_from_pixbuf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_from_pixbuf((Pixbuf *) RING_API_GETCPOINTER(1,"Pixbuf"),(Palette *) RING_API_GETCPOINTER(2,"Palette")),"Image");
}


RING_FUNC(ring_image_from_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_from_file(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"Image");
}


RING_FUNC(ring_image_from_data)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_from_data(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)),"Image");
}


RING_FUNC(ring_image_from_resource)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_from_resource((ResPack *) RING_API_GETCPOINTER(1,"ResPack"),* (const ResId  *) RING_API_GETCPOINTER(2,"const ResId")),"Image");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ResId"));
}


RING_FUNC(ring_image_copy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_copy((Image *) RING_API_GETCPOINTER(1,"Image")),"Image");
}


RING_FUNC(ring_image_trim)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_trim((Image *) RING_API_GETCPOINTER(1,"Image"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const uint32_t ) RING_API_GETNUMBER(5)),"Image");
}


RING_FUNC(ring_image_rotate)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_rotate((Image *) RING_API_GETCPOINTER(1,"Image"), (const real32_t ) RING_API_GETNUMBER(2), (const bool_t ) RING_API_GETNUMBER(3),* (const color_t  *) RING_API_GETCPOINTER(4,"const color_t"),(T2Df *) RING_API_GETCPOINTER(5,"T2Df")),"Image");
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"color_t"));
}


RING_FUNC(ring_image_scale)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_scale((Image *) RING_API_GETCPOINTER(1,"Image"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Image");
}


RING_FUNC(ring_image_read)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_read((Stream *) RING_API_GETCPOINTER(1,"Stream")),"Image");
}


RING_FUNC(ring_image_to_file)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(image_to_file((Image *) RING_API_GETCPOINTER(1,"Image"),RING_API_GETSTRING(2),(ferror_t *) RING_API_GETCPOINTER(3,"ferror_t")));
}


RING_FUNC(ring_image_write)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	image_write((Stream *) RING_API_GETCPOINTER(1,"Stream"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_image_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	image_destroy((Image **) RING_API_GETCPOINTER2POINTER(1,"Image"));
}


RING_FUNC(ring_image_format)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		pixformat_t *pValue ; 
		pValue = (pixformat_t *) RING_API_MALLOC(sizeof(pixformat_t)) ;
		*pValue = image_format((Image *) RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"pixformat_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_image_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(image_width((Image *) RING_API_GETCPOINTER(1,"Image")));
}


RING_FUNC(ring_image_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(image_height((Image *) RING_API_GETCPOINTER(1,"Image")));
}


RING_FUNC(ring_image_pixels)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_pixels((Image *) RING_API_GETCPOINTER(1,"Image"),* (const pixformat_t  *) RING_API_GETCPOINTER(2,"const pixformat_t")),"Pixbuf");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"pixformat_t"));
}


RING_FUNC(ring_image_codec)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(image_codec((Image *) RING_API_GETCPOINTER(1,"Image"),* (const codec_t  *) RING_API_GETCPOINTER(2,"const codec_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"codec_t"));
}


RING_FUNC(ring_image_get_codec)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		codec_t *pValue ; 
		pValue = (codec_t *) RING_API_MALLOC(sizeof(codec_t)) ;
		*pValue = image_get_codec((Image *) RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"codec_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_image_num_frames)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(image_num_frames((Image *) RING_API_GETCPOINTER(1,"Image")));
}


RING_FUNC(ring_image_frame_length)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(image_frame_length((Image *) RING_API_GETCPOINTER(1,"Image"), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_image_data_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	image_data_imp((Image *) RING_API_GETCPOINTER(1,"Image"),(void **) RING_API_GETCPOINTER2POINTER(2,"void"),* (FPtr_destroy  *) RING_API_GETCPOINTER(3,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_destroy"));
}


RING_FUNC(ring_image_get_data_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_get_data_imp((Image *) RING_API_GETCPOINTER(1,"Image")),"void");
}


RING_FUNC(ring_image_native)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(image_native((Image *) RING_API_GETCPOINTER(1,"Image")),"void");
}


RING_FUNC(ring_guictx_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(guictx_create(),"GuiCtx");
}


RING_FUNC(ring_guictx_retain)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guictx_retain((GuiCtx *) RING_API_GETCPOINTER(1,"GuiCtx")),"GuiCtx");
}


RING_FUNC(ring_guictx_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	guictx_destroy((GuiCtx **) RING_API_GETCPOINTER2POINTER(1,"GuiCtx"));
}


RING_FUNC(ring_guictx_release)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	guictx_release((GuiCtx **) RING_API_GETCPOINTER2POINTER(1,"GuiCtx"));
}


RING_FUNC(ring_guictx_get_current)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(guictx_get_current(),"GuiCtx");
}


RING_FUNC(ring_guictx_set_current)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	guictx_set_current((GuiCtx *) RING_API_GETCPOINTER(1,"GuiCtx"));
}


RING_FUNC(ring_font_create)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(font_create(RING_API_GETSTRING(1), (const real32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)),"Font");
}


RING_FUNC(ring_font_system)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(font_system( (const real32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2)),"Font");
}


RING_FUNC(ring_font_monospace)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(font_monospace( (const real32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2)),"Font");
}


RING_FUNC(ring_font_with_style)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(font_with_style((Font *) RING_API_GETCPOINTER(1,"Font"), (const uint32_t ) RING_API_GETNUMBER(2)),"Font");
}


RING_FUNC(ring_font_copy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(font_copy((Font *) RING_API_GETCPOINTER(1,"Font")),"Font");
}


RING_FUNC(ring_font_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	font_destroy((Font **) RING_API_GETCPOINTER2POINTER(1,"Font"));
}


RING_FUNC(ring_font_equals)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(font_equals((Font *) RING_API_GETCPOINTER(1,"Font"),(Font *) RING_API_GETCPOINTER(2,"Font")));
}


RING_FUNC(ring_font_regular_size)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(font_regular_size());
}


RING_FUNC(ring_font_small_size)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(font_small_size());
}


RING_FUNC(ring_font_mini_size)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(font_mini_size());
}


RING_FUNC(ring_font_family)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(font_family((Font *) RING_API_GETCPOINTER(1,"Font")));
}


RING_FUNC(ring_font_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(font_size((Font *) RING_API_GETCPOINTER(1,"Font")));
}


RING_FUNC(ring_font_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(font_height((Font *) RING_API_GETCPOINTER(1,"Font")));
}


RING_FUNC(ring_font_leading)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(font_leading((Font *) RING_API_GETCPOINTER(1,"Font")));
}


RING_FUNC(ring_font_style)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(font_style((Font *) RING_API_GETCPOINTER(1,"Font")));
}


RING_FUNC(ring_font_extents)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	font_extents((Font *) RING_API_GETCPOINTER(1,"Font"),RING_API_GETSTRING(2), (const real32_t ) RING_API_GETNUMBER(3),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_font_exists_family)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(font_exists_family(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_font_native)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(font_native((Font *) RING_API_GETCPOINTER(1,"Font")),"void");
}


RING_FUNC(ring_draw_v2df)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_v2df((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(V2Df *) RING_API_GETCPOINTER(3,"V2Df"), (const real32_t ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_v2dd)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_v2dd((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(V2Dd *) RING_API_GETCPOINTER(3,"V2Dd"), (const real64_t ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_seg2df)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_seg2df((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(Seg2Df *) RING_API_GETCPOINTER(2,"Seg2Df"));
}


RING_FUNC(ring_draw_seg2dd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_seg2dd((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(Seg2Dd *) RING_API_GETCPOINTER(2,"Seg2Dd"));
}


RING_FUNC(ring_draw_cir2df)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_cir2df((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(Cir2Df *) RING_API_GETCPOINTER(3,"Cir2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_cir2dd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_cir2dd((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(Cir2Dd *) RING_API_GETCPOINTER(3,"Cir2Dd"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_box2df)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_box2df((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(Box2Df *) RING_API_GETCPOINTER(3,"Box2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_box2dd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_box2dd((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(Box2Dd *) RING_API_GETCPOINTER(3,"Box2Dd"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_obb2df)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_obb2df((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(OBB2Df *) RING_API_GETCPOINTER(3,"OBB2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_obb2dd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_obb2dd((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(OBB2Dd *) RING_API_GETCPOINTER(3,"OBB2Dd"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_tri2df)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_tri2df((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(Tri2Df *) RING_API_GETCPOINTER(3,"Tri2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_tri2dd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_tri2dd((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(Tri2Dd *) RING_API_GETCPOINTER(3,"Tri2Dd"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_pol2df)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_pol2df((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(Pol2Df *) RING_API_GETCPOINTER(3,"Pol2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_pol2dd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_pol2dd((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(Pol2Dd *) RING_API_GETCPOINTER(3,"Pol2Dd"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw2d_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	draw2d_start();
}


RING_FUNC(ring_draw2d_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	draw2d_finish();
}


RING_FUNC(ring_draw_line)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_line((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_draw_polyline)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_polyline((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const bool_t ) RING_API_GETNUMBER(2),(V2Df *) RING_API_GETCPOINTER(3,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_draw_arc)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_arc((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_draw_bezier)
{
	if ( RING_API_PARACOUNT != 9 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_bezier((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6), (const real32_t ) RING_API_GETNUMBER(7), (const real32_t ) RING_API_GETNUMBER(8), (const real32_t ) RING_API_GETNUMBER(9));
}


RING_FUNC(ring_draw_line_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_line_color((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_draw_line_fill)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_line_fill((DCtx *) RING_API_GETCPOINTER(1,"DCtx"));
}


RING_FUNC(ring_draw_line_width)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_line_width((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_draw_line_cap)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_line_cap((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const linecap_t  *) RING_API_GETCPOINTER(2,"const linecap_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"linecap_t"));
}


RING_FUNC(ring_draw_line_join)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_line_join((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const linejoin_t  *) RING_API_GETCPOINTER(2,"const linejoin_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"linejoin_t"));
}


RING_FUNC(ring_draw_line_dash)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_line_dash((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_draw_rect)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_rect((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_rndrect)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_rndrect((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6), (const real32_t ) RING_API_GETNUMBER(7));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_circle)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_circle((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_ellipse)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_ellipse((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_polygon)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_polygon((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),(V2Df *) RING_API_GETCPOINTER(3,"V2Df"), (const uint32_t ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_fill_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_fill_color((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_draw_fill_linear)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_fill_linear((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(color_t *) RING_API_GETCPOINTER(2,"color_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"), (const uint32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6), (const real32_t ) RING_API_GETNUMBER(7), (const real32_t ) RING_API_GETNUMBER(8));
}


RING_FUNC(ring_draw_fill_matrix)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_fill_matrix((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_draw_fill_wrap)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_fill_wrap((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const fillwrap_t  *) RING_API_GETCPOINTER(2,"const fillwrap_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"fillwrap_t"));
}


RING_FUNC(ring_draw_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_font((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_draw_text_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text_color((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_draw_text)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),RING_API_GETSTRING(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_draw_text_single_line)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text_single_line((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),RING_API_GETSTRING(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_draw_text_path)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text_path((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"),RING_API_GETSTRING(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_draw_text_width)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text_width((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_draw_text_trim)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text_trim((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const ellipsis_t  *) RING_API_GETCPOINTER(2,"const ellipsis_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ellipsis_t"));
}


RING_FUNC(ring_draw_text_align)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text_align((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"),* (const align_t  *) RING_API_GETCPOINTER(3,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"align_t"));
}


RING_FUNC(ring_draw_text_halign)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text_halign((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_draw_text_extents)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text_extents((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),RING_API_GETSTRING(2), (const real32_t ) RING_API_GETNUMBER(3),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_draw_image)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_image((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(Image *) RING_API_GETCPOINTER(2,"Image"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_draw_image_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_image_frame((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(Image *) RING_API_GETCPOINTER(2,"Image"), (const uint32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_draw_image_align)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_image_align((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"),* (const align_t  *) RING_API_GETCPOINTER(3,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"align_t"));
}


RING_FUNC(ring_dctx_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(dctx_create(),"DCtx");
}


RING_FUNC(ring_dctx_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dctx_destroy((DCtx **) RING_API_GETCPOINTER2POINTER(1,"DCtx"));
}


RING_FUNC(ring_dctx_set_gcontext)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dctx_set_gcontext((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(void *) RING_API_GETCPOINTER(2,"void"), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6), (const uint32_t ) RING_API_GETNUMBER(7), (const bool_t ) RING_API_GETNUMBER(8));
}


RING_FUNC(ring_dctx_unset_gcontext)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dctx_unset_gcontext((DCtx *) RING_API_GETCPOINTER(1,"DCtx"));
}


RING_FUNC(ring_dctx_set_flipped)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dctx_set_flipped((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_dctx_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dctx_size((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_dctx_offset)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dctx_offset((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_dctx_line_dash)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dctx_line_dash((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_dctx_text_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(dctx_text_width((DCtx *) RING_API_GETCPOINTER(1,"DCtx")));
}


RING_FUNC(ring_dctx_text_intalign)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		align_t *pValue ; 
		pValue = (align_t *) RING_API_MALLOC(sizeof(align_t)) ;
		*pValue = dctx_text_intalign((DCtx *) RING_API_GETCPOINTER(1,"DCtx"));
		RING_API_RETMANAGEDCPOINTER(pValue,"align_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_dctx_text_color)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = dctx_text_color((DCtx *) RING_API_GETCPOINTER(1,"DCtx"));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_dctx_line_color)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = dctx_line_color((DCtx *) RING_API_GETCPOINTER(1,"DCtx"));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_dctx_background_color)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = dctx_background_color((DCtx *) RING_API_GETCPOINTER(1,"DCtx"));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_dctx_text_trim)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ellipsis_t *pValue ; 
		pValue = (ellipsis_t *) RING_API_MALLOC(sizeof(ellipsis_t)) ;
		*pValue = dctx_text_trim((DCtx *) RING_API_GETCPOINTER(1,"DCtx"));
		RING_API_RETMANAGEDCPOINTER(pValue,"ellipsis_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_dctx_native)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(dctx_native((DCtx *) RING_API_GETCPOINTER(1,"DCtx")),"void");
}


RING_FUNC(ring_dctx_internal_bitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(dctx_internal_bitmap((DCtx *) RING_API_GETCPOINTER(1,"DCtx")),"void");
}


RING_FUNC(ring_dctx_data_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dctx_data_imp((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(void *) RING_API_GETCPOINTER(2,"void"),* (FPtr_destroy  *) RING_API_GETCPOINTER(3,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_destroy"));
}


RING_FUNC(ring_dctx_get_data_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(dctx_get_data_imp((DCtx *) RING_API_GETCPOINTER(1,"DCtx")),"void");
}


RING_FUNC(ring_dctx_set_default_osfont)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dctx_set_default_osfont((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(void *) RING_API_GETCPOINTER(2,"void"));
}


RING_FUNC(ring_draw_set_raster_mode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_set_raster_mode((DCtx *) RING_API_GETCPOINTER(1,"DCtx"));
}


RING_FUNC(ring_draw_text_raster)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_text_raster((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),RING_API_GETSTRING(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_draw_line_imp)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_line_imp((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const bool_t ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_draw_rect_imp)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_rect_imp((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const drawop_t  *) RING_API_GETCPOINTER(2,"const drawop_t"), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4), (const real32_t ) RING_API_GETNUMBER(5), (const real32_t ) RING_API_GETNUMBER(6), (const bool_t ) RING_API_GETNUMBER(7));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"drawop_t"));
}


RING_FUNC(ring_dctx_bitmap)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(dctx_bitmap( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2),* (const pixformat_t  *) RING_API_GETCPOINTER(3,"const pixformat_t")),"DCtx");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"pixformat_t"));
}


RING_FUNC(ring_dctx_image)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(dctx_image((DCtx **) RING_API_GETCPOINTER2POINTER(1,"DCtx")),"Image");
}


RING_FUNC(ring_draw_clear)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_clear((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_draw_matrixf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_matrixf((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_draw_matrixd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_matrixd((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"));
}


RING_FUNC(ring_draw_matrix_cartesianf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_matrix_cartesianf((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_draw_matrix_cartesiand)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_matrix_cartesiand((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"));
}


RING_FUNC(ring_draw_antialias)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	draw_antialias((DCtx *) RING_API_GETCPOINTER(1,"DCtx"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_color_rgb)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_rgb( (const uint8_t ) RING_API_GETNUMBER(1), (const uint8_t ) RING_API_GETNUMBER(2), (const uint8_t ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_rgba)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_rgba( (const uint8_t ) RING_API_GETNUMBER(1), (const uint8_t ) RING_API_GETNUMBER(2), (const uint8_t ) RING_API_GETNUMBER(3), (const uint8_t ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_rgbaf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_rgbaf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3), (const real32_t ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_hsbf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_hsbf( (const real32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2), (const real32_t ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_red)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_red( (const uint8_t ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_green)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_green( (const uint8_t ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_blue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_blue( (const uint8_t ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_gray)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_gray( (const uint8_t ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_bgr)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_bgr( (const uint32_t ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_html)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_html(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_indexed)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_indexed( (const uint16_t ) RING_API_GETNUMBER(1),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_color_to_hsbf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	color_to_hsbf(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
}


RING_FUNC(ring_color_to_html)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	color_to_html(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
}


RING_FUNC(ring_color_get_rgb)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	color_get_rgb(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"),(uint8_t *) RING_API_GETCPOINTER(2,"uint8_t"),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"),(uint8_t *) RING_API_GETCPOINTER(4,"uint8_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
}


RING_FUNC(ring_color_get_rgbf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	color_get_rgbf(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
}


RING_FUNC(ring_color_get_rgba)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	color_get_rgba(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"),(uint8_t *) RING_API_GETCPOINTER(2,"uint8_t"),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"),(uint8_t *) RING_API_GETCPOINTER(4,"uint8_t"),(uint8_t *) RING_API_GETCPOINTER(5,"uint8_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
}


RING_FUNC(ring_color_get_rgbaf)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	color_get_rgbaf(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
}


RING_FUNC(ring_color_get_alpha)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(color_get_alpha(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
}


RING_FUNC(ring_color_set_alpha)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = color_set_alpha(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"), (const uint8_t ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tfilter_date)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tfilter_date(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (const uint32_t ) RING_API_GETNUMBER(5), (const bool_t ) RING_API_GETNUMBER(6),(uint32_t *) RING_API_GETCPOINTER(7,"uint32_t"));
}


RING_FUNC(ring_tfilter_to_date)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Date *pValue ; 
		pValue = (Date *) RING_API_MALLOC(sizeof(Date)) ;
		*pValue = tfilter_to_date(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Date",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_str_copy_c)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	str_copy_c(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_str_copy_cn)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	str_copy_cn(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (const uint32_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_str_cat)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	str_cat((String **) RING_API_GETCPOINTER2POINTER(1,"String"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_str_cat_c)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	str_cat_c(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_str_cmp_c)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_cmp_c(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_str_cmp_cn)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_cmp_cn(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_str_empty_c)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_empty_c(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_str_equ_c)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_equ_c(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_str_equ_cn)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_equ_cn(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_str_equ_nocase)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_equ_nocase(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_str_equ_end)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_equ_end(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_str_upper_c)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	str_upper_c(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_str_lower_c)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	str_lower_c(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_str_repl_c)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	str_repl_c(RING_API_GETSTRING(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_str_str)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(str_str(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_str_filename)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(str_filename(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_str_filext)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(str_filext(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_str_to_i8)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_i8(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_str_to_i16)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_i16(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_str_to_i32)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_i32(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_str_to_i64)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_i64(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_str_to_u8)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_u8(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_str_to_u16)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_u16(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_str_to_u32)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_u32(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_str_to_u64)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_u64(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2),(bool_t *) RING_API_GETCPOINTER(3,"bool_t")));
}


RING_FUNC(ring_str_to_r32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_r32(RING_API_GETSTRING(1),(bool_t *) RING_API_GETCPOINTER(2,"bool_t")));
}


RING_FUNC(ring_str_to_r64)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(str_to_r64(RING_API_GETSTRING(1),(bool_t *) RING_API_GETCPOINTER(2,"bool_t")));
}


RING_FUNC(ring_stm_from_block)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stm_from_block(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)),"Stream");
}


RING_FUNC(ring_stm_memory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stm_memory( (const uint32_t ) RING_API_GETNUMBER(1)),"Stream");
}


RING_FUNC(ring_stm_from_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stm_from_file(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"Stream");
}


RING_FUNC(ring_stm_to_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stm_to_file(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"Stream");
}


RING_FUNC(ring_stm_append_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stm_append_file(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"Stream");
}


RING_FUNC(ring_stm_socket)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stm_socket((Socket *) RING_API_GETCPOINTER(1,"Socket")),"Stream");
}


RING_FUNC(ring_stm_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_close((Stream **) RING_API_GETCPOINTER2POINTER(1,"Stream"));
}


RING_FUNC(ring_stm_get_write_endian)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		endian_t *pValue ; 
		pValue = (endian_t *) RING_API_MALLOC(sizeof(endian_t)) ;
		*pValue = stm_get_write_endian((Stream *) RING_API_GETCPOINTER(1,"Stream"));
		RING_API_RETMANAGEDCPOINTER(pValue,"endian_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_stm_get_read_endian)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		endian_t *pValue ; 
		pValue = (endian_t *) RING_API_MALLOC(sizeof(endian_t)) ;
		*pValue = stm_get_read_endian((Stream *) RING_API_GETCPOINTER(1,"Stream"));
		RING_API_RETMANAGEDCPOINTER(pValue,"endian_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_stm_set_write_endian)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_set_write_endian((Stream *) RING_API_GETCPOINTER(1,"Stream"),* (const endian_t  *) RING_API_GETCPOINTER(2,"const endian_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"endian_t"));
}


RING_FUNC(ring_stm_set_read_endian)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_set_read_endian((Stream *) RING_API_GETCPOINTER(1,"Stream"),* (const endian_t  *) RING_API_GETCPOINTER(2,"const endian_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"endian_t"));
}


RING_FUNC(ring_stm_get_write_utf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		unicode_t *pValue ; 
		pValue = (unicode_t *) RING_API_MALLOC(sizeof(unicode_t)) ;
		*pValue = stm_get_write_utf((Stream *) RING_API_GETCPOINTER(1,"Stream"));
		RING_API_RETMANAGEDCPOINTER(pValue,"unicode_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_stm_get_read_utf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		unicode_t *pValue ; 
		pValue = (unicode_t *) RING_API_MALLOC(sizeof(unicode_t)) ;
		*pValue = stm_get_read_utf((Stream *) RING_API_GETCPOINTER(1,"Stream"));
		RING_API_RETMANAGEDCPOINTER(pValue,"unicode_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_stm_set_write_utf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_set_write_utf((Stream *) RING_API_GETCPOINTER(1,"Stream"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_stm_set_read_utf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_set_read_utf((Stream *) RING_API_GETCPOINTER(1,"Stream"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_stm_is_memory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_is_memory((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_bytes_written)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_bytes_written((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_bytes_readed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_bytes_readed((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_col)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_col((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_row)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_row((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_token_col)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_token_col((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_token_row)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_token_row((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_token_lexeme)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(stm_token_lexeme((Stream *) RING_API_GETCPOINTER(1,"Stream"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t")));
}


RING_FUNC(ring_stm_token_escapes)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_token_escapes((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_token_spaces)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_token_spaces((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_token_comments)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_token_comments((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_state)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		sstate_t *pValue ; 
		pValue = (sstate_t *) RING_API_MALLOC(sizeof(sstate_t)) ;
		*pValue = stm_state((Stream *) RING_API_GETCPOINTER(1,"Stream"));
		RING_API_RETMANAGEDCPOINTER(pValue,"sstate_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_stm_file_err)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ferror_t *pValue ; 
		pValue = (ferror_t *) RING_API_MALLOC(sizeof(ferror_t)) ;
		*pValue = stm_file_err((Stream *) RING_API_GETCPOINTER(1,"Stream"));
		RING_API_RETMANAGEDCPOINTER(pValue,"ferror_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_stm_sock_err)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		serror_t *pValue ; 
		pValue = (serror_t *) RING_API_MALLOC(sizeof(serror_t)) ;
		*pValue = stm_sock_err((Stream *) RING_API_GETCPOINTER(1,"Stream"));
		RING_API_RETMANAGEDCPOINTER(pValue,"serror_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_stm_corrupt)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_corrupt((Stream *) RING_API_GETCPOINTER(1,"Stream"));
}


RING_FUNC(ring_stm_str)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(stm_str((Stream *) RING_API_GETCPOINTER(1,"Stream")),"String");
}


RING_FUNC(ring_stm_buffer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(stm_buffer((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_buffer_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_buffer_size((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_write)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write((Stream *) RING_API_GETCPOINTER(1,"Stream"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_stm_write_char)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_char((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_writef)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_writef((Stream *) RING_API_GETCPOINTER(1,"Stream"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_stm_write_bool)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_bool((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const bool_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_i8)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_i8((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const int8_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_i16)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_i16((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const int16_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_i32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_i32((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const int32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_i64)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_i64((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const int64_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_u8)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_u8((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const uint8_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_u16)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_u16((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const uint16_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_u32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_u32((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_u64)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_u64((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const uint64_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_r32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_r32((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const real32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_write_r64)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_write_r64((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const real64_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_read)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read((Stream *) RING_API_GETCPOINTER(1,"Stream"),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_stm_read_char)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_char((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_chars)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(stm_read_chars((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_stm_read_line)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(stm_read_line((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_trim)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(stm_read_trim((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_token)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ltoken_t *pValue ; 
		pValue = (ltoken_t *) RING_API_MALLOC(sizeof(ltoken_t)) ;
		*pValue = stm_read_token((Stream *) RING_API_GETCPOINTER(1,"Stream"));
		RING_API_RETMANAGEDCPOINTER(pValue,"ltoken_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_stm_read_i8_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_i8_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_i16_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_i16_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_i32_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_i32_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_i64_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_i64_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_u8_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_u8_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_u16_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_u16_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_u32_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_u32_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_u64_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_u64_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_r32_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_r32_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_r64_tok)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_r64_tok((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_bool)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_bool((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_i8)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_i8((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_i16)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_i16((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_i32)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_i32((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_i64)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_i64((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_u8)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_u8((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_u16)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_u16((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_u32)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_u32((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_u64)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_u64((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_r32)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_r32((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_read_r64)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(stm_read_r64((Stream *) RING_API_GETCPOINTER(1,"Stream")));
}


RING_FUNC(ring_stm_skip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_skip((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_stm_skip_bom)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_skip_bom((Stream *) RING_API_GETCPOINTER(1,"Stream"));
}


RING_FUNC(ring_stm_skip_token)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_skip_token((Stream *) RING_API_GETCPOINTER(1,"Stream"),* (const ltoken_t  *) RING_API_GETCPOINTER(2,"const ltoken_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ltoken_t"));
}


RING_FUNC(ring_stm_flush)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_flush((Stream *) RING_API_GETCPOINTER(1,"Stream"));
}


RING_FUNC(ring_stm_pipe)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	stm_pipe((Stream *) RING_API_GETCPOINTER(1,"Stream"),(Stream *) RING_API_GETCPOINTER(2,"Stream"), (const uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_respack_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	respack_destroy((ResPack **) RING_API_GETCPOINTER2POINTER(1,"ResPack"));
}


RING_FUNC(ring_respack_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(respack_text((ResPack *) RING_API_GETCPOINTER(1,"ResPack"),* (const ResId  *) RING_API_GETCPOINTER(2,"const ResId")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ResId"));
}


RING_FUNC(ring_respack_file)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(respack_file((ResPack *) RING_API_GETCPOINTER(1,"ResPack"),* (const ResId  *) RING_API_GETCPOINTER(2,"const ResId"),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ResId"));
}


RING_FUNC(ring_regex_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(regex_create(RING_API_GETSTRING(1)),"RegEx");
}


RING_FUNC(ring_regex_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	regex_destroy((RegEx **) RING_API_GETCPOINTER2POINTER(1,"RegEx"));
}


RING_FUNC(ring_regex_match)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(regex_match((RegEx *) RING_API_GETCPOINTER(1,"RegEx"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_rbtree_create)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(rbtree_create(* (FPtr_compare  *) RING_API_GETCPOINTER(1,"FPtr_compare"), (const uint16_t ) RING_API_GETNUMBER(2), (const uint16_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4)),"RBTree");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"FPtr_compare"));
}


RING_FUNC(ring_rbtree_destroy)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	rbtree_destroy((RBTree **) RING_API_GETCPOINTER2POINTER(1,"RBTree"),* (FPtr_remove  *) RING_API_GETCPOINTER(2,"FPtr_remove"),* (FPtr_destroy  *) RING_API_GETCPOINTER(3,"FPtr_destroy"),RING_API_GETSTRING(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_remove"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_destroy"));
}


RING_FUNC(ring_rbtree_destroy_ptr)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	rbtree_destroy_ptr((RBTree **) RING_API_GETCPOINTER2POINTER(1,"RBTree"),* (FPtr_destroy  *) RING_API_GETCPOINTER(2,"FPtr_destroy"),* (FPtr_destroy  *) RING_API_GETCPOINTER(3,"FPtr_destroy"),RING_API_GETSTRING(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_destroy"));
}


RING_FUNC(ring_rbtree_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(rbtree_size((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_get)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_get((RBTree *) RING_API_GETCPOINTER(1,"RBTree"),(void *) RING_API_GETCPOINTER(2,"void"), (const bool_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_rbtree_insert)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_insert((RBTree *) RING_API_GETCPOINTER(1,"RBTree"),(void *) RING_API_GETCPOINTER(2,"void"),* (FPtr_copy  *) RING_API_GETCPOINTER(3,"FPtr_copy")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_copy"));
}


RING_FUNC(ring_rbtree_insert_ptr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(rbtree_insert_ptr((RBTree *) RING_API_GETCPOINTER(1,"RBTree"),(void *) RING_API_GETCPOINTER(2,"void")));
}


RING_FUNC(ring_rbtree_delete)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(rbtree_delete((RBTree *) RING_API_GETCPOINTER(1,"RBTree"),(void *) RING_API_GETCPOINTER(2,"void"),* (FPtr_remove  *) RING_API_GETCPOINTER(3,"FPtr_remove"),* (FPtr_destroy  *) RING_API_GETCPOINTER(4,"FPtr_destroy")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_remove"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_destroy"));
}


RING_FUNC(ring_rbtree_delete_ptr)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(rbtree_delete_ptr((RBTree *) RING_API_GETCPOINTER(1,"RBTree"),(void *) RING_API_GETCPOINTER(2,"void"),* (FPtr_destroy  *) RING_API_GETCPOINTER(3,"FPtr_destroy"),* (FPtr_destroy  *) RING_API_GETCPOINTER(4,"FPtr_destroy")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_destroy"));
}


RING_FUNC(ring_rbtree_first)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_first((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_last)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_last((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_next)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_next((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_prev)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_prev((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_first_ptr)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_first_ptr((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_last_ptr)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_last_ptr((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_next_ptr)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_next_ptr((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_prev_ptr)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_prev_ptr((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_get_key)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(rbtree_get_key((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_rbtree_check)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(rbtree_check((RBTree *) RING_API_GETCPOINTER(1,"RBTree")));
}


RING_FUNC(ring_obj_init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obj_init((Object *) RING_API_GETCPOINTER(1,"Object"));
}


RING_FUNC(ring_obj_new_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(obj_new_imp( (const uint32_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_obj_new0_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(obj_new0_imp( (const uint32_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_obj_retain_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obj_retain_imp((void *) RING_API_GETCPOINTER(1,"void")),"void");
}


RING_FUNC(ring_obj_retain_optional_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obj_retain_optional_imp((void *) RING_API_GETCPOINTER(1,"void")),"void");
}


RING_FUNC(ring_obj_remove)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obj_remove((Object *) RING_API_GETCPOINTER(1,"Object"));
}


RING_FUNC(ring_obj_release_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obj_release_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void"));
}


RING_FUNC(ring_obj_release_optional_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obj_release_optional_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void"));
}


RING_FUNC(ring_obj_delete_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	obj_delete_imp((byte_t **) RING_API_GETCPOINTER2POINTER(1,"byte_t"), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_obj_listener_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(obj_listener_imp((void *) RING_API_GETCPOINTER(1,"void"),* (FPtr_event_handler  *) RING_API_GETCPOINTER(2,"FPtr_event_handler")),"Listener");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_event_handler"));
}


RING_FUNC(ring_keybuf_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(keybuf_create(),"KeyBuf");
}


RING_FUNC(ring_keybuf_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	keybuf_destroy((KeyBuf **) RING_API_GETCPOINTER2POINTER(1,"KeyBuf"));
}


RING_FUNC(ring_keybuf_OnUp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	keybuf_OnUp((KeyBuf *) RING_API_GETCPOINTER(1,"KeyBuf"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
}


RING_FUNC(ring_keybuf_OnDown)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	keybuf_OnDown((KeyBuf *) RING_API_GETCPOINTER(1,"KeyBuf"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
}


RING_FUNC(ring_keybuf_clear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	keybuf_clear((KeyBuf *) RING_API_GETCPOINTER(1,"KeyBuf"));
}


RING_FUNC(ring_keybuf_pressed)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(keybuf_pressed((KeyBuf *) RING_API_GETCPOINTER(1,"KeyBuf"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
}


RING_FUNC(ring_keybuf_str)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETSTRING(keybuf_str(* (const vkey_t  *) RING_API_GETCPOINTER(1,"const vkey_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"vkey_t"));
}


RING_FUNC(ring_keybuf_dump)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	keybuf_dump((KeyBuf *) RING_API_GETCPOINTER(1,"KeyBuf"));
}


RING_FUNC(ring_hfile_exename)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(hfile_exename(),"String");
}


RING_FUNC(ring_hfile_dir)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_dir(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_hfile_dir_create)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_dir_create(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")));
}


RING_FUNC(ring_hfile_dir_destroy)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_dir_destroy(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")));
}


RING_FUNC(ring_hfile_dir_entry_remove)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	hfile_dir_entry_remove((DirEntry *) RING_API_GETCPOINTER(1,"DirEntry"));
}


RING_FUNC(ring_hfile_date)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Date *pValue ; 
		pValue = (Date *) RING_API_MALLOC(sizeof(Date)) ;
		*pValue = hfile_date(RING_API_GETSTRING(1), (const bool_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Date",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_hfile_dir_sync)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_dir_sync(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const bool_t ) RING_API_GETNUMBER(3), (const bool_t ) RING_API_GETNUMBER(4),(char_t **) RING_API_GETCPOINTER2POINTER(5,"char_t"), (const uint32_t ) RING_API_GETNUMBER(6),(ferror_t *) RING_API_GETCPOINTER(7,"ferror_t")));
}


RING_FUNC(ring_hfile_exists)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_exists(RING_API_GETSTRING(1),(file_type_t *) RING_API_GETCPOINTER(2,"file_type_t")));
}


RING_FUNC(ring_hfile_is_uptodate)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_is_uptodate(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_hfile_copy)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_copy(RING_API_GETSTRING(1),RING_API_GETSTRING(2),(ferror_t *) RING_API_GETCPOINTER(3,"ferror_t")));
}


RING_FUNC(ring_hfile_buffer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(hfile_buffer(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"Buffer");
}


RING_FUNC(ring_hfile_string)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(hfile_string(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"String");
}


RING_FUNC(ring_hfile_stream)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(hfile_stream(RING_API_GETSTRING(1),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"Stream");
}


RING_FUNC(ring_hfile_from_string)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_from_string(RING_API_GETSTRING(1),(String *) RING_API_GETCPOINTER(2,"String"),(ferror_t *) RING_API_GETCPOINTER(3,"ferror_t")));
}


RING_FUNC(ring_hfile_from_data)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_from_data(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (const uint32_t ) RING_API_GETNUMBER(3),(ferror_t *) RING_API_GETCPOINTER(4,"ferror_t")));
}


RING_FUNC(ring_hfile_dir_loop)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hfile_dir_loop(RING_API_GETSTRING(1),(Listener *) RING_API_GETCPOINTER(2,"Listener"), (const bool_t ) RING_API_GETNUMBER(3), (const bool_t ) RING_API_GETNUMBER(4),(ferror_t *) RING_API_GETCPOINTER(5,"ferror_t")));
}


RING_FUNC(ring_hfile_appdata)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(hfile_appdata(RING_API_GETSTRING(1)),"String");
}


RING_FUNC(ring_hfile_home_dir)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(hfile_home_dir(RING_API_GETSTRING(1)),"String");
}


RING_FUNC(ring_heap_start_mt)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	heap_start_mt();
}


RING_FUNC(ring_heap_end_mt)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	heap_end_mt();
}


RING_FUNC(ring_heap_verbose)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	heap_verbose( (const bool_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_heap_stats)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	heap_stats( (const bool_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_heap_leaks)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(heap_leaks());
}


RING_FUNC(ring_heap_malloc_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(heap_malloc_imp( (const uint32_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2), (const bool_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_heap_calloc_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(heap_calloc_imp( (const uint32_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2), (const bool_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_heap_realloc)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(heap_realloc(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4)));
}


RING_FUNC(ring_heap_aligned_malloc_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(heap_aligned_malloc_imp( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (const bool_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_heap_aligned_calloc_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(heap_aligned_calloc_imp( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (const bool_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_heap_aligned_realloc)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(heap_aligned_realloc(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3), (const uint32_t ) RING_API_GETNUMBER(4),RING_API_GETSTRING(5)));
}


RING_FUNC(ring_heap_free)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	heap_free((byte_t **) RING_API_GETCPOINTER2POINTER(1,"byte_t"), (const uint32_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_heap_auditor_add)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	heap_auditor_add(RING_API_GETSTRING(1));
}


RING_FUNC(ring_heap_auditor_delete)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	heap_auditor_delete(RING_API_GETSTRING(1));
}


RING_FUNC(ring_listener_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(listener_imp((void *) RING_API_GETCPOINTER(1,"void"),* (FPtr_event_handler  *) RING_API_GETCPOINTER(2,"FPtr_event_handler")),"Listener");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_event_handler"));
}


RING_FUNC(ring_listener_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listener_destroy((Listener **) RING_API_GETCPOINTER2POINTER(1,"Listener"));
}


RING_FUNC(ring_listener_update)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listener_update((Listener **) RING_API_GETCPOINTER2POINTER(1,"Listener"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_listener_event_imp)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listener_event_imp((Listener *) RING_API_GETCPOINTER(1,"Listener"), (const uint32_t ) RING_API_GETNUMBER(2),(void *) RING_API_GETCPOINTER(3,"void"),(void *) RING_API_GETCPOINTER(4,"void"),(void *) RING_API_GETCPOINTER(5,"void"),RING_API_GETSTRING(6),RING_API_GETSTRING(7),RING_API_GETSTRING(8));
}


RING_FUNC(ring_listener_pass_event_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listener_pass_event_imp((Listener *) RING_API_GETCPOINTER(1,"Listener"),(Event *) RING_API_GETCPOINTER(2,"Event"),(void *) RING_API_GETCPOINTER(3,"void"),RING_API_GETSTRING(4));
}


RING_FUNC(ring_event_type)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(event_type((Event *) RING_API_GETCPOINTER(1,"Event")));
}


RING_FUNC(ring_event_sender_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(event_sender_imp((Event *) RING_API_GETCPOINTER(1,"Event"),RING_API_GETSTRING(2)),"void");
}


RING_FUNC(ring_event_params_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(event_params_imp((Event *) RING_API_GETCPOINTER(1,"Event"),RING_API_GETSTRING(2)),"void");
}


RING_FUNC(ring_event_result_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(event_result_imp((Event *) RING_API_GETCPOINTER(1,"Event"),RING_API_GETSTRING(2)),"void");
}


RING_FUNC(ring_dbind_imp)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_imp(RING_API_GETSTRING(1), (const uint16_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4), (const uint16_t ) RING_API_GETNUMBER(5), (const uint16_t ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_dbind_enum_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_enum_imp(RING_API_GETSTRING(1),RING_API_GETSTRING(2),* (const enum_t  *) RING_API_GETCPOINTER(3,"const enum_t"),RING_API_GETSTRING(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"enum_t"));
}


RING_FUNC(ring_dbind_create_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(dbind_create_imp(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_dbind_init_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_init_imp(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_dbind_remove_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_remove_imp(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_dbind_destroy_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_destroy_imp((byte_t **) RING_API_GETCPOINTER2POINTER(1,"byte_t"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_dbind_destopt_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_destopt_imp((byte_t **) RING_API_GETCPOINTER2POINTER(1,"byte_t"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_dbind_read_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(dbind_read_imp((Stream *) RING_API_GETCPOINTER(1,"Stream"),RING_API_GETSTRING(2)),"void");
}


RING_FUNC(ring_dbind_write_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_write_imp((Stream *) RING_API_GETCPOINTER(1,"Stream"),(void *) RING_API_GETCPOINTER(2,"void"),RING_API_GETSTRING(3));
}


RING_FUNC(ring_dbind_default_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_default_imp(RING_API_GETSTRING(1),RING_API_GETSTRING(2),(void *) RING_API_GETCPOINTER(3,"void"));
}


RING_FUNC(ring_dbind_range_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_range_imp(RING_API_GETSTRING(1),RING_API_GETSTRING(2),(void *) RING_API_GETCPOINTER(3,"void"),(void *) RING_API_GETCPOINTER(4,"void"));
}


RING_FUNC(ring_dbind_precision_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_precision_imp(RING_API_GETSTRING(1),RING_API_GETSTRING(2),(void *) RING_API_GETCPOINTER(3,"void"));
}


RING_FUNC(ring_dbind_increment_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_increment_imp(RING_API_GETSTRING(1),RING_API_GETSTRING(2),(void *) RING_API_GETCPOINTER(3,"void"));
}


RING_FUNC(ring_dbind_suffix_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dbind_suffix_imp(RING_API_GETSTRING(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_date_system)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		Date *pValue ; 
		pValue = (Date *) RING_API_MALLOC(sizeof(Date)) ;
		*pValue = date_system();
		RING_API_RETMANAGEDCPOINTER(pValue,"Date",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_date_pack)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Date *pValue ; 
		pValue = (Date *) RING_API_MALLOC(sizeof(Date)) ;
		*pValue = date_pack( (const int16_t ) RING_API_GETNUMBER(1), (const uint8_t ) RING_API_GETNUMBER(2), (const uint8_t ) RING_API_GETNUMBER(3), (const uint8_t ) RING_API_GETNUMBER(4), (const uint8_t ) RING_API_GETNUMBER(5), (const uint8_t ) RING_API_GETNUMBER(6));
		RING_API_RETMANAGEDCPOINTER(pValue,"Date",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_date_add_seconds)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Date *pValue ; 
		pValue = (Date *) RING_API_MALLOC(sizeof(Date)) ;
		*pValue = date_add_seconds((Date *) RING_API_GETCPOINTER(1,"Date"), (int32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Date",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_date_add_minutes)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Date *pValue ; 
		pValue = (Date *) RING_API_MALLOC(sizeof(Date)) ;
		*pValue = date_add_minutes((Date *) RING_API_GETCPOINTER(1,"Date"), (int32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Date",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_date_add_hours)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Date *pValue ; 
		pValue = (Date *) RING_API_MALLOC(sizeof(Date)) ;
		*pValue = date_add_hours((Date *) RING_API_GETCPOINTER(1,"Date"), (int32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Date",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_date_add_days)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Date *pValue ; 
		pValue = (Date *) RING_API_MALLOC(sizeof(Date)) ;
		*pValue = date_add_days((Date *) RING_API_GETCPOINTER(1,"Date"), (int32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Date",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_date_year)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(date_year());
}


RING_FUNC(ring_date_cmp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(date_cmp((Date *) RING_API_GETCPOINTER(1,"Date"),(Date *) RING_API_GETCPOINTER(2,"Date")));
}


RING_FUNC(ring_date_ellapsed_seconds)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(date_ellapsed_seconds((Date *) RING_API_GETCPOINTER(1,"Date"),(Date *) RING_API_GETCPOINTER(2,"Date")));
}


RING_FUNC(ring_date_between)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(date_between((Date *) RING_API_GETCPOINTER(1,"Date"),(Date *) RING_API_GETCPOINTER(2,"Date"),(Date *) RING_API_GETCPOINTER(3,"Date")));
}


RING_FUNC(ring_date_is_null)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(date_is_null((Date *) RING_API_GETCPOINTER(1,"Date")));
}


RING_FUNC(ring_date_is_valid)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(date_is_valid((Date *) RING_API_GETCPOINTER(1,"Date")));
}


RING_FUNC(ring_date_weekday)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		week_day_t *pValue ; 
		pValue = (week_day_t *) RING_API_MALLOC(sizeof(week_day_t)) ;
		*pValue = date_weekday((Date *) RING_API_GETCPOINTER(1,"Date"));
		RING_API_RETMANAGEDCPOINTER(pValue,"week_day_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_date_format)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(date_format((Date *) RING_API_GETCPOINTER(1,"Date"),RING_API_GETSTRING(2)),"String");
}


RING_FUNC(ring_core_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	core_start();
}


RING_FUNC(ring_core_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	core_finish();
}


RING_FUNC(ring_clock_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(clock_create( (const real64_t ) RING_API_GETNUMBER(1)),"Clock");
}


RING_FUNC(ring_clock_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	clock_destroy((Clock **) RING_API_GETCPOINTER2POINTER(1,"Clock"));
}


RING_FUNC(ring_clock_frame)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(clock_frame((Clock *) RING_API_GETCPOINTER(1,"Clock"),(real64_t *) RING_API_GETCPOINTER(2,"real64_t"),(real64_t *) RING_API_GETCPOINTER(3,"real64_t")));
}


RING_FUNC(ring_clock_reset)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	clock_reset((Clock *) RING_API_GETCPOINTER(1,"Clock"));
}


RING_FUNC(ring_clock_elapsed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(clock_elapsed((Clock *) RING_API_GETCPOINTER(1,"Clock")));
}


RING_FUNC(ring_buffer_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(buffer_create( (const uint32_t ) RING_API_GETNUMBER(1)),"Buffer");
}


RING_FUNC(ring_buffer_with_data)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(buffer_with_data(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)),"Buffer");
}


RING_FUNC(ring_buffer_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	buffer_destroy((Buffer **) RING_API_GETCPOINTER2POINTER(1,"Buffer"));
}


RING_FUNC(ring_buffer_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(buffer_size((Buffer *) RING_API_GETCPOINTER(1,"Buffer")));
}


RING_FUNC(ring_buffer_data)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(buffer_data((Buffer *) RING_API_GETCPOINTER(1,"Buffer")));
}


RING_FUNC(ring_buffer_const)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(buffer_const((Buffer *) RING_API_GETCPOINTER(1,"Buffer")));
}


RING_FUNC(ring_bhash_from_block)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bhash_from_block(RING_API_GETSTRING(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bhash_append_uint32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bhash_append_uint32( (const uint32_t ) RING_API_GETNUMBER(1), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_bhash_append_real32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bhash_append_real32( (const uint32_t ) RING_API_GETNUMBER(1), (const real32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_array_create)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(array_create( (const uint16_t ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2)),"Array");
}


RING_FUNC(ring_array_copy)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(array_copy((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_scopy  *) RING_API_GETCPOINTER(2,"FPtr_scopy"),RING_API_GETSTRING(3)),"Array");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_scopy"));
}


RING_FUNC(ring_array_copy_ptr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(array_copy_ptr((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_copy  *) RING_API_GETCPOINTER(2,"FPtr_copy"),RING_API_GETSTRING(3)),"Array");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_copy"));
}


RING_FUNC(ring_array_read)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(array_read((Stream *) RING_API_GETCPOINTER(1,"Stream"), (const uint16_t ) RING_API_GETNUMBER(2),* (FPtr_read_init  *) RING_API_GETCPOINTER(3,"FPtr_read_init"),RING_API_GETSTRING(4)),"Array");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_read_init"));
}


RING_FUNC(ring_array_read_ptr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(array_read_ptr((Stream *) RING_API_GETCPOINTER(1,"Stream"),* (FPtr_read  *) RING_API_GETCPOINTER(2,"FPtr_read"),RING_API_GETSTRING(3)),"Array");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_read"));
}


RING_FUNC(ring_array_destroy)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_destroy((Array **) RING_API_GETCPOINTER2POINTER(1,"Array"),* (FPtr_remove  *) RING_API_GETCPOINTER(2,"FPtr_remove"),RING_API_GETSTRING(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_remove"));
}


RING_FUNC(ring_array_destopt)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_destopt((Array **) RING_API_GETCPOINTER2POINTER(1,"Array"),* (FPtr_remove  *) RING_API_GETCPOINTER(2,"FPtr_remove"),RING_API_GETSTRING(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_remove"));
}


RING_FUNC(ring_array_destroy_ptr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_destroy_ptr((Array **) RING_API_GETCPOINTER2POINTER(1,"Array"),* (FPtr_destroy  *) RING_API_GETCPOINTER(2,"FPtr_destroy"),RING_API_GETSTRING(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_destroy"));
}


RING_FUNC(ring_array_destopt_ptr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_destopt_ptr((Array **) RING_API_GETCPOINTER2POINTER(1,"Array"),* (FPtr_destroy  *) RING_API_GETCPOINTER(2,"FPtr_destroy"),RING_API_GETSTRING(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_destroy"));
}


RING_FUNC(ring_array_clear)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_clear((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_remove  *) RING_API_GETCPOINTER(2,"FPtr_remove"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_remove"));
}


RING_FUNC(ring_array_clear_ptr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_clear_ptr((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_destroy  *) RING_API_GETCPOINTER(2,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_destroy"));
}


RING_FUNC(ring_array_write)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_write((Stream *) RING_API_GETCPOINTER(1,"Stream"),(Array *) RING_API_GETCPOINTER(2,"Array"),* (FPtr_write  *) RING_API_GETCPOINTER(3,"FPtr_write"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_write"));
}


RING_FUNC(ring_array_write_ptr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_write_ptr((Stream *) RING_API_GETCPOINTER(1,"Stream"),(Array *) RING_API_GETCPOINTER(2,"Array"),* (FPtr_write  *) RING_API_GETCPOINTER(3,"FPtr_write"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_write"));
}


RING_FUNC(ring_array_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(array_size((Array *) RING_API_GETCPOINTER(1,"Array")));
}


RING_FUNC(ring_array_esize)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(array_esize((Array *) RING_API_GETCPOINTER(1,"Array")));
}


RING_FUNC(ring_array_get)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(array_get((Array *) RING_API_GETCPOINTER(1,"Array"), (const uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_array_get_last)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(array_get_last((Array *) RING_API_GETCPOINTER(1,"Array")));
}


RING_FUNC(ring_array_all)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(array_all((Array *) RING_API_GETCPOINTER(1,"Array")));
}


RING_FUNC(ring_array_insert)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(array_insert((Array *) RING_API_GETCPOINTER(1,"Array"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_array_insert0)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(array_insert0((Array *) RING_API_GETCPOINTER(1,"Array"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_array_join)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_join((Array *) RING_API_GETCPOINTER(1,"Array"),(Array *) RING_API_GETCPOINTER(2,"Array"),* (FPtr_scopy  *) RING_API_GETCPOINTER(3,"FPtr_scopy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_scopy"));
}


RING_FUNC(ring_array_join_ptr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_join_ptr((Array *) RING_API_GETCPOINTER(1,"Array"),(Array *) RING_API_GETCPOINTER(2,"Array"),* (FPtr_copy  *) RING_API_GETCPOINTER(3,"FPtr_copy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_copy"));
}


RING_FUNC(ring_array_delete)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_delete((Array *) RING_API_GETCPOINTER(1,"Array"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3),* (FPtr_remove  *) RING_API_GETCPOINTER(4,"FPtr_remove"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_remove"));
}


RING_FUNC(ring_array_delete_ptr)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_delete_ptr((Array *) RING_API_GETCPOINTER(1,"Array"), (const uint32_t ) RING_API_GETNUMBER(2), (const uint32_t ) RING_API_GETNUMBER(3),* (FPtr_destroy  *) RING_API_GETCPOINTER(4,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_destroy"));
}


RING_FUNC(ring_array_pop)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_pop((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_remove  *) RING_API_GETCPOINTER(2,"FPtr_remove"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_remove"));
}


RING_FUNC(ring_array_pop_ptr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_pop_ptr((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_destroy  *) RING_API_GETCPOINTER(2,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_destroy"));
}


RING_FUNC(ring_array_sort)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_sort((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_compare  *) RING_API_GETCPOINTER(2,"FPtr_compare"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_compare"));
}


RING_FUNC(ring_array_sort_ex)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_sort_ex((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_compare_ex  *) RING_API_GETCPOINTER(2,"FPtr_compare_ex"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_compare_ex"));
}


RING_FUNC(ring_array_sort_ptr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_sort_ptr((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_compare  *) RING_API_GETCPOINTER(2,"FPtr_compare"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_compare"));
}


RING_FUNC(ring_array_sort_ptr_ex)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	array_sort_ptr_ex((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_compare_ex  *) RING_API_GETCPOINTER(2,"FPtr_compare_ex"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_compare_ex"));
}


RING_FUNC(ring_array_find_ptr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(array_find_ptr((Array *) RING_API_GETCPOINTER(1,"Array"),(void *) RING_API_GETCPOINTER(2,"void")));
}


RING_FUNC(ring_array_search)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(array_search((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_compare  *) RING_API_GETCPOINTER(2,"FPtr_compare"),(void *) RING_API_GETCPOINTER(3,"void"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_compare"));
}


RING_FUNC(ring_array_search_ptr)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(array_search_ptr((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_compare  *) RING_API_GETCPOINTER(2,"FPtr_compare"),(void *) RING_API_GETCPOINTER(3,"void"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_compare"));
}


RING_FUNC(ring_array_bsearch)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(array_bsearch((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_compare  *) RING_API_GETCPOINTER(2,"FPtr_compare"),(void *) RING_API_GETCPOINTER(3,"void"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_compare"));
}


RING_FUNC(ring_array_bsearch_ptr)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(array_bsearch_ptr((Array *) RING_API_GETCPOINTER(1,"Array"),* (FPtr_compare  *) RING_API_GETCPOINTER(2,"FPtr_compare"),(void *) RING_API_GETCPOINTER(3,"void"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_compare"));
}

RING_LIBINIT
{
	RING_API_REGISTER("osmain",ring_osmain);
	RING_API_REGISTER("guievent",ring_guievent);
	RING_API_REGISTER("cleanguievents",ring_cleanguievents);
	RING_API_REGISTER("unicode_convers",ring_unicode_convers);
	RING_API_REGISTER("unicode_convers_n",ring_unicode_convers_n);
	RING_API_REGISTER("unicode_convers_nbytes",ring_unicode_convers_nbytes);
	RING_API_REGISTER("unicode_nbytes",ring_unicode_nbytes);
	RING_API_REGISTER("unicode_nchars",ring_unicode_nchars);
	RING_API_REGISTER("unicode_to_u32",ring_unicode_to_u32);
	RING_API_REGISTER("unicode_to_u32b",ring_unicode_to_u32b);
	RING_API_REGISTER("unicode_to_char",ring_unicode_to_char);
	RING_API_REGISTER("unicode_valid_str",ring_unicode_valid_str);
	RING_API_REGISTER("unicode_valid_str_n",ring_unicode_valid_str_n);
	RING_API_REGISTER("unicode_valid",ring_unicode_valid);
	RING_API_REGISTER("unicode_next",ring_unicode_next);
	RING_API_REGISTER("unicode_back",ring_unicode_back);
	RING_API_REGISTER("unicode_isascii",ring_unicode_isascii);
	RING_API_REGISTER("unicode_isalnum",ring_unicode_isalnum);
	RING_API_REGISTER("unicode_isalpha",ring_unicode_isalpha);
	RING_API_REGISTER("unicode_iscntrl",ring_unicode_iscntrl);
	RING_API_REGISTER("unicode_isdigit",ring_unicode_isdigit);
	RING_API_REGISTER("unicode_isgraph",ring_unicode_isgraph);
	RING_API_REGISTER("unicode_isprint",ring_unicode_isprint);
	RING_API_REGISTER("unicode_ispunct",ring_unicode_ispunct);
	RING_API_REGISTER("unicode_isspace",ring_unicode_isspace);
	RING_API_REGISTER("unicode_isxdigit",ring_unicode_isxdigit);
	RING_API_REGISTER("unicode_islower",ring_unicode_islower);
	RING_API_REGISTER("unicode_isupper",ring_unicode_isupper);
	RING_API_REGISTER("unicode_tolower",ring_unicode_tolower);
	RING_API_REGISTER("unicode_toupper",ring_unicode_toupper);
	RING_API_REGISTER("min_u32",ring_min_u32);
	RING_API_REGISTER("min_r32",ring_min_r32);
	RING_API_REGISTER("min_r64",ring_min_r64);
	RING_API_REGISTER("max_u32",ring_max_u32);
	RING_API_REGISTER("max_r32",ring_max_r32);
	RING_API_REGISTER("max_r64",ring_max_r64);
	RING_API_REGISTER("abs_r32",ring_abs_r32);
	RING_API_REGISTER("to_u8",ring_to_u8);
	RING_API_REGISTER("sewer_start",ring_sewer_start);
	RING_API_REGISTER("sewer_finish",ring_sewer_finish);
	RING_API_REGISTER("sewer_nappgui_major",ring_sewer_nappgui_major);
	RING_API_REGISTER("sewer_nappgui_minor",ring_sewer_nappgui_minor);
	RING_API_REGISTER("sewer_nappgui_patch",ring_sewer_nappgui_patch);
	RING_API_REGISTER("sewer_nappgui_build",ring_sewer_nappgui_build);
	RING_API_REGISTER("sewer_nappgui_version",ring_sewer_nappgui_version);
	RING_API_REGISTER("ptr_dget_imp",ring_ptr_dget_imp);
	RING_API_REGISTER("ptr_dget_no_null_imp",ring_ptr_dget_no_null_imp);
	RING_API_REGISTER("ptr_destopt_imp",ring_ptr_destopt_imp);
	RING_API_REGISTER("ptr_copyopt_imp",ring_ptr_copyopt_imp);
	RING_API_REGISTER("cassert_set_func",ring_cassert_set_func);
	RING_API_REGISTER("cassert_imp",ring_cassert_imp);
	RING_API_REGISTER("cassert_fatal_imp",ring_cassert_fatal_imp);
	RING_API_REGISTER("cassert_no_null_imp",ring_cassert_no_null_imp);
	RING_API_REGISTER("cassert_default_imp",ring_cassert_default_imp);
	RING_API_REGISTER("bstd_vsprintf",ring_bstd_vsprintf);
	RING_API_REGISTER("bstd_writef",ring_bstd_writef);
	RING_API_REGISTER("bstd_ewritef",ring_bstd_ewritef);
	RING_API_REGISTER("bstd_read",ring_bstd_read);
	RING_API_REGISTER("bstd_write",ring_bstd_write);
	RING_API_REGISTER("bstd_ewrite",ring_bstd_ewrite);
	RING_API_REGISTER("bmem_aligned_malloc",ring_bmem_aligned_malloc);
	RING_API_REGISTER("bmem_aligned_realloc",ring_bmem_aligned_realloc);
	RING_API_REGISTER("bmem_free",ring_bmem_free);
	RING_API_REGISTER("bmem_set1",ring_bmem_set1);
	RING_API_REGISTER("bmem_set4",ring_bmem_set4);
	RING_API_REGISTER("bmem_set8",ring_bmem_set8);
	RING_API_REGISTER("bmem_set16",ring_bmem_set16);
	RING_API_REGISTER("bmem_cmp",ring_bmem_cmp);
	RING_API_REGISTER("bmem_is_zero",ring_bmem_is_zero);
	RING_API_REGISTER("bmem_set_zero",ring_bmem_set_zero);
	RING_API_REGISTER("bmem_copy",ring_bmem_copy);
	RING_API_REGISTER("bmem_move",ring_bmem_move);
	RING_API_REGISTER("bmem_overlaps",ring_bmem_overlaps);
	RING_API_REGISTER("bmem_rev",ring_bmem_rev);
	RING_API_REGISTER("bmem_rev2",ring_bmem_rev2);
	RING_API_REGISTER("bmem_rev4",ring_bmem_rev4);
	RING_API_REGISTER("bmem_rev8",ring_bmem_rev8);
	RING_API_REGISTER("bmem_revcopy",ring_bmem_revcopy);
	RING_API_REGISTER("bmem_rev_elems_imp",ring_bmem_rev_elems_imp);
	RING_API_REGISTER("bmem_swap",ring_bmem_swap);
	RING_API_REGISTER("bmem_shuffle",ring_bmem_shuffle);
	RING_API_REGISTER("bmath_cosf",ring_bmath_cosf);
	RING_API_REGISTER("bmath_cosd",ring_bmath_cosd);
	RING_API_REGISTER("bmath_sinf",ring_bmath_sinf);
	RING_API_REGISTER("bmath_sind",ring_bmath_sind);
	RING_API_REGISTER("bmath_tanf",ring_bmath_tanf);
	RING_API_REGISTER("bmath_tand",ring_bmath_tand);
	RING_API_REGISTER("bmath_acosf",ring_bmath_acosf);
	RING_API_REGISTER("bmath_acosd",ring_bmath_acosd);
	RING_API_REGISTER("bmath_asinf",ring_bmath_asinf);
	RING_API_REGISTER("bmath_asind",ring_bmath_asind);
	RING_API_REGISTER("bmath_atan2f",ring_bmath_atan2f);
	RING_API_REGISTER("bmath_atan2d",ring_bmath_atan2d);
	RING_API_REGISTER("bmath_norm_anglef",ring_bmath_norm_anglef);
	RING_API_REGISTER("bmath_norm_angled",ring_bmath_norm_angled);
	RING_API_REGISTER("bmath_sqrtf",ring_bmath_sqrtf);
	RING_API_REGISTER("bmath_sqrtd",ring_bmath_sqrtd);
	RING_API_REGISTER("bmath_isqrtf",ring_bmath_isqrtf);
	RING_API_REGISTER("bmath_isqrtd",ring_bmath_isqrtd);
	RING_API_REGISTER("bmath_logf",ring_bmath_logf);
	RING_API_REGISTER("bmath_logd",ring_bmath_logd);
	RING_API_REGISTER("bmath_log10f",ring_bmath_log10f);
	RING_API_REGISTER("bmath_log10d",ring_bmath_log10d);
	RING_API_REGISTER("bmath_expf",ring_bmath_expf);
	RING_API_REGISTER("bmath_expd",ring_bmath_expd);
	RING_API_REGISTER("bmath_powf",ring_bmath_powf);
	RING_API_REGISTER("bmath_powd",ring_bmath_powd);
	RING_API_REGISTER("bmath_absf",ring_bmath_absf);
	RING_API_REGISTER("bmath_absd",ring_bmath_absd);
	RING_API_REGISTER("bmath_maxf",ring_bmath_maxf);
	RING_API_REGISTER("bmath_maxd",ring_bmath_maxd);
	RING_API_REGISTER("bmath_minf",ring_bmath_minf);
	RING_API_REGISTER("bmath_mind",ring_bmath_mind);
	RING_API_REGISTER("bmath_clampf",ring_bmath_clampf);
	RING_API_REGISTER("bmath_clampd",ring_bmath_clampd);
	RING_API_REGISTER("bmath_modf",ring_bmath_modf);
	RING_API_REGISTER("bmath_modd",ring_bmath_modd);
	RING_API_REGISTER("bmath_modff",ring_bmath_modff);
	RING_API_REGISTER("bmath_modfd",ring_bmath_modfd);
	RING_API_REGISTER("bmath_precf",ring_bmath_precf);
	RING_API_REGISTER("bmath_precd",ring_bmath_precd);
	RING_API_REGISTER("bmath_roundf",ring_bmath_roundf);
	RING_API_REGISTER("bmath_roundd",ring_bmath_roundd);
	RING_API_REGISTER("bmath_round_stepf",ring_bmath_round_stepf);
	RING_API_REGISTER("bmath_round_stepd",ring_bmath_round_stepd);
	RING_API_REGISTER("bmath_floorf",ring_bmath_floorf);
	RING_API_REGISTER("bmath_floord",ring_bmath_floord);
	RING_API_REGISTER("bmath_ceilf",ring_bmath_ceilf);
	RING_API_REGISTER("bmath_ceild",ring_bmath_ceild);
	RING_API_REGISTER("bmath_rand_seed",ring_bmath_rand_seed);
	RING_API_REGISTER("bmath_randf",ring_bmath_randf);
	RING_API_REGISTER("bmath_randd",ring_bmath_randd);
	RING_API_REGISTER("bmath_randi",ring_bmath_randi);
	RING_API_REGISTER("bmath_rand_env",ring_bmath_rand_env);
	RING_API_REGISTER("bmath_rand_destroy",ring_bmath_rand_destroy);
	RING_API_REGISTER("bmath_rand_mtf",ring_bmath_rand_mtf);
	RING_API_REGISTER("bmath_rand_mtd",ring_bmath_rand_mtd);
	RING_API_REGISTER("bmath_rand_mti",ring_bmath_rand_mti);
	RING_API_REGISTER("blib_strlen",ring_blib_strlen);
	RING_API_REGISTER("blib_strstr",ring_blib_strstr);
	RING_API_REGISTER("blib_strcpy",ring_blib_strcpy);
	RING_API_REGISTER("blib_strncpy",ring_blib_strncpy);
	RING_API_REGISTER("blib_strcat",ring_blib_strcat);
	RING_API_REGISTER("blib_strcmp",ring_blib_strcmp);
	RING_API_REGISTER("blib_strncmp",ring_blib_strncmp);
	RING_API_REGISTER("blib_strftime",ring_blib_strftime);
	RING_API_REGISTER("blib_strtol",ring_blib_strtol);
	RING_API_REGISTER("blib_strtoul",ring_blib_strtoul);
	RING_API_REGISTER("blib_strtof",ring_blib_strtof);
	RING_API_REGISTER("blib_strtod",ring_blib_strtod);
	RING_API_REGISTER("blib_qsort",ring_blib_qsort);
	RING_API_REGISTER("blib_qsort_ex",ring_blib_qsort_ex);
	RING_API_REGISTER("blib_bsearch",ring_blib_bsearch);
	RING_API_REGISTER("blib_bsearch_ex",ring_blib_bsearch_ex);
	RING_API_REGISTER("blib_getenv",ring_blib_getenv);
	RING_API_REGISTER("blib_abort",ring_blib_abort);
	RING_API_REGISTER("blib_exit",ring_blib_exit);
	RING_API_REGISTER("blib_debug_break",ring_blib_debug_break);
	RING_API_REGISTER("oswindow_create",ring_oswindow_create);
	RING_API_REGISTER("oswindow_managed",ring_oswindow_managed);
	RING_API_REGISTER("oswindow_destroy",ring_oswindow_destroy);
	RING_API_REGISTER("oswindow_onmoved",ring_oswindow_OnMoved);
	RING_API_REGISTER("oswindow_onresize",ring_oswindow_OnResize);
	RING_API_REGISTER("oswindow_onclose",ring_oswindow_OnClose);
	RING_API_REGISTER("oswindow_title",ring_oswindow_title);
	RING_API_REGISTER("oswindow_edited",ring_oswindow_edited);
	RING_API_REGISTER("oswindow_movable",ring_oswindow_movable);
	RING_API_REGISTER("oswindow_z_order",ring_oswindow_z_order);
	RING_API_REGISTER("oswindow_alpha",ring_oswindow_alpha);
	RING_API_REGISTER("oswindow_enable_mouse_events",ring_oswindow_enable_mouse_events);
	RING_API_REGISTER("oswindow_hotkey",ring_oswindow_hotkey);
	RING_API_REGISTER("oswindow_taborder",ring_oswindow_taborder);
	RING_API_REGISTER("oswindow_tabcycle",ring_oswindow_tabcycle);
	RING_API_REGISTER("oswindow_tabstop",ring_oswindow_tabstop);
	RING_API_REGISTER("oswindow_focus",ring_oswindow_focus);
	RING_API_REGISTER("oswindow_get_focus",ring_oswindow_get_focus);
	RING_API_REGISTER("oswindow_info_focus",ring_oswindow_info_focus);
	RING_API_REGISTER("oswindow_attach_panel",ring_oswindow_attach_panel);
	RING_API_REGISTER("oswindow_detach_panel",ring_oswindow_detach_panel);
	RING_API_REGISTER("oswindow_attach_window",ring_oswindow_attach_window);
	RING_API_REGISTER("oswindow_detach_window",ring_oswindow_detach_window);
	RING_API_REGISTER("oswindow_launch",ring_oswindow_launch);
	RING_API_REGISTER("oswindow_hide",ring_oswindow_hide);
	RING_API_REGISTER("oswindow_launch_modal",ring_oswindow_launch_modal);
	RING_API_REGISTER("oswindow_stop_modal",ring_oswindow_stop_modal);
	RING_API_REGISTER("oswindow_get_origin",ring_oswindow_get_origin);
	RING_API_REGISTER("oswindow_origin",ring_oswindow_origin);
	RING_API_REGISTER("oswindow_get_size",ring_oswindow_get_size);
	RING_API_REGISTER("oswindow_size",ring_oswindow_size);
	RING_API_REGISTER("oswindow_set_default_pushbutton",ring_oswindow_set_default_pushbutton);
	RING_API_REGISTER("oswindow_set_cursor",ring_oswindow_set_cursor);
	RING_API_REGISTER("oswindow_property",ring_oswindow_property);
	RING_API_REGISTER("osview_create",ring_osview_create);
	RING_API_REGISTER("osview_destroy",ring_osview_destroy);
	RING_API_REGISTER("osview_ondraw",ring_osview_OnDraw);
	RING_API_REGISTER("osview_onoverlay",ring_osview_OnOverlay);
	RING_API_REGISTER("osview_onenter",ring_osview_OnEnter);
	RING_API_REGISTER("osview_onexit",ring_osview_OnExit);
	RING_API_REGISTER("osview_onmoved",ring_osview_OnMoved);
	RING_API_REGISTER("osview_ondown",ring_osview_OnDown);
	RING_API_REGISTER("osview_onup",ring_osview_OnUp);
	RING_API_REGISTER("osview_onclick",ring_osview_OnClick);
	RING_API_REGISTER("osview_ondrag",ring_osview_OnDrag);
	RING_API_REGISTER("osview_onwheel",ring_osview_OnWheel);
	RING_API_REGISTER("osview_onkeydown",ring_osview_OnKeyDown);
	RING_API_REGISTER("osview_onkeyup",ring_osview_OnKeyUp);
	RING_API_REGISTER("osview_onfocus",ring_osview_OnFocus);
	RING_API_REGISTER("osview_onresignfocus",ring_osview_OnResignFocus);
	RING_API_REGISTER("osview_onacceptfocus",ring_osview_OnAcceptFocus);
	RING_API_REGISTER("osview_onscroll",ring_osview_OnScroll);
	RING_API_REGISTER("osview_scroll",ring_osview_scroll);
	RING_API_REGISTER("osview_scroll_get",ring_osview_scroll_get);
	RING_API_REGISTER("osview_scroller_size",ring_osview_scroller_size);
	RING_API_REGISTER("osview_scroller_visible",ring_osview_scroller_visible);
	RING_API_REGISTER("osview_content_size",ring_osview_content_size);
	RING_API_REGISTER("osview_scale_factor",ring_osview_scale_factor);
	RING_API_REGISTER("osview_set_need_display",ring_osview_set_need_display);
	RING_API_REGISTER("osview_get_native_view",ring_osview_get_native_view);
	RING_API_REGISTER("osview_attach",ring_osview_attach);
	RING_API_REGISTER("osview_detach",ring_osview_detach);
	RING_API_REGISTER("osview_visible",ring_osview_visible);
	RING_API_REGISTER("osview_enabled",ring_osview_enabled);
	RING_API_REGISTER("osview_size",ring_osview_size);
	RING_API_REGISTER("osview_origin",ring_osview_origin);
	RING_API_REGISTER("osview_frame",ring_osview_frame);
	RING_API_REGISTER("osupdown_create",ring_osupdown_create);
	RING_API_REGISTER("osupdown_destroy",ring_osupdown_destroy);
	RING_API_REGISTER("osupdown_onclick",ring_osupdown_OnClick);
	RING_API_REGISTER("osupdown_tooltip",ring_osupdown_tooltip);
	RING_API_REGISTER("osupdown_attach",ring_osupdown_attach);
	RING_API_REGISTER("osupdown_detach",ring_osupdown_detach);
	RING_API_REGISTER("osupdown_visible",ring_osupdown_visible);
	RING_API_REGISTER("osupdown_enabled",ring_osupdown_enabled);
	RING_API_REGISTER("osupdown_size",ring_osupdown_size);
	RING_API_REGISTER("osupdown_origin",ring_osupdown_origin);
	RING_API_REGISTER("osupdown_frame",ring_osupdown_frame);
	RING_API_REGISTER("ostext_create",ring_ostext_create);
	RING_API_REGISTER("ostext_destroy",ring_ostext_destroy);
	RING_API_REGISTER("ostext_onfilter",ring_ostext_OnFilter);
	RING_API_REGISTER("ostext_onfocus",ring_ostext_OnFocus);
	RING_API_REGISTER("ostext_insert_text",ring_ostext_insert_text);
	RING_API_REGISTER("ostext_set_text",ring_ostext_set_text);
	RING_API_REGISTER("ostext_set_rtf",ring_ostext_set_rtf);
	RING_API_REGISTER("ostext_property",ring_ostext_property);
	RING_API_REGISTER("ostext_editable",ring_ostext_editable);
	RING_API_REGISTER("ostext_get_text",ring_ostext_get_text);
	RING_API_REGISTER("ostext_scroller_visible",ring_ostext_scroller_visible);
	RING_API_REGISTER("ostext_set_need_display",ring_ostext_set_need_display);
	RING_API_REGISTER("ostext_clipboard",ring_ostext_clipboard);
	RING_API_REGISTER("ostext_attach",ring_ostext_attach);
	RING_API_REGISTER("ostext_detach",ring_ostext_detach);
	RING_API_REGISTER("ostext_visible",ring_ostext_visible);
	RING_API_REGISTER("ostext_enabled",ring_ostext_enabled);
	RING_API_REGISTER("ostext_size",ring_ostext_size);
	RING_API_REGISTER("ostext_origin",ring_ostext_origin);
	RING_API_REGISTER("ostext_frame",ring_ostext_frame);
	RING_API_REGISTER("ossplit_create",ring_ossplit_create);
	RING_API_REGISTER("ossplit_destroy",ring_ossplit_destroy);
	RING_API_REGISTER("ossplit_attach_control",ring_ossplit_attach_control);
	RING_API_REGISTER("ossplit_detach_control",ring_ossplit_detach_control);
	RING_API_REGISTER("ossplit_ondrag",ring_ossplit_OnDrag);
	RING_API_REGISTER("ossplit_track_area",ring_ossplit_track_area);
	RING_API_REGISTER("ossplit_attach",ring_ossplit_attach);
	RING_API_REGISTER("ossplit_detach",ring_ossplit_detach);
	RING_API_REGISTER("ossplit_visible",ring_ossplit_visible);
	RING_API_REGISTER("ossplit_enabled",ring_ossplit_enabled);
	RING_API_REGISTER("ossplit_size",ring_ossplit_size);
	RING_API_REGISTER("ossplit_origin",ring_ossplit_origin);
	RING_API_REGISTER("ossplit_frame",ring_ossplit_frame);
	RING_API_REGISTER("osslider_create",ring_osslider_create);
	RING_API_REGISTER("osslider_destroy",ring_osslider_destroy);
	RING_API_REGISTER("osslider_onmoved",ring_osslider_OnMoved);
	RING_API_REGISTER("osslider_tooltip",ring_osslider_tooltip);
	RING_API_REGISTER("osslider_tickmarks",ring_osslider_tickmarks);
	RING_API_REGISTER("osslider_position",ring_osslider_position);
	RING_API_REGISTER("osslider_get_position",ring_osslider_get_position);
	RING_API_REGISTER("osslider_bounds",ring_osslider_bounds);
	RING_API_REGISTER("osslider_attach",ring_osslider_attach);
	RING_API_REGISTER("osslider_detach",ring_osslider_detach);
	RING_API_REGISTER("osslider_visible",ring_osslider_visible);
	RING_API_REGISTER("osslider_enabled",ring_osslider_enabled);
	RING_API_REGISTER("osslider_size",ring_osslider_size);
	RING_API_REGISTER("osslider_origin",ring_osslider_origin);
	RING_API_REGISTER("osslider_frame",ring_osslider_frame);
	RING_API_REGISTER("osprogress_create",ring_osprogress_create);
	RING_API_REGISTER("osprogress_destroy",ring_osprogress_destroy);
	RING_API_REGISTER("osprogress_position",ring_osprogress_position);
	RING_API_REGISTER("osprogress_thickness",ring_osprogress_thickness);
	RING_API_REGISTER("osprogress_attach",ring_osprogress_attach);
	RING_API_REGISTER("osprogress_detach",ring_osprogress_detach);
	RING_API_REGISTER("osprogress_visible",ring_osprogress_visible);
	RING_API_REGISTER("osprogress_enabled",ring_osprogress_enabled);
	RING_API_REGISTER("osprogress_size",ring_osprogress_size);
	RING_API_REGISTER("osprogress_origin",ring_osprogress_origin);
	RING_API_REGISTER("osprogress_frame",ring_osprogress_frame);
	RING_API_REGISTER("ospopup_create",ring_ospopup_create);
	RING_API_REGISTER("ospopup_destroy",ring_ospopup_destroy);
	RING_API_REGISTER("ospopup_onselect",ring_ospopup_OnSelect);
	RING_API_REGISTER("ospopup_elem",ring_ospopup_elem);
	RING_API_REGISTER("ospopup_tooltip",ring_ospopup_tooltip);
	RING_API_REGISTER("ospopup_font",ring_ospopup_font);
	RING_API_REGISTER("ospopup_list_height",ring_ospopup_list_height);
	RING_API_REGISTER("ospopup_selected",ring_ospopup_selected);
	RING_API_REGISTER("ospopup_get_selected",ring_ospopup_get_selected);
	RING_API_REGISTER("ospopup_bounds",ring_ospopup_bounds);
	RING_API_REGISTER("ospopup_attach",ring_ospopup_attach);
	RING_API_REGISTER("ospopup_detach",ring_ospopup_detach);
	RING_API_REGISTER("ospopup_visible",ring_ospopup_visible);
	RING_API_REGISTER("ospopup_enabled",ring_ospopup_enabled);
	RING_API_REGISTER("ospopup_size",ring_ospopup_size);
	RING_API_REGISTER("ospopup_origin",ring_ospopup_origin);
	RING_API_REGISTER("ospopup_frame",ring_ospopup_frame);
	RING_API_REGISTER("ospanel_create",ring_ospanel_create);
	RING_API_REGISTER("ospanel_destroy",ring_ospanel_destroy);
	RING_API_REGISTER("ospanel_area",ring_ospanel_area);
	RING_API_REGISTER("ospanel_scroller_size",ring_ospanel_scroller_size);
	RING_API_REGISTER("ospanel_content_size",ring_ospanel_content_size);
	RING_API_REGISTER("ospanel_display",ring_ospanel_display);
	RING_API_REGISTER("ospanel_attach",ring_ospanel_attach);
	RING_API_REGISTER("ospanel_detach",ring_ospanel_detach);
	RING_API_REGISTER("ospanel_visible",ring_ospanel_visible);
	RING_API_REGISTER("ospanel_enabled",ring_ospanel_enabled);
	RING_API_REGISTER("ospanel_size",ring_ospanel_size);
	RING_API_REGISTER("ospanel_origin",ring_ospanel_origin);
	RING_API_REGISTER("ospanel_frame",ring_ospanel_frame);
	RING_API_REGISTER("osmenuitem_create",ring_osmenuitem_create);
	RING_API_REGISTER("osmenuitem_destroy",ring_osmenuitem_destroy);
	RING_API_REGISTER("osmenuitem_onclick",ring_osmenuitem_OnClick);
	RING_API_REGISTER("osmenuitem_enabled",ring_osmenuitem_enabled);
	RING_API_REGISTER("osmenuitem_visible",ring_osmenuitem_visible);
	RING_API_REGISTER("osmenuitem_text",ring_osmenuitem_text);
	RING_API_REGISTER("osmenuitem_image",ring_osmenuitem_image);
	RING_API_REGISTER("osmenuitem_key",ring_osmenuitem_key);
	RING_API_REGISTER("osmenuitem_state",ring_osmenuitem_state);
	RING_API_REGISTER("osmenuitem_submenu",ring_osmenuitem_submenu);
	RING_API_REGISTER("osmenuitem_unset_submenu",ring_osmenuitem_unset_submenu);
	RING_API_REGISTER("osmenu_create",ring_osmenu_create);
	RING_API_REGISTER("osmenu_destroy",ring_osmenu_destroy);
	RING_API_REGISTER("osmenu_add_item",ring_osmenu_add_item);
	RING_API_REGISTER("osmenu_delete_item",ring_osmenu_delete_item);
	RING_API_REGISTER("osmenu_launch",ring_osmenu_launch);
	RING_API_REGISTER("osmenu_hide",ring_osmenu_hide);
	RING_API_REGISTER("oslabel_create",ring_oslabel_create);
	RING_API_REGISTER("oslabel_destroy",ring_oslabel_destroy);
	RING_API_REGISTER("oslabel_onclick",ring_oslabel_OnClick);
	RING_API_REGISTER("oslabel_onenter",ring_oslabel_OnEnter);
	RING_API_REGISTER("oslabel_onexit",ring_oslabel_OnExit);
	RING_API_REGISTER("oslabel_text",ring_oslabel_text);
	RING_API_REGISTER("oslabel_font",ring_oslabel_font);
	RING_API_REGISTER("oslabel_align",ring_oslabel_align);
	RING_API_REGISTER("oslabel_ellipsis",ring_oslabel_ellipsis);
	RING_API_REGISTER("oslabel_color",ring_oslabel_color);
	RING_API_REGISTER("oslabel_bgcolor",ring_oslabel_bgcolor);
	RING_API_REGISTER("oslabel_bounds",ring_oslabel_bounds);
	RING_API_REGISTER("oslabel_attach",ring_oslabel_attach);
	RING_API_REGISTER("oslabel_detach",ring_oslabel_detach);
	RING_API_REGISTER("oslabel_visible",ring_oslabel_visible);
	RING_API_REGISTER("oslabel_enabled",ring_oslabel_enabled);
	RING_API_REGISTER("oslabel_size",ring_oslabel_size);
	RING_API_REGISTER("oslabel_origin",ring_oslabel_origin);
	RING_API_REGISTER("oslabel_frame",ring_oslabel_frame);
	RING_API_REGISTER("osguictx",ring_osguictx);
	RING_API_REGISTER("osgui_start",ring_osgui_start);
	RING_API_REGISTER("osgui_finish",ring_osgui_finish);
	RING_API_REGISTER("osgui_set_menubar",ring_osgui_set_menubar);
	RING_API_REGISTER("osgui_unset_menubar",ring_osgui_unset_menubar);
	RING_API_REGISTER("osgui_redraw_menubar",ring_osgui_redraw_menubar);
	RING_API_REGISTER("osgui_message_loop",ring_osgui_message_loop);
	RING_API_REGISTER("osgui_is_initialized",ring_osgui_is_initialized);
	RING_API_REGISTER("osgui_initialize",ring_osgui_initialize);
	RING_API_REGISTER("osgui_terminate",ring_osgui_terminate);
	RING_API_REGISTER("osgui_set_app",ring_osgui_set_app);
	RING_API_REGISTER("osglobals_device",ring_osglobals_device);
	RING_API_REGISTER("osglobals_color",ring_osglobals_color);
	RING_API_REGISTER("osglobals_resolution",ring_osglobals_resolution);
	RING_API_REGISTER("osglobals_mouse_position",ring_osglobals_mouse_position);
	RING_API_REGISTER("osglobals_cursor",ring_osglobals_cursor);
	RING_API_REGISTER("osglobals_cursor_destroy",ring_osglobals_cursor_destroy);
	RING_API_REGISTER("osglobals_value",ring_osglobals_value);
	RING_API_REGISTER("osglobals_transitions",ring_osglobals_transitions);
	RING_API_REGISTER("osglobals_onidle",ring_osglobals_OnIdle);
	RING_API_REGISTER("osedit_create",ring_osedit_create);
	RING_API_REGISTER("osedit_destroy",ring_osedit_destroy);
	RING_API_REGISTER("osedit_onfilter",ring_osedit_OnFilter);
	RING_API_REGISTER("osedit_onchange",ring_osedit_OnChange);
	RING_API_REGISTER("osedit_onfocus",ring_osedit_OnFocus);
	RING_API_REGISTER("osedit_text",ring_osedit_text);
	RING_API_REGISTER("osedit_tooltip",ring_osedit_tooltip);
	RING_API_REGISTER("osedit_font",ring_osedit_font);
	RING_API_REGISTER("osedit_align",ring_osedit_align);
	RING_API_REGISTER("osedit_passmode",ring_osedit_passmode);
	RING_API_REGISTER("osedit_editable",ring_osedit_editable);
	RING_API_REGISTER("osedit_autoselect",ring_osedit_autoselect);
	RING_API_REGISTER("osedit_select",ring_osedit_select);
	RING_API_REGISTER("osedit_color",ring_osedit_color);
	RING_API_REGISTER("osedit_bgcolor",ring_osedit_bgcolor);
	RING_API_REGISTER("osedit_vpadding",ring_osedit_vpadding);
	RING_API_REGISTER("osedit_bounds",ring_osedit_bounds);
	RING_API_REGISTER("osedit_clipboard",ring_osedit_clipboard);
	RING_API_REGISTER("osedit_attach",ring_osedit_attach);
	RING_API_REGISTER("osedit_detach",ring_osedit_detach);
	RING_API_REGISTER("osedit_visible",ring_osedit_visible);
	RING_API_REGISTER("osedit_enabled",ring_osedit_enabled);
	RING_API_REGISTER("osedit_size",ring_osedit_size);
	RING_API_REGISTER("osedit_origin",ring_osedit_origin);
	RING_API_REGISTER("osedit_frame",ring_osedit_frame);
	RING_API_REGISTER("osdrawctrl_font",ring_osdrawctrl_font);
	RING_API_REGISTER("osdrawctrl_row_padding",ring_osdrawctrl_row_padding);
	RING_API_REGISTER("osdrawctrl_check_width",ring_osdrawctrl_check_width);
	RING_API_REGISTER("osdrawctrl_check_height",ring_osdrawctrl_check_height);
	RING_API_REGISTER("osdrawctrl_multisel",ring_osdrawctrl_multisel);
	RING_API_REGISTER("osdrawctrl_clear",ring_osdrawctrl_clear);
	RING_API_REGISTER("osdrawctrl_header",ring_osdrawctrl_header);
	RING_API_REGISTER("osdrawctrl_indicator",ring_osdrawctrl_indicator);
	RING_API_REGISTER("osdrawctrl_fill",ring_osdrawctrl_fill);
	RING_API_REGISTER("osdrawctrl_focus",ring_osdrawctrl_focus);
	RING_API_REGISTER("osdrawctrl_line",ring_osdrawctrl_line);
	RING_API_REGISTER("osdrawctrl_text",ring_osdrawctrl_text);
	RING_API_REGISTER("osdrawctrl_image",ring_osdrawctrl_image);
	RING_API_REGISTER("osdrawctrl_checkbox",ring_osdrawctrl_checkbox);
	RING_API_REGISTER("osdrawctrl_uncheckbox",ring_osdrawctrl_uncheckbox);
	RING_API_REGISTER("oscomwin_file",ring_oscomwin_file);
	RING_API_REGISTER("oscomwin_color",ring_oscomwin_color);
	RING_API_REGISTER("oscombo_create",ring_oscombo_create);
	RING_API_REGISTER("oscombo_destroy",ring_oscombo_destroy);
	RING_API_REGISTER("oscombo_onfilter",ring_oscombo_OnFilter);
	RING_API_REGISTER("oscombo_onchange",ring_oscombo_OnChange);
	RING_API_REGISTER("oscombo_onfocus",ring_oscombo_OnFocus);
	RING_API_REGISTER("oscombo_onselect",ring_oscombo_OnSelect);
	RING_API_REGISTER("oscombo_text",ring_oscombo_text);
	RING_API_REGISTER("oscombo_tooltip",ring_oscombo_tooltip);
	RING_API_REGISTER("oscombo_font",ring_oscombo_font);
	RING_API_REGISTER("oscombo_align",ring_oscombo_align);
	RING_API_REGISTER("oscombo_passmode",ring_oscombo_passmode);
	RING_API_REGISTER("oscombo_color",ring_oscombo_color);
	RING_API_REGISTER("oscombo_bgcolor",ring_oscombo_bgcolor);
	RING_API_REGISTER("oscombo_elem",ring_oscombo_elem);
	RING_API_REGISTER("oscombo_selected",ring_oscombo_selected);
	RING_API_REGISTER("oscombo_get_selected",ring_oscombo_get_selected);
	RING_API_REGISTER("oscombo_bounds",ring_oscombo_bounds);
	RING_API_REGISTER("oscombo_attach",ring_oscombo_attach);
	RING_API_REGISTER("oscombo_detach",ring_oscombo_detach);
	RING_API_REGISTER("oscombo_visible",ring_oscombo_visible);
	RING_API_REGISTER("oscombo_enabled",ring_oscombo_enabled);
	RING_API_REGISTER("oscombo_size",ring_oscombo_size);
	RING_API_REGISTER("oscombo_origin",ring_oscombo_origin);
	RING_API_REGISTER("oscombo_frame",ring_oscombo_frame);
	RING_API_REGISTER("osbutton_create",ring_osbutton_create);
	RING_API_REGISTER("osbutton_destroy",ring_osbutton_destroy);
	RING_API_REGISTER("osbutton_onclick",ring_osbutton_OnClick);
	RING_API_REGISTER("osbutton_text",ring_osbutton_text);
	RING_API_REGISTER("osbutton_tooltip",ring_osbutton_tooltip);
	RING_API_REGISTER("osbutton_font",ring_osbutton_font);
	RING_API_REGISTER("osbutton_align",ring_osbutton_align);
	RING_API_REGISTER("osbutton_image",ring_osbutton_image);
	RING_API_REGISTER("osbutton_state",ring_osbutton_state);
	RING_API_REGISTER("osbutton_get_state",ring_osbutton_get_state);
	RING_API_REGISTER("osbutton_vpadding",ring_osbutton_vpadding);
	RING_API_REGISTER("osbutton_bounds",ring_osbutton_bounds);
	RING_API_REGISTER("osbutton_attach",ring_osbutton_attach);
	RING_API_REGISTER("osbutton_detach",ring_osbutton_detach);
	RING_API_REGISTER("osbutton_visible",ring_osbutton_visible);
	RING_API_REGISTER("osbutton_enabled",ring_osbutton_enabled);
	RING_API_REGISTER("osbutton_size",ring_osbutton_size);
	RING_API_REGISTER("osbutton_origin",ring_osbutton_origin);
	RING_API_REGISTER("osbutton_frame",ring_osbutton_frame);
	RING_API_REGISTER("osbs_start",ring_osbs_start);
	RING_API_REGISTER("osbs_finish",ring_osbs_finish);
	RING_API_REGISTER("osbs_platform",ring_osbs_platform);
	RING_API_REGISTER("osbs_windows",ring_osbs_windows);
	RING_API_REGISTER("osbs_endian",ring_osbs_endian);
	RING_API_REGISTER("log_output",ring_log_output);
	RING_API_REGISTER("log_file",ring_log_file);
	RING_API_REGISTER("log_get_file",ring_log_get_file);
	RING_API_REGISTER("dlib_open",ring_dlib_open);
	RING_API_REGISTER("dlib_close",ring_dlib_close);
	RING_API_REGISTER("dlib_proc_imp",ring_dlib_proc_imp);
	RING_API_REGISTER("dlib_var_imp",ring_dlib_var_imp);
	RING_API_REGISTER("btime_now",ring_btime_now);
	RING_API_REGISTER("btime_date",ring_btime_date);
	RING_API_REGISTER("btime_to_micro",ring_btime_to_micro);
	RING_API_REGISTER("btime_to_date",ring_btime_to_date);
	RING_API_REGISTER("bthread_create_imp",ring_bthread_create_imp);
	RING_API_REGISTER("bthread_current_id",ring_bthread_current_id);
	RING_API_REGISTER("bthread_close",ring_bthread_close);
	RING_API_REGISTER("bthread_cancel",ring_bthread_cancel);
	RING_API_REGISTER("bthread_wait",ring_bthread_wait);
	RING_API_REGISTER("bthread_finish",ring_bthread_finish);
	RING_API_REGISTER("bthread_sleep",ring_bthread_sleep);
	RING_API_REGISTER("bsocket_connect",ring_bsocket_connect);
	RING_API_REGISTER("bsocket_server",ring_bsocket_server);
	RING_API_REGISTER("bsocket_accept",ring_bsocket_accept);
	RING_API_REGISTER("bsocket_close",ring_bsocket_close);
	RING_API_REGISTER("bsocket_local_ip",ring_bsocket_local_ip);
	RING_API_REGISTER("bsocket_remote_ip",ring_bsocket_remote_ip);
	RING_API_REGISTER("bsocket_read_timeout",ring_bsocket_read_timeout);
	RING_API_REGISTER("bsocket_write_timeout",ring_bsocket_write_timeout);
	RING_API_REGISTER("bsocket_read",ring_bsocket_read);
	RING_API_REGISTER("bsocket_write",ring_bsocket_write);
	RING_API_REGISTER("bsocket_url_ip",ring_bsocket_url_ip);
	RING_API_REGISTER("bsocket_str_ip",ring_bsocket_str_ip);
	RING_API_REGISTER("bsocket_host_name",ring_bsocket_host_name);
	RING_API_REGISTER("bsocket_host_name_ip",ring_bsocket_host_name_ip);
	RING_API_REGISTER("bsocket_ip_str",ring_bsocket_ip_str);
	RING_API_REGISTER("bsocket_hton2",ring_bsocket_hton2);
	RING_API_REGISTER("bsocket_hton4",ring_bsocket_hton4);
	RING_API_REGISTER("bsocket_hton8",ring_bsocket_hton8);
	RING_API_REGISTER("bsocket_ntoh2",ring_bsocket_ntoh2);
	RING_API_REGISTER("bsocket_ntoh4",ring_bsocket_ntoh4);
	RING_API_REGISTER("bsocket_ntoh8",ring_bsocket_ntoh8);
	RING_API_REGISTER("bproc_exec",ring_bproc_exec);
	RING_API_REGISTER("bproc_close",ring_bproc_close);
	RING_API_REGISTER("bproc_cancel",ring_bproc_cancel);
	RING_API_REGISTER("bproc_wait",ring_bproc_wait);
	RING_API_REGISTER("bproc_finish",ring_bproc_finish);
	RING_API_REGISTER("bproc_read",ring_bproc_read);
	RING_API_REGISTER("bproc_eread",ring_bproc_eread);
	RING_API_REGISTER("bproc_write",ring_bproc_write);
	RING_API_REGISTER("bproc_read_close",ring_bproc_read_close);
	RING_API_REGISTER("bproc_eread_close",ring_bproc_eread_close);
	RING_API_REGISTER("bproc_write_close",ring_bproc_write_close);
	RING_API_REGISTER("bproc_exit",ring_bproc_exit);
	RING_API_REGISTER("bmutex_create",ring_bmutex_create);
	RING_API_REGISTER("bmutex_close",ring_bmutex_close);
	RING_API_REGISTER("bmutex_lock",ring_bmutex_lock);
	RING_API_REGISTER("bmutex_unlock",ring_bmutex_unlock);
	RING_API_REGISTER("bfile_dir_work",ring_bfile_dir_work);
	RING_API_REGISTER("bfile_dir_set_work",ring_bfile_dir_set_work);
	RING_API_REGISTER("bfile_dir_home",ring_bfile_dir_home);
	RING_API_REGISTER("bfile_dir_data",ring_bfile_dir_data);
	RING_API_REGISTER("bfile_dir_exec",ring_bfile_dir_exec);
	RING_API_REGISTER("bfile_dir_create",ring_bfile_dir_create);
	RING_API_REGISTER("bfile_dir_open",ring_bfile_dir_open);
	RING_API_REGISTER("bfile_dir_close",ring_bfile_dir_close);
	RING_API_REGISTER("bfile_dir_get",ring_bfile_dir_get);
	RING_API_REGISTER("bfile_dir_delete",ring_bfile_dir_delete);
	RING_API_REGISTER("bfile_create",ring_bfile_create);
	RING_API_REGISTER("bfile_open",ring_bfile_open);
	RING_API_REGISTER("bfile_close",ring_bfile_close);
	RING_API_REGISTER("bfile_lstat",ring_bfile_lstat);
	RING_API_REGISTER("bfile_fstat",ring_bfile_fstat);
	RING_API_REGISTER("bfile_read",ring_bfile_read);
	RING_API_REGISTER("bfile_write",ring_bfile_write);
	RING_API_REGISTER("bfile_seek",ring_bfile_seek);
	RING_API_REGISTER("bfile_pos",ring_bfile_pos);
	RING_API_REGISTER("bfile_delete",ring_bfile_delete);
	RING_API_REGISTER("osapp_finish",ring_osapp_finish);
	RING_API_REGISTER("osapp_task_imp",ring_osapp_task_imp);
	RING_API_REGISTER("osapp_menubar",ring_osapp_menubar);
	RING_API_REGISTER("osapp_open_url",ring_osapp_open_url);
	RING_API_REGISTER("url_parse",ring_url_parse);
	RING_API_REGISTER("url_destroy",ring_url_destroy);
	RING_API_REGISTER("url_scheme",ring_url_scheme);
	RING_API_REGISTER("url_user",ring_url_user);
	RING_API_REGISTER("url_pass",ring_url_pass);
	RING_API_REGISTER("url_host",ring_url_host);
	RING_API_REGISTER("url_path",ring_url_path);
	RING_API_REGISTER("url_params",ring_url_params);
	RING_API_REGISTER("url_query",ring_url_query);
	RING_API_REGISTER("url_fragment",ring_url_fragment);
	RING_API_REGISTER("url_resource",ring_url_resource);
	RING_API_REGISTER("url_port",ring_url_port);
	RING_API_REGISTER("json_read_imp",ring_json_read_imp);
	RING_API_REGISTER("json_write_imp",ring_json_write_imp);
	RING_API_REGISTER("json_destroy_imp",ring_json_destroy_imp);
	RING_API_REGISTER("json_destopt_imp",ring_json_destopt_imp);
	RING_API_REGISTER("inet_start",ring_inet_start);
	RING_API_REGISTER("inet_finish",ring_inet_finish);
	RING_API_REGISTER("http_create",ring_http_create);
	RING_API_REGISTER("http_secure",ring_http_secure);
	RING_API_REGISTER("http_destroy",ring_http_destroy);
	RING_API_REGISTER("http_clear_headers",ring_http_clear_headers);
	RING_API_REGISTER("http_add_header",ring_http_add_header);
	RING_API_REGISTER("http_get",ring_http_get);
	RING_API_REGISTER("http_post",ring_http_post);
	RING_API_REGISTER("http_response_status",ring_http_response_status);
	RING_API_REGISTER("http_response_protocol",ring_http_response_protocol);
	RING_API_REGISTER("http_response_message",ring_http_response_message);
	RING_API_REGISTER("http_response_size",ring_http_response_size);
	RING_API_REGISTER("http_response_name",ring_http_response_name);
	RING_API_REGISTER("http_response_value",ring_http_response_value);
	RING_API_REGISTER("http_response_header",ring_http_response_header);
	RING_API_REGISTER("http_response_body",ring_http_response_body);
	RING_API_REGISTER("http_dget",ring_http_dget);
	RING_API_REGISTER("http_exists",ring_http_exists);
	RING_API_REGISTER("b64_encoded_size",ring_b64_encoded_size);
	RING_API_REGISTER("b64_decoded_size",ring_b64_decoded_size);
	RING_API_REGISTER("b64_encode",ring_b64_encode);
	RING_API_REGISTER("b64_decode",ring_b64_decode);
	RING_API_REGISTER("window_create",ring_window_create);
	RING_API_REGISTER("window_destroy",ring_window_destroy);
	RING_API_REGISTER("window_panel",ring_window_panel);
	RING_API_REGISTER("window_onclose",ring_window_OnClose);
	RING_API_REGISTER("window_onmoved",ring_window_OnMoved);
	RING_API_REGISTER("window_onresize",ring_window_OnResize);
	RING_API_REGISTER("window_title",ring_window_title);
	RING_API_REGISTER("window_show",ring_window_show);
	RING_API_REGISTER("window_hide",ring_window_hide);
	RING_API_REGISTER("window_overlay",ring_window_overlay);
	RING_API_REGISTER("window_modal",ring_window_modal);
	RING_API_REGISTER("window_stop_modal",ring_window_stop_modal);
	RING_API_REGISTER("window_hotkey",ring_window_hotkey);
	RING_API_REGISTER("window_clear_hotkeys",ring_window_clear_hotkeys);
	RING_API_REGISTER("window_cycle_tabstop",ring_window_cycle_tabstop);
	RING_API_REGISTER("window_next_tabstop",ring_window_next_tabstop);
	RING_API_REGISTER("window_previous_tabstop",ring_window_previous_tabstop);
	RING_API_REGISTER("window_focus",ring_window_focus);
	RING_API_REGISTER("window_get_focus",ring_window_get_focus);
	RING_API_REGISTER("window_focus_info",ring_window_focus_info);
	RING_API_REGISTER("window_update",ring_window_update);
	RING_API_REGISTER("window_origin",ring_window_origin);
	RING_API_REGISTER("window_size",ring_window_size);
	RING_API_REGISTER("window_get_origin",ring_window_get_origin);
	RING_API_REGISTER("window_get_size",ring_window_get_size);
	RING_API_REGISTER("window_get_client_size",ring_window_get_client_size);
	RING_API_REGISTER("window_control_frame",ring_window_control_frame);
	RING_API_REGISTER("window_client_to_screen",ring_window_client_to_screen);
	RING_API_REGISTER("window_defbutton",ring_window_defbutton);
	RING_API_REGISTER("window_cursor",ring_window_cursor);
	RING_API_REGISTER("window_imp",ring_window_imp);
	RING_API_REGISTER("view_create",ring_view_create);
	RING_API_REGISTER("view_scroll",ring_view_scroll);
	RING_API_REGISTER("view_custom",ring_view_custom);
	RING_API_REGISTER("view_data_imp",ring_view_data_imp);
	RING_API_REGISTER("view_get_data_imp",ring_view_get_data_imp);
	RING_API_REGISTER("view_size",ring_view_size);
	RING_API_REGISTER("view_ondraw",ring_view_OnDraw);
	RING_API_REGISTER("view_onoverlay",ring_view_OnOverlay);
	RING_API_REGISTER("view_onsize",ring_view_OnSize);
	RING_API_REGISTER("view_onenter",ring_view_OnEnter);
	RING_API_REGISTER("view_onexit",ring_view_OnExit);
	RING_API_REGISTER("view_onmove",ring_view_OnMove);
	RING_API_REGISTER("view_ondown",ring_view_OnDown);
	RING_API_REGISTER("view_onup",ring_view_OnUp);
	RING_API_REGISTER("view_onclick",ring_view_OnClick);
	RING_API_REGISTER("view_ondrag",ring_view_OnDrag);
	RING_API_REGISTER("view_onwheel",ring_view_OnWheel);
	RING_API_REGISTER("view_onkeydown",ring_view_OnKeyDown);
	RING_API_REGISTER("view_onkeyup",ring_view_OnKeyUp);
	RING_API_REGISTER("view_onfocus",ring_view_OnFocus);
	RING_API_REGISTER("view_onresignfocus",ring_view_OnResignFocus);
	RING_API_REGISTER("view_onacceptfocus",ring_view_OnAcceptFocus);
	RING_API_REGISTER("view_onscroll",ring_view_OnScroll);
	RING_API_REGISTER("view_keybuf",ring_view_keybuf);
	RING_API_REGISTER("view_get_size",ring_view_get_size);
	RING_API_REGISTER("view_content_size",ring_view_content_size);
	RING_API_REGISTER("view_scroll_x",ring_view_scroll_x);
	RING_API_REGISTER("view_scroll_y",ring_view_scroll_y);
	RING_API_REGISTER("view_scroll_size",ring_view_scroll_size);
	RING_API_REGISTER("view_scroll_visible",ring_view_scroll_visible);
	RING_API_REGISTER("view_viewport",ring_view_viewport);
	RING_API_REGISTER("view_point_scale",ring_view_point_scale);
	RING_API_REGISTER("view_update",ring_view_update);
	RING_API_REGISTER("view_native",ring_view_native);
	RING_API_REGISTER("updown_create",ring_updown_create);
	RING_API_REGISTER("updown_onclick",ring_updown_OnClick);
	RING_API_REGISTER("updown_tooltip",ring_updown_tooltip);
	RING_API_REGISTER("textview_create",ring_textview_create);
	RING_API_REGISTER("textview_onfilter",ring_textview_OnFilter);
	RING_API_REGISTER("textview_onfocus",ring_textview_OnFocus);
	RING_API_REGISTER("textview_size",ring_textview_size);
	RING_API_REGISTER("textview_clear",ring_textview_clear);
	RING_API_REGISTER("textview_writef",ring_textview_writef);
	RING_API_REGISTER("textview_rtf",ring_textview_rtf);
	RING_API_REGISTER("textview_units",ring_textview_units);
	RING_API_REGISTER("textview_family",ring_textview_family);
	RING_API_REGISTER("textview_fsize",ring_textview_fsize);
	RING_API_REGISTER("textview_fstyle",ring_textview_fstyle);
	RING_API_REGISTER("textview_color",ring_textview_color);
	RING_API_REGISTER("textview_bgcolor",ring_textview_bgcolor);
	RING_API_REGISTER("textview_pgcolor",ring_textview_pgcolor);
	RING_API_REGISTER("textview_halign",ring_textview_halign);
	RING_API_REGISTER("textview_lspacing",ring_textview_lspacing);
	RING_API_REGISTER("textview_bfspace",ring_textview_bfspace);
	RING_API_REGISTER("textview_afspace",ring_textview_afspace);
	RING_API_REGISTER("textview_scroll_visible",ring_textview_scroll_visible);
	RING_API_REGISTER("textview_editable",ring_textview_editable);
	RING_API_REGISTER("textview_select",ring_textview_select);
	RING_API_REGISTER("textview_scroll_caret",ring_textview_scroll_caret);
	RING_API_REGISTER("textview_get_text",ring_textview_get_text);
	RING_API_REGISTER("textview_copy",ring_textview_copy);
	RING_API_REGISTER("textview_cut",ring_textview_cut);
	RING_API_REGISTER("textview_paste",ring_textview_paste);
	RING_API_REGISTER("tableview_create",ring_tableview_create);
	RING_API_REGISTER("tableview_ondata",ring_tableview_OnData);
	RING_API_REGISTER("tableview_onselect",ring_tableview_OnSelect);
	RING_API_REGISTER("tableview_onrowclick",ring_tableview_OnRowClick);
	RING_API_REGISTER("tableview_onheaderclick",ring_tableview_OnHeaderClick);
	RING_API_REGISTER("tableview_font",ring_tableview_font);
	RING_API_REGISTER("tableview_size",ring_tableview_size);
	RING_API_REGISTER("tableview_new_column_text",ring_tableview_new_column_text);
	RING_API_REGISTER("tableview_column_width",ring_tableview_column_width);
	RING_API_REGISTER("tableview_column_limits",ring_tableview_column_limits);
	RING_API_REGISTER("tableview_column_resizable",ring_tableview_column_resizable);
	RING_API_REGISTER("tableview_column_freeze",ring_tableview_column_freeze);
	RING_API_REGISTER("tableview_header_title",ring_tableview_header_title);
	RING_API_REGISTER("tableview_header_align",ring_tableview_header_align);
	RING_API_REGISTER("tableview_header_indicator",ring_tableview_header_indicator);
	RING_API_REGISTER("tableview_header_visible",ring_tableview_header_visible);
	RING_API_REGISTER("tableview_header_clickable",ring_tableview_header_clickable);
	RING_API_REGISTER("tableview_header_resizable",ring_tableview_header_resizable);
	RING_API_REGISTER("tableview_header_height",ring_tableview_header_height);
	RING_API_REGISTER("tableview_row_height",ring_tableview_row_height);
	RING_API_REGISTER("tableview_hkey_scroll",ring_tableview_hkey_scroll);
	RING_API_REGISTER("tableview_multisel",ring_tableview_multisel);
	RING_API_REGISTER("tableview_grid",ring_tableview_grid);
	RING_API_REGISTER("tableview_update",ring_tableview_update);
	RING_API_REGISTER("tableview_select",ring_tableview_select);
	RING_API_REGISTER("tableview_deselect",ring_tableview_deselect);
	RING_API_REGISTER("tableview_deselect_all",ring_tableview_deselect_all);
	RING_API_REGISTER("tableview_focus_row",ring_tableview_focus_row);
	RING_API_REGISTER("tableview_get_focus_row",ring_tableview_get_focus_row);
	RING_API_REGISTER("tableview_scroll_visible",ring_tableview_scroll_visible);
	RING_API_REGISTER("splitview_horizontal",ring_splitview_horizontal);
	RING_API_REGISTER("splitview_vertical",ring_splitview_vertical);
	RING_API_REGISTER("splitview_size",ring_splitview_size);
	RING_API_REGISTER("splitview_view",ring_splitview_view);
	RING_API_REGISTER("splitview_text",ring_splitview_text);
	RING_API_REGISTER("splitview_split",ring_splitview_split);
	RING_API_REGISTER("splitview_panel",ring_splitview_panel);
	RING_API_REGISTER("splitview_pos",ring_splitview_pos);
	RING_API_REGISTER("slider_create",ring_slider_create);
	RING_API_REGISTER("slider_vertical",ring_slider_vertical);
	RING_API_REGISTER("slider_onmoved",ring_slider_OnMoved);
	RING_API_REGISTER("slider_tooltip",ring_slider_tooltip);
	RING_API_REGISTER("slider_steps",ring_slider_steps);
	RING_API_REGISTER("slider_value",ring_slider_value);
	RING_API_REGISTER("slider_get_value",ring_slider_get_value);
	RING_API_REGISTER("res_gui_respack",ring_res_gui_respack);
	RING_API_REGISTER("progress_create",ring_progress_create);
	RING_API_REGISTER("progress_undefined",ring_progress_undefined);
	RING_API_REGISTER("progress_value",ring_progress_value);
	RING_API_REGISTER("popup_create",ring_popup_create);
	RING_API_REGISTER("popup_onselect",ring_popup_OnSelect);
	RING_API_REGISTER("popup_tooltip",ring_popup_tooltip);
	RING_API_REGISTER("popup_add_elem",ring_popup_add_elem);
	RING_API_REGISTER("popup_set_elem",ring_popup_set_elem);
	RING_API_REGISTER("popup_clear",ring_popup_clear);
	RING_API_REGISTER("popup_count",ring_popup_count);
	RING_API_REGISTER("popup_list_height",ring_popup_list_height);
	RING_API_REGISTER("popup_selected",ring_popup_selected);
	RING_API_REGISTER("popup_get_selected",ring_popup_get_selected);
	RING_API_REGISTER("popup_get_text",ring_popup_get_text);
	RING_API_REGISTER("panel_create",ring_panel_create);
	RING_API_REGISTER("panel_scroll",ring_panel_scroll);
	RING_API_REGISTER("panel_custom",ring_panel_custom);
	RING_API_REGISTER("panel_data_imp",ring_panel_data_imp);
	RING_API_REGISTER("panel_get_data_imp",ring_panel_get_data_imp);
	RING_API_REGISTER("panel_size",ring_panel_size);
	RING_API_REGISTER("panel_layout",ring_panel_layout);
	RING_API_REGISTER("panel_get_layout",ring_panel_get_layout);
	RING_API_REGISTER("panel_visible_layout",ring_panel_visible_layout);
	RING_API_REGISTER("panel_update",ring_panel_update);
	RING_API_REGISTER("panel_scroll_width",ring_panel_scroll_width);
	RING_API_REGISTER("panel_scroll_height",ring_panel_scroll_height);
	RING_API_REGISTER("menuitem_create",ring_menuitem_create);
	RING_API_REGISTER("menuitem_separator",ring_menuitem_separator);
	RING_API_REGISTER("menuitem_onclick",ring_menuitem_OnClick);
	RING_API_REGISTER("menuitem_enabled",ring_menuitem_enabled);
	RING_API_REGISTER("menuitem_visible",ring_menuitem_visible);
	RING_API_REGISTER("menuitem_text",ring_menuitem_text);
	RING_API_REGISTER("menuitem_image",ring_menuitem_image);
	RING_API_REGISTER("menuitem_key",ring_menuitem_key);
	RING_API_REGISTER("menuitem_submenu",ring_menuitem_submenu);
	RING_API_REGISTER("menuitem_state",ring_menuitem_state);
	RING_API_REGISTER("menu_create",ring_menu_create);
	RING_API_REGISTER("menu_destroy",ring_menu_destroy);
	RING_API_REGISTER("menu_item",ring_menu_item);
	RING_API_REGISTER("menu_launch",ring_menu_launch);
	RING_API_REGISTER("menu_hide",ring_menu_hide);
	RING_API_REGISTER("menu_off_items",ring_menu_off_items);
	RING_API_REGISTER("menu_get_item",ring_menu_get_item);
	RING_API_REGISTER("menu_size",ring_menu_size);
	RING_API_REGISTER("menu_imp",ring_menu_imp);
	RING_API_REGISTER("listbox_create",ring_listbox_create);
	RING_API_REGISTER("listbox_ondown",ring_listbox_OnDown);
	RING_API_REGISTER("listbox_onselect",ring_listbox_OnSelect);
	RING_API_REGISTER("listbox_size",ring_listbox_size);
	RING_API_REGISTER("listbox_checkbox",ring_listbox_checkbox);
	RING_API_REGISTER("listbox_multisel",ring_listbox_multisel);
	RING_API_REGISTER("listbox_add_elem",ring_listbox_add_elem);
	RING_API_REGISTER("listbox_set_elem",ring_listbox_set_elem);
	RING_API_REGISTER("listbox_clear",ring_listbox_clear);
	RING_API_REGISTER("listbox_color",ring_listbox_color);
	RING_API_REGISTER("listbox_select",ring_listbox_select);
	RING_API_REGISTER("listbox_check",ring_listbox_check);
	RING_API_REGISTER("listbox_count",ring_listbox_count);
	RING_API_REGISTER("listbox_text",ring_listbox_text);
	RING_API_REGISTER("listbox_selected",ring_listbox_selected);
	RING_API_REGISTER("listbox_checked",ring_listbox_checked);
	RING_API_REGISTER("layout_create",ring_layout_create);
	RING_API_REGISTER("layout_cell",ring_layout_cell);
	RING_API_REGISTER("layout_control",ring_layout_control);
	RING_API_REGISTER("layout_label",ring_layout_label);
	RING_API_REGISTER("layout_button",ring_layout_button);
	RING_API_REGISTER("layout_popup",ring_layout_popup);
	RING_API_REGISTER("layout_edit",ring_layout_edit);
	RING_API_REGISTER("layout_combo",ring_layout_combo);
	RING_API_REGISTER("layout_listbox",ring_layout_listbox);
	RING_API_REGISTER("layout_updown",ring_layout_updown);
	RING_API_REGISTER("layout_slider",ring_layout_slider);
	RING_API_REGISTER("layout_progress",ring_layout_progress);
	RING_API_REGISTER("layout_view",ring_layout_view);
	RING_API_REGISTER("layout_textview",ring_layout_textview);
	RING_API_REGISTER("layout_imageview",ring_layout_imageview);
	RING_API_REGISTER("layout_tableview",ring_layout_tableview);
	RING_API_REGISTER("layout_splitview",ring_layout_splitview);
	RING_API_REGISTER("layout_panel",ring_layout_panel);
	RING_API_REGISTER("layout_panel_replace",ring_layout_panel_replace);
	RING_API_REGISTER("layout_layout",ring_layout_layout);
	RING_API_REGISTER("layout_get_label",ring_layout_get_label);
	RING_API_REGISTER("layout_get_button",ring_layout_get_button);
	RING_API_REGISTER("layout_get_popup",ring_layout_get_popup);
	RING_API_REGISTER("layout_get_edit",ring_layout_get_edit);
	RING_API_REGISTER("layout_get_combo",ring_layout_get_combo);
	RING_API_REGISTER("layout_get_listbox",ring_layout_get_listbox);
	RING_API_REGISTER("layout_get_updown",ring_layout_get_updown);
	RING_API_REGISTER("layout_get_slider",ring_layout_get_slider);
	RING_API_REGISTER("layout_get_progress",ring_layout_get_progress);
	RING_API_REGISTER("layout_get_view",ring_layout_get_view);
	RING_API_REGISTER("layout_get_textview",ring_layout_get_textview);
	RING_API_REGISTER("layout_get_imageview",ring_layout_get_imageview);
	RING_API_REGISTER("layout_get_tableview",ring_layout_get_tableview);
	RING_API_REGISTER("layout_get_splitview",ring_layout_get_splitview);
	RING_API_REGISTER("layout_get_panel",ring_layout_get_panel);
	RING_API_REGISTER("layout_get_layout",ring_layout_get_layout);
	RING_API_REGISTER("layout_ncols",ring_layout_ncols);
	RING_API_REGISTER("layout_nrows",ring_layout_nrows);
	RING_API_REGISTER("layout_insert_col",ring_layout_insert_col);
	RING_API_REGISTER("layout_insert_row",ring_layout_insert_row);
	RING_API_REGISTER("layout_remove_col",ring_layout_remove_col);
	RING_API_REGISTER("layout_remove_row",ring_layout_remove_row);
	RING_API_REGISTER("layout_taborder",ring_layout_taborder);
	RING_API_REGISTER("layout_tabstop",ring_layout_tabstop);
	RING_API_REGISTER("layout_hsize",ring_layout_hsize);
	RING_API_REGISTER("layout_vsize",ring_layout_vsize);
	RING_API_REGISTER("layout_hmargin",ring_layout_hmargin);
	RING_API_REGISTER("layout_vmargin",ring_layout_vmargin);
	RING_API_REGISTER("layout_hexpand",ring_layout_hexpand);
	RING_API_REGISTER("layout_hexpand2",ring_layout_hexpand2);
	RING_API_REGISTER("layout_hexpand3",ring_layout_hexpand3);
	RING_API_REGISTER("layout_vexpand",ring_layout_vexpand);
	RING_API_REGISTER("layout_vexpand2",ring_layout_vexpand2);
	RING_API_REGISTER("layout_vexpand3",ring_layout_vexpand3);
	RING_API_REGISTER("layout_halign",ring_layout_halign);
	RING_API_REGISTER("layout_valign",ring_layout_valign);
	RING_API_REGISTER("layout_show_col",ring_layout_show_col);
	RING_API_REGISTER("layout_show_row",ring_layout_show_row);
	RING_API_REGISTER("layout_margin",ring_layout_margin);
	RING_API_REGISTER("layout_margin2",ring_layout_margin2);
	RING_API_REGISTER("layout_margin4",ring_layout_margin4);
	RING_API_REGISTER("layout_bgcolor",ring_layout_bgcolor);
	RING_API_REGISTER("layout_skcolor",ring_layout_skcolor);
	RING_API_REGISTER("layout_update",ring_layout_update);
	RING_API_REGISTER("layout_dbind_imp",ring_layout_dbind_imp);
	RING_API_REGISTER("layout_dbind_obj_imp",ring_layout_dbind_obj_imp);
	RING_API_REGISTER("layout_dbind_update_imp",ring_layout_dbind_update_imp);
	RING_API_REGISTER("label_create",ring_label_create);
	RING_API_REGISTER("label_multiline",ring_label_multiline);
	RING_API_REGISTER("label_onclick",ring_label_OnClick);
	RING_API_REGISTER("label_text",ring_label_text);
	RING_API_REGISTER("label_size_text",ring_label_size_text);
	RING_API_REGISTER("label_font",ring_label_font);
	RING_API_REGISTER("label_style_over",ring_label_style_over);
	RING_API_REGISTER("label_align",ring_label_align);
	RING_API_REGISTER("label_color",ring_label_color);
	RING_API_REGISTER("label_color_over",ring_label_color_over);
	RING_API_REGISTER("label_bgcolor",ring_label_bgcolor);
	RING_API_REGISTER("label_bgcolor_over",ring_label_bgcolor_over);
	RING_API_REGISTER("imageview_create",ring_imageview_create);
	RING_API_REGISTER("imageview_size",ring_imageview_size);
	RING_API_REGISTER("imageview_scale",ring_imageview_scale);
	RING_API_REGISTER("imageview_image",ring_imageview_image);
	RING_API_REGISTER("imageview_onclick",ring_imageview_OnClick);
	RING_API_REGISTER("imageview_onoverdraw",ring_imageview_OnOverDraw);
	RING_API_REGISTER("guicontrol_label",ring_guicontrol_label);
	RING_API_REGISTER("guicontrol_button",ring_guicontrol_button);
	RING_API_REGISTER("guicontrol_popup",ring_guicontrol_popup);
	RING_API_REGISTER("guicontrol_edit",ring_guicontrol_edit);
	RING_API_REGISTER("guicontrol_combo",ring_guicontrol_combo);
	RING_API_REGISTER("guicontrol_listbox",ring_guicontrol_listbox);
	RING_API_REGISTER("guicontrol_updown",ring_guicontrol_updown);
	RING_API_REGISTER("guicontrol_slider",ring_guicontrol_slider);
	RING_API_REGISTER("guicontrol_progress",ring_guicontrol_progress);
	RING_API_REGISTER("guicontrol_view",ring_guicontrol_view);
	RING_API_REGISTER("guicontrol_textview",ring_guicontrol_textview);
	RING_API_REGISTER("guicontrol_imageview",ring_guicontrol_imageview);
	RING_API_REGISTER("guicontrol_tableview",ring_guicontrol_tableview);
	RING_API_REGISTER("guicontrol_splitview",ring_guicontrol_splitview);
	RING_API_REGISTER("guicontrol_panel",ring_guicontrol_panel);
	RING_API_REGISTER("guicontrol_tag",ring_guicontrol_tag);
	RING_API_REGISTER("guicontrol_get_tag",ring_guicontrol_get_tag);
	RING_API_REGISTER("gui_start",ring_gui_start);
	RING_API_REGISTER("gui_finish",ring_gui_finish);
	RING_API_REGISTER("gui_respack",ring_gui_respack);
	RING_API_REGISTER("gui_language",ring_gui_language);
	RING_API_REGISTER("gui_text",ring_gui_text);
	RING_API_REGISTER("gui_image",ring_gui_image);
	RING_API_REGISTER("gui_file",ring_gui_file);
	RING_API_REGISTER("gui_dark_mode",ring_gui_dark_mode);
	RING_API_REGISTER("gui_alt_color",ring_gui_alt_color);
	RING_API_REGISTER("gui_label_color",ring_gui_label_color);
	RING_API_REGISTER("gui_view_color",ring_gui_view_color);
	RING_API_REGISTER("gui_line_color",ring_gui_line_color);
	RING_API_REGISTER("gui_link_color",ring_gui_link_color);
	RING_API_REGISTER("gui_border_color",ring_gui_border_color);
	RING_API_REGISTER("gui_resolution",ring_gui_resolution);
	RING_API_REGISTER("gui_mouse_pos",ring_gui_mouse_pos);
	RING_API_REGISTER("gui_update",ring_gui_update);
	RING_API_REGISTER("gui_onthemechanged",ring_gui_OnThemeChanged);
	RING_API_REGISTER("gui_update_transitions",ring_gui_update_transitions);
	RING_API_REGISTER("gui_onnotification",ring_gui_OnNotification);
	RING_API_REGISTER("gui_onidle",ring_gui_OnIdle);
	RING_API_REGISTER("gui_info_window",ring_gui_info_window);
	RING_API_REGISTER("evbind_object_imp",ring_evbind_object_imp);
	RING_API_REGISTER("evbind_modify_imp",ring_evbind_modify_imp);
	RING_API_REGISTER("globals_device",ring_globals_device);
	RING_API_REGISTER("globals_resolution",ring_globals_resolution);
	RING_API_REGISTER("globals_mouse_position",ring_globals_mouse_position);
	RING_API_REGISTER("edit_create",ring_edit_create);
	RING_API_REGISTER("edit_multiline",ring_edit_multiline);
	RING_API_REGISTER("edit_onfilter",ring_edit_OnFilter);
	RING_API_REGISTER("edit_onchange",ring_edit_OnChange);
	RING_API_REGISTER("edit_onfocus",ring_edit_OnFocus);
	RING_API_REGISTER("edit_text",ring_edit_text);
	RING_API_REGISTER("edit_font",ring_edit_font);
	RING_API_REGISTER("edit_align",ring_edit_align);
	RING_API_REGISTER("edit_passmode",ring_edit_passmode);
	RING_API_REGISTER("edit_editable",ring_edit_editable);
	RING_API_REGISTER("edit_autoselect",ring_edit_autoselect);
	RING_API_REGISTER("edit_select",ring_edit_select);
	RING_API_REGISTER("edit_tooltip",ring_edit_tooltip);
	RING_API_REGISTER("edit_color",ring_edit_color);
	RING_API_REGISTER("edit_color_focus",ring_edit_color_focus);
	RING_API_REGISTER("edit_bgcolor",ring_edit_bgcolor);
	RING_API_REGISTER("edit_bgcolor_focus",ring_edit_bgcolor_focus);
	RING_API_REGISTER("edit_phtext",ring_edit_phtext);
	RING_API_REGISTER("edit_phcolor",ring_edit_phcolor);
	RING_API_REGISTER("edit_phstyle",ring_edit_phstyle);
	RING_API_REGISTER("edit_vpadding",ring_edit_vpadding);
	RING_API_REGISTER("edit_get_text",ring_edit_get_text);
	RING_API_REGISTER("edit_get_height",ring_edit_get_height);
	RING_API_REGISTER("edit_copy",ring_edit_copy);
	RING_API_REGISTER("edit_cut",ring_edit_cut);
	RING_API_REGISTER("edit_paste",ring_edit_paste);
	RING_API_REGISTER("comwin_open_file",ring_comwin_open_file);
	RING_API_REGISTER("comwin_save_file",ring_comwin_save_file);
	RING_API_REGISTER("comwin_color",ring_comwin_color);
	RING_API_REGISTER("combo_create",ring_combo_create);
	RING_API_REGISTER("combo_onfilter",ring_combo_OnFilter);
	RING_API_REGISTER("combo_onchange",ring_combo_OnChange);
	RING_API_REGISTER("combo_text",ring_combo_text);
	RING_API_REGISTER("combo_align",ring_combo_align);
	RING_API_REGISTER("combo_tooltip",ring_combo_tooltip);
	RING_API_REGISTER("combo_color",ring_combo_color);
	RING_API_REGISTER("combo_color_focus",ring_combo_color_focus);
	RING_API_REGISTER("combo_bgcolor",ring_combo_bgcolor);
	RING_API_REGISTER("combo_bgcolor_focus",ring_combo_bgcolor_focus);
	RING_API_REGISTER("combo_phtext",ring_combo_phtext);
	RING_API_REGISTER("combo_phcolor",ring_combo_phcolor);
	RING_API_REGISTER("combo_phstyle",ring_combo_phstyle);
	RING_API_REGISTER("combo_get_text",ring_combo_get_text);
	RING_API_REGISTER("combo_count",ring_combo_count);
	RING_API_REGISTER("combo_add_elem",ring_combo_add_elem);
	RING_API_REGISTER("combo_set_elem",ring_combo_set_elem);
	RING_API_REGISTER("combo_ins_elem",ring_combo_ins_elem);
	RING_API_REGISTER("combo_del_elem",ring_combo_del_elem);
	RING_API_REGISTER("combo_duplicates",ring_combo_duplicates);
	RING_API_REGISTER("cell_empty",ring_cell_empty);
	RING_API_REGISTER("cell_control",ring_cell_control);
	RING_API_REGISTER("cell_label",ring_cell_label);
	RING_API_REGISTER("cell_button",ring_cell_button);
	RING_API_REGISTER("cell_popup",ring_cell_popup);
	RING_API_REGISTER("cell_edit",ring_cell_edit);
	RING_API_REGISTER("cell_combo",ring_cell_combo);
	RING_API_REGISTER("cell_listbox",ring_cell_listbox);
	RING_API_REGISTER("cell_updown",ring_cell_updown);
	RING_API_REGISTER("cell_slider",ring_cell_slider);
	RING_API_REGISTER("cell_progress",ring_cell_progress);
	RING_API_REGISTER("cell_view",ring_cell_view);
	RING_API_REGISTER("cell_textview",ring_cell_textview);
	RING_API_REGISTER("cell_imageview",ring_cell_imageview);
	RING_API_REGISTER("cell_tableview",ring_cell_tableview);
	RING_API_REGISTER("cell_splitview",ring_cell_splitview);
	RING_API_REGISTER("cell_panel",ring_cell_panel);
	RING_API_REGISTER("cell_layout",ring_cell_layout);
	RING_API_REGISTER("cell_enabled",ring_cell_enabled);
	RING_API_REGISTER("cell_visible",ring_cell_visible);
	RING_API_REGISTER("cell_padding",ring_cell_padding);
	RING_API_REGISTER("cell_padding2",ring_cell_padding2);
	RING_API_REGISTER("cell_padding4",ring_cell_padding4);
	RING_API_REGISTER("cell_dbind_imp",ring_cell_dbind_imp);
	RING_API_REGISTER("button_push",ring_button_push);
	RING_API_REGISTER("button_check",ring_button_check);
	RING_API_REGISTER("button_check3",ring_button_check3);
	RING_API_REGISTER("button_radio",ring_button_radio);
	RING_API_REGISTER("button_flat",ring_button_flat);
	RING_API_REGISTER("button_flatgle",ring_button_flatgle);
	RING_API_REGISTER("button_onclick",ring_button_OnClick);
	RING_API_REGISTER("button_text",ring_button_text);
	RING_API_REGISTER("button_text_alt",ring_button_text_alt);
	RING_API_REGISTER("button_tooltip",ring_button_tooltip);
	RING_API_REGISTER("button_font",ring_button_font);
	RING_API_REGISTER("button_image",ring_button_image);
	RING_API_REGISTER("button_image_alt",ring_button_image_alt);
	RING_API_REGISTER("button_state",ring_button_state);
	RING_API_REGISTER("button_tag",ring_button_tag);
	RING_API_REGISTER("button_vpadding",ring_button_vpadding);
	RING_API_REGISTER("button_get_state",ring_button_get_state);
	RING_API_REGISTER("button_get_tag",ring_button_get_tag);
	RING_API_REGISTER("button_get_height",ring_button_get_height);
	RING_API_REGISTER("v2df",ring_v2df);
	RING_API_REGISTER("v2dd",ring_v2dd);
	RING_API_REGISTER("v2d_tof",ring_v2d_tof);
	RING_API_REGISTER("v2d_tod",ring_v2d_tod);
	RING_API_REGISTER("v2d_tofn",ring_v2d_tofn);
	RING_API_REGISTER("v2d_todn",ring_v2d_todn);
	RING_API_REGISTER("v2d_addf",ring_v2d_addf);
	RING_API_REGISTER("v2d_addd",ring_v2d_addd);
	RING_API_REGISTER("v2d_subf",ring_v2d_subf);
	RING_API_REGISTER("v2d_subd",ring_v2d_subd);
	RING_API_REGISTER("v2d_mulf",ring_v2d_mulf);
	RING_API_REGISTER("v2d_muld",ring_v2d_muld);
	RING_API_REGISTER("v2d_fromf",ring_v2d_fromf);
	RING_API_REGISTER("v2d_fromd",ring_v2d_fromd);
	RING_API_REGISTER("v2d_midf",ring_v2d_midf);
	RING_API_REGISTER("v2d_midd",ring_v2d_midd);
	RING_API_REGISTER("v2d_unitf",ring_v2d_unitf);
	RING_API_REGISTER("v2d_unitd",ring_v2d_unitd);
	RING_API_REGISTER("v2d_unit_xyf",ring_v2d_unit_xyf);
	RING_API_REGISTER("v2d_unit_xyd",ring_v2d_unit_xyd);
	RING_API_REGISTER("v2d_perp_posf",ring_v2d_perp_posf);
	RING_API_REGISTER("v2d_perp_posd",ring_v2d_perp_posd);
	RING_API_REGISTER("v2d_perp_negf",ring_v2d_perp_negf);
	RING_API_REGISTER("v2d_perp_negd",ring_v2d_perp_negd);
	RING_API_REGISTER("v2d_from_anglef",ring_v2d_from_anglef);
	RING_API_REGISTER("v2d_from_angled",ring_v2d_from_angled);
	RING_API_REGISTER("v2d_normf",ring_v2d_normf);
	RING_API_REGISTER("v2d_normd",ring_v2d_normd);
	RING_API_REGISTER("v2d_lengthf",ring_v2d_lengthf);
	RING_API_REGISTER("v2d_lengthd",ring_v2d_lengthd);
	RING_API_REGISTER("v2d_sqlengthf",ring_v2d_sqlengthf);
	RING_API_REGISTER("v2d_sqlengthd",ring_v2d_sqlengthd);
	RING_API_REGISTER("v2d_dotf",ring_v2d_dotf);
	RING_API_REGISTER("v2d_dotd",ring_v2d_dotd);
	RING_API_REGISTER("v2d_distf",ring_v2d_distf);
	RING_API_REGISTER("v2d_distd",ring_v2d_distd);
	RING_API_REGISTER("v2d_sqdistf",ring_v2d_sqdistf);
	RING_API_REGISTER("v2d_sqdistd",ring_v2d_sqdistd);
	RING_API_REGISTER("v2d_anglef",ring_v2d_anglef);
	RING_API_REGISTER("v2d_angled",ring_v2d_angled);
	RING_API_REGISTER("v2d_rotatef",ring_v2d_rotatef);
	RING_API_REGISTER("v2d_rotated",ring_v2d_rotated);
	RING_API_REGISTER("tri2df",ring_tri2df);
	RING_API_REGISTER("tri2dd",ring_tri2dd);
	RING_API_REGISTER("tri2d_vf",ring_tri2d_vf);
	RING_API_REGISTER("tri2d_vd",ring_tri2d_vd);
	RING_API_REGISTER("tri2d_transformf",ring_tri2d_transformf);
	RING_API_REGISTER("tri2d_transformd",ring_tri2d_transformd);
	RING_API_REGISTER("tri2d_areaf",ring_tri2d_areaf);
	RING_API_REGISTER("tri2d_aread",ring_tri2d_aread);
	RING_API_REGISTER("tri2d_ccwf",ring_tri2d_ccwf);
	RING_API_REGISTER("tri2d_ccwd",ring_tri2d_ccwd);
	RING_API_REGISTER("tri2d_centroidf",ring_tri2d_centroidf);
	RING_API_REGISTER("tri2d_centroidd",ring_tri2d_centroidd);
	RING_API_REGISTER("t2d_tof",ring_t2d_tof);
	RING_API_REGISTER("t2d_tod",ring_t2d_tod);
	RING_API_REGISTER("t2d_movef",ring_t2d_movef);
	RING_API_REGISTER("t2d_moved",ring_t2d_moved);
	RING_API_REGISTER("t2d_rotatef",ring_t2d_rotatef);
	RING_API_REGISTER("t2d_rotated",ring_t2d_rotated);
	RING_API_REGISTER("t2d_scalef",ring_t2d_scalef);
	RING_API_REGISTER("t2d_scaled",ring_t2d_scaled);
	RING_API_REGISTER("t2d_invfastf",ring_t2d_invfastf);
	RING_API_REGISTER("t2d_invfastd",ring_t2d_invfastd);
	RING_API_REGISTER("t2d_inversef",ring_t2d_inversef);
	RING_API_REGISTER("t2d_inversed",ring_t2d_inversed);
	RING_API_REGISTER("t2d_multf",ring_t2d_multf);
	RING_API_REGISTER("t2d_multd",ring_t2d_multd);
	RING_API_REGISTER("t2d_vmultf",ring_t2d_vmultf);
	RING_API_REGISTER("t2d_vmultd",ring_t2d_vmultd);
	RING_API_REGISTER("t2d_vmultnf",ring_t2d_vmultnf);
	RING_API_REGISTER("t2d_vmultnd",ring_t2d_vmultnd);
	RING_API_REGISTER("t2d_decomposef",ring_t2d_decomposef);
	RING_API_REGISTER("t2d_decomposed",ring_t2d_decomposed);
	RING_API_REGISTER("seg2df",ring_seg2df);
	RING_API_REGISTER("seg2dd",ring_seg2dd);
	RING_API_REGISTER("seg2d_vf",ring_seg2d_vf);
	RING_API_REGISTER("seg2d_vd",ring_seg2d_vd);
	RING_API_REGISTER("seg2d_lengthf",ring_seg2d_lengthf);
	RING_API_REGISTER("seg2d_lengthd",ring_seg2d_lengthd);
	RING_API_REGISTER("seg2d_sqlengthf",ring_seg2d_sqlengthf);
	RING_API_REGISTER("seg2d_sqlengthd",ring_seg2d_sqlengthd);
	RING_API_REGISTER("seg2d_evalf",ring_seg2d_evalf);
	RING_API_REGISTER("seg2d_evald",ring_seg2d_evald);
	RING_API_REGISTER("seg2d_close_paramf",ring_seg2d_close_paramf);
	RING_API_REGISTER("seg2d_close_paramd",ring_seg2d_close_paramd);
	RING_API_REGISTER("seg2d_point_sqdistf",ring_seg2d_point_sqdistf);
	RING_API_REGISTER("seg2d_point_sqdistd",ring_seg2d_point_sqdistd);
	RING_API_REGISTER("seg2d_sqdistf",ring_seg2d_sqdistf);
	RING_API_REGISTER("seg2d_sqdistd",ring_seg2d_sqdistd);
	RING_API_REGISTER("r2df",ring_r2df);
	RING_API_REGISTER("r2dd",ring_r2dd);
	RING_API_REGISTER("r2d_centerf",ring_r2d_centerf);
	RING_API_REGISTER("r2d_centerd",ring_r2d_centerd);
	RING_API_REGISTER("r2d_collidef",ring_r2d_collidef);
	RING_API_REGISTER("r2d_collided",ring_r2d_collided);
	RING_API_REGISTER("r2d_containsf",ring_r2d_containsf);
	RING_API_REGISTER("r2d_containsd",ring_r2d_containsd);
	RING_API_REGISTER("r2d_clipf",ring_r2d_clipf);
	RING_API_REGISTER("r2d_clipd",ring_r2d_clipd);
	RING_API_REGISTER("r2d_joinf",ring_r2d_joinf);
	RING_API_REGISTER("r2d_joind",ring_r2d_joind);
	RING_API_REGISTER("pol2d_createf",ring_pol2d_createf);
	RING_API_REGISTER("pol2d_created",ring_pol2d_created);
	RING_API_REGISTER("pol2d_convex_hullf",ring_pol2d_convex_hullf);
	RING_API_REGISTER("pol2d_convex_hulld",ring_pol2d_convex_hulld);
	RING_API_REGISTER("pol2d_copyf",ring_pol2d_copyf);
	RING_API_REGISTER("pol2d_copyd",ring_pol2d_copyd);
	RING_API_REGISTER("pol2d_destroyf",ring_pol2d_destroyf);
	RING_API_REGISTER("pol2d_destroyd",ring_pol2d_destroyd);
	RING_API_REGISTER("pol2d_transformf",ring_pol2d_transformf);
	RING_API_REGISTER("pol2d_transformd",ring_pol2d_transformd);
	RING_API_REGISTER("pol2d_pointsf",ring_pol2d_pointsf);
	RING_API_REGISTER("pol2d_pointsd",ring_pol2d_pointsd);
	RING_API_REGISTER("pol2d_nf",ring_pol2d_nf);
	RING_API_REGISTER("pol2d_nd",ring_pol2d_nd);
	RING_API_REGISTER("pol2d_areaf",ring_pol2d_areaf);
	RING_API_REGISTER("pol2d_aread",ring_pol2d_aread);
	RING_API_REGISTER("pol2d_boxf",ring_pol2d_boxf);
	RING_API_REGISTER("pol2d_boxd",ring_pol2d_boxd);
	RING_API_REGISTER("pol2d_ccwf",ring_pol2d_ccwf);
	RING_API_REGISTER("pol2d_ccwd",ring_pol2d_ccwd);
	RING_API_REGISTER("pol2d_convexf",ring_pol2d_convexf);
	RING_API_REGISTER("pol2d_convexd",ring_pol2d_convexd);
	RING_API_REGISTER("pol2d_centroidf",ring_pol2d_centroidf);
	RING_API_REGISTER("pol2d_centroidd",ring_pol2d_centroidd);
	RING_API_REGISTER("pol2d_visual_centerf",ring_pol2d_visual_centerf);
	RING_API_REGISTER("pol2d_visual_centerd",ring_pol2d_visual_centerd);
	RING_API_REGISTER("obb2d_createf",ring_obb2d_createf);
	RING_API_REGISTER("obb2d_created",ring_obb2d_created);
	RING_API_REGISTER("obb2d_from_linef",ring_obb2d_from_linef);
	RING_API_REGISTER("obb2d_from_lined",ring_obb2d_from_lined);
	RING_API_REGISTER("obb2d_from_pointsf",ring_obb2d_from_pointsf);
	RING_API_REGISTER("obb2d_from_pointsd",ring_obb2d_from_pointsd);
	RING_API_REGISTER("obb2d_copyf",ring_obb2d_copyf);
	RING_API_REGISTER("obb2d_copyd",ring_obb2d_copyd);
	RING_API_REGISTER("obb2d_destroyf",ring_obb2d_destroyf);
	RING_API_REGISTER("obb2d_destroyd",ring_obb2d_destroyd);
	RING_API_REGISTER("obb2d_updatef",ring_obb2d_updatef);
	RING_API_REGISTER("obb2d_updated",ring_obb2d_updated);
	RING_API_REGISTER("obb2d_movef",ring_obb2d_movef);
	RING_API_REGISTER("obb2d_moved",ring_obb2d_moved);
	RING_API_REGISTER("obb2d_transformf",ring_obb2d_transformf);
	RING_API_REGISTER("obb2d_transformd",ring_obb2d_transformd);
	RING_API_REGISTER("obb2d_cornersf",ring_obb2d_cornersf);
	RING_API_REGISTER("obb2d_cornersd",ring_obb2d_cornersd);
	RING_API_REGISTER("obb2d_centerf",ring_obb2d_centerf);
	RING_API_REGISTER("obb2d_centerd",ring_obb2d_centerd);
	RING_API_REGISTER("obb2d_widthf",ring_obb2d_widthf);
	RING_API_REGISTER("obb2d_widthd",ring_obb2d_widthd);
	RING_API_REGISTER("obb2d_heightf",ring_obb2d_heightf);
	RING_API_REGISTER("obb2d_heightd",ring_obb2d_heightd);
	RING_API_REGISTER("obb2d_anglef",ring_obb2d_anglef);
	RING_API_REGISTER("obb2d_angled",ring_obb2d_angled);
	RING_API_REGISTER("obb2d_areaf",ring_obb2d_areaf);
	RING_API_REGISTER("obb2d_aread",ring_obb2d_aread);
	RING_API_REGISTER("obb2d_boxf",ring_obb2d_boxf);
	RING_API_REGISTER("obb2d_boxd",ring_obb2d_boxd);
	RING_API_REGISTER("col2d_point_pointf",ring_col2d_point_pointf);
	RING_API_REGISTER("col2d_point_pointd",ring_col2d_point_pointd);
	RING_API_REGISTER("col2d_segment_pointf",ring_col2d_segment_pointf);
	RING_API_REGISTER("col2d_segment_pointd",ring_col2d_segment_pointd);
	RING_API_REGISTER("col2d_segment_segmentf",ring_col2d_segment_segmentf);
	RING_API_REGISTER("col2d_segment_segmentd",ring_col2d_segment_segmentd);
	RING_API_REGISTER("col2d_circle_pointf",ring_col2d_circle_pointf);
	RING_API_REGISTER("col2d_circle_pointd",ring_col2d_circle_pointd);
	RING_API_REGISTER("col2d_circle_segmentf",ring_col2d_circle_segmentf);
	RING_API_REGISTER("col2d_circle_segmentd",ring_col2d_circle_segmentd);
	RING_API_REGISTER("col2d_circle_circlef",ring_col2d_circle_circlef);
	RING_API_REGISTER("col2d_circle_circled",ring_col2d_circle_circled);
	RING_API_REGISTER("col2d_box_pointf",ring_col2d_box_pointf);
	RING_API_REGISTER("col2d_box_pointd",ring_col2d_box_pointd);
	RING_API_REGISTER("col2d_box_segmentf",ring_col2d_box_segmentf);
	RING_API_REGISTER("col2d_box_segmentd",ring_col2d_box_segmentd);
	RING_API_REGISTER("col2d_box_circlef",ring_col2d_box_circlef);
	RING_API_REGISTER("col2d_box_circled",ring_col2d_box_circled);
	RING_API_REGISTER("col2d_box_boxf",ring_col2d_box_boxf);
	RING_API_REGISTER("col2d_box_boxd",ring_col2d_box_boxd);
	RING_API_REGISTER("col2d_obb_pointf",ring_col2d_obb_pointf);
	RING_API_REGISTER("col2d_obb_pointd",ring_col2d_obb_pointd);
	RING_API_REGISTER("col2d_obb_segmentf",ring_col2d_obb_segmentf);
	RING_API_REGISTER("col2d_obb_segmentd",ring_col2d_obb_segmentd);
	RING_API_REGISTER("col2d_obb_circlef",ring_col2d_obb_circlef);
	RING_API_REGISTER("col2d_obb_circled",ring_col2d_obb_circled);
	RING_API_REGISTER("col2d_obb_boxf",ring_col2d_obb_boxf);
	RING_API_REGISTER("col2d_obb_boxd",ring_col2d_obb_boxd);
	RING_API_REGISTER("col2d_obb_obbf",ring_col2d_obb_obbf);
	RING_API_REGISTER("col2d_obb_obbd",ring_col2d_obb_obbd);
	RING_API_REGISTER("col2d_tri_pointf",ring_col2d_tri_pointf);
	RING_API_REGISTER("col2d_tri_pointd",ring_col2d_tri_pointd);
	RING_API_REGISTER("col2d_tri_segmentf",ring_col2d_tri_segmentf);
	RING_API_REGISTER("col2d_tri_segmentd",ring_col2d_tri_segmentd);
	RING_API_REGISTER("col2d_tri_circlef",ring_col2d_tri_circlef);
	RING_API_REGISTER("col2d_tri_circled",ring_col2d_tri_circled);
	RING_API_REGISTER("col2d_tri_boxf",ring_col2d_tri_boxf);
	RING_API_REGISTER("col2d_tri_boxd",ring_col2d_tri_boxd);
	RING_API_REGISTER("col2d_tri_obbf",ring_col2d_tri_obbf);
	RING_API_REGISTER("col2d_tri_obbd",ring_col2d_tri_obbd);
	RING_API_REGISTER("col2d_tri_trif",ring_col2d_tri_trif);
	RING_API_REGISTER("col2d_tri_trid",ring_col2d_tri_trid);
	RING_API_REGISTER("col2d_poly_pointf",ring_col2d_poly_pointf);
	RING_API_REGISTER("col2d_poly_pointd",ring_col2d_poly_pointd);
	RING_API_REGISTER("col2d_poly_segmentf",ring_col2d_poly_segmentf);
	RING_API_REGISTER("col2d_poly_segmentd",ring_col2d_poly_segmentd);
	RING_API_REGISTER("col2d_poly_circlef",ring_col2d_poly_circlef);
	RING_API_REGISTER("col2d_poly_circled",ring_col2d_poly_circled);
	RING_API_REGISTER("col2d_poly_boxf",ring_col2d_poly_boxf);
	RING_API_REGISTER("col2d_poly_boxd",ring_col2d_poly_boxd);
	RING_API_REGISTER("col2d_poly_obbf",ring_col2d_poly_obbf);
	RING_API_REGISTER("col2d_poly_obbd",ring_col2d_poly_obbd);
	RING_API_REGISTER("col2d_poly_trif",ring_col2d_poly_trif);
	RING_API_REGISTER("col2d_poly_trid",ring_col2d_poly_trid);
	RING_API_REGISTER("col2d_poly_polyf",ring_col2d_poly_polyf);
	RING_API_REGISTER("col2d_poly_polyd",ring_col2d_poly_polyd);
	RING_API_REGISTER("cir2df",ring_cir2df);
	RING_API_REGISTER("cir2dd",ring_cir2dd);
	RING_API_REGISTER("cir2d_from_boxf",ring_cir2d_from_boxf);
	RING_API_REGISTER("cir2d_from_boxd",ring_cir2d_from_boxd);
	RING_API_REGISTER("cir2d_from_pointsf",ring_cir2d_from_pointsf);
	RING_API_REGISTER("cir2d_from_pointsd",ring_cir2d_from_pointsd);
	RING_API_REGISTER("cir2d_minimumf",ring_cir2d_minimumf);
	RING_API_REGISTER("cir2d_minimumd",ring_cir2d_minimumd);
	RING_API_REGISTER("cir2d_areaf",ring_cir2d_areaf);
	RING_API_REGISTER("cir2d_aread",ring_cir2d_aread);
	RING_API_REGISTER("cir2d_is_nullf",ring_cir2d_is_nullf);
	RING_API_REGISTER("cir2d_is_nulld",ring_cir2d_is_nulld);
	RING_API_REGISTER("box2df",ring_box2df);
	RING_API_REGISTER("box2dd",ring_box2dd);
	RING_API_REGISTER("box2d_from_pointsf",ring_box2d_from_pointsf);
	RING_API_REGISTER("box2d_from_pointsd",ring_box2d_from_pointsd);
	RING_API_REGISTER("box2d_centerf",ring_box2d_centerf);
	RING_API_REGISTER("box2d_centerd",ring_box2d_centerd);
	RING_API_REGISTER("box2d_addf",ring_box2d_addf);
	RING_API_REGISTER("box2d_addd",ring_box2d_addd);
	RING_API_REGISTER("box2d_addnf",ring_box2d_addnf);
	RING_API_REGISTER("box2d_addnd",ring_box2d_addnd);
	RING_API_REGISTER("box2d_add_circlef",ring_box2d_add_circlef);
	RING_API_REGISTER("box2d_add_circled",ring_box2d_add_circled);
	RING_API_REGISTER("box2d_mergef",ring_box2d_mergef);
	RING_API_REGISTER("box2d_merged",ring_box2d_merged);
	RING_API_REGISTER("box2d_segmentsf",ring_box2d_segmentsf);
	RING_API_REGISTER("box2d_segmentsd",ring_box2d_segmentsd);
	RING_API_REGISTER("box2d_areaf",ring_box2d_areaf);
	RING_API_REGISTER("box2d_aread",ring_box2d_aread);
	RING_API_REGISTER("box2d_is_nullf",ring_box2d_is_nullf);
	RING_API_REGISTER("box2d_is_nulld",ring_box2d_is_nulld);
	RING_API_REGISTER("pixbuf_create",ring_pixbuf_create);
	RING_API_REGISTER("pixbuf_copy",ring_pixbuf_copy);
	RING_API_REGISTER("pixbuf_trim",ring_pixbuf_trim);
	RING_API_REGISTER("pixbuf_convert",ring_pixbuf_convert);
	RING_API_REGISTER("pixbuf_destroy",ring_pixbuf_destroy);
	RING_API_REGISTER("pixbuf_format",ring_pixbuf_format);
	RING_API_REGISTER("pixbuf_width",ring_pixbuf_width);
	RING_API_REGISTER("pixbuf_height",ring_pixbuf_height);
	RING_API_REGISTER("pixbuf_size",ring_pixbuf_size);
	RING_API_REGISTER("pixbuf_dsize",ring_pixbuf_dsize);
	RING_API_REGISTER("pixbuf_cdata",ring_pixbuf_cdata);
	RING_API_REGISTER("pixbuf_data",ring_pixbuf_data);
	RING_API_REGISTER("pixbuf_format_bpp",ring_pixbuf_format_bpp);
	RING_API_REGISTER("pixbuf_get",ring_pixbuf_get);
	RING_API_REGISTER("pixbuf_set",ring_pixbuf_set);
	RING_API_REGISTER("palette_create",ring_palette_create);
	RING_API_REGISTER("palette_cga2",ring_palette_cga2);
	RING_API_REGISTER("palette_ega4",ring_palette_ega4);
	RING_API_REGISTER("palette_rgb8",ring_palette_rgb8);
	RING_API_REGISTER("palette_gray1",ring_palette_gray1);
	RING_API_REGISTER("palette_gray2",ring_palette_gray2);
	RING_API_REGISTER("palette_gray4",ring_palette_gray4);
	RING_API_REGISTER("palette_gray8",ring_palette_gray8);
	RING_API_REGISTER("palette_binary",ring_palette_binary);
	RING_API_REGISTER("palette_destroy",ring_palette_destroy);
	RING_API_REGISTER("palette_size",ring_palette_size);
	RING_API_REGISTER("palette_colors",ring_palette_colors);
	RING_API_REGISTER("palette_ccolors",ring_palette_ccolors);
	RING_API_REGISTER("image_from_pixels",ring_image_from_pixels);
	RING_API_REGISTER("image_from_pixbuf",ring_image_from_pixbuf);
	RING_API_REGISTER("image_from_file",ring_image_from_file);
	RING_API_REGISTER("image_from_data",ring_image_from_data);
	RING_API_REGISTER("image_from_resource",ring_image_from_resource);
	RING_API_REGISTER("image_copy",ring_image_copy);
	RING_API_REGISTER("image_trim",ring_image_trim);
	RING_API_REGISTER("image_rotate",ring_image_rotate);
	RING_API_REGISTER("image_scale",ring_image_scale);
	RING_API_REGISTER("image_read",ring_image_read);
	RING_API_REGISTER("image_to_file",ring_image_to_file);
	RING_API_REGISTER("image_write",ring_image_write);
	RING_API_REGISTER("image_destroy",ring_image_destroy);
	RING_API_REGISTER("image_format",ring_image_format);
	RING_API_REGISTER("image_width",ring_image_width);
	RING_API_REGISTER("image_height",ring_image_height);
	RING_API_REGISTER("image_pixels",ring_image_pixels);
	RING_API_REGISTER("image_codec",ring_image_codec);
	RING_API_REGISTER("image_get_codec",ring_image_get_codec);
	RING_API_REGISTER("image_num_frames",ring_image_num_frames);
	RING_API_REGISTER("image_frame_length",ring_image_frame_length);
	RING_API_REGISTER("image_data_imp",ring_image_data_imp);
	RING_API_REGISTER("image_get_data_imp",ring_image_get_data_imp);
	RING_API_REGISTER("image_native",ring_image_native);
	RING_API_REGISTER("guictx_create",ring_guictx_create);
	RING_API_REGISTER("guictx_retain",ring_guictx_retain);
	RING_API_REGISTER("guictx_destroy",ring_guictx_destroy);
	RING_API_REGISTER("guictx_release",ring_guictx_release);
	RING_API_REGISTER("guictx_get_current",ring_guictx_get_current);
	RING_API_REGISTER("guictx_set_current",ring_guictx_set_current);
	RING_API_REGISTER("font_create",ring_font_create);
	RING_API_REGISTER("font_system",ring_font_system);
	RING_API_REGISTER("font_monospace",ring_font_monospace);
	RING_API_REGISTER("font_with_style",ring_font_with_style);
	RING_API_REGISTER("font_copy",ring_font_copy);
	RING_API_REGISTER("font_destroy",ring_font_destroy);
	RING_API_REGISTER("font_equals",ring_font_equals);
	RING_API_REGISTER("font_regular_size",ring_font_regular_size);
	RING_API_REGISTER("font_small_size",ring_font_small_size);
	RING_API_REGISTER("font_mini_size",ring_font_mini_size);
	RING_API_REGISTER("font_family",ring_font_family);
	RING_API_REGISTER("font_size",ring_font_size);
	RING_API_REGISTER("font_height",ring_font_height);
	RING_API_REGISTER("font_leading",ring_font_leading);
	RING_API_REGISTER("font_style",ring_font_style);
	RING_API_REGISTER("font_extents",ring_font_extents);
	RING_API_REGISTER("font_exists_family",ring_font_exists_family);
	RING_API_REGISTER("font_native",ring_font_native);
	RING_API_REGISTER("draw_v2df",ring_draw_v2df);
	RING_API_REGISTER("draw_v2dd",ring_draw_v2dd);
	RING_API_REGISTER("draw_seg2df",ring_draw_seg2df);
	RING_API_REGISTER("draw_seg2dd",ring_draw_seg2dd);
	RING_API_REGISTER("draw_cir2df",ring_draw_cir2df);
	RING_API_REGISTER("draw_cir2dd",ring_draw_cir2dd);
	RING_API_REGISTER("draw_box2df",ring_draw_box2df);
	RING_API_REGISTER("draw_box2dd",ring_draw_box2dd);
	RING_API_REGISTER("draw_obb2df",ring_draw_obb2df);
	RING_API_REGISTER("draw_obb2dd",ring_draw_obb2dd);
	RING_API_REGISTER("draw_tri2df",ring_draw_tri2df);
	RING_API_REGISTER("draw_tri2dd",ring_draw_tri2dd);
	RING_API_REGISTER("draw_pol2df",ring_draw_pol2df);
	RING_API_REGISTER("draw_pol2dd",ring_draw_pol2dd);
	RING_API_REGISTER("draw2d_start",ring_draw2d_start);
	RING_API_REGISTER("draw2d_finish",ring_draw2d_finish);
	RING_API_REGISTER("draw_line",ring_draw_line);
	RING_API_REGISTER("draw_polyline",ring_draw_polyline);
	RING_API_REGISTER("draw_arc",ring_draw_arc);
	RING_API_REGISTER("draw_bezier",ring_draw_bezier);
	RING_API_REGISTER("draw_line_color",ring_draw_line_color);
	RING_API_REGISTER("draw_line_fill",ring_draw_line_fill);
	RING_API_REGISTER("draw_line_width",ring_draw_line_width);
	RING_API_REGISTER("draw_line_cap",ring_draw_line_cap);
	RING_API_REGISTER("draw_line_join",ring_draw_line_join);
	RING_API_REGISTER("draw_line_dash",ring_draw_line_dash);
	RING_API_REGISTER("draw_rect",ring_draw_rect);
	RING_API_REGISTER("draw_rndrect",ring_draw_rndrect);
	RING_API_REGISTER("draw_circle",ring_draw_circle);
	RING_API_REGISTER("draw_ellipse",ring_draw_ellipse);
	RING_API_REGISTER("draw_polygon",ring_draw_polygon);
	RING_API_REGISTER("draw_fill_color",ring_draw_fill_color);
	RING_API_REGISTER("draw_fill_linear",ring_draw_fill_linear);
	RING_API_REGISTER("draw_fill_matrix",ring_draw_fill_matrix);
	RING_API_REGISTER("draw_fill_wrap",ring_draw_fill_wrap);
	RING_API_REGISTER("draw_font",ring_draw_font);
	RING_API_REGISTER("draw_text_color",ring_draw_text_color);
	RING_API_REGISTER("draw_text",ring_draw_text);
	RING_API_REGISTER("draw_text_single_line",ring_draw_text_single_line);
	RING_API_REGISTER("draw_text_path",ring_draw_text_path);
	RING_API_REGISTER("draw_text_width",ring_draw_text_width);
	RING_API_REGISTER("draw_text_trim",ring_draw_text_trim);
	RING_API_REGISTER("draw_text_align",ring_draw_text_align);
	RING_API_REGISTER("draw_text_halign",ring_draw_text_halign);
	RING_API_REGISTER("draw_text_extents",ring_draw_text_extents);
	RING_API_REGISTER("draw_image",ring_draw_image);
	RING_API_REGISTER("draw_image_frame",ring_draw_image_frame);
	RING_API_REGISTER("draw_image_align",ring_draw_image_align);
	RING_API_REGISTER("dctx_create",ring_dctx_create);
	RING_API_REGISTER("dctx_destroy",ring_dctx_destroy);
	RING_API_REGISTER("dctx_set_gcontext",ring_dctx_set_gcontext);
	RING_API_REGISTER("dctx_unset_gcontext",ring_dctx_unset_gcontext);
	RING_API_REGISTER("dctx_set_flipped",ring_dctx_set_flipped);
	RING_API_REGISTER("dctx_size",ring_dctx_size);
	RING_API_REGISTER("dctx_offset",ring_dctx_offset);
	RING_API_REGISTER("dctx_line_dash",ring_dctx_line_dash);
	RING_API_REGISTER("dctx_text_width",ring_dctx_text_width);
	RING_API_REGISTER("dctx_text_intalign",ring_dctx_text_intalign);
	RING_API_REGISTER("dctx_text_color",ring_dctx_text_color);
	RING_API_REGISTER("dctx_line_color",ring_dctx_line_color);
	RING_API_REGISTER("dctx_background_color",ring_dctx_background_color);
	RING_API_REGISTER("dctx_text_trim",ring_dctx_text_trim);
	RING_API_REGISTER("dctx_native",ring_dctx_native);
	RING_API_REGISTER("dctx_internal_bitmap",ring_dctx_internal_bitmap);
	RING_API_REGISTER("dctx_data_imp",ring_dctx_data_imp);
	RING_API_REGISTER("dctx_get_data_imp",ring_dctx_get_data_imp);
	RING_API_REGISTER("dctx_set_default_osfont",ring_dctx_set_default_osfont);
	RING_API_REGISTER("draw_set_raster_mode",ring_draw_set_raster_mode);
	RING_API_REGISTER("draw_text_raster",ring_draw_text_raster);
	RING_API_REGISTER("draw_line_imp",ring_draw_line_imp);
	RING_API_REGISTER("draw_rect_imp",ring_draw_rect_imp);
	RING_API_REGISTER("dctx_bitmap",ring_dctx_bitmap);
	RING_API_REGISTER("dctx_image",ring_dctx_image);
	RING_API_REGISTER("draw_clear",ring_draw_clear);
	RING_API_REGISTER("draw_matrixf",ring_draw_matrixf);
	RING_API_REGISTER("draw_matrixd",ring_draw_matrixd);
	RING_API_REGISTER("draw_matrix_cartesianf",ring_draw_matrix_cartesianf);
	RING_API_REGISTER("draw_matrix_cartesiand",ring_draw_matrix_cartesiand);
	RING_API_REGISTER("draw_antialias",ring_draw_antialias);
	RING_API_REGISTER("color_rgb",ring_color_rgb);
	RING_API_REGISTER("color_rgba",ring_color_rgba);
	RING_API_REGISTER("color_rgbaf",ring_color_rgbaf);
	RING_API_REGISTER("color_hsbf",ring_color_hsbf);
	RING_API_REGISTER("color_red",ring_color_red);
	RING_API_REGISTER("color_green",ring_color_green);
	RING_API_REGISTER("color_blue",ring_color_blue);
	RING_API_REGISTER("color_gray",ring_color_gray);
	RING_API_REGISTER("color_bgr",ring_color_bgr);
	RING_API_REGISTER("color_html",ring_color_html);
	RING_API_REGISTER("color_indexed",ring_color_indexed);
	RING_API_REGISTER("color_to_hsbf",ring_color_to_hsbf);
	RING_API_REGISTER("color_to_html",ring_color_to_html);
	RING_API_REGISTER("color_get_rgb",ring_color_get_rgb);
	RING_API_REGISTER("color_get_rgbf",ring_color_get_rgbf);
	RING_API_REGISTER("color_get_rgba",ring_color_get_rgba);
	RING_API_REGISTER("color_get_rgbaf",ring_color_get_rgbaf);
	RING_API_REGISTER("color_get_alpha",ring_color_get_alpha);
	RING_API_REGISTER("color_set_alpha",ring_color_set_alpha);
	RING_API_REGISTER("tfilter_date",ring_tfilter_date);
	RING_API_REGISTER("tfilter_to_date",ring_tfilter_to_date);
	RING_API_REGISTER("str_copy_c",ring_str_copy_c);
	RING_API_REGISTER("str_copy_cn",ring_str_copy_cn);
	RING_API_REGISTER("str_cat",ring_str_cat);
	RING_API_REGISTER("str_cat_c",ring_str_cat_c);
	RING_API_REGISTER("str_cmp_c",ring_str_cmp_c);
	RING_API_REGISTER("str_cmp_cn",ring_str_cmp_cn);
	RING_API_REGISTER("str_empty_c",ring_str_empty_c);
	RING_API_REGISTER("str_equ_c",ring_str_equ_c);
	RING_API_REGISTER("str_equ_cn",ring_str_equ_cn);
	RING_API_REGISTER("str_equ_nocase",ring_str_equ_nocase);
	RING_API_REGISTER("str_equ_end",ring_str_equ_end);
	RING_API_REGISTER("str_upper_c",ring_str_upper_c);
	RING_API_REGISTER("str_lower_c",ring_str_lower_c);
	RING_API_REGISTER("str_repl_c",ring_str_repl_c);
	RING_API_REGISTER("str_str",ring_str_str);
	RING_API_REGISTER("str_filename",ring_str_filename);
	RING_API_REGISTER("str_filext",ring_str_filext);
	RING_API_REGISTER("str_to_i8",ring_str_to_i8);
	RING_API_REGISTER("str_to_i16",ring_str_to_i16);
	RING_API_REGISTER("str_to_i32",ring_str_to_i32);
	RING_API_REGISTER("str_to_i64",ring_str_to_i64);
	RING_API_REGISTER("str_to_u8",ring_str_to_u8);
	RING_API_REGISTER("str_to_u16",ring_str_to_u16);
	RING_API_REGISTER("str_to_u32",ring_str_to_u32);
	RING_API_REGISTER("str_to_u64",ring_str_to_u64);
	RING_API_REGISTER("str_to_r32",ring_str_to_r32);
	RING_API_REGISTER("str_to_r64",ring_str_to_r64);
	RING_API_REGISTER("stm_from_block",ring_stm_from_block);
	RING_API_REGISTER("stm_memory",ring_stm_memory);
	RING_API_REGISTER("stm_from_file",ring_stm_from_file);
	RING_API_REGISTER("stm_to_file",ring_stm_to_file);
	RING_API_REGISTER("stm_append_file",ring_stm_append_file);
	RING_API_REGISTER("stm_socket",ring_stm_socket);
	RING_API_REGISTER("stm_close",ring_stm_close);
	RING_API_REGISTER("stm_get_write_endian",ring_stm_get_write_endian);
	RING_API_REGISTER("stm_get_read_endian",ring_stm_get_read_endian);
	RING_API_REGISTER("stm_set_write_endian",ring_stm_set_write_endian);
	RING_API_REGISTER("stm_set_read_endian",ring_stm_set_read_endian);
	RING_API_REGISTER("stm_get_write_utf",ring_stm_get_write_utf);
	RING_API_REGISTER("stm_get_read_utf",ring_stm_get_read_utf);
	RING_API_REGISTER("stm_set_write_utf",ring_stm_set_write_utf);
	RING_API_REGISTER("stm_set_read_utf",ring_stm_set_read_utf);
	RING_API_REGISTER("stm_is_memory",ring_stm_is_memory);
	RING_API_REGISTER("stm_bytes_written",ring_stm_bytes_written);
	RING_API_REGISTER("stm_bytes_readed",ring_stm_bytes_readed);
	RING_API_REGISTER("stm_col",ring_stm_col);
	RING_API_REGISTER("stm_row",ring_stm_row);
	RING_API_REGISTER("stm_token_col",ring_stm_token_col);
	RING_API_REGISTER("stm_token_row",ring_stm_token_row);
	RING_API_REGISTER("stm_token_lexeme",ring_stm_token_lexeme);
	RING_API_REGISTER("stm_token_escapes",ring_stm_token_escapes);
	RING_API_REGISTER("stm_token_spaces",ring_stm_token_spaces);
	RING_API_REGISTER("stm_token_comments",ring_stm_token_comments);
	RING_API_REGISTER("stm_state",ring_stm_state);
	RING_API_REGISTER("stm_file_err",ring_stm_file_err);
	RING_API_REGISTER("stm_sock_err",ring_stm_sock_err);
	RING_API_REGISTER("stm_corrupt",ring_stm_corrupt);
	RING_API_REGISTER("stm_str",ring_stm_str);
	RING_API_REGISTER("stm_buffer",ring_stm_buffer);
	RING_API_REGISTER("stm_buffer_size",ring_stm_buffer_size);
	RING_API_REGISTER("stm_write",ring_stm_write);
	RING_API_REGISTER("stm_write_char",ring_stm_write_char);
	RING_API_REGISTER("stm_writef",ring_stm_writef);
	RING_API_REGISTER("stm_write_bool",ring_stm_write_bool);
	RING_API_REGISTER("stm_write_i8",ring_stm_write_i8);
	RING_API_REGISTER("stm_write_i16",ring_stm_write_i16);
	RING_API_REGISTER("stm_write_i32",ring_stm_write_i32);
	RING_API_REGISTER("stm_write_i64",ring_stm_write_i64);
	RING_API_REGISTER("stm_write_u8",ring_stm_write_u8);
	RING_API_REGISTER("stm_write_u16",ring_stm_write_u16);
	RING_API_REGISTER("stm_write_u32",ring_stm_write_u32);
	RING_API_REGISTER("stm_write_u64",ring_stm_write_u64);
	RING_API_REGISTER("stm_write_r32",ring_stm_write_r32);
	RING_API_REGISTER("stm_write_r64",ring_stm_write_r64);
	RING_API_REGISTER("stm_read",ring_stm_read);
	RING_API_REGISTER("stm_read_char",ring_stm_read_char);
	RING_API_REGISTER("stm_read_chars",ring_stm_read_chars);
	RING_API_REGISTER("stm_read_line",ring_stm_read_line);
	RING_API_REGISTER("stm_read_trim",ring_stm_read_trim);
	RING_API_REGISTER("stm_read_token",ring_stm_read_token);
	RING_API_REGISTER("stm_read_i8_tok",ring_stm_read_i8_tok);
	RING_API_REGISTER("stm_read_i16_tok",ring_stm_read_i16_tok);
	RING_API_REGISTER("stm_read_i32_tok",ring_stm_read_i32_tok);
	RING_API_REGISTER("stm_read_i64_tok",ring_stm_read_i64_tok);
	RING_API_REGISTER("stm_read_u8_tok",ring_stm_read_u8_tok);
	RING_API_REGISTER("stm_read_u16_tok",ring_stm_read_u16_tok);
	RING_API_REGISTER("stm_read_u32_tok",ring_stm_read_u32_tok);
	RING_API_REGISTER("stm_read_u64_tok",ring_stm_read_u64_tok);
	RING_API_REGISTER("stm_read_r32_tok",ring_stm_read_r32_tok);
	RING_API_REGISTER("stm_read_r64_tok",ring_stm_read_r64_tok);
	RING_API_REGISTER("stm_read_bool",ring_stm_read_bool);
	RING_API_REGISTER("stm_read_i8",ring_stm_read_i8);
	RING_API_REGISTER("stm_read_i16",ring_stm_read_i16);
	RING_API_REGISTER("stm_read_i32",ring_stm_read_i32);
	RING_API_REGISTER("stm_read_i64",ring_stm_read_i64);
	RING_API_REGISTER("stm_read_u8",ring_stm_read_u8);
	RING_API_REGISTER("stm_read_u16",ring_stm_read_u16);
	RING_API_REGISTER("stm_read_u32",ring_stm_read_u32);
	RING_API_REGISTER("stm_read_u64",ring_stm_read_u64);
	RING_API_REGISTER("stm_read_r32",ring_stm_read_r32);
	RING_API_REGISTER("stm_read_r64",ring_stm_read_r64);
	RING_API_REGISTER("stm_skip",ring_stm_skip);
	RING_API_REGISTER("stm_skip_bom",ring_stm_skip_bom);
	RING_API_REGISTER("stm_skip_token",ring_stm_skip_token);
	RING_API_REGISTER("stm_flush",ring_stm_flush);
	RING_API_REGISTER("stm_pipe",ring_stm_pipe);
	RING_API_REGISTER("respack_destroy",ring_respack_destroy);
	RING_API_REGISTER("respack_text",ring_respack_text);
	RING_API_REGISTER("respack_file",ring_respack_file);
	RING_API_REGISTER("regex_create",ring_regex_create);
	RING_API_REGISTER("regex_destroy",ring_regex_destroy);
	RING_API_REGISTER("regex_match",ring_regex_match);
	RING_API_REGISTER("rbtree_create",ring_rbtree_create);
	RING_API_REGISTER("rbtree_destroy",ring_rbtree_destroy);
	RING_API_REGISTER("rbtree_destroy_ptr",ring_rbtree_destroy_ptr);
	RING_API_REGISTER("rbtree_size",ring_rbtree_size);
	RING_API_REGISTER("rbtree_get",ring_rbtree_get);
	RING_API_REGISTER("rbtree_insert",ring_rbtree_insert);
	RING_API_REGISTER("rbtree_insert_ptr",ring_rbtree_insert_ptr);
	RING_API_REGISTER("rbtree_delete",ring_rbtree_delete);
	RING_API_REGISTER("rbtree_delete_ptr",ring_rbtree_delete_ptr);
	RING_API_REGISTER("rbtree_first",ring_rbtree_first);
	RING_API_REGISTER("rbtree_last",ring_rbtree_last);
	RING_API_REGISTER("rbtree_next",ring_rbtree_next);
	RING_API_REGISTER("rbtree_prev",ring_rbtree_prev);
	RING_API_REGISTER("rbtree_first_ptr",ring_rbtree_first_ptr);
	RING_API_REGISTER("rbtree_last_ptr",ring_rbtree_last_ptr);
	RING_API_REGISTER("rbtree_next_ptr",ring_rbtree_next_ptr);
	RING_API_REGISTER("rbtree_prev_ptr",ring_rbtree_prev_ptr);
	RING_API_REGISTER("rbtree_get_key",ring_rbtree_get_key);
	RING_API_REGISTER("rbtree_check",ring_rbtree_check);
	RING_API_REGISTER("obj_init",ring_obj_init);
	RING_API_REGISTER("obj_new_imp",ring_obj_new_imp);
	RING_API_REGISTER("obj_new0_imp",ring_obj_new0_imp);
	RING_API_REGISTER("obj_retain_imp",ring_obj_retain_imp);
	RING_API_REGISTER("obj_retain_optional_imp",ring_obj_retain_optional_imp);
	RING_API_REGISTER("obj_remove",ring_obj_remove);
	RING_API_REGISTER("obj_release_imp",ring_obj_release_imp);
	RING_API_REGISTER("obj_release_optional_imp",ring_obj_release_optional_imp);
	RING_API_REGISTER("obj_delete_imp",ring_obj_delete_imp);
	RING_API_REGISTER("obj_listener_imp",ring_obj_listener_imp);
	RING_API_REGISTER("keybuf_create",ring_keybuf_create);
	RING_API_REGISTER("keybuf_destroy",ring_keybuf_destroy);
	RING_API_REGISTER("keybuf_onup",ring_keybuf_OnUp);
	RING_API_REGISTER("keybuf_ondown",ring_keybuf_OnDown);
	RING_API_REGISTER("keybuf_clear",ring_keybuf_clear);
	RING_API_REGISTER("keybuf_pressed",ring_keybuf_pressed);
	RING_API_REGISTER("keybuf_str",ring_keybuf_str);
	RING_API_REGISTER("keybuf_dump",ring_keybuf_dump);
	RING_API_REGISTER("hfile_exename",ring_hfile_exename);
	RING_API_REGISTER("hfile_dir",ring_hfile_dir);
	RING_API_REGISTER("hfile_dir_create",ring_hfile_dir_create);
	RING_API_REGISTER("hfile_dir_destroy",ring_hfile_dir_destroy);
	RING_API_REGISTER("hfile_dir_entry_remove",ring_hfile_dir_entry_remove);
	RING_API_REGISTER("hfile_date",ring_hfile_date);
	RING_API_REGISTER("hfile_dir_sync",ring_hfile_dir_sync);
	RING_API_REGISTER("hfile_exists",ring_hfile_exists);
	RING_API_REGISTER("hfile_is_uptodate",ring_hfile_is_uptodate);
	RING_API_REGISTER("hfile_copy",ring_hfile_copy);
	RING_API_REGISTER("hfile_buffer",ring_hfile_buffer);
	RING_API_REGISTER("hfile_string",ring_hfile_string);
	RING_API_REGISTER("hfile_stream",ring_hfile_stream);
	RING_API_REGISTER("hfile_from_string",ring_hfile_from_string);
	RING_API_REGISTER("hfile_from_data",ring_hfile_from_data);
	RING_API_REGISTER("hfile_dir_loop",ring_hfile_dir_loop);
	RING_API_REGISTER("hfile_appdata",ring_hfile_appdata);
	RING_API_REGISTER("hfile_home_dir",ring_hfile_home_dir);
	RING_API_REGISTER("heap_start_mt",ring_heap_start_mt);
	RING_API_REGISTER("heap_end_mt",ring_heap_end_mt);
	RING_API_REGISTER("heap_verbose",ring_heap_verbose);
	RING_API_REGISTER("heap_stats",ring_heap_stats);
	RING_API_REGISTER("heap_leaks",ring_heap_leaks);
	RING_API_REGISTER("heap_malloc_imp",ring_heap_malloc_imp);
	RING_API_REGISTER("heap_calloc_imp",ring_heap_calloc_imp);
	RING_API_REGISTER("heap_realloc",ring_heap_realloc);
	RING_API_REGISTER("heap_aligned_malloc_imp",ring_heap_aligned_malloc_imp);
	RING_API_REGISTER("heap_aligned_calloc_imp",ring_heap_aligned_calloc_imp);
	RING_API_REGISTER("heap_aligned_realloc",ring_heap_aligned_realloc);
	RING_API_REGISTER("heap_free",ring_heap_free);
	RING_API_REGISTER("heap_auditor_add",ring_heap_auditor_add);
	RING_API_REGISTER("heap_auditor_delete",ring_heap_auditor_delete);
	RING_API_REGISTER("listener_imp",ring_listener_imp);
	RING_API_REGISTER("listener_destroy",ring_listener_destroy);
	RING_API_REGISTER("listener_update",ring_listener_update);
	RING_API_REGISTER("listener_event_imp",ring_listener_event_imp);
	RING_API_REGISTER("listener_pass_event_imp",ring_listener_pass_event_imp);
	RING_API_REGISTER("event_type",ring_event_type);
	RING_API_REGISTER("event_sender_imp",ring_event_sender_imp);
	RING_API_REGISTER("event_params_imp",ring_event_params_imp);
	RING_API_REGISTER("event_result_imp",ring_event_result_imp);
	RING_API_REGISTER("dbind_imp",ring_dbind_imp);
	RING_API_REGISTER("dbind_enum_imp",ring_dbind_enum_imp);
	RING_API_REGISTER("dbind_create_imp",ring_dbind_create_imp);
	RING_API_REGISTER("dbind_init_imp",ring_dbind_init_imp);
	RING_API_REGISTER("dbind_remove_imp",ring_dbind_remove_imp);
	RING_API_REGISTER("dbind_destroy_imp",ring_dbind_destroy_imp);
	RING_API_REGISTER("dbind_destopt_imp",ring_dbind_destopt_imp);
	RING_API_REGISTER("dbind_read_imp",ring_dbind_read_imp);
	RING_API_REGISTER("dbind_write_imp",ring_dbind_write_imp);
	RING_API_REGISTER("dbind_default_imp",ring_dbind_default_imp);
	RING_API_REGISTER("dbind_range_imp",ring_dbind_range_imp);
	RING_API_REGISTER("dbind_precision_imp",ring_dbind_precision_imp);
	RING_API_REGISTER("dbind_increment_imp",ring_dbind_increment_imp);
	RING_API_REGISTER("dbind_suffix_imp",ring_dbind_suffix_imp);
	RING_API_REGISTER("date_system",ring_date_system);
	RING_API_REGISTER("date_pack",ring_date_pack);
	RING_API_REGISTER("date_add_seconds",ring_date_add_seconds);
	RING_API_REGISTER("date_add_minutes",ring_date_add_minutes);
	RING_API_REGISTER("date_add_hours",ring_date_add_hours);
	RING_API_REGISTER("date_add_days",ring_date_add_days);
	RING_API_REGISTER("date_year",ring_date_year);
	RING_API_REGISTER("date_cmp",ring_date_cmp);
	RING_API_REGISTER("date_ellapsed_seconds",ring_date_ellapsed_seconds);
	RING_API_REGISTER("date_between",ring_date_between);
	RING_API_REGISTER("date_is_null",ring_date_is_null);
	RING_API_REGISTER("date_is_valid",ring_date_is_valid);
	RING_API_REGISTER("date_weekday",ring_date_weekday);
	RING_API_REGISTER("date_format",ring_date_format);
	RING_API_REGISTER("core_start",ring_core_start);
	RING_API_REGISTER("core_finish",ring_core_finish);
	RING_API_REGISTER("clock_create",ring_clock_create);
	RING_API_REGISTER("clock_destroy",ring_clock_destroy);
	RING_API_REGISTER("clock_frame",ring_clock_frame);
	RING_API_REGISTER("clock_reset",ring_clock_reset);
	RING_API_REGISTER("clock_elapsed",ring_clock_elapsed);
	RING_API_REGISTER("buffer_create",ring_buffer_create);
	RING_API_REGISTER("buffer_with_data",ring_buffer_with_data);
	RING_API_REGISTER("buffer_destroy",ring_buffer_destroy);
	RING_API_REGISTER("buffer_size",ring_buffer_size);
	RING_API_REGISTER("buffer_data",ring_buffer_data);
	RING_API_REGISTER("buffer_const",ring_buffer_const);
	RING_API_REGISTER("bhash_from_block",ring_bhash_from_block);
	RING_API_REGISTER("bhash_append_uint32",ring_bhash_append_uint32);
	RING_API_REGISTER("bhash_append_real32",ring_bhash_append_real32);
	RING_API_REGISTER("array_create",ring_array_create);
	RING_API_REGISTER("array_copy",ring_array_copy);
	RING_API_REGISTER("array_copy_ptr",ring_array_copy_ptr);
	RING_API_REGISTER("array_read",ring_array_read);
	RING_API_REGISTER("array_read_ptr",ring_array_read_ptr);
	RING_API_REGISTER("array_destroy",ring_array_destroy);
	RING_API_REGISTER("array_destopt",ring_array_destopt);
	RING_API_REGISTER("array_destroy_ptr",ring_array_destroy_ptr);
	RING_API_REGISTER("array_destopt_ptr",ring_array_destopt_ptr);
	RING_API_REGISTER("array_clear",ring_array_clear);
	RING_API_REGISTER("array_clear_ptr",ring_array_clear_ptr);
	RING_API_REGISTER("array_write",ring_array_write);
	RING_API_REGISTER("array_write_ptr",ring_array_write_ptr);
	RING_API_REGISTER("array_size",ring_array_size);
	RING_API_REGISTER("array_esize",ring_array_esize);
	RING_API_REGISTER("array_get",ring_array_get);
	RING_API_REGISTER("array_get_last",ring_array_get_last);
	RING_API_REGISTER("array_all",ring_array_all);
	RING_API_REGISTER("array_insert",ring_array_insert);
	RING_API_REGISTER("array_insert0",ring_array_insert0);
	RING_API_REGISTER("array_join",ring_array_join);
	RING_API_REGISTER("array_join_ptr",ring_array_join_ptr);
	RING_API_REGISTER("array_delete",ring_array_delete);
	RING_API_REGISTER("array_delete_ptr",ring_array_delete_ptr);
	RING_API_REGISTER("array_pop",ring_array_pop);
	RING_API_REGISTER("array_pop_ptr",ring_array_pop_ptr);
	RING_API_REGISTER("array_sort",ring_array_sort);
	RING_API_REGISTER("array_sort_ex",ring_array_sort_ex);
	RING_API_REGISTER("array_sort_ptr",ring_array_sort_ptr);
	RING_API_REGISTER("array_sort_ptr_ex",ring_array_sort_ptr_ex);
	RING_API_REGISTER("array_find_ptr",ring_array_find_ptr);
	RING_API_REGISTER("array_search",ring_array_search);
	RING_API_REGISTER("array_search_ptr",ring_array_search_ptr);
	RING_API_REGISTER("array_bsearch",ring_array_bsearch);
	RING_API_REGISTER("array_bsearch_ptr",ring_array_bsearch_ptr);
	RING_API_REGISTER("get_ekgui_horizontal",ring_get_ekgui_horizontal);
	RING_API_REGISTER("get_ekgui_vertical",ring_get_ekgui_vertical);
	RING_API_REGISTER("get_ekgui_off",ring_get_ekgui_off);
	RING_API_REGISTER("get_ekgui_on",ring_get_ekgui_on);
	RING_API_REGISTER("get_ekgui_mixed",ring_get_ekgui_mixed);
	RING_API_REGISTER("get_ekgui_mouse_left",ring_get_ekgui_mouse_left);
	RING_API_REGISTER("get_ekgui_mouse_right",ring_get_ekgui_mouse_right);
	RING_API_REGISTER("get_ekgui_mouse_middle",ring_get_ekgui_mouse_middle);
	RING_API_REGISTER("get_ekgui_cursor_arrow",ring_get_ekgui_cursor_arrow);
	RING_API_REGISTER("get_ekgui_cursor_hand",ring_get_ekgui_cursor_hand);
	RING_API_REGISTER("get_ekgui_cursor_ibeam",ring_get_ekgui_cursor_ibeam);
	RING_API_REGISTER("get_ekgui_cursor_cross",ring_get_ekgui_cursor_cross);
	RING_API_REGISTER("get_ekgui_cursor_sizewe",ring_get_ekgui_cursor_sizewe);
	RING_API_REGISTER("get_ekgui_cursor_sizens",ring_get_ekgui_cursor_sizens);
	RING_API_REGISTER("get_ekgui_cursor_user",ring_get_ekgui_cursor_user);
	RING_API_REGISTER("get_ekgui_close_esc",ring_get_ekgui_close_esc);
	RING_API_REGISTER("get_ekgui_close_intro",ring_get_ekgui_close_intro);
	RING_API_REGISTER("get_ekgui_close_button",ring_get_ekgui_close_button);
	RING_API_REGISTER("get_ekgui_close_deact",ring_get_ekgui_close_deact);
	RING_API_REGISTER("get_ekgui_scale_auto",ring_get_ekgui_scale_auto);
	RING_API_REGISTER("get_ekgui_scale_none",ring_get_ekgui_scale_none);
	RING_API_REGISTER("get_ekgui_scale_aspect",ring_get_ekgui_scale_aspect);
	RING_API_REGISTER("get_ekgui_scale_aspectdw",ring_get_ekgui_scale_aspectdw);
	RING_API_REGISTER("get_ekgui_scroll_begin",ring_get_ekgui_scroll_begin);
	RING_API_REGISTER("get_ekgui_scroll_end",ring_get_ekgui_scroll_end);
	RING_API_REGISTER("get_ekgui_scroll_step_left",ring_get_ekgui_scroll_step_left);
	RING_API_REGISTER("get_ekgui_scroll_step_right",ring_get_ekgui_scroll_step_right);
	RING_API_REGISTER("get_ekgui_scroll_page_left",ring_get_ekgui_scroll_page_left);
	RING_API_REGISTER("get_ekgui_scroll_page_right",ring_get_ekgui_scroll_page_right);
	RING_API_REGISTER("get_ekgui_scroll_thumb",ring_get_ekgui_scroll_thumb);
	RING_API_REGISTER("get_ekgui_focus_changed",ring_get_ekgui_focus_changed);
	RING_API_REGISTER("get_ekgui_focus_keep",ring_get_ekgui_focus_keep);
	RING_API_REGISTER("get_ekgui_focus_no_next",ring_get_ekgui_focus_no_next);
	RING_API_REGISTER("get_ekgui_focus_no_resign",ring_get_ekgui_focus_no_resign);
	RING_API_REGISTER("get_ekgui_focus_no_accept",ring_get_ekgui_focus_no_accept);
	RING_API_REGISTER("get_ekgui_tab_key",ring_get_ekgui_tab_key);
	RING_API_REGISTER("get_ekgui_tab_backkey",ring_get_ekgui_tab_backkey);
	RING_API_REGISTER("get_ekgui_tab_next",ring_get_ekgui_tab_next);
	RING_API_REGISTER("get_ekgui_tab_prev",ring_get_ekgui_tab_prev);
	RING_API_REGISTER("get_ekgui_tab_move",ring_get_ekgui_tab_move);
	RING_API_REGISTER("get_ekgui_tab_click",ring_get_ekgui_tab_click);
	RING_API_REGISTER("get_ekgui_event_label",ring_get_ekgui_event_label);
	RING_API_REGISTER("get_ekgui_event_button",ring_get_ekgui_event_button);
	RING_API_REGISTER("get_ekgui_event_popup",ring_get_ekgui_event_popup);
	RING_API_REGISTER("get_ekgui_event_listbox",ring_get_ekgui_event_listbox);
	RING_API_REGISTER("get_ekgui_event_slider",ring_get_ekgui_event_slider);
	RING_API_REGISTER("get_ekgui_event_updown",ring_get_ekgui_event_updown);
	RING_API_REGISTER("get_ekgui_event_txtfilter",ring_get_ekgui_event_txtfilter);
	RING_API_REGISTER("get_ekgui_event_txtchange",ring_get_ekgui_event_txtchange);
	RING_API_REGISTER("get_ekgui_event_focus_resign",ring_get_ekgui_event_focus_resign);
	RING_API_REGISTER("get_ekgui_event_focus_accept",ring_get_ekgui_event_focus_accept);
	RING_API_REGISTER("get_ekgui_event_focus",ring_get_ekgui_event_focus);
	RING_API_REGISTER("get_ekgui_event_menu",ring_get_ekgui_event_menu);
	RING_API_REGISTER("get_ekgui_event_draw",ring_get_ekgui_event_draw);
	RING_API_REGISTER("get_ekgui_event_overlay",ring_get_ekgui_event_overlay);
	RING_API_REGISTER("get_ekgui_event_resize",ring_get_ekgui_event_resize);
	RING_API_REGISTER("get_ekgui_event_enter",ring_get_ekgui_event_enter);
	RING_API_REGISTER("get_ekgui_event_exit",ring_get_ekgui_event_exit);
	RING_API_REGISTER("get_ekgui_event_moved",ring_get_ekgui_event_moved);
	RING_API_REGISTER("get_ekgui_event_down",ring_get_ekgui_event_down);
	RING_API_REGISTER("get_ekgui_event_up",ring_get_ekgui_event_up);
	RING_API_REGISTER("get_ekgui_event_click",ring_get_ekgui_event_click);
	RING_API_REGISTER("get_ekgui_event_drag",ring_get_ekgui_event_drag);
	RING_API_REGISTER("get_ekgui_event_wheel",ring_get_ekgui_event_wheel);
	RING_API_REGISTER("get_ekgui_event_keydown",ring_get_ekgui_event_keydown);
	RING_API_REGISTER("get_ekgui_event_keyup",ring_get_ekgui_event_keyup);
	RING_API_REGISTER("get_ekgui_event_scroll",ring_get_ekgui_event_scroll);
	RING_API_REGISTER("get_ekgui_event_wnd_moved",ring_get_ekgui_event_wnd_moved);
	RING_API_REGISTER("get_ekgui_event_wnd_sizing",ring_get_ekgui_event_wnd_sizing);
	RING_API_REGISTER("get_ekgui_event_wnd_size",ring_get_ekgui_event_wnd_size);
	RING_API_REGISTER("get_ekgui_event_wnd_close",ring_get_ekgui_event_wnd_close);
	RING_API_REGISTER("get_ekgui_event_color",ring_get_ekgui_event_color);
	RING_API_REGISTER("get_ekgui_event_theme",ring_get_ekgui_event_theme);
	RING_API_REGISTER("get_ekgui_event_objchange",ring_get_ekgui_event_objchange);
	RING_API_REGISTER("get_ekgui_event_tbl_nrows",ring_get_ekgui_event_tbl_nrows);
	RING_API_REGISTER("get_ekgui_event_tbl_begin",ring_get_ekgui_event_tbl_begin);
	RING_API_REGISTER("get_ekgui_event_tbl_end",ring_get_ekgui_event_tbl_end);
	RING_API_REGISTER("get_ekgui_event_tbl_cell",ring_get_ekgui_event_tbl_cell);
	RING_API_REGISTER("get_ekgui_event_tbl_sel",ring_get_ekgui_event_tbl_sel);
	RING_API_REGISTER("get_ekgui_event_tbl_headclick",ring_get_ekgui_event_tbl_headclick);
	RING_API_REGISTER("get_ekgui_event_tbl_rowclick",ring_get_ekgui_event_tbl_rowclick);
	RING_API_REGISTER("get_ekgui_event_idle",ring_get_ekgui_event_idle);
	RING_API_REGISTER("get_ekgui_type_label",ring_get_ekgui_type_label);
	RING_API_REGISTER("get_ekgui_type_button",ring_get_ekgui_type_button);
	RING_API_REGISTER("get_ekgui_type_popup",ring_get_ekgui_type_popup);
	RING_API_REGISTER("get_ekgui_type_editbox",ring_get_ekgui_type_editbox);
	RING_API_REGISTER("get_ekgui_type_combobox",ring_get_ekgui_type_combobox);
	RING_API_REGISTER("get_ekgui_type_slider",ring_get_ekgui_type_slider);
	RING_API_REGISTER("get_ekgui_type_updown",ring_get_ekgui_type_updown);
	RING_API_REGISTER("get_ekgui_type_progress",ring_get_ekgui_type_progress);
	RING_API_REGISTER("get_ekgui_type_textview",ring_get_ekgui_type_textview);
	RING_API_REGISTER("get_ekgui_type_tableview",ring_get_ekgui_type_tableview);
	RING_API_REGISTER("get_ekgui_type_treeview",ring_get_ekgui_type_treeview);
	RING_API_REGISTER("get_ekgui_type_boxview",ring_get_ekgui_type_boxview);
	RING_API_REGISTER("get_ekgui_type_splitview",ring_get_ekgui_type_splitview);
	RING_API_REGISTER("get_ekgui_type_customview",ring_get_ekgui_type_customview);
	RING_API_REGISTER("get_ekgui_type_panel",ring_get_ekgui_type_panel);
	RING_API_REGISTER("get_ekgui_type_line",ring_get_ekgui_type_line);
	RING_API_REGISTER("get_ekgui_type_header",ring_get_ekgui_type_header);
	RING_API_REGISTER("get_ekgui_type_window",ring_get_ekgui_type_window);
	RING_API_REGISTER("get_ekgui_type_toolbar",ring_get_ekgui_type_toolbar);
	RING_API_REGISTER("get_ekgui_size_mini",ring_get_ekgui_size_mini);
	RING_API_REGISTER("get_ekgui_size_small",ring_get_ekgui_size_small);
	RING_API_REGISTER("get_ekgui_size_regular",ring_get_ekgui_size_regular);
	RING_API_REGISTER("get_ekgui_role_main",ring_get_ekgui_role_main);
	RING_API_REGISTER("get_ekgui_role_overlay",ring_get_ekgui_role_overlay);
	RING_API_REGISTER("get_ekgui_role_modal",ring_get_ekgui_role_modal);
	RING_API_REGISTER("get_ekgui_role_managed",ring_get_ekgui_role_managed);
	RING_API_REGISTER("get_ekgui_prop_resize",ring_get_ekgui_prop_resize);
	RING_API_REGISTER("get_ekgui_prop_children",ring_get_ekgui_prop_children);
	RING_API_REGISTER("get_ekgui_text_family",ring_get_ekgui_text_family);
	RING_API_REGISTER("get_ekgui_text_units",ring_get_ekgui_text_units);
	RING_API_REGISTER("get_ekgui_text_size",ring_get_ekgui_text_size);
	RING_API_REGISTER("get_ekgui_text_style",ring_get_ekgui_text_style);
	RING_API_REGISTER("get_ekgui_text_color",ring_get_ekgui_text_color);
	RING_API_REGISTER("get_ekgui_text_bgcolor",ring_get_ekgui_text_bgcolor);
	RING_API_REGISTER("get_ekgui_text_pgcolor",ring_get_ekgui_text_pgcolor);
	RING_API_REGISTER("get_ekgui_text_paralign",ring_get_ekgui_text_paralign);
	RING_API_REGISTER("get_ekgui_text_lspacing",ring_get_ekgui_text_lspacing);
	RING_API_REGISTER("get_ekgui_text_bfparspace",ring_get_ekgui_text_bfparspace);
	RING_API_REGISTER("get_ekgui_text_afparspace",ring_get_ekgui_text_afparspace);
	RING_API_REGISTER("get_ekgui_text_select",ring_get_ekgui_text_select);
	RING_API_REGISTER("get_ekgui_text_scroll",ring_get_ekgui_text_scroll);
	RING_API_REGISTER("get_ekclipboard_copy",ring_get_ekclipboard_copy);
	RING_API_REGISTER("get_ekclipboard_cut",ring_get_ekclipboard_cut);
	RING_API_REGISTER("get_ekclipboard_paste",ring_get_ekclipboard_paste);
	RING_API_REGISTER("get_eklabel_flag",ring_get_eklabel_flag);
	RING_API_REGISTER("get_eklabel_single",ring_get_eklabel_single);
	RING_API_REGISTER("get_eklabel_multi",ring_get_eklabel_multi);
	RING_API_REGISTER("get_eklabel_type",ring_get_eklabel_type);
	RING_API_REGISTER("get_ekbutton_flag",ring_get_ekbutton_flag);
	RING_API_REGISTER("get_ekbutton_push",ring_get_ekbutton_push);
	RING_API_REGISTER("get_ekbutton_check2",ring_get_ekbutton_check2);
	RING_API_REGISTER("get_ekbutton_check3",ring_get_ekbutton_check3);
	RING_API_REGISTER("get_ekbutton_radio",ring_get_ekbutton_radio);
	RING_API_REGISTER("get_ekbutton_flat",ring_get_ekbutton_flat);
	RING_API_REGISTER("get_ekbutton_flatgle",ring_get_ekbutton_flatgle);
	RING_API_REGISTER("get_ekbutton_header",ring_get_ekbutton_header);
	RING_API_REGISTER("get_ekbutton_type",ring_get_ekbutton_type);
	RING_API_REGISTER("get_ekpopup_flag",ring_get_ekpopup_flag);
	RING_API_REGISTER("get_ekedit_flag",ring_get_ekedit_flag);
	RING_API_REGISTER("get_ekedit_single",ring_get_ekedit_single);
	RING_API_REGISTER("get_ekedit_multi",ring_get_ekedit_multi);
	RING_API_REGISTER("get_ekedit_type",ring_get_ekedit_type);
	RING_API_REGISTER("get_ekedit_autosel",ring_get_ekedit_autosel);
	RING_API_REGISTER("get_ekcombo_flag",ring_get_ekcombo_flag);
	RING_API_REGISTER("get_ekslider_flag",ring_get_ekslider_flag);
	RING_API_REGISTER("get_ekslider_horz",ring_get_ekslider_horz);
	RING_API_REGISTER("get_ekslider_vert",ring_get_ekslider_vert);
	RING_API_REGISTER("get_ekslider_type",ring_get_ekslider_type);
	RING_API_REGISTER("get_ekupdown_flag",ring_get_ekupdown_flag);
	RING_API_REGISTER("get_ekprogress_flag",ring_get_ekprogress_flag);
	RING_API_REGISTER("get_ekprogress_horz",ring_get_ekprogress_horz);
	RING_API_REGISTER("get_ekprogress_vert",ring_get_ekprogress_vert);
	RING_API_REGISTER("get_ekprogress_type",ring_get_ekprogress_type);
	RING_API_REGISTER("get_ekview_opengl",ring_get_ekview_opengl);
	RING_API_REGISTER("get_ekview_hscroll",ring_get_ekview_hscroll);
	RING_API_REGISTER("get_ekview_vscroll",ring_get_ekview_vscroll);
	RING_API_REGISTER("get_ekview_border",ring_get_ekview_border);
	RING_API_REGISTER("get_ekview_noerase",ring_get_ekview_noerase);
	RING_API_REGISTER("get_ekview_control",ring_get_ekview_control);
	RING_API_REGISTER("get_ektext_flag",ring_get_ektext_flag);
	RING_API_REGISTER("get_ektable_flag",ring_get_ektable_flag);
	RING_API_REGISTER("get_ektable_text",ring_get_ektable_text);
	RING_API_REGISTER("get_ektable_icon16",ring_get_ektable_icon16);
	RING_API_REGISTER("get_ektable_edit",ring_get_ektable_edit);
	RING_API_REGISTER("get_ektable_combo",ring_get_ektable_combo);
	RING_API_REGISTER("get_ektable_popup",ring_get_ektable_popup);
	RING_API_REGISTER("get_ektable_radio",ring_get_ektable_radio);
	RING_API_REGISTER("get_ektable_check",ring_get_ektable_check);
	RING_API_REGISTER("get_ektable_tooltip",ring_get_ektable_tooltip);
	RING_API_REGISTER("get_ektable_bgcolor",ring_get_ektable_bgcolor);
	RING_API_REGISTER("get_ektable_rowalt",ring_get_ektable_rowalt);
	RING_API_REGISTER("get_ektable_rowpresel",ring_get_ektable_rowpresel);
	RING_API_REGISTER("get_eksplit_flag",ring_get_eksplit_flag);
	RING_API_REGISTER("get_eksplit_vert",ring_get_eksplit_vert);
	RING_API_REGISTER("get_eksplit_horz",ring_get_eksplit_horz);
	RING_API_REGISTER("get_eksplit_type",ring_get_eksplit_type);
	RING_API_REGISTER("get_eksplit_prop",ring_get_eksplit_prop);
	RING_API_REGISTER("get_eksplit_left",ring_get_eksplit_left);
	RING_API_REGISTER("get_eksplit_right",ring_get_eksplit_right);
	RING_API_REGISTER("get_ekwindow_flag",ring_get_ekwindow_flag);
	RING_API_REGISTER("get_ekwindow_edge",ring_get_ekwindow_edge);
	RING_API_REGISTER("get_ekwindow_title",ring_get_ekwindow_title);
	RING_API_REGISTER("get_ekwindow_max",ring_get_ekwindow_max);
	RING_API_REGISTER("get_ekwindow_min",ring_get_ekwindow_min);
	RING_API_REGISTER("get_ekwindow_close",ring_get_ekwindow_close);
	RING_API_REGISTER("get_ekwindow_resize",ring_get_ekwindow_resize);
	RING_API_REGISTER("get_ekwindow_return",ring_get_ekwindow_return);
	RING_API_REGISTER("get_ekwindow_esc",ring_get_ekwindow_esc);
	RING_API_REGISTER("get_ekwindow_offscreen",ring_get_ekwindow_offscreen);
	RING_API_REGISTER("get_ekwindow_modal_nohide",ring_get_ekwindow_modal_nohide);
	RING_API_REGISTER("get_ekwindow_std",ring_get_ekwindow_std);
	RING_API_REGISTER("get_ekwindow_stdres",ring_get_ekwindow_stdres);
	RING_API_REGISTER("get_ekmenu_flag",ring_get_ekmenu_flag);
	RING_API_REGISTER("get_ekmenu_item",ring_get_ekmenu_item);
	RING_API_REGISTER("get_ekmenu_separator",ring_get_ekmenu_separator);
	RING_API_REGISTER("get_ekctrl_state_normal",ring_get_ekctrl_state_normal);
	RING_API_REGISTER("get_ekctrl_state_hot",ring_get_ekctrl_state_hot);
	RING_API_REGISTER("get_ekctrl_state_pressed",ring_get_ekctrl_state_pressed);
	RING_API_REGISTER("get_ekctrl_state_bknormal",ring_get_ekctrl_state_bknormal);
	RING_API_REGISTER("get_ekctrl_state_bkhot",ring_get_ekctrl_state_bkhot);
	RING_API_REGISTER("get_ekctrl_state_bkpressed",ring_get_ekctrl_state_bkpressed);
	RING_API_REGISTER("get_ekctrl_state_disabled",ring_get_ekctrl_state_disabled);
	RING_API_REGISTER("get_ekctrl_msel_no",ring_get_ekctrl_msel_no);
	RING_API_REGISTER("get_ekctrl_msel_single",ring_get_ekctrl_msel_single);
	RING_API_REGISTER("get_ekctrl_msel_burst",ring_get_ekctrl_msel_burst);
	RING_API_REGISTER("get_ekctrl_op_add",ring_get_ekctrl_op_add);
	RING_API_REGISTER("get_ekctrl_op_del",ring_get_ekctrl_op_del);
	RING_API_REGISTER("get_ekctrl_op_ins",ring_get_ekctrl_op_ins);
	RING_API_REGISTER("get_ekctrl_op_set",ring_get_ekctrl_op_set);
	RING_API_REGISTER("get_eksyscolor_darkmode",ring_get_eksyscolor_darkmode);
	RING_API_REGISTER("get_eksyscolor_label",ring_get_eksyscolor_label);
	RING_API_REGISTER("get_eksyscolor_view",ring_get_eksyscolor_view);
	RING_API_REGISTER("get_eksyscolor_line",ring_get_eksyscolor_line);
	RING_API_REGISTER("get_eksyscolor_link",ring_get_eksyscolor_link);
	RING_API_REGISTER("get_eksyscolor_border",ring_get_eksyscolor_border);
}
