/*  
 **      Application : Substr()
 **      name        : Abdelrahman Adam
 **      Date        : 20\12\2017 
*/ 
#======================================================

# variables type ( string , number , list , object , cobject )

#test25
cString = "Welcome to the Ring Programing Language (ring)"

?substr(cString,16,4)
?substr(cString,"Ring")					#get position of substring
?substr(cString,"Ring","***Ring***")			#replace substring

#not Case sensitive
?substr(cString,"Ring","***Ring***", true)
