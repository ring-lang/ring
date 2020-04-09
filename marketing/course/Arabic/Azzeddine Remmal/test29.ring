#####################################
# Application  :  Object
# Author        : Azzeddine Remmal            
# Date           : 06.01.2018                  
####################################


# -----------Variable Types (String, Number, List, Object, C Object)

# -----------Ring (Compiler + VM) + Libraries (GUI, Games, Web, etc)

# ----------Libraries (Ring -or- C -or- C++)

# Web ---------> Ring
# GUI ----------> C++ (Qt + RingQt) + Ring classes 
# functions ----> C	(Pointer)



fp = fopen("test29.ring","r")
for x = 1 to 5 ? fgets(fp,100) next
? fp
fclose(fp)

? fp
? type(fp)
