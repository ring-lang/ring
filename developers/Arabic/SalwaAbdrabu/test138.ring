/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

Load "stdlib.ring"

/*

		Reflection & Metaprogramming 

*/


func main
oPerson = new Person {
		name ="Salwa" address ="Egypt" phone ="5345"

}

? oPerson 
? attributes(oPerson)
addattribute(oPerson , :salary)

? oPerson 

oPerson.salary = "xxxxxxxx"

? oPerson 

addmethod(oPerson , "PrintSalary" , func{ ? salary })
? "Salary:" ? oPerson.PrintSalary()
//=========================================================
class Person 
	name address phone
