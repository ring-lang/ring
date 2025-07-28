aPackageInfo = [
	:name 		= "MyApp",
	:description	= "Our first application",
	:folder		= "myapp",
	:developer  	= "Mahmoud Fayed",
	:email		= "msfclipper@yahoo.com",
	:license	= "MIT License",
	:version	= "1.0.0",
	:ringversion	= "1.9",
	:files 		= [
		"myapp.ring"
	],
	:libs		= [
		[:name = "mylib", :version = "1.0.0"]
	],

	:run		= "ring myapp.ring"
]
