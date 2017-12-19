/*
**	Application    : list functions
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

alist = 1:10
? alist

del(alist,5)
? alist

alist + "Egypt"
alist + "KSA"
alist + "France"

? "Egypt Position: " + find(alist,"Egypt")

alist = [
	["Mohamed"	,100],
	["Mahmoud"	,200],
	["Ahmed"	,300],
	["Ibrahim"	,400]
]

? alist[find(alist,"Mohamed",1)][2]
? alist[find(alist,"Ahmed",1)][2]
