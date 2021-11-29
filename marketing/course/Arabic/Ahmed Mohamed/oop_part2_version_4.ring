/*
	Application	: OOP Part 2 Version 4
	Author		: Ahmed Mohamed
	Date		: 2019/10/28
*/

o1 = new Person {
	name = "Ahmed" country = "Egypt"
	print()
}

o2 = new Employee {
	name = "Mahmoud" country = "KSA" job = "Developer"
	salary = "xxxxx"
	print()
}

? o1
? o2

class Person name country
	func print()
		? "Name : " + name;	

class employee from Person
	job salary
