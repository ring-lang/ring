/*
**	Application:stdlib classes
**	Author	   :Sara Abozeina
**	Date       :2018.01.03
*/

Load "stdlib.ring"


func rmNullLines filename,newfile		#remove empty lines
	cLines=read(filename)
	oString = new string(cLines)
	alist=oString.tolist()
	alist2=[]
	for x=1 to len(alist)
		if isNull(alist[x])  loop
		else alist2+trim(alist[x])
		ok
	next
	write(newfile,list2str(alist2))
	return newfile
