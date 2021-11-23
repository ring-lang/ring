/*
	Application	: Exit From More Loop Once Time
	Author		: Ahmed Mohamed
	Date		: 2019/10/15
*/

# Control Structures

for x = 1 to 10
	for y = 1 to 10
		? "X = " + x + " Y = " + y
		if x = 3 and y = 5 # &&
			exit 2
		ok
	next
next

? "Done"

# Condition (And Or Not)
# Condition (&& || !)

x = 10
y = 20

if x = 10 and y = 10
	? "First"
ok

if x = 10 or y = 10
	? "Second"
ok
