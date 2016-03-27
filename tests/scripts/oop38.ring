mylist = 
[
	"one",
	"two",
	"three",
	[1,2,3,4,5],
	new first { name = "Mahmoud" },
	mylist[5] { 
		address = "Egypt"
		phone = "123456"
		link = new Second 
		{
			job = "Programmer"
			link = new third 
			{
				salary = 49000
				vlist = [1,2,3,4,5] 
				tlist = [1000,2000,3000,4000]
				
			}
 
		}
	}
]

see mylist[5]
see mylist[6]

see "more..." + nl
see mylist[6].link.link.salary + nl

see mylist[6].link.link
see mylist[6].link.link.tlist

see vlist

	
Class First
	name address phone
	link

class second
	job link

class third
	salary
	tlist
	func settlist x
		see "nice " + nl
		tlist = x 
		tlist + 5000