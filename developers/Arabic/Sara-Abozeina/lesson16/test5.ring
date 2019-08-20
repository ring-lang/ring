/*
**	Application:reflection and meta programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.03
*/
######
/*
addmethod

*/
######
mergemethods(:test1,:test2)
o=new test1
?o
addattribute(o,:age)
o.age=:XXX
?o
?attributes(o)

#----------#
o2=new test2
f=func{
	? "that is the information :"
}
addmethod(o2,:print,f)
?o2.print()
?o2
#----------#

Class test1
	name="A" phone="___" company="XXX"
	
Class test2 from test1   #doesn't has the new attribute
