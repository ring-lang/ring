aPackageInfo = [
	:name = "The RingREPL Package",
	:description = "Our RingREPL package using the Ring programming language",
	:folder = "ringrepl",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.6",
	:ringversion = "1.20",
	:versions = 	[
		[
			:version = "1.0.6",
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
		"bin/ringrepl.exe",
		"tools/ringrepl/build.bat",
		"tools/ringrepl/build.sh",
		"tools/ringrepl/ringrepl.ring",
		"tools/ringrepl/ringreplw.ring",
		"tools/ringrepl/README.md",
		"tools/ringrepl/replwscript.ring",
		"tools/ringrepl/source.png"
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
	:remotefolder = "ringrepl",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]