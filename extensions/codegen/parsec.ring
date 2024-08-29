# Generate C Functions wrappers for the Ring programming language
# To execute : run parsec test.cf [test.c] [test.ring]
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

/* Data Structure & Usage
		C_FUNC_INS
	List [  C_INS_CODE    , C_FUNC_CODE  ]	
	     [  C_INS_FUNCTION, C_FUNC_OUTPUT, C_FUNC_NAME , C_FUNC_PARA , C_CLASS_NAME]
	     [  C_INS_REGISTER, C_FUNC_OUTPUT, C_FUNC_NAME , C_FUNC_PARA , C_CLASS_NAME]
	     [  C_INS_STRUCT  , C_FUNC_STRUCTDATA  ]	
	     [  C_INS_RUNCODE , C_FUNC_CODE ]
	     [  C_INS_CLASS   , C_FUNC_CODE ]
	     [  C_INS_CONSTANT, C_CONSTANT_NAME] 
	The first record is used for generating code written in <code> and </code>
	The second record is used for function prototype 
	The third record is used for function registration only <register> and </register>
	we can put comments between <comment> and </comment>
	The record no. 4 is used for defining functions to create/destroy
	struct. used for <struct> and </struct>
	We can put function start when we generate function for structures
	between <funcstart> and </funcstart>
	We can execute ring code during code generation by using
	<runcode> and </runcode>
	We can define classes between <class> and </class>
	using <nodllstartup> we can avoid #include "ring.h", We need this to write our startup code. 
	using <libinitfunc> we can change the function name that register the library functions
	using <ignorecpointertype> we can ignore pointer type check         
	using <filter> and </filter> we can include/exclude parts of the configuration file
	based on a condition
	for example <filter> iswindows() 
			... functions related to windows
		    </filter>
	in method prototype - when we use @ in the method name
	we mean that we have the same method with different parameters (As in C++)	
	Using <loadfile> filename.cf  we can separate the configuration to many files
	Using <runcodenow> we can execute code directly to defined variables for <filter>
	Using $globals we have global list for variables used by <runcodenow>
*/

load "stdlibcore.ring"

C_INS_FUNCTION  	= 1
C_INS_CODE		= 2
C_INS_REGISTER  	= 3
C_INS_COMMENT  		= 4
C_INS_STRUCT    	= 5
C_INS_FUNCSTART 	= 6
C_INS_RUNCODE   	= 7
C_INS_CLASS		= 8
C_INS_FILTER    	= 9
C_INS_CONSTANT  	= 10
C_INS_FREEFUNCTIONS 	= 11

C_FUNC_INS	= 1
C_FUNC_OUTPUT 	= 2
C_FUNC_NAME 	= 3
C_FUNC_PARA 	= 4

C_CLASS_NAME    = 5

C_FUNC_CODE 	= 2

C_FUNC_STRUCTDATA = 2

C_TYPE_VOID 	= 1
C_TYPE_NUMBER 	= 2
C_TYPE_STRING 	= 3
C_TYPE_POINTER 	= 4
C_TYPE_UNKNOWN 	= 5
C_TYPE_ENUM	= 6

$cFuncStart 	= ""
$aStructFuncs 	= []

aNumberTypes 	= ["int","float","double","bool",
"char","unsigned char","signed char","size_t",
"long int","int8_t","int16_t","int32_t","int64_t",
"uint8_t","uint16_t","uint32_t","uint64_t"]

aEnumTypes 	= []

aStringTypes 	= ["const char *","char const *","char *"]

# When we have function callback type we add it to the next list to avoid treating it as struct 
aFunctionCallback = []

# Extra Function Name (i.e. another name for the same function)
aExtraFunctionName = []		# list store another function name ["function name","new function name"]

aNewMethodName 		= []	# list store new method name ["class name","method name","new method name"]
C_NMN_CLASSNAME 	= 1
C_NMN_METHODNAME 	= 2
C_NMN_NEWMETHODNAME 	= 3

aBeforeReturn 	= []	# array include arrays ["type","code after calling the method
			# Ex: ["QString",".toStdString().c_str()"]
C_BR_TYPENAME 	= 1
C_BR_CODE     	= 2

$cClassName 	= ""
$cNewPara 	= ""
$cClassParent 	= ""

$aClassesList = []
C_CLASSESLIST_NAME 		= 1
C_CLASSESLIST_PARA 		= 2
C_CLASSESLIST_PARENT 		= 3
C_CLASSESLIST_CODENAME 		= 4
C_CLASSESLIST_PASSVMPOINTER 	= 5
C_CLASSESLIST_ABSTRACT 		= 6
C_CLASSESLIST_NONEW 		= 7
C_CLASSESLIST_STATICMETHODS	= 8
C_CLASSESLIST_MANAGED		= 9
C_CLASSESLIST_PASSNULL		= 10

$lNodllstartup = false	# when used, ring.h will not be included automatically
$cLibInitFunc = "ringlib_init"

$lIgnoreCPointerTypeCheck = false

$aMallocClassesList = []   # list contains classes to use malloc() instead of new when we return objects of this type (not pointer)

$lAddFreeFunctions = false 

# When we define constants 
	C_CONSTANT_INS			= 1
	C_CONSTANT_NAME 		= 2
	C_CONSTANT_TYPE_NUMBER 		= 1
	C_CONSTANT_TYPE_STRING 		= 2
	C_CONSTANT_TYPE_POINTER 	= 3
	$nDefaultConstantType 		= C_CONSTANT_TYPE_NUMBER	
	$cDefaultConstantPointerType 	= "void"

# Tabs 

C_TABS_1 = "	"
C_TABS_2 = "		"

# nl

if isWindows()
	nl = Windowsnl()
ok

# Global list to be used by command <runcodenow> when needed 

$globals = []

# Allow methods to return objects of these types that have classes without init() methods
# I.e. classes that uses (nonew) in their definition like QClipboard in RingQt

$aNoNewClassesException = []  

Func Main
	if len(sysargv) < 3
		See "Input : filename.cf is missing!" + nl
		bye
	ok
	cFile = sysargv[3]
	cStr = read(cFile)
	aList = str2list(cStr)
	aData = []
	cDir = currentdir()
	chdir( JustFilePath(cFile) )
	ProcessCommands(aData,aList)
	chdir(cDir)
	cCode = GenCode(aData)
	if len(sysargv) = 3
		see cCode
	else
		WriteFile(sysargv[4],cCode)
	ok
	if len(sysargv) = 5  # Generate Ring Classes for C++ Classes
		cCode = GenRingCode(aData)
		WriteFile(sysargv[5],cCode)
	ok

	if isWindows() and (len($aClassesList) > 0)
		cCode = ""
		for x in $aClassesList
			cCode += x[1] + nl
		next
		WriteFile("classes.txt",cCode)
	ok

Func ProcessCommands aData,aList
	lFlag = C_INS_FUNCTION
	nMax = len(aList)
	for t = 1 to nMax 
		cLine = aList[t]
		cLine = trim(cLine)
		nPos = substr(cLine,"#")
		if nPos > 0  
			if (substr(cLine,"#include") = 0 ) and ( substr(cLine,"#define") = 0 )
			cLine = trim(left(cLine,nPos-1))
			ok
		ok
		see "ReadLine : " + cLine + nl
		if cLine = NULL and lflag != C_INS_CODE
			loop
		but  lFlag = C_INS_COMMENT and cLine != "</comment>" 
			loop
		but  lFlag = C_INS_FILTER and cLine != "</filter>" 
			loop
		ok
		if cLine = "<code>"
			lflag = C_INS_CODE
			loop
		but cLine = "<register>"
			lflag = C_INS_REGISTER
			loop
		but cLine = "<comment>"
			lFlag = C_INS_COMMENT
			loop
		but cLine = "<struct>"
			lFlag = C_INS_STRUCT
			loop
		but cLine = "<funcstart>"
			lFlag = C_INS_FUNCSTART
			loop
		but cLine = "<runcode>"
			lFlag = C_INS_RUNCODE
			loop
		but cLine = "<class>"
			lFlag = C_INS_CLASS
			loop
		but cLine = "<constant>"
			lFlag = C_INS_CONSTANT
			loop
		but cLine = "<nodllstartup>"
			$lNodllstartup = true
			loop
		but cLine = "<addfreefunctionsprototype>"
			lFlag = C_INS_FREEFUNCTIONS
			aData + [C_INS_FREEFUNCTIONS]
			$lAddFreeFunctions = true
			loop
		but left(cLine,13) = "<libinitfunc>"
			$cLibInitFunc = trim(substr(cLine,14))
			loop
		but cLine = "<ignorecpointertype>"
			$lIgnoreCPointerTypeCheck = true
			loop
		but left(cLine,8) = "<filter>"
			cFilter = "lInclude = (" + trim(substr(cLine,9)) + ")"
			see "Execute Filter : " + cFilter + nl
			eval(cFilter)
			See "Filter output : " + lInclude + nl
			lFilterFlag = lFlag 
			if lInclude = false
				lFlag = C_INS_FILTER
			ok
			loop
		but cLine = "</filter>"
			lFlag = lFilterFlag 
			loop
		but cLine = "</constant>"
			cCodeToRun = '
			$nDefaultConstantType = C_CONSTANT_TYPE_NUMBER	
			$cDefaultConstantPointerType = "void *"
			'
			aData + [C_INS_RUNCODE,cCodeToRun]
			lFlag = C_INS_FUNCTION			
			loop
		but cLine = "</code>" or cLine = "</register>" or 
		    cLine = "</comment>" or cLine = "</struct>" or
		    cLine = "</funcstart>" or cLine = "</runcode>" or
		    cLine = "</class>"
			lFlag = C_INS_FUNCTION			
			loop
		but left(cLine,10) = "<loadfile>"
			cSubFileName = trim(substr(cLine,11))
			cSubFileStr = read(cSubFileName)
			aSubList = str2list(cSubFileStr)
			cDir = currentdir()
			chdir( JustFilePath(cSubFileName) )
			ProcessCommands(aData,aSubList)
			chdir(cDir)
			loop
		but left(lower(cLine),12)="<runcodenow>"		 
			cCodeNow = trim(substr(cLine,13))
			eval(cCodeNow)
			loop
		ok
		if lFlag = C_INS_FUNCTION 
			aData + ThreeParts(cLine)
			aData[len(aData)] + $cClassName
		but lFlag = C_INS_REGISTER
			aData + ThreeParts(cLine)
			aData[len(aData)][1] = C_INS_REGISTER
			aData[len(aData)] + $cClassName
		but lFlag = C_INS_CODE
			aData + [C_INS_CODE,cLine]
		but lFlag = C_INS_STRUCT
			aData + [C_INS_STRUCT,cLine]			
		but lFlag = C_INS_FUNCSTART
			$cFuncStart = trim(lower(cLine)) + "_"
		but lFlag = C_INS_RUNCODE
			aData + [C_INS_RUNCODE,cLine]
		but lFlag = C_INS_CLASS
			aData + [C_INS_CLASS,cLine]
			cValue = trim(cLine)
			if left(lower(cValue),5) = "name:"
				$cClassName = trim(substr(cValue,6))
			ok
		but lFlag = C_INS_CONSTANT
			aData + [C_INS_CONSTANT,cLine]
		ok
	next


Func WriteFile cFileName,cCode
	See "Writing file : " + cFileName + nl + 
	    "Size : " + len(cCode) + " Bytes" + nl
	write(cFileName,cCode)
	
Func ThreeParts cLine
	# Get three parts (output - function name - parameters)
	nPos1 = substr(cLine,"(")
	nPos2 = 0
	cFuncName = ""
	for x = nPos1 to 1 step -1
		switch cLine[x] 	
		on " " 
			nPos2 = x
			cFuncName = substr(cLine,nPos2+1,nPos1-nPos2-1)
			exit
		on "*"
			nPos2 = x + 1
			cFuncName = substr(cLine,nPos2,nPos1-nPos2)
			exit
		off
	next
	if nPos2 = 0 or cFuncName = ""
		Raise("Can't parse this line in the configuration file")
	ok
	cFuncOutput = left(cLine,nPos2-1)
	cFuncPara = substr(cLine,nPos1+1,len(cLine)-nPos1-1)
	return [C_INS_FUNCTION,cFuncOutput,cFuncName,ParaList(cFuncPara)]

Func ParaList cPara
	# convert string of parameters separated by , to a list
	aList = []
	nPos = substr(cPara,",") 
	while nPos
		aList + ParaTypeNoName( left(cPara,nPos-1) )
		cPara = substr(cPara,nPos+1)
		nPos = substr(cPara,",") 
	end
	aList + ParaTypeNoName( cPara )
	return aList

Func ParaTypeNoName cLine
	# get the parameter type and name, remove name and keep the type only
	cLine = trim(cLine)
	nMax = len(cLine)
	for x = nMax to 1 step -1
		if cLine[x] = "*" or cLine[x] = " "
			return left(cLine,x)
		ok
	next
	return cLine

Func VarTypeID cType
	# get type as string - return type as number
	# 1 = void 2 = Number   3 = String   4 = Pointer  5 - UnKnown
	cType = Trim(cType)
	if cType = "void"
		return C_TYPE_VOID
	but find(aNumberTypes,cType) > 0
		return C_TYPE_NUMBER
	but find(aEnumTypes,cType) > 0
		return C_TYPE_ENUM
	but find(aStringTypes,cType) > 0
		return C_TYPE_STRING
	but right(cType,1) = "*"
		return C_TYPE_POINTER
	else
		return C_TYPE_UNKNOWN
	ok

Func GenCode aList
	cCode = ""
	cCode += GenDLLStart()
	# Generate Classes List at first
	? "Prepare the lists..."
	nMax = len(aList)
	for t = 1 to nMax 
		aFunc = aList[t]
		if aFunc[C_FUNC_INS] = C_INS_CLASS
			cValue = trim(aFunc[C_INS_CODE])
			if left(lower(cValue),5) = "name:"
				cClassName = trim(substr(cValue,6))
				See "Class Name : " + cClassName + nl
				$aClassesList + [cClassName,"","","",false,false,false,false,false,false]
			ok
		ok
	next		
	? "Generate the code..."
	for t = 1 to nMax 
		aFunc = aList[t]
		if aFunc[C_FUNC_INS] = C_INS_FUNCTION
			if $cClassName = ""
				cCode += GenFuncCode(aFunc)
			else
				cCode += GenMethodCode(aFunc)
			ok
		but aFunc[C_FUNC_INS] = C_INS_CODE
			cCode += aFunc[C_INS_CODE] + nl
		but aFunc[C_FUNC_INS] = C_INS_STRUCT
			cCode += GenStruct(aFunc)
		but aFunc[C_FUNC_INS] = C_INS_CONSTANT
			cCode += GenConstant(aFunc)
		but aFunc[C_FUNC_INS] = C_INS_FREEFUNCTIONS
			cCode += GenFreeFuncForClassesPrototype(aList)
		but aFunc[C_FUNC_INS] = C_INS_RUNCODE
			Try
				eval(aFunc[C_INS_CODE])
			Catch
				See "Error executing code : " + aFunc[C_INS_CODE] + nl
			Done
		but aFunc[C_FUNC_INS] = C_INS_CLASS
			cValue = trim(aFunc[C_INS_CODE])
			if left(lower(cValue),5) = "name:"
				$cClassName = trim(substr(cValue,6))
				See "Class Name : " + $cClassName + nl
			but left(lower(cValue),5) = "para:"
				$cNewPara = trim(substr(cValue,6))
				See "Parameters : " + $cNewPara + nl
				nIndex = find($aClassesList,$cClassName,1)
				$aClassesList[nIndex][C_CLASSESLIST_PARA] = $cNewPara
			but left(lower(cValue),7) = "parent:"
				$cClassParent = trim(substr(cValue,8))
				See "Class Parent : " + $cClassParent + nl
				nIndex = find($aClassesList,$cClassName,1)
				$aClassesList[nIndex][C_CLASSESLIST_PARENT] = $cClassParent
			but left(lower(cValue),9) = "codename:"
				cCodeName = trim(substr(cValue,10))
				See "Class Code Name : " + cCodeName + nl
				nIndex = find($aClassesList,$cClassName,1)
				$aClassesList[nIndex][C_CLASSESLIST_CODENAME] = cCodeName
			but lower(cValue) = "passvmpointer"
				nIndex = find($aClassesList,$cClassName,1)
				$aClassesList[nIndex][C_CLASSESLIST_PASSVMPOINTER] = true
			but lower(cValue) = "passnullbeforevmpointer"
				nIndex = find($aClassesList,$cClassName,1)
				$aClassesList[nIndex][C_CLASSESLIST_PASSNULL] = true
			but lower(cValue) = "abstract"
				nIndex = find($aClassesList,$cClassName,1)
				$aClassesList[nIndex][C_CLASSESLIST_ABSTRACT] = true
				See "Class : Abstract" + nl		
			but lower(cValue) = "nonew"
				nIndex = find($aClassesList,$cClassName,1)
				$aClassesList[nIndex][C_CLASSESLIST_NONEW] = true
			but lower(cValue) = "staticmethods"
				nIndex = find($aClassesList,$cClassName,1)
				$aClassesList[nIndex][C_CLASSESLIST_STATICMETHODS] = true
			but lower(cValue) = "managed"
				nIndex = find($aClassesList,$cClassName,1)
				$aClassesList[nIndex][C_CLASSESLIST_MANAGED] = true
				See "Class : Managed" + nl		

			ok
		ok
	next
	cCode += GenNewFuncForClasses(aList)
	cCode += GenDeleteFuncForClasses(aList)
	if $lAddFreeFunctions 
		cCode += GenFreeFuncForClasses(aList)
	ok
	cCode += GenFuncPrototype(aList)
	return cCode

Func GenDLLStart
	if $lNodllstartup return "" ok
	return 	'#include "ring.h"' + nl + nl

Func GenFuncPrototype aList
	if $cLibInitFunc = "ringlib_init"
		cCode = "RING_LIBINIT" + nl 
	else
		cCode = "RING_API void "+$cLibInitFunc+"(RingState *pRingState)" + nl 		
	ok
	cCode += "{" + nl
	nMax = len(aList)
	for t=1 to nMax 
		aFunc = aList[t]
		if aFunc[C_FUNC_INS] = C_INS_FUNCTION OR aFunc[C_FUNC_INS] = C_INS_REGISTER
			if len(aFunc) >= C_CLASS_NAME
				cClassName = aFunc[C_CLASS_NAME]
			else
				cClassName = $cClassName
			ok
			cCode += C_TABS_1 + 'RING_API_REGISTER("' 
			cFuncName = aFunc[C_FUNC_NAME]
			cFuncName = SubStr(cFuncName,"@","_")
			if cClassName != ""
				cCode += lower(cClassName) + "_" 
			ok
			cCode += lower(cFuncName) + '",' +
				  "ring_"
			if cClassName != ""
				cCode += cClassName + "_" 
			ok
			cCode += cFuncName + ");" + nl
		ok
	next
	for cFunc in $aStructFuncs
			cCode += C_TABS_1 + 'RING_API_REGISTER("' + lower(cFunc) + '",' +
				  "ring_"+cFunc + ");" + nl
	next
	for aExtraFunc in aExtraFunctionName
			cCode += C_TABS_1 + 'RING_API_REGISTER("' + lower(aExtraFunc[1]) + '",' +
				  "ring_"+aExtraFunc[2] + ");" + nl
	next
	cCode += "}" + nl
	return cCode

Func GenFuncCode aList
	cFuncName = aList[C_FUNC_NAME]
	cFuncName = substr(cFuncName,"@","_")
	cCode = nl+"RING_FUNC(" + "ring_"+cFuncName + ")" + nl +
	 	"{" + nl +
	 	GenFuncCodeCheckParaCount(aList) +
		GenMethodCodeCheckIgnorePointerType() +
	 	GenFuncCodeCheckParaType(aList) +
		GenFuncCodeCallFunc(aList)+
	 	"}" + nl + nl 
	return cCode

Func GenFuncCodeCheckParaCount aList
	aPara = aList[C_FUNC_PARA]
	nCount = ParaCount(aPara)
	cCode = C_TABS_1 + "if ( RING_API_PARACOUNT != "+nCount+" ) {" + nl +
		C_TABS_2 +"RING_API_ERROR("
	switch nCount
	on 1 
		cCode += "RING_API_MISS1PARA"
	on 2
		cCode += "RING_API_MISS2PARA"
	on 3
		cCode += "RING_API_MISS3PARA"
	on 4
		cCode += "RING_API_MISS4PARA"
	other
		cCode += "RING_API_BADPARACOUNT"
	off
	cCode += ");" + nl +
		C_TABS_2 +"return ;" + nl +
		C_TABS_1 +"}" + nl
	return cCode

Func GenFuncCodeCheckParaType aList
	cCode = ""
	aPara = aList[C_FUNC_PARA]
	nCount = ParaCount(aPara)
	if nCount > 0
		nMax = len(aPara)
		for t = 1 to nMax
			x = aPara[t]
			switch VarTypeID(x)
			on C_TYPE_NUMBER
				cCode += C_TABS_1 + "if ( ! RING_API_ISNUMBER("+t+") ) {" + nl +
					 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
					 C_TABS_2 + "return ;" + nl +
					 C_TABS_1 + "}" + nl
			on C_TYPE_ENUM
				cCode += C_TABS_1 + "if ( ! RING_API_ISNUMBER("+t+") ) {" + nl +
					 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
					 C_TABS_2 + "return ;" + nl +
					 C_TABS_1 + "}" + nl
			on C_TYPE_STRING
				cCode += C_TABS_1 + "if ( ! RING_API_ISSTRING("+t+") ) {" + nl +
					 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
					 C_TABS_2 + "return ;" + nl +
					 C_TABS_1 + "}" + nl
			on C_TYPE_POINTER
				if GenPointerType(x) = "int" or GenPointerType(x) = "double"
					# pointer to int, i.e. int *
					cCode += C_TABS_1 + "if ( ! RING_API_ISSTRING("+t+") ) {" + nl +
						 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
						 C_TABS_2 + "return ;" + nl +
						 C_TABS_1 + "}" + nl
				else
					cCode += C_TABS_1 + "if ( ! RING_API_ISCPOINTER("+t+") ) {" + nl +
						 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
						 C_TABS_2 + "return ;" + nl +
						 C_TABS_1 + "}" + nl
				ok
			off
		next
	ok
	return cCode

Func GenFuncCodeCallFunc aList
	cCode = C_TABS_1
	lRet = true
	lUNKNOWN = false
	lRetPointer = false
	switch VarTypeID(aList[C_FUNC_OUTPUT])
		on C_TYPE_VOID
			lRet = false
		on C_TYPE_NUMBER
			cCode += "RING_API_RETNUMBER("
		on C_TYPE_ENUM
			cCode += "RING_API_RETNUMBER("
		on C_TYPE_STRING
			cCode += "RING_API_RETSTRING("
		on C_TYPE_POINTER
			lRetPointer = true
			cCode += "RING_API_RETCPOINTER("
		on C_TYPE_UNKNOWN
			cCode += "{" + nl + 
				C_TABS_2 + aList[C_FUNC_OUTPUT] + " *pValue ; " + nl +
				C_TABS_2 + "pValue = (" + aList[C_FUNC_OUTPUT] + 
				" *) RING_API_MALLOC(sizeof("+aList[C_FUNC_OUTPUT]+")) ;" + nl +
				C_TABS_2 + "*pValue = " 
			lRet = false
			lUNKNOWN = true
	off

	cFuncName = aList[C_FUNC_NAME]
	nPos = SubStr(cFuncName,"@")
	if nPos > 0
		cFuncName = left(cFuncName,nPos-1)
	ok

	cCode += cFuncName + "(" +
		GenFuncCodeGetParaValues(aList) + ")"
	if lRet		
		if lRetPointer
			cCode += ',"' + GenPointerType(aList[C_FUNC_OUTPUT]) + '"'
		ok
		cCode += ")"
	ok
	cCode +=  ";" + nl
	cCode += GenFuncCodeFreeNotAssignedPointers(aList)
	if lUNKNOWN 	# Generate code to convert struct to struct *
		cCode += C_TABS_2 + 'RING_API_RETMANAGEDCPOINTER(pValue,"' + trim(aList[C_FUNC_OUTPUT]) +
			'",RING_API_FREEFUNC' +
			 ');' + nl + C_TABS_1 + "}" + nl

	ok
	# Accept int values, when the C function take int * as parameter
	cCode += GenFuncCodeGetIntValues(aList)
	return cCode

Func GenFuncCodeGetParaValues aList
	cCode = ""
	aPara = aList[C_FUNC_PARA]
	nCount = ParaCount(aPara)
	if nCount > 0
		nMax = len(aPara)
		for t = 1 to nMax
			if t > 1	# separator between parameters	
				cCode += ","
			ok
			x = aPara[t]
			switch VarTypeID(x)
			on C_TYPE_NUMBER
				cCode += " (" + x + ") " + "RING_API_GETNUMBER(" + t + ")"
			on C_TYPE_ENUM
				cCode += " (" + x + ") " + " (int) RING_API_GETNUMBER(" + t + ")"
			on C_TYPE_STRING
				cCode += "RING_API_GETSTRING(" + t + ")"
			on C_TYPE_POINTER
				if GenPointerType(x) = "int"
					cCode += "RING_API_GETINTPOINTER(" + t + ")"
				but GenPointerType(x) = "double"
					cCode += "RING_API_GETDOUBLEPOINTER(" + t + ")"
				else
					if not IsPointer2Pointer(x)
						cCode += "(" + GenPointerType(x) + " *) RING_API_GETCPOINTER(" + t +',"'+GenPointerType(x)+ '")'
					else
						cCode += "(" + GenPointerType(x) + " **) RING_API_GETCPOINTER2POINTER(" + t +',"'+GenPointerType(x)+ '")'
					ok
				ok
			on C_TYPE_UNKNOWN
				if find(aFunctionCallback,trim(x))
					# Here we avoid the cast 
					cCode += "RING_API_GETCPOINTER(" + t +',"'+trim(x)+'")'
				else 
					# Struct 
					cCode += "* (" + x + " *) RING_API_GETCPOINTER(" + t +',"'+trim(x)+'")'
				ok
			off
		next
	ok
	return cCode

Func GenFuncCodeGetIntValues aList
	cCode = ""
	aPara = aList[C_FUNC_PARA]
	nCount = ParaCount(aPara)
	if nCount > 0
		nMax = len(aPara)
		for t = 1 to nMax
			x = aPara[t]
			if VarTypeID(x) = C_TYPE_POINTER
				if GenPointerType(x) = "int"
					cCode += C_TABS_1 + 
					"RING_API_ACCEPTINTVALUE(" + t + ") ;" + nl
				ok
			ok
		next
	ok
	return cCode

Func GenFuncCodeFreeNotAssignedPointers aList
	cCode = ""
	aPara = aList[C_FUNC_PARA]
	nCount = ParaCount(aPara)
	if nCount > 0
		nMax = len(aPara)
		for t = 1 to nMax
			x = aPara[t]
			if VarTypeID(x) = C_TYPE_UNKNOWN
				cCode += C_TABS_1 + "if (RING_API_ISCPOINTERNOTASSIGNED(" + t + "))" + nl
				cCode += C_TABS_2 + "RING_API_FREE(RING_API_GETCPOINTER("+t+',"'+GenPointerType(x)+'"));' + nl
			ok
		next
	ok
	return cCode

Func IsPointer2Pointer x
	if substr(x,"**")
		return True
	ok
	return false

Func GenPointerType x
	x = substr(x,"const","")
	x = substr(x,"*","")
	x = trim(x)
	return x

Func GenTabs x
	return copy(char(9),x)

Func ParaCount aList
	# get list of parameters, return parameters count
	if len(aList) > 1
		return len(aList)
	else
		if VarTypeID(alist[1]) = C_TYPE_VOID
			return 0
		else
			return 1
		ok
	ok

Func GenStruct	aFunc
	# this function parse struct information 
	# struct_name { struct_members }
	# strucut_members are separated by comma (,)	
	aStructMembers = []
	cLine = aFunc[C_FUNC_STRUCTDATA]
	nPos = substr(cLine,"{")
	if nPos > 0
		# Get Struct Members and store it in aStructMembers
		cStruct = trim(left(cLine,nPos-1))		
		cStructMembers = substr(cLine,nPos+1)
		nPos = substr(cStructMembers,"}")
		if nPos > 0
			cStructMembers = left(cStructMembers,nPos-1)
			cStructMembers = substr(cStructMembers,",",nl)
			aStructMembers = str2list(cStructMembers)
			for x in aStructMembers x = trim(x) next		
		ok
	else
		cStruct = trim(cLine)
	ok
	# We have struct_name in cStruct and struct_members in aStructMembers
	cCode = ""
	# Generate Functions to Create the Struct
	cFuncName = $cFuncStart+"new_"+lower(cStruct)
	$aStructFuncs + cFuncName
	cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
			"{" + nl + 
			C_TABS_1 + cStruct + " *pMyPointer ;" + nl +
			C_TABS_1 + "pMyPointer = (" + cStruct + " *) RING_API_MALLOC(sizeof(" +
			cStruct + ")) ;" + nl +
			C_TABS_1 + "if (pMyPointer == NULL) " + nl +
			C_TABS_1 + "{" + nl +
			C_TABS_2 + "RING_API_ERROR(RING_OOM);" + nl + 
			C_TABS_2 + "return ;" + nl +
			C_TABS_1 + "}" + nl +
			C_TABS_1 + "RING_API_RETCPOINTER(pMyPointer,"+
			'"'+cStruct  +'");' + nl +
			"}" + nl + nl
	# Generate Functions to Create the Struct (Managed Pointer)
	cFuncName = $cFuncStart+"new_managed_"+lower(cStruct)
	$aStructFuncs + cFuncName
	cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
			"{" + nl + 
			C_TABS_1 + cStruct + " *pMyPointer ;" + nl +
			C_TABS_1 + "pMyPointer = (" + cStruct + " *) RING_API_MALLOC(sizeof(" +
			cStruct + ")) ;" + nl +
			C_TABS_1 + "if (pMyPointer == NULL) " + nl +
			C_TABS_1 + "{" + nl +
			C_TABS_2 + "RING_API_ERROR(RING_OOM);" + nl + 
			C_TABS_2 + "return ;" + nl +
			C_TABS_1 + "}" + nl +
			C_TABS_1 + "RING_API_RETMANAGEDCPOINTER(pMyPointer,"+
			'"'+cStruct  +'",RING_API_FREEFUNC);' + nl +
			"}" + nl + nl
	# Generate Functions to Destroy the Struct
	cFuncName = $cFuncStart+"destroy_"+lower(cStruct)
	$aStructFuncs + cFuncName
	cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
			"{" + nl + 
			C_TABS_1 + cStruct + " *pMyPointer ;" + nl +
			C_TABS_1 + "if ( RING_API_PARACOUNT != 1 ) {" + nl +
			C_TABS_2 +"RING_API_ERROR(RING_API_MISS1PARA) ;" + nl +
			C_TABS_2 + "return ;" + nl +
			C_TABS_1 + "}" + nl +
			C_TABS_1 + "if ( ! RING_API_ISCPOINTER(1) ) { " + nl +
			C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
			C_TABS_2 + "return ;" + nl + 
			C_TABS_1 + "}" + nl +
			C_TABS_1 + "pMyPointer = ("+ cStruct + "*) RING_API_GETCPOINTER(1," +
			'"'+cStruct  +'");' + nl +
			C_TABS_1 + "if (pMyPointer != NULL) {" + nl +
			C_TABS_2 + "RING_API_FREE(pMyPointer) ;" + nl +		
			C_TABS_2 + "RING_API_SETNULLPOINTER(1);" + nl +
			C_TABS_1 + "}" + nl +				
			"}" + nl + nl
	# We expect the members to be of type (numbers) or (pointers)
	for x in aStructMembers
		cItem = substr(x,".","_")
		nPointer = substr(cItem,"*")
		# Check if the Item is a String
		cItemLower = lower(cItem)
		lTypeIsString = False
		if startswith(cItemLower,"const char * ") 
			lTypeIsString = True
			cMemberName = substr(cItem,len("const char * ")+1)
		but startsWith(cItemLower,"string ")
			lTypeIsString = True		
			cMemberName = substr(cItem,len("string ")+1)
		ok
		if lTypeIsString
			# Generate Functions to Get Struct Members Values
			cFuncName = $cFuncStart+"get_"+lower(cStruct)+"_"+cMemberName
			$aStructFuncs + cFuncName
			cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
				"{" + nl + 
				C_TABS_1 + cStruct + " *pMyPointer ;" + nl +
				C_TABS_1 + "if ( RING_API_PARACOUNT != 1 ) {" + nl +
				C_TABS_2 +"RING_API_ERROR(RING_API_MISS1PARA) ;" + nl +
				C_TABS_2 + "return ;" + nl +
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "if ( ! RING_API_ISCPOINTER(1) ) { " + nl +
				C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				C_TABS_2 + "return ;" + nl + 
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "pMyPointer = ("+cStruct + " *) RING_API_GETCPOINTER(1," +
				'"'+cStruct  +'");' + nl 			
			if startswith(cItemLower,"const char * ") 
				cCode += C_TABS_1 + "RING_API_RETSTRING(pMyPointer->"+cMemberName+");" + nl 
			else
				cCode += C_TABS_1 + "RING_API_RETSTRING(pMyPointer->"+cMemberName+".c_str());" + nl 
			ok
			cCode += "}" + nl + nl
			# Generate Functions to Set Struct Members Value
			cFuncName = $cFuncStart+"set_"+lower(cStruct)+"_"+cMemberName
			$aStructFuncs + cFuncName
			cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
				"{" + nl + 
				C_TABS_1 + cStruct + " *pMyPointer ;" + nl +
				C_TABS_1 + "if ( RING_API_PARACOUNT != 2 ) {" + nl +
				C_TABS_2 +"RING_API_ERROR(RING_API_MISS2PARA) ;" + nl +
				C_TABS_2 + "return ;" + nl +
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "if ( ! RING_API_ISCPOINTER(1) ) { " + nl +
				C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				C_TABS_2 + "return ;" + nl + 
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "if ( ! RING_API_ISNUMBER(2) ) { " + nl +
				C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				C_TABS_2 + "return ;" + nl + 
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "pMyPointer = ("+ cStruct +" *) RING_API_GETCPOINTER(1," +
				'"'+cStruct  +'");' + nl +			
				C_TABS_1 + "pMyPointer->"+cMemberName+" = "+"RING_API_GETSTRING(2);" + nl +
				"}" + nl + nl

			loop		
		ok
		if not nPointer	# The item is number - not pointer
			# Generate Functions to Get Struct Members Values
			cFuncName = $cFuncStart+"get_"+lower(cStruct)+"_"+cItem
			$aStructFuncs + cFuncName
			cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
				"{" + nl + 
				C_TABS_1 + cStruct + " *pMyPointer ;" + nl +
				C_TABS_1 + "if ( RING_API_PARACOUNT != 1 ) {" + nl +
				C_TABS_2 +"RING_API_ERROR(RING_API_MISS1PARA) ;" + nl +
				C_TABS_2 + "return ;" + nl +
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "if ( ! RING_API_ISCPOINTER(1) ) { " + nl +
				C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				C_TABS_2 + "return ;" + nl + 
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "pMyPointer = RING_API_GETCPOINTER(1," +
				'"'+cStruct  +'");' + nl +			
				C_TABS_1 + "RING_API_RETNUMBER(pMyPointer->"+x+");" + nl +
				"}" + nl + nl
			# Generate Functions to Set Struct Members Value
			cFuncName = $cFuncStart+"set_"+lower(cStruct)+"_"+cItem
			$aStructFuncs + cFuncName
			cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
				"{" + nl + 
				C_TABS_1 + cStruct + " *pMyPointer ;" + nl +
				C_TABS_1 + "if ( RING_API_PARACOUNT != 2 ) {" + nl +
				C_TABS_2 +"RING_API_ERROR(RING_API_MISS2PARA) ;" + nl +
				C_TABS_2 + "return ;" + nl +
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "if ( ! RING_API_ISCPOINTER(1) ) { " + nl +
				C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				C_TABS_2 + "return ;" + nl + 
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "if ( ! RING_API_ISNUMBER(2) ) { " + nl +
				C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				C_TABS_2 + "return ;" + nl + 
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "pMyPointer = RING_API_GETCPOINTER(1," +
				'"'+cStruct  +'");' + nl +			
				C_TABS_1 + "pMyPointer->"+x+" = "+"RING_API_GETNUMBER(2);" + nl +
				"}" + nl + nl
		else
			cPointerType = left(cItem,nPointer)
			cPointerTypeRet = trim(substr(cPointerType,"*",""))
			cItem = substr(cItem,nPointer+1)
			x = substr(x,nPointer+1)
			# Generate Functions to Get Struct Members Values
			cFuncName = $cFuncStart+"get_"+lower(cStruct)+"_"+cItem
			$aStructFuncs + cFuncName
			cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
				"{" + nl + 
				C_TABS_1 + cStruct + " *pMyPointer ;" + nl +
				C_TABS_1 + "if ( RING_API_PARACOUNT != 1 ) {" + nl +
				C_TABS_2 +"RING_API_ERROR(RING_API_MISS1PARA) ;" + nl +
				C_TABS_2 + "return ;" + nl +
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "if ( ! RING_API_ISCPOINTER(1) ) { " + nl +
				C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				C_TABS_2 + "return ;" + nl + 
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "pMyPointer = RING_API_GETCPOINTER(1," +
				'"'+cStruct  +'");' + nl +			
				C_TABS_1 + "RING_API_RETCPOINTER(pMyPointer->"+x+',"'+cPointerTypeRet+'"'+");" + nl +
				"}" + nl + nl
			# Generate Functions to Set Struct Members Value
			cFuncName = $cFuncStart+"set_"+lower(cStruct)+"_"+cItem
			$aStructFuncs + cFuncName
			cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
				"{" + nl + 
				C_TABS_1 + cStruct + " *pMyPointer ;" + nl +
				C_TABS_1 + "if ( RING_API_PARACOUNT != 2 ) {" + nl +
				C_TABS_2 +"RING_API_ERROR(RING_API_MISS2PARA) ;" + nl +
				C_TABS_2 + "return ;" + nl +
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "if ( ! RING_API_ISCPOINTER(1) ) { " + nl +
				C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				C_TABS_2 + "return ;" + nl + 
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "if ( ! RING_API_ISCPOINTER(2) ) { " + nl +
				C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				C_TABS_2 + "return ;" + nl + 
				C_TABS_1 + "}" + nl +
				C_TABS_1 + "pMyPointer = RING_API_GETCPOINTER(1," +
				'"'+cStruct  +'");' + nl +			
				C_TABS_1 + "pMyPointer->"+x+" = ("+cPointerType+") RING_API_GETCPOINTER(2,"+'"'+cPointerTypeRet+'"'+");" + nl +
				"}" + nl + nl			
		ok
	next
	return cCode

Func GenConstant aFunc
	# this function get constant information 
	# and generate function to get the constant value
	cConstant = aFunc[C_CONSTANT_NAME]
	cCode = ""
	# Generate Functions to Get The Constant Value
	cFuncName = $cFuncStart+"get_"+lower(cConstant)
	$aStructFuncs + cFuncName
	cCode += "RING_FUNC(ring_"+cFuncName+")" + nl +
		"{" + nl 
	switch $nDefaultConstantType
	on C_CONSTANT_TYPE_NUMBER	
		cCode += C_TABS_1 + "RING_API_RETNUMBER("+cConstant+");" + nl 
	on C_CONSTANT_TYPE_STRING
		cCode += C_TABS_1 + "RING_API_RETSTRING("+cConstant+");" + nl 
	on C_CONSTANT_TYPE_POINTER
		cConstantPointerType = ',"' + $cDefaultConstantPointerType + '"'
		cCode += C_TABS_1 + "RING_API_RETCPOINTER("+cConstant+cConstantPointerType+");" + nl 
	off
	cCode += "}" + nl + nl
	return cCode


Func GenMethodCode aList

	cFuncName = aList[C_FUNC_NAME]
	cFuncName = substr(cFuncName,"@","_")
	
	cCode = nl+"RING_FUNC(" + "ring_"+$cClassName+"_"+
				cFuncName + ")" + nl +
	 	"{" + nl +
	 	GenMethodCodeCheckParaCount(aList) +
		GenMethodCodeCheckIgnorePointerType() +
	 	GenMethodCodeCheckParaType(aList) +
		GenMethodCodeCallFunc(aList)+
	 	"}" + nl + nl 
	return cCode


Func GenMethodCodeCheckIgnorePointerType
	if $lIgnoreCPointerTypeCheck	
		return C_TABS_1 + "RING_API_IGNORECPOINTERTYPE ;" + nl
	ok

Func GenMethodCodeGetClassCodeName
	nIndex = find($aClassesList,$cClassName,1)
	if $aClassesList[nIndex][C_CLASSESLIST_CODENAME] != NULL
		cClassCodeName = $aClassesList[nIndex][C_CLASSESLIST_CODENAME]
	else
		cClassCodeName = $aClassesList[nIndex][C_CLASSESLIST_NAME]
	ok
	return cClassCodeName

Func GenMethodCodeISStaticMethods
	nIndex = find($aClassesList,$cClassName,1)
	return $aClassesList[nIndex][C_CLASSESLIST_STATICMETHODS]

Func GenMethodCodeCheckParaCount aList

	cClassCodeName = GenMethodCodeGetClassCodeName()

	aPara = aList[C_FUNC_PARA]
	if GenMethodCodeISStaticMethods()
		nCount = ParaCount(aPara)
		cCode = C_TABS_1 + "if ( RING_API_PARACOUNT != "+nCount+" ) {" + nl +
		 C_TABS_2 +"RING_API_ERROR("
	else
		nCount = ParaCount(aPara) + 1
		cCode =  C_TABS_1 + cClassCodeName + " *pObject ;" + nl +
		 	 C_TABS_1 + "if ( RING_API_PARACOUNT != "+nCount+" ) {" + nl +
			 C_TABS_2 +"RING_API_ERROR("
	ok
	switch nCount
	on 1 
		cCode += "RING_API_MISS1PARA"
	on 2
		cCode += "RING_API_MISS2PARA"
	on 3
		cCode += "RING_API_MISS3PARA"
	on 4
		cCode += "RING_API_MISS4PARA"
	other
		cCode += "RING_API_BADPARACOUNT"
	off
	cCode += ");" + nl +
		C_TABS_2 +"return ;" + nl +
		C_TABS_1 +"}" + nl
	return cCode

Func GenMethodCodeCheckParaType aList
	cClassCodeName = GenMethodCodeGetClassCodeName()
	if GenMethodCodeISStaticMethods()
		cCode = ""
	else 
		cCode = C_TABS_1 + "if ( ! RING_API_ISCPOINTER(1) ) {" + nl +
				 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
				 C_TABS_2 + "return ;" + nl +
				 C_TABS_1 + "}" + nl +
				 C_TABS_1 + "pObject = ("+
				 cClassCodeName+" *) RING_API_GETCPOINTER(1," + '"'+
				 $cClassName+'"' + ");"+nl
	ok
	aPara = aList[C_FUNC_PARA]
	nCount = ParaCount(aPara)
	if nCount > 0
		nMax = len(aPara)
		for t = 1 to nMax
			x = aPara[t]
			if not GenMethodCodeISStaticMethods()
				t++ # avoid the object pointer
			ok
			switch VarTypeID(x)
			on C_TYPE_NUMBER
				cCode += C_TABS_1 + "if ( ! RING_API_ISNUMBER("+t+") ) {" + nl +
					 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
					 C_TABS_2 + "return ;" + nl +
					 C_TABS_1 + "}" + nl
			on C_TYPE_ENUM
				cCode += C_TABS_1 + "if ( ! RING_API_ISNUMBER("+t+") ) {" + nl +
					 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
					 C_TABS_2 + "return ;" + nl +
					 C_TABS_1 + "}" + nl
			on C_TYPE_STRING
				cCode += C_TABS_1 + "if ( ! RING_API_ISSTRING("+t+") ) {" + nl +
					 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
					 C_TABS_2 + "return ;" + nl +
					 C_TABS_1 + "}" + nl
			on C_TYPE_POINTER
				if GenPointerType(x) = "int" or GenPointerType(x) = "double"
					# pointer to int, i.e. int *
					cCode += C_TABS_1 + "if ( ! RING_API_ISSTRING("+t+") ) {" + nl +
						 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
						 C_TABS_2 + "return ;" + nl +
						 C_TABS_1 + "}" + nl
				else
					cCode += C_TABS_1 + "if ( ! RING_API_ISCPOINTER("+t+") ) {" + nl +
						 C_TABS_2 + "RING_API_ERROR(RING_API_BADPARATYPE);" + nl +
						 C_TABS_2 + "return ;" + nl +
						 C_TABS_1 + "}" + nl
				ok
			off
			if not GenMethodCodeISStaticMethods()
				t-- # ignore effect of avoiding the object pointer
			ok
		next
	ok
	return cCode

Func GenMethodCodeCallFunc aList
	cFuncName = aList[C_FUNC_NAME]
	nPos = SubStr(cFuncName,"@")
	if nPos > 0
		cFuncName = left(cFuncName,nPos-1)
	ok
	cCode = C_TABS_1
	lRet = true
	lUNKNOWN = false
	lRetPointer = false
	lObject = false
	switch VarTypeID(aList[C_FUNC_OUTPUT])
		on C_TYPE_VOID
			lRet = false
		on C_TYPE_NUMBER
			cCode += "RING_API_RETNUMBER("
		on C_TYPE_ENUM
			cCode += "RING_API_RETNUMBER("
		on C_TYPE_STRING
			cCode += "RING_API_RETSTRING("
		on C_TYPE_POINTER
			lRetPointer = true
			cCode += "RING_API_RETCPOINTER("
		on C_TYPE_UNKNOWN
			if ( find($aClassesList,trim(aList[C_FUNC_OUTPUT]),1) > 0 ) and ( find($aMallocClassesList,trim(aList[C_FUNC_OUTPUT])) = 0 )
				cCode += "{" + nl + 
				C_TABS_2 + aList[C_FUNC_OUTPUT] + " *pValue ; " + nl +
				C_TABS_2 + "pValue = new " + aList[C_FUNC_OUTPUT] + 
				"() ;" + nl +
				C_TABS_2 + "*pValue = " 
				lObject = true
			else
				cCode += "{" + nl + 
				C_TABS_2 + aList[C_FUNC_OUTPUT] + " *pValue ; " + nl +
				C_TABS_2 + "pValue = (" + aList[C_FUNC_OUTPUT] + 
				" *) RING_API_MALLOC(sizeof("+aList[C_FUNC_OUTPUT]+")) ;" + nl +
				C_TABS_2 + "*pValue = " 
			ok
			lRet = false
			lUNKNOWN = true
	off
	if GenMethodCodeISStaticMethods()
		cClassCodeName = GenMethodCodeGetClassCodeName()
		cCode += cClassCodeName + "::"+ cFuncName + "(" +
		GenMethodCodeGetParaValues(aList) + ")"
	else 
	cCode += "pObject->"+ cFuncName + "(" +
		GenMethodCodeGetParaValues(aList) + ")"
	ok

	# Check before return list for any 
		if len(aBeforeReturn) > 0
			nIndex = find(aBeforeReturn,trim(aList[C_FUNC_OUTPUT]),C_BR_TYPENAME)
			if nIndex > 0
				cCode += aBeforeReturn[nIndex][C_BR_CODE]
			ok
		ok
	
	if lRet		
		if lRetPointer
			cCode += ',"' + GenPointerType(aList[C_FUNC_OUTPUT]) + '"'
		ok
		cCode += ")"
	ok
	cCode +=  ";" + nl
	
	cCode += GenMethodCodeFreeNotAssignedPointers(aList)

	if lUNKNOWN 	# Generate code to convert struct to struct *
		if lObject and $lAddFreeFunctions
			cCode += C_TABS_2 + 'RING_API_RETMANAGEDCPOINTER(pValue,"' + trim(aList[C_FUNC_OUTPUT]) +
				'",ring_'+ trim(aList[C_FUNC_OUTPUT]) + "_freefunc" +
				 ');' + nl + C_TABS_1 + "}" + nl
		else 
			cCode += C_TABS_2 + 'RING_API_RETMANAGEDCPOINTER(pValue,"' + trim(aList[C_FUNC_OUTPUT]) +
				'",RING_API_FREEFUNC' +
				 ');' + nl + C_TABS_1 + "}" + nl
		ok
	ok
	# Accept int values, when the C function take int * as parameter
	cCode += GenFuncCodeGetIntValues(aList)
	return cCode

Func GenMethodCodeFreeNotAssignedPointers aList
	cCode = ""
	aPara = aList[C_FUNC_PARA]
	nCount = ParaCount(aPara)
	if nCount > 0
		nMax = len(aPara)
		for t = 1 to nMax
			x = aPara[t]
			t++ # avoid the object pointer
			if VarTypeID(x) = C_TYPE_UNKNOWN
				cCode += C_TABS_1 + "if (RING_API_ISCPOINTERNOTASSIGNED(" + t + "))" + nl
				cCode += C_TABS_2 + "RING_API_FREE(RING_API_GETCPOINTER("+t+',"'+GenPointerType(x)+'"));' + nl
			ok
			t-- # Ignore the effect of avoiding the object pointer
		next
	ok
	return cCode

Func GenMethodCodeGetParaValues aList
	cCode = ""
	aPara = aList[C_FUNC_PARA]
	nCount = ParaCount(aPara)
	if nCount > 0
		nMax = len(aPara)
		for t = 1 to nMax
			if t > 1	# separator between parameters	
				cCode += ","
			ok
			x = aPara[t]
			if not GenMethodCodeISStaticMethods()
				t++ # avoid the object pointer
			ok
			switch VarTypeID(x)
			on C_TYPE_NUMBER
				cCode += " (" + x + ") " + "RING_API_GETNUMBER(" + t + ")"
			on C_TYPE_ENUM
				cCode += " (" + x + ") " + " (int) RING_API_GETNUMBER(" + t + ")"
			on C_TYPE_STRING
				cCode += "RING_API_GETSTRING(" + t + ")"
			on C_TYPE_POINTER
				if GenPointerType(x) = "int"
					cCode += "RING_API_GETINTPOINTER(" + t + ")"
				but GenPointerType(x) = "double"
					cCode += "RING_API_GETDOUBLEPOINTER(" + t + ")"
				else
					cCode += "(" + GenPointerType(x) + " *) " + 
					"RING_API_GETCPOINTER(" + t +',"'+GenPointerType(x)+ '")'
				ok
			on C_TYPE_UNKNOWN
				cCode += "* (" + x + " *) RING_API_GETCPOINTER(" + t +',"'+trim(x)+'")'
			off
			if not GenMethodCodeISStaticMethods()
				t-- # ignore effect of avoiding the object pointer
			ok
		next
	ok
	return cCode

Func GenNewFuncForClasses aList
	cCode = ""
	for aSub in $aClassesList
		if aSub[C_CLASSESLIST_ABSTRACT] = true or aSub[C_CLASSESLIST_NONEW] = true
			loop
		ok
		cName = aSub[1]	cPara = aSub[2]
		if aSub[C_CLASSESLIST_CODENAME] != NULL
			cCodeName = aSub[C_CLASSESLIST_CODENAME]
		else
			cCodeName = cName
		ok
		cFuncName = "ring_" + cName + "_new"
		mylist = [C_INS_REGISTER,"void","new",ParaList(cPara),cName]
		aList + mylist
		cCode += "RING_FUNC(" + cFuncName + ")" + nl + 
			"{" + nl +
				GenMethodCodeCheckIgnorePointerType() +
			 	GenFuncCodeCheckParaCount(myList) +
	 			GenFuncCodeCheckParaType(myList) +
				C_TABS_1 + cCodeName + " *pObject = " +
				"new " + cCodeName + "("
				cParaValues = Trim(GenFuncCodeGetParaValues(myList))
				cCode += cParaValues
				if aSub[C_CLASSESLIST_PASSVMPOINTER] 
					if cParaValues != NULL
						cCode += ", "
					else 
						if aSub[C_CLASSESLIST_PASSNULL] 
							cCode += "NULL, "
						ok
					ok
					cCode += "(VM *) pPointer"					
				ok
				cCode += ");" + nl 
			if aSub[C_CLASSESLIST_MANAGED]	
				cCode += C_TABS_1 + "RING_API_RETMANAGEDCPOINTER(pObject,"+
					'"'+cName+'",' + "ring_" + cName + "_freefunc" + ");"+ nl 
			else 
				cCode += C_TABS_1 + "RING_API_RETCPOINTER(pObject,"+
					'"'+cName+'"' + ");"+ nl 
			ok
			cCode += "}" + nl + nl
	next
	return cCode

Func GenDeleteFuncForClasses aList
	cCode = ""
	for aSub in $aClassesList
		cName = aSub[1]	cPara = "void"
		if aSub[C_CLASSESLIST_ABSTRACT] = true or aSub[C_CLASSESLIST_NONEW] = true
			loop
		ok
		if aSub[C_CLASSESLIST_CODENAME] != NULL
			cCodeName = aSub[C_CLASSESLIST_CODENAME]
		else
			cCodeName = cName
		ok
		cFuncName = "ring_" + cName + "_delete"
		mylist = [C_INS_REGISTER,"void","delete",ParaList(cPara),cName]
		aList + mylist
		cCode += "RING_FUNC(" + cFuncName + ")" + nl + 
			"{" + nl +
				C_TABS_1 + cCodeName + " *pObject ; " + nl +
				C_TABS_1 + "RING_API_IGNORECPOINTERTYPE ;" + nl +
				C_TABS_1 +"if ( RING_API_PARACOUNT != 1 )" + nl +
    				C_TABS_1 +"{" + nl +
        			C_TABS_2 +"RING_API_ERROR(RING_API_MISS1PARA);" + nl +
        			C_TABS_2 +"return ;" + nl +
    				C_TABS_1 +"}" + nl +
    				C_TABS_1 +"if ( RING_API_ISCPOINTER(1) )" + nl +
    				C_TABS_1 +"{" + nl +
            			C_TABS_2 +'pObject = ('+cCodeName+' *) RING_API_GETCPOINTER(1,"'+cCodeName+'");' + nl +
            			C_TABS_2 +"delete pObject ;" + nl +
				C_TABS_2 +"RING_API_SETNULLPOINTER(1);" + nl +
    				C_TABS_1 +"}" + nl +				
			"}" + nl + nl
	next
	return cCode

Func GenFreeFuncForClasses aList
	cCode = ""
	for aSub in $aClassesList
		cName = aSub[1]	cPara = "void"
		if aSub[C_CLASSESLIST_ABSTRACT] = true or aSub[C_CLASSESLIST_NONEW] = true
			loop
		ok
		if aSub[C_CLASSESLIST_CODENAME] != NULL
			cCodeName = aSub[C_CLASSESLIST_CODENAME]
		else
			cCodeName = cName
		ok
		cFuncName = "ring_" + cName + "_freefunc"
		cCode += "void " + cFuncName + "(void *pState,void *pPointer)" + nl + 
			"{" + nl +
				C_TABS_1 + cCodeName + " *pObject ; " + nl +
            			C_TABS_1 +'pObject = ('+cCodeName+' *) pPointer;' + nl +
            			C_TABS_1 +"delete pObject ;" + nl +
			"}" + nl + nl
	next
	return cCode

Func GenFreeFuncForClassesPrototype aList
	cCode = nl + "// Functions Prototype - Functions used to Free Memory " + nl + nl
	for aSub in $aClassesList
		cName = aSub[1]	cPara = "void"
		if aSub[C_CLASSESLIST_ABSTRACT] = true or aSub[C_CLASSESLIST_NONEW] = true
			loop
		ok
		if aSub[C_CLASSESLIST_CODENAME] != NULL
			cCodeName = aSub[C_CLASSESLIST_CODENAME]
		else
			cCodeName = cName
		ok
		cFuncName = "ring_" + cName + "_freefunc"
		cCode += C_TABS_1 + "void " + cFuncName + "(void *pState,void *pPointer);" + nl 
	next
	cCode += nl + "// End of Functions Prototype - Functions used to Free Memory " + nl + nl
	return cCode


Func GenRingConstants aList
	cCode = ""
	for aFunc in aList
		if aFunc[C_FUNC_INS] = C_INS_CONSTANT
			cConstant = aFunc[C_CONSTANT_NAME]
			cCode += cConstant + " = " + $cFuncStart + "get_" + cConstant + "()" + nl
		ok
	next	
	return cCode

Func GenRingCode aList
	# This function generate Ring Classes that wraps C++ Classes
	cCode = ""
	cCode = GenRingConstants(aList)
	if len($aClassesList) = 0 return cCode Ok	# if no classes then Avoid generating code 
	cClassName = ""
	aClasses = []
	cCode += GenRingCodeFuncGetObjectPointer()
	nMax = len(aList)
	for t=1 to nMax 
		aFunc = aList[t]
		if aFunc[C_FUNC_INS] = C_INS_FUNCTION or
		   aFunc[C_FUNC_INS] = C_INS_REGISTER 
			# Check the start of a New Class
			if aFunc[C_CLASS_NAME] != cClassName
				cClassName = aFunc[C_CLASS_NAME]
				if find(aClasses,cClassName) = 0
					cCode += nl+"Class " + cClassName 
					nIndex = find($aClassesList,cClassName,1) 
					if nIndex > 0
						if $aClassesList[nIndex][C_CLASSESLIST_PARENT] != ""
							cCode += " from " + $aClassesList[nIndex][C_CLASSESLIST_PARENT]
						ok
						cCode += nl+nl+
						C_TABS_1 + "pObject" + nl + nl
						
						if $aClassesList[nIndex][C_CLASSESLIST_NONEW] = false
						  cCode += C_TABS_1 + "Func init " + 
						  GenRingCodeParaList(ParaList($aClassesList[nIndex][C_CLASSESLIST_PARA])) + nl +
						  C_TABS_2 + "pObject = " + cClassName + "_new(" + 
						  GenRingCodeParaListUse(ParaList($aClassesList[nIndex][C_CLASSESLIST_PARA])) +")"+nl+
						  C_TABS_2 + "return self" + nl + nl +
						  C_TABS_1 + "Func delete" + nl + 
						  C_TABS_2 + "pObject = " + cClassName+"_delete(pObject)" + nl + nl +
						  C_TABS_1 + "Func ObjectPointer" + nl +
						  C_TABS_2 + "return pObject" + nl 					
						else
							if ! find ($aNoNewClassesException,cClassName)
								del($aClassesList,nIndex)
							ok
						ok
					else
						cCode += nl + nl
					ok
					aClasses + cClassName
				else
					loop
				ok
			ok
			# Define the method
			if aFunc[C_FUNC_NAME] = "new" or aFunc[C_FUNC_NAME] = "delete" loop ok
			cMethodName = aFunc[C_FUNC_NAME]
			cMethodName = GenRingCodeNewMethodName(cClassName,cMethodName)
			cMethodName = SubStr(cMethodName,"@","_")
			cCode += nl + C_TABS_1 + "Func " + cMethodName + " "
			aPara = aFunc[C_FUNC_PARA]
			cCode += GenRingCodeParaList(aPara)

			# Support ClassName<ClassName> like QVector<QVoice> 
				cFuncOutput = aFunc[C_FUNC_OUTPUT]
				cFuncOutput = substr(cFuncOutput,"<","")
				cFuncOutput = substr(cFuncOutput,">","")
			
			lRetObj = false
			if find($aClassesList,trim(cFuncOutput),1) > 0
				lRetObj = true
				cCode += nl + C_TABS_2 + "pTempObj = new " + cFuncOutput + nl +
					 C_TABS_2+"pTempObj.pObject = "
			but find($aClassesList,GenPointerType(trim(aFunc[C_FUNC_OUTPUT])),1) > 0
				lRetObj = true
				cCode += nl + C_TABS_2 + "pTempObj = new " + GenPointerType(aFunc[C_FUNC_OUTPUT]) + nl +
					 C_TABS_2+"pTempObj.pObject = "
			else
				cCode += nl + C_TABS_2 + "return " 
			ok
			cMethodName = aFunc[C_FUNC_NAME]
			cMethodName = SubStr(cMethodName,"@","_")
			if find($aClassesList,cClassName,1) > 0
				cCode += cClassName + "_" + cMethodName + "(pObject"
				cParaCode = GenRingCodeParaListUse(aPara)
				if cParaCode != NULL
					cCode += ","+cParaCode
				ok
			else
				cCode += cClassName + "_" + cMethodName + "(" +
				GenRingCodeParaListUse(aPara)			
			ok
			cCode += ")" + nl
			if lRetObj
				cCode += C_TABS_2 + "return pTempObj" + nl
			ok
		ok
	next
	return cCode

Func GenRingCodeParaList aPara
	cCode = ""
	nMax = len(aPara)
	for x = 1 to nMax
		if aPara[x] = "void" loop ok
		if x != 1 cCode += "," ok
		cCode += "P"+x
	next
	return cCode

Func GenRingCodeParaListUse aPara
	cCode = ""
	nMax = len(aPara)
	for x = 1 to nMax
		if aPara[x] = "void" loop ok
		if x != 1 cCode += "," ok
		cValue = "P"+x
		if VarTypeID(aPara[x]) = C_TYPE_POINTER or
		   VarTypeID(aPara[x]) = C_TYPE_UNKNOWN							
			cCode += "GetObjectPointerFromRingObject(" + cValue + ")"
		else
			cCode += cValue	
		ok 	
	next
	return cCode

Func GenRingCodeFuncGetObjectPointer
	return '
load "codegenlib.ring"
'

Func GenRingCodeNewMethodName cClassName,cMethodName
	nMax = len(aNewMethodName)
	for t=1 to nMax
		x = aNewMethodName[t]
		if trim(lower(x[C_NMN_CLASSNAME])) = trim(lower(cClassName)) and
		   trim(lower(x[C_NMN_METHODNAME])) = trim(lower(cMethodName))
			return x[C_NMN_NEWMETHODNAME]
		ok
	next
	return cMethodName	
