/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 17/12/2017
*/
#================================================================

# eval() and the variable scope 

eval("x = 10")		# x is global 
? x

func main 
	eval(" y= 20")
	? y
	test()

func test
	? x
	? y
	
