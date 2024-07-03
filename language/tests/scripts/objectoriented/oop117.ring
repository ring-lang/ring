? f(2)

mylist = new List([1,2,3])

f(mylist).print()

func f x
	return 2+x*x

class List

	aList = []

	func init vValue
		aList = vValue

	func operator cOperator,vValue

		if cOperator = "r+"  
			cOperator = "+"
		ok

		switch cOperator 
			on "+"
				if isNumber(vValue) { 
					for t in aList
						t += vValue
					next
				but isObject(vValue)
					for t = 1 to len(aList)
						aList[t] += vValue[t]
					next
				ok
			on "*"
				if isNumber(vValue) { 
					for t in aList 
						t *= vValue
					next
				but isObject(vValue)
					for t = 1 to len(aList)
						aList[t] *= vValue[t]
					next
				ok
			on "[]"
				return aList[vValue]
			on "len"
				return len(aList)
		off
		return self

	func print
		? aList
