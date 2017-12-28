/*
	Application	: SubStr()
	Author		: Khaled ABID
	Date		:25/12/2017
*/

# Variable Types (String, Number, List, Object, C Object)

cString = "Welcome to the Ring Programming Language (ring)" 
? cString 
? substr(cString,16,4) 				# Get number of characters
? substr(cString,"Ring")			# Get position of substring
? substr(cString,"Ring","***Ring***")		# Replace substring
# Not case sensitive
	? substr(cString,"Ring","***Ring***",true)
