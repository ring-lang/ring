/*
**	Project : RingQt - Objects Library
**	File Purpose : Windows Controller Class Parent
**	Date : 2016.12.12
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

class WindowsControllerParent from ObjectsParent

	func Start		
		oView.win.Show()

	func CloseAction
		oView.Close()
		Super.Close()

class WindowsViewParent from ObjectsParent

	func Close
		win.close()
