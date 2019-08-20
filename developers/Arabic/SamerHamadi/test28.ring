/*
**	Application    : C Object
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

//? read("test28.ring")

fp = fopen("test28.ring" ,"r")
for x=1 to 5 ? fgets(fp,100) next
? fp
fclose(fp)

? fp
? type(fp)

