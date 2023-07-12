aPackageInfo = [
	:name = "The RingBeep Package",
	:description = "Our RingBeep package using the Ring programming language",
	:folder = "ringbeep",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.2",
	:ringversion = "1.18",
	:versions = 	[
		[
			:version = "1.0.2",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "codegen",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[

	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"extensions/ringbeep/buildvc.bat",
		"extensions/ringbeep/gencode.bat",
		"extensions/ringbeep/README.md",
		"extensions/ringbeep/ringbeep.c",
		"extensions/ringbeep/ringbeep.cf",
		"extensions/ringbeep/ringbeep.dll",
		"extensions/ringbeep/ringbeep.exp",
		"extensions/ringbeep/ringbeep.ilk",
		"extensions/ringbeep/ringbeep.lib",
		"extensions/ringbeep/ringbeep.pdb",
		"extensions/ringbeep/test.ring"
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
	:remotefolder = "ringbeep",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]