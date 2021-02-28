aPackageInfo = [
	:name = "The VisualStudioEditorExtension Package",
	:description = "Our VisualStudioEditorExtension package using the Ring programming language",
	:folder = "visualstudioeditorextension",
	:developer = "Mahmoud Fayed",
	:email = "msfclipper@yahoo.com",
	:license = "MIT License",
	:version = "1.0.2",
	:ringversion = "1.13",
	:versions = 	[
		[
			:version = "1.0.2",
			:branch = "master"
		]
	],
	:libs = 	[
		[
			:name = "ringzip",
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
		"setup.ring",
		"uninstall.ring",
		"README.md"
	],
	:ringfolderfiles = 	[
		"tools/editors/visualstudio.zip"
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
	:setup = "ring setup.ring",
	:windowssetup = "",
	:linuxsetup = "",
	:macossetup = "",
	:ubuntusetup = "",
	:fedorasetup = "",
	:remove = "ring uninstall.ring",
	:windowsremove = "",
	:linuxremove = "",
	:macosremove = "",
	:ubunturemove = "",
	:fedoraremove = "",
	:remotefolder = "visualstudioeditorextension",
	:branch = "master",
	:providerusername = "ringpackages",
	:providerwebsite = "github.com"
]