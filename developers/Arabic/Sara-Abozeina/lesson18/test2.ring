/*
**	Application:lexical scoping
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
scope in methods and functions
*/
######
load "stdlib.ring"

$name="B"			
func main	
new person{msg()}

print("sara")			# 2-search in functions {stdlib funcs}

Class person
	name="A" age="B" company
		
	func print data			


	func msg
		?"Hello world!"


Class person2				
	name age job

	func msg
		?"msg from second class!"
