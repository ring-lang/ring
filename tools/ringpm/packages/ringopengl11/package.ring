aPackageInfo = [
	:name = "The RingOpenGL11 Package",
	:description = "Our RingOpenGL11 package using the Ring programming language",
	:folder = "ringopengl11",
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
		"bin/load/opengl11lib.ring",
		"extensions/ringopengl/opengl11/buildclang.sh",
		"extensions/ringopengl/opengl11/buildgcc.sh",
		"extensions/ringopengl/opengl11/buildvc.bat",
		"extensions/ringopengl/opengl11/document.bat",
		"extensions/ringopengl/opengl11/gencode.bat",
		"extensions/ringopengl/opengl11/gencode.sh",
		"extensions/ringopengl/opengl11/gendoc.ring",
		"extensions/ringopengl/opengl11/opengl11.cf",
		"extensions/ringopengl/opengl11/opengl11lib.ring",
		"extensions/ringopengl/opengl11/ring_opengl11.c",
		"extensions/ringopengl/opengl11/ring_opengl11.rh",
		"extensions/ringopengl/opengl11/test.ring",
		"tools/ring2exe/libs/opengl11.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/ring_opengl11.dll"
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
	:remotefolder = "ringopengl11",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]