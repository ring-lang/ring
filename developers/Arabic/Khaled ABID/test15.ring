/*
**	Application	: Variables (Lists) - version 3
**	Author		: Khaled ABID
**	Date		: 19/12/2017
*/

#=====================================================================

# Strings ---> character, array of characters, ML, Binary, Null
# Numbers ---> int, float|double, boolean(True|False)
# Lists	  ---> Array, List, Nested List, MD Array, Hash|Dict

mylist = []	# Empty List to store the numbers

add(mylist,"one")
? mylist

mylist + "two"
? mylist

# + Operator --->-> String + String 		-> merge strings
#		\-> Number + Number 		-> sum numbers
#		\-> String + Number 		-> merge strings (Convert)
#		\-> Number + String 		-> sum numbers (Convert)
#		\-> List + (String|Number|List) -> add item
