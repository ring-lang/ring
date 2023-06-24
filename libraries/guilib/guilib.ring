# Check if Light GUILib is used in the same project!
	if isGlobal(:C_USING_LIGHTGUILIB)
		? "Warning: Trying to load GUILib while LightGUILib is already used! - Operation Canceled"
		return
	ok

C_USING_GUILIB = True

# Load the DLL files 
	load "loadlibfile.ring"
	loadlibfile("ringqt")

# Load the files
	load "guilibfiles.ring"