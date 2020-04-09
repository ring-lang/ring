/*
**	Application:object oriented-timer
**	Author	   :Sara Abozeina
**	Date       :2017.12.31
*/

load "stdlib.ring"

otimer=new timer
otimer.showMessage()

class timer

	func showMessage
		?"Hello in Ring"
		Sleep(2)
		?"again!,Hello in Ring"

