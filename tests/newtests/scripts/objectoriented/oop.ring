oPerson = new Person

oPerson.cName = "Mahmoud"
oPerson.cJob = "Programmer"
oPerson.cPhone = "123456"

oPerson.display()

Class Person

	cName = ""
	cJob = ""
	cPhone = ""

	oMsg = new Message
	oMsg.text = "Welcome"

	func display

		oMsg.show()
		see oMsg.text + NL
		see cName + NL + cJob + NL + cPhone + NL
		goodbye()

	func goodbye

		see "bye " + NL

Class Message

	text = ""

	func show
		see text + NL

Class Message2 from Message	

	func show

		super.show()
		see "done" + nl

