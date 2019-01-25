/*
	Application : Object
	Author      : Salwa Abdrabu
*/

# Variables Type( String, Number, List, Object, C Object )

# Ring (Compiler + VM) + Libraries (GUI ,Games ,Web ,etc)
# Libraries ( Ring --- C --- C++ )
# web ---> Ring
# GUI ---> C++(Qt + RingQt) + Ring Classes
# Functions ---> C  (Pointer)
// ? read ("test29.ring")
fp = fopen("test29.ring","r")
for i = 1 to 5 ? fgets(fp,100) next
? fp
fclose(fp)

? fp 
? type(fp)
