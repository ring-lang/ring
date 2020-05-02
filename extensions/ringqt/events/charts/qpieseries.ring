aClasses + [
		:name = "GPieSeries" ,
		:realname = "QtCharts::QPieSeries" ,
		:headerfile = "QtCharts",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "added(QList<QPieSlice *>)" ,
					:slot = "addedSlot()" ,
					:event = "added"
				],
				[ 	:signal = "clicked(QPieSlice *)" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "countChanged()" ,
					:slot = "countChangedSlot()" ,
					:event = "countChanged"
				],
				[ 	:signal = "doubleClicked(QPieSlice *)" ,
					:slot = "doubleClickedSlot()" ,
					:event = "doubleClicked"
				],
				[ 	:signal = "hovered(QPieSlice *,bool)" ,
					:slot = "hoveredSlot()" ,
					:event = "hovered"
				],
				[ 	:signal = "pressed(QPieSlice *)" ,
					:slot = "pressedSlot()" ,
					:event = "pressed"
				],
				[ 	:signal = "released(QPieSlice *)" ,
					:slot = "releasedSlot()" ,
					:event = "released"
				],
				[ 	:signal = "removed(QList<QPieSlice *>)" ,
					:slot = "removedSlot()" ,
					:event = "removed"
				],
				[ 	:signal = "sumChanged()" ,
					:slot = "sumChangedSlot()" ,
					:event = "sumChanged"
				]
		]
	]