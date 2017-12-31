/*
**	Application:object oriented
**	Author	   :Sara Abozeina
**	Date       :2017.12.31
*/

load "stdlib.ring"

new counter{
	x=1 y=10
	showMessage()

}


class counter
	x y
	func showMessage
		?"Hello in Ring"
		Sleep(1)
		?"again!,Hello in Ring"
		while x<=y ?x Sleep(1) x++ end
			

