o1 = new person

o1.name = "Mahmoud"
see o1.name + nl

see "Test : " + nl

o1 {
	name = "Ahmed"
	see name
}


Class Person

	name

	func setname value
		see "Message from SetName() Function!" + nl
		name = value + " Fayed"

	func getname
		see "Message from GetName() Function!" + nl
		return "Mr. " + name

