aPackageInfo = [
	:name = "The RingMySQL Package",
	:description = "Our RingMySQL package using the Ring programming language",
	:folder = "ringmysql",
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
		"bin/mysqllib.ring",
		"extensions/ringmysql/buildclang.sh",
		"extensions/ringmysql/buildgcc.sh",
		"extensions/ringmysql/buildgccfedora.sh",
		"extensions/ringmysql/buildvc.bat",
		"extensions/ringmysql/mysqllib.ring",
		"extensions/ringmysql/ring_vmmysql.c",
		"extensions/ringmysql/ring_vmmysql.h",
		"ring2exe/libs/mysql.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/libmysql.dll",
		"bin/ring_mysql.dll"
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
	:remotefolder = "ringmysql",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]