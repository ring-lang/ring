Func Main
	list = 1:10
	each(list, func x {
		x = x*x
		see x + nl
	})
	see list

Func each aList, cFunc
	for x in aList
		_x = x
		call cfunc(_x)
	next