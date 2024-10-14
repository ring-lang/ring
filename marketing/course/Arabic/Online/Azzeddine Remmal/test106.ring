#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 20.01.2018                  
####################################



new point 
{			 #-------- call bracestart()
	x=10 y=10 z=30
	? self
	
	ssdhsdh     # Error ---> BraceError()
}			#--------- call braceend()



class point 
	x y z 

	func bracestart 
		? "Start!"

	func braceend
		? "End!"

	func braceerror
		? "Error!" 
