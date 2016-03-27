o1 = new point
for x in o1
	see x 
next

class point x y z
	func operator cOperator,vValue
		if cOperator = "[]"
			return "10"
		but cOperator = "len"
			return 5
		ok