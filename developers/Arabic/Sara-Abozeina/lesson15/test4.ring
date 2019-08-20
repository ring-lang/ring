/*
**	Application:functional programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
###############
/*
first class,pure 
*/
###############
load"stdlib.ring"


o1=new listops{ sum() }
?o1.alist
?o1.alist2

class listops
	alist=[1,2,3,4,5,6,7,8,9,10]
	alist2=[]
	func sum 
		alist2=sumlist(alist)
		sqrt(alist2)
		return alist2


		
	


