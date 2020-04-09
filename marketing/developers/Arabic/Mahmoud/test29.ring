/*
	Application 	: Object
	Author		: Mahmoud Fayed
	Date		: 2017.12.13
*/

# Variable Types (String, Number, List, Object, C Object)

# Ring (Compiler + VM) + Libraries (GUI, Games, Web, etc)

# Libraries (Ring --- C --- C++)

# Web --> Ring
# GUI --> C++ (Qt + RingQt) + Ring classes 
# functions ---> C	(Pointer)

//? read("test29.ring")

fp = fopen("test29.ring","r")
for x = 1 to 5 ? fgets(fp,100) next
? fp
fclose(fp)

? fp
? type(fp)
