/*
**	Project : RingQt - Objects Library
**	File Purpose : Windows Controller Class Parent
**	Date : 2016.12.12
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load the General Objects Library 
	load "objectslib.ring"

class WindowsControllerParent from ObjectsParent

	func Start		
		oView.win.Show()

	func CloseAction
		oView.Close()
		Super.Close()
