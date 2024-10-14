/*
**	Application:Trace Library 
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
Trace(:PassError)
Trace(:Debugger)
Trace(:LineByLine)
BreakPoint()
*/
load "tracelib.ring"
Trace(:PassError)
Trace(:Debugger)
#Trace(:LineByLine)
#NoBreakPoints()
?1/0					# by Trace(:Debugger)/PassError we can continue execute.
? "Give name:" Give name ? "Hello "+name
BreakPoint()				# break code output 

func main	
new person{msg("inside method")}
new person {print("sara")}
msg("outside method")			
func msg data{
	?"msg from second class!"
	?data
	return new person2
}
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
