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

o2=new obj{name="A" ID="2"}
o3=new obj{name="B" ID="3"}
o4=new addobj
{
	add(o2)
	add(o3)	
}
?o4.alist
?o4.first().name
o4.last().id=40
?o4.alist
class addobj  
	alist=[]
	func add ooob			###to add objects directly by reference
		alist+ooob
		return alist[len(alist)]

	func first
		return alist[1]
	func last
		return alist[len(alist)]
	
class obj
	name id
	func init cname,cid
		name=cname
		id=cid
	return self
				


