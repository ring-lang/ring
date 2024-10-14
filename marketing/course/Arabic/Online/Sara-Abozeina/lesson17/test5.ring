/*
**	Application:Lexical Scoping
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
##---conflict between global & class---##
(1)special marks for global variables{$}
(2)self for object&class attributes 
(3)change the global variable $
*/
######
name="B"				
func main				# main to avoid conflict

new addpersons{
	add(){
		self.name="sara"	# self is sol. 
		self.age="__"
		?self 
	}
			
}
new person{print()}
Class addpersons
	alist=[] 	
	func add		
		alist+new person
	return alist[len(alist)]

Class person
	self.name="A"  age="XXX" 		# self is sol.
	func print
		?name	
