/*
**	Application Name : control structure 2;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-16;		
*/

aList = [:ahmed, :mohamed, :mahmoud]
for item in aList
	? item
	switch item
	on :ahmed 	item=1
	on :mohamed	item=2
	on :mahmoud	item=3
	off
next
? aList
#========= another way
aList = [:ahmed, :mohamed, :mahmoud]
for item in aList
	? item
	switch item {
	on :ahmed 	item=1
	on :mohamed	item=2
	on :mahmoud	item=3
	}
end
? aList
