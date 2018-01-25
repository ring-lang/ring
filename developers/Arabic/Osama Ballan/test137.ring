/*
**	Application	: Ring lessons - Reflection and Meta-programming .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 24 .
*/
/*
	Reflection and Meta-programming - addattribute(Object,attribute)
*/
Load "stdlib.ring"

oPerson = new person {name = "Osama" address = "Syria" phone = "223443"}

? oPerson
? attributes(oPerson)				# Reflection

addattribute(oPerson , :salary)		# Meta-programming
oPerson.salary = "10000$"			# Add Attribute to Object
? oPerson

oMan = new person {name = "Kinan"}
? attributes(oMan)				

Class person
		name address phone

