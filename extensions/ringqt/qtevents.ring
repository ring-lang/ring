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
		[	:name = "GWebEngineView" ,
			:realname = "QWebEngineView" ,
			:events = [
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
		],
		[	:name = "GNetworkAccessManager" ,
			:realname = "QNetworkAccessManager" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "finished(QNetworkReply*)" ,
						:slot = "finishedSlot()" ,
						:event = "finished",
						:slotparaconnect = "QNetworkReply*",
						:slotparafunction = "QNetworkReply *p1",
						:slotparacode = SlotParaGetPointer("QNetworkReply *")
					] 
				  ]
		],
		[	:name = "GThread" ,
			:realname = "QThread" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "started()" ,
						:slot = "startedSlot()" ,
						:event = "Started",
						:thread = True
					] ,
					[ 	:signal = "finished()" ,
						:slot = "finishedSlot()" ,
						:event = "Finished",
						:thread = True
					] 
				  ]
		],
		[	:name = "GPlainTextEdit" ,
			:realname = "QPlainTextEdit" ,
			:events = [
					[ 	:signal = "blockCountChanged(int)" ,
						:slot = "blockCountChangedSlot()" ,
						:event = "blockCountChanged"
					] ,
					[ 	:signal = "copyAvailable(bool)" ,
						:slot = "copyAvailableSlot()" ,
						:event = "copyAvailable"
					] ,
					[ 	:signal = "cursorPositionChanged()" ,
						:slot = "cursorPositionChangedSlot()" ,
						:event = "cursorPositionChanged"
					] ,
					[ 	:signal = "modificationChanged(bool)" ,
						:slot = "modificationChangedSlot()" ,
						:event = "modificationChanged"
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
					],
					[ 	:signal = "updateRequest(const QRect, int)" ,
						:slot = "updateRequestSlot()" ,
						:event = "updateRequest"
					]
				  ]
		] ,
		[	:name = "GHeaderView" ,
			:initpara = "Qt::Orientation x, QWidget *",
			:initparaparent = "x,",
			:realname = "QHeaderView" ,
			:events = [
					[ 	:signal = "geometriesChanged()" ,
						:slot = "geometriesChangedSlot()" ,
						:event = "geometriesChanged"
					] ,
					[ 	:signal = "sectionClicked(int)" ,
						:slot = "sectionClickedSlot()" ,
						:event = "sectionClicked",
						:slotparaconnect = "int",
						:slotparafunction = "int p1",
						:slotparacode = SlotParaGetNumber()
					],
					[ 	:signal = "sectionCountChanged(int, int)" ,
						:slot = "sectionCountChangedSlot()" ,
						:event = "sectionCountChanged"
					] ,			
					[ 	:signal = "sectionDoubleClicked(int)" ,
						:slot = "sectionDoubleClickedSlot()" ,
						:event = "sectionDoubleClicked"
					] ,			
					[ 	:signal = "sectionEntered(int)" ,
						:slot = "sectionEnteredSlot()" ,
						:event = "sectionEntered"
					] ,			
					[ 	:signal = "sectionHandleDoubleClicked(int)" ,
						:slot = "sectionHandleDoubleClickedSlot()" ,
						:event = "sectionHandleDoubleClicked"
					] ,		
					[ 	:signal = "sectionMoved(int, int, int)" ,
						:slot = "sectionMovedSlot()" ,
						:event = "sectionMoved"
					] ,		
					[ 	:signal = "sectionPressed(int)" ,
						:slot = "sectionPressedSlot()" ,
						:event = "sectionPressed"
					] ,		
					[ 	:signal = "sectionResized(int, int, int)" ,
						:slot = "sectionResizedSlot()" ,
						:event = "sectionResized"
					] ,		
					[ 	:signal = "sortIndicatorChanged(int, Qt::SortOrder)" ,
						:slot = "sortIndicatorChangedSlot()" ,
						:event = "sortIndicatorChanged"
					] 		
			  ]
		] ,
		[	:name = "GProcess" ,
			:realname = "QProcess" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "readyReadStandardError()" ,
						:slot = "readyReadStandardErrorSlot()" ,
						:event = "readyReadStandardError"
					] ,
					[ 	:signal = "readyReadStandardOutput()" ,
						:slot = "readyReadStandardOutputSlot()" ,
						:event = "readyReadStandardOutput"
					] 
				  ]
		],
		[	:name = "GToolButton" ,
			:realname = "QToolButton" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "triggered(QAction *)" ,
						:slot = "triggeredSlot()" ,
						:event = "triggered"
					],
					[ 	:signal = "clicked()" ,
						:slot = "clickedSlot()" ,
						:event = "Click"
					]
				  ]
		],
		[	:name = "GSerialPort" ,
			:realname = "QSerialPort" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "baudRateChanged(qint32,QSerialPort::Directions)" ,
						:slot = "baudRateChangedSlot()" ,
						:event = "baudRateChanged"
					],
					[ 	:signal = "breakEnabledChanged(bool)" ,
						:slot = "breakEnabledChangedSlot()" ,
						:event = "breakEnabledChanged"
					],
					[ 	:signal = "dataBitsChanged(QSerialPort::DataBits)" ,
						:slot = "dataBitsChangedSlot()" ,
						:event = "dataBitsChanged"
					],
					[ 	:signal = "dataTerminalReadyChanged(bool)" ,
						:slot = "dataTerminalReadyChangedSlot()" ,
						:event = "dataTerminalReadyChanged"
					],
					[ 	:signal = "error(QSerialPort::SerialPortError)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "flowControlChanged(QSerialPort::FlowControl)" ,
						:slot = "flowControlChangedSlot()" ,
						:event = "flowControlChanged"
					],
					[ 	:signal = "parityChanged(QSerialPort::Parity)" ,
						:slot = "parityChangedSlot()" ,
						:event = "parityChanged"
					],
					[ 	:signal = "requestToSendChanged(bool)" ,
						:slot = "requestToSendChangedSlot()" ,
						:event = "requestToSendChanged"
					],
					[ 	:signal = "stopBitsChanged(QSerialPort::StopBits)" ,
						:slot = "stopBitsChangedSlot()" ,
						:event = "stopBitsChanged"
					]
			]
		],
		[	:name = "GBluetoothDeviceDiscoveryAgent" ,
			:realname = "QBluetoothDeviceDiscoveryAgent" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "canceled()" ,
						:slot = "canceledSlot()" ,
						:event = "canceled"
					],
					[ 	:signal = "deviceDiscovered(const QBluetoothDeviceInfo)" ,
						:slot = "deviceDiscoveredSlot()" ,
						:event = "deviceDiscovered"
					],
					[ 	:signal = "error(QBluetoothDeviceDiscoveryAgent::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "finished()" ,
						:slot = "finishedSlot()" ,
						:event = "finished"
					]
				]
		],
		[	:name = "GBluetoothLocalDevice" ,
			:realname = "QBluetoothLocalDevice" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "deviceConnected(const QBluetoothAddress)" ,
						:slot = "deviceConnectedSlot()" ,
						:event = "deviceConnected"
					],
					[ 	:signal = "deviceDisconnected(const QBluetoothAddress)" ,
						:slot = "deviceDisconnectedSlot()" ,
						:event = "deviceDisconnected"
					],
					[ 	:signal = "error(QBluetoothLocalDevice::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "hostModeStateChanged(QBluetoothLocalDevice::HostMode)" ,
						:slot = "hostModeStateChangedSlot()" ,
						:event = "hostModeStateChanged"
					],
					[ 	:signal = "pairingDisplayConfirmation(const QBluetoothAddress,QString)" ,
						:slot = "pairingDisplayConfirmationSlot()" ,
						:event = "pairingDisplayConfirmation"
					],
					[ 	:signal = "pairingDisplayPinCode(const QBluetoothAddress,QString)" ,
						:slot = "pairingDisplayPinCodeSlot()" ,
						:event = "pairingDisplayPinCode"
					],
					[ 	:signal = "pairingFinished(const QBluetoothAddress,QBluetoothLocalDevice::Pairing)" ,
						:slot = "pairingFinishedSlot()" ,
						:event = "pairingFinished"
					]
				]
		],
		[	:name = "GBluetoothServer" ,
			:realname = "QBluetoothServer" ,
			:initpara = "QBluetoothServiceInfo::Protocol x,QObject *",
			:initparaparent = "x,",
			:events = [
					[ 	:signal = "error(QBluetoothServer::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "newConnection()" ,
						:slot = "newConnectionSlot()" ,
						:event = "newConnection"
					]
				]
		],
		[	:name = "GBluetoothServiceDiscoveryAgent" ,
			:realname = "QBluetoothServiceDiscoveryAgent" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "canceled()" ,
						:slot = "canceledSlot()" ,
						:event = "canceled"
					],
					[ 	:signal = "error(QBluetoothServiceDiscoveryAgent::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "finished()" ,
						:slot = "finishedSlot()" ,
						:event = "finished"
					],
					[ 	:signal = "serviceDiscovered(const QBluetoothServiceInfo)" ,
						:slot = "serviceDiscoveredSlot()" ,
						:event = "serviceDiscovered"
					]
				]
		],
		[	:name = "GBluetoothSocket" ,
			:realname = "QBluetoothSocket" ,
			:initpara = "QBluetoothServiceInfo::Protocol x,QObject *",
			:initparaparent = "x,",
			:events = [
					[ 	:signal = "connected()" ,
						:slot = "connectedSlot()" ,
						:event = "connected"
					],
					[ 	:signal = "disconnected()" ,
						:slot = "disconnectedSlot()" ,
						:event = "disconnected"
					],
					[ 	:signal = "error(QBluetoothSocket::SocketError)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "stateChanged(QBluetoothSocket::SocketState)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					]
				]
		],
		[	:name = "GBluetoothTransferManager" ,
			:realname = "QBluetoothTransferManager" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "finished(QBluetoothTransferReply *)" ,
						:slot = "finishedSlot()" ,
						:event = "finished"
					]
				]
		],
		[	:name = "GBluetoothTransferReply" ,
			:realname = "QBluetoothTransferReply" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "error(QBluetoothTransferReply::TransferError)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "finished(QBluetoothTransferReply *)" ,
						:slot = "finishedSlot()" ,
						:event = "finished"
					],
					[ 	:signal = "transferProgress(qint64,qint64)" ,
						:slot = "transferProgressSlot()" ,
						:event = "transferProgress"
					]
				]
		],
		[	:name = "GWindow" ,
			:realname = "QWindow" ,
			:initpara = "QScreen *",
			:events = [
					[ 	:signal = "activeChanged()" ,
						:slot = "activeChangedSlot()" ,
						:event = "activeChanged"
					],
					[ 	:signal = "contentOrientationChanged(Qt::ScreenOrientation)" ,
						:slot = "contentOrientationChangedSlot()" ,
						:event = "contentOrientationChanged"
					],
					[ 	:signal = "focusObjectChanged(QObject *)" ,
						:slot = "focusObjectChangedSlot()" ,
						:event = "focusObjectChanged"
					],
					[ 	:signal = "heightChanged(int)" ,
						:slot = "heightChangedSlot()" ,
						:event = "heightChanged"
					],
					[ 	:signal = "maximumHeightChanged(int)" ,
						:slot = "maximumHeightChangedSlot()" ,
						:event = "maximumHeightChanged"
					],
					[ 	:signal = "maximumWidthChanged(int)" ,
						:slot = "maximumWidthChangedSlot()" ,
						:event = "maximumWidthChanged"
					],
					[ 	:signal = "minimumHeightChanged(int)" ,
						:slot = "minimumHeightChangedSlot()" ,
						:event = "minimumHeightChanged"
					],
					[ 	:signal = "minimumWidthChanged(int)" ,
						:slot = "minimumWidthChangedSlot()" ,
						:event = "minimumWidthChanged"
					],
					[ 	:signal = "modalityChanged(Qt::WindowModality)" ,
						:slot = "modalityChangedSlot()" ,
						:event = "modalityChanged"
					],
					[ 	:signal = "opacityChanged(qreal)" ,
						:slot = "opacityChangedSlot()" ,
						:event = "opacityChanged"
					],
					[ 	:signal = "screenChanged(QScreen *)" ,
						:slot = "screenChangedSlot()" ,
						:event = "screenChanged"
					],
					[ 	:signal = "visibilityChanged(QWindow::Visibility)" ,
						:slot = "visibilityChangedSlot()" ,
						:event = "visibilityChanged"
					],
					[ 	:signal = "visibleChanged(bool)" ,
						:slot = "visibleChangedSlot()" ,
						:event = "visibleChanged"
					],
					[ 	:signal = "widthChanged(int)" ,
						:slot = "widthChangedSlot()" ,
						:event = "widthChanged"
					],
					[ 	:signal = "windowStateChanged(Qt::WindowState)" ,
						:slot = "windowStateChangedSlot()" ,
						:event = "windowStateChanged"
					],
					[ 	:signal = "windowTitleChanged(const QString)" ,
						:slot = "windowTitleChangedSlot()" ,
						:event = "windowTitleChanged"
					],
					[ 	:signal = "xChanged(int)" ,
						:slot = "xChangedSlot()" ,
						:event = "xChanged"
					],
					[ 	:signal = "yChanged(int)" ,
						:slot = "yChangedSlot()" ,
						:event = "yChanged"
					]
				 ]
		],
		[	:name = "GGuiApplication" ,
			:realname = "QGuiApplication" ,
			:initpara = "int argc,char **",
			:initparaparent = "argc,",
			:events = [
					[ 	:signal = "applicationDisplayNameChanged()" ,
						:slot = "applicationDisplayNameChangedSlot()" ,
						:event = "applicationDisplayNameChanged"
					],
					[ 	:signal = "applicationStateChanged(Qt::ApplicationState)" ,
						:slot = "applicationStateChangedSlot()" ,
						:event = "applicationStateChanged"
					],
					[ 	:signal = "commitDataRequest(QSessionManager)" ,
						:slot = "commitDataRequestSlot()" ,
						:event = "commitDataRequest"
					],
					[ 	:signal = "focusObjectChanged(QObject *)" ,
						:slot = "focusObjectChangedSlot()" ,
						:event = "focusObjectChanged"
					],
					[ 	:signal = "focusWindowChanged(QWindow *)" ,
						:slot = "focusWindowChangedSlot()" ,
						:event = "focusWindowChanged"
					],
					[ 	:signal = "fontDatabaseChanged()" ,
						:slot = "fontDatabaseChangedSlot()" ,
						:event = "fontDatabaseChanged"
					],
					[ 	:signal = "lastWindowClosed()" ,
						:slot = "lastWindowClosedSlot()" ,
						:event = "lastWindowClosed"
					],
					[ 	:signal = "layoutDirectionChanged(Qt::LayoutDirection)" ,
						:slot = "layoutDirectionChangedSlot()" ,
						:event = "layoutDirectionChanged"
					],
					[ 	:signal = "paletteChanged(const QPalette)" ,
						:slot = "paletteChangedSlot()" ,
						:event = "paletteChanged"
					],
					[ 	:signal = "primaryScreenChanged(QScreen *)" ,
						:slot = "primaryScreenChangedSlot()" ,
						:event = "primaryScreenChanged"
					],
					[ 	:signal = "saveStateRequest(QSessionManager)" ,
						:slot = "saveStateRequestSlot()" ,
						:event = "saveStateRequest"
					],
					[ 	:signal = "screenAdded(QScreen *)" ,
						:slot = "screenAddedSlot()" ,
						:event = "screenAdded"
					],
					[ 	:signal = "screenRemoved(QScreen *)" ,
						:slot = "screenRemovedSlot()" ,
						:event = "screenRemoved"
					]
				]
		],
		[	:name = "GTextBrowser" ,
			:realname = "QTextBrowser" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "anchorClicked(const QUrl)" ,
						:slot = "anchorClickedSlot()" ,
						:event = "anchorClicked"
					],
					[ 	:signal = "backwardAvailable(bool)" ,
						:slot = "backwardAvailableSlot()" ,
						:event = "backwardAvailable"
					],
					[ 	:signal = "forwardAvailable(bool)" ,
						:slot = "forwardAvailableSlot()" ,
						:event = "forwardAvailable"
					],
					[ 	:signal = "highlighted(const QString)" ,
						:slot = "highlightedSlot()" ,
						:event = "highlighted"
					],
					[ 	:signal = "historyChanged()" ,
						:slot = "historyChangedSlot()" ,
						:event = "historyChanged"
					],
					[ 	:signal = "sourceChanged(const QUrl)" ,
						:slot = "sourceChangedSlot()" ,
						:event = "sourceChanged"
					]
				]
		],
		[	:name = "GDockWidget" ,
			:realname = "QDockWidget" ,
			:initpara = "QWidget *x,Qt::WindowFlags ",
			:initparaparent = "x,",
			:events = [
					[ 	:signal = "allowedAreasChanged(Qt::DockWidgetAreas)" ,
						:slot = "allowedAreasChangedSlot()" ,
						:event = "allowedAreasChanged"
					],
					[ 	:signal = "dockLocationChanged(Qt::DockWidgetArea)" ,
						:slot = "dockLocationChangedSlot()" ,
						:event = "dockLocationChanged"
					],
					[ 	:signal = "featuresChanged(QDockWidget::DockWidgetFeatures)" ,
						:slot = "featuresChangedSlot()" ,
						:event = "featuresChanged"
					],
					[ 	:signal = "topLevelChanged(bool)" ,
						:slot = "topLevelChangedSlot()" ,
						:event = "topLevelChanged"
					],
					[ 	:signal = "visibilityChanged(bool)" ,
						:slot = "visibilityChangedSlot()" ,
						:event = "visibilityChanged"
					]
				]
		],
		[	:name = "GStackedWidget" ,
			:realname = "QStackedWidget" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "currentChanged(int)" ,
						:slot = "currentChangedSlot()" ,
						:event = "currentChanged"
					],
					[ 	:signal = "widgetRemoved(int)" ,
						:slot = "widgetRemovedSlot()" ,
						:event = "widgetRemoved"
					]
				]
		],
		[	:name = "GCalendarWidget" ,
			:realname = "QCalendarWidget" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "activated(const QDate)" ,
						:slot = "activatedSlot()" ,
						:event = "activated"
					],
					[ 	:signal = "clicked(const QDate)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					],
					[ 	:signal = "currentPageChanged(int,int)" ,
						:slot = "currentPageChangedSlot()" ,
						:event = "currentPageChanged"
					],
					[ 	:signal = "selectionChanged()" ,
						:slot = "selectionChangedSlot()" ,
						:event = "selectionChanged"
					]
				]
		],
		[	:name = "GTabBar" ,
			:realname = "QTabBar" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "currentChanged(int)" ,
						:slot = "currentChangedSlot()" ,
						:event = "currentChanged"
					],
					[ 	:signal = "tabCloseRequested(int)" ,
						:slot = "tabCloseRequestedSlot()" ,
						:event = "tabCloseRequested"
					],
					[ 	:signal = "tabMoved(int,int)" ,
						:slot = "tabMovedSlot()" ,
						:event = "tabMoved"
					]
				]
		],
		[	:name = "GQuickWidget" ,
			:realname = "QQuickWidget" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "sceneGraphError(QQuickWindow::SceneGraphError,const QString)" ,
						:slot = "sceneGraphErrorSlot()" ,
						:event = "sceneGraphError"
					],
					[ 	:signal = "statusChanged(QQuickWidget::Status)" ,
						:slot = "statusChangedSlot()" ,
						:event = "statusChanged"
					]
				]
		]

	    ]

Func Main

	# DocFuncs() bye
	for aClass in aClasses
		GenHeader(aClass)	GenSource(aClass)
	next

Func DocFuncs
	for aClass in aClasses
		see copy("=",50)  + nl
		see aClass[:realname] + " Class " + nl +copy("=",50) +nl
		aEvents  = aClass[:events]
		for aEvent in aEvents
			cEvent = aEvent[:event]
			see "Set" + upper(left(cEvent,1))+substr(cEvent,2)+"Event()" + nl
		next		
		see copy("=",50)  + nl	
	next
	

Func GenHeader aClass

	# Start of code string
	cCode = `
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    List *pParaList;

<T_EVENTSATTRIBUTES>

<T_CLASSNAMEMETHOD>(<T_INITPARA>parent,VM *pVM );

<T_CLASSNAMEMETHOD2>();

<T_GETEVENTPARAMETERS>

<T_SETEVENTS>

<T_GETEVENTS>

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
	cCode = substr(cCode,"<T_CLASSNAMEMETHOD2>", cSpace+"~"+aClass[:name])
	cCode = substr(cCode,"<T_GETEVENTPARAMETERS>", cSpace+"void geteventparameters(void) ;")
	cCode = substr(cCode,"<T_REALCLASSNAME>", aClass[:realname])

	if aClass[:initpara] != NULL
		cCode = substr(cCode,"<T_INITPARA>", aClass[:initpara])
	else
		cCode = substr(cCode,"<T_INITPARA>", "QWidget *")
	ok

	aEvents = aClass[:events]
	cEventsAttributes = "" cSetEvents = ""  cGetEvents = "" cEventsSlots = ""

	for aEvent in aEvents
		# Events Attributes
		cEventsAttributes += cSpace+"char c"+aEvent[:event]+"Event[100];"+nl
		# Set Events
		cSetEvents += cSpace+"void set"+aEvent[:event]+"Event(const char *cStr);"+nl
		# Get Events
		cGetEvents += cSpace+"const char *get"+aEvent[:event]+"Event(void);"+nl
		# Events Slots

		cSlot = aEvent[:slot]
		if aEvent[:slotparafunction] != NULL
			cSlot = substr(cSlot,"()","("+aEvent[:slotparafunction]+")")
		ok

		cEventsSlots += cSpace+"void "+cSlot+";"+nl
	Next

	cCode = substr(cCode,"<T_EVENTSATTRIBUTES>", cEventsAttributes)
	cCode = substr(cCode,"<T_SETEVENTS>", cSetEvents)
	cCode = substr(cCode,"<T_GETEVENTS>", cGetEvents)
	cCode = substr(cCode,"<T_SLOTS>", cEventsSlots)

	cFileName = lower(aClass[:name]) + ".h"
	writefile(cFileName,cCode)

Func GenSource aClass

# Start of code string
	cCode = `
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "<T_HEADER>.h"

<T_CLASSNAME>::<T_CLASSNAME>(<T_INITPARA>parent,VM *pVM)  : <T_REALCLASSNAME>(<T_INITPARAPARENT>parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
<T_CLEAREVENTS>
<T_CONNECT>
}

<T_CLASSNAME>::~<T_CLASSNAME>()
{
	ring_list_delete(this->pParaList);
}

void <T_CLASSNAME>::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


<T_SETEVENTS>
<T_GETEVENTS>
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
	cClearEvents = "" cConnect = ""  cSetEvents = " " cGetEvents = " " cSlots = ""

	for aEvent in aEvents

		# Clear Events
		cClearEvents += char(9) + 'strcpy(this->c'+aEvent[:event]+'Event,"");'+nl

		# Connect
		cSlot = aEvent[:slot]
		if aEvent[:slotparaconnect] != NULL
			cSlot = substr(cSlot,"()","("+aEvent[:slotparaconnect]+")")
		ok

		cConnect += char(9) + "QObject::connect(this, SIGNAL("+aEvent[:signal]+
				"),this, SLOT("+cSlot+"));"+nl
		# Set Events
		cSetEvents += "
void "+aClass[:name]+"::set"+aEvent[:event]+"Event(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->c"+aEvent[:event]+"Event,cStr);
}" + nl

		# Get Events
		cGetEvents += "
const char *"+aClass[:name]+"::get"+aEvent[:event]+"Event(void)
{
	return this->c"+aEvent[:event]+"Event;
}" + nl

		# Slots
		cSlots += '
void '+aClass[:name]+'::'


		cSlot = aEvent[:slot]
		if aEvent[:slotparafunction] != NULL
			cSlot = substr(cSlot,"()","("+aEvent[:slotparafunction]+")")
		ok

		cSlots += cSlot

		cSlots +='
{
	if (strcmp(this->c'+aEvent[:event]+'Event,"")==0)
		return ;
'
		cSlots += aEvent[:slotparacode]


	if aEvent[:thread] = True 
		cSlots +='
	ring_vm_runcodefromthread(this->pVM,this->c'+aEvent[:event]+'Event);
}
'
	else 
		cSlots +='
	ring_vm_runcode(this->pVM,this->c'+aEvent[:event]+'Event);
}
'
	ok

	Next

	cCode = substr(cCode,"<T_CLEAREVENTS>", cClearEvents)
	cCode = substr(cCode,"<T_CONNECT>", cConnect)
	cCode = substr(cCode,"<T_SETEVENTS>", cSetEvents)
	cCode = substr(cCode,"<T_GETEVENTS>", cGetEvents)
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


Func SlotParaGetNumber 
	return "
		ring_list_deleteallitems(this->pParaList);
		ring_list_adddouble(this->pParaList, (double) p1 ) ;	
	"

Func SlotParaGetPointer cType
	return "
		ring_list_deleteallitems(this->pParaList);
		ring_list_addcpointer(this->pParaList, p1, "+'"'+cType+'"'+" ) ;	
	"