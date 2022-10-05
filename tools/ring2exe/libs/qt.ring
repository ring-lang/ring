aLibrary = [:name = :qt ,
	 :title = "RingQt",
	 :windowsfiles = [
		"Qt5*.dll",
		"ringqt.dll",
		"icudt54.dll",
		"icuin54.dll",
		"icuuc54.dll",
		"QtWebEngineProcess.exe",
		"icudtl.dat",
		"qtwebengine_devtools_resources.pak",
		"qtwebengine_resources.pak",
		"qtwebengine_resources_100p.pak",
		"qtwebengine_resources_200p.pak",
		"msvcp140.dll",
		"vccorlib140.dll",
		"vcruntime140.dll",
		"libEGL.dll",
		"libGLESv2.dll",
		"d3dcompiler_47.dll",
		"opengl32sw.dll",
		'"libstdc++-6.dll"',
		'"libwinpthread-1.dll"'
	 ] ,
	 :windowsfolders = [
		:audio,
		:bearer,
		:geometryloaders,
		:texttospeech,
		:iconengines,
		:imageformats,
		:mediaservice,
		:platforms,
		:playlistformats,
		:position,
		:printsupport,
		:sensors,
		:sensorgestures,
		:sqldrivers,
		:translations,
		:styles
	 ],
	 :linuxfiles = [
		"libringqt.so"
	 ],
	 :macosxfiles = [
		"libringqt.dylib"
	 ],
	 :ubuntudep = "qt5-default qtbase5-dev qtmultimedia5-dev"+
		      " libqt5webkit5-dev libqt5serialport5-dev qtconnectivity5-dev libqt5opengl5-dev qtdeclarative5-dev qtpositioning5-dev",
	 :fedoradep = "qt5-qtbase-devel qt5-qtmultimedia-devel "+
		      "qt5-qtwebkit-devel qt5-qtserialport-devel qt5-qtconnectivity-devel qt5-qtdeclarative-devel qt5-qtlocation-devel",
	 :macosxdep = "qt@5"
	]