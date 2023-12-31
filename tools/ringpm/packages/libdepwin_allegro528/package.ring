aPackageInfo = [
	:name = "The LibDepWin_Allegro528 Package",
	:description = "Our LibDepWin_Allegro528 package using the Ring programming language",
	:folder = "libdepwin_allegro528",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.1",
	:ringversion = "1.19",
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
		"extensions/libdepwin/Allegro5.2.8.zip"
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
	:windowsremove = "",
	:linuxremove = "",
	:macosremove = "",
	:ubunturemove = "",
	:fedoraremove = "",
	:remotefolder = "libdepwin_allegro528",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]