/*
**	Application	: Ring lessons - Stdlib Classes - String Class .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 24 .
*/

Load "stdlib.ring"

oString = new string("Ring Language")
oString.lower().println()
? methods(oString)
? oString.value()
str = "Hello World"
? str
? len(str)
? upper(str)
? lower(str)

