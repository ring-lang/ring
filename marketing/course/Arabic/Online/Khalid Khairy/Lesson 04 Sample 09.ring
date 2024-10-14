/*
**	Application : SubStr()
**	     Author : Khalid Khairy
**	       Date : 14/12/2017
*/

#========================================================

cString = "welcome to the Ring programming language (ring)"
?cString

? substr(cstring,16,4)				# Get number of characters
? substr(cstring,"Ring")			# Get position of substring
? substr(cstring,"Ring", "***Ring***")  	# Replace subString
? substr(cstring,"Ring", "***Ring***", true)    # Replace subString Not CaseSensitive








