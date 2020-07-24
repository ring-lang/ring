

func main
	p1 = new person
	//p1.name = "Ahmed"
	p1.setName("Ahmed")
	//see p1.name + nl
	see p1.getName() + nl
end

class person

	func setName(value)
		name = value
	end

	func getName()
		return name
	end

	func setAddress(value)
		address = value
	end

	func getAddress()
		return address
	end

	private

	name
	address

end

