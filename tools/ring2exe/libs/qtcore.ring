aLibrary = [:name = :qtcore ,
	 :title = "QtCore",
	 :windowsfiles = [
		"Qt5Core.dll",
		"ringqt_core.dll",
		"msvcp140.dll",
		"vccorlib140.dll",
		"vcruntime140.dll",
		"libEGL.dll",
		"libGLESv2.dll",
		"d3dcompiler_47.dll",
		'"libstdc++-6.dll"',
		'"libwinpthread-1.dll"',
		"api-ms-win-core-winrt-l1-1-0.dll",
		"api-ms-win-core-winrt-string-l1-1-0.dll",
		"concrt140.dll",
		"libgcc_s_dw2-1.dll",
		"platforms\qwindows.dll"
	 ] ,
	 :windowsfolders = [
		"imageformats"
	 ],
	 :linuxfiles = [
		"libringqt_core.so"
	 ],
	 :macosxfiles = [
		"libringqt_core.dylib"
	 ],
	 :ubuntudep = "qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools",
	 :fedoradep = "qt5-qtbase-devel",
	 :macosxdep = "qt@5"
	]