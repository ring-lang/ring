/*
**	Application:stdlib classes
**	Author	   :Sara Abozeina
**	Date       :2018.01.03
*/
###############
/*

string classes
*/

###############

load "stdlib.ring"
cLines=read(filename())
oString = new string(cLines)
nMax=oString.Lines()
file1=oString.tofile("file.ring")
?oString.strcmp(file1)
cfile2=oString.getfrom(1)  #get from the first position()
afile=oString.tolist()
n=len(afile)
alist1=[]
alist2=[]
for x=1 to n
	alist1+trimall(afile[x])	#remove spaces in each line
	alist2+trim(afile[x])
next
write("new1.ring",list2str(alist1))
write("new2.ring",list2str(alist2))
cLines1=read("new1.ring")
cLines2=read("new2.ring")
?oString.strcmp(cLines1)
?oString.strcmp(cLines2)
oString.copy(2)



