aPackageInfo = [
	:name 		= "The C Package",
	:description	= "Our C package using the RingPM",
	:folder		= "c",
	:developer  	= "Mahmoud Fayed",
	:email		= "msfclipper@yahoo.com",
	:license	= "MIT License",
	:version	= "1.0.0",
	:ringversion	= "1.9",
	:files 		= [
		"test.ring"
	],
	:libs		= [
		[:name = "d", :version = "1.0.0"]
	],
	:run		= "ring test.ring"
]
