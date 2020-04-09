/*
**	Application:Lexical Scoping
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
##---objects in class region---##

*/
######
$name="B"				
func main	
new person{print()}

Class person
	name="A" age="B" company
		new person2{

			name="xxx"
			age ="xxx"
			job ="xxx"
			?self		# class scope
		}
		?self			# class scope

	func print
		new person2{

			name="xxx"
			age ="xxx"
			job ="xxx"
			?self		# object scope
		}
		?self			# class scope

Class person2
	name age job
