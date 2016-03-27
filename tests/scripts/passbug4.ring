tabmlstring("test
hello
how are you
")

Func TabMLString cStr
	aList = str2list(cStr)
	for t in aList
		t = gettabs() + t
	next
	return list2str(aList)	

func gettabs
	return char(9)	