/*
**	Application Name : Functional programming;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-29;		
*/

load "stdlib.ring"

alist = 1:10
map(alist, func x {
	? x
})
alist2 = filter(alist, func x {
	if x % 2 = 0
		return true
	else 
		return false
	ok
})
? alist2
