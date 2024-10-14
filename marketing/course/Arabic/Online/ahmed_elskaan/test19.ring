/*
**	Application Name : variables (List part 3);
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-11;		
*/
aList = [
	:name    = "ahmed",
	:age     = 28,
	:country = "Egypt"
]
? "Length : " + len(aList)
for aItem in aList 
	? aItem[2]

next
