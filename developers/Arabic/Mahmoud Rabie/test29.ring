/*

   	Application         : C Object
   	author                :Mahmoud Rabie 
	Date                   :2017/12/24  
*/

#===============================================================
 
// read("test29.ring")
fp = fopen("test29.ring","r")
for x = 1 to 5 ? fgets(fp,100) next
? fp
 
fclose(fp)

? fp
? type(fp)  
