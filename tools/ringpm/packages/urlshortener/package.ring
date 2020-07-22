aPackageInfo = [
	:name = "The URLShortener Package",
	:description = "Our URLShortener package using the Ring programming language",
	:folder = "urlshortener",
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
		"applications/urlshortener/GoogleAPIHistory.db",
		"applications/urlshortener/GoogleAPIKey.xml",
		"applications/urlshortener/link.png",
		"applications/urlshortener/README.md",
		"applications/urlshortener/urlshortenerdeclarations.ring",
		"applications/urlshortener/urlshortenereventfunctions.ring",
		"applications/urlshortener/urlshortenerfunctions.ring",
		"applications/urlshortener/urlshortenermain.ring",
		"applications/urlshortener/urlshortenersqlbuilderclass.ring",
		"applications/urlshortener/urlshortenersqliteclass.ring",
		"applications/urlshortener/urlshortenerxmlhandlers.ring"
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
	:remotefolder = "urlshortener",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]