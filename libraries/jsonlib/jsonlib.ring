#=======================================================================================#
#
# JSONLib Library for the Ring programming language
# 2021, Mahmoud Fayed 
# 
# Functions:
#	List2JSON(aList) --> cJSONString
#	JSON2List(cJSONString) --> aList
#
#=======================================================================================#

load "cjson.ring"
load "stdlibcore.ring"

#=======================================================================================#

C_ERROR_EXPECTASTRING = "Bad parameter type! - The JSON2List() function expect a String"
C_ERROR_CANTPARSE     = "Parsing Error (JSONLib) : Can't parse the content "
C_ERROR_EXPECTALIST   = "Bad parameter type! - The List2JSON() function expect a List"
C_ERROR_UNEXPECTED    = "Unexpected Input!"

#=======================================================================================#

func JSON2List cJSON

	if ! isString(cJSON)
		raise(C_ERROR_EXPECTASTRING)
	ok

	oJSON = cJSON_Parse(cJSON)	

	if isNULL(oJSON)
		raise(C_ERROR_CANTPARSE + nl + cJSON_GetErrorPtr() )
	ok

	aList = cJSON_ToRingList(oJSON)

	return aList

#=======================================================================================#

func List2JSON aList 
	if ! isList(aList) 
		raise(C_ERROR_EXPECTALIST)
	ok
	cOutput = "{" + nl
	cOutput += List2JSON_process(aList,1)
	cOutput += "}"
	return cOutput

func List2JSON_process aList,nTabs 
	cOutput = ""
	for t=1 to len(aList)
		aSubList = aList[t]
		if List2JSON_isObjectAttribute(aSubList)
			cOutput += List2JSON_processObjectAttribute(aSubList,nTabs)
		but isList(aSubList[1]) 
			cOutput += Copy(Tab,nTabs) + List2JSON_processListValue(aSubList,nTabs)
		but isList(aSubList)
			cOutput += Copy(Tab,nTabs) + List2JSON_processSubList(aSubList,nTabs)
		but isString(aSubList)
			cOutput += Copy(Tab,nTabs) + List2JSON_processListValue(aList,nTabs)
			exit
		else	
			? C_ERROR_UNEXPECTED		
		ok
		if t != len(aList) 
			cOutput += ","
		ok
		cOutput += nl
	next
	return cOutput 

func List2JSON_isObjectAttribute aSubList
	return isList(aSubList) and (len(aSubList) = 2) and isString(aSubList[1])

func List2JSON_processObjectAttribute aSubList,nTabs
	cOutput = ""
	# Add the object name
		cOutput += Copy(Tab,nTabs) + Char(34) +  aSubList[1] + Char(34) + ": "
	# Add the object value
		vValue = aSubList[2]
		if isString(vValue)
			cOutput += Char(34) + vValue + Char(34) 
		but isNumber(vValue)
			cOutput += "" + vValue 
		but isList(vValue)
			cOutput += List2JSON_processListValue(vValue,nTabs)
		ok
	return cOutput

func List2JSON_processListValue aSubList,nTabs
	cOutput = ""
	if len(aSubList) = 0
		return "[]"
	ok
	if List2JSON_isObjectAttribute(aSubList[1]) 
		cOutput += "{" + nl
		nTabs++
		cOutput += List2JSON_process( aSubList, nTabs )
		nTabs--
		cOutput += Copy(Tab,nTabs) + "}" 
	but isString(aSubList[1]) or isNumber(aSubList[1])
		cOutput += List2JSON_processSubList(aSubList,nTabs)
	else 
		cOutput += "[" + nl
		nTabs++
		cOutput += List2JSON_process( aSubList, nTabs )
		nTabs--
		cOutput += Copy(Tab,nTabs) + "]" 
	ok
	return cOutput

func List2JSON_processSubList aSubList,nTabs
	cOutput = "[" + nl
	nTabs++
	for m=1 to len(aSubList)
		vValue = aSubList[m]
		if isString(vValue)
			cOutput += ""+Copy(Tab,nTabs)+Char(34)+vValue+ Char(34)
		but isNumber(vValue)
			cOutput += ""+Copy(Tab,nTabs)+vValue
		but isList(vValue)
			cOutput += List2JSON_process(vValue,nTabs)
		ok
		if m != len(aSubList)
			cOutput += ","
		ok
		cOutput += nl
	next
	nTabs--
	cOutput += Copy(Tab,nTabs) + "]" 
	return cOutput

#=======================================================================================#