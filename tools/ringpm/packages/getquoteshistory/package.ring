aPackageInfo = [
	:name = "The GetQuotesHistory Package",
	:description = "Our GetQuotesHistory package using the Ring programming language",
	:folder = "getquoteshistory",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.2",
	:ringversion = "1.22",
	:versions = 	[
		[
			:version = "1.0.2",
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
		"applications/getquoteshistory/appicon.png",
		"applications/getquoteshistory/GetDataMusicList.txt",
		"applications/getquoteshistory/GetQuotesHistoryDraw.ring",
		"applications/getquoteshistory/GetTkr1-1500.tickers",
		"applications/getquoteshistory/MSFT-Snap1.png",
		"applications/getquoteshistory/README.md",
		"applications/getquoteshistory/stock.bmp",
		"applications/getquoteshistory/stock.jpg",
		"applications/getquoteshistory/stock.mp3",
		"applications/getquoteshistory/T1-SP500.tickers",
		"applications/getquoteshistory/T2-NASD100.tickers"
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