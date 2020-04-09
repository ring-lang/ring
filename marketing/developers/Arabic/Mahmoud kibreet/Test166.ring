/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.04.03
*/

load "tracelib.ring"

func main 
	? "Hello from main!"
	test1()

func test1 
	? "Hello from test1!"
	test2()

func test2 
	? "Hello from test2!"
	test3()

func test3 
	? "Hello from test3!"
	breakpoint()
