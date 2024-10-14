###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 24.01.2018                  
###################################

func main
	aList = 1:10
	? mypurefunction(aList)
	? aList


func mypurefunction  aList 
	aList2 = aList		#------- Copy 
	aList2[1] = "one"
	aList2[10] = "ten"
	return aList2
