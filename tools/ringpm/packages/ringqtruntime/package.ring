aPackageInfo = [
	:name = "The RingQtRuntime Package",
	:description = "Our RingQtRuntime package using the Ring programming language",
	:folder = "ringqtruntime",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.13",
	:ringversion = "1.13",
	:versions = 	[
		[
			:version = "1.0.13",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "guilib",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "objectslib",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "qt515runtime",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"tools/ring2exe/libs/qt.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/ringqt.dll"
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
	:remotefolder = "ringqtruntime",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]