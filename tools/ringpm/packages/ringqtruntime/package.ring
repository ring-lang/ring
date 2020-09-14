aPackageInfo = [
	:name = "The RingQtRuntime Package",
	:description = "Our RingQtRuntime package using the Ring programming language",
	:folder = "ringqtruntime",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.5",
	:ringversion = "1.13",
	:versions = 	[
		[
			:version = "1.0.5",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "qt515runtime",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"bin/load/guilib.ring",
		"libraries/guilib/classes/ring_qt.ring",
		"libraries/guilib/constants/qt.rh",
		"libraries/guilib/guilib.ring",
		"libraries/guilib/modernlib/appclass.ring",
		"libraries/guilib/modernlib/comboboxclass.ring",
		"libraries/guilib/modernlib/commonfunctions.ring",
		"libraries/guilib/modernlib/guilibclass.ring",
		"libraries/guilib/modernlib/listwidgetclass.ring",
		"libraries/guilib/modernlib/modernlib.ring",
		"libraries/guilib/modernlib/newguiclasses.ring",
		"libraries/guilib/modernlib/tablewidgetclass.ring",
		"libraries/guilib/modernlib/treewidgetclass.ring",
		"libraries/guilib/mvc/controllerparent.ring",
		"libraries/guilib/mvc/viewparent.ring",
		"libraries/guilib/webassembly/webassembly.ring",
		"tools/ring2exe/libs/qt.ring"
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
	:setup = "",
	:windowssetup = "",
	:linuxsetup = "",
	:macossetup = "",
	:ubuntusetup = "",
	:fedorasetup = "",
	:remotefolder = "ringqtruntime",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]