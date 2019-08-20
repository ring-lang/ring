/*
**	Application Name : Functional programming;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-29;		
*/

load "stdlib.ring"
alist = 1:10
alist2 = map(alist, func x {
	? x * x
})
? alist
? alist2
