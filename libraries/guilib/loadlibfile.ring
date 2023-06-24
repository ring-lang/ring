func loadlibfile cLibName
	if iswindows()
		cPluginPath = SysGet("QT_QPA_PLATFORM_PLUGIN_PATH")	
		SysSet ("QT_QPA_PLATFORM_PLUGIN_PATH", "")
		LoadLib(cLibName+".dll")
		SysSet ("QT_QPA_PLATFORM_PLUGIN_PATH", cPluginPath)
	but ismacosx()
		LoadLib("lib"+cLibName+".dylib")
	but islinux()
		LoadLib("lib"+cLibName+".so")
	ok