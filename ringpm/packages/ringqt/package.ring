aPackageInfo = [
	:name = "The RingQt Package",
	:description = "Our RingQt package using the Ring programming language",
	:folder = "ringqt",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.1",
	:ringversion = "1.10",
	:versions = 	[
		[
			:version = "1.0.1",
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
			:name = "qt55runtime",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "qt55qmlruntime",
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
		"bin/guilib.ring",
		"ring2exe/libs/qt.ring",
		"extensions/ringqt.zip"
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