# Check if GUILib is used in the same project!
	if isGlobal(:C_USING_GUILIB)
		? "Warning: Trying to load LightGUILib while GUILib is already used! - Operation Canceled"
		return
	ok

C_USING_LIGHTGUILIB = True

# Load the DLL files 
	if iswindows()
		LoadLib("ringqt_light.dll")
	but ismacosx()
		LoadLib("libringqt_light.dylib")
	but islinux()
		LoadLib("libringqt_light.so")
	ok

# Load the files
	load "guilibfiles.ring"