aPackageInfo = [
	:name = "The RingQtRuntime Package",
	:description = "Our RingQtRuntime package using the Ring programming language",
	:folder = "ringqtruntime",
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
			:name = "qt55runtime",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"bin/guilib.ring",
		"extensions/ringqt/guilib/guilib.ring",
		"extensions/ringqt/guilib/modernlib/appclass.ring",
		"extensions/ringqt/guilib/modernlib/comboboxclass.ring",
		"extensions/ringqt/guilib/modernlib/commonfunctions.ring",
		"extensions/ringqt/guilib/modernlib/guilibclass.ring",
		"extensions/ringqt/guilib/modernlib/listwidgetclass.ring",
		"extensions/ringqt/guilib/modernlib/modernlib.ring",
		"extensions/ringqt/guilib/modernlib/newguiclasses.ring",
		"extensions/ringqt/guilib/modernlib/tablewidgetclass.ring",
		"extensions/ringqt/guilib/modernlib/treewidgetclass.ring",
		"extensions/ringqt/guilib/objectslib/objects.ring",
		"extensions/ringqt/guilib/objectslib/objectslib.ring",
		"extensions/ringqt/guilib/objectslib/subwindows.ring",
		"extensions/ringqt/guilib/qt.rh",
		"extensions/ringqt/guilib/ring_qt.ring",
		"ring2exe/libs/qt.ring"
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