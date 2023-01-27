list = [1,2,3]

for e in list
	? e
	test()
	? e
	list = null
	? e
next

func test
	list[1] = ref(list)
