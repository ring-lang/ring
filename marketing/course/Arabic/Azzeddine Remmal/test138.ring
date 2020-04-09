###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 24.01.2018                  
###################################

load "stdlib.ring"


#----------------Reflection & Metaprogramming


func main 

oPerson = new Person {
	name="Mahmoud" address="Egypt" phone="23632623"
	}

? oPerson
? attributes(oPerson)

addAttribute(oPerson,:salary)
? oPerson
oPerson.Salary = "XXXXXXXXXX"
? oPerson

addMethod(oPerson,"PrintSalary", func {
	? Salary
	})

? "Salary = " ? oPerson.PrintSalary()


class person 
	name address phone 
