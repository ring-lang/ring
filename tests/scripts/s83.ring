see "Enter number of records : " give nCount

aList = []

nCount = 0 + nCount

for x = 1 to nCount
	see "[" + x + "] Name : " give fname
	add(aList,fname)
next

for x = 1 to nCount see aList[x] + nl next
