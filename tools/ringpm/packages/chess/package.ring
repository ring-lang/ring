aPackageInfo = [
	:name = "The Chess Package",
	:description = "Our Chess package using the Ring programming language",
	:folder = "chess",
	:developer = "Mahmoud Fayed",
	:email = "msflcipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.1",
	:ringversion = "1.18",
	:versions = 	[
		[
			:version = "1.0.1",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "ringqt",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "stdlib",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"applications/chess/AA-ChessBoard.ring",
		"applications/chess/BBishop.png",
		"applications/chess/BKing.png",
		"applications/chess/BKnight.png",
		"applications/chess/BPawn.png",
		"applications/chess/BQueen.png",
		"applications/chess/BRook.png",
		"applications/chess/chessgame.png",
		"applications/chess/ChessPuzzles.ring",
		"applications/chess/README.md",
		"applications/chess/WBishop.png",
		"applications/chess/WKing.png",
		"applications/chess/WKnight.png",
		"applications/chess/WPawn.png",
		"applications/chess/WQueen.png",
		"applications/chess/WRook.png"
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
	:remotefolder = "chess",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]