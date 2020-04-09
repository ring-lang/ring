/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 06/05/2018
*/

load "stdlib.ring"

# times ( nCount, Function )

times(5, func { ? "Hello, World" })
times2(5, func { ? "Hello, World" })

func times2 nCount, function
	for t=1 to nCount
		call function()
	next
