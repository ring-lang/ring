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
load "qtoolbutton.ring"
load "qserialport.ring"
load "qbluetoothdevicediscoveryagent.ring"
load "qbluetoothlocaldevice.ring"
load "qbluetoothserver.ring"
load "qbluetoothservicediscoveryagent.ring"
load "qbluetoothsocket.ring"
load "qbluetoothtransfermanager.ring"
load "qbluetoothtransferreply.ring"
load "qwindow.ring"
load "qguiapplication.ring"
load "qtextbrowser.ring"
load "qdockwidget.ring"

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
	    
