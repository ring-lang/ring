aLibrary = [:name = :allegro ,
	 :title = "RingAllegro",
	 :windowsfiles = [
			"allegro*.dll",
			"ring_allegro.dll",
			"FLAC.dll",
			"freetype.dll",
			"jpeg62.dll",
			"libpng16.dll",
			"ogg.dll",
			"physfs.dll",
			"theoradec.dll",
			"vorbis.dll",
			"vorbisfile.dll",	
			"zlib.dll"
	 ],
	 :linuxfiles = [
		"libringallegro.so"
	 ],
	 :macosxfiles = [
		"libringallegro.dylib"
	 ],
	 :ubuntudep = "liballegro5-dev liballegro-image5-dev liballegro-ttf5-dev "+
		      "liballegro-audio5-dev liballegro-acodec5-dev "+
                      "liballegro-dialog5-dev liballegro-physfs5-dev",
	 :fedoradep = "allegro5 allegro5-devel allegro5-addon-acodec "+
		      "allegro5-addon-acodec-devel allegro5-addon-dialog "+
		      "allegro5-addon-dialog-devel allegro5-addon-image "+
		      "allegro5-addon-image-devel allegro5-addon-physfs "+
		      "allegro5-addon-physfs-devel allegro5-addon-ttf "+
		      "allegro5-addon-ttf-devel",
	 :macosxdep = "allegro"
	]