aPackageInfo = [
	:name = "The QtClassConverter Package",
	:description = "Our QtClassConverter package using the Ring programming language",
	:folder = "qtclassconverter",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.1",
	:ringversion = "1.13",
	:versions = 	[
		[
			:version = "1.0.1",
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
		"extensions/ringqt/converter/app/QtClassConverter.rform",
		"extensions/ringqt/converter/app/QtClassConverterController.ring",
		"extensions/ringqt/converter/app/QtClassConverterView.ring",
		"extensions/ringqt/converter/images/01.jpg",
		"extensions/ringqt/converter/images/02.jpg",
		"extensions/ringqt/converter/images/03.jpg",
		"extensions/ringqt/converter/images/04.jpg",
		"extensions/ringqt/converter/images/05.jpg",
		"extensions/ringqt/converter/images/06.jpg",
		"extensions/ringqt/converter/images/07.jpg",
		"extensions/ringqt/converter/QtClassConverter.ring",
		"extensions/ringqt/converter/README.md",
		"extensions/ringqt/converter/start.bat"
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
	:remove = "",
	:windowsremove = "",
	:linuxremove = "",
	:macosremove = "",
	:ubunturemove = "",
	:fedoraremove = "",
	:remotefolder = "qtclassconverter",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]