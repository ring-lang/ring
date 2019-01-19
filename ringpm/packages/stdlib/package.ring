aPackageInfo = [
	:name = "The StdLib Package",
	:description = "Our StdLib package using the Ring programming language",
	:folder = "stdlib",
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
		"bin/stdlib.ring",
		"bin/stdlibcore.ring",
		"ringlibs/stdlib/myfile.txt",
		"ringlibs/stdlib/README.md",
		"ringlibs/stdlib/stdbase.ring",
		"ringlibs/stdlib/stdclasses.ring",
		"ringlibs/stdlib/stdconversion.ring",
		"ringlibs/stdlib/stddatatype.ring",
		"ringlibs/stdlib/stddatetime.ring",
		"ringlibs/stdlib/stddebug.ring",
		"ringlibs/stdlib/stdfile.ring",
		"ringlibs/stdlib/stdfunctions.ring",
		"ringlibs/stdlib/stdhashtable.ring",
		"ringlibs/stdlib/stdinternet.ring",
		"ringlibs/stdlib/stdlib.rh",
		"ringlibs/stdlib/stdlib.ring",
		"ringlibs/stdlib/stdlibcore.ring",
		"ringlibs/stdlib/stdlist.ring",
		"ringlibs/stdlib/stdmath.ring",
		"ringlibs/stdlib/stdmysql.ring",
		"ringlibs/stdlib/stdodbc.ring",
		"ringlibs/stdlib/stdpostgresql.ring",
		"ringlibs/stdlib/stdqueue.ring",
		"ringlibs/stdlib/stdsecurity.ring",
		"ringlibs/stdlib/stdsqlite.ring",
		"ringlibs/stdlib/stdstack.ring",
		"ringlibs/stdlib/stdstring.ring",
		"ringlibs/stdlib/stdsystem.ring",
		"ringlibs/stdlib/stdtree.ring",
		"ringlibs/stdlib/test.mdb",
		"ringlibs/stdlib/test.ring",
		"ringlibs/stdlib/test.txt",
		"ringlibs/stdlib/usestdlibcore.ring"
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