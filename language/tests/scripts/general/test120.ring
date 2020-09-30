# Test using variable += function()

$aClassesList  = ["test"]
C_FUNC_INS = 1
C_INS_CONSTANT = 1
C_CONSTANT_NAME = 2
$cFuncStart = "test:"

func main
	aList = [[1,"one"],[2,"two"]]
	test(aList)

func test aList
	cCode = ""
	cCode = GenRingConstants(aList)
	if len($aClassesList) = 0 return cCode Ok	# if no classes then Avoid generating code 
	cClassName = ""
	aClasses = []
	cCode += GenRingCodeFuncGetObjectPointer()
	? cCode

Func GenRingConstants aList
	cCode = ""
	for aFunc in aList
		if aFunc[C_FUNC_INS] = C_INS_CONSTANT
			cConstant = aFunc[C_CONSTANT_NAME]
			cCode += cConstant + " = " + $cFuncStart + "get_" + cConstant + "()" + nl
		ok
	next	
	ccode += "okkkkkkkkkkkkk"
	return cCode

Func GenRingCodeFuncGetObjectPointer
	return "
Func GetObjectPointerFromRingObject pObj
     if isobject(pObj)
	if isattribute(pObj,'pObject')
		return pObj.pObject
	else 
		raise('Error, The parameter is not a GUI object!')
	ok
     ok	
     return pObj		
"