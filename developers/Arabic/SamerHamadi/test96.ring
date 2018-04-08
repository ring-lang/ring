/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 22/12/2017
*/
#================================================================

o1 = new person {
	name = "Mahmoud" country = "Egypt"
	print()
}

o2 = new employee {
	name = "Ahmed" country= "Egypt" job= "Developer" 
	salary = "xxxxxxxx"
	print()

}

? o1
? o2

class person 
	name country
	func print
		? "Name :" + name 

class employee from person
	 job salary
	
