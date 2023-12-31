aPackageInfo = [
	:name = "The RingQtRuntime Package",
	:description = "Our RingQtRuntime package using the Ring programming language",
	:folder = "ringqtruntime",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.23",
	:ringversion = "1.19",
	:versions = 	[
		[
			:version = "1.0.23",
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
		"bin/load/guilib.ring",
		"bin/load/lightguilib.ring",
		"tools/ring2exe/libs/qt.ring",
		"tools/ring2exe/libs/lightguilib.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/ringqt.dll",
		"bin/ringqt_core.dll",
		"bin/ringqt_light.dll"
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