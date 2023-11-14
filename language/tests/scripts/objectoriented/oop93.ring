data = [NEW myclass]

for m=1 to 10
	? data[1][NULL]
next

class myclass
	aList = new myclass2
	func operator cOperator,vValue
		if cOperator = "[]"
			return aList[vValue]
		ok

class myclass2
	aList = 1:10
	nInc  = 0
	func operator cOperator,vValue
		if cOperator = "[]"
			return aList[nInc++]
		ok