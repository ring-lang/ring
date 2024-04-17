/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osgui_win.ixx
 *
 */

/* Operating system native gui */

#ifndef __OSGUIWIN_IXX__
#define __OSGUIWIN_IXX__

#include "osgui.ixx"

#if _MSC_VER == 1400
#define _WIN32_WINNT 0x501
#endif

#include <sewer/nowarn.hxx>
#include <windows.h>
#include <uxtheme.h>
#if _MSC_VER > 1400
#include <vssym32.h>
#include <vsstyle.h>
#else
#include <tmschema.h>
#endif
#include <sewer/warn.hxx>

#define WCHAR_BUFFER_SIZE 512

typedef struct _view_listeners_t ViewListeners;
typedef struct _osimgdata_t OSImgData;
typedef struct _osimglist_t OSImgList;
typedef struct _osdraw_t OSDraw;

struct _view_listeners_t
{
    BOOL is_mouse_inside;
    BOOL enabled;
    gui_mouse_t button;
    LONG OnMouseMoved_event_source;
    real32_t mouse_down_x;
    real32_t mouse_down_y;
    uint64_t mouse_down_time;
    Listener *OnDraw;
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
};

struct _oscontrol_t
{
    gui_type_t type;
    HWND hwnd;
    HWND tooltip_hwnd;
    WNDPROC def_wnd_proc;

    /* HWND does not save the coordinates of the child with respect to the parent.
	   They can be calculated with 'MapWindowPoints', but it does not work correctly
	   on scrolling panels. */
    int32_t x;
    int32_t y;
};

struct _strsize_data_t
{
    HDC hdc;
};

struct _osdraw_t
{
    HTHEME button_theme;
    HTHEME list_theme;
    HTHEME header_theme;
    SIZE sort_size;
};

#endif
