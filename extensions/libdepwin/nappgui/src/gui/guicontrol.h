/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: guicontrol.h
 * https://nappgui.com/en/gui/guicontrol.html
 *
 */

/* Generic-virtual gui control */

#include "gui.hxx"

__EXTERN_C

_gui_api Label *guicontrol_label(GuiControl *control);

_gui_api Button *guicontrol_button(GuiControl *control);

_gui_api PopUp *guicontrol_popup(GuiControl *control);

_gui_api Edit *guicontrol_edit(GuiControl *control);

_gui_api Combo *guicontrol_combo(GuiControl *control);

_gui_api ListBox *guicontrol_listbox(GuiControl *control);

_gui_api UpDown *guicontrol_updown(GuiControl *control);

_gui_api Slider *guicontrol_slider(GuiControl *control);

_gui_api Progress *guicontrol_progress(GuiControl *control);

_gui_api View *guicontrol_view(GuiControl *control);

_gui_api TextView *guicontrol_textview(GuiControl *control);

_gui_api ImageView *guicontrol_imageview(GuiControl *control);

_gui_api TableView *guicontrol_tableview(GuiControl *control);

_gui_api SplitView *guicontrol_splitview(GuiControl *control);

_gui_api Panel *guicontrol_panel(GuiControl *control);

_gui_api void guicontrol_tag(GuiControl *control, const uint32_t tag);

_gui_api uint32_t guicontrol_get_tag(const GuiControl *control);

__END_C

#define guicontrol(control) ((GuiControl *)control)
