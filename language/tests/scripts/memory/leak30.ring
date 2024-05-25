X = 0

? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	test()
end
? "Memory: " + ringvm_ismempool()

func test
	mylist = [[space(1024)],10]
	test2(mylist[1])


func test2 x
	aList = [space(1024)]
	for x in aList
		exit
	next


