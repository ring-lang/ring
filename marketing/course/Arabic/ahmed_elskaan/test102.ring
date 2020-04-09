/*
**	Application Name : class from stdlib;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-29;		
*/
load "stdlib.ring"

oPerson = new person {
	name = "ahmed" address = "cairo" phone = "1234"
}
? oPerson
? attributes(oPerson)
addattribute(oPerson, :salary)
oPerson.salary = "23333"
? oPerson

class person 
	name address phone
