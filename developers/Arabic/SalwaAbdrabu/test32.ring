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
	on "One"	Item = 1 
	on "Two"	Item = 2  
	on "Three"	Item = 3 
	other
	off

next

? aList
