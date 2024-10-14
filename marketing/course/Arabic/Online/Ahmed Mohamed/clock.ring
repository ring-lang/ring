/*
	Application	: Clock
	Author		: Ahmed Mohamed
	Date		: 2019/10/16
*/

t1 = clock();


for x = 1 to 1000000
next

? (clock() - t1) / clockspersecond()
