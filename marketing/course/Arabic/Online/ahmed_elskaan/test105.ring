/*
**	Application Name : Scope;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-31;		
*/
x = 10			# global variable

func main
	y = 70		# local variable 
	? x		
	test()
	new person {
		name = "ahmed"
		country = "egypt"
		phone = "xxxx"
		? self
	}
func test
	? x

class person
	name country phone
