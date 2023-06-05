# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# FindPrevValue() Added by Gal Zsolt 

class RNoteFind

	func OpenFindWindow

		if isobject(oSearch)
			oSearch.activatewindow()
			return
		ok

		oSearch = new qWidget()
		{
			oLblFindWhat = new qLabel(this.oSearch)
			{
				setText(T_RINGNOTEPAD_FINDWINDOWFINDWHAT) # "Find What : "
			}
			this.oSearchValue = new qlineedit(this.oSearch)
			{
				setText(this.cSearchText)
				setReturnPressedEvent(Method(:FindValue))
			}
			oLayout1 = new qHBoxLayout()
			{
				addWidget(oLblFindWhat)
				addWidget(this.oSearchValue)
			}
			oLblReplaceWith = new qLabel(this.oSearch)
			{
				setText(T_RINGNOTEPAD_FINDWINDOWREPLACEWITH) # "Replace with "
			}
			this.oReplaceValue = new qlineedit(this.oSearch)
			{
				setText(this.cReplaceText)
			}

			oLayout2 = new qHBoxLayout()
			{
				addWidget(oLblReplaceWith)
				addWidget(this.oReplaceValue)
			}
			this.oSearchCase = new qCheckbox(this.oSearch)
			{
				setText(T_RINGNOTEPAD_FINDWINDOWCASESENSITIVE) # "Case Sensitive"
			}
			oLayout3 = new qHBoxLayout()
			{
				addWidget(this.oSearchCase)
			}
			oBtnFind = new qPushButton(this.oSearch)
			{
				setText(T_RINGNOTEPAD_FINDWINDOWFINDFINDNEXT) # "Find/Find Next"
				setclickEvent(Method(:FindValue))
			}
			oBtnFindPrev = new qPushButton(this.oSearch)
			{
				setText(T_RINGNOTEPAD_FINDWINDOWFINDFINDPREV) # "Find/Find Prev"
				setclickEvent(Method(:FindPrevValue))
			}
			oBtnReplace = new qPushButton(this.oSearch)
			{
				setText(T_RINGNOTEPAD_FINDWINDOWREPLACE) # "Replace"
				setclickEvent(Method(:Replace))
			}
			oBtnReplaceAll = new qPushButton(this.oSearch)
			{
				setText(T_RINGNOTEPAD_FINDWINDOWREPLACEALL) # "Replace All"
				setclickEvent(Method(:ReplaceAll))
			}
			oBtnClose = new qPushButton(this.oSearch)
			{
				setText(T_RINGNOTEPAD_FINDWINDOWCLOSE) # "Close"
				setclickEvent(Method(:SearchClose))
			}
			oLayout4 = new qHBoxLayout()
			{
				addWidget(oBtnFind)
				addWidget(oBtnFindPrev)
				addWidget(oBtnReplace)
				addWidget(oBtnReplaceAll)
				addWidget(oBtnClose)
			}
			oLayout5 = new qVBoxLayout()
			{
				AddLayout(oLayout1)
				AddLayout(oLayout2)
				AddLayout(oLayout3)
				AddLayout(oLayout4)
			}
			setLayout(oLayout5)
			setwinicon(this.oSearch,"image/notepad.png")
			setWindowTitle(T_RINGNOTEPAD_FINDWINDOWFINDREPLACE) # "Find/Replace"
			setFixedsize(550,160)
			setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint) 
			this.oSearchFilter = new qallevents(this.oSearch)
			this.oSearchFilter.setKeyPressEvent(Method(:SearchKeyPress))
			installeventfilter(this.oSearchFilter)
			setlayoutdirection(T_RINGNOTEPAD_LAYOUTDIRECTION)
			show()
		}

	func FindValue

		# Check the content and the search value
			cStr = textedit1.toplaintext()
			cValue = oSearchValue.text()
			if len(cStr) < 1 or len(cValue) < 1 return ok

		# Get the cursor position 
			nPosStart = CursorPosition()

		# Find the sub string 
			oContent = ToQString(cStr)
			nPos = oContent.indexof(cValue,nPosStart,IsNotCaseSensitive())		

		return SelectSearchResult(cValue,nPos)

	func FindPrevValue

		# Check the content and the search value
			cStr = textedit1.toplaintext()
			cValue = oSearchValue.text()
			if len(cStr) < 1 or len(cValue) < 1 return ok

		# Get the cursor position 
			oCursor = textedit1.textcursor()
			nPosStart = oCursor.Position()
			if oCursor.HasSelection()
				nPosStart = oCursor.SelectionStart()
			ok
			nPosStart--
			nPosStart = max(nPosStart,0)

		# Find the sub string 
			oContent = ToQString(cStr)
			nPos = oContent.lastindexof(cValue,nPosStart,IsNotCaseSensitive())		

		return SelectSearchResult(cValue,nPos)

	func IsNotCaseSensitive
			return ! (oSearchCase.checkState() = Qt_Unchecked)

	func SelectSearchResult cValue,nPos

		# Get the substring size 
			nSize = UTF8Size(cValue)

		# If we have the substring then select it 		
			if nPos >= 0
				SelectFromTo(nPos,nPos+nSize)
				return true
			ok

		return nooutput(cValue)

	func Replace

		oCursor = textedit1.textCursor()

		if oCursor.HasSelection() = false
			SearchMessage(T_RINGNOTEPAD_FINDWINDOWREPLACE,
							T_RINGNOTEPAD_FINDWINDOWNOSELECTION)
			return false
		ok

		cValue = oSearchValue.text()
		if len(cValue) < 1 return ok
		cSelected = oCursor.SelectedText()
		if oSearchCase.checkState() = Qt_Unchecked
			cValue = lower(cValue)
			cSelected = lower(cSelected)
		ok
		if cSelected != cValue
			SearchMessage(T_RINGNOTEPAD_FINDWINDOWREPLACE,
							T_RINGNOTEPAD_FINDWINDOWNOMATCH)
			return false
		ok

		cValue = oReplaceValue.text()
		nStart = oCursor.SelectionStart()
		nEnd = oCursor.SelectionEnd()
		cStr = textedit1.toPlainText()

		oString = ToQString(cStr)

		cStr = oString.mid(0,nStart) + cValue + oString.mid(nEnd,-1)

		setTextAllowUndo(cStr)
		oCursor.setposition(nEnd+1,1)
		textedit1.settextcursor(oCursor)
		return FindValue()

	func ReplaceAll

		cStr = textedit1.toPlainText()
		cOldValue = oSearchValue.text()
		cNewValue = oReplaceValue.text()
		cnt = count(cStr,cOldValue)
		if len(cStr) < 1 or len(cOldValue) < 1 return ok

		if oSearchCase.checkState() = Qt_Unchecked
			# Not Case Sensitive
			cStr = SubStr(cStr,cOldValue,cNewValue,true)
		else
			# Case Sensitive
			cStr = SubStr(cStr,cOldValue,cNewValue)
		ok

		if cStr != textedit1.toPlainText()
			setTextAllowUndo(cStr)
			cMsg = T_RINGNOTEPAD_FINDWINDOWOPERATIONDONE # "Operation Done"
			cMsg = cMsg + T_RINGNOTEPAD_FINDWINDOWREPLACED + cnt
		else 
			cMsg = T_RINGNOTEPAD_FINDWINDOWNOTHINGTOREPLACE # "Nothing to replace!"
		ok

		SearchMessage(T_RINGNOTEPAD_FINDWINDOWREPLACEALL,cMsg)

	func setTextAllowUndo cText 

		# Get the Text Size 
			nTextSize = UTF8Size(textedit1.toplaintext())

		# Select All of the Text 
			# Save the current position 
				nPosStart = CursorPosition()

			SetCursorPosition(0,0)
			SetCursorPosition(nTextSize,1)

		# Set the new text using InsertPlainText() that support the Undo process 
			textedit1.InsertPlainText(cText)

		# Restore the Cursor Position
			SetCursorPosition(nPosStart,0)

	func ToQString cStr 
			oString = new QString2()
			oString.append(cStr)
			return oString

	func UTF8Size cStr 
			oString = ToQString(cStr)
			return oString.count()

	func SelectFromTo nFrom,nTo
			SetCursorPosition(nFrom,0)
			SetCursorPosition(nTo,1)

	func CursorPosition 
			oCursor = textedit1.textcursor()
			return oCursor.Position()

	func SetCursorPosition nIndex,lFlag
			oCursor = textedit1.textcursor()
			oCursor.setposition(nIndex,lFlag)
			textedit1.settextcursor(oCursor)

	func NoOutput cValue
		SearchMessage(T_RINGNOTEPAD_FINDWINDOWSEARCH,
						T_RINGNOTEPAD_FINDWINDOWCANNOTFIND + cValue)
		return false

	func SearchMessage cTitle,cContent
		new qMessagebox(oSearch)
		{
			SetWindowTitle(cTitle)
			SetText(cContent)
			show()
		}

	func Count cString,dString
		sum = 0
		while substr(cString,dString) > 0
			sum++
			cString = substr(cString,substr(cString,dString)+len(dString))
		end
		return sum

	func SearchKeyPress
		if oSearchFilter.getKeyCode() = Qt_Key_Escape
			SearchClose()
		ok

	func SearchClose
		oSearch.close()
		oSearch = NULL
		cSearchText = oSearchValue.text()
		cReplaceText = oReplaceValue.text()
