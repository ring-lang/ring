/*
**	Application:lexical scoping
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
scope in methods and functions {with the same name}
*/
######

$name="B"
			
func main	
new person{msg()}

new person {print("sara")}			


func print data			            # it is a function
	?"hello in func print()"
	?data
	return data

Class person
	name="A" age="B" 
		
	func print data			    # it is a method
		?"hello in method print()"
		?data
		return data			

	func msg
		?"Hello world!"
		print("A")		    # search in the methods firstly
		
		NEW local{
				print("S")  # escape from class scope ,so print function not method
		}
class local

Class person2				
	name age job

	func msg
		?"msg from second class!"
