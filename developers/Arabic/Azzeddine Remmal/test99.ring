#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 20.01.2018                  
####################################



o1 = new person {
	name = "Azzeddine" Country = "Algiria"
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
