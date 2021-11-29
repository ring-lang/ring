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

aList = [:one,:two,:three]

for item in aList
	? item
	switch item
	on :one		item = 1
	on :two		item = 2
	on :three	item = 3
	other 		item = 0
	off
next
? aList
