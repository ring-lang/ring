
p = new person("Ahmed")
p.printName()

e = new employee("Amr")
e.printName()

d = new doctor("Yasser")
d.printName()

class doctor from employee{}

class employee from person{}

class person{
	name
	func init(name){
		self.name = name
	}
	func printName(){
		see name + nl
	}
}
