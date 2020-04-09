/*
**	Application:Lexical Scoping
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
##---this---##

*/
######
$name="B"				
func main	
new person{print()}

Class person
	name="A" age="B" company

		?name			# class scope
	func print
		?name			# local scope ,searches in class scope

		new person2{		# it is a way to escape from class scope to object 
			msg()
			name="xxx"
			age ="xxx"
			job ="xxx"
			?name		# object scope
			this.msg()	# to use method from the current class
		}
		?name			# class scope

	func msg
		?"Hello world!"


Class person2				# it is a way to escape from class scope to object 
	name age job

	func msg
		?"msg from second class!"
