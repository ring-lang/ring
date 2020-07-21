o1 = new person

o1.name = "Mahmoud"
o1.setname("Mahmoud")

for x = 1 to 100
	see o1.name 
	see x
next

Class Person

	name address phone

	Message = new Message

	func setname	value
		name = value

	func getname
		see "Message from GetName() Function!" + nl
		return name


Class Message
	text = "welcome to nova!"
	func show
		see text + nl