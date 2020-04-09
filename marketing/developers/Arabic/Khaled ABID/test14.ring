/*
**	Application	: Variables (Lists) - version 2
**	Author		: Khaled ABID
**	Date		: 19/12/2017
*/

#=====================================================================

# Strings ---> character, array of characters, ML, Binary, Null
# Numbers ---> int, float|double, boolean(True|False)
# Lists	  ---> Array, List, Nested List, MD Array, Hash|Dict

mylist = [
	"one",
	"two",
	"three",
	4,5,6,7,8,9,"ten",
	[11,12,13,14,15],
	["algeria","algiers","..."],
	[ [1,2,3],
	  [4,5,6]
	]
]
? MyLisT				# not case-sensitive
? "Count: " + len(mylist)
? mylist [12]
? mylist [12][2]
? mylist [13][2][3]
? mylist [12][2][3]
