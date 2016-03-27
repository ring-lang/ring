o1 = new first

o1 { 

	name = "Mahmoud" 
	link = new second 

	link {
		job = "programmer"
	}.level = fact(5)

	phone = "123456789"

} {id = 1 } .address = "Egypt"

MYSET(o1)

myprint(o1)	

func myset c1
	c1 {
		id = 2014
	}

func fact x
	if x = 1
		return 1
	else
		return x * fact(x-1)
	ok

func myprint c1
	see " ID   : " + c1.id + nl +
		" name : " + c1.name + nl + 
	    " address : " + c1.address + nl +
	    " phone : " + c1.phone + nl +
	    " job  : " + c1.link.job + nl +
	    " level : " + c1.link.level
	
class base
	id

Class first from base
	name address phone
	link

class second
	job
	level