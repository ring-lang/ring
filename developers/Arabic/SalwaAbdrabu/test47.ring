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
	aList2   = aList    # Copy By Value
	aList[1] = "one"
	? aList[1]
	? aList2[1]
		
	
