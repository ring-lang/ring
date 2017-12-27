/*


app:conversion between lists and strings 
author:heba atef 
date: 26.12.2017
*/
alist=[:one, :two, :three , :four ,:five]
?alist
?len(alist)
cstring=list2str(alist)
?cstring 
?len(cstring)


alist2=str2list(cstring)
?len(alist2)



cstring="hello"
?upper(cstring)
?lower(cstring)
?left(cstring,2)
?right(cstring,2)
?substr(cstring,3,2)
