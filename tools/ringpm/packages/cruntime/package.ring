aPackageInfo = [
	:name = "The CRuntime Package",
	:description = "Our CRuntime package using the Ring programming language",
	:folder = "cruntime",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.5",
	:ringversion = "1.27",
	:versions = 	[
		[
			:version = "1.0.5",
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
		"tools/ring2exe/libs/cruntime.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/concrt140.dll",
		"bin/msvcp140.dll",
		"bin/msvcp140_1.dll",
		"bin/msvcp140_2.dll",
		"bin/msvcp140_atomic_wait.dll",
		"bin/msvcp140_codecvt_ids.dll",
		"bin/vcamp140.dll",
		"bin/vccorlib140.dll",
		"bin/vcomp140.dll",
		"bin/vcruntime140.dll",
		"bin/api-ms-win-core-winrt-l1-1-0.dll",
		"bin/api-ms-win-core-winrt-string-l1-1-0.dll",
		"bin/libgcc_s_dw2-1.dll"
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