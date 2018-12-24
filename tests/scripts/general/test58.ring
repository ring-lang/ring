	load "stdlib.ring"

	aList = 1:5	# create list contains numbers from 1 to 5
	# replace list numbers with strings
	for x in aList {
		switch x {
		case 1  x = "one"
		case 2  x = "two"
		case 3  x = "three"
		case 4  x = "four"
		case 5  x = "five"
		}
	}
	print(aList)	# print the list items