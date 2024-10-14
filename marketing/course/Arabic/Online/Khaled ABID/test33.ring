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

aList = [:one, :two, :three]
for item in aList	# item by reference
	? item
	switch item
	case :one 	item=1
	case :two 	item=2
	case :three 	item=3
	else 		item=0
	end 
end
? aList

aList = [:one, :two, :three]
for item in aList {	# item by reference
	? item
	switch item {
	case :one 	item=1
	case :two 	item=2
	case :three 	item=3
	else 		item=0
	} 
}
? aList
