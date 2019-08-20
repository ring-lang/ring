/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.28
*/

# eval() and variable scope 

eval(" x = 10 ")           # global 

? x

func main 
	eval(" y = 20 ")  # y is  local 
	? y
	test()

func test 
	? x
	? y              # error 
