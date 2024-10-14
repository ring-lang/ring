/*
**	Application:functional programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
###############
/*
anonymous function 
*/
###############
load"stdlib.ring"

f1=func {?"Hello world!"}
callfunc(f1)
f2=func {
		?"That it is Ring Language Programming,please wait...."
		f3=func {sleep(3)}	
		callfunc(f3)
		?"you can read more about it in that ref."+
		system(exefolder()+'/../docs/"ring.pdf"') 
}
callfunc(f2)
	
func callfunc f
	call f()
