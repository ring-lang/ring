/*
**	Application	: Ring lessons - Functional Programming - Map() Method .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 22 .
*/

load "stdlib.ring"
# Map (List , Function)

aList = 1:10

aList2 = map(aList , func x {return x*x})
? aList
? aList2
