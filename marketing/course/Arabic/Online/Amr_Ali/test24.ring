/*
**	Application	: List Functions
**	Author    	: Amr Ali
**	Date   		: 08/03/2018
*/
####################################################################
# Variables types(String, Number, List, Object, c object)

alist = 1:10
#? alist

del(alist, 5)
? alist

alist + "Cairo"
alist + "Alex"
alist + "Tanta"

#? alist
? "Position of Alex: " + find(alist, "Alex")

alist = [
		["Mohamed"	, 100],
		["Ali"		, 200],
		["Amr"		, 300]
]

? alist[find(alist, "Ali", 1)][2]
