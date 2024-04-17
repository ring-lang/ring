/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: guicontrol.c
 *
 */

/* Generic-virtual gui control */

#include "guicontrol.h"
#include "component.inl"
#include "view.inl"
#include <core/strings.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

Label *guicontrol_label(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_LABEL)
        return (Label *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

Button *guicontrol_button(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_BUTTON)
        return (Button *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

PopUp *guicontrol_popup(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_POPUP)
        return (PopUp *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

Edit *guicontrol_edit(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_EDITBOX)
        return (Edit *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

Combo *guicontrol_combo(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_COMBOBOX)
        return (Combo *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

ListBox *guicontrol_listbox(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_CUSTOMVIEW)
    {
        if (str_equ_c(_view_subtype((View *)component), "ListBox") == TRUE)
            return (ListBox *)component;
    }
    return NULL;
}

/*---------------------------------------------------------------------------*/

UpDown *guicontrol_updown(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_UPDOWN)
        return (UpDown *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

Slider *guicontrol_slider(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_SLIDER)
        return (Slider *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

Progress *guicontrol_progress(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_PROGRESS)
        return (Progress *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

View *guicontrol_view(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_CUSTOMVIEW)
    {
        if (str_equ_c(_view_subtype((View *)component), "View") == TRUE)
            return (View *)component;
    }
    return NULL;
}

/*---------------------------------------------------------------------------*/

TextView *guicontrol_textview(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_CUSTOMVIEW)
    {
        if (str_equ_c(_view_subtype((View *)component), "TextView") == TRUE)
            return (TextView *)component;
    }
    return NULL;
}

/*---------------------------------------------------------------------------*/

ImageView *guicontrol_imageview(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_CUSTOMVIEW)
    {
        if (str_equ_c(_view_subtype((View *)component), "ImageView") == TRUE)
            return (ImageView *)component;
    }
    return NULL;
}

/*---------------------------------------------------------------------------*/

TableView *guicontrol_tableview(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_CUSTOMVIEW)
    {
        if (str_equ_c(_view_subtype((View *)component), "TableView") == TRUE)
            return (TableView *)component;
    }
    return NULL;
}

/*---------------------------------------------------------------------------*/

SplitView *guicontrol_splitview(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_SPLITVIEW)
        return (SplitView *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

Panel *guicontrol_panel(GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    if (component != NULL && component->type == ekGUI_TYPE_PANEL)
        return (Panel *)component;
    return NULL;
}

/*---------------------------------------------------------------------------*/

void guicontrol_tag(GuiControl *control, const uint32_t tag)
{
    GuiComponent *component = (GuiComponent *)control;
    cassert_no_null(component);
    component->tag.tag_uint32 = tag;
}

/*---------------------------------------------------------------------------*/

uint32_t guicontrol_get_tag(const GuiControl *control)
{
    GuiComponent *component = (GuiComponent *)control;
    cassert_no_null(component);
    return component->tag.tag_uint32;
}
