/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

Load "stdlib.ring"

/*

		Reflection & Metaprogramming 

*/


oPerson = new Person {
		name ="Salwa" address ="Egypt" phone ="5345"

}

? oPerson 
? attributes(oPerson)
addattribute(oPerson , :salary)

? oPerson 

oPerson.salary = "xxxxxxxxxxx"

? oPerson 

//=========================================================
class Person 
	name address phone
