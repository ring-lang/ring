/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.31
*/

load "stdlib.ring"

# times ( nCount , function )

times( 5, func { ? "Hello, World" } )
times2( 5, func { ? "Hello, World" } )

func times2 nCount,function 
	for t=1 to nCount 
		call function()
	
	next

	
