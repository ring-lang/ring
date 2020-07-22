aPackageInfo = [
	:name = "The FifteenPuzzle Package",
	:description = "Our FifteenPuzzle package using the Ring programming language",
	:folder = "fifteenpuzzle",
	:developer = "msfclipper@yahoo.com",
	:email = "Mahmoud Fayed",
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
		"applications/fifteenpuzzle/CalmoSoftFifteenPuzzleGame.ring",
		"applications/fifteenpuzzle/CalmoSoftPuzzle.ring",
		"applications/fifteenpuzzle/README.md"
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
	:remotefolder = "fifteenpuzzle",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]