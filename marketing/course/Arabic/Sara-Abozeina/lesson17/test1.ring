/*
**	Application:Variables Scope
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*

*/
######
variables=[:x]			# global scope

func main            	        # to separate local and global functions

test()				# take its data from global


new object{		
	?variables		# object scope(inside objects)=>search in self braces then calss then global
}

new Global{
	?variables		# take data from class
}

new Local{
	variables=[:y,:z]	# take from braces
	?variables
}

func test			# local function search in self then global
	?variables	

Class Global
	variables=[:x,:y,:z] functions   

Class Object	
	attributes methods

Class Local 
	attributes functions methods
