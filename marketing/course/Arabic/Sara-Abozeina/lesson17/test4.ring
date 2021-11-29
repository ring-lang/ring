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
$name="B"				# $ is a sol.
func main				# main to avoid conflict

new addpersons{
	add(){
		self.name="sara"	 # self is sol.
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
	self.name="A"  self.age="XXX" 	# self is sol.
	func print
		? name	
