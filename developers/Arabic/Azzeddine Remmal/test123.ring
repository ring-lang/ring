###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 24.01.2018                  
###################################	

test(func {
	? "Anonymous Function"
	})

test2()
cFunc = "test2"
call cFunc()

myfunc = func {
	? "Hello from myfunc"
	}

call myfunc()

myfunc2 = func x,y {
	? x+y 
	}

call myfunc2(3,5)

func test f1
	? "Hello"
	call f1()

func test2 
	? "Hello from test2"
