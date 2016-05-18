# Generate C++ Classes for RingQt Events
# To execute : ring qtevents.ring
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

aclasses = [
		[	:name = "GPushButton" ,
			:realname = "QPushButton" ,
			:events = [
					[ 	:signal = "clicked()" ,
						:slot = "clickedSlot()" ,
						:event = "Click"
					]
				  ]
		] ,
		[	:name = "GAction" ,
			:realname = "QAction" ,
			:events = [
					[ 	:signal = "triggered()" ,
						:slot = "clickedSlot()" ,
						:event = "Click"
					]
				  ]
		] ,
		[	:name = "GLineEdit" ,
			:realname = "QLineEdit" ,
			:events = [
					[ 	:signal = "textChanged(QString)" ,
						:slot = "textChangedSlot()" ,
						:event = "TextChanged"
					] ,
					[ 	:signal = "cursorPositionChanged(int,int)" ,
						:slot = "cursorPositionChangedSlot()" ,
						:event = "cursorPositionChanged"
					] ,
					[ 	:signal = "editingFinished()" ,
						:slot = "editingFinishedSlot()" ,
						:event = "editingFinished"
					] ,
					[ 	:signal = "returnPressed()" ,
						:slot = "returnPressedSlot()" ,
						:event = "returnPressed"
					] ,
					[ 	:signal = "selectionChanged()" ,
						:slot = "selectionChangedSlot()" ,
						:event = "selectionChanged"
					] ,
					[ 	:signal = "textEdited(QString)" ,
						:slot = "textEditedSlot()" ,
						:event = "textEdited"
					]
				  ]
		] ,
		[	:name = "GTextEdit" ,
			:realname = "QTextEdit" ,
			:events = [
					[ 	:signal = "copyAvailable(bool)" ,
						:slot = "copyAvailableSlot()" ,
						:event = "copyAvailable"
					] ,
					[ 	:signal = "currentCharFormatChanged(QTextCharFormat)" ,
						:slot = "currentCharFormatChangedSlot()" ,
						:event = "currentCharFormatChanged"
					] ,
					[ 	:signal = "cursorPositionChanged()" ,
						:slot = "cursorPositionChangedSlot()" ,
						:event = "cursorPositionChanged"
					] ,
					[ 	:signal = "redoAvailable(bool)" ,
						:slot = "redoAvailableSlot()" ,
						:event = "redoAvailable"
					] ,
					[ 	:signal = "selectionChanged()" ,
						:slot = "selectionChanged()" ,
						:event = "selectionChanged"
					] ,
					[ 	:signal = "textChanged()" ,
						:slot = "textChangedSlot()" ,
						:event = "textChanged"
					] ,
					[ 	:signal = "undoAvailable(bool)" ,
						:slot = "undoAvailableSlot()" ,
						:event = "undoAvailable"
					]
				  ]
		] ,
		[	:name = "GListWidget" ,
			:realname = "QListWidget" ,
			:events = [
					[ 	:signal = "currentItemChanged(QListWidgetItem*,QListWidgetItem*)" ,
						:slot = "currentItemChangedSlot()" ,
						:event = "currentItemChanged"
					] ,
					[ 	:signal = "currentRowChanged(int)" ,
						:slot = "currentRowChangedSlot()" ,
						:event = "currentRowChanged"
					] ,
					[ 	:signal = "currentTextChanged(QString)" ,
						:slot = "currentTextChangedSlot()" ,
						:event = "currentTextChanged"
					] ,
					[ 	:signal = "itemActivated(QListWidgetItem*)" ,
						:slot = "itemActivatedSlot()" ,
						:event = "itemActivated"
					] ,
					[ 	:signal = "itemChanged(QListWidgetItem*)" ,
						:slot = "itemChangedSlot()" ,
						:event = "itemChanged"
					] ,
					[ 	:signal = "itemClicked(QListWidgetItem*)" ,
						:slot = "itemClickedSlot()" ,
						:event = "itemClicked"
					] ,
					[ 	:signal = "itemDoubleClicked(QListWidgetItem*)" ,
						:slot = "itemDoubleClickedSlot()" ,
						:event = "itemDoubleClicked"
					] ,
					[ 	:signal = "itemEntered(QListWidgetItem*)" ,
						:slot = "itemEnteredSlot()" ,
						:event = "itemEntered"
					] ,
					[ 	:signal = "itemPressed(QListWidgetItem*)" ,
						:slot = "itemPressedSlot()" ,
						:event = "itemPressed"
					] ,
					[ 	:signal = "itemSelectionChanged()" ,
						:slot = "itemSelectionChangedSlot()" ,
						:event = "itemSelectionChanged"
					]
				  ]
		] ,
		[	:name = "GTreeView" ,
			:realname = "QTreeView" ,
			:events = [
					[ 	:signal = "collapsed(QModelIndex)" ,
						:slot = "collapsedSlot()" ,
						:event = "collapsed"
					] ,
					[ 	:signal = "expanded(QModelIndex)" ,
						:slot = "expandedSlot()" ,
						:event = "expanded"
					] ,
					[ 	:signal = "activated(QModelIndex)" ,
						:slot = "activatedSlot()" ,
						:event = "activated"
					] ,
					[ 	:signal = "clicked(QModelIndex)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					] ,
					[ 	:signal = "doubleClicked(QModelIndex)" ,
						:slot = "doubleClickedSlot()" ,
						:event = "doubleClicked"
					] ,
					[ 	:signal = "entered(QModelIndex)" ,
						:slot = "enteredSlot()" ,
						:event = "entered"
					] ,
					[ 	:signal = "pressed(QModelIndex)" ,
						:slot = "pressedSlot()" ,
						:event = "pressed"
					] ,
					[ 	:signal = "viewportEntered()" ,
						:slot = "viewportEnteredSlot()" ,
						:event = "viewportEntered"
					]
				  ]
		] ,
		[	:name = "GTreeWidget" ,
			:realname = "QTreeWidget" ,
			:events = [
					[ 	:signal = "collapsed(QModelIndex)" ,
						:slot = "collapsedSlot()" ,
						:event = "collapsed"
					] ,
					[ 	:signal = "expanded(QModelIndex)" ,
						:slot = "expandedSlot()" ,
						:event = "expanded"
					] ,
					[ 	:signal = "activated(QModelIndex)" ,
						:slot = "activatedSlot()" ,
						:event = "activated"
					] ,
					[ 	:signal = "clicked(QModelIndex)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					] ,
					[ 	:signal = "doubleClicked(QModelIndex)" ,
						:slot = "doubleClickedSlot()" ,
						:event = "doubleClicked"
					] ,
					[ 	:signal = "entered(QModelIndex)" ,
						:slot = "enteredSlot()" ,
						:event = "entered"
					] ,
					[ 	:signal = "pressed(QModelIndex)" ,
						:slot = "pressedSlot()" ,
						:event = "pressed"
					] ,
					[ 	:signal = "viewportEntered()" ,
						:slot = "viewportEnteredSlot()" ,
						:event = "viewportEntered"
					] ,
					[ 	:signal = "currentItemChanged(QTreeWidgetItem *,QTreeWidgetItem *)" ,
						:slot = "currentItemChangedSlot()" ,
						:event = "currentItemChanged"
					] ,
					[ 	:signal = "itemActivated(QTreeWidgetItem *,int)" ,
						:slot = "itemActivatedSlot()" ,
						:event = "itemActivated"
					] ,
					[ 	:signal = "itemChanged(QTreeWidgetItem *,int)" ,
						:slot = "itemChangedSlot()" ,
						:event = "itemChanged"
					] ,
					[ 	:signal = "itemClicked(QTreeWidgetItem *,int)" ,
						:slot = "itemClickedSlot()" ,
						:event = "itemClicked"
					] ,
					[ 	:signal = "itemCollapsed(QTreeWidgetItem *)" ,
						:slot = "itemCollapsedSlot()" ,
						:event = "itemCollapsed"
					] ,
					[ 	:signal = "itemDoubleClicked(QTreeWidgetItem * ,int)" ,
						:slot = "itemDoubleClickedSlot()" ,
						:event = "itemDoubleClicked"
					] ,
					[ 	:signal = "itemEntered(QTreeWidgetItem * ,int)" ,
						:slot = "itemEnteredSlot()" ,
						:event = "itemEntered"
					] ,
					[ 	:signal = "itemExpanded(QTreeWidgetItem *)" ,
						:slot = "itemExpandedSlot()" ,
						:event = "itemExpanded"
					] ,
					[ 	:signal = "itemPressed(QTreeWidgetItem * ,int)" ,
						:slot = "itemPressedSlot()" ,
						:event = "itemPressed"
					] ,
					[ 	:signal = "itemSelectionChanged()" ,
						:slot = "itemSelectionChangedSlot()" ,
						:event = "itemSelectionChanged"
					]
				  ]
		] ,
		[	:name = "GComboBox" ,
			:realname = "QComboBox" ,
			:events = [
					[ 	:signal = "activated(int)" ,
						:slot = "activatedSlot()" ,
						:event = "activated"
					] ,
					[ 	:signal = "currentIndexChanged(int)" ,
						:slot = "currentIndexChangedSlot()" ,
						:event = "currentIndexChanged"
					] ,
					[ 	:signal = "editTextChanged(QString)" ,
						:slot = "editTextChangedSlot()" ,
						:event = "editTextChanged"
					] ,
					[ 	:signal = "highlighted(int)" ,
						:slot = "highlightedSlot()" ,
						:event = "highlighted"
					]
				  ]
		] ,
		[	:name = "GTabWidget" ,
			:realname = "QTabWidget" ,
			:events = [
					[ 	:signal = "currentChanged(int)" ,
						:slot = "currentChangedSlot()" ,
						:event = "currentChanged"
					] ,
					[ 	:signal = "tabCloseRequested(int)" ,
						:slot = "tabCloseRequestedSlot()" ,
						:event = "tabCloseRequested"
					]
				  ]
		] ,
		[	:name = "GTableWidget" ,
			:realname = "QTableWidget" ,
			:events = [
					[ 	:signal = "cellActivated(int,int)" ,
						:slot = "cellActivatedSlot()" ,
						:event = "cellActivated"
					] ,
					[ 	:signal = "cellChanged(int,int)" ,
						:slot = "cellChangedSlot()" ,
						:event = "cellChanged"
					] ,
					[ 	:signal = "cellClicked(int,int)" ,
						:slot = "cellClickedSlot()" ,
						:event = "cellClicked"
					] ,
					[ 	:signal = "cellDoubleClicked(int,int)" ,
						:slot = "cellDoubleClickedSlot()" ,
						:event = "cellDoubleClicked"
					] ,
					[ 	:signal = "cellEntered(int,int)" ,
						:slot = "cellEnteredSlot()" ,
						:event = "cellEntered"
					] ,
					[ 	:signal = "cellPressed(int,int)" ,
						:slot = "cellPressedSlot()" ,
						:event = "cellPressed"
					] ,
					[ 	:signal = "currentCellChanged(int,int,int,int)" ,
						:slot = "currentCellChangedSlot()" ,
						:event = "currentCellChanged"
					] ,
					[ 	:signal = "currentItemChanged(QTableWidgetItem *,QTableWidgetItem *)" ,
						:slot = "currentItemChangedSlot()" ,
						:event = "currentItemChanged"
					] ,
					[ 	:signal = "itemActivated(QTableWidgetItem *)" ,
						:slot = "itemActivatedSlot()" ,
						:event = "itemActivated"
					] ,
					[ 	:signal = "itemChanged(QTableWidgetItem *)" ,
						:slot = "itemChangedSlot()" ,
						:event = "itemChanged"
					] ,
					[ 	:signal = "itemClicked(QTableWidgetItem *)" ,
						:slot = "itemClickedSlot()" ,
						:event = "itemClicked"
					] ,
					[ 	:signal = "itemDoubleClicked(QTableWidgetItem *)" ,
						:slot = "itemDoubleClickedSlot()" ,
						:event = "itemDoubleClicked"
					] ,
					[ 	:signal = "itemEntered(QTableWidgetItem *)" ,
						:slot = "itemEnteredSlot()" ,
						:event = "itemEntered"
					] ,
					[ 	:signal = "itemPressed(QTableWidgetItem *)" ,
						:slot = "itemPressedSlot()" ,
						:event = "itemPressed"
					] ,
					[ 	:signal = "itemSelectionChanged()" ,
						:slot = "itemSelectionChangedSlot()" ,
						:event = "itemSelectionChanged"
					]
				  ]
		] ,
		[	:name = "GProgressBar" ,
			:realname = "QProgressBar" ,
			:events = [
					[ 	:signal = "valueChanged(int)" ,
						:slot = "valueChangedSlot()" ,
						:event = "valueChanged"
					]
				  ]
		] ,
		[	:name = "GSpinBox" ,
			:realname = "QSpinBox" ,
			:events = [
					[ 	:signal = "valueChanged(int)" ,
						:slot = "valueChangedSlot()" ,
						:event = "valueChanged"
					]
				  ]
		] ,
		[	:name = "GSlider" ,
			:realname = "QSlider" ,
			:events = [
					[ 	:signal = "actionTriggered(int)" ,
						:slot = "actionTriggeredSlot()" ,
						:event = "actionTriggered"
					] ,
					[ 	:signal = "rangeChanged(int,int)" ,
						:slot = "rangeChangedSlot()" ,
						:event = "rangeChanged"
					] ,
					[ 	:signal = "sliderMoved(int)" ,
						:slot = "sliderMovedSlot()" ,
						:event = "sliderMoved"
					] ,
					[ 	:signal = "sliderPressed()" ,
						:slot = "sliderPressedSlot()" ,
						:event = "sliderPressed"
					] ,
					[ 	:signal = "sliderReleased()" ,
						:slot = "sliderReleasedSlot()" ,
						:event = "sliderReleased"
					] ,
					[ 	:signal = "valueChanged(int)" ,
						:slot = "valueChangedSlot()" ,
						:event = "valueChanged"
					]
				  ]
		] ,
		[	:name = "GDial" ,
			:realname = "QDial" ,
			:events = [
					[ 	:signal = "actionTriggered(int)" ,
						:slot = "actionTriggeredSlot()" ,
						:event = "actionTriggered"
					] ,
					[ 	:signal = "rangeChanged(int,int)" ,
						:slot = "rangeChangedSlot()" ,
						:event = "rangeChanged"
					] ,
					[ 	:signal = "sliderMoved(int)" ,
						:slot = "sliderMovedSlot()" ,
						:event = "sliderMoved"
					] ,
					[ 	:signal = "sliderPressed()" ,
						:slot = "sliderPressedSlot()" ,
						:event = "sliderPressed"
					] ,
					[ 	:signal = "sliderReleased()" ,
						:slot = "sliderReleasedSlot()" ,
						:event = "sliderReleased"
					] ,
					[ 	:signal = "valueChanged(int)" ,
						:slot = "valueChangedSlot()" ,
						:event = "valueChanged"
					]
				  ]
		] ,
		[	:name = "GWebView" ,
			:realname = "QWebView" ,
			:events = [
					[ 	:signal = "iconChanged()" ,
						:slot = "iconChangedSlot()" ,
						:event = "iconChanged"
					] ,
					[ 	:signal = "linkClicked(QUrl)" ,
						:slot = "linkClickedSlot()" ,
						:event = "linkClicked"
					] ,
					[ 	:signal = "loadFinished(bool)" ,
						:slot = "loadFinishedSlot()" ,
						:event = "loadFinished"
					] ,
					[ 	:signal = "loadProgress(int)" ,
						:slot = "loadProgressSlot()" ,
						:event = "loadProgress"
					] ,
					[ 	:signal = "loadStarted()" ,
						:slot = "loadStartedSlot()" ,
						:event = "loadStarted"
					] ,
					[ 	:signal = "selectionChanged()" ,
						:slot = "selectionChangedSlot()" ,
						:event = "selectionChanged"
					] ,
					[ 	:signal = "statusBarMessage(QString)" ,
						:slot = "statusBarMessageSlot()" ,
						:event = "statusBarMessage"
					] ,
					[ 	:signal = "titleChanged(QString)" ,
						:slot = "titleChangedSlot()" ,
						:event = "titleChanged"
					] ,
					[ 	:signal = "urlChanged(QUrl)" ,
						:slot = "urlChangedSlot()" ,
						:event = "urlChanged"
					]
				  ]
		] ,
		[	:name = "GCheckBox" ,
			:realname = "QCheckBox" ,
			:events = [
					[ 	:signal = "stateChanged(int)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					] ,
					[ 	:signal = "clicked(bool)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					] ,
					[ 	:signal = "pressed()" ,
						:slot = "pressedSlot()" ,
						:event = "pressed"
					] ,
					[ 	:signal = "released()" ,
						:slot = "releasedSlot()" ,
						:event = "released"
					] ,
					[ 	:signal = "toggled(bool)" ,
						:slot = "toggledSlot()" ,
						:event = "toggled"
					]
				  ]
		] ,
		[	:name = "GRadioButton" ,
			:realname = "QRadioButton" ,
			:events = [
					[ 	:signal = "clicked(bool)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					] ,
					[ 	:signal = "pressed()" ,
						:slot = "pressedSlot()" ,
						:event = "pressed"
					] ,
					[ 	:signal = "released()" ,
						:slot = "releasedSlot()" ,
						:event = "released"
					] ,
					[ 	:signal = "toggled(bool)" ,
						:slot = "toggledSlot()" ,
						:event = "toggled"
					]
				  ]
		] ,
		[	:name = "GButtonGroup" ,
			:realname = "QButtonGroup" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "buttonClicked(int)" ,
						:slot = "buttonClickedSlot()" ,
						:event = "buttonClicked"
					] ,
					[ 	:signal = "buttonPressed(int)" ,
						:slot = "buttonPressedSlot()" ,
						:event = "buttonPressed"
					] ,
					[ 	:signal = "buttonReleased(int)" ,
						:slot = "buttonReleasedSlot()" ,
						:event = "buttonReleased"
					]
				  ]
		] ,
		[	:name = "GVideoWidget" ,
			:realname = "QVideoWidget" ,
			:events = [
					[ 	:signal = "brightnessChanged(int)" ,
						:slot = "brightnessChangedSlot()" ,
						:event = "brightnessChanged"
					] ,
					[ 	:signal = "contrastChanged(int)" ,
						:slot = "contrastChangedSlot()" ,
						:event = "contrastChanged"
					] ,
					[ 	:signal = "fullScreenChanged(bool)" ,
						:slot = "fullScreenChangedSlot()" ,
						:event = "fullScreenChanged"
					] ,
					[ 	:signal = "hueChanged(int)" ,
						:slot = "hueChangedSlot()" ,
						:event = "hueChanged"
					] ,
					[ 	:signal = "saturationChanged(int)" ,
						:slot = "saturationChangedSlot()" ,
						:event = "saturationChanged"
					]
				  ]
		] ,
		[	:name = "GTimer" ,
			:realname = "QTimer" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "timeout()" ,
						:slot = "timeoutSlot()" ,
						:event = "timeout"
					]
				  ]
		] ,
		[	:name = "GTcpServer" ,
			:realname = "QTcpServer" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "acceptError(QAbstractSocket::SocketError)" ,
						:slot = "acceptErrorSlot()" ,
						:event = "acceptError"
					] ,
					[ 	:signal = "newConnection()" ,
						:slot = "newConnectionSlot()" ,
						:event = "newConnection"
					]
				  ]
		] ,
		[	:name = "GIODevice" ,
			:realname = "QIODevice" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "aboutToClose()" ,
						:slot = "aboutToCloseSlot()" ,
						:event = "aboutToClose"
					] ,
					[ 	:signal = "bytesWritten(qint64)" ,
						:slot = "bytesWrittenSlot()" ,
						:event = "bytesWritten"
					] ,
					[ 	:signal = "readChannelFinished()" ,
						:slot = "readChannelFinishedSlot()" ,
						:event = "readChannelFinished"
					] ,
					[ 	:signal = "readyRead()" ,
						:slot = "readyReadSlot()" ,
						:event = "readyRead"
					]
				  ]
		] ,
		[	:name = "GAbstractSocket" ,
			:realname = "QAbstractSocket" ,
			:initpara = "QAbstractSocket::SocketType x,QObject *",
			:initparaparent = "x,",
			:events = [
					[ 	:signal = "connected()" ,
						:slot = "connectedSlot()" ,
						:event = "connected"
					] ,
					[ 	:signal = "disconnected()" ,
						:slot = "disconnectedSlot()" ,
						:event = "disconnected"
					] ,
					[ 	:signal = "error(QAbstractSocket::SocketError)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					] ,
					[ 	:signal = "hostFound()" ,
						:slot = "hostFoundSlot()" ,
						:event = "hostFound"
					] ,
					[ 	:signal = "proxyAuthenticationRequired(QNetworkProxy,QAuthenticator *)" ,
						:slot = "proxyAuthenticationRequiredSlot()" ,
						:event = "proxyAuthenticationRequired"
					] ,
					[ 	:signal = "stateChanged(QAbstractSocket::SocketState)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					]
				  ]
		] ,
		[	:name = "GTcpSocket" ,
			:realname = "QTcpSocket" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "connected()" ,
						:slot = "connectedSlot()" ,
						:event = "connected"
					] ,
					[ 	:signal = "disconnected()" ,
						:slot = "disconnectedSlot()" ,
						:event = "disconnected"
					] ,
					[ 	:signal = "error(QAbstractSocket::SocketError)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					] ,
					[ 	:signal = "hostFound()" ,
						:slot = "hostFoundSlot()" ,
						:event = "hostFound"
					] ,
					[ 	:signal = "proxyAuthenticationRequired(QNetworkProxy,QAuthenticator *)" ,
						:slot = "proxyAuthenticationRequiredSlot()" ,
						:event = "proxyAuthenticationRequired"
					] ,
					[ 	:signal = "stateChanged(QAbstractSocket::SocketState)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					] ,
					[ 	:signal = "aboutToClose()" ,
						:slot = "aboutToCloseSlot()" ,
						:event = "aboutToClose"
					] ,
					[ 	:signal = "bytesWritten(qint64)" ,
						:slot = "bytesWrittenSlot()" ,
						:event = "bytesWritten"
					] ,
					[ 	:signal = "readChannelFinished()" ,
						:slot = "readChannelFinishedSlot()" ,
						:event = "readChannelFinished"
					] ,
					[ 	:signal = "readyRead()" ,
						:slot = "readyReadSlot()" ,
						:event = "readyRead"
					]
				  ]
		],
		[	:name = "GColorDialog" ,
			:realname = "QColorDialog" ,
			:events = [
					[ 	:signal = "colorSelected(QColor)" ,
						:slot = "colorSelectedSlot()" ,
						:event = "colorSelected"
					] ,
					[ 	:signal = "currentColorChanged(QColor)" ,
						:slot = "currentColorChangedSlot()" ,
						:event = "currentColorChanged"
					]
				  ]
		]
	    ]

Func Main

	for aClass in aClasses
		GenHeader(aClass)	GenSource(aClass)
	next

Func GenHeader aClass

	# Start of code string
	cCode = `
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef <T_HEADER>
#define <T_HEADER>
#include <QApplication>
#include <<T_REALCLASSNAME>>
extern "C" {
#include "ring.h"
}

class <T_CLASSNAME> : public <T_REALCLASSNAME>
{

  Q_OBJECT

  public:

    VM *pVM;

<T_EVENTSATTRIBUTES>

<T_CLASSNAMEMETHOD>(<T_INITPARA>parent,VM *pVM );

<T_SETEVENTS>

  public slots:

<T_SLOTS>
};

#endif

`	# End of Code String

	cSpace = copy(" ",4)

	# Set the header name
	cCode = substr(cCode,"<T_HEADER>", upper(aClass[:name])+"_H")

	# Set the class name and the parent class name
	cCode = substr(cCode,"<T_CLASSNAME>", aClass[:name])
	cCode = substr(cCode,"<T_CLASSNAMEMETHOD>", cSpace+aClass[:name])
	cCode = substr(cCode,"<T_REALCLASSNAME>", aClass[:realname])

	if aClass[:initpara] != NULL
		cCode = substr(cCode,"<T_INITPARA>", aClass[:initpara])
	else
		cCode = substr(cCode,"<T_INITPARA>", "QWidget *")
	ok

	aEvents = aClass[:events]
	cEventsAttributes = "" cSetEvents = ""  cEventsSlots = ""

	for aEvent in aEvents
		# Events Attributes
		cEventsAttributes += cSpace+"char c"+aEvent[:event]+"Event[100];"+nl
		# Set Events
		cSetEvents += cSpace+"void set"+aEvent[:event]+"Event(const char *cStr);"+nl
		# Events Slots
		cEventsSlots += cSpace+"void "+aEvent[:slot]+";"+nl
	Next

	cCode = substr(cCode,"<T_EVENTSATTRIBUTES>", cEventsAttributes)
	cCode = substr(cCode,"<T_SETEVENTS>", cSetEvents)
	cCode = substr(cCode,"<T_SLOTS>", cEventsSlots)

	cFileName = lower(aClass[:name]) + ".h"
	writefile(cFileName,cCode)

Func GenSource aClass

# Start of code string
	cCode = `
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "<T_HEADER>.h"

<T_CLASSNAME>::<T_CLASSNAME>(<T_INITPARA>parent,VM *pVM)  : <T_REALCLASSNAME>(<T_INITPARAPARENT>parent)
{
	this->pVM = pVM;
<T_CLEAREVENTS>
<T_CONNECT>
}
<T_SETEVENTS>
<T_SLOTS>
`	# End of Code String

	# Set the class name and the parent class name
	cCode = substr(cCode,"<T_HEADER>", lower(aClass[:name]))
	cCode = substr(cCode,"<T_CLASSNAME>", aClass[:name])
	cCode = substr(cCode,"<T_REALCLASSNAME>", aClass[:realname])

	if aClass[:initpara] != NULL
		cCode = substr(cCode,"<T_INITPARA>", aClass[:initpara])
	else
		cCode = substr(cCode,"<T_INITPARA>", "QWidget *")
	ok

	if aClass[:initparaparent] != NULL
		cCode = substr(cCode,"<T_INITPARAPARENT>", aClass[:initparaparent])
	else
		cCode = substr(cCode,"<T_INITPARAPARENT>", "")
	ok

	aEvents = aClass[:events]
	cClearEvents = "" cConnect = ""  cSetEvents = " " cSlots = ""

	for aEvent in aEvents

		# Clear Events
		cClearEvents += char(9) + 'strcpy(this->c'+aEvent[:event]+'Event,"");'+nl

		# Connect
		cConnect += char(9) + "QObject::connect(this, SIGNAL("+aEvent[:signal]+
				"),this, SLOT("+aEvent[:slot]+"));"+nl
		# Set Events
		cSetEvents += "
void "+aClass[:name]+"::set"+aEvent[:event]+"Event(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->c"+aEvent[:event]+"Event,cStr);
}" + nl

		# Slots
		cSlots += '
void '+aClass[:name]+'::'+aEvent[:slot]+'
{
	if (strcmp(this->c'+aEvent[:event]+'Event,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->c'+aEvent[:event]+'Event);
}
'

	Next

	cCode = substr(cCode,"<T_CLEAREVENTS>", cClearEvents)
	cCode = substr(cCode,"<T_CONNECT>", cConnect)
	cCode = substr(cCode,"<T_SETEVENTS>", cSetEvents)
	cCode = substr(cCode,"<T_SLOTS>", cSlots)

	cFileName = lower(aClass[:name]) + ".cpp"
	writefile(cFileName,cCode)

Func WriteFile cFileName,cCode
	See "Writing file : " + cFileName + nl +
	    "Size : " + len(cCode) + " Bytes" + nl
	aCode = str2list(cCode)
	fp = fopen(cFileName,"wb")
	for cLine in aCode
		fwrite(fp,cLine+char(13)+char(10))
	next
	fclose(fp)
