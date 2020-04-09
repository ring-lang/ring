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


aList = [:one,:two,:three]

for item in aList        # item by reference 
	? item
	switch item 
	case :one   item = 1
	case :two   item = 2
	case :three item = 3
	else
	end 
end 
? aList


aList = [:one,:two,:three]

for item in aList {       # item by reference 
	? item
	switch item {
	case :one   item = 1
	case :two   item = 2
	case :three item = 3
	else
	} 
} 
? aList
