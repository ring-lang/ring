/*
**	Application:object-oriented
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
########
/*
Declarative
getter
*/
########


new addobj{
	obj{name="A" ID="2"}
	obj{name="B" ID="3"}

?alist		
}
	
class addobj  
	alist=[] obj

	func getobj
		alist+new obj
		return alist[len(alist)]


class obj
	name id
				


