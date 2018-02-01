#####################################
# Application  :  Functions
# Author        : Azzeddine Remmal            
# Date           : 08.01.2018                  
####################################



#----------------- Functions - Scope - Pass by value - Pass by reference 

#------- Ring 
# -------String | Number ----> Pass by value 
#-------- List   | Object ------> Pass by reference 

func main

	aList = 1:10
	test(aList)
	? aList 

func test aList 


	aList[1] = :one 
