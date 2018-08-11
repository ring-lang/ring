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
