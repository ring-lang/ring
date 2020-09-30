o1 = new person

o1.name = "Mahmoud"
see o1.name + nl

o1 {
	self.name = "Ahmed"
	see self.name
}


Class Person

	name

	func setname value
		see "Message from SetName() Function!" + nl
		name = value + " Fayed"

	func getname
		see "Message from GetName() Function!" + nl
		return "Mr. " + name
