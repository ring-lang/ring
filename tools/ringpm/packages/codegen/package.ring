aPackageInfo = [
	:name = "The CodeGen Package",
	:description = "Our CodeGen package using the Ring programming language",
	:folder = "codegen",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.13",
	:ringversion = "1.19",
	:versions = 	[
		[
			:version = "1.0.13",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "",
			:version = "",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"extensions/codegen/gendoc.ring",
		"extensions/codegen/parsec.ring",
		"extensions/codegen/codegenlib.ring",
		"extensions/codegen/README.md",
		"bin/load/codegenlib.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:run = "ring main.ring",
	:setup = "",
	:remotefolder = "codegen",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]