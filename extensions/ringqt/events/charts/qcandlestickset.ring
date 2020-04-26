aClasses + [
		:name = "GCandlestickSet" ,
		:realname = "QtCharts::QCandlestickSet" ,
		:headerfile = "QtCharts",
		:initpara = "qreal x,QObject *",
		:initparaparent = "x,",
		:events = [
				[ 	:signal = "brushChanged()" ,
					:slot = "brushChangedSlot()" ,
					:event = "brushChanged"
				],
				[ 	:signal = "clicked()" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "closeChanged()" ,
					:slot = "closeChangedSlot()" ,
					:event = "closeChanged"
				],
				[ 	:signal = "doubleClicked()" ,
					:slot = "doubleClickedSlot()" ,
					:event = "doubleClicked"
				],
				[ 	:signal = "highChanged()" ,
					:slot = "highChangedSlot()" ,
					:event = "highChanged"
				],
				[ 	:signal = "hovered(bool)" ,
					:slot = "hoveredSlot()" ,
					:event = "hovered"
				],
				[ 	:signal = "lowChanged()" ,
					:slot = "lowChangedSlot()" ,
					:event = "lowChanged"
				],
				[ 	:signal = "openChanged()" ,
					:slot = "openChangedSlot()" ,
					:event = "openChanged"
				],
				[ 	:signal = "penChanged()" ,
					:slot = "penChangedSlot()" ,
					:event = "penChanged"
				],
				[ 	:signal = "pressed()" ,
					:slot = "pressedSlot()" ,
					:event = "pressed"
				],
				[ 	:signal = "released()" ,
					:slot = "releasedSlot()" ,
					:event = "released"
				],
				[ 	:signal = "timestampChanged()" ,
					:slot = "timestampChangedSlot()" ,
					:event = "timestampChanged"
				]
		]
	]
