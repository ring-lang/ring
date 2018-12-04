aLibrary = [:name = :opengl ,
	 :title = "RingOpenGL",
	 :windowsfiles = [
			"ring_opengl*.dll"
	 ],
	 :linuxfiles = [
		"libring_opengl21.so"
	 ],
	 :macosxfiles = [
		"libring_opengl21.dylib"
	 ],
	 :ubuntudep = "mesa-common-dev",
	 :fedoradep = "mesa-libGLU-devel",
	 :macosxdep = ""  
	]