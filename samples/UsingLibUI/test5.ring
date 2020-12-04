# Sample ported to Ring 
# Based on original sample from : https://github.com/andlabs/libui

load "libui.ring"

# Create the Menubar

	fileMenu = uiNewMenu("File")
	newItem = uiMenuAppendItem(fileMenu, "New")
	openItem = uiMenuAppendItem(fileMenu, "Open")
	uiMenuAppendSeparator(fileMenu)
	shouldQuitItem = uiMenuAppendCheckItem(fileMenu, "Should Quit")
	quitItem = uiMenuAppendQuitItem(fileMenu)
	
	editMenu = uiNewMenu("Edit")
	undoItem = uiMenuAppendItem(editMenu, "Undo")
	uiMenuItemDisable(undoItem)
	uiMenuAppendSeparator(editMenu)
	checkItem = uiMenuAppendCheckItem(editMenu, "Check Me\tTest")
	accelItem = uiMenuAppendItem(editMenu, "A&ccele&&rator T_es__t")
	prefsItem = uiMenuAppendPreferencesItem(editMenu)
	
	testMenu = uiNewMenu("Test")
	enabledItem = uiMenuAppendCheckItem(testMenu, "Enable Below Item")
	uiMenuItemSetChecked(enabledItem, 1)
	enableThisItem = uiMenuAppendItem(testMenu, "This Will Be Enabled")
	uiMenuItemOnClicked(enabledItem, "enableItemTest(enableThisItem)")
	forceCheckedItem = uiMenuAppendItem(testMenu, "Force Above Checked")
	uiMenuItemOnClicked(forceCheckedItem, "forceOn()")
	forceUncheckedItem = uiMenuAppendItem(testMenu, "Force Above Unchecked")
	uiMenuItemOnClicked(forceUncheckedItem, "forceOff()")
	uiMenuAppendSeparator(testMenu)
	whatWindowItem = uiMenuAppendItem(testMenu, "What Window?")
	uiMenuItemOnClicked(whatWindowItem, "whatWindow()")
	
	moreTestsMenu = uiNewMenu("More Tests")
	quitEnabledItem = uiMenuAppendCheckItem(moreTestsMenu, "Quit Item Enabled")
	uiMenuItemSetChecked(quitEnabledItem, 1)
	prefsEnabledItem = uiMenuAppendCheckItem(moreTestsMenu, "Preferences Item Enabled")
	uiMenuItemSetChecked(prefsEnabledItem, 1)
	aboutEnabledItem = uiMenuAppendCheckItem(moreTestsMenu, "About Item Enabled")
	uiMenuItemSetChecked(aboutEnabledItem, 1)
	uiMenuAppendSeparator(moreTestsMenu)
	checkEnabledItem = uiMenuAppendCheckItem(moreTestsMenu, "Check Me Item Enabled")
	uiMenuItemSetChecked(checkEnabledItem, 1)
	
	multiMenu = uiNewMenu("Multi")
	uiMenuAppendSeparator(multiMenu)
	uiMenuAppendSeparator(multiMenu)
	uiMenuAppendItem(multiMenu, "Item && Item && Item")
	uiMenuAppendSeparator(multiMenu)
	uiMenuAppendSeparator(multiMenu)
	uiMenuAppendItem(multiMenu, "Item __ Item __ Item")
	uiMenuAppendSeparator(multiMenu)
	uiMenuAppendSeparator(multiMenu)
	
	helpMenu = uiNewMenu("Help")
	helpItem = uiMenuAppendItem(helpMenu, "Help")
	aboutItem = uiMenuAppendAboutItem(helpMenu)
	
	uiMenuItemOnClicked(quitEnabledItem, "enableItemTest(quitItem)")
	uiMenuItemOnClicked(prefsEnabledItem, "enableItemTest(prefsItem)")
	uiMenuItemOnClicked(aboutEnabledItem, "enableItemTest(aboutItem)")
	uiMenuItemOnClicked(checkEnabledItem, "enableItemTest(checkItem)")

# Create the Window
	
	oWindow = uiNewWindow( "Using the Menubar", 400, 400, True)
	uiWindowOnClosing(oWindow,"closeApp()")
	
	uiControlShow( oWindow )
	uiMain()
	
func enableItemTest(data)
	item = uiEventMenuItem()
	if uiMenuItemChecked(item)
		uiMenuItemEnable(data)
	else
		uiMenuItemDisable(data)
	ok

func forceOn
	uiMenuItemSetChecked(enabledItem, 1)

func forceOff
	uiMenuItemSetChecked(enabledItem, 0)

func whatWindow
	? "menu item clicked on window " 
	? oWindow

func closeApp
	uiQuit()
