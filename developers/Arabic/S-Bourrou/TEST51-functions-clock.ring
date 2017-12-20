# بسم الله الرحمن الرحيم
// this is Lesson7 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  functions:Clock()
  Author     :  S.BOURROU
  Date       :  17.12.2017  
*/

T1 = clock()
	for x = 1 to 1000000
	next
? (clock() -T1)/ clockspersecond()
