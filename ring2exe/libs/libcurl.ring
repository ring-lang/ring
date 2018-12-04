aLibrary = [:name = :libcurl ,
	 :title = "RingLibCurl",
	 :windowsfiles = [
			"ring_libcurl.dll",
			"ring_internet.dll",
			"libcurl.dll"
	 ],
	 :linuxfiles = [
		"libring_libcurl.so"
	 ],
	 :macosxfiles = [
		"libring_libcurl.dylib"
	 ],
	 :ubuntudep = "libcurl4-gnutls-dev",
	 :fedoradep = "libcurl libcurl-devel",
	 :macosxdep = ""
	]