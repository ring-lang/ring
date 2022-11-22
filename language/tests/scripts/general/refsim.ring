/*
** Description : Reference Counting Simulator
**		 Playing with algorithms around it 
**		 The simulator can detect 
**		 	* Memory Leak
**		 	* Double Free 
**		 	* Some Circular References (Some Cases) 
**		 The algorithm is just experimental (i.e. not correct)
*/

#==========================#
#	 Constants 
#==========================#

C_LINESIZE 	 = 35
C_VARNAME        = 1
C_STATUS         = 2
C_REFCOUNT       = 3
C_VALUE          = 4
C_LOSTOWNERCOUNT = 5
C_MEMLEAK 	 = "[Memory Leak Detected!]"
C_NOMEMLEAK	 = "[No Memory Leak]"
C_DOUBLEFREE	 = "Double Free Error! - Variable: "

#==========================#
# Memory Variables & Values 
#==========================#

/*
	In this group of variables (Mem1)
	We have three varaibles a, mix & mix2 
	a have just some value [1,2,3]
	mix have a reference to a and two references to itself 
	mix2 is just another reference to mix
*/

mem1 = [
	[:a,:Live,1,[1,2,3],0],
	[:mix,:Live,3,[1,2,3,:a,:mix,:mix],0], 
	[:mix2,:Live,3,:mix,0]
]

/*
	In this group of variables (Mem2)
	We have two variables a,b 
	a have a reference to b 
	b have a reference to a
*/

mem2 = [
	[:a,:Live,1,[:b],0],
	[:b,:Live,1,[:a],0]
]

/*
	In this group of variables (Mem3)
	We have five variables n1,n2,n3,n4,n5 
	n1 have one reference to n2 
	n2 have a reference to n1 and a reference to n3 
	n3 have a reference to n2 and a reference to n4
	n4 have a reference to n3 and a reference to n5
	n5 have one reference to n4
*/

mem3 = [
	[:n1,:Live,1,[null,:n2],0],
	[:n2,:Live,2,[:n1,:n3],0],
	[:n3,:Live,2,[:n2,:n4],0],
	[:n4,:Live,2,[:n3,:n5],0],
	[:n5,:Live,1,[:n4,null],0]
]

/*
	In this group of variables 
	We mix between the previous groups 
	n1 have a reference to mix
	n3 have a reference to x 
	n5 have a reference to a
*/

mem4 = [
	[:x,:Live,2,[1,2,3],0],
	[:mix,:Live,3,[1,2,3,:x,:mix,:mix],0], 
	[:n1,:Live,1,[:mix,:n2],0],
	[:n2,:Live,2,[:n1,:n3],0],
	[:n3,:Live,2,[:n2,:n4,:x],0],
	[:n4,:Live,2,[:n3,:n5],0],
	[:n5,:Live,1,[:n4,:a],0],
	[:a,:Live,2,[:b],0],
	[:b,:Live,1,[:a],0]
]

/*
	In this group of variables 
	n5 have a reference to n1
*/

mem5 = [
	[:n1,:Live,1,[:n2],0],
	[:n2,:Live,1,[:n3],0],
	[:n3,:Live,1,[:n4],0],
	[:n4,:Live,1,[:n5],0],
	[:n5,:Live,1,[:n1],0]
]

#==========================#
# Testing 
#==========================#

/*
	Display the variables & their values 
*/

printMemory(mem1,"MEM1")
printMemory(mem2,"MEM2")
printMemory(mem3,"MEM3")
printMemory(mem4,"MEM4")
printMemory(mem5,"MEM5")

/*
	Test getting children at one level or at all nested levels 
*/

testGetChildren()
testGetNestedChildren()

/*
	Get Circular References count at one level 
	i.e. the variable have a reference to itself 
	Or at nested levels 
*/

testDirectCircularCount()
testIndirectCircularCount()

/*
	Test deleting variables to see how the algorithm will delete them 
	Or will keep them because they are used by other references 
*/

testDeleteVar()

/*
	Testing functions 
*/

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

func testDeleteVar
	testDeleteVarInMem1()
	testDeleteVarInMem2()
	testDeleteVarInMem3()
	testDeleteVarInMem4()
	testDeleteVarInMem5()

func testDeleteVarInMem1
	testDeleteVars("MEM1",mem1,[:a,:mix,:mix2])

func testDeleteVarInMem2
	testDeleteVars("MEM2",mem2,[:a,:b])

func testDeleteVarInMem3
	Mem3Copy = Mem3
	testDeleteVars("MEM3",mem3,[:n1,:n2,:n3,:n4,:n5])
	Mem3 = Mem3Copy 
	testDeleteVars("MEM3",mem3,[:n3,:n2,:n1,:n4,:n5])
	Mem3 = Mem3Copy 
	printMemory(mem3,"MEM3")
	testDeleteVarInMem("mem3",mem3,:n1)
	title("Test deleteItem(mem3,:n2,1)")
	deleteItem(mem3,:n2,1)
	testDeleteVars("MEM3",mem3,[:n2,:n3,:n4,:n5])

func testDeleteVarInMem4
	testDeleteVars("MEM4",mem4,[:n1,:n3,:x,:mix,:b,:n5,:a,:n3,:n4,:n2])

func testDeleteVarInMem5
	testDeleteVars("MEM5",mem5,[:n1,:n2,:n3,:n4,:n5])

func testDeleteVars(cMemTitle,aMem,aVars)
	printMemory(aMem,cMemTitle)
	for cVar in aVars 
		testDeleteVarInMem(cMemTitle,aMem,cVar)
	next
	checkMemoryLeak(aMem)

func testDeleteVarInMem(cMemTitle,aMem,cVar)
	title("Test deleteVar("+cMemTitle+",:"+cVar+")")
	deleteVar(aMem,cVar)
	printMemory(aMem,"")

#==========================#
# User Interface Functions
#==========================#

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

func ListAsString aList 
	if isString(aList) return aList ok
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

func PrintMemory aList,cTitle
	if cTitle != NULL
		title(cTitle)
	ok
	? size("Var",5) + size("S",5) + 
	  size("RC",3) + size("LO",3) +
	  size("Value",20)
	subLine()
	for vValue in aList
		# Print Variable Name
			see size(vValue[C_VARNAME],5)
		# Print Status
			see Size(UPPER(vValue[C_STATUS]),5)
		# Print Reference Count
			see Size(vValue[C_REFCOUNT],3)
		# Print Lost Owner Count 
			see Size(vValue[C_LOSTOWNERCOUNT],3)
		# Print the Value 
			see Size(ListAsString(vValue[C_VALUE]),20)
		see nl
	next

#==========================#
# Variables & Attributes  
#==========================#

func getVar aMem,cVar
	nIndex = find(aMem,cVar,C_VARNAME)
	if nIndex
		return nIndex
	ok
	raise( "Sorry, Can't find the variable: " + cVar)

func increment aMem,cVar
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_REFCOUNT]++

func removeVar aMem,cVar 
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_STATUS] = :LOST

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

#==========================#
# Children & Nested Children
#==========================#

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

#==========================#
# Checking Memory 
#==========================#

func checkMemoryLeak aMem 
	for var in aMem 
			if var[C_STATUS] != :Dead
				? C_MEMLEAK
				return 
			ok
	next
	? C_NOMEMLEAK

func checkDoubleFree aMem,cVar
	nIndex = getVar(aMem,cVar)
	if aMem[nIndex][C_STATUS] = :Dead 
		? C_DOUBLEFREE + cVar 
		return True
	ok
	return False

#==========================#
# Algorithm
#==========================#

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

func incLostOwnerCount aMem,cVar
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_LOSTOWNERCOUNT]++
	aMem[nIndex][C_STATUS] = :LOST
	aChild = getChildren(aMem,cVar)
	for child in aChild 
		if (child = NULL) or (child = cVar) loop ok
		nIndex = getVar(aMem,child)
		aMem[nIndex][C_LOSTOWNERCOUNT]++
	next

func checkAllOwnersAreLost aMem,cVar
	nIndex = getVar(aMem,cVar)
	aChild = getNestedChildren(aMem,cVar)
	for child in aChild 
		if (child = NULL) Or (child = cVar) loop ok
		nIndex = getVar(aMem,child)
		if ! ( aMem[nIndex][C_LOSTOWNERCOUNT] > aMem[nIndex][C_REFCOUNT] ) 
			return 
		ok
	next
	for child in aChild 
		if (child = NULL) or (child = cVar) loop ok
		nIndex = getVar(aMem,child)
		aMem[nIndex][C_LOSTOWNERCOUNT]++
		if aMem[nIndex][C_LOSTOWNERCOUNT] > aMem[nIndex][C_REFCOUNT]
			setRefCount(aMem,aMem[nIndex][C_VARNAME],0)
		ok
	next
	setRefCount(aMem,cVar,0)
	deleteVar(aMem,cVar)

func decrement aMem,cVar
	nDirectCount   = DirectCircularCount(aMem,cVar)   #  WithoutCountingTheRoot
	nInDirectCount = InDirectCircularCount(aMem,cVar) #  WithoutCountingTheRoot
	nRefCount      = getRefCount(aMem,cVar)
	if nRefCount - nDirectCount = 0
		# We have one owner and we can free the reference 
		setRefCount(aMem,cVar,0)
		deleteVar(aMem,cVar)
		return
	ok
	# Increment lost owner counter 
		incLostOwnerCount(aMem,cVar)
	# Do the decrement 
		decRefCount(aMem,cVar)
	# Hide the Var 
		removeVar(aMem,cVar)
	if (nInDirectCount > 0) and (nRefCount <= nDirectCount+nInDirectCount)
		# Circular Reference 
		# Check if this is the last owner where we can delete the reference
			if getLostOwnerCount(aMem,cVar)+1 >= nRefCount
				checkAllOwnersAreLost(aMem,cVar)
			ok
		return 
	ok 

func deleteVar aMem,cVar 
	if getRefCount(aMem,cVar) > 0
		decrement(aMem,cVar)
		return 
	ok
	killVar(aMem,cVar)

func killVar aMem,cVar 
	if checkDoubleFree(aMem,cVar) return ok
	nIndex = getVar(aMem,cVar)
	aMem[nIndex][C_STATUS] = :Dead
	# Each child with RefCount=0 is dead too
	deleteChildren(aMem,cVar)

func deleteChildren aMem,cVar
	aChild = getNestedChildren(aMem,cVar)
	for child in aChild 
		if (child = NULL) OR (child = cVar) loop ok
		nIndex = getVar(aMem,child)
		if aMem[nIndex][C_REFCOUNT] = 0
			aMem[nIndex][C_STATUS] = :Dead
		ok
	next

func deleteItem aMem,cVar,num 
	nIndex = getVar(aMem,cVar)
	cName = aMem[nIndex][C_VALUE][num] 
	del(aMem[nIndex][C_VALUE],num)
	nIndex = getVar(aMem,cName)
	aMem[nIndex][C_LOSTOWNERCOUNT]++
	if aMem[nIndex][C_LOSTOWNERCOUNT] > aMem[nIndex][C_REFCOUNT]
		aMem[nIndex][C_REFCOUNT] = 0
	ok
	deleteVar(aMem,cName)
