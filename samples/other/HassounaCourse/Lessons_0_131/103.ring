
func main
	p1 = new person
	p2 = new person

	p1.name="Ahmed"
	p1.address = "Cairo"
	p2.name = "Amr"
	p2.address = "Giza"

	see p1.name + " ; "
	see p1.address + nl
	see p2.name + " ; "
	see p2.address + nl

end

class person

	name
	address

	func setName(value) name=value
	func getName() return name

	func setAddress(value) address=value
	func getAddress() return address

	//func myF() see myName

end
