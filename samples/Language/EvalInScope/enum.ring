colors = enum( [ :white , :red , :black , :blue ] )

? colors[:white]
? colors[:red]
? colors[:black]
? colors[:blue]

useEnum(colors)

? WHITE
? RED
? BLACK
? BLUE

func enum aList
	if !isList(aList) raise("Bad parameter type!") ok
	aEnum = []
	nCounter = 1
	for item in aList
		aEnum[item] = nCounter
		nCounter++
	next
	return aEnum

func useEnum aEnum
	for item in aEnum
		ringvm_EvalInScope(1,item[1] + " = " + item[2])
	next