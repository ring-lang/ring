#============================================================================#
#
# JSONLib Library for the Ring programming language
# 2021, Mahmoud Fayed 
# 
# Functions:
#	List2JSON(aList) --> cJSONString
#	JSON2List(cJSONString) --> aList
#
#============================================================================#

load "cjson.ring"
load "stdlibcore.ring"

#============================================================================#

func JSON2List cJSON

	if ! isString(cJSON) {
		raise("Bad parameter type! - The JSON2List() function expect a String")
	}

	oJSON = cJSON_Parse(cJSON)	

	if isNULL(oJSON)
		raise("Parsing Error (JSONLib) : Can't parse the content " + nl +
			cJSON_GetErrorPtr() )
	ok

	aList = cJSON_ToRingList(oJSON)

	return aList

#============================================================================#

func List2JSON aList 
	if ! isList(aList) {
		raise("Bad parameter type! - The List2JSON() function expect a List")
	}
	cOutput = "{" + nl
	cOutput += List2JSON_process(aList,1)
	cOutput += "}"
	return cOutput

func List2JSON_process aList,nTabs 
	cOutput = ""
	for t=1 to len(aList)
		aSubList = aList[t]
		# Check JSON Object
		if (len(aSubList) = 2) and isString(aSubList[1])
			# Add the object name
			cOutput += Copy(Tab,nTabs) + Char(34) +  aSubList[1] + Char(34) + ": "
			# Add the object value
			if isString(aSubList[2])
				cOutput += Char(34) + aSubList[2] + Char(34) 
			but isNumber(aSubList[2])
				cOutput += "" + aSubList[2] 
			but isList(aSubList[2])
				cOutput += List2JSON_processListValue(aSubList[2],nTabs)
			ok
		but isList(aSubList[1]) 
			cOutput += Copy(Tab,nTabs) + List2JSON_processListValue(aSubList[1],nTabs)
		else	
			? "Unexpected Input!" 		
		ok
		if t != len(aList) 
			cOutput += ","
		ok
		cOutput += nl
	next
	return cOutput 

func List2JSON_processListValue aSubList,nTabs
	cOutput = ""
	if isList(aSubList[1]) and (len(aSubList[1]) = 2 ) and isString(aSubList[1][1]) 
		cOutput += "{" + nl
		nTabs++
		cOutput += List2JSON_process( aSubList, nTabs )
		nTabs--
		cOutput += Copy(Tab,nTabs) + "}" 
	elseif isString(aSubList[1]) or isNumber(aSubList[1])
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
		elseif isNumber(vValue)
			cOutput += ""+Copy(Tab,nTabs)+vValue
		elseif isList(vValue)
			cOutput += Copy(Tab,nTabs)+List2JSON_process(vValue,nTabs)
		ok
		if m != len(aSubList)
			cOutput += ","
		ok
		cOutput += nl
	next
	nTabs--
	cOutput += Copy(Tab,nTabs) + "]" 
	return cOutput

#============================================================================#