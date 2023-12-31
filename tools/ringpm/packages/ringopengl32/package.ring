aPackageInfo = [
	:name = "The RingOpenGL32 Package",
	:description = "Our RingOpenGL32 package using the Ring programming language",
	:folder = "ringopengl32",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
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
		"bin/load/opengl32lib.ring",
		"extensions/ringopengl/opengl32/buildclang.sh",
		"extensions/ringopengl/opengl32/buildgcc.sh",
		"extensions/ringopengl/opengl32/buildvc.bat",
		"extensions/ringopengl/opengl32/buildvc_x64.bat",
		"extensions/ringopengl/opengl32/document.bat",
		"extensions/ringopengl/opengl32/gencode.bat",
		"extensions/ringopengl/opengl32/gencode.sh",
		"extensions/ringopengl/opengl32/gendoc.ring",
		"extensions/ringopengl/opengl32/opengl32.cf",
		"extensions/ringopengl/opengl32/opengl32lib.ring",
		"extensions/ringopengl/opengl32/ring_opengl32.c",
		"extensions/ringopengl/opengl32/ring_opengl32.rh",
		"extensions/ringopengl/opengl32/test.ring",
		"tools/ring2exe/libs/opengl32.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/ring_opengl32.dll"
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
	:remotefolder = "ringopengl32",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]