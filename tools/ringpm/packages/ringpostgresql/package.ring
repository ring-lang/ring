aPackageInfo = [
	:name = "The RingPostgreSQL Package",
	:description = "Our RingPostgreSQL package using the Ring programming language",
	:folder = "ringpostgresql",
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
		"bin/load/postgresqllib.ring",
		"extensions/ringpostgresql/buildclang.sh",
		"extensions/ringpostgresql/buildgcc.sh",
		"extensions/ringpostgresql/buildvc.bat",
		"extensions/ringpostgresql/gencode.bat",
		"extensions/ringpostgresql/gencode.sh",
		"extensions/ringpostgresql/pgsql.cf",
		"extensions/ringpostgresql/postgresqllib.ring",
		"extensions/ringpostgresql/ring_pgsql.c",
		"extensions/ringpostgresql/ring_pgsql.rh",
		"tools/ring2exe/libs/postgresql.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/libeay32.dll",
		"bin/libiconv-2.dll",
		"bin/libintl-8.dll",
		"bin/libpq.dll",
		"bin/ring_pgsql.dll",
		"bin/ssleay32.dll"
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
	:remotefolder = "ringpostgresql",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]