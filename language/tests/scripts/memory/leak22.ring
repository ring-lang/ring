? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	try
		test4()
	catch
	done
end
? "Memory: " + ringvm_ismempool()

func test4
	new point2

func happy1
	happy2()

func happy2
	happy3()

func happy3
	new point5

class point2
	new point3

class point3
	new point4

class point4
	happy1()

class point5
	new point6

class point6
	1/0