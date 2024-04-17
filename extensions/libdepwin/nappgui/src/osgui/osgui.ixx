/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osgui.ixx
 *
 */

/* Operating system native gui */

#ifndef __OSGUI_IXX__
#define __OSGUI_IXX__

#include "osgui.hxx"

typedef struct _oswidget_t OSWidget;
typedef struct _oshotkey_t OSHotKey;
typedef struct _osframe_t OSFrame;
typedef struct _ostabstop_t OSTabStop;
typedef struct _osscrolls_t OSScrolls;
typedef struct _osscroll_t OSScroll;
typedef struct _strsize_data_t StringSizeData;

struct _oshotkey_t
{
    vkey_t key;
    uint32_t modifiers;
    Listener *listener;
};

struct _osframe_t
{
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
};

struct _ostabstop_t
{
    ArrPt(OSControl) *controls;
    ArrPt(OSControl) *tablist;
    uint32_t tabindex;
    gui_tab_t motion;
    OSWindow *window;
    OSButton *defbutton;
    OSControl *current;
    OSControl *transient;
    OSControl *next;
    bool_t cycle;
};

DeclSt(OSHotKey);
DeclPt(OSControl);
DeclPt(OSMenuItem);

#define OSControlPtr(ptr) ((OSControl *)(ptr))
#define OSWidgetPtr(ptr) ((OSWidget *)(ptr))
#define OSLabelPtr(ptr) ((OSLabel *)(ptr))
#define OSButtonPtr(ptr) ((OSButton *)(ptr))
#define OSPopUpPtr(ptr) ((OSPopUp *)(ptr))
#define OSEditPtr(ptr) ((OSEdit *)(ptr))
#define OSComboPtr(ptr) ((OSCombo *)(ptr))
#define OSSliderPtr(ptr) ((OSSlider *)(ptr))
#define OSUpDownPtr(ptr) ((OSUpDown *)(ptr))
#define OSProgressPtr(ptr) ((OSProgress *)(ptr))
#define OSTextPtr(ptr) ((OSText *)(ptr))
#define OSViewPtr(ptr) ((OSView *)(ptr))
#define OSPanelPtr(ptr) ((OSPanel *)(ptr))
#define OSSplitPtr(ptr) ((OSSplit *)(ptr))
#define OSWindowPtr(ptr) ((OSWindow *)(ptr))

#define OSControlDPtr(ptr) ((OSControl **)(ptr))
#define OSLabelDPtr(ptr) ((OSLabel **)(ptr))
#define OSButtonDPtr(ptr) ((OSButton **)(ptr))
#define OSPopUpDPtr(ptr) ((OSPopUp **)(ptr))
#define OSEditDPtr(ptr) ((OSEdit **)(ptr))
#define OSComboDPtr(ptr) ((OSCombo **)(ptr))
#define OSSliderDPtr(ptr) ((OSSlider **)(ptr))
#define OSUpDownDPtr(ptr) ((OSUpDown **)(ptr))
#define OSProgressDPtr(ptr) ((OSProgress **)(ptr))
#define OSTextDPtr(ptr) ((OSText **)(ptr))
#define OSViewDPtr(ptr) ((OSView **)(ptr))
#define OSPanelDPtr(ptr) ((OSPanel **)(ptr))
#define OSSplitDPtr(ptr) ((OSSplit **)(ptr))

#endif
