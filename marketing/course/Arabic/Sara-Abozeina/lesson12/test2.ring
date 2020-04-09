/*
**	Application:object-oriented
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
########
/*
init function to modify specific data in initialization
different style for object access
*/
########

func main
phone="8765432324568"
?new message("hello")
o1=new persons_data("1111")
?o1
new persons_data{self.name="sara" self.phone="567" print()}
new persons_data{?phone} 
new message{}

Class persons_data
	name="soha" phone="123"

	func init cphone
		phone=cphone
		return self

	func print
		?self

class message
	msg
	func init cmsg 
		msg=cmsg
		return self
	func braceend
		? "bye bye"
	
