/*
**	Application Name : eval();
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-18;		
*/

eval("x = 10")              # global variable
? x
func main
 	eval("y = 20")      # local variable
	? y
	test()
func test
	? x 
	? y
