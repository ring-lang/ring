/*
**	Application	: Ring lessons - Reflection and Meta-programming(1) .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 24 .
*/
/*
	Reflection and Meta-programming - Inheritance 
*/
Load "stdlib.ring"

oList = new myList ( [ 1 , 2 , 3 ] )
? oList.vValue
? "List Size = " + oList.size()
? "List Size = " + oList.count()

Class myList from list 
		Func count 
			return len(vValue)
