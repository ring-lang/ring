/*
	Application : SubStr()
	Author      : Salwa Abdrabu
*/

# Variables Type( String, Number, List, Object, C Object )
cString = "Welcome To The Ring Programming (ring)"
? cString

# Get Number Of Characters
? substr(cString,16,4)

# Get Position Of SubString		       
? substr(cString,"Ring")

# Replace SubString              
? substr(cString,"Ring","***Ring***") 

# Replace SubString (Not Case Sensitive)               
? substr(cString,"Ring","***Ring***",True)  
 

