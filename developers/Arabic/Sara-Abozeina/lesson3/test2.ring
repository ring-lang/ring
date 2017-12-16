/*
**	Application	: 	isNull()
**	Author		: 	Sara Abozeina
**	Date			:	2017.12.16	
*/

Hfile=fopen("/home/sara/newfile.txt","r+")
fstrings=fread(Hfile,200)
#  the empty file is not null but has value 0
#  "" = = Null
cStrings=fgets(Hfile,100)
? "isNull(fstrings):  "+isNull(fstrings)
alist=[1,2,Null ,3,4,""]
?isNull(alist[3])		#1
?isNull(alist[6])		#1


