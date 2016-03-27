obj1 = new Manager

obj1 {
	name = "ali"
	country = "KSA"
	AGE = 40
	job = "programmer"
	salary = 15000
	department = "IT"
	mypoint {
		x = 10
		y = 20
		z = 30
	}
}

see obj1
see obj1.mypoint

Class Person 
	name country age
	mypoint = new point

Class Emp from Person 
	Job Salary

Class Manager from Emp 
	department

Class point
	x y z 