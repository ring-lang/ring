/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.03.27
*/

func main()
	? version()
	
	x = 1000000000
	? x
	
	x = 1_000_000_000
	? x
	
	aList = [1,2,3]
	cString = List2str(aList)
	? cString
	
	# Statement -> Expression -> List
		["one", "two", "three"]
	
	cString = "NULL"
	? isnull(cString)
	cString = "null"
	? isnull(cString)
	decimals(5)
	? new point

class point 
	x=10.1 y=20.1 z=30.1
