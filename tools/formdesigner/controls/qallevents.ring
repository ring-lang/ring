/*
**	Project : Form Designer 
**	File Purpose :  QAllEvents
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QAllEvents from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cControlName = "win"

	cKeyPressEvent = ""
	cMouseButtonPressEvent = ""
	cMouseButtonReleaseEvent = ""
	cMouseButtonDblClickEvent = ""
	cMouseMoveEvent = ""
	cCloseEvent = ""
	cContextMenuEvent = ""
	cDragEnterEvent = ""
	cDragLeaveEvent = ""
	cDragMoveEvent = ""
	cDropEvent = ""
	cEnterEvent = ""
	cFocusInEvent = ""
	cFocusOutEvent = ""
	cKeyReleaseEvent = ""
	cLeaveEvent = ""
	cNonClientAreaMouseButtonDblClickEvent = ""
	cNonClientAreaMouseButtonPressEvent = ""
	cNonClientAreaMouseButtonReleaseEvent = ""
	cNonClientAreaMouseMoveEvent = ""
	cMoveEvent = ""
	cResizeEvent = ""
	cWindowActivateEvent = ""
	cWindowBlockedEvent = ""
	cWindowDeactivateEvent = ""
	cWindowStateChangeEvent = ""
	cWindowUnblockedEvent = ""
	cPaintEvent = ""

	func ControlNameValue
		return cControlName

	func SetControlNameValue  cValue
		cControlName = cValue

	func SetKeyPressEventCode cValue
		cKeyPressEvent = cValue

	func KeyPressEventCode
		return cKeyPressEvent

	func SetMouseButtonPressEventCode cValue
		cMouseButtonPressEvent = cValue

	func MouseButtonPressEventCode
		return cMouseButtonPressEvent

	func SetMouseButtonReleaseEventCode cValue
		cMouseButtonReleaseEvent = cValue

	func MouseButtonReleaseEventCode
		return cMouseButtonReleaseEvent

	func SetMouseButtonDblClickEventCode cValue
		cMouseButtonDblClickEvent = cValue

	func MouseButtonDblClickEventCode
		return cMouseButtonDblClickEvent

	func SetMouseMoveEventCode cValue
		cMouseMoveEvent = cValue

	func MouseMoveEventCode
		return cMouseMoveEvent

	func SetCloseEventCode cValue
		cCloseEvent = cValue

	func CloseEventCode
		return cCloseEvent

	func SetContextMenuEventCode cValue
		cContextMenuEvent = cValue

	func ContextMenuEventCode
		return cContextMenuEvent

	func SetDragEnterEventCode cValue
		cDragEnterEvent = cValue

	func DragEnterEventCode
		return cDragEnterEvent

	func SetDragLeaveEventCode cValue
		cDragLeaveEvent = cValue

	func DragLeaveEventCode
		return cDragLeaveEvent

	func SetDragMoveEventCode cValue
		cDragMoveEvent = cValue

	func DragMoveEventCode
		return cDragMoveEvent

	func SetDropEventCode cValue
		cDropEvent = cValue

	func DropEventCode
		return cDropEvent

	func SetEnterEventCode cValue
		cEnterEvent = cValue

	func EnterEventCode
		return cEnterEvent

	func SetFocusInEventCode cValue
		cFocusInEvent = cValue

	func FocusInEventCode
		return cFocusInEvent

	func SetFocusOutEventCode cValue
		cFocusOutEvent = cValue

	func FocusOutEventCode
		return cFocusOutEvent

	func SetKeyReleaseEventCode cValue
		cKeyReleaseEvent = cValue

	func KeyReleaseEventCode
		return cKeyReleaseEvent

	func SetLeaveEventCode cValue
		cLeaveEvent = cValue

	func LeaveEventCode
		return cLeaveEvent

	func SetNonClientAreaMouseButtonDblClickEventCode cValue
		cNonClientAreaMouseButtonDblClickEvent = cValue

	func NonClientAreaMouseButtonDblClickEventCode
		return cNonClientAreaMouseButtonDblClickEvent

	func SetNonClientAreaMouseButtonPressEventCode cValue
		cNonClientAreaMouseButtonPressEvent = cValue

	func NonClientAreaMouseButtonPressEventCode
		return cNonClientAreaMouseButtonPressEvent

	func SetNonClientAreaMouseButtonReleaseEventCode cValue
		cNonClientAreaMouseButtonReleaseEvent = cValue

	func NonClientAreaMouseButtonReleaseEventCode
		return cNonClientAreaMouseButtonReleaseEvent

	func SetNonClientAreaMouseMoveEventCode cValue
		cNonClientAreaMouseMoveEvent = cValue

	func NonClientAreaMouseMoveEventCode
		return cNonClientAreaMouseMoveEvent

	func SetMoveEventCode cValue
		cMoveEvent = cValue

	func MoveEventCode
		return cMoveEvent

	func SetResizeEventCode cValue
		cResizeEvent = cValue

	func ResizeEventCode
		return cResizeEvent

	func SetWindowActivateEventCode cValue
		cWindowActivateEvent = cValue

	func WindowActivateEventCode
		return cWindowActivateEvent

	func SetWindowBlockedEventCode cValue
		cWindowBlockedEvent = cValue

	func WindowBlockedEventCode
		return cWindowBlockedEvent

	func SetWindowDeactivateEventCode cValue
		cWindowDeactivateEvent = cValue

	func WindowDeactivateEventCode
		return cWindowDeactivateEvent

	func SetWindowStateChangeEventCode cValue
		cWindowStateChangeEvent = cValue

	func WindowStateChangeEventCode
		return cWindowStateChangeEvent

	func SetWindowUnblockedEventCode cValue
		cWindowUnblockedEvent = cValue

	func WindowUnblockedEventCode
		return cWindowUnblockedEvent

	func SetPaintEventCode cValue
		cPaintEvent = cValue

	func PaintEventCode
		return cPaintEvent

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CONTROLNAME,False)			 # "Control Name"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_KEYPRESSEVENT,False)		 # "KeyPressEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_MOUSEBUTTONPRESSEVENT,False)	 # "MouseButtonPressEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_MOUSEBUTTONRELEASEEVENT,False)	 # "MouseButtonReleaseEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_MOUSEBUTTONDBLCLICKEVENT,False)	 # "MouseButtonDblClickEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_MOUSEMOVEEVENT,False)		 # "MouseMoveEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CLOSEEVENT,False)			 # "CloseEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CONTEXTMENUEVENT,False)		 # "ContextMenuEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_DRAGENTEREVENT,False)		 # "DragEnterEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_DRAGLEAVEEVENT,False)		 # "DragLeaveEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_DRAGMOVEEVENT,False)		 # "DragMoveEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_DROPEVENT,False)			 # "DropEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ENTEREVENT,False)			 # "EnterEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_FOCUSINEVENT,False)		 # "FocusInEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_FOCUSOUTEVENT,False)		 # "FocusOutEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_KEYRELEASEEVENT,False)		 # "KeyReleaseEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_LEAVEEVENT,False)			 # "LeaveEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_NONCLIENTAREAMOUSEBUTTONDBLCLICKEVENT,False)		 # "NonClientAreaMouseButtonDblClickEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_NONCLIENTAREAMOUSEBUTTONPRESSEVENT,False)			 # "NonClientAreaMouseButtonPressEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_NONCLIENTAREAMOUSEBUTTONRELEASEEVENT,False)		 # "NonClientAreaMouseButtonReleaseEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_NONCLIENTAREAMOUSEMOVEEVENT,False)				 # "NonClientAreaMouseMoveEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_MOVEEVENT,False)			 # "MoveEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_RESIZEEVENT,False)			 # "ResizeEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_WINDOWACTIVATEEVENT,False)		 # "WindowActivateEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_WINDOWBLOCKEDEVENT,False)		 # "WindowBlockedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_WINDOWDEACTIVATEEVENT,False)	 # "WindowDeactivateEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_WINDOWSTATECHANGEEVENT,False)	 # "WindowStateChangeEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_WINDOWUNBLOCKEDEVENT,False)	 # "WindowUnblockedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_PAINTEVENT,False)			 # "PaintEvent"


	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		oPropertiesTable.item(C_AFTERCOMMON,1).settext(ControlNameValue())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(KeyPressEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(MouseButtonPressEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(MouseButtonReleaseEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(MouseButtonDblClickEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(MouseMoveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+6,1).settext(CloseEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+7,1).settext(ContextMenuEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+8,1).settext(DragEnterEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+9,1).settext(DragLeaveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+10,1).settext(DragMoveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+11,1).settext(DropEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+12,1).settext(EnterEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+13,1).settext(FocusInEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+14,1).settext(FocusOutEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+15,1).settext(KeyReleaseEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+16,1).settext(LeaveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+17,1).settext(NonClientAreaMouseButtonDblClickEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+18,1).settext(NonClientAreaMouseButtonPressEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+19,1).settext(NonClientAreaMouseButtonReleaseEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+20,1).settext(NonClientAreaMouseMoveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+21,1).settext(MoveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+22,1).settext(ResizeEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+23,1).settext(WindowActivateEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+24,1).settext(WindowBlockedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+25,1).settext(WindowDeactivateEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+26,1).settext(WindowStateChangeEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+27,1).settext(WindowUnblockedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+28,1).settext(PaintEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setControlNameValue(cValue)
				case C_AFTERCOMMON+1
					setKeyPressEventCode(cValue)
				case C_AFTERCOMMON+2
					setMouseButtonPressEventCode(cValue)
				case C_AFTERCOMMON+3
					setMouseButtonReleaseEventCode(cValue)
				case C_AFTERCOMMON+4
					setMouseButtonDblClickEventCode(cValue)
				case C_AFTERCOMMON+5
					setMouseMoveEventCode(cValue)
				case C_AFTERCOMMON+6
					setCloseEventCode(cValue)
				case C_AFTERCOMMON+7
					setContextMenuEventCode(cValue)
				case C_AFTERCOMMON+8
					setDragEnterEventCode(cValue)
				case C_AFTERCOMMON+9
					setDragLeaveEventCode(cValue)
				case C_AFTERCOMMON+10
					setDragMoveEventCode(cValue)
				case C_AFTERCOMMON+11
					setDropEventCode(cValue)
				case C_AFTERCOMMON+12
					setEnterEventCode(cValue)
				case C_AFTERCOMMON+13
					setFocusInEventCode(cValue)
				case C_AFTERCOMMON+14
					setFocusOutEventCode(cValue)
				case C_AFTERCOMMON+15
					setKeyReleaseEventCode(cValue)
				case C_AFTERCOMMON+16
					setLeaveEventCode(cValue)
				case C_AFTERCOMMON+17
					setNonClientAreaMouseButtonDblClickEventCode(cValue)
				case C_AFTERCOMMON+18
					setNonClientAreaMouseButtonPressEventCode(cValue)
				case C_AFTERCOMMON+19
					setNonClientAreaMouseButtonReleaseEventCode(cValue)
				case C_AFTERCOMMON+20
					setNonClientAreaMouseMoveEventCode(cValue)
				case C_AFTERCOMMON+21
					setMoveEventCode(cValue)
				case C_AFTERCOMMON+22
					setResizeEventCode(cValue)
				case C_AFTERCOMMON+23
					setWindowActivateEventCode(cValue)
				case C_AFTERCOMMON+24
					setWindowBlockedEventCode(cValue)
				case C_AFTERCOMMON+25
					setWindowDeactivateEventCode(cValue)
				case C_AFTERCOMMON+26
					setWindowStateChangeEventCode(cValue)
				case C_AFTERCOMMON+27
					setWindowUnblockedEventCode(cValue)
				case C_AFTERCOMMON+28
					setPaintEventCode(cValue)
			}
			if (nRow >= C_AFTERCOMMON+1 ) and 
			   (nRow <= C_AFTERCOMMON+28 ) {
					oDesigner.NewEventName(cValue)
			}

		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :controlname =  "' + oDesigner.PrepareStringForFormFile(ControlNameValue()) + '"'
		cOutput += "," + nl + cTabs + ' :setKeyPressEvent =  "' + oDesigner.PrepareStringForFormFile(KeyPressEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setMouseButtonPressEvent =  "' + oDesigner.PrepareStringForFormFile(MouseButtonPressEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setMouseButtonReleaseEvent =  "' + oDesigner.PrepareStringForFormFile(MouseButtonReleaseEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setMouseButtonDblClickEvent =  "' + oDesigner.PrepareStringForFormFile(MouseButtonDblClickEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setMouseMoveEvent =  "' + oDesigner.PrepareStringForFormFile(MouseMoveEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setCloseEvent =  "' + oDesigner.PrepareStringForFormFile(CloseEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setContextMenuEvent =  "' + oDesigner.PrepareStringForFormFile(ContextMenuEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setDragEnterEvent =  "' + oDesigner.PrepareStringForFormFile(DragEnterEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setDragLeaveEvent =  "' + oDesigner.PrepareStringForFormFile(DragLeaveEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setDragMoveEvent =  "' + oDesigner.PrepareStringForFormFile(DragMoveEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setDropEvent =  "' + oDesigner.PrepareStringForFormFile(DropEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setEnterEvent =  "' + oDesigner.PrepareStringForFormFile(EnterEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setFocusInEvent =  "' + oDesigner.PrepareStringForFormFile(FocusInEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setFocusOutEvent =  "' + oDesigner.PrepareStringForFormFile(FocusOutEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setKeyReleaseEvent =  "' + oDesigner.PrepareStringForFormFile(KeyReleaseEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setLeaveEvent =  "' + oDesigner.PrepareStringForFormFile(LeaveEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setNonClientAreaMouseButtonDblClickEvent =  "' + oDesigner.PrepareStringForFormFile(NonClientAreaMouseButtonDblClickEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setNonClientAreaMouseButtonPressEvent =  "' + oDesigner.PrepareStringForFormFile(NonClientAreaMouseButtonPressEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setNonClientAreaMouseButtonReleaseEvent =  "' + oDesigner.PrepareStringForFormFile(NonClientAreaMouseButtonReleaseEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setNonClientAreaMouseMoveEvent =  "' + oDesigner.PrepareStringForFormFile(NonClientAreaMouseMoveEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setMoveEvent =  "' + oDesigner.PrepareStringForFormFile(MoveEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setResizeEvent =  "' + oDesigner.PrepareStringForFormFile(ResizeEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setWindowActivateEvent =  "' + oDesigner.PrepareStringForFormFile(WindowActivateEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setWindowBlockedEvent =  "' + oDesigner.PrepareStringForFormFile(WindowBlockedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setWindowDeactivateEvent =  "' + oDesigner.PrepareStringForFormFile(WindowDeactivateEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setWindowStateChangeEvent =  "' + oDesigner.PrepareStringForFormFile(WindowStateChangeEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setWindowUnblockedEvent =  "' + oDesigner.PrepareStringForFormFile(WindowUnblockedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setPaintEvent =  "' + oDesigner.PrepareStringForFormFile(PaintEventCode()) + '"'
		return cOutput

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) +
		"#{f4} = " +
		'new #{f1}(win) {
#{f2}
		}
		#{f3}.installEventFilter(#{f4})' + nl

		cClass = substr(classname(self),"formdesigner_","")
		cOutput = substr(cOutput,"#{f1}",cClass)
		cOutput = substr(cOutput,"#{f2}",AddTabs(GenerateCustomCode(oDesigner),3))
		cOutput = substr(cOutput,"#{f3}",ControlNameValue())
		cOutput = substr(cOutput,"#{f4}",oDesigner.oModel.GetObjectName(self))
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setKeyPressEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,KeyPressEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",KeyPressEventCode())
		cOutput += 'setMouseButtonPressEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MouseButtonPressEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MouseButtonPressEventCode())
		cOutput += 'setMouseButtonReleaseEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MouseButtonReleaseEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MouseButtonReleaseEventCode())
		cOutput += 'setMouseButtonDblClickEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MouseButtonDblClickEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MouseButtonDblClickEventCode())
		cOutput += 'setMouseMoveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MouseMoveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MouseMoveEventCode())
		cOutput += 'setCloseEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,CloseEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",CloseEventCode())
		cOutput += 'setContextMenuEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,ContextMenuEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",ContextMenuEventCode())
		cOutput += 'setDragEnterEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,KeyPressEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",DragEnterEventCode())
		cOutput += 'setDragLeaveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,DragLeaveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",DragLeaveEventCode())
		cOutput += 'setDragMoveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,DragMoveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",DragMoveEventCode())
		cOutput += 'setDropEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,DropEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",DropEventCode())
		cOutput += 'setEnterEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,EnterEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",EnterEventCode())
		cOutput += 'setFocusInEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,FocusInEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",FocusInEventCode())
		cOutput += 'setFocusOutEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,FocusOutEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",FocusOutEventCode())
		cOutput += 'setKeyReleaseEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,KeyReleaseEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",KeyReleaseEventCode())
		cOutput += 'setLeaveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,LeaveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",LeaveEventCode())
		cOutput += 'setNonClientAreaMouseButtonDblClickEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,NonClientAreaMouseButtonDblClickEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",NonClientAreaMouseButtonDblClickEventCode())
		cOutput += 'setNonClientAreaMouseButtonPressEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,NonClientAreaMouseButtonPressEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",NonClientAreaMouseButtonPressEventCode())
		cOutput += 'setNonClientAreaMouseButtonReleaseEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,NonClientAreaMouseButtonReleaseEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",NonClientAreaMouseButtonReleaseEventCode())
		cOutput += 'setNonClientAreaMouseMoveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,NonClientAreaMouseMoveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",NonClientAreaMouseMoveEventCode())
		cOutput += 'setMoveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MoveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MoveEventCode())
		cOutput += 'setResizeEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,ResizeEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",ResizeEventCode())
		cOutput += 'setWindowActivateEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowActivateEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowActivateEventCode())
		cOutput += 'setWindowBlockedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowBlockedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowBlockedEventCode())
		cOutput += 'setWindowDeactivateEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowDeactivateEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowDeactivateEventCode())
		cOutput += 'setWindowStateChangeEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowStateChangeEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowStateChangeEventCode())
		cOutput += 'setWindowUnblockedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowUnblockedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowUnblockedEventCode())
		cOutput += 'setPaintEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,PaintEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",PaintEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		SetControlNameValue(itemdata[:ControlName])
		SetKeyPressEventCode(itemdata[:setKeyPressEvent])
		SetMouseButtonPressEventCode(itemdata[:setMouseButtonPressEvent])
		SetMouseButtonReleaseEventCode(itemdata[:setMouseButtonReleaseEvent])
		SetMouseButtonDblClickEventCode(itemdata[:setMouseButtonDblClickEvent])
		SetMouseMoveEventCode(itemdata[:setMouseMoveEvent])
		SetCloseEventCode(itemdata[:setCloseEvent])
		SetContextMenuEventCode(itemdata[:setContextMenuEvent])
		SetDragEnterEventCode(itemdata[:setDragEnterEvent])
		SetDragLeaveEventCode(itemdata[:setDragLeaveEvent])
		SetDragMoveEventCode(itemdata[:setDragMoveEvent])
		SetDropEventCode(itemdata[:setDropEvent])
		SetEnterEventCode(itemdata[:setEnterEvent])
		SetFocusInEventCode(itemdata[:setFocusInEvent])
		SetFocusOutEventCode(itemdata[:setFocusOutEvent])
		SetKeyReleaseEventCode(itemdata[:setKeyReleaseEvent])
		SetLeaveEventCode(itemdata[:setLeaveEvent])
		SetNonClientAreaMouseButtonDblClickEventCode(itemdata[:setNonClientAreaMouseButtonDblClickEvent])
		SetNonClientAreaMouseButtonPressEventCode(itemdata[:setNonClientAreaMouseButtonPressEvent])
		SetNonClientAreaMouseButtonReleaseEventCode(itemdata[:setNonClientAreaMouseButtonReleaseEvent])
		SetNonClientAreaMouseMoveEventCode(itemdata[:setNonClientAreaMouseMoveEvent])
		SetMoveEventCode(itemdata[:setMoveEvent])
		SetResizeEventCode(itemdata[:setResizeEvent])
		SetWindowActivateEventCode(itemdata[:setWindowActivateEvent])
		SetWindowBlockedEventCode(itemdata[:setWindowBlockedEvent])
		SetWindowDeactivateEventCode(itemdata[:setWindowDeactivateEvent])
		SetWindowStateChangeEventCode(itemdata[:setWindowStateChangeEvent])
		SetWindowUnblockedEventCode(itemdata[:setWindowUnblockedEvent])
		SetPaintEventCode(itemdata[:setPaintEvent])
