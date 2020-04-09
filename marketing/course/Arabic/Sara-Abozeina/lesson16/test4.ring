/*
**	Application:reflection and meta programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.03
*/
######
/*
addattribute
*/
######
o=new test1
?o
addattribute(o,:age)
o.age=:XXX
?o
?attributes(o)

Class test1
	name="A" phone="___" company="XXX"
	

