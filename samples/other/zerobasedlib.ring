func Z vValue
	if isString(vValue)
		return new ZeroBasedString(vValue)
	but isList(vValue)
		return new ZeroBasedList(vValue)
	ok

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
