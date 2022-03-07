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
	for t=1 to len( aList )
		aSubList = aList[t]
		if isString(aSubList[1]) and len(aSubList) = 2 
			cOutput += Copy(Tab,nTabs) + Char(34) +  aSubList[1] + Char(34) + ": "
			if isString(aSubList[2])
				cOutput += Char(34) + aSubList[2] + Char(34) 
			but isNumber(aSubList[2])
				cOutput += "" + aSubList[2] 
			but isList(aSubList[2])
				if isString(aSubList[2][1][1])
					cOutput += "{" + nl
					nTabs++
					cOutput += List2JSON_process( aSubList[2], nTabs )
					nTabs--
					cOutput += Copy(Tab,nTabs) + "}" 
				else 
					cOutput += "[" + nl
					nTabs++
					cOutput += List2JSON_process( aSubList[2], nTabs )
					nTabs--
					cOutput += Copy(Tab,nTabs) + "]" 
				ok
			ok
		but isList(aSubList[1]) 
				cOutput += Copy(Tab,nTabs) + "{" + nl
				nTabs++
				for t2 = 1 to len(aSubList)
					aSubList2 = aSubList[t2]
					cOutput += List2JSON_process( [ aSubList2 ], nTabs)
					if t2 != len(aSubList)
						if right(cOutput,1) = nl
							cOutput = left(cOutput,len(cOutput)-1)
						ok
						cOutput += "," + nl
					ok
				next
				nTabs--
				cOutput += Copy(Tab,nTabs) + "}" 
		else	
			? "Unexpected Input!" 		
		ok
		if t != len(aList) 
			cOutput += ","
		ok
		cOutput += nl
	next
	return cOutput 

#============================================================================#