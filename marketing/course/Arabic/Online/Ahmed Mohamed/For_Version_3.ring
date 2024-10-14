/*
	Application	: For Version 3
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
	case :one 	item = 1
	case :two		item = 2
	case :three	item = 3
	else		item = 0
	end
end
? aList


aList = [:one, :two, :three]

for item in aList {
	? item
	switch item {
	case :one 	item = 1
	case :two		item = 2
	case :three	item = 3
	else		item = 0
	}
}
? aList
