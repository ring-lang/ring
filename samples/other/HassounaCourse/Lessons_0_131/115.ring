

p = new person
p.getName()

e = new employee
e.getName("Ahmed")

c = new customer
c.getName()

d = new doctor
d.getName()

t = new teacher
t.getName("Yasser")

class employee from person{
	func getName(name){
		see name + nl
	}
}

class customer from person{}

class doctor from employee{
	func getName{
		see "Doctor" + nl
	}
}

class teacher from employee{}

class person{
	func getName{
		see "Person" + nl
	}
}
