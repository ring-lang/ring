###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 24.01.2018                  
###################################
load "stdlib.ring" 

aList = 1:10

aList2 = map(aList,func x {
	return x * x
	})

? aList 
? aList2
