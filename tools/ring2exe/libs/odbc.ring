aLibrary = [:name = :odbc ,
	 :title = "RingODBC",
	 :windowsfiles = [
			"ring_odbc.dll"
	 ],
	 :linuxfiles = [
		"libring_odbc.so"
	 ],
	 :macosxfiles = [
		"libring_odbc.dylib"
	 ],
	 :ubuntudep = "unixodbc unixodbc-dev",
	 :fedoradep = "unixODBC unixODBC-devel",
	 :macosxdep = "unixodbc" 
	]