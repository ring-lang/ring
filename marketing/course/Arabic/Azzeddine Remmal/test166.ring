###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           :16.08.2018                  
###################################


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
