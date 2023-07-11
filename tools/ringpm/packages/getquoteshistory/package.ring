aPackageInfo = [
	:name = "The GetQuotesHistory Package",
	:description = "Our GetQuotesHistory package using the Ring programming language",
	:folder = "getquoteshistory",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.1",
	:ringversion = "1.18",
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
		"applications/getquoteshistory/GetQuotesHistoryDraw-v1.3.ring",
		"applications/getquoteshistory/GetTkr1-1500.tickers",
		"applications/getquoteshistory/appicon.png",
		"applications/getquoteshistory/README.md"
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
	:remotefolder = "getquoteshistory",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]