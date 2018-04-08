/*
**	Application	: Ring lessons - Functional Programming - First-class .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 22 .
*/

#-------
test(func {
	? "Anonymous Function"
})
#-------
test2()
cFunc = "test2"
call cFunc()
#-------
myFunc = func { ? "Hello From myFunc"}
call myFunc()
#-------
myFunc2 = func x,y { ? x+y}
call myFunc2(10,2)
#-------
func test f1
	? "Hello"
	call f1()

func test2
	? "Hello From Test2"
