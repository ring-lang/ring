o1 = new Test
o1.hello()
o1.welcome()

see ismethod(o1,"hello") + nl
see ismethod(o1,"test") + nl
see ismethod(o1,"welcome") + nl

Class Test
	func hello
		see "hello" + nl
	func welcome
		see "Welcome" + nl