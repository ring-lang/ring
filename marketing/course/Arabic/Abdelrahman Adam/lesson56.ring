/*  
 **      Application : clock & clockspersecond
 **      Author      : Abdelrahman Adam
 **      Date        : 22/12/2017 
*/ 
#======================================================

t1 = clock()
for x=1 to 1000000
next

?(clock() - t1) / clockspersecond()
