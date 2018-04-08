/*
**  Application: Object
**  Author     : Hany Hassan
**  Date       : 2018.01.14
*/
#=========================================================================================
# Condition 	----> True | False 

aList = [:one, :two,:three]

for item in aList 
	? item 
	switch item 
	on :one 	item=1
	on :two		item=2
	on :three 	item=3
	other 		item=0
	off
next
 ? aList
#================================================
