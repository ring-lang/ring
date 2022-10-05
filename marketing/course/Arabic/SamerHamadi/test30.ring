/*
**	Application    : Object
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

# control structures
# while for if

# 1- statement
# 2- statement
# 3- statement
# .........
# .........

# condition    ------> true|false

x=10

if x= 5
	? "Nice Number!"
but x=6
	? "six"
but x=7
	? "seven"
else
	? "Another Number!"
ok

if x= 5
	? "Nice Number!"
elseif x=6
	? "six"
elseif x=7
	? "seven"
else
	? "Another Number!"
end

if x= 5{
	? "Nice Number!"
elseif x=6
	? "six"
elseif x=7
	? "seven"
else
	? "Another Number!"
}

#for

for x= 1 to 10
	? x
next

for x= 1 to 10 step 2
	? x
next

for x= 10 to 1 step -1
	? x
next

#======================

for x= 1 to 10
	? x
end

for x= 1 to 10 step 2
	? x
end

for x= 10 to 1 step -1
	? x
end

#======================

for x= 1 to 10{
	? x
}

for x= 1 to 10 step 2{
	? x
}

for x= 10 to 1 step -1{
	? x
}

