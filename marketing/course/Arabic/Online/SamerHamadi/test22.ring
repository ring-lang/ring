/*
**	Application    : conversion between lists and string
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

aList = [:one, :two, :three, :four, :five]

? alist
? len(alist)

cstring = list2str(aList)
? len(cstring)

? cstring

alist2 = str2list(cstring)
? len(alist2)
