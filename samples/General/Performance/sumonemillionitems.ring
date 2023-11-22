# Create a List contains 1000000 items
# Then sum the list items!

t1 = clock()
aList = list(7000000)

nSum = 0
nMax = len(aList)
for x=nMax to 1 step -1
	nSum += aList[x]
next

nTime = (clock()-t1)/clockspersecond()

? "Size : " + nMax
? "Sum  : " + nSum
? "Time : " + nTime
