o1 = new myclass 
O1.GOSTART()

see o1.mylist[5].x + nl
see o1.mylist[5].y + nl

Class myclass

	mylist = list(10)

	func gostart
		
		for t = 1 to 10
			see "t value = " + t + nl
			mylist[t] = new point {
				x = 10
				y = 20
			}
			see mylist[t].x + nl +
			    mylist[t].y + nl
			
		next

Class point x y
