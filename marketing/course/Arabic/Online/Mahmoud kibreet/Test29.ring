/*
          Application : Object
          Author      : Mahmoud Kibreet
          Date        : 2018.01.25
*/

# Variable Types (String , Number , List , Object , C Object)

# Ring (Compiler + VM) + Libraries (GUI , Games , Web , etc)

# Libraries (Ring --- C --- C++ )

# Web --> Ring
# GUI --> C++ (Qt + RingQt) + Ring Classes
# Functions ---> C        (Pointer)
//? read("Test29.ring")
fp = fopen("Test29.ring","r")
for x = 1 to 5 ? fgets(fp,100) next
? fp
fclose(fp)
? type(fp)
