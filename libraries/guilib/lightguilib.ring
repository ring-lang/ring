# Check if GUILib is used in the same project!
	if isGlobal(:C_USING_GUILIB)
		? "Warning: Trying to load LightGUILib while GUILib is already used! - Operation Canceled"
		return
	ok

C_USING_LIGHTGUILIB = True

# Load the DLL files 
	if iswindows()
		cPluginPath = SysGet("QT_QPA_PLATFORM_PLUGIN_PATH")	
		SysSet ("QT_QPA_PLATFORM_PLUGIN_PATH", "")
		LoadLib("ringqt_light.dll")
		SysSet ("QT_QPA_PLATFORM_PLUGIN_PATH", cPluginPath)
	but ismacosx()
		LoadLib("libringqt_light.dylib")
	but islinux()
		LoadLib("libringqt_light.so")
	ok

# Load the files
	load "guilibfiles.ring"