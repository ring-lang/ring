/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscontrol.c
 *
 */

/* Control common functions */

#include "oscontrol.inl"
#include "osbutton.inl"
#include "oscombo.inl"
#include "osedit.inl"
#include "oslabel.inl"
#include "ospanel.inl"
#include "ospopup.inl"
#include "osprogress.inl"
#include "osslider.inl"
#include "ossplit.inl"
#include "ostext.inl"
#include "osupdown.inl"
#include "osview.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

const char_t *oscontrol_type_str(const gui_type_t type)
{
    switch (type)
    {
    case ekGUI_TYPE_LABEL:
        return "OSLabel";
    case ekGUI_TYPE_BUTTON:
        return "OSButton";
    case ekGUI_TYPE_POPUP:
        return "OSPopUp";
    case ekGUI_TYPE_EDITBOX:
        return "OSEdit";
    case ekGUI_TYPE_COMBOBOX:
        return "OSComboBox";
    case ekGUI_TYPE_SLIDER:
        return "OSSlider";
    case ekGUI_TYPE_UPDOWN:
        return "OSUpDown";
    case ekGUI_TYPE_PROGRESS:
        return "OSProgress";
    case ekGUI_TYPE_TEXTVIEW:
        return "OSTextView";
    case ekGUI_TYPE_TABLEVIEW:
        return "OSTableView";
    case ekGUI_TYPE_TREEVIEW:
        return "OSTreeView";
    case ekGUI_TYPE_BOXVIEW:
        return "OSBoxView";
    case ekGUI_TYPE_SPLITVIEW:
        return "OSSplitView";
    case ekGUI_TYPE_CUSTOMVIEW:
        return "OSView";
    case ekGUI_TYPE_PANEL:
        return "OSPanel";
    case ekGUI_TYPE_LINE:
        return "OSLine";
    case ekGUI_TYPE_HEADER:
        return "OSHeader";
    case ekGUI_TYPE_TOOLBAR:
        return "OSToolbar";
    case ekGUI_TYPE_WINDOW:
        return "OSWindow";
        cassert_default();
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

void oscontrol_detach_and_destroy(OSControl **control, OSPanel *panel)
{
    gui_type_t type = ENUM_MAX(gui_type_t);
    cassert_no_null(control);
    type = oscontrol_type(*control);
    switch (type)
    {
    case ekGUI_TYPE_LABEL:
        oslabel_detach_and_destroy(OSLabelDPtr(control), panel);
        break;
    case ekGUI_TYPE_BUTTON:
        osbutton_detach_and_destroy(OSButtonDPtr(control), panel);
        break;
    case ekGUI_TYPE_POPUP:
        ospopup_detach_and_destroy(OSPopUpDPtr(control), panel);
        break;
    case ekGUI_TYPE_EDITBOX:
        osedit_detach_and_destroy(OSEditDPtr(control), panel);
        break;
    case ekGUI_TYPE_COMBOBOX:
        oscombo_detach_and_destroy(OSComboDPtr(control), panel);
        break;
    case ekGUI_TYPE_SLIDER:
        osslider_detach_and_destroy(OSSliderDPtr(control), panel);
        break;
    case ekGUI_TYPE_UPDOWN:
        osupdown_detach_and_destroy(OSUpDownDPtr(control), panel);
        break;
    case ekGUI_TYPE_PROGRESS:
        osprogress_detach_and_destroy(OSProgressDPtr(control), panel);
        break;
    case ekGUI_TYPE_TEXTVIEW:
        ostext_detach_and_destroy(OSTextDPtr(control), panel);
        break;
    case ekGUI_TYPE_CUSTOMVIEW:
        osview_detach_and_destroy(OSViewDPtr(control), panel);
        break;
    case ekGUI_TYPE_PANEL:
        ospanel_detach_and_destroy(OSPanelDPtr(control), panel);
        break;
    case ekGUI_TYPE_SPLITVIEW:
        ossplit_detach_and_destroy(OSSplitDPtr(control), panel);
        break;
    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }
}
