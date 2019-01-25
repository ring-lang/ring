/*
	Application : Object
	Author      : Salwa Abdrabu
*/

# Control Structure
# While For If
# 1- Statement
# 2- Statement
# 3- Statement
# ----
# ----
# ----

aList = [:One ,:Two ,:Three]
for Item in aList		# Item By Reference
	? Item 
	switch Item 
	case "One"	Item = 1 
	case "Two"	Item = 2  
	case "Three"	Item = 3 
	else
	off

end

? aList
#======================================

for Item in aList {		# Item By Reference
	? Item 
	switch Item { 
	case "One"	Item = 1 
	case "Two"	Item = 2  
	case "Three"	Item = 3 
	else
	}

}

? aList
