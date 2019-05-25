func Z vValue
	if isString(vValue)
		return new ZeroBasedString(vValue)
	but isList(vValue)
		return new ZeroBasedList(vValue)
	ok

func ZeroBased_Add List,Value 
	Add(List,Value)

func ZeroBased_Insert List,nPos,Value 
	Insert(List,nPos,Value)

class ZeroBasedList 

	ZB_aItems = []

	func init aList 
		ZB_aItems = aList 

	func operator cOperator,cValue 
		switch cOperator
			on  "[]"
				return &ZB_aItems[cValue+1]
			on "len"
				return len(ZB_aItems)
		off

	func add Value 
		# We use ZeroBased_Add() because we have add() method in this class
		ZeroBased_Add(ZB_aItems,Value)

	func insert nPos,Value
		# We use ZeroBased_insert() because we have insert() method in this class		
		ZeroBased_Insert(ZB_aItems,nPos,Value)		

class ZeroBasedString

	ZB_cString = ""

	func init cValue
		ZB_cString = cValue

	func operator cOperator,cValue 
		switch cOperator
			on  "[]"
				return ZB_cString[cValue+1]
			on "len"
				return len(ZB_cString)
		off
