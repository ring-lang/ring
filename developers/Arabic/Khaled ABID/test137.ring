/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 07/05/2018
*/

load "stdlib.ring"

/*
	Reflection & Metaprogramming
*/

oPerson = new person {
	name = "khaled" address = "Algeria" phone = "+213123"
}

? oPerson
? attributes(oPerson)

addattribute(oPerson,:Salary)
? oPerson
oPerson.Salary = "1234xx"
? oPerson

class person
	name address phone
