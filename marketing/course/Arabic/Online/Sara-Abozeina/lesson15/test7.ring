/*
**	Application:functional programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
###############
/*
times ~copy ntimes
value ~copy {list|object}
*/
###############
load "stdlib.ring"

?times2(func{?"Hello"},3)
func times2 f,n
	for t=1 to n
		call f()
	next

###-----------###
alist=1:9
addlist(value(alist))
?alist
func addlist alist
	alist+22
	?alist
