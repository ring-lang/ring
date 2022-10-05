/*
**	Application:Trace Library 
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
trace for functions
*/

load "tracelib.ring"
trace(:Functions)

func main	
new person{msg("inside method")}

new person {print("sara")}

msg("outside method")			

func msg data{
	?"msg from second class!"
	?data
	return new person2
}
func print data			            # it is a function.
	?"hello in func print()"
	?data
	return data

Class person
	name="A" age="B" 
		
	func print data			    # it is a method
		?"hello in method print()"
		?data
		return data			

	func msg data
		?"Hello world!"
		?data
		print("A")		    # search in the methods firstly
		
		NEW local{
				print("S")  # escape from class scope ,so print function not method
		}
class local

Class person2				
	name age job
