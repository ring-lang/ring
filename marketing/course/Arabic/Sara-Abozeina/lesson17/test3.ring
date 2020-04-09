/*
**	Application:Lexical Scoping
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
##---conflict between global & class---##
(1)func main
(2)special marks for global variables {$}
(3)self for attributes
*/
######
name="B"
func main			#to avoid conflict

new addpersons{
	add(){
		self.name="sara" 
		self.age="__"
		?self 
	}
			
}

Class addpersons
	alist=[] 	
	func add		
		alist+new person
	return alist[len(alist)]

Class person
	self.name="A"  self.age="XXX" 
