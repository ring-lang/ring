# Sample ported to Ring 
# Based on original sample from : https://github.com/andlabs/libui

load "libui.ring"

# Global Variables
	mainwin		= NULL
	area		= NULL
	handler		= NULL
	fontButton	= NULL
	alignment	= NULL
	attrstr		= NULL

func appendWithAttribute what, attr, attr2
	nStart = uiAttributedStringLen(attrstr)
	nEnd = nStart + len(what)
	uiAttributedStringAppendUnattributed(attrstr, what)
	uiAttributedStringSetAttribute(attrstr, attr, nStart, nEnd)
	if ! ISNULL(attr2)
		uiAttributedStringSetAttribute(attrstr, attr2, nStart, nEnd)
	ok

func makeAttributedString

	attrstr = uiNewAttributedString("Drawing strings with libui is done with the uiAttributedString and uiDrawTextLayout objects."+nl+
		"uiAttributedString lets you have a variety of attributes: ")

	attr = uiNewFamilyAttribute("Courier New")
	appendWithAttribute("font family", attr, NULL)
	uiAttributedStringAppendUnattributed(attrstr, ", ")

	attr = uiNewSizeAttribute(18)
	appendWithAttribute("font size", attr, NULL)
	uiAttributedStringAppendUnattributed(attrstr, ", ")

	attr = uiNewWeightAttribute(uiTextWeightBold)
	appendWithAttribute("font weight", attr, NULL)
	uiAttributedStringAppendUnattributed(attrstr, ", ")

	attr = uiNewItalicAttribute(uiTextItalicItalic)
	appendWithAttribute("font italicness", attr, NULL)
	uiAttributedStringAppendUnattributed(attrstr, ", ")

	attr = uiNewStretchAttribute(uiTextStretchCondensed)
	appendWithAttribute("font stretch", attr, NULL)
	uiAttributedStringAppendUnattributed(attrstr, ", ")

	attr = uiNewColorAttribute(0.75, 0.25, 0.5, 0.75)
	appendWithAttribute("text color", attr, NULL)
	uiAttributedStringAppendUnattributed(attrstr, ", ")

	attr = uiNewBackgroundAttribute(0.5, 0.5, 0.25, 0.5)
	appendWithAttribute("text background color", attr, NULL)
	uiAttributedStringAppendUnattributed(attrstr, ", ")


	attr = uiNewUnderlineAttribute(uiUnderlineSingle)
	appendWithAttribute("underline style", attr, NULL)
	uiAttributedStringAppendUnattributed(attrstr, ", ")

	uiAttributedStringAppendUnattributed(attrstr, "and ")
	attr = uiNewUnderlineAttribute(uiUnderlineDouble)
	attr2 = uiNewUnderlineColorAttribute(uiUnderlineColorCustom, 1.0, 0.0, 0.5, 1.0)
	appendWithAttribute("underline color", attr, attr2)
	uiAttributedStringAppendUnattributed(attrstr, ". ")

	uiAttributedStringAppendUnattributed(attrstr, "Furthermore, there are attributes allowing for ")
	attr = uiNewUnderlineAttribute(uiUnderlineSuggestion)
	attr2 = uiNewUnderlineColorAttribute(uiUnderlineColorSpelling, 0, 0, 0, 0)
	appendWithAttribute("special underlines for indicating spelling errors", attr, attr2)
	uiAttributedStringAppendUnattributed(attrstr, " (and other types of errors) ")

	uiAttributedStringAppendUnattributed(attrstr, "and control over OpenType features such as ligatures (for instance, ")
	otf = uiNewOpenTypeFeatures()
	uiOpenTypeFeaturesAdd(otf, ASCII('l'), ASCII('i'), ASCII('g'), ASCII('a'), 0)
	attr = uiNewFeaturesAttribute(otf)
	appendWithAttribute("afford", attr, NULL)
	uiAttributedStringAppendUnattributed(attrstr, " vs. ")
	uiOpenTypeFeaturesAdd(otf, ASCII('l'), ASCII('i'), ASCII('g'), ASCII('a'), 1)
	attr = uiNewFeaturesAttribute(otf)
	appendWithAttribute("afford", attr, NULL)
	uiFreeOpenTypeFeatures(otf)
	uiAttributedStringAppendUnattributed(attrstr, ").\n")

	uiAttributedStringAppendUnattributed(attrstr, "Use the controls opposite to the text to control properties of the text.")

func handlerDraw

	defaultfont = new_uiFontDescriptor()
	params = new_uiDrawTextLayoutParams()

	set_uiDrawTextLayoutParams_String(params,attrstr)
	uiFontButtonFont(fontButton, defaultFont)
	set_uiDrawTextLayoutParams_DefaultFont(params,defaultFont)
	set_uiDrawTextLayoutParams_Width(params,uiEventAreaWidth())
	set_uiDrawTextLayoutParams_Align(params,uiComboboxSelected(alignment))
	textLayout = uiDrawNewTextLayout(params)
	uiDrawText(uiEventContext(), textLayout, 0, 0)
	uiDrawFreeTextLayout(textLayout)
	uiFreeFontButtonFont(defaultFont)

func onFontChanged
	uiAreaQueueRedrawAll(area)

func onComboboxSelected
	uiAreaQueueRedrawAll(area)

func onClosing
	uiControlDestroy(mainwin)
	uiQuit()

func shouldQuit
	uiControlDestroy(mainwin)

func main

	uiOnShouldQuit("shouldQuit()")

	makeAttributedString()

	mainwin = uiNewWindow("libui Text-Drawing Example", 640, 480, 1)
	uiWindowSetMargined(mainwin, 1)
	uiWindowOnClosing(mainwin, "onClosing()")

	hbox = uiNewHorizontalBox()
	uiBoxSetPadded(hbox, 1)
	uiWindowSetChild(mainwin, hbox)

	vbox = uiNewVerticalBox()
	uiBoxSetPadded(vbox, 1)
	uiBoxAppend(hbox, vbox, 0)

	fontButton = uiNewFontButton()
	uiFontButtonOnChanged(fontButton, "onFontChanged()")
	uiBoxAppend(vbox, fontButton, 0)

	form = uiNewForm()
	uiFormSetPadded(form, 1)
	uiBoxAppend(vbox, form, 0)

	alignment = uiNewCombobox()
	uiComboboxAppend(alignment, "Left")
	uiComboboxAppend(alignment, "Center")
	uiComboboxAppend(alignment, "Right")
	uiComboboxSetSelected(alignment, 0)		// start with left alignment
	uiComboboxOnSelected(alignment, "onComboboxSelected()")
	uiFormAppend(form, "Alignment", alignment, 0)

	oAreaHandler = uiNewAreaHandler("handlerDraw()","","","","")
	area = uiNewArea(oAreaHandler)
	uiBoxAppend(hbox, area, 1)

	uiControlShow(mainwin)
	uiMain()
	uiFreeAttributedString(attrstr)
