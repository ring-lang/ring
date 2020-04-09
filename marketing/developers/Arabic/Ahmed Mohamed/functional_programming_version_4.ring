/*
	Application	: Functional Programming Version 4
	Author		: Ahmed Mohamed
	Date		: 2019/11/1
*/

test(func {
	? "Anonymous Functions"
})

test2()

cFunc = "test2"

call cFunc()

myFunc = func {
	? "Hello From My Func"
}

call myFunc()

myFunc2 = func x,y {
	? x + y
}

call myFunc2(3,5)

func test f1
	? "Hello"
	call f1()

func test2
	? "Hello From Test 2"
