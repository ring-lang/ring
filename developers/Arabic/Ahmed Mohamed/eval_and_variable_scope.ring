/*
	Application	: Eval And Variables Scope
	Author		: Ahmed Mohamed
	Date		: 2019/10/24
*/

eval("x = 10") # x global

? x

func main
	eval("y = 20") # y is local
	? y
	test()

func test
	? x
	? y
