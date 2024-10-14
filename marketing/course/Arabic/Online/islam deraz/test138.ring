/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.04.13
*/

load "stdlib.ring"
/*

	Reflection & Meta-programming

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

addmethod(operson, "printsalary", func {
	? salary
})

? "salary: = "  ? operson.printsalary()

class person 
	name address phone 
