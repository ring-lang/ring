aClasses = []

load "qpushbutton.ring"
load "qaction.ring"
load "qlineedit.ring"
load "qtextedit.ring"
load "qlistwidget.ring"
load "qtreeview.ring"
load "qtreewidget.ring"
load "qcombobox.ring"
load "qtabwidget.ring"
load "qtablewidget.ring"
load "qprogressbar.ring"
load "qspinbox.ring"
load "qslider.ring"
load "qdial.ring"
load "qwebview.ring"
load "qwebengineview.ring"
load "qcheckbox.ring"
load "qradiobutton.ring"
load "qbuttongroup.ring"
load "qvideowidget.ring"
load "qtimer.ring"
load "qtcpserver.ring"
load "qiodevice.ring"
load "qabstractsocket.ring"
load "qobject.ring"
load "qcolordialog.ring"
load "qnetworkaccessmanager.ring"
load "qthread.ring"
load "qplaintextedit.ring"
load "qheaderview.ring"
load "qprocess.ring"

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
	    
