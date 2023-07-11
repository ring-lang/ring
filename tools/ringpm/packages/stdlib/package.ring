aPackageInfo = [
	:name = "The StdLib Package",
	:description = "Our StdLib package using the Ring programming language",
	:folder = "stdlib",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.14",
	:ringversion = "1.18",
	:versions = 	[
		[
			:version = "1.0.14",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "ringopenssl",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringcurl",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "internetlib",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringodbc",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringsqlite",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringmysql",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringpostgresql",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"bin/load/stdlib.ring",
		"bin/load/stdlibcore.ring",
		"libraries/stdlib/myfile.txt",
		"libraries/stdlib/README.md",
		"libraries/stdlib/stdbase.ring",
		"libraries/stdlib/stdclasses.ring",
		"libraries/stdlib/stdconversion.ring",
		"libraries/stdlib/stddatatype.ring",
		"libraries/stdlib/stddatetime.ring",
		"libraries/stdlib/stddebug.ring",
		"libraries/stdlib/stdfile.ring",
		"libraries/stdlib/stdfunctions.ring",
		"libraries/stdlib/stdhashtable.ring",
		"libraries/stdlib/stdinternet.ring",
		"libraries/stdlib/stdlib.rh",
		"libraries/stdlib/stdlib.ring",
		"libraries/stdlib/stdlibcore.ring",
		"libraries/stdlib/stdlist.ring",
		"libraries/stdlib/stdmath.ring",
		"libraries/stdlib/stdmysql.ring",
		"libraries/stdlib/stdodbc.ring",
		"libraries/stdlib/stdpostgresql.ring",
		"libraries/stdlib/stdqueue.ring",
		"libraries/stdlib/stdsecurity.ring",
		"libraries/stdlib/stdsqlite.ring",
		"libraries/stdlib/stdstack.ring",
		"libraries/stdlib/stdstring.ring",
		"libraries/stdlib/stdsystem.ring",
		"libraries/stdlib/stdtree.ring",
		"libraries/stdlib/test.mdb",
		"libraries/stdlib/test.ring",
		"libraries/stdlib/test.txt",
		"libraries/stdlib/usestdlibcore.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[

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
	:remotefolder = "stdlib",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]