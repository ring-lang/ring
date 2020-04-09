/*  
 **      Application : cOpject
 **      name        : Abdelrahman Adam
 **      Date        : 20\12\2017 
*/ 
#======================================================

# variables type ( string , number , list , object , cobject )

#test29

#?read("lesson29.ring")

fP = fOpen("lesson29.ring","r")
for x = 1 to 10  ?fgets(fP , 100)  next
? fP
fClose(fP)
?fP
?type(fP)
