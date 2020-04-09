/*
	Application 	: Reflection And Meta Programming Version 3
	Author		: Ahmed Mohamed
	Date		: 2019/11/02
*/

load "stdlib.ring"

/*
	Reflection & Meta Programming
*/

oPerson = new person {
	name = "Ahmed" address = "Egypt" phone = "xxxx"
}

? oPerson
? attributes(oPerson)

addattribute(oPerson, "Salary")

? oPerson
oPerson.salary = "1200"

? oPerson

class person 
	name address phone
	
