/*
**	Application	: Ring lessons - Reflection and Meta-programming .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 24 .
*/

Load "stdlib.ring"

oPerson = new person {name = "Osama" address = "Syria" phone = "223443"}

? oPerson
? attributes(oPerson)				# Reflection

addattribute(oPerson , :salary)		# Meta-programming
oPerson.salary = "10000$"
? oPerson

addmethod(oPerson,"printsalary",Func { return salary })	# Add Method To Class
? "Salary(oPerson) : " + oPerson.printsalary()

oMan = new person {name = "Kinan" salary = "500$"}
? "Salary(oMan) : " + oMan.printsalary()
? attributes(oMan)

Class person
		name address phone

