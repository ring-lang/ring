aPackageInfo = [
	:name = "The WinStartupManager Package",
	:description = "Our WinStartupManager package using the Ring programming language",
	:folder = "winstartupmanager",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.3",
	:ringversion = "1.18",
	:versions = 	[
		[
			:version = "1.0.3",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "ringqt",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "stdlib",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"applications/winstartupmanager/forms/addeditentry.rform",
		"applications/winstartupmanager/forms/addeditentryController.ring",
		"applications/winstartupmanager/forms/addeditentryView.ring",
		"applications/winstartupmanager/forms/winstartupmanager.rform",
		"applications/winstartupmanager/forms/winstartupmanagerController.ring",
		"applications/winstartupmanager/forms/winstartupmanagerView.ring",
		"applications/winstartupmanager/imgs/UsageImg.jpg",
		"applications/winstartupmanager/imgs/WinStartupManager.jpg",
		"applications/winstartupmanager/libs/ring_winapi.dll",
		"applications/winstartupmanager/libs/ring_wincreg.dll",
		"applications/winstartupmanager/libs/winapi.rh",
		"applications/winstartupmanager/libs/winapi.ring",
		"applications/winstartupmanager/libs/wincreg.rh",
		"applications/winstartupmanager/libs/wincreg.ring",
		"applications/winstartupmanager/LICENSE",
		"applications/winstartupmanager/README.md",
		"applications/winstartupmanager/WinStartupManager.ring"
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
	:remotefolder = "winstartupmanager",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]