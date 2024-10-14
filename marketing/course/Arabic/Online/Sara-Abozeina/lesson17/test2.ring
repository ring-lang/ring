/*
**	Application:Lexical Scoping
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
##---conflict between global & local {variables}---##
(1)func main
(2)special marks for global variables {$}
*/
######
$name="B"
func main			#to avoid conflict

new addpersons{
	add(){
		name="sara" 
		age="__" 
	}
?alist				#take data from object braces
}

Class addpersons
	alist=[] 	
	func add		
		alist+new person
	return alist[len(alist)]

Class person
	name="A"  age="XXX" 
