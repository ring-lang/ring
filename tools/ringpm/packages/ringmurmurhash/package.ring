aPackageInfo = [
	:name = "The RingMurmurHash Package",
	:description = "Our RingMurmurHash package using the Ring programming language",
	:folder = "ringmurmurhash",
	:developer = "Hassan Ahmad",
	:email = "hsn@outlook.hu",
	:license = "MIT License",
	:version = "1.0.6",
	:ringversion = "1.19",
	:versions = 	[
		[
			:version = "1.0.6",
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
		"bin/load/murmurhashlib.ring",
		"extensions/ringmurmurhash/buildclang.sh",
		"extensions/ringmurmurhash/buildgcc.sh",
		"extensions/ringmurmurhash/buildvc.bat",
		"extensions/ringmurmurhash/buildvc_x64.bat",
		"extensions/ringmurmurhash/libmurmurhash/MurmurHash1.c",
		"extensions/ringmurmurhash/libmurmurhash/MurmurHash1.h",
		"extensions/ringmurmurhash/libmurmurhash/MurmurHash2.c",
		"extensions/ringmurmurhash/libmurmurhash/MurmurHash2.h",
		"extensions/ringmurmurhash/libmurmurhash/MurmurHash3.c",
		"extensions/ringmurmurhash/libmurmurhash/MurmurHash3.h",
		"extensions/ringmurmurhash/libmurmurhash/README.md",
		"extensions/ringmurmurhash/murmurhashlib.ring",
		"extensions/ringmurmurhash/README.md",
		"extensions/ringmurmurhash/ring_murmurhash.c",
		"extensions/ringmurmurhash/ring_murmurhash.h",
		"tools/ring2exe/libs/murmurhash.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/ring_murmurhash.dll"
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
	:remotefolder = "ringmurmurhash",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]