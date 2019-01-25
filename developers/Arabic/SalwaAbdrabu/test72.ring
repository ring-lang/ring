/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

# eval and a variable scope 
eval("x = 10")           # x is Global
? x

func main 
	eval("y = 20")   # y is Local
	? y 
	test()
func test
	? x
	? y              # Error
