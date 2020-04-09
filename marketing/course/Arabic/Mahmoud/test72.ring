/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.15
*/

# eval() and the variable scope 

eval("x = 10")			# x is global 

? x 

func main 
	eval(" y = 20 " )	# y is local
	? y
	test()

func test 
	? x 
	? y			# Error 
