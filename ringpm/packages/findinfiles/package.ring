aPackageInfo = [
	:name = "The FindInFiles Package",
	:description = "Our FindInFiles package using the Ring programming language",
	:folder = "findinfiles",
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
			:name = "stdlib",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringqt",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"applications/findinfiles/findinfiles.rform",
		"applications/findinfiles/findinfilescontroller.pwct",
		"applications/findinfiles/findinfilesController.ring",
		"applications/findinfiles/findinfilesView.ring",
		"applications/findinfiles/images/closeicon.jpg",
		"applications/findinfiles/images/Search.ico",
		"applications/findinfiles/images/search.jpg",
		"applications/findinfiles/images/selectfolder.jpg",
		"applications/findinfiles/README.md"
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
	:remotefolder = "findinfiles",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]