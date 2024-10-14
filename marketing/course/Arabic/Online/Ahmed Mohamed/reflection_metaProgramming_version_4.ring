/*
	Application 	: Reflection And Meta Programming Version 4
	Author		: Ahmed Mohamed
	Date		: 2019/11/02
*/

load "stdlib.ring"

/*
	Reflection & Meta Programming
*/

func main

oPerson = new person {
	name = "Ahmed" address = "Egypt" phone = "xxxx"
}

? oPerson
? attributes(oPerson)

addattribute(oPerson, "Salary")

? oPerson
oPerson.salary = "1200"

? oPerson

addmethod(oPerson, "printSalary", func {
	? salary
})

see "Salary = " see oPerson.printSalary()

class person 
	name address phone
	
