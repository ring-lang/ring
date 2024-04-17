/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: guictx.hxx
 *
 */

/*
   The GUI library knows how to compose and manage dynamic graphical
   user interfaces. But it does NOT know how to draw the elements (widgets)
   nor how to get the user events (keyboard, mouse). The drawing and event
   capture tasks are performed through a GuiCtx context object. Currently,
   NAppGUI implements a native context in OSGUI that links to Win32, Cocoa,
   and GTK. However, is opened the possibility of creating alternative contexts
   (for example OpenGL) and the use of them with Gui library to manage interfaces created
   with other technologies.

   The files:
   guictx.c
   guictx.h
   guictx.hxx

   are included in the Draw2D library and defines the basic types and functions
   needed to create a context.
   It is NOT documented, it is currently considered part of the final Gui library.

   The OSGUI library:

   Implements a native GUI context, using the core technologies:
   Win32, Cocoa and GTK.
   It is NOT documented, it is currently considered part of the final Gui library.

   The Gui library:

   It is the final library for compositing graphical user interfaces. It is documented
   and encapsulates the other two.
*/

/*
                                                    +-------+
                                             +----->| OSGui | Win32, Cocoa, Gtk
 +---------------+       +------------+      |      +-------+
 |  Gui library  |<----->|  GuiCtx    |------+        Native
 +---------------+       | (context)  |      |        context
     Compose &           +------------+      |
     management             Drawing &        |      +-----------+
                             events          +----->| OpenGLGui |
                                                    +-----------+
                                                       (Future)
*/

/* Gui rendering context */

#ifndef __GUICTX_HXX__
#define __GUICTX_HXX__

#include "draw2d.hxx"

typedef enum _gui_orient_t
{
    ekGUI_HORIZONTAL = 1,
    ekGUI_VERTICAL
} gui_orient_t;

typedef enum _gui_state_t
{
    ekGUI_OFF = 0,
    ekGUI_ON,
    ekGUI_MIXED
} gui_state_t;

typedef enum _gui_mouse_t
{
    ekGUI_MOUSE_LEFT = 1,
    ekGUI_MOUSE_RIGHT,
    ekGUI_MOUSE_MIDDLE
} gui_mouse_t;

typedef enum _gui_cursor_t
{
    ekGUI_CURSOR_ARROW = 1,
    ekGUI_CURSOR_HAND,
    ekGUI_CURSOR_IBEAM,
    ekGUI_CURSOR_CROSS,
    ekGUI_CURSOR_SIZEWE,
    ekGUI_CURSOR_SIZENS,
    ekGUI_CURSOR_USER
} gui_cursor_t;

typedef enum _gui_close_t
{
    ekGUI_CLOSE_ESC = 1,
    ekGUI_CLOSE_INTRO,
    ekGUI_CLOSE_BUTTON,
    ekGUI_CLOSE_DEACT
} gui_close_t;

typedef enum _gui_scale_t
{
    ekGUI_SCALE_AUTO = 1,
    ekGUI_SCALE_NONE,
    ekGUI_SCALE_ASPECT,
    ekGUI_SCALE_ASPECTDW
} gui_scale_t;

typedef enum _gui_scroll_t
{
    ekGUI_SCROLL_BEGIN = 1,
    ekGUI_SCROLL_END,
    ekGUI_SCROLL_STEP_LEFT,
    ekGUI_SCROLL_STEP_RIGHT,
    ekGUI_SCROLL_PAGE_LEFT,
    ekGUI_SCROLL_PAGE_RIGHT,
    ekGUI_SCROLL_THUMB
} gui_scroll_t;

typedef enum _gui_focus_t
{
    ekGUI_FOCUS_CHANGED = 1,
    ekGUI_FOCUS_KEEP,
    ekGUI_FOCUS_NO_NEXT,
    ekGUI_FOCUS_NO_RESIGN,
    ekGUI_FOCUS_NO_ACCEPT
} gui_focus_t;

typedef enum _gui_tab_t
{
    ekGUI_TAB_KEY = 1,
    ekGUI_TAB_BACKKEY,
    ekGUI_TAB_NEXT,
    ekGUI_TAB_PREV,
    ekGUI_TAB_MOVE,
    ekGUI_TAB_CLICK
} gui_tab_t;

typedef enum _gui_event_t
{
    ekGUI_EVENT_LABEL = 0x400,
    ekGUI_EVENT_BUTTON,
    ekGUI_EVENT_POPUP,
    ekGUI_EVENT_LISTBOX,
    ekGUI_EVENT_SLIDER,
    ekGUI_EVENT_UPDOWN,
    ekGUI_EVENT_TXTFILTER,
    ekGUI_EVENT_TXTCHANGE,
    ekGUI_EVENT_FOCUS_RESIGN,
    ekGUI_EVENT_FOCUS_ACCEPT,
    ekGUI_EVENT_FOCUS,
    ekGUI_EVENT_MENU,
    ekGUI_EVENT_DRAW,
    ekGUI_EVENT_OVERLAY,
    ekGUI_EVENT_RESIZE,
    ekGUI_EVENT_ENTER,
    ekGUI_EVENT_EXIT,
    ekGUI_EVENT_MOVED,
    ekGUI_EVENT_DOWN,
    ekGUI_EVENT_UP,
    ekGUI_EVENT_CLICK,
    ekGUI_EVENT_DRAG,
    ekGUI_EVENT_WHEEL,
    ekGUI_EVENT_KEYDOWN,
    ekGUI_EVENT_KEYUP,
    ekGUI_EVENT_SCROLL,
    ekGUI_EVENT_WND_MOVED,
    ekGUI_EVENT_WND_SIZING,
    ekGUI_EVENT_WND_SIZE,
    ekGUI_EVENT_WND_CLOSE,
    ekGUI_EVENT_COLOR,
    ekGUI_EVENT_THEME,
    ekGUI_EVENT_OBJCHANGE,

    ekGUI_EVENT_TBL_NROWS,
    ekGUI_EVENT_TBL_BEGIN,
    ekGUI_EVENT_TBL_END,
    ekGUI_EVENT_TBL_CELL,
    ekGUI_EVENT_TBL_SEL,
    ekGUI_EVENT_TBL_HEADCLICK,
    ekGUI_EVENT_TBL_ROWCLICK,
    ekGUI_EVENT_IDLE
} gui_event_t;

typedef enum _gui_type_t
{
    /* Basic controls */
    ekGUI_TYPE_LABEL = 0,
    ekGUI_TYPE_BUTTON = 1,
    ekGUI_TYPE_POPUP = 2,
    ekGUI_TYPE_EDITBOX = 3,
    ekGUI_TYPE_COMBOBOX = 4,
    ekGUI_TYPE_SLIDER = 5,
    ekGUI_TYPE_UPDOWN = 6,
    ekGUI_TYPE_PROGRESS = 7,

    /* View Controls */
    ekGUI_TYPE_TEXTVIEW = 8,
    ekGUI_TYPE_TABLEVIEW = 9,
    ekGUI_TYPE_TREEVIEW = 10,
    ekGUI_TYPE_BOXVIEW = 11,
    ekGUI_TYPE_SPLITVIEW = 12,
    ekGUI_TYPE_CUSTOMVIEW = 13,

    /* Others */
    ekGUI_TYPE_PANEL = 14,
    ekGUI_TYPE_LINE = 15,
    ekGUI_TYPE_HEADER = 16,

    /* Non-Components */
    ekGUI_TYPE_WINDOW = 17,
    ekGUI_TYPE_TOOLBAR = 18
} gui_type_t;

#define GUI_CONTEXT_NUM_COMPONENTS 17

typedef enum _gui_size_t
{
    ekGUI_SIZE_MINI = 1,
    ekGUI_SIZE_SMALL,
    ekGUI_SIZE_REGULAR
} gui_size_t;

typedef enum _gui_role_t
{
    ekGUI_ROLE_MAIN = 0,
    ekGUI_ROLE_OVERLAY = 1,
    ekGUI_ROLE_MODAL = 2,
    ekGUI_ROLE_MANAGED = 3
} gui_role_t;

typedef enum _gui_prop_t
{
    ekGUI_PROP_RESIZE = 0,
    ekGUI_PROP_CHILDREN
} gui_prop_t;

typedef enum _gui_text_t
{
    ekGUI_TEXT_FAMILY = 0,
    ekGUI_TEXT_UNITS,
    ekGUI_TEXT_SIZE,
    ekGUI_TEXT_STYLE,
    ekGUI_TEXT_COLOR,
    ekGUI_TEXT_BGCOLOR,
    ekGUI_TEXT_PGCOLOR,
    ekGUI_TEXT_PARALIGN,
    ekGUI_TEXT_LSPACING,
    ekGUI_TEXT_BFPARSPACE,
    ekGUI_TEXT_AFPARSPACE,
    ekGUI_TEXT_SELECT,
    ekGUI_TEXT_SCROLL
} gui_text_t;

typedef enum _clipboard_t
{
    ekCLIPBOARD_COPY,
    ekCLIPBOARD_CUT,
    ekCLIPBOARD_PASTE
} clipboard_t;

typedef enum _label_flag_t
{
    ekLABEL_FLAG = 0,
    ekLABEL_SINGLE = 0,
    ekLABEL_MULTI = 1,
    ekLABEL_TYPE = 1
} label_flag_t;

typedef enum _button_flag_t
{
    ekBUTTON_FLAG = 0,
    ekBUTTON_PUSH = 0,
    ekBUTTON_CHECK2 = 1,
    ekBUTTON_CHECK3 = 2,
    ekBUTTON_RADIO = 3,
    ekBUTTON_FLAT = 4,
    ekBUTTON_FLATGLE = 5,
    ekBUTTON_HEADER = 6,
    ekBUTTON_TYPE = 7
} button_flag_t;

typedef enum _popup_flag_t
{
    ekPOPUP_FLAG = 0
} popup_flag_t;

typedef enum _edit_flag_t
{
    ekEDIT_FLAG = 0,
    ekEDIT_SINGLE = 0,
    ekEDIT_MULTI = 1,
    ekEDIT_TYPE = 1,
    ekEDIT_AUTOSEL = 4
} edit_flag_t;

typedef enum _combo_flag_t
{
    ekCOMBO_FLAG = 0
} combo_flag_t;

typedef enum _slider_flag_t
{
    ekSLIDER_FLAG = 0,
    ekSLIDER_HORZ = 0,
    ekSLIDER_VERT = 1,
    ekSLIDER_TYPE = 1
} slider_flag_t;

typedef enum _updown_flag_t
{
    ekUPDOWN_FLAG = 0
} updown_flag_t;

typedef enum _progress_flag_t
{
    ekPROGRESS_FLAG = 0,
    ekPROGRESS_HORZ = 0,
    ekPROGRESS_VERT = 1,
    ekPROGRESS_TYPE = 1
} progress_flag_t;

typedef enum _view_flag_t
{
    ekVIEW_OPENGL = 0x1,
    ekVIEW_HSCROLL = 0x2,
    ekVIEW_VSCROLL = 0x4,
    ekVIEW_BORDER = 0x8,
    ekVIEW_NOERASE = 0x20,
    ekVIEW_CONTROL = 0x40
} view_flag_t;

typedef enum _text_flag_t
{
    ekTEXT_FLAG = 0
} text_flag_t;

typedef enum _table_flag_t
{
    ekTABLE_FLAG = 0,
    ekTABLE_TEXT = 0x1,
    ekTABLE_ICON16 = 0x2,
    ekTABLE_EDIT = 0x4,
    ekTABLE_COMBO = 0x8,
    ekTABLE_POPUP = 0x10,
    ekTABLE_RADIO = 0x20,
    ekTABLE_CHECK = 0x40,
    ekTABLE_TOOLTIP = 0x80,
    ekTABLE_BGCOLOR = 0x100,
    ekTABLE_ROWALT = 0x200,
    ekTABLE_ROWPRESEL = 0x400
} table_flag_t;

typedef enum _split_flag_t
{
    ekSPLIT_FLAG = 0,
    ekSPLIT_VERT = 0,
    ekSPLIT_HORZ = 1,
    ekSPLIT_TYPE = 1,
    ekSPLIT_PROP = 2,
    ekSPLIT_LEFT = 3,
    ekSPLIT_RIGHT = 4
} split_flag_t;

typedef enum _window_flag_t
{
    ekWINDOW_FLAG = 0,
    ekWINDOW_EDGE = 1 << 0,
    ekWINDOW_TITLE = 1 << 1,
    ekWINDOW_MAX = 1 << 2,
    ekWINDOW_MIN = 1 << 3,
    ekWINDOW_CLOSE = 1 << 4,
    ekWINDOW_RESIZE = 1 << 5,
    ekWINDOW_RETURN = 1 << 6,
    ekWINDOW_ESC = 1 << 7,
    ekWINDOW_OFFSCREEN = 1 << 8,
    ekWINDOW_MODAL_NOHIDE = 1 << 9,
    ekWINDOW_STD = ekWINDOW_TITLE | ekWINDOW_MIN | ekWINDOW_CLOSE,
    ekWINDOW_STDRES = ekWINDOW_STD | ekWINDOW_MAX | ekWINDOW_RESIZE
} window_flag_t;

typedef enum _menu_flag_t
{
    ekMENU_FLAG = 0,
    ekMENU_ITEM,
    ekMENU_SEPARATOR
} menu_flag_t;

typedef enum _ctrl_state_t
{
    ekCTRL_STATE_NORMAL,
    ekCTRL_STATE_HOT,
    ekCTRL_STATE_PRESSED,
    ekCTRL_STATE_BKNORMAL,
    ekCTRL_STATE_BKHOT,
    ekCTRL_STATE_BKPRESSED,
    ekCTRL_STATE_DISABLED
} ctrl_state_t;

typedef enum _ctrl_msel_t
{
    ekCTRL_MSEL_NO,
    ekCTRL_MSEL_SINGLE,
    ekCTRL_MSEL_BURST
} ctrl_msel_t;

typedef enum _ctrl_op_t
{
    ekCTRL_OP_ADD = 1,
    ekCTRL_OP_DEL,
    ekCTRL_OP_INS,
    ekCTRL_OP_SET
} ctrl_op_t;

typedef enum _syscolor_t
{
    ekSYSCOLOR_DARKMODE = 0,
    ekSYSCOLOR_LABEL,
    ekSYSCOLOR_VIEW,
    ekSYSCOLOR_LINE,
    ekSYSCOLOR_LINK,
    ekSYSCOLOR_BORDER
} syscolor_t;

typedef struct _ccursor_t Cursor;
typedef struct _guictx_t GuiCtx;
typedef struct _evbutton_t EvButton;
typedef struct _evslider_t EvSlider;
typedef struct _evtext_t EvText;
typedef struct _evtextfilter_t EvTextFilter;
typedef struct _evdraw_t EvDraw;
typedef struct _evmouse_t EvMouse;
typedef struct _evwheel_t EvWheel;
typedef struct _evkey_t EvKey;
typedef struct _evpos_t EvPos;
typedef struct _evsize_t EvSize;
typedef struct _evwinclose_t EvWinClose;
typedef struct _evmenu_t EvMenu;
typedef struct _evscroll_t EvScroll;
typedef struct _evtbpos_t EvTbPos;
typedef struct _evtbrow_t EvTbRow;
typedef struct _evtbrect_t EvTbRect;
typedef struct _evtbsel_t EvTbSel;
typedef struct _evtbcell_t EvTbCell;

#define label_get_type(flags) ((flags)&ekLABEL_TYPE)
#define button_get_type(flags) ((flags)&ekBUTTON_TYPE)
#define edit_get_type(flags) ((flags)&ekEDIT_TYPE)
#define slider_get_type(flags) ((flags)&ekSLIDER_TYPE)
#define progress_get_type(flags) ((flags)&ekPROGRESS_TYPE)
#define split_get_type(flags) ((flags)&ekSPLIT_TYPE)

typedef void *(*FPtr_gctx_create)(const uint32_t flags);
#define FUNC_CHECK_GCTX_CREATE(func, type) \
    (void)((type * (*)(const uint32_t)) func == func)

typedef void *(*FPtr_gctx_create2)(void *);
#define FUNC_CHECK_GCTX_CREATE2(func, type) \
    (void)((type * (*)(void *)) func == func)

typedef void (*FPtr_gctx_destroy)(void **item);
#define FUNC_CHECK_GCTX_DESTROY(func, type) \
    (void)((void (*)(type **))func == func)

typedef void (*FPtr_gctx_set_text)(void *item, const char_t *text);
#define FUNC_CHECK_GCTX_SET_TEXT(func, type) \
    (void)((void (*)(type *, const char_t *))func == func)

typedef void (*FPtr_gctx_set_ptr)(void *item, void *ptr);
#define FUNC_CHECK_GCTX_SET_PTR(func, type, ptr_type) \
    (void)((void (*)(type *, ptr_type *))func == func)

typedef uint32_t (*FPtr_gctx_set_ptr2)(void *item, void *ptr);
#define FUNC_CHECK_GCTX_SET_PTR2(func, type, ptr_type) \
    (void)((uint32_t(*)(type *, ptr_type *))func == func)

typedef enum_t (*FPtr_gctx_set_ptr3)(void *item, void *ptr);
#define FUNC_CHECK_GCTX_SET_PTR3(func, type, ptr_type, enum_type) \
    (void)((enum_type(*)(type *, ptr_type *))func == func)

typedef void (*FPtr_gctx_set_cptr)(void *item, const void *ptr);
#define FUNC_CHECK_GCTX_SET_CPTR(func, type, ptr_type) \
    (void)((void (*)(type *, const ptr_type *))func == func)

typedef void (*FPtr_gctx_set_listener)(void *item, Listener *listener);
#define FUNC_CHECK_GCTX_SET_LISTENER(func, type) \
    (void)((void (*)(type *, Listener *))func == func)

typedef void (*FPtr_gctx_set_bool)(void *item, const bool_t value);
#define FUNC_CHECK_GCTX_SET_BOOL(func, type) \
    (void)((void (*)(type *, const bool_t))func == func)

typedef void (*FPtr_gctx_set_uint32)(void *item, const uint32_t value);
#define FUNC_CHECK_GCTX_SET_UINT32(func, type) \
    (void)((void (*)(type *, const uint32_t))func == func)

typedef void (*FPtr_gctx_set_real32)(void *item, const real32_t value);
#define FUNC_CHECK_GCTX_SET_REAL32(func, type) \
    (void)((void (*)(type *, const real32_t))func == func)

typedef void (*FPtr_gctx_set_enum)(void *item, const enum_t value);
#define FUNC_CHECK_GCTX_SET_ENUM(func, type, type_enum) \
    (void)((void (*)(type *, const type_enum))func == func)

typedef enum_t (*FPtr_gctx_set_enum2)(void *item, const bool_t);
#define FUNC_CHECK_GCTX_SET_ENUM2(func, type, type_enum) \
    (void)((type_enum(*)(type *, const bool_t))func == func)

typedef void (*FPtr_gctx_set_elem)(void *item, const ctrl_op_t op, const uint32_t index, const char_t *text, const Image *data);
#define FUNC_CHECK_GCTX_SET_ELEM(func, type) \
    (void)((void (*)(type *, const ctrl_op_t, const uint32_t, const char_t *, const Image *))func == func)

typedef void (*FPtr_gctx_set_property)(void *item, const enum_t prop, const void *value);
#define FUNC_CHECK_GCTX_SET_PROPERTY(func, type, prop_type) \
    (void)((void (*)(type *, const prop_type, const void *))func == func)

typedef void (*FPtr_gctx_set_key)(void *item, const uint32_t key, const uint32_t modifiers);
#define FUNC_CHECK_GCTX_SET_KEY(func, type) \
    (void)((void (*)(type *, const uint32_t, const uint32_t))func == func)

typedef void (*FPtr_gctx_set_hotkey)(void *item, const vkey_t, const uint32_t, Listener *);
#define FUNC_CHECK_GCTX_SET_HOTKEY(func, type) \
    (void)((void (*)(type *, const vkey_t, const uint32_t, Listener *))func == func)

typedef void (*FPtr_gctx_set_area)(void *item, void *obj, const color_t bgcolor, const color_t skcolor, const real32_t x, const real32_t y, const real32_t width, const real32_t height);
#define FUNC_CHECK_GCTX_SET_AREA(func, type) \
    (void)((void (*)(type *, void *, const color_t, const color_t, const real32_t, const real32_t, const real32_t, const real32_t))func == func)

typedef void (*FPtr_gctx_set2_bool)(void *item, const bool_t value1, const bool_t value2);
#define FUNC_CHECK_GCTX_SET2_BOOL(func, type) \
    (void)((void (*)(type *, const bool_t, const bool_t))func == func)

typedef void (*FPtr_gctx_set2_int32)(void *item, const int32_t value1, const int32_t value2);
#define FUNC_CHECK_GCTX_SET2_INT32(func, type) \
    (void)((void (*)(type *, const int32_t, const int32_t))func == func)

typedef void (*FPtr_gctx_set2_real32)(void *item, const real32_t value1, const real32_t value2);
#define FUNC_CHECK_GCTX_SET2_REAL32(func, type) \
    (void)((void (*)(type *, const real32_t, const real32_t))func == func)

typedef void (*FPtr_gctx_set2_real64)(void *item, const real64_t value1, const real64_t value2);
#define FUNC_CHECK_GCTX_SET2_REAL64(func, type) \
    (void)((void (*)(type *, const real64_t, const real64_t))func == func)

typedef void (*FPtr_gctx_set4_real32)(void *item, const real32_t value1, const real32_t value2, const real32_t value3, const real32_t value4);
#define FUNC_CHECK_GCTX_SET4_REAL32(func, type) \
    (void)((void (*)(type *, const real32_t, const real32_t, const real32_t, const real32_t))func == func)

typedef const char_t *(*FPtr_gctx_get_text)(const void *item);
#define FUNC_CHECK_GCTX_GET_TEXT(func, type) \
    (void)((const char_t *(*)(const type *))func == func)

typedef void *(*FPtr_gctx_get_ptr)(const void *item);
#define FUNC_CHECK_GCTX_GET_PTR(func, type, ptr_type) \
    (void)((ptr_type * (*)(const type *)) func == func)

typedef uint32_t (*FPtr_gctx_get_uint32)(const void *item);
#define FUNC_CHECK_GCTX_GET_UINT32(func, type) \
    (void)((uint32_t(*)(const type *))func == func)

typedef real32_t (*FPtr_gctx_get_real32)(const void *item);
#define FUNC_CHECK_GCTX_GET_REAL32(func, type) \
    (void)((real32_t(*)(const type *))func == func)

typedef enum_t (*FPtr_gctx_get_enum)(const void *item);
#define FUNC_CHECK_GCTX_GET_ENUM(func, type, type_enum) \
    (void)((type_enum(*)(const type *))func == func)

typedef enum_t (*FPtr_gctx_get_enum2)(const void *item, const enum_t);
#define FUNC_CHECK_GCTX_GET_ENUM2(func, type, type_enum, type_enum2) \
    (void)((type_enum(*)(const type *, const type_enum2))func == func)

typedef enum_t (*FPtr_gctx_get_enum3)(const void *item, void **ptr);
#define FUNC_CHECK_GCTX_GET_ENUM3(func, type, type_enum) \
    (void)((type_enum(*)(const type *, void **ptr))func == func)

typedef real32_t (*FPtr_gctx_get_real32e)(const void *item, const enum_t value);
#define FUNC_CHECK_GCTX_GET_REAL32E(func, type, type_enum) \
    (void)((real32_t(*)(const type *, const type_enum))func == func)

typedef void (*FPtr_gctx_get2_real32)(const void *item, real32_t *value1, real32_t *value2);
#define FUNC_CHECK_GCTX_GET2_REAL32(func, type) \
    (void)((void (*)(const type *, real32_t *, real32_t *))func == func)

typedef void (*FPtr_gctx_get_indexed)(const uint32_t, void *);
#define FUNC_CHECK_GCTX_GET_INDEXED(func) \
    (void)((void (*)(const uint32_t, void *))func == func)

typedef void (*FPtr_gctx_call)(void *item);
#define FUNC_CHECK_GCTX_CALL(func, type) \
    (void)((void (*)(type *))func == func)

typedef void (*FPtr_gctx_bounds1)(const void *item, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height);
#define FUNC_CHECK_GCTX_BOUNDS1(func, type) \
    (void)((void (*)(const type *, const char_t *, const real32_t, real32_t *, real32_t *))func == func)

typedef void (*FPtr_gctx_bounds2)(const void *item, const char_t *text, const real32_t refwidth, const real32_t refheight, real32_t *width, real32_t *height);
#define FUNC_CHECK_GCTX_BOUNDS2(func, type) \
    (void)((void (*)(const type *, const char_t *, const real32_t, const real32_t, real32_t *, real32_t *))func == func)

typedef void (*FPtr_gctx_bounds3)(const void *item, const char_t *text, real32_t *width, real32_t *height);
#define FUNC_CHECK_GCTX_BOUNDS3(func, type) \
    (void)((void (*)(const type *, const char_t *, real32_t *, real32_t *))func == func)

typedef void (*FPtr_gctx_bounds4)(const void *item, const real32_t refwidth, const uint32_t lines, real32_t *width, real32_t *height);
#define FUNC_CHECK_GCTX_BOUNDS4(func, type) \
    (void)((void (*)(const type *, const real32_t, const uint32_t, real32_t *, real32_t *))func == func)

typedef void (*FPtr_gctx_bounds5)(const void *item, const real32_t refwidth, real32_t *width, real32_t *height);
#define FUNC_CHECK_GCTX_BOUNDS5(func, type) \
    (void)((void (*)(const type *, const real32_t, real32_t *, real32_t *))func == func)

typedef void (*FPtr_gctx_bounds6)(const void *item, const real32_t length, const gui_size_t size, real32_t *width, real32_t *height);
#define FUNC_CHECK_GCTX_BOUNDS6(func, type) \
    (void)((void (*)(const type *, const real32_t, const gui_size_t, real32_t *, real32_t *))func == func)

typedef void (*FPtr_gctx_tickmarks)(void *item, const uint32_t num_tickmarks, const bool_t tickmarks_at_left_top);
#define FUNC_CHECK_GCTX_TICKMARKS(func, type) \
    (void)((void (*)(type *, const uint32_t, const bool_t))func == func)

typedef void (*FPtr_gctx_menu)(void *item, void *window, const real32_t x, const real32_t y);
#define FUNC_CHECK_GCTX_MENU(func, type, window_type) \
    (void)((void (*)(type *, window_type *, const real32_t, const real32_t))func == func)

typedef const char_t *(*FPtr_gctx_win_file)(void *parent, const char_t **ftypes, const uint32_t size, const char_t *start_dir, const bool_t open);
#define FUNC_CHECK_GCTX_WIN_FILE(func, type) \
    (void)((const char_t *(*)(type *, const char_t **, const uint32_t, const char_t *, const bool_t))func == func)

typedef void (*FPtr_gctx_win_color)(void *parent, const char_t *title, const real32_t x, const real32_t y, const align_t halign, const align_t valign, color_t current, color_t *colors, const uint32_t n, Listener *OnChange);
#define FUNC_CHECK_GCTX_WIN_COLOR(func, type) \
    (void)((void (*)(type *, const char_t *, const real32_t, const real32_t, const align_t, const align_t, const color_t, color_t *, const uint32_t, Listener *))func == func)

typedef Cursor *(*FPtr_gctx_cursor)(const enum_t, const Image *, const real32_t, const real32_t);
#define FUNC_CHECK_GCTX_CURSOR(func) \
    (void)((Cursor * (*)(const gui_cursor_t, const Image *, const real32_t, const real32_t)) func == func)

typedef void (*FPtr_gctx_draw_rect)(void *, const int32_t, const int32_t, const uint32_t, const uint32_t, const enum_t);
#define FUNC_CHECK_GCTX_DRAW_RECT(func, type, enum_type) \
    (void)((void (*)(type *, const int32_t, const int32_t, const uint32_t, const uint32_t, const enum_type))func == func)

typedef void (*FPtr_gctx_draw_line)(void *, const int32_t, const int32_t, const int32_t, const int32_t);
#define FUNC_CHECK_GCTX_DRAW_LINE(func, type) \
    (void)((void (*)(type *, const int32_t, const int32_t, const int32_t, const int32_t))func == func)

typedef void (*FPtr_gctx_draw_text)(void *, const char_t *, const int32_t, const int32_t, const enum_t);
#define FUNC_CHECK_GCTX_DRAW_TEXT(func, type, enum_type) \
    (void)((void (*)(type *, const char_t *, const int32_t, const int32_t, const enum_type))func == func)

typedef void (*FPtr_gctx_draw_image)(void *, const Image *, const int32_t, const int32_t, const enum_t);
#define FUNC_CHECK_GCTX_DRAW_IMAGE(func, type, enum_type) \
    (void)((void (*)(type *, const Image *, const int32_t, const int32_t, const enum_type))func == func)

typedef void (*FPtr_gctx_clipboard)(void *, const clipboard_t);
#define FUNC_CHECK_GCTX_CLIPBOARD(func, type) \
    (void)((void (*)(type *, const clipboard_t))func == func)

struct _guictx_t
{
    uint32_t retain_count;

    /*! <Commons> */
    FPtr_gctx_create func_create[GUI_CONTEXT_NUM_COMPONENTS];
    FPtr_gctx_destroy func_destroy[GUI_CONTEXT_NUM_COMPONENTS];
    FPtr_gctx_set_text func_set_tooltip[GUI_CONTEXT_NUM_COMPONENTS];
    FPtr_gctx_set_ptr func_attach_to_panel[GUI_CONTEXT_NUM_COMPONENTS];
    FPtr_gctx_set_ptr func_detach_from_panel[GUI_CONTEXT_NUM_COMPONENTS];
    FPtr_gctx_set_bool func_set_visible[GUI_CONTEXT_NUM_COMPONENTS];
    FPtr_gctx_set_bool func_set_enabled[GUI_CONTEXT_NUM_COMPONENTS];
    FPtr_gctx_get2_real32 func_get_size[GUI_CONTEXT_NUM_COMPONENTS];
    FPtr_gctx_get2_real32 func_get_origin[GUI_CONTEXT_NUM_COMPONENTS];
    FPtr_gctx_set4_real32 func_set_frame[GUI_CONTEXT_NUM_COMPONENTS];

    /*! <Label> */
    FPtr_gctx_set_listener func_label_OnClick;
    FPtr_gctx_set_listener func_label_OnMouseEnter;
    FPtr_gctx_set_listener func_label_OnMouseExit;
    FPtr_gctx_set_text func_label_set_text;
    FPtr_gctx_set_cptr func_label_set_font;
    FPtr_gctx_set_enum func_label_set_align;
    FPtr_gctx_set_enum func_label_set_ellipsis;
    FPtr_gctx_set_uint32 func_label_set_text_color;
    FPtr_gctx_set_uint32 func_label_set_bg_color;
    FPtr_gctx_bounds1 func_label_bounds;

    /*! <Button> */
    FPtr_gctx_set_listener func_button_OnClick;
    FPtr_gctx_set_text func_button_set_text;
    FPtr_gctx_set_cptr func_button_set_font;
    FPtr_gctx_set_enum func_button_set_align;
    FPtr_gctx_set_cptr func_button_set_image;
    FPtr_gctx_set_enum func_button_set_state;
    FPtr_gctx_get_enum func_button_get_state;
    FPtr_gctx_set_real32 func_button_set_vpadding;
    FPtr_gctx_bounds2 func_button_bounds;

    /*! <PopUp> */
    FPtr_gctx_set_listener func_popup_OnChange;
    FPtr_gctx_set_elem func_popup_set_elem;
    FPtr_gctx_set_cptr func_popup_set_font;
    FPtr_gctx_set_uint32 func_popup_list_height;
    FPtr_gctx_set_uint32 func_popup_set_selected;
    FPtr_gctx_get_uint32 func_popup_get_selected;
    FPtr_gctx_bounds3 func_popup_bounds;

    /*! <Edit> */
    FPtr_gctx_set_listener func_edit_OnFilter;
    FPtr_gctx_set_listener func_edit_OnChange;
    FPtr_gctx_set_listener func_edit_OnFocus;
    FPtr_gctx_set_text func_edit_set_text;
    FPtr_gctx_set_cptr func_edit_set_font;
    FPtr_gctx_set_enum func_edit_set_align;
    FPtr_gctx_set_bool func_edit_set_passmode;
    FPtr_gctx_set_bool func_edit_set_editable;
    FPtr_gctx_set_bool func_edit_set_autoselect;
    FPtr_gctx_set2_int32 func_edit_set_select;
    FPtr_gctx_set_uint32 func_edit_set_text_color;
    FPtr_gctx_set_uint32 func_edit_set_bg_color;
    FPtr_gctx_set_real32 func_edit_set_vpadding;
    FPtr_gctx_bounds4 func_edit_bounds;
    FPtr_gctx_clipboard func_edit_clipboard;

    /*! <Combo> */
    FPtr_gctx_set_listener func_combo_OnFilter;
    FPtr_gctx_set_listener func_combo_OnChange;
    FPtr_gctx_set_listener func_combo_OnFocus;
    FPtr_gctx_set_listener func_combo_OnSelect;
    FPtr_gctx_set_text func_combo_set_text;
    FPtr_gctx_set_cptr func_combo_set_font;
    FPtr_gctx_set_enum func_combo_set_align;
    FPtr_gctx_set_bool func_combo_set_passmode;
    FPtr_gctx_set_uint32 func_combo_set_text_color;
    FPtr_gctx_set_uint32 func_combo_set_bg_color;
    FPtr_gctx_set_elem func_combo_set_elem;
    FPtr_gctx_set_uint32 func_combo_set_selected;
    FPtr_gctx_get_uint32 func_combo_get_selected;
    FPtr_gctx_bounds5 func_combo_bounds;

    /*! <Slider> */
    FPtr_gctx_set_listener func_slider_OnMoved;
    FPtr_gctx_tickmarks func_slider_set_tickmarks;
    FPtr_gctx_get_real32 func_slider_get_position;
    FPtr_gctx_set_real32 func_slider_set_position;
    FPtr_gctx_bounds6 func_slider_bounds;

    /* UpDown */
    FPtr_gctx_set_listener func_updown_OnClick;

    /*! <Progress> */
    FPtr_gctx_set_real32 func_progress_set_position;
    FPtr_gctx_get_real32e func_progress_get_thickness;

    /*! <Text view> */
    FPtr_gctx_set_listener func_text_OnFilter;
    FPtr_gctx_set_listener func_text_OnFocus;
    FPtr_gctx_set_text func_text_insert_text;
    FPtr_gctx_set_text func_text_set_text;
    FPtr_gctx_set_ptr func_text_set_rtf;
    FPtr_gctx_set_property func_text_set_prop;
    FPtr_gctx_set_bool func_text_set_editable;
    FPtr_gctx_get_text func_text_get_text;
    FPtr_gctx_set2_bool func_text_scroller_visible;
    FPtr_gctx_call func_text_set_need_display;
    FPtr_gctx_clipboard func_text_clipboard;

    /*! <Split view> */
    FPtr_gctx_set_ptr func_split_attach_control;
    FPtr_gctx_set_ptr func_split_detach_control;
    FPtr_gctx_set_listener func_split_OnDrag;
    FPtr_gctx_set4_real32 func_split_track_area;

    /*! <View> */
    FPtr_gctx_set_listener func_view_OnDraw;
    FPtr_gctx_set_listener func_view_OnOverlay;
    FPtr_gctx_set_listener func_view_OnEnter;
    FPtr_gctx_set_listener func_view_OnExit;
    FPtr_gctx_set_listener func_view_OnMoved;
    FPtr_gctx_set_listener func_view_OnDown;
    FPtr_gctx_set_listener func_view_OnUp;
    FPtr_gctx_set_listener func_view_OnClick;
    FPtr_gctx_set_listener func_view_OnDrag;
    FPtr_gctx_set_listener func_view_OnWheel;
    FPtr_gctx_set_listener func_view_OnKeyDown;
    FPtr_gctx_set_listener func_view_OnKeyUp;
    FPtr_gctx_set_listener func_view_OnFocus;
    FPtr_gctx_set_listener func_view_OnResignFocus;
    FPtr_gctx_set_listener func_view_OnAcceptFocus;
    FPtr_gctx_set_listener func_view_OnScroll;
    FPtr_gctx_set_listener func_view_OnTouchTap;
    FPtr_gctx_set_listener func_view_OnTouchStartDrag;
    FPtr_gctx_set_listener func_view_OnTouchDragging;
    FPtr_gctx_set_listener func_view_OnTouchEndDrag;
    FPtr_gctx_set_listener func_view_OnTouchStartPinch;
    FPtr_gctx_set_listener func_view_OnTouchPinching;
    FPtr_gctx_set_listener func_view_OnTouchEndPinch;
    FPtr_gctx_set2_real32 func_view_scroll;
    FPtr_gctx_get2_real32 func_view_scroll_get;
    FPtr_gctx_get2_real32 func_view_scroller_size;
    FPtr_gctx_set2_bool func_view_scroller_visible;
    FPtr_gctx_set4_real32 func_view_content_size;
    FPtr_gctx_get_real32 func_view_scale_factor;
    FPtr_gctx_call func_view_set_need_display;
    FPtr_gctx_set_bool func_view_set_drawable;
    FPtr_gctx_get_ptr func_view_get_native_view;

    /*! <Panels> */
    FPtr_gctx_set_area func_panel_area;
    FPtr_gctx_get2_real32 func_panel_scroller_size;
    FPtr_gctx_set4_real32 func_panel_content_size;
    FPtr_gctx_call func_panel_set_need_display;

    /*! <Menus> */
    FPtr_gctx_create func_menu_create;
    FPtr_gctx_destroy func_menu_destroy;
    FPtr_gctx_set_ptr func_attach_menuitem_to_menu;
    FPtr_gctx_set_ptr func_detach_menuitem_from_menu;
    FPtr_gctx_menu func_menu_launch_popup;
    FPtr_gctx_call func_menu_hide_popup;

    /*! <MenuItems> */
    FPtr_gctx_create func_menuitem_create;
    FPtr_gctx_destroy func_menuitem_destroy;
    FPtr_gctx_set_listener func_menuitem_OnClick;
    FPtr_gctx_set_bool func_menuitem_set_enabled;
    FPtr_gctx_set_bool func_menuitem_set_visible;
    FPtr_gctx_set_text func_menuitem_set_text;
    FPtr_gctx_set_cptr func_menuitem_set_image;
    FPtr_gctx_set_key func_menuitem_set_key_equivalent;
    FPtr_gctx_set_enum func_menuitem_set_state;
    FPtr_gctx_set_ptr func_attach_menu_to_menu_item;
    FPtr_gctx_set_ptr func_detach_menu_from_menu_item;

    /*! <Windows> */
    FPtr_gctx_create func_window_create;
    FPtr_gctx_create2 func_window_managed;
    FPtr_gctx_destroy func_window_destroy;
    FPtr_gctx_set_listener func_window_OnMoved;
    FPtr_gctx_set_listener func_window_OnResize;
    FPtr_gctx_set_listener func_window_OnClose;
    FPtr_gctx_set_text func_window_set_title;
    FPtr_gctx_set_bool func_window_set_edited;
    FPtr_gctx_set_bool func_window_set_movable;
    FPtr_gctx_set_ptr func_window_set_z_order;
    FPtr_gctx_set_real32 func_window_set_alpha;
    FPtr_gctx_set_bool func_window_enable_mouse_events;
    FPtr_gctx_set_hotkey func_window_hotkey;
    FPtr_gctx_set_ptr func_window_set_taborder;
    FPtr_gctx_set_bool func_window_tabcycle;
    FPtr_gctx_set_enum2 func_window_tabstop;
    FPtr_gctx_set_ptr3 func_window_set_focus;
    FPtr_gctx_get_ptr func_window_get_focus;
    FPtr_gctx_get_enum3 func_window_info_focus;
    FPtr_gctx_set_ptr func_attach_main_panel_to_window;
    FPtr_gctx_set_ptr func_detach_main_panel_from_window;
    FPtr_gctx_set_ptr func_attach_window_to_window;
    FPtr_gctx_set_ptr func_detach_window_from_window;
    FPtr_gctx_set_ptr func_window_launch;
    FPtr_gctx_set_ptr func_window_hide;
    FPtr_gctx_set_ptr2 func_window_launch_modal;
    FPtr_gctx_set_uint32 func_window_stop_modal;
    FPtr_gctx_get2_real32 func_window_get_origin_in_screen_coordinates;
    FPtr_gctx_set2_real32 func_window_set_origin_in_screen_coordinates;
    FPtr_gctx_get2_real32 func_window_get_size;
    FPtr_gctx_set2_real32 func_window_set_size;
    FPtr_gctx_set_ptr func_window_set_default_pushbutton;
    FPtr_gctx_set_ptr func_window_set_cursor;
    FPtr_gctx_set_property func_window_set_property;

    /*! <Common Windows> */
    FPtr_gctx_win_file func_comwin_file;
    FPtr_gctx_win_color func_comwin_color;

    /*! <Globals> */
    FPtr_gctx_get_enum func_globals_device;
    FPtr_gctx_get_enum func_globals_color;
    FPtr_gctx_get2_real32 func_globals_resolution;
    FPtr_gctx_get2_real32 func_globals_mouse_position;
    FPtr_gctx_cursor func_globals_cursor;
    FPtr_gctx_destroy func_globals_cursor_destroy;
    FPtr_gctx_get_indexed func_globals_value;
    FPtr_gctx_set2_real64 func_globals_transitions;
    FPtr_gctx_set_listener func_globals_OnIdle;

    /*! <Draw Custom Controls> */
    FPtr_gctx_get_ptr func_drawctrl_font;
    FPtr_gctx_get_uint32 func_drawctrl_row_padding;
    FPtr_gctx_get_uint32 func_drawctrl_check_width;
    FPtr_gctx_get_uint32 func_drawctrl_check_height;
    FPtr_gctx_get_enum2 func_drawctrl_multisel;
    FPtr_gctx_draw_rect func_drawctrl_clear;
    FPtr_gctx_draw_rect func_drawctrl_header;
    FPtr_gctx_draw_rect func_drawctrl_indicator;
    FPtr_gctx_draw_rect func_drawctrl_fill;
    FPtr_gctx_draw_rect func_drawctrl_focus;
    FPtr_gctx_draw_line func_drawctrl_line;
    FPtr_gctx_draw_text func_drawctrl_text;
    FPtr_gctx_draw_image func_drawctrl_image;
    FPtr_gctx_draw_rect func_drawctrl_checkbox;
    FPtr_gctx_draw_rect func_drawctrl_uncheckbox;
};

struct _evbutton_t
{
    uint32_t index;
    gui_state_t state;
    const char_t *text;
};

struct _evslider_t
{
    real32_t pos;
    real32_t incr;
    uint32_t step;
};

struct _evtext_t
{
    const char_t *text;
    uint32_t cpos;
    int32_t len;
};

#define kTEXTFILTER_SIZE 4096

struct _evtextfilter_t
{
    bool_t apply;
    char_t text[kTEXTFILTER_SIZE];
    uint32_t cpos;
};

struct _evdraw_t
{
    DCtx *ctx;
    real32_t x;
    real32_t y;
    real32_t width;
    real32_t height;
};

struct _evmouse_t
{
    real32_t x;
    real32_t y;
    real32_t lx;
    real32_t ly;
    gui_mouse_t button;
    uint32_t count;
    uint32_t modifiers;
    uint32_t tag;
};

struct _evwheel_t
{
    real32_t x;
    real32_t y;
    real32_t dx;
    real32_t dy;
    real32_t dz;
};

struct _evkey_t
{
    vkey_t key;
    uint32_t modifiers;
};

struct _evpos_t
{
    real32_t x;
    real32_t y;
};

struct _evsize_t
{
    real32_t width;
    real32_t height;
};

struct _evwinclose_t
{
    gui_close_t origin;
};

struct _evmenu_t
{
    uint32_t index;
    gui_state_t state;
    const char_t *text;
};

struct _evscroll_t
{
    gui_orient_t orient;
    gui_scroll_t scroll;
    real32_t cpos;
};

struct _evtbpos_t
{
    uint32_t col;
    uint32_t row;
};

struct _evtbrow_t
{
    bool_t sel;
    uint32_t row;
};

struct _evtbrect_t
{
    uint32_t stcol;
    uint32_t edcol;
    uint32_t strow;
    uint32_t edrow;
};

struct _evtbsel_t
{
    ArrSt(uint32_t) *sel;
};

struct _evtbcell_t
{
    const char_t *text;
    align_t align;
};

#endif
