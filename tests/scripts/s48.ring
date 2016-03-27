aList = [ ["Mahmoud",27],["Mohammed",30],["Ahmed",25],["Ibrahim",22]]

for x = 1 to 4
	see aList[x][1] + " " 
	see aList[x][2] 
	see NL
	if aList[x][1] = "Ahmed"
		see "Item Number "
		see x
		see NL
	ok
next

see aList[5][1]

