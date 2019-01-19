aPackageInfo = [
	:name = "The CRuntime Package",
	:description = "Our CRuntime package using the Ring programming language",
	:folder = "cruntime",
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
		"ring2exe/libs/cruntime.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/libgcc_s_dw2-1.dll",
		"bin/msvcp120.dll",
		"bin/msvcp120d.dll",
		"bin/msvcp120_clr0400.dll",
		"bin/msvcr100.dll",
		"bin/msvcr120.dll",
		"bin/msvcr120d.dll",
		"bin/msvcr120_clr0400.dll"
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
	:remotefolder = "cruntime",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]