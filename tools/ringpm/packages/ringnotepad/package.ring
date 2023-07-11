aPackageInfo = [
	:name = "The RingNotepad Package",
	:description = "Our RingNotepad package using the Ring programming language",
	:folder = "ringnotepad",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.22",
	:ringversion = "1.18",
	:versions = 	[
		[
			:version = "1.0.22",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "stdlib",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "ringqt",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "findinfiles",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "formdesigner",
			:version = "1.0",
			:providerusername = ""
		],
		[
			:name = "libdepwin_apache",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"main.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"RingNotepad.exe",
		"tools/ringnotepad/batch/killwebserver.bat",
		"tools/ringnotepad/batch/run.bat",
		"tools/ringnotepad/batch/run2.bat",
		"tools/ringnotepad/batch/run.sh",
		"tools/ringnotepad/batch/run2.sh",
		"tools/ringnotepad/batch/apache_config/makeexecutable.sh",
		"tools/ringnotepad/batch/apache_config/setwebappconf.sh",
		"tools/ringnotepad/batch/apache_config/webapp.conf.bak",
		"tools/ringnotepad/image/closeapp.png",
		"tools/ringnotepad/image/pause.png",
		"tools/ringnotepad/image/back.jpg",
		"tools/ringnotepad/image/back2.jpg",
		"tools/ringnotepad/image/close.png",
		"tools/ringnotepad/image/colors.png",
		"tools/ringnotepad/image/comment.png",
		"tools/ringnotepad/image/comment2.png",
		"tools/ringnotepad/image/copy.png",
		"tools/ringnotepad/image/cut.png",
		"tools/ringnotepad/image/debug.png",
		"tools/ringnotepad/image/font.png",
		"tools/ringnotepad/image/formdesigner.png",
		"tools/ringnotepad/image/new.png",
		"tools/ringnotepad/image/notepad.png",
		"tools/ringnotepad/image/open.png",
		"tools/ringnotepad/image/paste.png",
		"tools/ringnotepad/image/print.png",
		"tools/ringnotepad/image/project.png",
		"tools/ringnotepad/image/richtext.png",
		"tools/ringnotepad/image/run.png",
		"tools/ringnotepad/image/rungui.png",
		"tools/ringnotepad/image/save.png",
		"tools/ringnotepad/image/saveas.png",
		"tools/ringnotepad/image/search.png",
		"tools/ringnotepad/image/source.png",
		"tools/ringnotepad/image/undo.png",
		"tools/ringnotepad/image/web.png",
		"tools/ringnotepad/README.md",
		"tools/ringnotepad/rnote.ring",
		"tools/ringnotepad/rnote_arabic.ring",
		"tools/ringnotepad/rnoteexe/buildvc.bat",
		"tools/ringnotepad/rnoteexe/README.md",
		"tools/ringnotepad/rnoteexe/ringicon.ico",
		"tools/ringnotepad/rnoteexe/rnote.c",
		"tools/ringnotepad/rnoteexe/rnote.ico",
		"tools/ringnotepad/rnoteexe/rnote.rc",
		"tools/ringnotepad/src/rnoteactivefile.ring",
		"tools/ringnotepad/src/rnoteactivefolder.ring",
		"tools/ringnotepad/src/rnoteautocomplete.ring",
		"tools/ringnotepad/src/rnotebase.ring",
		"tools/ringnotepad/src/rnotecontroller.ring",
		"tools/ringnotepad/src/rnotedistribute.ring",
		"tools/ringnotepad/src/rnoteeditmenu.ring",
		"tools/ringnotepad/src/rnoteeditorevents.ring",
		"tools/ringnotepad/src/rnotefilemenu.ring",
		"tools/ringnotepad/src/rnotefiles.ring",
		"tools/ringnotepad/src/rnotefilestabs.ring",
		"tools/ringnotepad/src/rnotefind.ring",
		"tools/ringnotepad/src/rnotefindinfiles.ring",
		"tools/ringnotepad/src/rnoteformdesigner.ring",
		"tools/ringnotepad/src/rnotegoto.ring",
		"tools/ringnotepad/src/rnotehelp.ring",
		"tools/ringnotepad/src/rnoteinserttext.ring",
		"tools/ringnotepad/src/rnotelists.ring",
		"tools/ringnotepad/src/rnotemainfiletoolbar.ring",
		"tools/ringnotepad/src/rnotemainwindow.ring",
		"tools/ringnotepad/src/rnotemode.ring",
		"tools/ringnotepad/src/rnoteoutputwindow.ring",
		"tools/ringnotepad/src/rnoteprogrammenu.ring",
		"tools/ringnotepad/src/rnoterun.ring",
		"tools/ringnotepad/src/rnotesettings.ring",
		"tools/ringnotepad/src/rnotestyle.ring",
		"tools/ringnotepad/src/rnotetabwidth.ring",
		"tools/ringnotepad/src/rnotetools.ring",
		"tools/ringnotepad/src/rnotetreeviewevents.ring",
		"tools/ringnotepad/src/rnoteviewmenu.ring",
		"tools/ringnotepad/src/rnotewebbrowser.ring",
		"tools/ringnotepad/src/templates.ring",
		"tools/ringnotepad/src/rnoteselectfile.ring",
		"tools/ringnotepad/translation/arabic.ring",
		"tools/ringnotepad/translation/english.ring"
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
	:remotefolder = "ringnotepad",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]