/*
	Application	: Course of Essentials (Functions)
	Author		: Khaled ABID
	Date		: 02/01/2018
*/

# Functions - Scope - Pass by value - Pass by refernce

# Ring 
# String | Number -----> Pass by value
# List 	 | Object -----> Pass by reference
func main 
	
	aList = 1:10

	alist2 = aList	# copy by value

	aList[1] = "one"

	? aList[1]
