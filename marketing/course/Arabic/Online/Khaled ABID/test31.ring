/*
	Application	: Course of Essentials
	Author		: Khaled ABID
	Date		: 01/01/2018
*/

# Control Structures
# while for if

# 1 - statement
# 2 - statement
# 3 - statement
# ----
# ----
# ----

# Condition ------> True | False

x = 10 

if x = 5 	# we are using = instead ==
	? "Nice Number!"
	# ......
but x = 6	
	? "six"
but x = 7 
	? "seven"
else
	? "Another number!"
ok

if x = 5 
	? "Nice Number!"
	# ......
elseif x = 6	
	? "six"
elseif x = 7 
	? "seven"
else
	? "Another number!"
end

if x = 5 {
	? "Nice Number!"
	# ......
elseif x = 6	
	? "six"
elseif x = 7 
	? "seven"
else
	? "Another number!"
}

# for

for x=1 to 10
	? x
next

for x=1 to 10 step 1
	? x
next

for x=10 to 1 step -1
	? x
next
#======================

for x=1 to 10
	? x
end

for x=1 to 10 step 5
	? x
end

for x=10 to 1 step -2
	? x
end
#======================

for x=1 to 10 {
	? x
}

for x=1 to 10 step 4 {
	? x
}

for x=10 to 1 step -3 {
	? x
}
