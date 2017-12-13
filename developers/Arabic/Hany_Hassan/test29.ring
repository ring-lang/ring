/*
**  Application: Object
**  Author     : Hany Hassan
**  Date       : 2017.12.13
*/
#=========================================================================================
# Variable Types (String, Number, List, Object, C Object)
fp = fopen("test29.ring","r")
for x = 1 to 5 ? fgets(fp,100) next
? fp
fclose(fp)

? fp
? type(fp)

#=========================================================================================
