/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: gui.hxx
 * https://nappgui.com/en/gui/gui.html
 *
 */

/* Graphics User Interface */

#ifndef __GUI_HXX__
#define __GUI_HXX__

#include <draw2d/guictx.hxx>
#include "gui.def"

typedef enum _gui_notif_t
{
    ekGUI_NOTIF_LANGUAGE = 1,
    ekGUI_NOTIF_WIN_DESTROY,
    ekGUI_NOTIF_MENU_DESTROY
} gui_notif_t;

typedef struct _guicontrol_t GuiControl;
typedef struct _label_t Label;
typedef struct _button_t Button;
typedef struct _popup_t PopUp;
typedef struct _edit_t Edit;
typedef struct _combo_t Combo;
typedef struct _listbox_t ListBox;
typedef struct _updown_t UpDown;
typedef struct _slider_t Slider;
typedef struct _progress_t Progress;
typedef struct _view_t View;
typedef struct _textview_t TextView;
typedef struct _imageview_t ImageView;
typedef struct _tableview_t TableView;
typedef struct _splitview_t SplitView;
typedef struct _layout_t Layout;
typedef struct _cell_t Cell;
typedef struct _panel_t Panel;
typedef struct _window_t Window;
typedef struct _menu_t Menu;
typedef struct _menu_item_t MenuItem;
typedef struct _focus_info_t FocusInfo;

typedef ResPack *(*FPtr_respack)(const char_t *locale);

struct _focus_info_t
{
    gui_tab_t action;
    GuiControl *next;
};

DeclSt(FPtr_respack);

#endif
