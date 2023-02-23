# Posted to Ring Group by Dan 
# Updated by Fayed

Concat = func x, y { return x + y }

? Reduce( [ "I", "Love", "Ring" ], Concat )

? Reduce( 1:63, func x, y { return x + y } )

Func Reduce alist,cFunc

	xResult = NULL
	if aList and isNumber(aList[1]) xResult = 0 ok 
	
	for x in alist
		xResult = call cFunc(xResult,x)
	next
	
	return xResult