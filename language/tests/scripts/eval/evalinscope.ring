func main
	test()

func test
	v1 = 100
	test2()
	? v1

func test2
	? ringvm_scopescount()
	v2 = 1000
	? v2
	ringvm_evalinscope(ringvm_scopescount()-1,"? v1 "+nl+"nice()")
	? ringvm_scopescount()
	? v2

func nice
	? :great
	v2 = 50
	? v2