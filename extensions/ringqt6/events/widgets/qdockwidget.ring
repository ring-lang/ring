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
