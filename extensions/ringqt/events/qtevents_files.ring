aClasses = []

load "qpushbutton.ring"
load "qaction.ring"
load "qlineedit.ring"
load "qtextedit.ring"
aClasses +	[	:name = "GListWidget" ,
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
		] 
aClasses +	[	:name = "GTreeView" ,
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
		] 
aClasses +	[	:name = "GTreeWidget" ,
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
		] 
aClasses +	[	:name = "GComboBox" ,
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
		] 
aClasses +	[	:name = "GTabWidget" ,
			:realname = "QTabWidget" ,
			:events = [
					[ 	:signal = "currentChanged(int)" ,
						:slot = "currentChangedSlot()" ,
						:event = "currentChanged"
					] ,
					[ 	:signal = "tabCloseRequested(int)" ,
						:slot = "tabCloseRequestedSlot()" ,
						:slotparaconnect = "int",
						:slotparafunction = "int p1",
						:slotparacode = SlotParaGetNumber(),
						:event = "tabCloseRequested"
					]
				  ]
		] 
aClasses +	[	:name = "GTableWidget" ,
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
		] 
aClasses +	[	:name = "GProgressBar" ,
			:realname = "QProgressBar" ,
			:events = [
					[ 	:signal = "valueChanged(int)" ,
						:slot = "valueChangedSlot()" ,
						:event = "valueChanged"
					]
				  ]
		] 
aClasses +	[	:name = "GSpinBox" ,
			:realname = "QSpinBox" ,
			:events = [
					[ 	:signal = "valueChanged(int)" ,
						:slot = "valueChangedSlot()" ,
						:event = "valueChanged"
					]
				  ]
		] 
aClasses +	[	:name = "GSlider" ,
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
		] 
aClasses +	[	:name = "GDial" ,
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
		] 
aClasses +	[	:name = "GWebView" ,
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
		] 
aClasses +	[	:name = "GWebEngineView" ,
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
		] 
aClasses +	[	:name = "GCheckBox" ,
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
		] 
aClasses +	[	:name = "GRadioButton" ,
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
		] 
aClasses +	[	:name = "GButtonGroup" ,
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
		] 
aClasses +	[	:name = "GVideoWidget" ,
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
		] 
aClasses +	[	:name = "GTimer" ,
			:realname = "QTimer" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "timeout()" ,
						:slot = "timeoutSlot()" ,
						:event = "timeout"
					]
				  ]
		] 
aClasses +	[	:name = "GTcpServer" ,
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
		] 
aClasses +	[	:name = "GIODevice" ,
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
		] 
aClasses +	[	:name = "GAbstractSocket" ,
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
		] 
aClasses +	[	:name = "GTcpSocket" ,
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
		]
aClasses +	[	:name = "GColorDialog" ,
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
aClasses +	[	:name = "GNetworkAccessManager" ,
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
		]
aClasses +	[	:name = "GThread" ,
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
		]
aClasses +	[	:name = "GPlainTextEdit" ,
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
		] 
aClasses +	[	:name = "GHeaderView" ,
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
		] 
aClasses +	[	:name = "GProcess" ,
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
		]
aClasses +	[	:name = "GToolButton" ,
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
		]
aClasses +	[	:name = "GSerialPort" ,
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
		]
aClasses +	[	:name = "GBluetoothDeviceDiscoveryAgent" ,
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
		]
aClasses +	[	:name = "GBluetoothLocalDevice" ,
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
		]
aClasses +	[	:name = "GBluetoothServer" ,
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
		]
aClasses +	[	:name = "GBluetoothServiceDiscoveryAgent" ,
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
		]
aClasses +	[	:name = "GBluetoothSocket" ,
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
		]
aClasses +	[	:name = "GBluetoothTransferManager" ,
			:realname = "QBluetoothTransferManager" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "finished(QBluetoothTransferReply *)" ,
						:slot = "finishedSlot()" ,
						:event = "finished"
					]
				]
		]
aClasses +	[	:name = "GBluetoothTransferReply" ,
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
		]
aClasses +	[	:name = "GWindow" ,
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
		]
aClasses +	[	:name = "GGuiApplication" ,
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
		]
aClasses +	[	:name = "GTextBrowser" ,
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
		]
aClasses +	[	:name = "GDockWidget" ,
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
		]
aClasses +	[	:name = "GStackedWidget" ,
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
		]
aClasses +	[	:name = "GCalendarWidget" ,
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
		]
aClasses +	[	:name = "GTabBar" ,
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
		]
aClasses +	[	:name = "GQuickWidget" ,
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
aClasses +	[	:name = "GDrag" ,
			:realname = "QDrag" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "actionChanged(Qt::DropAction)" ,
						:slot = "actionChangedSlot()" ,
						:event = "actionChanged"
					],
					[ 	:signal = "targetChanged(QObject *)" ,
						:slot = "targetChangedSlot()" ,
						:event = "targetChanged"
					]
			]
		]
aClasses +	[	:name = "GGeoPositionInfoSource" ,
			:realname = "QGeoPositionInfoSource" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "error(QGeoPositionInfoSource::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "positionUpdated(const QGeoPositionInfo)" ,
						:slot = "positionUpdatedSlot()" ,
						:event = "positionUpdated"
					],
					[ 	:signal = "updateTimeout()" ,
						:slot = "updateTimeoutSlot()" ,
						:event = "updateTimeout"
					]
			]
		]
	    
