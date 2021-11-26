/*
**	Application Name : Scope;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-31;		
*/
# problem: conflict between global and local variables
# solution 2: use special character at the beginning of variable

x = 10 y = 40
$nSum = x + y
? sum(1,2)
? $nSum


func sum x,y
	nSum = x + y
	return nSum
