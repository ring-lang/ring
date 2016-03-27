aList = [
["",0],
["",0],
["",0],
["",0],
["",0],
["",0],
["",0],
["",0],
["",0],
["",0]
]
see "Enter number of records : " give nMax
nMax = num(nMax)
for x = 1 to nMax
	see "Name : " give cName
	see "Age  : " give nAge
	aList[x][1] = cName
	aList[x][2] = nAge
next
see "print data " + nl
for x = 1 to nMax
	see "Name " + aList[x][1] + nl
	see "Age " + aList[x][2] + nl
next

func num x 
	x = 0 + x 
	return x