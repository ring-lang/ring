/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.02.02
*/

load "stdlib.ring"

/*
Reflection Metaprogramming
*/

oPerson = new person {
	name = "Mahmoud" address = "Lebanon" Phone = "+96171309876"
}

? oPerson
? attributes(oPerson)
? addattribute(oPerson,:Salary)
? oPerson
oPerson.Salary = "xxxxx"
? oPerson

class person
	name address phone
