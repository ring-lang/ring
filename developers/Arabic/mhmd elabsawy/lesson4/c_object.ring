# app     :c_objects
# author  : mhmd elabsawy
#-----------------------------------------------------------------
fp = fopen("c_object.ring","r")
for x = 1 to 5 ? fgets(fp,100) next
? fp
fclose(fp)

? fp
? type(fp)






