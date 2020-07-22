aLibrary = [:name = :mysql ,
	 :title = "RingMySQL",
	 :windowsfiles = [
			"ring_mysql.dll",
			"libmysql.dll"
	 ],
	 :linuxfiles = [
		"libring_mysql.so"
	 ],
	 :macosxfiles = [
		"libring_mysql.dylib"
	 ],
	 :ubuntudep = "libmysqlclient-dev",
	 :fedoradep = "mysql-devel",
	 :macosxdep = "mysql-connector-c"
	]