/*
**	Application	: Control Structure  .
**	Author		: Osama Ballan .
**	Date		: 2018 - 01 - 06 .
*/

# Control Structures
# For (Exit Nested Loops)

for x = 1 to 10
	for y = 1 to 10
		? "x = " + x + "   y = " + y
		if x = 3 and y = 5
			exit 2
		ok
	next
next
? "Done"

# Condition	( and		or		not)
# Condition	( &&		||		  ! )
x = 10
y = 20

if x = 10 and y = 10
	? "First"
ok
if x = 10 or y = 20
	? "Second"
ok
