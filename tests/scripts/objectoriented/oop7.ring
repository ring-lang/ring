o1 = new myclass 				
o1.sayhello()
o1.cName = "Ahmed" 				
o1.SayHello()

for x = 1 to 10 
	o1.cName = x 	
	o1.SayHello() 	
next

class myclass
	cName = "Mahmoud"
	func sayhello
		see "Hello " 
		see self.cName 
		see nl
