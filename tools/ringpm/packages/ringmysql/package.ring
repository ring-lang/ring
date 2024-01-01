aPackageInfo = [
	:name = "The RingMySQL Package",
	:description = "Our RingMySQL package using the Ring programming language",
	:folder = "ringmysql",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.7",
	:ringversion = "1.19",
	:versions = 	[
		[
			:version = "1.0.7",
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
		"bin/load/mysqllib.ring",
		"extensions/ringmysql/buildclang.sh",
		"extensions/ringmysql/buildgcc.sh",
		"extensions/ringmysql/buildgccfedora.sh",
		"extensions/ringmysql/buildvc.bat",
		"extensions/ringmysql/buildvc_x64.bat",
		"extensions/ringmysql/mysqllib.ring",
		"extensions/ringmysql/ring_vmmysql.c",
		"extensions/ringmysql/ring_vmmysql.h",
		"tools/ring2exe/libs/mysql.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/libmysql.dll",
		"bin/ring_mysql.dll",
		"bin/libssl-3-x64.dll",
		"bin/libssl-3-x64"
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