/*
**	Application	: Ring lessons - Functional Programming - times() Method .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 22 .
*/

load "stdlib.ring"
# times ( nCount , Function )
times(5,func { ? "Hello Osama"})
? copy("--",10)
times2(5,func { ? "Hello Mahmoud"})

func times2 nCount, f
	for i = 1 to nCount
		call f()
	next
