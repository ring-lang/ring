aPackageInfo = [
	:name = "The ringodbc Package",
	:description = "Our ringodbc package using the Ring programming language",
	:folder = "ringodbc",
	:developer = "YourName",
	:email = "YourEmail",
	:license = "MIT License",
	:version = "1.0.6",
	:ringversion = "1.19",
	:versions = 	[
		[
			:version = "1.0.6",
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
		"bin/load/odbclib.ring",
		"extensions/ringodbc/buildclang.sh",
		"extensions/ringodbc/buildgcc.sh",
		"extensions/ringodbc/buildvc.bat",
		"extensions/ringodbc/buildvc_x64.bat",
		"extensions/ringodbc/odbclib.ring",
		"extensions/ringodbc/ring_vmodbc.c",
		"extensions/ringodbc/ring_vmodbc.h",
		"tools/ring2exe/libs/odbc.ring"
	],
	:windowsringfolderfiles = 	[
		"bin/ring_odbc.dll"
	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:run = "ring main.ring",
	:setup = "",
	:remotefolder = "ringodbc",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]