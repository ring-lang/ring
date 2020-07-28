
p = new person
e = new employee
c = new customer
d = new doctor
s = new student
t = new teacher

printType(p)
printType(e)
printType(c)
printType(d)
printType(s)
printType(t)

func printType(person){
	see "Class Type is: "
	see person.getType()
	see nl
}

class teacher from employee{
	func getType(){
		return "Teacher"
	}
}

class student from person{
	func getType(){
		return "Student"
	}
}

class doctor from employee{
	func getType(){
		return "Doctor"
	}
}

class customer from person{
	func getType(){
		return "Customer"
	}
}

class employee from person{
	func getType(){
		return "Employee"
	}
}

class person{
	func getType(){
		return "Person"
	}
}
