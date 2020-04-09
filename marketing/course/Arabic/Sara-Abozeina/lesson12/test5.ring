/*
**	Application:object-oriented
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
########
/*
init, put data according to  class attributes 
inheritance
edit object data by accessing braces
private
*/
########


new persons_data("A","122321","TTT")
new persons_data("B","7387","QQQQ") 

new persons_data{
		print()
		name="XXXX"
		print()

}
new edit_data("c","11111","xxxxx")
o1=new edit_data{check()}
?o1

Class persons_data
	name="sara" address="Egypt" phone="___"  

	func init cname,cphone,caddress
		name=cname		
		phone=cphone		
		address=caddress
		print()
	func print
		?self
	
class edit_data from persons_data

	func second_init 
		super.init()

	func check
		cresponse=""
		while cresponse != 'n'
			?tab+tab+"do you want to edit|add|show data?!(Y|N)" Give cresponse
			if cresponse="y"
		
					?tab+tab+"ok,that is the data:"
					?tab+tab super.print()
					edit()						
			else
					loop
		
			ok
		end

	func edit
			eval('?"Enter the name"          Give name	')
			eval('?"Enter the address"       Give address	')
			eval('?"Enter the phone"         Give phone  	')

#it is appeared & take its "data" not attribute from class only
	print_private()
private
	name ="ZZZZ"
	phone="5555"
	func print_private
		?self
