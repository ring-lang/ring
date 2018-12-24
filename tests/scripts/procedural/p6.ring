see "hello world" + NL

for x = 1 to 10
	see x 
	see NL
	if x = 3
		see "number three" + NL
	ok
next

aList = ["Mahmoud","Samir","Fayed"]
aList2 = [1,2,3,4,5]

see aList
see aList2

see "*****************************************************" + NL
seelist(aList,3)
seelist(aList2,5)

seelist ( reverselist(aList,3)  ,3)

see reverselist(aList,3)
see aList

see squarearray(aList2,5)

for x = 1 to 5
	see retlist(aList2)[x]
	see NL
next

see "*****************************************************" + NL

mylist = squarearray(aList2,5)

see mylist 

for x = 1 to 5
	see squarearray(aList2,5)[x]
	see NL
next
 
func seelist aArray,nSize
	for x = 1 to nSize
		see aArray[x]
		see NL
	next

func reverselist aArray,nSize
	newarray = aArray
	for t = 1 to nSize
		newarray[nSize+1-t] = aArray[t]
	next
	return newarray

func squarearray aArray,nSize
	newarray = aArray
	for t = 1 to nSize
		newarray[t] = aArray[t] * aArray[t]
	next
	return newarray

func retlist aArray
	return aArray