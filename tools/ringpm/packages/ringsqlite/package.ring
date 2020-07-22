aPackageInfo = [
	:name = "The RingSQLite Package",
	:description = "Our RingSQLite package using the Ring programming language",
	:folder = "ringsqlite",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.0",
	:ringversion = "1.10",
	:versions = 	[
		[
			:version = "1.0.0",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "",
			:version = "",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"bin/sqlitelib.ring",
		"extensions/ringsqlite/buildclang.sh",
		"extensions/ringsqlite/buildgcc.sh",
		"extensions/ringsqlite/buildvc.bat",
		"extensions/ringsqlite/ring_vmsqlite.c",
		"extensions/ringsqlite/ring_vmsqlite.h",
		"extensions/ringsqlite/sqlite3.c",
		"extensions/ringsqlite/sqlite3.h",
		"extensions/ringsqlite/sqlitelib.ring",
		"ring2exe/libs/sqlite.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/ring_sqlite.dll"
	],
	:linuxringfolderfiles = 	[

	],
	:macosringfolderfiles = 	[

	],
	:run = "ring main.ring",
	:setup = "",
	:windowssetup = "",
	:linuxsetup = "",
	:macossetup = "",
	:ubuntusetup = "",
	:fedorasetup = "",
	:remotefolder = "ringsqlite",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]