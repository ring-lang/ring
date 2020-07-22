aPackageInfo = [
	:name = "The Qt512QMLRuntime Package",
	:description = "Our Qt512QMLRuntime package using the Ring programming language",
	:folder = "qt512qmlruntime",
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
		"bin/qml.zip"
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
	:remotefolder = "qt512qmlruntime",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]