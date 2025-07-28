aPackageInfo = [
	:name 		= "The A Package",
	:description	= "Our A package using the RingPM",
	:folder		= "a",
	:developer  	= "Mahmoud Fayed",
	:email		= "msfclipper@yahoo.com",
	:license	= "MIT License",
	:version	= "1.0.0",
	:ringversion	= "1.9",
	:files 		= [
		"test.ring"
	],
	:libs		= [
		[:name = "b", :version = "1.0.0"],
		[:name = "c", :version = "1.0.0"]
	],
	:run		= "ring test.ring"
]
