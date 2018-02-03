/*
**          Application        		:Variables (Numbers version 2)
**          Author               		:Islam Deraz
**          Date                      	:2018.02.02
**          Application Number 	:4
*/ 

#========================================

#variable Types (string, number, list, object, c object)

		mynumber 	= 4          				# int 
		mynumber2	=10.26f			        # float | double

		mynumber3	= 1000000				
		mynumber4	= 1_000_000				

#========================================

# Display Data

		? mynumber
		?mynumber2
		?mynumber3
		?mynumber4
     	
#========================================

#Conversion

		x 			= 100 
		mystring 		= string(x)
		mynumber		=number(mystring)

		mystring2		= ""  +  x			# string + number -> string		
		mynumber2	= 0 + mystring 	        # number + string -> number

# performance ( operators faster than functions )
