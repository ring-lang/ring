/*  
 **      Application : variables (Conversion between strings and lists )
 **      name        : Abdelrahman Adam
 **      Date        : 20\12\2017 
*/ 
#======================================================

# variables type ( string , number , list , object , cobject )

#test23

aList = [ :one , :Two , :three , :four , :five ]
?aList
?len(aList)

#conversion to string
cList = list2str(aList)
?cList
?"string Count : " +len(cList)

#conversion to list
alist2= str2list(cList)
?Len(alist2)
