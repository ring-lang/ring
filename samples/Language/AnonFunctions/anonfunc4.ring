load "anonfunclib.ring"

# Global Variables
	x = 100

func main

	aFunc = [ 
		func aPara {
			? "test using global"
			? x
			? "Using parameters"
			? "Language : "  + aPara[:name]
			? "License  : "  + aPara[:license]
			? "Version  : "  + aPara[:version]
		} 
		, [
			:name = "Ring",
			:license = "MIT",
			:version = version()
		]
	]

	callfunc(aFunc)