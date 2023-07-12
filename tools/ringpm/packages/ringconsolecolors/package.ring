aPackageInfo = [
	:name = "The RingConsoleColors Package",
	:description = "Our RingConsoleColors package using the Ring programming language",
	:folder = "ringconsolecolors",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.4",
	:ringversion = "1.18",
	:versions = 	[
		[
			:version = "1.0.4",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "codegen",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"bin/load/consolecolors.ring",
		"extensions/ringconsolecolors/build.bat",
		"extensions/ringconsolecolors/buildclang.sh",
		"extensions/ringconsolecolors/buildgcc.sh",
		"extensions/ringconsolecolors/buildvc.bat",
		"extensions/ringconsolecolors/console-colors.c",
		"extensions/ringconsolecolors/console-colors.h",
		"extensions/ringconsolecolors/consolecolors.cf",
		"extensions/ringconsolecolors/consolecolors.ring",
		"extensions/ringconsolecolors/document.bat",
		"extensions/ringconsolecolors/example.c",
		"extensions/ringconsolecolors/example.ring",
		"extensions/ringconsolecolors/gencode.bat",
		"extensions/ringconsolecolors/gencode.sh",
		"extensions/ringconsolecolors/gendoc.ring",
		"extensions/ringconsolecolors/ring_consolecolors.c",
		"extensions/ringconsolecolors/ring_consolecolors.rh",
		"tools/ring2exe/libs/consolecolors.ring"
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
	:remotefolder = "ringconsolecolors",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]