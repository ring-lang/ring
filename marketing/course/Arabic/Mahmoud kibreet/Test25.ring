/*
          Application : Substr()
          Author      : Mahmoud Kibreet
          Date        : 2018.01.24
*/

# Variable Types (String , Number , List , Object , C Object)

cString = "welcome to the Ring program language (ring)"

? cString

? substr(cString,16,4)     	           # Get number of characters
? substr(cString,"Ring")   	           # Get position of substring
? substr(cString,"Ring","***Ring***") # Replace substring

# Not case sensitive
	? substr(cString,"Ring","***Ring***",True)
