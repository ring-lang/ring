/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 03/05/2018
*/

test(func {
	? "Anonymous function"
})

test2()
cFunc = "test2"
call cFunc()

myFunc = func {
	? "Hello from myFunc"
}

call myfunc()

func test f1
	? "Hello!"
	call f1()

func test2
	? "Hello from test2"
