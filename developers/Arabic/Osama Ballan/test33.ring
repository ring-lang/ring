/*
**	Application		: Control Structure  .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 06 .
*/

# Control Structures
# while	for	if .

# 1 - Statement
# 2 - Statement
# 3 - Statement
# ...
# ...
# ...
# Condition ----> True | False
# FOR Statement

alist = [:one, :two, :three]
for item in alist				# item by Reference
	? item
	switch item
	on :one	item = 1
	on :two	item = 2
	on :three	item = 3
	other	item = 0
	off
next
? alist
# ---------
alist = [:one, :two, :three]
for item in alist				# item by Reference
	? item
	switch item
	case :one	item = 1
	case :two	item = 2
	case :three	item = 3
	else	item = 0
	end
next
? alist
# ---------
alist = [:one, :two, :three]
for item in alist				# item by Reference
	? item
	switch item {
	case :one	item = 1
	case :two	item = 2
	case :three	item = 3
	else	item = 0
	}
next
? alist





