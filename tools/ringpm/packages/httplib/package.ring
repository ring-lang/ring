aPackageInfo = [
	:name = "The HTTPLib Package",
	:description = "Our RingHTTPLib package using the Ring programming language",
	:folder = "httplib",
	:developer = "",
	:email = "",
	:license = "MIT License",
	:version = "1.0.10",
	:ringversion = "1.20",
	:versions = 	[
		[
			:version = "1.0.10",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "weblib",
			:version = "1.0",
			:providerusername = "ringpackages"
		]
	],
	:files = 	[
		"main.ring",
		"setup.ring",
		"uninstall.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"bin/load/httplib.ring",
		"bin/ring_httplib.dll",
		"tools/ring2exe/libs/httplib.ring",
		"extensions/ringhttplib.zip",
		"samples/UsingHTTPLib.zip"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:ubuntufiles = 	[

	],
	:fedorafiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[

	],
	:linuxringfolderfiles = 	[

	],
	:ubunturingfolderfiles = 	[

	],
	:fedoraringfolderfiles = 	[

	],
	:macosringfolderfiles = 	[

	],
	:run = "ring main.ring",
	:windowsrun = "",
	:linuxrun = "",
	:macosrun = "",
	:ubunturun = "",
	:fedorarun = "",
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
	:remotefolder = "httplib",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]