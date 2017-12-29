/*
**	Application Name : Functional programming;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-29;		
*/

load "stdlib.ring"

times(5, func { ? "hello " })
times2(5, func { ? "hello " })

func times2 nCount, function
	for t = 1 to nCount
		call function()
	next
