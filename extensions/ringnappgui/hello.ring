load "nappgui.ring"

# Global Variables

	Window  = NULL 
	text    = NULL 
	nClicks = 0

# Give control to the GUI library

	osmain()

func create_gui

	window = window_create(ekWINDOW_STD)
	window_title(window, "Hello, World!")
 	window_origin(window, v2df(100, 100))
	window_OnClose( window, create_event("close_app()"))

	panel = panel_create()
	layout = layout_create(1, 3)
	label = label_create()
	button = button_push()
	text = textview_create()
	label_text(label, "Hello!, I'm a label")
	button_text(button, "Click Me!")
	button_OnClick(button, create_event("button_click()") )
	layout_label(layout, label, 0, 0)
	layout_button(layout, button, 0, 1)
	layout_textview(layout, text, 0, 2)
	layout_hsize(layout, 0, 250)
	layout_vsize(layout, 2, 100)
	layout_margin(layout, 5)
	layout_vmargin(layout, 0, 5)
	layout_vmargin(layout, 1, 5)
	panel_layout(panel, layout)

	window_panel(window,panel)
	window_show(window)

func button_click

	nClicks++
	textview_writef(text,"Button click (" + nClicks + ")" + nl)

func close_app

	window_destroy(window)
	clean_events()
	osapp_finish()
