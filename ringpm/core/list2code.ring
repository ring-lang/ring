/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.31
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "stdlibcore.ring"

if isMainSourceFile()
	aList = [
		:one = 1,
		:two = 2,
		:three =3,
		:name = "wow",
		:libs = ["one","two","three"],
		:dep = [
			:v = 1 , :x = 2 , :t = :nice
		]
	]
	
	new List2Code {
		? List2Code(aList)
	}
ok
	
class List2Code
	nTabs = 0
	func List2Code aList
		nTabs++
		cCode = Copy(Tab,nTabs-1)+"["+Windowsnl()
		lStart = True
		for item in aList 
			if !lStart 
				cCode += "," + WindowsNL()
			else 
				lStart = False
			ok
			if isString(item) 
				cCode += Copy(Tab,nTabs)+'"' + item + '"' 
			but isnumber(item)
				cCode += Copy(Tab,nTabs)+(""+item)
			but islist(item)
				if len(item) = 2 and isString(item[1])
					if isString(item[2])
						cCode += Copy(Tab,nTabs)+":"+item[1] + ' = "' +
							item[2] + '"' 
					but isNumber(item[2])
						cCode += Copy(Tab,nTabs)+":"+item[1] + ' = ' +
							item[2] 
					but isList(item[2])
						cCode += Copy(Tab,nTabs)+":"+item[1] + ' = ' +
							List2Code(item[2]) 
					ok
					
				else 
					cCode += List2Code(item)
				ok
			ok
		next
		cCode += windowsnl()+Copy(Tab,nTabs-1)+"]"
		nTabs--
		return cCode
	
