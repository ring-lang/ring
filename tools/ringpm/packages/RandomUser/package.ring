aPackageInfo = [
	:name = "The RandomUser Application Package",
	:description = "Our RandomUser Application package using the Ring programming language",
	:folder = "randomuser",
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
			:name = "ringzip",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringqt",
			:version = "1.0",
			:providerusername = "ringpackages"
		],
		[
			:name = "stdlib",
			:version = "1.0",
			:providerusername = "ringpackages"
		],
		[
			:name = "internetlib",
			:version = "1.0",
			:providerusername = "ringpackages"
		],
		[
			:name = "jsonlib",
			:version = "1.0",
			:providerusername = "ringpackages"
		],
		[
			:name = "weblib",
			:version = "1.0",
			:providerusername = "ringpackages"
		],
		[
			:name = "httplib",
			:version = "1.0",
			:providerusername = "ringpackages"
		],
		[
			:name = "ringraylib",
			:version = "1.0",
			:providerusername = "ringpackages"
		],
		[
			:name = "gameengine",
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
		"applications/randomuser.zip"
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
	:remotefolder = "randomuser",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]