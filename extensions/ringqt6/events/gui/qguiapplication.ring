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
