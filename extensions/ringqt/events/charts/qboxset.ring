aClasses + [
		:name = "GBoxSet" ,
		:realname = "QtCharts::QBoxSet" ,
		:headerfile = "QtCharts",
		:initpara = "QString x,QObject *",
		:initparaparent = "x,",
		:events = [
				[ 	:signal = "brushChanged()" ,
					:slot = "brushChangedSlot()" ,
					:event = "brushChanged"
				],
				[ 	:signal = "cleared()" ,
					:slot = "clearedSlot()" ,
					:event = "cleared"
				],
				[ 	:signal = "clicked()" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "doubleClicked()" ,
					:slot = "doubleClickedSlot()" ,
					:event = "doubleClicked"
				],
				[ 	:signal = "hovered(bool)" ,
					:slot = "hoveredSlot()" ,
					:event = "hovered"
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
				[ 	:signal = "valueChanged(int)" ,
					:slot = "valueChangedSlot()" ,
					:event = "valueChanged"
				],
				[ 	:signal = "valuesChanged()" ,
					:slot = "valuesChangedSlot()" ,
					:event = "valuesChanged"
				]
		]
	]
