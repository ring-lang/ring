/*
**	Application Name : control structure 7;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-17;		
*/
for x = 1 to 10 
	for z = 1 to 10
		? "x = " + x + " z = " + z
		if x = 3 and z = 6 
			exit 2
		ok
	next
next
#==============
x = 5
z = 6
if x = 5 and z = 8
	? "right"
ok
#==============
if x = 5 or z = 3
	? "right"
ok
