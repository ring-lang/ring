/*
**	Application		:cObjects 1
**	Author			:Adel Mahmoud
**	Date			:2018.01.29
*/

#=========================================================
#           
# Variable Types (String, Number, List, Object, C Object)

# Ring (Compiler + VM) + Libraries (GUI, Games, Web, etc)

# Libraries (Ring --- C --- C++)

# Web --> Ring
# GUI --> C++ (Qt + RingQt) + Ring classes 
# functions ---> C	(Pointer)

# ? read("test29.ring")			# read will eat the memory if file is big

fp = fopen("030-cObject1.ring","r")	# fp is cObject

for x = 1 to 3 ? fgets(fp,100) next	# 100 is 100 character but from 1 line

? fp					# 00717C50 is the pointer in memory for fp
fclose(fp)				# file in memory closed

? fp					# 00000000 because file closed
? type(fp)				# type is file

#
#=========================================================


