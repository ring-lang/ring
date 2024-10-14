/*
	Application	: Pass By Value Pass By Reference
	Author		: Ahmed Mohamed
	Date		: 2019/10/16
*/

# Functions Scope - Pass By Value - Pass By Reference
# Ring
# String | Number ---> Pass By Value
# List | Object ---> Pass By Reference

func main

	aList = 1:10
	test(aList)
	 ? aList

func test aList
	aList[1] = "one"

