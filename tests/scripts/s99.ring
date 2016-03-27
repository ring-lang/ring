
see f1() + f2()
see nl
y = f3()
see y
z = f4()
see z

func f1 
	return 5

func f2 
	return 6

func f3
	list = [1,2,3,4,5]
	see list
	return list

func f4
	tlist = []
	for x = 1 to 4
		add(tlist,x)
	next
	see tlist
	return tlist
