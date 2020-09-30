aPackageInfo = [
	:name = "The Qt515Runtime Package",
	:description = "Our Qt515Runtime package using the Ring programming language",
	:folder = "qt515runtime",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.3",
	:ringversion = "1.13",
	:versions = 	[
		[
			:version = "1.0.3",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "ringzip",
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

	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/bin.zip",
		"bin/bin2.zip"
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
	:remotefolder = "qt515runtime",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]