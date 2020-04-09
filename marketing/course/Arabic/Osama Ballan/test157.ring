/*
**	Application	: Ring lessons - Functions and Methods Scope .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 26 .
*/

# Function|Method Call .
# Search ----> Methods ----> Functions ----> STD Functions .

? copy("Hello ",3)

new myClass { test() }

Func copy cStr,nCount
	for x = 1 to nCount
		? cStr
	next

Class myClass 
	Func copy cString,nCount
	Func test
		new local{
			copy("Ring",4)
			}
Class local
