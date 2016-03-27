Func Main
	list = 1:10
	each(list, func x {
		x = x*x
	})
	see list

Func each aList, cFunc
	for x in aList
		call cfunc(x)
	next