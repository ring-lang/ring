###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 28.01.2018                  
###################################

/*
	Variables Scope 
		Three Scopes 
			[1] -------Global Scope 
			[2] -------Object Scope 
			[3] -------Local Scope 

*/

#------------ Conflict between the global variable and local variable 

x=10 y=20			#-------- x,y are global variables 
nSum = x + y 			# --------nSum is global 
? sum(5,6)
? nSum 

func sum x,y			#--------- x,y are local variable  
	nSum = x+y 		#--------- nSum is expected to be Local !
	return nSum 
