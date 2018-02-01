###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 24.01.2018                  
###################################

load "stdlib.ring" 

aList = 1:10

map(aList,func x {
	? x
 	})

aList2 = filter(aList,func x {
	if x % 2 = 0 
		return True
	else 
		return False
	ok
	})

? aList2

