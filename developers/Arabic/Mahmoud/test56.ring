/*
	Application 	: Clock  
	Author		: Mahmoud Fayed
	Date		: 2017.12.15
*/

t1 = clock()	

for x = 1 to 1000000
next 

? (clock() - t1)/ clockspersecond()
