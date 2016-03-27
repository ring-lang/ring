see "welcome " + nl fun()
for t = 1 to 2 	fun()  next
see nl + "Other " + nl 
see list()

func list
	mylist = [
	["Mahmoud",27],
	["Mona",19],
	["Ahmed",25]
	]
	see nl + "Name  ----  Age" + nl		
	for x = 1 to 3 see mylist[x][1] + "  " + mylist[x][2] + nl next
	see " i am here " + nl
	return mylist

func fun
	see "hello world" + nl for x = 1 to 5
	if x = 1 see "one" 	but x = 2 see "two" 	
	but x = 3 see "three" but x = 4 see "four" 
	but x = 5 see "five" ok see nl next
	x = 1 while x <= 10 see x see nl x = x + 1 end