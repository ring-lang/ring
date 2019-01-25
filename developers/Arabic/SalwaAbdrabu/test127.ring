/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

load "stdlib.ring"

# times( nCount , Function )

times(5,func{ ? "Hello,World!"})

times2(5,func{ ? "Hello,World!"})

func times2 nCount,Function

	for x = 1 to nCount
		call Function()
	next
	
