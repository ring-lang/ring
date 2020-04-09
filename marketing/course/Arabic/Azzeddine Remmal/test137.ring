###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 24.01.2018                  
###################################

load "stdlib.ring"


#---------Reflection & Metaprogramming


oPerson = new Person {
	name="Mahmoud" address="Egypt" phone="23632623"
			}

? oPerson
? attributes(oPerson)

addAttribute(oPerson,:salary)
? oPerson
oPerson.Salary = "XXXXXXXXXX"
? oPerson

class person 
	name address phone 
