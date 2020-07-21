func main
mylist = [
	"one",
	"two",
	"three",
	[1,2,3,4,5],
	new first { 
		name = "Mahmoud"
		address = "Egypt"
		phone = "123456"
		link = new Second {
			job = "Programmer"
			link = new third {
				salary = 49000
				tlist = [1000,2000,3000,4000]
			}
		}
	}
]

see mylist[5]

see mylist[5].link.link.salary + nl
see mylist[5].link.link
see mylist[5].link.link.tlist 

	
Class First
	name address phone
	link

class second
	job link

class third
	salary
	tlist