/*
**	Application Name : Functional programming;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-29;		
*/

func main
	? fact(5)
	? fact2(5)

func fact x
	if x = 0 return 1 ok
	return x * fact(x - 1)

func fact2 x
	nresult = 1
	for t = x to 1 step -1
		nresult *= t
	next
	return nresult
