/*
**	Application Name : List function;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-11;		
*/
aList = 1:10
? aList 
del(aList, 6)
? aList
aList + "mansours"
aList + "alex"
aList + "cairo"
? find(aList, "cairo")

aList2 = [
	["ahmed", 	900],
	["mohamed", 	100],
	["yasser",	600]
]
? alist2[find(aList2, "ahmed", 1)][2]
? alist2[find(aList2, "yasser", 1)][2]

