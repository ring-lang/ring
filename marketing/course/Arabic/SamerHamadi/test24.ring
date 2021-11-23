/*
**	Application    : SubStr() 
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

cString = "Welcome To The Ring Programming Language (ring)"

? cstring

? substr(cstring,16,4)			# Get number of characters
? substr(cstring,"Ring")		# Get Position of substring
? substr(cstring,"Ring","***Ring***")	# Replace substring
# Not case sensitive
            ? substr(cstring,"Ring","***Ring***",true)	# Replace substring
