/*
**	Application:functional programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
###############
/*
anonymous function ,call func ,return func
*/
###############
load"stdlib.ring"

f1=func {?"Hello world!"}
call f1()
#-----------------#

f2=callfunc()
call f2()


func callfunc      	 

	return func{
			?"Welcome!"
	}
