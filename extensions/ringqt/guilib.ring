Load "qt.rh"
Load "ring_qt.ring"
Load "objectslib/objects.ring"
Load "objectslib/subwindows.ring"

if iswindows()
	LoadLib("ringqt.dll")
but ismacosx()
	LoadLib("libringqt.dylib")
else
	LoadLib("libringqt.so")
ok

GUILib = new GUILib

func setwinicon pWindow,cImage
	if cImage = NULL return ok		
	pWindow.setWindowIcon(new qicon(new qpixmap(cImage)))
		
func setbtnimage pBtn,cImage
	if cImage = NULL return ok		
	pBtn.setIcon(new qicon(new qpixmap(cImage)))

Class GUILib

	func objcmp o1,o2
		return ptrcmp(o1.pObject,o2.pObject)

	func findobj aList,o1,nColumn
		return find(aList,o1.pObject,nColumn)

/*
	This package 
	(1) Create new classes names (Better Names)
	(2) Index starts from 1 instead of 0 (More Natural)
*/

package System.GUI

	class window from qWidget

	class mainwindow from qMainWindow

	class label from qLabel

	class button from qPushButton

	class textbox from qLineEdit

	class editbox from qTextEdit

	class listbox from qListWidget

		func CurrentRow
			return 1+Super.CurrentRow()

		func SetCurrentRow nIndex,nOptions
			Super.SetCurrentRow(nIndex-1,nOptions)

	class checkbox from qCheckBox

	class slider from qSlider

	class progressbar from qProgressbar

	class SpinBox from qSpinBox

	class ComboBox from qComboBox

		func CurrentIndex
			return Super.CurrentIndex() + 1

		func SetCurrentIndex nIndex
			Super.SetCurrentIndex(nIndex - 1)

	class DateTimeEdit from qDateTimeEdit

	class Grid from TableWidget

	class TreeView from TreeView

	class TreeWidget from TreeWidget

	class RadioButton from qRadioButton

	class WebView from qWebView

	class Dial  from qDial

	class Frame from qFrame

	class LCDNumber from qLCDNumber

	class Timer from qTimer

	class vboxlayout from qVBoxLayout

	class hboxlayour from qHBoxLayout

	class Tab from qTabWidget

	class Statusbar from qStatusBar

	class ToolBar from qToolBar

	