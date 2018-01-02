/*
**	Application:object-oriented
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
########
/*
init
inheritance
*/
########

func main
new persons_data("A","122321","TTT")
new persons_data("B","7387","QQQQ")
new persons_data{
		name="sara"
		address="Egypt"	
		phone="___"
		print()
}
new edit_data("c","11111","xxxxx")

Class persons_data
	name address  phone  

	func init cname,cphone,caddress
		name=cname		
		phone=cphone		
		address=caddress
		print()			
		return self


	func print
		?self

class edit_data from persons_data

	func second_init 
		super.init()






