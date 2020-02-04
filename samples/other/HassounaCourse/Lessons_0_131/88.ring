
func main

	p1 = new person
	p1.id = 111
	p1.name = "Ahmed"
	p1.address = "Giza"
	p1.printData()

	p2 = new person
	p2.id = 222
	p2.name = "Omar"
	p2.address = "Cairo"
	p2.printData()
	
	p1.printData()
	p2.printData()

end

class person{

	id
	name
	address

	func printID see id + nl
	func printName see name + nl
	func printAddress see address + nl
	func printData see "ID:" + id + " ; Name:" + name + " ; Address:" + address + nl

}


