aLibrary = [:name = :qt ,
	 :title = "RingQt",
	 :windowsfiles = [
		"Qt5*.dll",
		"ringqt.dll",
		"icudt54.dll",
		"icuin54.dll",
		"icuuc54.dll",
		"libEGL.dll",
		'"libstdc++-6.dll"',
		'"libwinpthread-1.dll"',
		"libGLESv2.dll",
		"D3Dcompiler_47.dll"
	 ] ,
	 :windowsfolders = [
		:audio,
		:bearer,
		:iconengines,
		:imageformats,
		:mediaservice,
		:platforms,
		:playlistformats,
		:position,
		:printsupport,
		:sensorgestures,
		:sqldrivers,
		:translations
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
	 :macosxdep = "qt"
	]