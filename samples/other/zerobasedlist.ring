oList = new ZeroBasedList( [1,2,3] )
? oList[0]
? oList[1]
? oList[2]

class ZeroBasedList 
	aItems = []
	func init aList 
		aItems = aList 
	func operator cOperator,cValue 
		if cOperator = "[]"
			return aItems[cValue+1]
		ok
