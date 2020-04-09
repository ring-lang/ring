/*
**	Application	: lists-version(2)-add to list
**	Author		: Sara Abozeina
**	Date			: 2017.12.16	
*/
alist=[1,2,3,4,[True,False],['one','two']]
?alist

? alist[1] = alist[5][1]

alist2=[alist[1],alist[6][1]]
?"====="
?alist2
?"====="

add(alist2,10)
?alist2
?"====="

alist2+"7"
?alist2
