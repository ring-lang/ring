oList = new ZeroBasedList( [1,2,3] )
? oList[0]
? oList[1]
? oList[2]
? "Items Count: " + len(oList)
class ZeroBasedList 
	aItems = []
	func init aList 
		aItems = aList 
	func operator cOperator,cValue 
		switch cOperator
			on  "[]"
				return &aItems[cValue+1]
			on "len"
				return len(aItems)
		off
