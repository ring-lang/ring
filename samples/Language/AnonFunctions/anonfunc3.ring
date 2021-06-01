# Constants 
	C_FUNCTION  = 1
	C_PARAMETER = 2

# Global Variables
	x = 100

func main

	aList = [ 
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

	sub(aList)

func sub aList

	f = aList[C_FUNCTION]
	call f(aList[C_PARAMETER])