/*  
 **      Application : Substr()
 **      Author      : Abdelrahman Adam
 **      Date        : 20/12/2017 
*/ 
#======================================================

# variables type ( string , number , list , object , cobject )

#test25

cString = "Welcome to the Ring Programming Language (ring)"

? substr(cString, 16, 4)
? substr(cString, "Ring")                  # Get position of substring
? substr(cString, "Ring", "***Ring***")    # Replace substring

# not Case sensitive
? substr(cString, "Ring", "***Ring***", true)
