p1 = new person
p1.setName("amr")
see p1.getName() + nl
see p1.justtest() + nl
class person

	func setName(name)
		this.name = name	
	end

	func getName return name

	func justtest
		this.name = "wow"
		see this.name

	private

	id
	name
	address

end