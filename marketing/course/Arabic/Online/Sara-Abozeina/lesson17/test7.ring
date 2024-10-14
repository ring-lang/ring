/*
**	Application:Lexical Scoping
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
##---conflict between local & class---##
(1)special marks for class attributes{@}
*/
######
$name="B"				
func main	
o1=new person{

		@name="sara"		# take the object attributes
		@age="__"
		?self	
}			
new addpersons{add(o1) ?alist}
	 			
new person{
		print()			?"2------2"
		say("Hello ","Heba")	?"3------3"
		?@name			?"4------4"
}
Class addpersons
	alist=[] 	
	func add obj		
		alist+new person
		return alist[len(alist)]

Class person
	@name="A"  @age="XXX" 		# class
	func print			# local
		?@name			# I control what will be showed 

	func say msg,name		# local
		? msg+name		# to take func para.
		? msg+@name		# to take class attribute
