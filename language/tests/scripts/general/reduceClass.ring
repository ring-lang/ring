reduce = new reduce

func main

	aList   = ["I","Love","Ring"]
	aList2  = 1:63
	concat = func x,y {return x+y}

	? reduce {aList  concat}.value()
	? reduce {aList2 concat}.value()
	? reduce {aList}.value()
	? reduce {concat}.value()

class reduce

	nCounter=0 data cfunction	

	func braceexpreval cValue

		nCounter++ switch nCounter
		on 1	data	  = cValue
		on 2	cfunction = cValue
		off

	func reset

		nCounter=0 data=NULL cFunction=NULL	

	func value

		switch nCounter
		on 1
			return data[1]
		on 2
			out = Reduce(data,cFunction)
			reset()
		off
		return out

	func Reduce alist,cFunc

		xResult = NULL
		if aList and isNumber(aList[1]) xResult = 0 ok 
	
		for x in alist
			xResult = call cFunc(xResult,x)
		next
	
		return xResult