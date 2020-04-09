/*
**	Application Name : clock;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-18;		
*/
t1 = clock()
	for x=1 to 200000
	next
? (clock() - t1) / clockspersecond()

