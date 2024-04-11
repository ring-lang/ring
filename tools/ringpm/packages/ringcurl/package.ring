aPackageInfo = [
	:name = "The RingCurl Package",
	:description = "Our RingCurl package using the Ring programming language",
	:folder = "ringcurl",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.11",
	:ringversion = "1.20",
	:versions = 	[
		[
			:version = "1.0.11",
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
		"bin/load/libcurl.ring",
		"tools/ring2exe/libs/libcurl.ring",
		"extensions/ringcurl/buildclang.sh",
		"extensions/ringcurl/buildgcc.sh",
		"extensions/ringcurl/buildvc.bat",
		"extensions/ringcurl/buildvc_x64.bat",
		"extensions/ringcurl/document.bat",
		"extensions/ringcurl/gencode.bat",
		"extensions/ringcurl/gencode.sh",
		"extensions/ringcurl/gendoc.ring",
		"extensions/ringcurl/libcurl.cf",
		"extensions/ringcurl/libcurl.ring",
		"extensions/ringcurl/ring_libcurl.c",
		"extensions/ringcurl/ring_libcurl_x64.c",
		"extensions/ringcurl/ring_libcurl.rh"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/ring_libcurl.dll"
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
	:remotefolder = "ringcurl",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]