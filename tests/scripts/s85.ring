mylist = [
func1(),
func2(),
func3()
]

see mylist

for x = 1 to len(mylist)
	see mylist[x] + nl
next

mylist = [
sublist(),sublist(),sublist()
]

see mylist

for x = 1 to 3
	for y = 1 to 3
		see mylist[x][y]
	next
	see nl
next

func func1
	see " name : " give fname
	return fname

func func2
	see " country : " give country
	return country

func func3
	see " age : " give age
	return age

func sublist
	vlist = [1,2,3]
	return vlist
