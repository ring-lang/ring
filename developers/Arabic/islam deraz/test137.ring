/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.04.13
*/

load "stdlib.ring"
/*

	Reflection & Metaprograming

*/

operson = new person {
	name = "Hamza" address = "Egypt" phone = "123456"
}

? operson 
? attributes(operson)

addattribute(operson,:Salary)
? operson 

operson.Salary = "XXXXX"
? operson 

class person 
	name address phone 
