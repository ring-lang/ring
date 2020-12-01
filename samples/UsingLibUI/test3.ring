# Sample ported to Ring 
# Based on original sample from : https://github.com/andlabs/libui

load "libui.ring"

# Global Variables  

	slider = NULL
	spinbox = NULL
	pBar = NULL
	entryOpen = NULL
	entrySave = NULL

# Main Window

	mainwin = uiNewWindow("libui Control Gallery", 640, 480, 1)
	uiWindowOnClosing(mainwin, "onClosing()")

	tab = uiNewTab()
	uiWindowSetChild(mainwin, uiControl(tab))
	uiWindowSetMargined(mainwin, 1)

	uiTabAppend(tab, "Basic Controls", makeBasicControlsPage())
	uiTabSetMargined(tab, 0, 1)

	uiTabAppend(tab, "Numbers and Lists", makeNumbersPage())
	uiTabSetMargined(tab, 1, 1)

	uiTabAppend(tab, "Data Choosers", makeDataChoosersPage())
	uiTabSetMargined(tab, 2, 1)

	uiControlShow(uiControl(mainwin))
	uiMain()

func onClosing
	uiQuit()

func makeDataChoosersPage 

	hbox = uiNewHorizontalBox()
	uiBoxSetPadded(hbox, 1)

	vbox = uiNewVerticalBox()
	uiBoxSetPadded(vbox, 1)
	uiBoxAppend(hbox, uiControl(vbox), 0)

	uiBoxAppend(vbox,
		uiControl(uiNewDatePicker()),
		0)
	uiBoxAppend(vbox,
		uiControl(uiNewTimePicker()),
		0)
	uiBoxAppend(vbox,
		uiControl(uiNewDateTimePicker()),
		0)

	uiBoxAppend(vbox,
		uiControl(uiNewFontButton()),
		0)
	uiBoxAppend(vbox,
		uiControl(uiNewColorButton()),
		0)

	uiBoxAppend(hbox,
		uiControl(uiNewVerticalSeparator()),
		0)

	vbox = uiNewVerticalBox()
	uiBoxSetPadded(vbox, 1)
	uiBoxAppend(hbox, uiControl(vbox), 1)

	grid = uiNewGrid()
	uiGridSetPadded(grid, 1)
	uiBoxAppend(vbox, uiControl(grid), 0)

	button = uiNewButton("Open File")
	entryOpen = uiNewEntry()
	uiEntrySetReadOnly(entryOpen, 1)
	uiButtonOnClicked(button, "onOpenFileClicked()")
	uiGridAppend(grid, uiControl(button),
		0, 0, 1, 1,
		0, uiAlignFill, 0, uiAlignFill)
	uiGridAppend(grid, uiControl(entryOpen),
		1, 0, 1, 1,
		1, uiAlignFill, 0, uiAlignFill)

	button = uiNewButton("Save File")
	entrySave = uiNewEntry()
	uiEntrySetReadOnly(entrySave, 1)
	uiButtonOnClicked(button, "onSaveFileClicked()")
	uiGridAppend(grid, uiControl(button),
		0, 1, 1, 1,
		0, uiAlignFill, 0, uiAlignFill)
	uiGridAppend(grid, uiControl(entrySave),
		1, 1, 1, 1,
		1, uiAlignFill, 0, uiAlignFill)

	msggrid = uiNewGrid()
	uiGridSetPadded(msggrid, 1)
	uiGridAppend(grid, uiControl(msggrid),
		0, 2, 2, 1,
		0, uiAlignCenter, 0, uiAlignStart)

	button = uiNewButton("Message Box")
	uiButtonOnClicked(button, "onMsgBoxClicked()")
	uiGridAppend(msggrid, uiControl(button),
		0, 0, 1, 1,
		0, uiAlignFill, 0, uiAlignFill)
	button = uiNewButton("Error Box")
	uiButtonOnClicked(button, "onMsgBoxErrorClicked()")
	uiGridAppend(msggrid, uiControl(button),
		1, 0, 1, 1,
		0, uiAlignFill, 0, uiAlignFill)

	return uiControl(hbox)

func makeNumbersPage

	hbox = uiNewHorizontalBox()
	uiBoxSetPadded(hbox, 1)

	group = uiNewGroup("Numbers")
	uiGroupSetMargined(group, 1)
	uiBoxAppend(hbox, uiControl(group), 1)

	vbox = uiNewVerticalBox()
	uiBoxSetPadded(vbox, 1)
	uiGroupSetChild(group, uiControl(vbox))

	spinbox = uiNewSpinbox(0, 100)
	slider = uiNewSlider(0, 100)
	pbar = uiNewProgressBar()
	uiSpinboxOnChanged(spinbox, "onSpinboxChanged()")
	uiSliderOnChanged(slider, "onSliderChanged()")
	uiBoxAppend(vbox, uiControl(spinbox), 0)
	uiBoxAppend(vbox, uiControl(slider), 0)
	uiBoxAppend(vbox, uiControl(pbar), 0)

	ip = uiNewProgressBar()
	uiProgressBarSetValue(ip, -1)
	uiBoxAppend(vbox, uiControl(ip), 0)

	group = uiNewGroup("Lists")
	uiGroupSetMargined(group, 1)
	uiBoxAppend(hbox, uiControl(group), 1)

	vbox = uiNewVerticalBox()
	uiBoxSetPadded(vbox, 1)
	uiGroupSetChild(group, uiControl(vbox))

	cbox = uiNewCombobox()
	uiComboboxAppend(cbox, "Combobox Item 1")
	uiComboboxAppend(cbox, "Combobox Item 2")
	uiComboboxAppend(cbox, "Combobox Item 3")
	uiBoxAppend(vbox, uiControl(cbox), 0)

	ecbox = uiNewEditableCombobox()
	uiEditableComboboxAppend(ecbox, "Editable Item 1")
	uiEditableComboboxAppend(ecbox, "Editable Item 2")
	uiEditableComboboxAppend(ecbox, "Editable Item 3")
	uiBoxAppend(vbox, uiControl(ecbox), 0)

	rb = uiNewRadioButtons()
	uiRadioButtonsAppend(rb, "Radio Button 1")
	uiRadioButtonsAppend(rb, "Radio Button 2")
	uiRadioButtonsAppend(rb, "Radio Button 3")
	uiBoxAppend(vbox, uiControl(rb), 0)

	return uiControl(hbox)


func makeBasicControlsPage

	vbox = uiNewVerticalBox()
	uiBoxSetPadded(vbox, 1)

	hbox = uiNewHorizontalBox()
	uiBoxSetPadded(hbox, 1)
	uiBoxAppend(vbox, uiControl(hbox), 0)

	uiBoxAppend(hbox,
		uiControl(uiNewButton("Button")),
		0)
	uiBoxAppend(hbox,
		uiControl(uiNewCheckbox("Checkbox")),
		0)

	uiBoxAppend(vbox,
		uiControl(uiNewLabel("This is a label. Right now, labels can only span one line.")),
		0)

	uiBoxAppend(vbox,
		uiControl(uiNewHorizontalSeparator()),
		0)

	group = uiNewGroup("Entries")
	uiGroupSetMargined(group, 1)
	uiBoxAppend(vbox, uiControl(group), 1)

	entryForm = uiNewForm()
	uiFormSetPadded(entryForm, 1)
	uiGroupSetChild(group, uiControl(entryForm))

	uiFormAppend(entryForm,
		"Entry",
		uiControl(uiNewEntry()),
		0)
	uiFormAppend(entryForm,
		"Password Entry",
		uiControl(uiNewPasswordEntry()),
		0)
	uiFormAppend(entryForm,
		"Search Entry",
		uiControl(uiNewSearchEntry()),
		0)
	uiFormAppend(entryForm,
		"Multiline Entry",
		uiControl(uiNewMultilineEntry()),
		1)
	uiFormAppend(entryForm,
		"Multiline Entry No Wrap",
		uiControl(uiNewNonWrappingMultilineEntry()),
		1)

	return uiControl(vbox)


func onSpinboxChanged
	s = uiEventSpinBox()
	uiSliderSetValue(slider, uiSpinboxValue(s));
	uiProgressBarSetValue(pbar, uiSpinboxValue(s));

func onSliderChanged
	s = uiEventSlider()
	uiSpinboxSetValue(spinbox, uiSliderValue(s));
	uiProgressBarSetValue(pbar, uiSliderValue(s));


func onOpenFileClicked
	filename = uiOpenFile(mainwin)
	if filename = NULL
		uiEntrySetText(entryOpen, "(cancelled)")
		return;
	ok
	uiEntrySetText(entryOpen, filename)
	uiFreeText(filename)

func onSaveFileClicked
	filename = uiSaveFile(mainwin)
	if filename = NULL
		uiEntrySetText(entrySave, "(cancelled)")
		return
	ok
	uiEntrySetText(entrySave, filename)
	uiFreeText(filename)

func onMsgBoxClicked
	uiMsgBox(mainwin,
		"This is a normal message box.",
		"More detailed information can be shown here.")

func onMsgBoxErrorClicked
	uiMsgBoxError(mainwin,
		"This message box describes an error.",
		"More detailed information can be shown here.")
