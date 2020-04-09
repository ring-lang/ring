/*
**	Application	: Ring lessons - Reflection and Meta-programming(2) .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 24 .
*/
/*
	Reflection and Meta-programming - mergemethods(class(to),class(from))
*/
Load "stdlib.ring"

mergemethods(:list,:myList)

oList = new List ( [ 1 , 2 , 3 ] )
? oList.vValue
? "List Size = " + oList.size()
? "List Size = " + oList.count()

Class myList
		Func count 
			return len(vValue)
