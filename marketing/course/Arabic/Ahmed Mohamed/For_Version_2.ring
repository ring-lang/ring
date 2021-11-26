/*
	Application	: For Version 2
	Author		: Ahmed Mohamed
	Date		: 2019/10/15
*/

# Control Structures
# While For If

# 1 - Statement
# 2 - Statement
# 3 - Statement

aList = [:one, :two, :three]

for item in aList 
	? item
	switch item
	on :one 	item = 1
	on :two		item = 2
	on :three	item = 3
	other		item = 0
	off
next
? aList
