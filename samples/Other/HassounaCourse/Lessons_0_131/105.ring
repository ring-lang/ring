
func main
	
	p = new person
	//p.salary = 45000  ////NOT Found

	e1 = new employee
	e1.id = "A11"
	e1.name = "Amr"
	e1.address = "Giza"
	e1.salary = 50000
	e1.printID()
	e1.printName()
	e1.printAddress()
	e1.printSalary()
	e1.printData()

	see "=======================" + nl

	d1 = new doctor
	d1.id = "D111"
	d1.name = "Yasser Ahmed"
	d1.address = "Mohandseen"
	d1.salary = 70000
	d1.doctoralID = "222BA333"
	d1.printID()
	d1.printName()
	d1.printAddress()
	d1.printData()
	d1.printSalary()
	d1.printDoctoralID()

end


class doctor from employee
	doctoralID
	func printDoctoralID() see doctoralID + nl
end

class employee from person
	salary
	func printSalary() see salary + nl
end

class person

	id
	name
	address

	func printID() see id + nl
	func printName() see name + nl
	func printAddress() see address + nl
	func printData() see id + " ; " + name + " ; " + address + nl

end
