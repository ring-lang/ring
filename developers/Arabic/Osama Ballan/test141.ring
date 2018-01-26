/*
**	Application	: Ring lessons - Scope .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 25 .
*/

/*
			Variables Scope
			Three Scopes :
			(1) Global Scope
			(2) Object Scope
			(3) Local Scope
*/
# Lexical Scoping ( Scope Of Variable is Based On Location )
x = 10		# Global Scope

Func main
	y = 20	# Local Variable
	? x
	test()
	? y
	new person {
	name = "Osama" address = "Syria" phone = "229102"
	? self
	}
	
Func test
	? x + 5
Class person	
		name address phone
		



