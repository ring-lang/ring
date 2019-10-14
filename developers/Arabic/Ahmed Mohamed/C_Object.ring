/*
	Application	: C Object
	Author		: Ahmed Mohamed
	Date		: 2019/10/14
*/


# Variables Types (Strings, Number, List, Object, C Object)

# Ring (Compiler + VM) + Libraries (GUI, Games, etc)

# Libraries (Ring --- C --- C++)
# Web --> Ring
# GUI --> C++ (Qt + RingQt) + Ring Classes
# functions ---> C 	(Pointer)


#? read("Object.ring")

fp = fopen("Object.ring", "r")

for x = 1 to 5 ? fgets(fp, 100) next

? fp

fclose(fp)
