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
	on :one 	item=1
	on :two 	item=2
	on :three 	item=3
	other 		item=0
	off 
next
? aList
