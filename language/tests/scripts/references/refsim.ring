C_LINESIZE = 30

C_VARNAME        = 1
C_STATUS         = 2
C_REFCOUNT       = 3
C_VALUE          = 4
C_LOSTOWNERCOUNT = 5

mem1 = [
	[:a,:Live,1,[1,2,3],0],
	[:mix,:Live,3,[1,2,3,:a,:mix,:mix],0], 
	[:mix2,:Live,3,:mix,0]
]

mem2 = [
	[:a,:Live,1,[:b],0],
	[:b,:Live,1,[:a],0]
]

mem3 = [
	[:n1,:Live,1,[null,:n2],0],
	[:n2,:Live,2,[:n1,:n3],0],
	[:n3,:Live,2,[:n2,:n4],0],
	[:n4,:Live,2,[:n3,:n5],0],
	[:n5,:Live,1,[:n4,null],0]
]

printMemory(mem1,"MEM1")
printMemory(mem2,"MEM2")
printMemory(mem3,"MEM3")

testGetChildren()
testGetNestedChildren()
testDirectCircularCount()
testIndirectCircularCount()
testDeleteVar()

func size cStr,nSize
	cStr = "" + cStr
	return cStr + Copy(" ",nSize-len(cStr))

func line
	? copy("=",C_LINESIZE)

func subline
	? copy("-",C_LINESIZE)

func title cTitle 
	line()
	nSpace = (C_LINESIZE - len(cTitle)) / 2
	? copy(" ",nSpace) + cTitle 
	line()

func PrintMemory aList,cTitle
	if cTitle != NULL
		title(cTitle)
	ok
	? size("Var",5) + size("Status",7) + 
	  size("RefCount",9) + size("LostOwner",7) 
	subLine()
	for vValue in aList
		# Print Variable Name
			see size(vValue[C_VARNAME],5)
		# Print Status
			see Size(UPPER(vValue[C_STATUS]),7)
		# Print Reference Count
			see Size(vValue[C_REFCOUNT],9)
		# Print Lost Owner Count 
			see Size(vValue[C_LOSTOWNERCOUNT],10)
		see nl
	next

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
	title("Test: Direct Cirular Count")
	? "MEM1 - a    : " + directCircularCount(mem1,:a)
	? "MEM1 - mix  : " + directCircularCount(mem1,:mix)
	? "MEM1 - mix2 : " + directCircularCount(mem1,:mix2)
	? "MEM2 - a    : " + directCircularCount(mem2,:a)
	? "MEM2 - b    : " + directCircularCount(mem2,:b)
	? "MEM3 - n1   : " + directCircularCount(mem3,:n1)
	? "MEM3 - n2   : " + directCircularCount(mem3,:n2)
	? "MEM3 - n3   : " + directCircularCount(mem3,:n3)
	? "MEM3 - n4   : " + directCircularCount(mem3,:n4)
	? "MEM3 - n5   : " + directCircularCount(mem3,:n5)

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
		if aList[t] != NULL
			cStr += aList[t]
			if t != nMax
				cStr += ","
			ok
		ok
	next
	if right(cStr,1) = "," cStr = left(cStr,len(cStr)-1) ok
	cStr += "]"
	return cStr

func testGetChildren 
	title("Test: GetChildren")
	? "MEM1 - a    : " + ListAsString( getChildren(mem1,:a)    )
	? "MEM1 - mix  : " + ListAsString( getChildren(mem1,:mix)  )
	? "MEM1 - mix2 : " + ListAsString( getChildren(mem1,:mix2) )
	? "MEM2 - a    : " + ListAsString( getChildren(mem2,:a)    )
	? "MEM2 - b    : " + ListAsString( getChildren(mem2,:b)    )
	? "MEM3 - n1   : " + ListAsString( getChildren(mem3,:n1)   )
	? "MEM3 - n2   : " + ListAsString( getChildren(mem3,:n2)   )
	? "MEM3 - n3   : " + ListAsString( getChildren(mem3,:n3)   )
	? "MEM3 - n4   : " + ListAsString( getChildren(mem3,:n4)   )
	? "MEM3 - n5   : " + ListAsString( getChildren(mem3,:n5)   )

func getNestedChildren aMem,cVar 
	aChild = getChildren(aMem,cVar)
	if len(aChild) = 0 return aChild ok	
	for t=1 to len(aChild)
		if aChild[t] = NULL loop ok
		aNewChild = getChildren(aMem,aChild[t])
		if len(aNewChild) = 0 loop ok
		for item in aNewChild 
			if not find(aChild,item)
				aChild + item
			ok
		next	
	next
	return aChild

func testGetNestedChildren 
	title("Test: GetNestedChildren")
	? "MEM1 - a    : " + ListAsString( GetNestedChildren(mem1,:a)    )
	? "MEM1 - mix  : " + ListAsString( GetNestedChildren(mem1,:mix)  )
	? "MEM1 - mix2 : " + ListAsString( GetNestedChildren(mem1,:mix2) )
	? "MEM2 - a    : " + ListAsString( GetNestedChildren(mem2,:a)    )
	? "MEM2 - b    : " + ListAsString( GetNestedChildren(mem2,:b)    )
	? "MEM3 - n1   : " + ListAsString( GetNestedChildren(mem3,:n1)   )
	? "MEM3 - n2   : " + ListAsString( GetNestedChildren(mem3,:n2)   )
	? "MEM3 - n3   : " + ListAsString( GetNestedChildren(mem3,:n3)   )
	? "MEM3 - n4   : " + ListAsString( GetNestedChildren(mem3,:n4)   )
	? "MEM3 - n5   : " + ListAsString( GetNestedChildren(mem3,:n5)   )

func indirectCircularCount aMem,cVar 
	nIndex = getVar(aMem,cVar)
	if isString(aMem[nIndex][C_VALUE])
		return indirectCircularCount(aMem,aMem[nIndex][C_VALUE])
	ok
	nDirectCircularCount   = DirectCircularCount(aMem,cVar)
	nCount = 0
	aChild = getChildren(aMem,cVar)
	for t=1 to len(aChild)
		if aChild[t] = NULL loop ok
		if aChild[t] = cVar 
			nCount++ 
			loop
		ok
		aNewChild = getChildren(aMem,aChild[t])
		for item in aNewChild 
			if item = NULL loop ok
			if item = cVar 
				nCount++ 
				loop
			ok
			if not find(aChild,item)
				aChild + item
			ok
		next	
	next
	nIndirectCircularCount = nCount - nDirectCircularCount
	return nIndirectCircularCount

func testIndirectCircularCount
	title("Test: Indirect Cirular Count")
	? "MEM1 - a    : " + indirectCircularCount(mem1,:a)
	? "MEM1 - mix  : " + indirectCircularCount(mem1,:mix)
	? "MEM1 - mix2 : " + indirectCircularCount(mem1,:mix2)
	? "MEM2 - a    : " + indirectCircularCount(mem2,:a)
	? "MEM2 - b    : " + indirectCircularCount(mem2,:b)
	? "MEM3 - n1   : " + indirectCircularCount(mem3,:n1)
	? "MEM3 - n2   : " + indirectCircularCount(mem3,:n2)
	? "MEM3 - n3   : " + indirectCircularCount(mem3,:n3)
	? "MEM3 - n4   : " + indirectCircularCount(mem3,:n4)
	? "MEM3 - n5   : " + indirectCircularCount(mem3,:n5)

func getRefCount aMem,cVar 
	nIndex = getVar(aMem,cVar)
	return aMem[nIndex][C_REFCOUNT]

func setRefCount aMem,cVar,nValue 
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_REFCOUNT] = nValue 
	refreshRefCount(aMem,cVar)

func decRefCount aMem,cVar
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_REFCOUNT]--
	refreshRefCount(aMem,cVar)

func refreshRefCount aMem,cVar
	nIndex = getVar(aMem,cVar)
	# Reflect the update to other variables 
	# which is just a reference to this variable 
	# This is not needed in Ring VM  (C Code)
	# Because in Ring VM the List pointer is shared 
	for var in aMem 
		if isString(var[C_VALUE])
			if var[C_VALUE] = cVar 
				var[C_REFCOUNT] = aMem[nIndex][C_REFCOUNT]
			ok
		ok
	next
	if isString(aMem[nIndex][C_VALUE])
		for var in aMem 
			if var[C_VARNAME] = aMem[nIndex][C_VALUE]
				var[C_REFCOUNT] = aMem[nIndex][C_REFCOUNT]
			ok
		next
	ok

func getLostOwnerCount aMem,cVar 
	nIndex = getVar(aMem,cVar)
	return aMem[nIndex][C_LOSTOWNERCOUNT]

func incLostOwnerCount aMem,cVar 
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_LOSTOWNERCOUNT]++
	aMem[nIndex][C_STATUS] = :Hidden
	aChild = getChildren(aMem,cVar)
	for child in aChild 
		if child = NULL loop ok
		nIndex = getVar(aMem,child)
		if aMem[nIndex][C_VARNAME] != cVar 
			aMem[nIndex][C_LOSTOWNERCOUNT]++
			if aMem[nIndex][C_LOSTOWNERCOUNT] > aMem[nIndex][C_REFCOUNT]
				killVar(aMem,aMem[nIndex][C_VARNAME])
			ok
		ok
	next

func decrement aMem,cVar
	nDirectCount   = DirectCircularCount(aMem,cVar)   #  WithoutCountingTheRoot
	nInDirectCount = InDirectCircularCount(aMem,cVar) #  WithoutCountingTheRoot
	nRefCount      = getRefCount(aMem,cVar)
	if nRefCount - nDirectCount = 0
		# We have one owner and we can free the reference 
		setRefCount(aMem,cVar,0)
		freeRef(aMem,cVar)
		return
	ok
	if nInDirectCount > 0
		# Circular Reference 
		incLostOwnerCount(aMem,cVar)
		# Check if this is the last owner where we can delete the reference
		if getLostOwnerCount(aMem,cVar) > nInDirectCount
			setRefCount(aMem,cVar,0)
			freeRef(aMem,cVar)
		ok
		return 
	ok 
	# Do the decrement 
		decRefCount(aMem,cVar)
	# Hide the Var 
		hideVar(aMem,cVar)

func decrementChildren aMem,cVar
	aChild = getNestedChildren(aMem,cVar)
	for child in aChild 
		if child != cVar 
			deleteVar(aMem,cVar)
		ok
	next

func freeRef aMem,cVar 
	decrementChildren(aMem,cVar)
	deleteVar(aMem,cVar) 

func deleteVar aMem,cVar 
	if getRefCount(aMem,cVar) > 0
		decrement(aMem,cVar)
		return 
	ok
	killVar(aMem,cVar)

func killVar aMem,cVar 
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_STATUS] = :Dead

func hideVar aMem,cVar 
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_STATUS] = :Hidden

func testDeleteVar
	testDeleteVarInMem1()
	testDeleteVarInMem2()
	testDeleteVarInMem3()

func testDeleteVarInMem1
	title("Test deleteVar(mem1,:a)")
	deleteVar(mem1,:a)
	printMemory(mem1,"")
	title("Test deleteVar(mem1,:mix)")
	deleteVar(mem1,:mix)
	printMemory(mem1,"")
	title("Test deleteVar(mem1,:mix2)")
	deleteVar(mem1,:mix2)
	printMemory(mem1,"")

func testDeleteVarInMem2
	title("Test deleteVar(mem2,:a)")
	deleteVar(mem2,:a)
	printMemory(mem2,"MEM2")
	title("Test deleteVar(mem2,:b)")
	deleteVar(mem2,:b)
	printMemory(mem2,"MEM2")

func testDeleteVarInMem3
	title("Test deleteVar(mem3,:n1)")
	deleteVar(mem3,:n1)
	printMemory(mem3,"")
	title("Test deleteVar(mem3,:n2)")
	deleteVar(mem3,:n2)
	printMemory(mem3,"")
	title("Test deleteVar(mem3,:n3)")
	deleteVar(mem3,:n3)
	printMemory(mem3,"")
	title("Test deleteVar(mem3,:n4)")
	deleteVar(mem3,:n4)
	printMemory(mem3,"")
	title("Test deleteVar(mem3,:n5)")
	deleteVar(mem3,:n5)
	printMemory(mem3,"")
