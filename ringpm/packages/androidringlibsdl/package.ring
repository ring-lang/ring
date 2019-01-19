aPackageInfo = [
	:name = "The AndroidRingLibSDL Package",
	:description = "Our AndroidRingLibSDL package using the Ring programming language",
	:folder = "androidringlibsdl",
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
			:name = "gameengine",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringzip",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"setup.ring",
		"uninstall.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"android/ringlibsdl.zip"
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
	:setup = "ring setup.ring",
	:windowssetup = "",
	:linuxsetup = "",
	:macossetup = "",
	:ubuntusetup = "",
	:fedorasetup = "",
	:remove = "ring uninstall.ring",
	:remotefolder = "androidringlibsdl",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]