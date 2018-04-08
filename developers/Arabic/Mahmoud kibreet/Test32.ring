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
	on :one   item = 1
	on :two   item = 2
	on :three item = 3
	other
	off 
next 
? aList
