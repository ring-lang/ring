aClasses + [
		:name = "GBoxPlotSeries" ,
		:realname = "QtCharts::QBoxPlotSeries" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "boxOutlineVisibilityChanged()" ,
					:slot = "boxOutlineVisibilityChangedSlot()" ,
					:event = "boxOutlineVisibilityChanged"
				],
				[ 	:signal = "boxWidthChanged()" ,
					:slot = "boxWidthChangedSlot()" ,
					:event = "boxWidthChanged"
				],
				[ 	:signal = "boxsetsAdded(QList<QBoxSet *>)" ,
					:slot = "boxsetsAddedSlot()" ,
					:event = "boxsetsAdded"
				],
				[ 	:signal = "boxsetsRemoved(QList<QBoxSet *>)" ,
					:slot = "boxsetsRemovedSlot()" ,
					:event = "boxsetsRemoved"
				],
				[ 	:signal = "brushChanged()" ,
					:slot = "brushChangedSlot()" ,
					:event = "brushChanged"
				],
				[ 	:signal = "clicked(QBoxSet *)" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "countChanged()" ,
					:slot = "countChangedSlot()" ,
					:event = "countChanged"
				],
				[ 	:signal = "doubleClicked(QBoxSet *)" ,
					:slot = "doubleClickedSlot()" ,
					:event = "doubleClicked"
				],
				[ 	:signal = "hovered(bool,QBoxSet *)" ,
					:slot = "hoveredSlot()" ,
					:event = "hovered"
				],
				[ 	:signal = "penChanged()" ,
					:slot = "penChangedSlot()" ,
					:event = "penChanged"
				],
				[ 	:signal = "pressed(QBoxSet *)" ,
					:slot = "pressedSlot()" ,
					:event = "pressed"
				],
				[ 	:signal = "released(QBoxSet *)" ,
					:slot = "releasedSlot()" ,
					:event = "released"
				]
		]
	]
