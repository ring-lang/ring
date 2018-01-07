/*
**	Application		: Functions .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 07 .
*/

# Functions	-	Scope	-	Pass By Value	-	Pass By Reference
? "Hello"
	$x = 10	# global
func main{
	? "Welcome To The Main Function"
	print_x()
}
def print_x{
	? $x
}
