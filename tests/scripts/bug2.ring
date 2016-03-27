aList = list(10)
for x = 1 to len(aList)
	aList[x] = new object { 
		name = "object" + x
	}
next

cCode = '
	for x = 1 to len(aList)
		see "x value = " + x + nl
		see "len = " + len(aList) + nl
		see aList[x]
	next
'

eval(cCode)

class object name