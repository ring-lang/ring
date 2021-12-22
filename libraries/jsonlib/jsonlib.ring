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

load "tokenslib.ring"
load "stdlibcore.ring"

#============================================================================#

func JSON2List cJSON

	if ! isString(cJSON) {
		raise("Bad parameter type! - The JSON2List() function expect a String")
	}

	# convert \" to '
		cJSON = substr(cJSON,'\"',"'")

	# Get the Tokens
		oTokens = new RingTokens {
			fromString(cJson)
			aList = GetTokens()
		}

	# Convert Json Tokens to Ring Tokens 	
		aList = JsonTokens2RingTokens(aList)

	# Get Ring Code from Ring Tokens 
		cCode = RingTokens2Code(aList)

	# Get Ring List
		eval("aJson2List_TempList = " + cCode)

	return aJson2List_TempList


func JSONTokens2RingTokens aList
	for nIndex = 1 to len(aList) 
		aToken = aList[nIndex]
		switch aToken[C_TOKENTYPE] 
			on C_OPERATOR 
				switch aToken[C_TOKENVALUE] 
				on "{"
					aList[nIndex][C_TOKENVALUE] = "["
					aList[nIndex][C_TOKENINDEX] = 17
				on "}"
					aList[nIndex][C_TOKENVALUE] = "]"
					aList[nIndex][C_TOKENINDEX] = 15
				on ":"
					# Add '[' 
						insert(aList,nIndex-2,[C_OPERATOR,"[",17])
						nIndex++
					# Change ':' to ','
						aList[nIndex][C_TOKENVALUE] = ","
						aList[nIndex][C_TOKENINDEX] = 10
					# Add ']'
						nCounter = 0
						lInsert = False
						for t=nIndex+1 to len(aList) 
							aToken2 = aList[t]
							if aToken2[C_TOKENTYPE] = C_OPERATOR 
								if (nCounter = 0) and (aToken2[C_TOKENVALUE] = "," or
								    aToken2[C_TOKENVALUE] = "]" or aToken2[C_TOKENVALUE] = "}" ) 
									insert(aList,t-1,[C_OPERATOR,"]",15])
									t++
									lInsert = True
									exit
								but aToken2[C_TOKENVALUE] = "[" or aToken2[C_TOKENVALUE] = "{"
									aList[t][C_TOKENVALUE] = "["
									aList[t][C_TOKENINDEX] = 17
									nCounter++
								but aToken2[C_TOKENVALUE] = "]" or aToken2[C_TOKENVALUE] = "}"
									aList[t][C_TOKENVALUE] = "]"
									aList[t][C_TOKENINDEX] = 15
									nCounter--
								ok
							ok
						next
						if lInsert = False 
							? "Index = " + nIndex
							Raise("wrong JSON string")
						ok
				off
		off
	next
	return aList

func RingTokens2Code aList 
	cCode = ""
	for nIndex = 1 to len(aList) 
		aToken = aList[nIndex]
		switch aToken[C_TOKENTYPE] 
			on C_OPERATOR 
				cCode += aToken[C_TOKENVALUE] 
			on C_LITERAL
				cCode += Char(34) + aToken[C_TOKENVALUE] + Char(34)
			on C_NUMBER
				cCode += aToken[C_TOKENVALUE] 
			on C_IDENTIFIER
				if trim(Upper(aToken[C_TOKENVALUE])) = "NULL"
					cCode += Char(34) + Char(34)
				ok
		off
	next
	return cCode

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