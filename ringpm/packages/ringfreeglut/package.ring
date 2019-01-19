aPackageInfo = [
	:name = "The RingFreeGLUT Package",
	:description = "Our RingFreeGLUT package using the Ring programming language",
	:folder = "ringfreeglut",
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
		"bin/freeglut.ring",
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
		"extensions/ringfreeglut/tests/cube.ring",
		"extensions/ringfreeglut/tests/test.ring",
		"extensions/ringfreeglut/tests/test10.ring",
		"extensions/ringfreeglut/tests/test11.ring",
		"extensions/ringfreeglut/tests/test12.ring",
		"extensions/ringfreeglut/tests/test13.ring",
		"extensions/ringfreeglut/tests/test14.ring",
		"extensions/ringfreeglut/tests/test15.ring",
		"extensions/ringfreeglut/tests/test16.ring",
		"extensions/ringfreeglut/tests/test2.ring",
		"extensions/ringfreeglut/tests/test3.ring",
		"extensions/ringfreeglut/tests/test4.ring",
		"extensions/ringfreeglut/tests/test5.ring",
		"extensions/ringfreeglut/tests/test6.ring",
		"extensions/ringfreeglut/tests/test7.ring",
		"extensions/ringfreeglut/tests/test8.ring",
		"extensions/ringfreeglut/tests/test9.ring",
		"ring2exe/libs/freeglut.ring"
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