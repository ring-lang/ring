/*
**	Application	: Ring lessons - Functional Programming - Map() - Filter() Methods .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 22 .
*/

load "stdlib.ring"
# Map (List , Function)

aList = 1:10

map(aList , func x { ? x})

aList2 = filter(aList , func x {

	if (x+1)%2 = 0 
		return true
	else
		return false
	ok
})
? aList2
