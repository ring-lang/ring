# Check if Light GUILib is used in the same project!
	if isGlobal(:C_USING_LIGHTGUILIB)
		? "Warning: Trying to load GUILib while LightGUILib is already used! - Operation Canceled"
		return
	ok

C_USING_GUILIB = True

# Load the DLL files 
	if iswindows()
		cPluginPath = SysGet("QT_QPA_PLATFORM_PLUGIN_PATH")	
		SysSet ("QT_QPA_PLATFORM_PLUGIN_PATH", "")
		LoadLib("ringqt.dll")
		SysSet ("QT_QPA_PLATFORM_PLUGIN_PATH", cPluginPath)
	but ismacosx()
		LoadLib("libringqt.dylib")
	but islinux()
		LoadLib("libringqt.so")
	ok

# Load the files
	load "guilibfiles.ring"