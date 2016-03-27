sum([ :a = 1, :b = 2])
sum([ :a = 1 ])
sum([ :b = 2 ])

func sum pList
	if plist[:a] = NULL pList[:a] = 4 ok
	if plist[:b] = NULL pList[:b] = 5 ok
	see pList[:a] + pList[:b] + nl