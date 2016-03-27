N = 100000

aList = cFunctions()
aList = sort(aList)

binarysearch(aList,"sendmail")

nTime = clock()
for x = 1 to N
	binarysearch(aList,"sendmail")
next
nTime2 = clock()
see "Binary Search : " + (nTime2 - nTime) + nl



nTime = clock()
for x = 1 to N
	find(aList,"sendmail")
next
nTime2 = clock()

see "Linear Search : " + (nTime2 - nTime) + nl

aList = 1:185
nTime = clock()
for x = 1 to N
	find(aList,185)
next
see "Linear Search : " + (clock() - nTime) + nl
nTime = clock()
for x = 1 to N
	binarysearch(aList,185)
next
see "Binary Search : " + (clock() - nTime) + nl

aList = []
for x = 1 to 100
aList + ["test"+x,x]
NEXT
see binarysearch(aList,50,2) + nl
see binarysearch(aList,"test21",1) + nl

