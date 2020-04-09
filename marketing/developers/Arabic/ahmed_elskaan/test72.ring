/*
**	Application Name : OOP 9;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-23;		
*/
o1 = new person {
	name    = "ahmed"
	country = "egypt"
	print()
}

o2 = new employee {
	name    = "mohamed"
	country = "egypt"
	job     = "programmer"
	salary  = 5000
}
? o1
? o2

class person 
	name country
	func print
		? "Name: " + name
class employee from person 
	job salary 
