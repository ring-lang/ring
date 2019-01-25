/*
	Application : Clock
	Author      : Salwa Abdrabu
*/

t1 = clock()

for x = 1 to 100000
next

? (clock()- t1) / clockspersecond()
