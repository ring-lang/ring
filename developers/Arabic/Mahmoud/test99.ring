/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.20
*/

o1 = new person {
	name = "Mahmoud" Country = "Egypt"
	print()
}

o2 = new Employee {
	name = "Ahmed" country = "Egypt"
	job = "developer"  salary = "xxxxxxxx"
	print()
}

? o1
? o2

class person  
	name country 
	func print 
		? "Name : " + name 

class employee from person 
	job  salary 
