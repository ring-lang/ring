aList = ["Mahmoud","Samir","Fayed",""]

aList[4] = "Nice"

for x = 1 to 4
	see aList[x] see NL
next

aList2 = [1,2,3,4]

for x = 1 to 4
	see aList2[x] see NL
next

for x = 1 to 4
	aList2[x] = x * x
next

for x = 1 to 4
	see aList2[x] see NL
next

