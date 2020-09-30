oPerson = new Person 
{ 
	name = "Mahmoud" 
	Country = "Egypt" 
	Job = "Programmer" 
	Print() 
}

oPerson { name = "ahmed" print() }

o1 = new Person
o2 = new Person
o3 = new Person
o1 { name = "one" } o2 { name = "two"} o3 { name = "three"}
see o1.name + nl + o2.name + nl + o3.name + nl

o4 = new Person 

printobj( o4{ name = "Love"} )

x = o4 {name = "Mahmoud"}.name + " from " + o4 {country = "Egypt"}.country

see x

func printobj c1
	see c1.name + nl

Class Person

	name country job 

	func print 

		see "Name    : " + name 	+ nl + 
			"Country : " + country 	+ nl + 
			"Job     : " + job 		+ nl