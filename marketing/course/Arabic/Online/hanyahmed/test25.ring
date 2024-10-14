# variables types 
/*
*Application       : substr()
*Author            : Hany Ibrahim Ahmed
*Date              : 20/12/2017
*/
#variables types (string,number,list,object,c object)
cstring="welcome to the ring language Ring"

?cstring
?substr(cstring,16,4)    # get number of character
?substr(cstring,"ring")  # get position of substring
?substr(cstring,"ring","**ring**") # replace substring
# not case-sensitive
?substr(cstring,"ring","**ring**",true)
