# Create a List contains 1000000 items
# Then sum the list items!

t1 = clock()
aList = 1:1000000

nTime = (clock()-t1)/clockspersecond()

nSum = 0
nMax = len(aList)
for x=1 to nMax
	nSum += aList[x]
next

? "Size : " + nMax
? "Sum  : " + nSum
? "Time : " + nTime
