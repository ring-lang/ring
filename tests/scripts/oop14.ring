oMsg = new Message
oMsg.cName = "Mahmoud"
oMsg.sayhello()

oMsg2 = new Message2
oMsg2.cName = "Ahmed"
oMsg2.sayhello2()

oMsg3 = new Message3
oMsg3.cName = "Samir"
oMsg3.welcome()

oMsg3.cAddress = "Egypt"
oMsg3.cPhone = "123456"
oMsg3.print()

Class Message
	cName = ""
		func sayhello
			see "Hello " + cName + nl

Class Message2 from Message
	cAddress = ""
		func sayhello2
			see "before " + nl
			for x in cName
				see x + nl
			next
			see "After" + nl

Class Message3 from Message2
	cPhone = ""
		func welcome
			sayhello()
			sayhello2()
		func print
			see "Name : " + cName + nl
			see "Address : "  + cAddress + nl
			see "Phone : " + cPhone + nl
