aPackageInfo = [
	:name = "The FindInFiles Package",
	:description = "Our FindInFiles package using the Ring programming language",
	:folder = "findinfiles",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.3",
	:ringversion = "1.19",
	:versions = 	[
		[
			:version = "1.0.3",
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
		"tools/findinfiles/findinfiles.rform",
		"tools/findinfiles/findinfilesController.ring",
		"tools/findinfiles/findinfilesView.ring",
		"tools/findinfiles/images/closeicon.jpg",
		"tools/findinfiles/images/Search.ico",
		"tools/findinfiles/images/search.jpg",
		"tools/findinfiles/images/selectfolder.jpg",
		"tools/findinfiles/README.md"
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