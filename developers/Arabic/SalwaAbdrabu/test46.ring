/*
	Application : functions
	Author      : Salwa Abdrabu
*/

# Functions - Scope - Pass By Value - Pass By Reference
# Ring 
# String | Number ----> Pass By Value
# List   | Object ----> Pass by Reference
  
func main 

	aList    = 1 : 10
	test(aList)
	? aList
func test aList
	aList[1] = "one"	
	
