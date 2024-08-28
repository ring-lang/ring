# Check if GUILib or LightGUILib is used in the same project!
	if isGlobal(:C_USING_LIGHTGUILIB) or isGlobal(:C_USING_GUILIB)
		return
	ok

# Load the DLL files 
	load "loadlibfile.ring"
	loadlibfile("ringqt_core")

# Load the files
	load "guilibfiles.ring"
