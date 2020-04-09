/*
**	Application	: Ring lessons - Scope - Conflicts (Class|Object - Local) .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 25 .
*/

# Conflict Between The Class|Object Attribute and Local Variables .

sayHello("Osama")

new test{ mytest() }

Func sayHello p1
	name = "Mr. " + p1
	? "Hello " + name

Class test
	name = "Ring"
	Func mytest
		? name
