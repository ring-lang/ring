/*
**	Application		:List Functions 2
**	Author			:Adel Mahmoud
**	Date			:2018.01.29
*/

#=========================================================
#                   
aList = [				# Have Two Columns
	["Mohamed"	,100],
	["Ahmed"	,200],
	["Osama"	,500],
	["Adel"		,900]
]

? aList

? find(aList,"Mohamed",1)		# 1 ---> search in first column
? aList[ find(aList,"Mohamed",1)][2]	# 2 ---> get second item in item 1

? find(aList,"Osama",1)			# 1 ---> search in first column
? aList[ find(aList,"Osama",1)][2]	# 2 ---> get second item in item 3 

#
#=========================================================


