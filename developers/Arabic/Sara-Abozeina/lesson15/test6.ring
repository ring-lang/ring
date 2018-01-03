/*
**	Application:functional programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
###############
/*
recursion
*/
###############
#call its self 

?fact(5)
?fact2(5)
func fact x
	if x=0 return 1 ok
	return x *fact(x-1)

func fact2 x
	res=1
	for t=x to 1 step -1
		res*=t
	next
	return res
