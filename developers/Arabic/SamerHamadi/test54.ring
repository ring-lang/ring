/*
**	Application    : clock 
**	Author 	       : Samer Hammadi
**	Date           : 17/12/2017
*/
#================================================================

t1 = clock()
for i=1 to 10000000
next

? "Performance:"+(clock()-t1)/clockspersecond()+"s"
