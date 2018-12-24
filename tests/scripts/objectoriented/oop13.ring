oMsg = new Message
oMsg.cMsg = "Welcome"
oMsg.print()

oMsg2 = new Message2
oMsg2.cMsg = "Great"

oMsg2.test()
oMsg2.print()
oMsg2.one()

oMsg3 = new Message3
oMsg3.test()
oMsg3.sum(3,4)

oMsg3copy = oMsg3
oMsg3copy.test()
oMsg3copy.one()

oMsg4 = new message4
oMsg4.tesT()

oMsg5 = new message5
oMsg5.tesT()

class base 
	func one 
		see "one " + nl

Class Message from base
	cMsg = ""
	func print
		see cMsg + nl

Class Message2 from Message
	cMsg = ""
	func test
		see "nice" + nl
	func sum x , y
		see "Sum : " + (x+y) + nl

class Message3 from Message2
	func test
		see "very nice " + nl

class Message4 from Message3
	func test
		see "very nice " + nl
		one()

class Message5 from Message4
	func test
		see "very nice " + nl
		one()		
	func one
		see "another one!" + nl
