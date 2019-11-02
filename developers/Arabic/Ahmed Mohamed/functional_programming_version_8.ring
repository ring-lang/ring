/*
	Application	: Functional Programming Version 8
	Author		: Ahmed Mohamed
	Date		: 2019/11/1
*/


load "stdlib.ring"

# times(nCount, functions)

times(5, func { ? "Hello World" })

times2(5, func { ? "Hello World 2" })

func times2 nCount, function
	for x = 1 to nCount
		call function()
	next
