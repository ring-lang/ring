/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 09/04/2018
*/

o1 = new person {
	name = "khaled"	country = "alg"
	print()
}

o2 = new employee {
	name = "omar" country = "alg" job = "Prgrmr"
	salary = "xxxxx"
	print()
}

? o1
? o2

class Person name country
	func print 
		? "Name : " + name

class Employee from person		# using : or < instead from
	job salary 

	
