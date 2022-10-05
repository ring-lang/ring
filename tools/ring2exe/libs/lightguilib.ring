aLibrary = [:name = :lightguilib ,
	 :title = "LightGuiLib",
	 :windowsfiles = [
		"Qt5Core.dll",
		"Qt5Gui.dll",
		"Qt5Test.dll",
		"Qt5Widgets.dll",
		"ringqt_light.dll",
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
		"platforms\qwindows.dll",
		"styles\qwindowsvistastyle.dll",
		"styles\qwindowsvistastyled.dll"
	 ] ,
	 :windowsfolders = [
		"imageformats"
	 ],
	 :linuxfiles = [
		"libringqt_light.so"
	 ],
	 :macosxfiles = [
		"libringqt_light.dylib"
	 ],
	 :ubuntudep = "qt5-default qtbase5-dev",
	 :fedoradep = "qt5-qtbase-devel",
	 :macosxdep = "qt@5"
	]