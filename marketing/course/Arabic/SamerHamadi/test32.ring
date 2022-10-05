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
	case :one		item = 1
	case :two		item = 2
	case :three	item = 3
	else 		item = 0
	end
end
? aList

aList = [:one,:two,:three]

for item in aList{
	? item
	switch item{
	case :one		item = 1
	case :two		item = 2
	case :three	item = 3
	else 		item = 0
	}
}
? aList
