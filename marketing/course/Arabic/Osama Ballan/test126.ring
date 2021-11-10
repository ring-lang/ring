/*
**	Application	: Ring lessons - Functional Programming - Recursion.
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 22 .
*/

func main
	? fact1(5)		# 5 * 4 * 3 * 2 * 1
	? fact2(5)

func fact1 x
	if x = 0 
		return 1
	else return x * fact1(x-1)
	ok

func fact2 x
	nResult = 1
	for t = 1 to x
		nResult *= t
	next
	return nResult
