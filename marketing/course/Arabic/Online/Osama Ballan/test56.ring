/*
**	Application		: Clock .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 08 .
*/


t1 = clock()
for i = 1 to 100000
next
? (clock() - t1)/clockspersecond()

