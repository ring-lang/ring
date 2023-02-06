aList = 1:100
aOut = []
while len(aOut) != 100
	nSize = len(aList)
	if nSize > 1
		nIndex = random(nSize)
		if nIndex = 0  nIndex=1 ok
		aOut + aList[nIndex]
		del(aList,nIndex)
	else
		aOut + aList[1]
		aList = []
	ok
end
? aOut
