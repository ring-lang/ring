# Check if GUILib is used in the same project!
	if isGlobal(:C_USING_GUILIB)
		? "Warning: Trying to load LightGUILib while GUILib is already used! - Operation Canceled"
		return
	ok

C_USING_LIGHTGUILIB = True

# Load the DLL files 
	load "loadlibfile.ring"
	loadlibfile("ringqt_light")

# Load the files
	load "guilibfiles.ring"