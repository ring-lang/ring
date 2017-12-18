/*
**	Application : lists reference-version2
**	Author 	  : Sara Abozeina
**	Date		  :2017.12.18	
*/

store_books=	[
			:shelf1 ="Android books",
			:shelf2 ="WEb books"	         ,
			:shelf3 ="Desktop books"
	 		]

? store_books [1]
? store_books ["shelf2"]
? store_books [:shelf3]

?"--------------"

for x in store_books
	if x[1]="shelf3"
		x[:shelf3]="Mobile"
	ok
next
?store_books[3]
?store_books[3][2]
?store_books[3][1]
?"--------------"
?store_books[3][3]

del(store_books[3],2)
del(store_books[3],1)
?"--------------"
store_books+[:shelf4,"Expert Systems"]

?store_books

