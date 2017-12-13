/*
**  Application: SubStr()
**  Author     : Hany Hassan
**  Date       : 2017.12.13
*/
#=========================================================================================
# Variable Types (String, Number, List, Object, C Object)
cString = "welcome to the Ring programming language (ring)"

? cString 

? substr(cString,16,16)			# Get number of characters
? substr(cString,"Ring")		# Get position of substring 
? substr(cString,"Ring","***Ring***")	# Replace substring
? substr(cString,"Ring","***Ring***",True) # Replace substring
#=========================================================================================
