/*
**	Application:functional programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
###############
/*
first class,copy value in list&objects
*/
###############
load"stdlib.ring"
func main

	o1=new listops
	o1{ copyandedit(1:3) }
		 
?o1.alist2

##--------###
alist=1:5
?purefuncedit(alist)
?alist
func purefuncedit alist
	alist2=alist
	alist2[2]="two"
	return alist2	

##--------###


class listOps 
	alist=[] alist2	
	func copyandedit alist
		alist2=alist
		alist2+25+26
		return alist2
