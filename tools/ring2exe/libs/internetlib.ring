aLibrary = [:name = :internetlib ,
	 :title = "RingInternetLib",
	 :windowsfiles = [
			"ring_internet.dll",
			"ring_libcurl.dll",
			"libcurl.dll"
	 ],
	 :linuxfiles = [
		"libring_internet.so",
		"libring_libcurl.so"
	 ],
	 :macosxfiles = [
		"libring_internet.dylib",
		"libring_libcurl.dylib"
	 ],
	 :ubuntudep = "libcurl4-gnutls-dev",
	 :fedoradep = "libcurl libcurl-devel",
	 :macosxdep = ""
	]