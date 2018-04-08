# بسم الله الرحمن الرحيم
// this is Lesson6 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  Functions  : Pass by Value, Pass by Reference
  Author     :  S.BOURROU
  Date       :  17.12.2017  
*/
#
func main
 	aList = 1:10
 	aList2 = aList # copy by value
	
	
	aList2[1] = :one

	?aList[1]
	?aList2[1]
