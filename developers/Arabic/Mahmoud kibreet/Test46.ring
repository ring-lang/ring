/*
          Application : Functions
          Author      : Mahmoud Kibreet
          Date        : 2018.01.27
*/


# Functions - Scope - Pass by Value - Pass by reference

# Ring
# String | Number ----> Pass by value
# List   | Object ----> Pass by reference

func main

	aList = 1:10
	test(aList)
	? aList

func test aList


	aList[1]="one"
