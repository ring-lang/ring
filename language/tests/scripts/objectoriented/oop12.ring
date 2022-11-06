oMsg = new Message
oMsg.cMsg = "Welcome"
oMsg.print()

oMsg2 = new Message2
oMsg2.cMsg = "Great"

t = clock()
for x = 1 to 100
	oMsg2.test()
	oMsg2.print()
	oMsg2.one()
next
cTime = "Time " + (clock() - t) + nl

class base
	func one

Class Message from base
	cMsg = ""
	func print
		? "Hello from print() method"

Class Message2 from Message
	cMsg = ""
	func test
		? "Hello from test() method"