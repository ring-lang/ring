aLibrary = [:name = :libuv ,
	 :title = "RingLibuv",
	 :windowsfiles = [
			"libuv.dll",
			"ring_uv.dll"
	 ],
	 :linuxfiles = [
		"libring_uv.so"
	 ],
	 :macosxfiles = [
		"libring_uv.dylib"
	 ],
	 :ubuntudep = "",
	 :fedoradep = "",
	 :macosxdep = "libuv"  
	]