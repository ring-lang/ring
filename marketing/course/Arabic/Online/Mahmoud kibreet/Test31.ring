/*
          Application : Object
          Author      : Mahmoud Kibreet
          Date        : 2018.01.26
*/

# Control Structures
# While for if 

# 1- statement
# 2- statement
# 3- statement
# ....
# ....
# ....

# Condition ----> True | False

x=10
if x=5  # we are using = instead ==
	? "Nice number!"
	# ....
but x=6
	? "Six"
but x=7
	? "Seven"
else 
	? "Another number!"
ok 


if x=5
	? "Nice number!"
	# ....
elseif x=6
	? "Six"
elseif x=7
	? "Seven"
else 
	? "Another number!"
end 



if x=5 {
	? "Nice number!"
	# ....
elseif x=6
	? "Six"
elseif x=7
	? "Seven"
else 
	? "Another number!"
}


# for 

for x=1 to 10
	? x 
next

for x=1 to 10 step 2
	? x 
next

for x=10 to 1 step -1
	? x 
next

#==========================

for x=1 to 10
	? x 
end

for x=1 to 10 step 2
	? x 
end

for x=10 to 1 step -1
	? x 
end

#==========================

for x=1 to 10 {
	? x 
}

for x=1 to 10 step 2 {
	? x 
}

for x=10 to 1 step -1 {
	? x 
}

#=======================
