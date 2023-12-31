aPackageInfo = [
	:name = "The RingAllegro Package",
	:description = "Our RingAllegro package using the Ring programming language",
	:folder = "ringallegro",
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
		"bin/load/gamelib.ring",
		"extensions/ringallegro/allegro.cf",
		"extensions/ringallegro/allegro.rh",
		"extensions/ringallegro/buildclang.sh",
		"extensions/ringallegro/buildgcc.sh",
		"extensions/ringallegro/buildvc.bat",
		"extensions/ringallegro/buildvc_allegro5.2.8.bat",
		"extensions/ringallegro/buildvc_x64.bat",
		"extensions/ringallegro/buildvc_allegro5.2.8_x64.bat",
		"extensions/ringallegro/document.bat",
		"extensions/ringallegro/gamelib.ring",
		"extensions/ringallegro/gencode.bat",
		"extensions/ringallegro/gencode.sh",
		"extensions/ringallegro/gendoc.ring",
		"extensions/ringallegro/ringallegrofuncsdoc.txt",
		"extensions/ringallegro/ring_allegro.c",
		"tools/ring2exe/libs/allegro.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/allegro-5.2.dll",
		"bin/allegro_acodec-5.2.dll",
		"bin/allegro_audio-5.2.dll",
		"bin/allegro_color-5.2.dll",
		"bin/allegro_dialog-5.2.dll",
		"bin/allegro_font-5.2.dll",
		"bin/allegro_image-5.2.dll",
		"bin/allegro_main-5.2.dll",
		"bin/allegro_memfile-5.2.dll",
		"bin/allegro_physfs-5.2.dll",
		"bin/allegro_primitives-5.2.dll",
		"bin/allegro_ttf-5.2.dll",
		"bin/allegro_video-5.2.dll",
		"bin/FLAC.dll",
		"bin/freetype.dll",
		"bin/jpeg62.dll",
		"bin/libpng16.dll",
		"bin/ogg.dll",
		"bin/physfs.dll",
		"bin/ring_allegro.dll",
		"bin/theoradec.dll",
		"bin/vorbis.dll",
		"bin/vorbisfile.dll",
		"bin/zlib.dll"
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
	:remotefolder = "ringallegro",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]