/*
	Application	: C Object
	Author		: Khaled ABID
	Date		:28/12/2017
*/

# Variable Types (String, Number, List, Object, C Object)

# Ring (Compiler + VM) + Libraries (GUI, Games, Web, etc)

# Libraries (Ring --- C --- C++)

# Web --> Ring
# GUI --> C++ (Qt + RingQt) + Ring classes
# Functions ---> C 	(Pointer)

//? read("test29.ring")

fp = fopen("test29.ring","r")
for x = 1 to 5 ? fgets(fp,100) next
? fp
fclose(fp)

? fp
? type(fp)
