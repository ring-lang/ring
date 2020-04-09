/*
**	Application	: Ring lessons - Object Oriented Programming ( OOP )- Class Inheritance  .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 16 .
*/
? copy("-",10)
o1 = new person {name = "Osama" country = "Syria"
			print()
}
? copy("-",10)
o2 = new employee {
			name = "Mahmoud" country = "Egypt"
			job = "Developer" salary = "10000$"
			print()
}
? copy("-",10)
? o1
? copy("-",10)
? o2
? copy("-",10)
class person
		name country		
		func print
		? "Name : " + name
class employee from person			
		job salary






