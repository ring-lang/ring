#============================================================================#
#
# CSVLib Library for the Ring programming language
# 2021, Mahmoud Fayed 
# 
# Functions:
#	List2CSV(aList) --> cCSVString
#	CSV2List(cCSVString) --> aList
#
# Note: We can open CSV files using Microsoft Excel
#
#============================================================================#

load "stdlibcore.ring"

if isMainSourceFile() {
	CSVLib_test()
}

func CSVLib_test
	? list2csv(1:10)
	? list2csv(["one","two","three"])
	aList = [
	  ["name","phone"],
	  ["Mahmoud",123456],
	  ["Ahmed",654321],
	  ['"Kareem"',123321], 
	  ["Fayed, Mahmoud",999111],
	  ['""Ali""',443344]
	]
	cCSV = list2csv(aList)
	? cCSV
	write("test.csv",cCSV)
	aList = [
	   ["one",
	      ["two","three",
	         ["four"]
	      ]
	   ]
	]
	cCSV = list2csv(aList)
	? cCSV
	write("test2.csv",cCSV)
	? "Test CSV2List() "
	cFile = read("test.csv")
	aTable = CSV2List(cFile)
	? aTable
	cCSV = list2csv(aTable)
	write("test3.csv",cCSV)

#============================================================================#

func List2CSV aList 
	if ! isList(aList) {
		raise("Bad parameter type! - The List2CSV() function expect a List")
	}
	return List2CSV_Process(aList,0)

func List2CSV_Process aList,nStart
	cOutput = ""
	nSize = len(aList)
	nIndex = 1
	for item in aList step 1 { 
		# Add comma before the list
			if nIndex = 1 { 
				for t = 1 to nStart-1 step 1 { 
					cOutput += ","
				}
			}
		if isString(item) { 
			cOutput += CHAR(34)
			for t in Item step 1 { 
				if  NOT t = CHAR(34) { 
					cOutput += t
				else 
					cOutput += CHAR(34)+CHAR(34)
				} 
			}
			cOutput += CHAR(34)
			if nIndex != nSize  { 
				if ! isList(aList[nIndex+1]) { 
					cOutput += ","
				}
			}
		elseif isnumber(item) 
			cOutput += ""+item
			if nIndex != nSize  { 
				if ! isList(aList[nIndex+1]) { 
					cOutput += ","
				}
			}
		elseif isList(item)
			if nStart! = 0 { 
				cOutput += nl
			} 
			cOutput += List2CSV_Process(item,nStart+1)
		}
		nIndex++
	}
	if nStart! = 0 { 
		cOutput += nl
	} 
	return cOutput 

#============================================================================#

func CSV2List cString
	if ! isString(cString) {
		raise("Bad parameter type! - The CSV2List() function expect a String")
	}
	aList = []
	aLines = str2list(cString)
	for cLine in aLines step 1 { 
		aSubList = []
		cToken = ""
		lSupportComma = True
		nSize = len(cLine)
		nIndex = 1
		cLine  = trim(cLine)
		for t in cLine step 1 { 
			switch t { 
				case char(34)
					lSupportComma = ! lSupportComma
					if (nIndex !=1) AND (nIndex != nSize) { 
						if cLine[nIndex+1] != "," { 
							if lSupportComma { 
								cToken += t
							}
						}
					}
				case ","
					if lSupportComma { 
						CSV2List_AddItem(aSubList, cToken)
						cToken = ""
						nSize -= nIndex
						nIndex = 0
					else 
						cToken += t
					}
				else 
					cToken += t
			}
			nIndex++
		}
		if cToken != "" { 
			CSV2List_AddItem(aSubList, cToken)
		}
		aList+aSubList
	}
	return aList

func CSV2List_AddItem aSubList,cToken
	# Check if we have a Number
		lNumber = True
		for n in cToken  step 1 { 
			if !isdigit(n) { 
				lNumber = False
				exit 1
			} 
		}
	if lNumber  { 
		aSubList+number(cToken)
	else 
		aSubList+cToken
	}

#============================================================================#