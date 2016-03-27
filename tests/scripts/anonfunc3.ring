r = test(1)
see "before"+ nl
eval(r + "()")
see "after"+nl

func test x

	see x + nl
	return func { see "great" + nl }