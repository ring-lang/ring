/*
**	Application	: Substr()
**	Author    	: Amr Ali
**	Date   		: 08/03/2018
*/
####################################################################
# Variables types(String, Number, List, Object, c object)

str = "Welcome to the Ring programming language (ring)"

? str  ? " "
? substr(str, 16, 4)		 # Get substring by position number
? substr(str, "language")	 # Get position of substring
? substr(str, "Ring", '"Ring"')	 # Replace substring

# for not case sensitive
	? substr(str, "Ring", "*Ring*", true)
