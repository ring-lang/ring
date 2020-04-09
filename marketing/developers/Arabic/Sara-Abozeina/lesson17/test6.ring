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
func main				# main to avoid conflict
new addpersons{
	add(){
		name="sara"	
		age="__"
		?self			# take class attributes	as it can not define these attributes for class person	 			
	}
#?alist[1]		
}

new person{
		print()			?"2------2"
		say("Hello ","Heba")	?"3------3"
		?@name			?"4------4"
		?name	
}
Class addpersons
	alist=[] 	
	func add 		
		alist+new person
		return alist[len(alist)]

Class person
	@name="A"  @age="XXX" 		# class
	func print			# local
		?@name			# I control what will be showed 

	func say msg,name		# local
		? msg+name		# to take func para.
		? msg+@name		# to take class attribute
