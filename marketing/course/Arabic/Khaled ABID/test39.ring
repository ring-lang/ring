/*
	Application	: Course of Essentials
	Author		: Khaled ABID
	Date		: 01/01/2018
*/

# Control Structures

for x=1 to 10
	for y=1 to 10
		? "x= " + x + "y= " + y
		if x=3 and y=5	# &&
			exit 2
		ok
	next 
next 
? "done"

# Condition (and or not)
# Condition (&&	 || !  )

x = 10 
y = 20

if x = 10 and y = 10
	? "1st"
ok

if x = 10 or y = 10
	? "2nd"
ok
