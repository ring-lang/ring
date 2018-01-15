/*
**  Application: Object
**  Author     : Hany Hassan
**  Date       : 2018.01.14
*/
#=========================================================================================
# Condition 	----> True | False 
aList = [:one, :two,:three]

for item in aList 		# item by reference 
	? item 
	switch item 
	case :one 	item=1
	case :two	item=2
	case :three 	item=3
	else 		item=0
	end
end
? aList 



aList = [:one, :two,:three]

for item in aList 	{	# item by reference 
	? item 
	switch item {
	case :one 	item=1
	case :two	item=2
	case :three 	item=3
	else 		item=0
	}
}
? aList 
#================================================
