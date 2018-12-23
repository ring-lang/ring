Load "general/weblib.ring"

Import system.web

see "welcome" + nl

func main

new point 

class point x y z

	myobj = new good
	myobj.f2()
	
class smart
	func f1
		see "one" + nl

class good from smart

	func f2

		#r = new page 
		#r.text("wow")

		new page {
			text("Wow")
		}
		

		return