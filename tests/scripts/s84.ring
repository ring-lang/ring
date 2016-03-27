see "welcome" + nl

sayhello(
"Mahmoud",
28
)

printlist (
			[
				"Mohammed", # first item
				"Mahmoud",
				"Ahmed",
				"Ibrahim",
				[
				  "one",
				  "two",
				  "three",
				  [
				  	1,2,3,4,5,
				  	6,7,8,9,10	
				  ],
				  "four",
				  "five"
				],
				"fady"
			] 
		 )  aList = 	[
				"Mohammed",
				"Mahmoud",
				"Ahmed",
				"Ibrahim",
				"fady"
			] 
see "reverse list " + nl
see reverse(aList)		# here we reverse the list to see items from bottom to up

see "done..." + nl + "bye!"+nl
func sayhello cName,nAge
	see "Hello " + nl
	see "Your name is " + cName + nl
	see "You are " + nAge + " years old" + nl

func printlist aList
	for x = 1 to len(aList)
		see "item " + x + " value is " 
		see aList[x] 
		see nl
	next

func reverse aList
	templist = aList
	for x = 1 to len(aList)
		templist[len(aList)-x+1] = aList[x]
	next
	return templist