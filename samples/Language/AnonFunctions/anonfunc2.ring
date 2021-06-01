# Constants 
	C_FUNCTION  = 1
	C_PARAMETER = 2

# Global Variables
	x = 100

func main

	t = 10

	aList = [ 
		func p1 {
			? "test using global"
			? x
			? "using parameter"
			? p1
		} 
		, t 
	]

	sub(aList)

func sub aList

	f = aList[C_FUNCTION]
	call f(aList[C_PARAMETER])