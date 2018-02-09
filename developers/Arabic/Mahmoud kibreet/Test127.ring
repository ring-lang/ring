/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.02.02
*/

load "stdlib.ring"     

# time( nCount , function)

times(5 , func { ? "Hello , World" })
times2(5 , func { ? "Hello , World" })


func times2 nCount,function
	for t = 1 to nCount
		call function()
	next
