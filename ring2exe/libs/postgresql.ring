aLibrary = [:name = :postgresql ,
	 :title = "RingPostgreSQL",
	 :windowsfiles = [
			"libeay32.dll",
			"libiconv-2.dll",
			"libintl-8.dll",
			"libpq.dll",
			"ssleay32.dll",
			"ring_pgsql.dll"
	 ],
	 :linuxfiles = [
		"libring_pgsql.so"
	 ],
	 :macosxfiles = [
		"libring_pgsql.dylib"
	 ],
	 :ubuntudep = "libpq-dev",
	 :fedoradep = "libpqxx-devel",
	 :macosxdep = "libpq"
	]