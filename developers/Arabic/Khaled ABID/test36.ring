/*
	Application	: Course of Essentials
	Author		: Khaled ABID
	Date		: 01/01/2018
*/

# Control Structures

x = 1
while x < 10 {
	? x
	//x = x + 1
	x++
}


x = 1
while true {	# we can write 1 instead true
	? "Welcome"
	x++
	if x = 10 {
		exit
	}
}

while 5	{	# Everything is true except zero 0 is False
	? "test"
	exit
}
