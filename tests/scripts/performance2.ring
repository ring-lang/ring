t = clock()

for i = 1 to 1000
	x = []
	for j = 1 to 1000
		add(x,[j,i])
	next
next

see "Time : " + ( clock() - t ) + nl