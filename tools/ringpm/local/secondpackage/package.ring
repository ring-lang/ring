aPackageInfo = [
	:name 		= "The Second Package",
	:description	= "Our second package using the RingPM",
	:folder		= "secondpackage",
	:developer  	= "Mahmoud Fayed",
	:email		= "msfclipper@yahoo.com",
	:license	= "MIT License",
	:version	= "1.0.1",
	:ringversion	= "1.9",
	:files 		= [
		"test.ring"
	],	
	:libs		= [
		[:name = "firstpackage", :version = "1.0.0"]
	],
	:run = "ring test.ring"
]
