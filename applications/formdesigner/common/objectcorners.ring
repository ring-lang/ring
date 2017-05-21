/*
**	Project : Form Designer 
**	File Purpose :  Object Corners
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class ObjectCorners

	oCorner1 oCorner2 oCorner3 oCorner4

	lCornersCreated = False

	func init oParent

		lCornersCreated = True

		oCorner1 = new qPushButton(oParent.ParentWidget()) {
			move(oParent.x()-5,oParent.y()-5)
			resize(5,5)
			setStyleSheet("background-color:black;")
			setEnabled(False)
			setMouseTracking(False)
			show()
		}

		oCorner2 = new qPushButton(oParent.ParentWidget()) {
			move(oParent.x()-5,oParent.y()+oParent.height())
			resize(5,5)
			setStyleSheet("background-color:black;")
			setEnabled(False)
			setMouseTracking(False)
			show()
		}

		oCorner3 = new qPushButton(oParent.ParentWidget()) {
			move(oParent.x()+oParent.Width(),oParent.y()-5)
			resize(5,5)
			setStyleSheet("background-color:black;")
			setEnabled(False)
			setMouseTracking(False)
			show()
		}

		oCorner4 = new qPushButton(oParent.ParentWidget()) {
			move(oParent.x()+oParent.width(),oParent.y()+oParent.height())
			resize(5,5)
			setStyleSheet("background-color:black;")
			setEnabled(False)
			setMouseTracking(False)
			show()
		}

	func CheckInit oParent
		if lCornersCreated = False {
			init(oParent)
		}

	func refresh  oParent

		CheckInit(oParent)

		oCorner1  {
			move(oParent.x()-5,oParent.y()-5)
			resize(5,5)
		}

		oCorner2  {
			move(oParent.x()-5,oParent.y()+oParent.height())
			resize(5,5)
		}

		oCorner3  {
			move(oParent.x()+oParent.Width(),oParent.y()-5)
			resize(5,5)
		}

		oCorner4 {
			move(oParent.x()+oParent.width(),oParent.y()+oParent.height())
			resize(5,5)
		}

	func show
		oCorner1.show()
		oCorner2.show()
		oCorner3.show()
		oCorner4.show()

	func hide
		oCorner1.hide()
		oCorner2.hide()
		oCorner3.hide()
		oCorner4.hide()

