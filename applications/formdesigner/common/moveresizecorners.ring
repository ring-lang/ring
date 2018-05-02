/*
**	Project : Form Designer 
**	File Purpose :  Move/Resize Corners
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

Class MoveResizeCorners

	func CreateMoveResizeCornersAttributes
		# Movement Event
			AddAttribute(self,:nX)
			AddAttribute(self,:nY)
			AddAttribute(self,:lPress)
			AddAttribute(self,:oFilter)
			AddAttribute(self,:lMoveEvent)
		# Resize Event
			AddAttribute(self,:lResize)
			AddAttribute(self,:nResizeMode)
		# Corners
			AddAttribute(self,:oCorners)
		# Default Values
			lPress=False
			lMoveEvent=False
			lResize=False
			nResizeMode=0
		# For Mobile Devices 
			AddAttribute(self,:nClockValue)
			AddAttribute(self,:nClocksCount)
			nClockValue = 0
			nClocksCount = clockspersecond() / 4

	func CreateCorners
		oCorners = new ObjectCorners(self)

	func CreateCornersNoInit 	
		oCorners = new ObjectCorners

	func RefreshCorners oParent
		oCorners.refresh(oParent)

	func MousePress oDesigner
		lPress = True
		lMoveEvent=False
		lResize = False
		nResizeMode = 0
		nX = oFilter.getglobalx()
		ny = oFilter.getglobaly()
		setCursor(oDesigner.oGeneral.oCursorA())
		# To be responsive to quick clicks/movement		
			MouseMove(oDesigner)
			# Draw Corners
				aObjects = oDesigner.oModel.getselectedObjects()
				for item in aObjects {
					oObject = item[2]
					oObject.oCorners.refresh(oObject)
				}
			# Set focus to be the current object (after drawing corners)
				setfocus(0)


	func MouseRelease oDesigner
		lPress = False
		lMoveEvent=False
		lResize = False
		nResizeMode = 0
		setCursor(oDesigner.oGeneral.oCursorA())
		if not oDesigner.oModel.IsManySelected() {
			DisplayProperties(oDesigner)
		}

	func MouseMove oDesigner
		if not resizeEvent(oDesigner) { return }
		MoveEvent(oDesigner)

	func ResizeEvent oDesigner
		# Resize Event
			nXPos =  oFilter.getx()
			nYPos = ofilter.gety()
			if (nResizeMode = 0 or lPress = False) and lMoveEvent=False  {
				if nXPos < 5 {
					if nYPos < 5 {	# Top + Left
						setCursor(oDesigner.oGeneral.oCursorF() )
						nResizeMode = 1
					elseif nYPos > Height() - 5	# Left + Bottom
						setCursor(oDesigner.oGeneral.oCursorB() )
						nResizeMode = 2
					else 			# Left
						setCursor(oDesigner.oGeneral.oCursorH() )
						nResizeMode = 3
					}
					lResize = True
				elseif nYPos < 5
					if nXPos > Width() - 5 {	# Top+Width
						setCursor(oDesigner.oGeneral.oCursorB() )
						nResizeMode = 4
					else					# Top
						setCursor(oDesigner.oGeneral.oCursorV() )
						nResizeMode = 5
					}
					if lPress { 	lResize = True }
				elseif nYPos > Height() - 5
					if nXPos > Width() - 5 {	# Bottom+Width
						setCursor(oDesigner.oGeneral.oCursorF() )
						nResizeMode = 6
					else					# Bottom
						setCursor(oDesigner.oGeneral.oCursorV())
						nResizeMode = 7
					}
					if lPress { 	lResize = True }
				elseif nXPos > Width() - 5		# Left+Width
					setCursor(oDesigner.oGeneral.oCursorH() )
					nResizeMode = 8
					if lPress { 	lResize = True }
				else
 					lResizeMode = 0
					lResize = False
					setCursor(oDesigner.oGeneral.oCursorA())
				}
			}

			if lResize and lPress and lMoveEvent=False {
				switch nResizeMode {
					case 1	# Top+Left
						move(x()+nXPos,y()+nYPos)
						resize(width() + (-1) * nXPos , height() + (-1) * nYPos)
					case 2	# Left + Bottom
						move(x()+ nXPos,y())
						resize(width() + (-1) *  nXPos , nYPos)
					case 3	# Left
						move(x()+nXPos,y())
						resize(width() + (-1) * nXPos , height() )
					case 4	# Top+Width
						move(x(), y() + nYPos)
						resize(   nXPos , height() + (-1) *  nYPos )
					case 5	# Top
						move(x(), y() + nYPos)
						resize(width() , height() + (-1) *  nYPos )
					case 6	# Bottom+Width
						move(x(), y())
						resize(nXPos , nYPos )
					case 7	# Bottom
						move(x(), y() )
						resize(width() , nYPos )
					case 8	# Left+Width
						move(x(), y() )
						resize(nXPos , height() )
				}
				oCorners.refresh(oDesigner.oModel.ActiveObject())
				return false
			}
			return True

	func MoveEvent oDesigner
		if MobileEventDelay() { return }
		# Move Event
		if lPress {
			lMoveEvent=True
			nX2 = oFilter.getglobalx()
			ny2 = oFilter.getglobaly()
			ndiffx = nX2 - nX
			ndiffy = nY2 - nY
			move(x()+ndiffx,y()+ndiffy)
			nX = nX2
			ny = nY2
			oCorners.refresh(oDesigner.oModel.ActiveObject())
			if isMobile() {
				show()
				oFDApp.processevents()
			}
		}

	func MousePressMany oDesigner
		MousePress(oDesigner)

	func MouseMoveMany oDesigner
		if MobileEventDelay() { return }
		if lPress {
			lMoveEvent=True
			nX2 = oFilter.getglobalx()
			ny2 = oFilter.getglobaly()
			ndiffx = nX2 - nX
			ndiffy = nY2 - nY
			nX = nX2
			ny = nY2
			# Move the objects together
			aObjects = oDesigner.oModel.getselectedObjects()
			for item in aObjects {
				oObject = item[2]
				oObject.move(oObject.x()+ndiffx,oObject.y()+ndiffy)
				oObject.oCorners.refresh(oObject)
			}
			if isMobile() {
				oFDApp.processevents()
			}
		}

	func MouseReleaseMany oDesigner
		MouseRelease(oDesigner)


	func MobileEventDelay
		if isMobile() {
			if nClockValue != 0 and clock() - nClockValue < nClocksCount {
				return True
			}
			nClockValue = clock()
		}
		return False
