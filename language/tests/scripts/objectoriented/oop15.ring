oPerson = new Person
oPerson.print()

oPerson2 = new Person2
oPerson2.print()

Class Person
	Name = "Mahmoud"
	age = 28
	Country = "Egypt"
	nice()
	func print
		see "Name : " + name + nl
		see "Age : " + age + nl
		see "Country : " + country + nl
	func nice
		see "Welcome to my class Person" + nl

Class Person2 from Person
	Name = "Ahmed"
	nice()
	func nice
		see "Welcome to my class Person2" + nl
