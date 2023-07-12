aPackageInfo = [
	:name = "The RingFreeGLUT Package",
	:description = "Our RingFreeGLUT package using the Ring programming language",
	:folder = "ringfreeglut",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.11",
	:ringversion = "1.18",
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
		"bin/load/freeglut.ring",
		"extensions/ringfreeglut/buildclang.sh",
		"extensions/ringfreeglut/buildgcc.sh",
		"extensions/ringfreeglut/buildvc.bat",
		"extensions/ringfreeglut/document.bat",
		"extensions/ringfreeglut/freeglut.cf",
		"extensions/ringfreeglut/freeglut.ring",
		"extensions/ringfreeglut/gencode.bat",
		"extensions/ringfreeglut/gencode.sh",
		"extensions/ringfreeglut/gendoc.ring",
		"extensions/ringfreeglut/ring_freeglut.c",
		"extensions/ringfreeglut/ring_freeglut.rh",
		"tools/ring2exe/libs/freeglut.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/freeglut.dll",
		"bin/glew32.dll",
		"bin/ring_freeglut.dll"
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
	:remotefolder = "ringfreeglut",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]