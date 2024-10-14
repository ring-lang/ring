/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.31
*/

test(func {
	? "Anonymous Function"
})

test2()
cFunc = "test2"
call cFunc()

myFunc = func {
	? "Hello from myFunc"
}

call myFunc()

myFunc2 = func x,y {
	? x+y
}

call myFunc2(3,5)

func test f1
	? "Hello"
	call f1()

func test2
	? "Hello form test2"


