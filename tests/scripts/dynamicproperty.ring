o1 = new person {
	name = "Mahmoud" 	address = "Egypt"
	phone = 123456		job = "programmer"
}

o2 = new person { name = "ahmed" address = "egypt" phone = 123456789 }

o1.show()
see o1.job + nl

o2.show()
see o2.name + nl
see o2.job + nl

see job + nl

o1.job = "engineer"
see o1.job + nl
see o2.job + nl

test = "nice"
see o2.test + nl

class person

	name address phone

	func show

		see " name " + name +
		    " address " + address +
	 	    " phone " + phone + nl
