/*
	Application	: Functions/Methods Scope Version 3
	Author		: Ahmed Mohamed
	Date		: 23-11-2019
*/

/*
	(1) Desktop
	(2) Web
	(3) Mobile
	(4) Games
*/

/*
	(1) Functions/Methods Scope
	(2) Type Hints
	(3) Trace Library (Debugging)
*/

# functions | Methods Call
# Search ----> Methods ----> Functions ----> std functions

? copy("Hello ", 3)

new myClass { test() }

func copy cString, nCount
	for t = 1 to nCount
		? cString
	next

class myClass
	func copy cString, nCount
	func test
		new local {	
			copy("Ring ", 3)
		}

class local
