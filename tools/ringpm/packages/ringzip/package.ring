aPackageInfo = [
	:name = "The RingZip Package",
	:description = "Our RingZip package using the Ring programming language",
	:folder = "ringzip",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.5",
	:ringversion = "1.18",
	:versions = 	[
		[
			:version = "1.0.5",
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
		"bin/load/ziplib.ring",
		"extensions/ringzip/buildclang.sh",
		"extensions/ringzip/buildgcc.sh",
		"extensions/ringzip/buildvc.bat",
		"extensions/ringzip/document.bat",
		"extensions/ringzip/gencode.bat",
		"extensions/ringzip/gencode.sh",
		"extensions/ringzip/gendoc.ring",
		"extensions/ringzip/libzip.cf",
		"extensions/ringzip/miniz.h",
		"extensions/ringzip/ring_libzip.c",
		"extensions/ringzip/ring_libzip.rh",
		"extensions/ringzip/t1.ring",
		"extensions/ringzip/t10.ring",
		"extensions/ringzip/t11.ring",
		"extensions/ringzip/t12.ring",
		"extensions/ringzip/t2.ring",
		"extensions/ringzip/t3.ring",
		"extensions/ringzip/t4.ring",
		"extensions/ringzip/t5.ring",
		"extensions/ringzip/t6.ring",
		"extensions/ringzip/t7.ring",
		"extensions/ringzip/t8.ring",
		"extensions/ringzip/t9.ring",
		"extensions/ringzip/test.c",
		"extensions/ringzip/zip.c",
		"extensions/ringzip/zip.h",
		"extensions/ringzip/ziplib.ring",
		"tools/ring2exe/libs/libzip.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/ring_libzip.dll"
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
	:remotefolder = "ringzip",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]