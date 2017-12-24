/*
** Testing types conversion and lists
** Author Rashad Kamsheh
** Date 2017-12-24
*/

# prompts the user to enter a number
	? "Enter a number" give number
# converts a number to a string
	numberToString = "" + number
# converts a string to a number
	StringToNumber = (0 + numberToString) 


List = ["dwarf", ["human", "midget"], "zoro"]

# in ring, the first index is 1 and not 0
# should print out "midget"
	? List[2][2]
