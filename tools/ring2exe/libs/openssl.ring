aLibrary = [:name = :openssl ,
	 :title = "RingOpenSSL",
	 :windowsfiles = [
			"ring_openssl.dll",
			"ssleay32.dll",
			"libeay32.dll"
	 ],
	 :linuxfiles = [
		"libring_openssl.so"
	 ],
	 :macosxfiles = [
		"libring_openssl.dylib"
	 ],
	 :ubuntudep = "libssl-dev",
	 :fedoradep = "openssl",
	 :macosxdep = "openssl" 
	]