/*
	Application	: Clock
	Author		: Khaled ABID
	Date		: 04/02/2018
*/

t1 = clock()

for x = 1 to 1000000
next

? (clock() - t1)/clockspersecond()
