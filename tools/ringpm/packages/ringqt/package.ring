aPackageInfo = [
	:name = "The RingQt Package",
	:description = "Our RingQt package using the Ring programming language",
	:folder = "ringqt",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.34",
	:ringversion = "1.20",
	:versions = 	[
		[
			:version = "1.0.34",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "ringzip",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "codegen",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringqtruntime",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "qt515runtime",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "qt515qmlruntime",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md",
		"setup.ring",
		"uninstall.ring"
	],
	:ringfolderfiles = 	[
		"bin/load/guilib.ring",
		"bin/load/lightguilib.ring",
		"tools/ring2exe/libs/qt.ring",
		"tools/ring2exe/libs/lightguilib.ring",
		"extensions/ringqt.zip"
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
	:setup = "ring setup.ring",
	:remove = "ring uninstall.ring",
	:windowssetup = "",
	:linuxsetup = "",
	:macossetup = "",
	:ubuntusetup = "",
	:fedorasetup = "",
	:remotefolder = "ringqt",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]