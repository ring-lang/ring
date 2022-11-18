C_VARNAME  = 1
C_STATUS   = 2
C_REFCOUNT = 3
C_VALUE    = 4

mem1 = [
	[:a,:Live,1,[1,2,3]],
	[:mix,:Live,3,[1,2,3,:a,:mix,:mix]],
	[:mix2,:Live,3,:mix]
]

mem2 = [
	[:a,:Live,1,[:b]],
	[:b,:Live,1,[:a]]
]

mem3 = [
	[:n1,:Live,1,[null,:n2]],
	[:n2,:Live,2,[:n1,:n3]],
	[:n3,:Live,2,[:n2,:n4]],
	[:n4,:Live,2,[:n3,:n5]],
	[:n5,:Live,1,[:n4,null]]
]

printMemory(mem1)
printMemory(mem2)
printMemory(mem3)

testDirectCircularCount()
testGetChildren()

func size cStr,nSize
	cStr = "" + cStr
	return cStr + Copy(" ",nSize-len(cStr))

func line
	? copy("=",30)

func PrintMemory aList
	line()
	for vValue in aList
		# Print Variable Name
			see size(vValue[1],10)
		# Print Status
			see Size(UPPER(vValue[2]),10)
		# Print Reference Count
			see Size(vValue[3],10)
		see nl
	next
	line()

func getVar aMem,cVar
	nIndex = find(aMem,cVar,C_VARNAME)
	if nIndex
		return nIndex
	ok
	raise( "Sorry, Can't find the variable: " + cVar)

func increment aMem,cVar
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_REFCOUNT]++

func directCircularCount aMem,cVar 
	nIndex = getVar(aMem,cVar)
	vValue = aMem[nIndex][C_VALUE]
	nCount = 0
	if isList(vValue)
		for item in vValue 
			if ""+item = cVar 
				nCount++
			ok
		next 
	but isString(vValue)
		return directCircularCount(aMem,vValue)
	ok
	return nCount

func testDirectCircularCount
	? "Test: Direct Cirular Count"
	? "MEM1 - a    - " + directCircularCount(mem1,:a)
	? "MEM1 - mix  - " + directCircularCount(mem1,:mix)
	? "MEM1 - mix2 - " + directCircularCount(mem1,:mix2)
	? "MEM2 - a    - " + directCircularCount(mem2,:a)
	? "MEM2 - b    - " + directCircularCount(mem2,:b)
	? "MEM3 - n1   - " + directCircularCount(mem3,:n1)
	? "MEM3 - n2   - " + directCircularCount(mem3,:n2)
	? "MEM3 - n3   - " + directCircularCount(mem3,:n3)
	? "MEM3 - n4   - " + directCircularCount(mem3,:n4)
	? "MEM3 - n5   - " + directCircularCount(mem3,:n5)
	line()

func getChildren aMem,cVar 
	aChild = []
	nIndex = getVar(aMem,cVar)
	vValue = aMem[nIndex][C_VALUE]
	if isList(vValue)
		for item in vValue 
			if isString(item)
				aChild + item 
			ok
		next
	but isString(vValue)
		aChild + vValue
	ok
	return aChild 

func ListAsString aList 
	cStr = "["
	nMax = len(aList)
	for t=1 to nMax
		cStr += aList[t]
		if t != nMax
			cStr += ","
		ok
	next
	cStr += "]"
	return cStr

func testGetChildren 
	? "Test: GetChildren"
	? "MEM1 - a    : " + ListAsString( getChildren(mem1,:a)    )
	? "MEM1 - mix  : " + ListAsString( getChildren(mem1,:mix)  )
	? "MEM1 - mix2 : " + ListAsString( getChildren(mem1,:mix2) )
