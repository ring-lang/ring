/*
**	Application:stdlib classes
**	Author	   :Sara Abozeina
**	Date       :2018.01.03
*/
###############
/*
list classes
*/
###############
load "stdlib.ring"
load "test.ring"
rmNullLines("test2.ring","x.ring")
cLines=read("x.ring")
oString= new string(cLines)
getstrings=oString.getfrom(1) #object
alist2=getstrings.tolist()
oList  = new list (alist2)
oList.Find("list classes")   #show index
olist.sort().print()
?olist.first()
?olist.last()
#olist.insert(24,"thanks") 


