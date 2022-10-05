/*
	Application	: Control Structures
	Author		: Ahmed Mohamed
	Date		: 2019/10/15
*/

# Control Structures
# While For If

# 1 - Statement
# 2 - Statement
# 3 - Statement



x = 10

if x = 5
	? "Nice Number !"
but x = 6
	? "Six"
but x = 7
	? "Seven"
else
	? "Another Number"
ok




if x = 5
	? "Nice Number !"
elseif x = 6
	? "Six"
elseif x = 7
	? "Seven"
else
	? "Another Number"
end



if x = 5 {
	? "Nice Number !"
elseif x = 6
	? "Six"
elseif x = 7
	? "Seven"
else
	? "Another Number"
}


if (x = 5) {
	? "Nice Number !"
elseif (x = 6)
	? "Six"
elseif (x = 7)
	? "Seven"
else
	? "Another Number"
}


# For

for x = 1 to 10
	? x
next

for x = 1 to 10 step 2
	? x
next

for x = 10 to 1 step -1
	? x
next

#================================================

for x = 1 to 10
	? x
end

for x = 1 to 10 step 2
	? x
end

for x = 10 to 1 step -1
	? x
end

#================================================

for x = 1 to 10 {
	? x
}

for x = 1 to 10 step 2 {
	? x
}

for x = 10 to 1 step -1 {
	? x
}
