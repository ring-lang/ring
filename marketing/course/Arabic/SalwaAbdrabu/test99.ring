/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/


o1 = new person { 
	name = "Salwa" country = "Egypt" 
	print()
}

o2 = new employee {
	name = "Ahmed" country = "Egypt" 
	salary = "xxx" job = "developer"
	print()
}
? o1
? o2

class person 
	name country
	func print 
		 ?"Name :" + name + nl

class employee from person
		job  salary
