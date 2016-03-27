o1 = new person

o1.name = "Mahmoud"
see o1.name 

Class Person

	name address phone
	Message = new Message

	func setname	value
		see "Message from SetName() Function!" + nl
		name = value + " Fayed"

	func getname
		see "Message from GetName() Function!" + nl
		return "Mr. " + name


Class Message
	text = "welcome to nova!"
	func show
		see text + nl