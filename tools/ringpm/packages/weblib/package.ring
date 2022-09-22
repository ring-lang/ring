aPackageInfo = [
	:name = "The WebLib Package",
	:description = "Our WebLib package using the Ring programming language",
	:folder = "weblib",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.6",
	:ringversion = "1.13",
	:versions = 	[
		[
			:version = "1.0.6",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "stdlib",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "weblibtools",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"bin/load/weblib.ring",
		"libraries/weblib/lib/application.ring",
		"libraries/weblib/lib/bootstrappage.ring",
		"libraries/weblib/lib/bootstrapwebpage.ring",
		"libraries/weblib/lib/functions.ring",
		"libraries/weblib/lib/globals.ring",
		"libraries/weblib/lib/html2pdf.ring",
		"libraries/weblib/lib/htmlpage.ring",
		"libraries/weblib/lib/newobjectsfunctions.ring",
		"libraries/weblib/lib/objsbase.ring",
		"libraries/weblib/lib/page.ring",
		"libraries/weblib/lib/pagebuffer.ring",
		"libraries/weblib/lib/prepare.ring",
		"libraries/weblib/lib/scriptfunctions.ring",
		"libraries/weblib/lib/stylefunctions.ring",
		"libraries/weblib/lib/template.ring",
		"libraries/weblib/lib/weblib.ring",
		"libraries/weblib/lib/webpage.ring",
		"libraries/weblib/lib/webpageelementsclasses.ring",
		"libraries/weblib/README.md",
		"libraries/weblib/run.bat",
		"libraries/weblib/test.bat",
		"libraries/weblib/weblib.ring"
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
	:remotefolder = "weblib",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]