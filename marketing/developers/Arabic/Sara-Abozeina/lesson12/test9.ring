/*
**	Application:object-oriented
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
########
/*
Declarative
*/
########


o1=new obj("sara","1"){
?self
}


new addobj{
	add(){
		name="A" ID="2"
	}
	add(){
		name="B" ID="3"
	}
?alist
?copy("*",5)	
?alist[1]
}

	
class addobj  
	alist=[]
	func add   		    #simple func to add objects to list
		alist+new obj
		return alist[len(alist)]
class obj
	name id
	func init cname,cid
		name=cname
		id=cid
	return self
				


