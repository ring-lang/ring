/*
**	Application : list reference-version1
**	Author 	  : Sara Abozeina
**	Date		  :2017.12.18	
*/


numbers=[["one",1],["Two",2],["Three",3]]
?numbers
?"*********************"
?numbers["one"]
?"*********************"
?numbers[3][2]
?numbers[3][1]
?"*********************"
?numbers[1]
?numbers[2]
?"==========================="

store_books=	[
			["shelf1" ,"Android books"]	,
			["shelf2" ,"WEb books"]	         ,
			["shelf3" ,"Desktop books"]
	 		]

? store_books ["shelf1"]

? "------"
#at index 3
?find(store_books,"Desktop books",2)
