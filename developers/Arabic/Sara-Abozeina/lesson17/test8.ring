/*
**	Application:Lexical Scoping
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
##---objects in local region---##

*/
######
$name="B"				
func main	
new person{print()}

Class person
	name="A" age="B" company

	func print
		new person2{

			name="xxx"
			age ="xxx"
			job ="xxx"
			?self		# object scope
		}
		?self			# class scope

		new person2{

			name="fff"
			age ="fff"	
			job ="xxx"
			this.company="ll"	# add data to class from obj scope by this
			?self			# object scope
		}
		?self				# class scope

Class person2
	name age job
