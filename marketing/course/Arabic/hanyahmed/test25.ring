# variables types 
/*
*application       : substr()
*auther            : Hany Ibrahim Ahmed
*Date              : 20/12/2017
*/
#variables types (string,number,list,object,c object)
cstring="welcome to the ring language Ring"

?cstring
?substr(cstring,16,4)    # get number of character
?substr(cstring,"ring")  # get postion of substring
?substr(cstring,"ring","**ring**") # replace substring
# not casesensitive
?substr(cstring,"ring","**ring**",true)
