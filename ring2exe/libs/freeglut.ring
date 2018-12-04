aLibrary = [:name = :freeglut ,
	 :title = "RingFreeGLUT",
	 :windowsfiles = [
			"ring_freeglut.dll",
			"freeglut.dll",
			"glew32.dll"
	 ],
	 :linuxfiles = [
		"libring_freeglut.so"
	 ],
	 :macosxfiles = [
		"libring_freeglut.dylib"
	 ],
	 :ubuntudep = "freeglut3-dev",
	 :fedoradep = "freeglut freeglut-devel glew-devel",
	 :macosxdep = "glew" 
	]