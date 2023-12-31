aPackageInfo = [
	:name = "The GameEngine Package",
	:description = "Our GameEngine package using the Ring programming language",
	:folder = "gameengine",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.8",
	:ringversion = "1.19",
	:versions = 	[
		[
			:version = "1.0.8",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "ringallegro",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringlibsdl",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"bin/load/gameengine.ring",
		"libraries/gameengine/classes/gameanimate.ring",
		"libraries/gameengine/classes/gamebase.ring",
		"libraries/gameengine/classes/gameclass.ring",
		"libraries/gameengine/classes/gamemap.ring",
		"libraries/gameengine/classes/gameobject.ring",
		"libraries/gameengine/classes/gameresources.ring",
		"libraries/gameengine/classes/gamesound.ring",
		"libraries/gameengine/classes/gamesprite.ring",
		"libraries/gameengine/classes/gametext.ring",
		"libraries/gameengine/gameengine.rh",
		"libraries/gameengine/gameengine.ring",
		"libraries/gameengine/gl.ring",
		"libraries/gameengine/gl_allegro.ring",
		"libraries/gameengine/gl_libsdl.ring",
		"libraries/gameengine/libsdl.ring",
		"libraries/gameengine/README.md",
		"libraries/gameengine/ring_libsdl.rh",
		"libraries/gameengine/sdl.rh"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[

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
	:remotefolder = "gameengine",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]