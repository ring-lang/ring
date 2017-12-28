/*            app :dir 





*/

afiles=dir("c:/perflogs/lesson7")
alist=[]
	for afile in afiles 
	 if right(afile[1],5)=".ring"
	alist +afile[1]
ok
	next

alist = sort(alist)
x=1
for cfile  in alist 
?"(" + x + "  ) " + cfile 
x++
next
give cnumber 
nnumber = 0 +cnumber 
if nnumber < len(alist)
? read(alist[nnumber])
ok
