aClasses + [
		:name = "GBarSet" ,
		:realname = "QtCharts::QBarSet" ,
		:headerfile = "QtCharts",
		:initpara = "const QString x,QObject *",
		:initparaparent = "x,",
		:events = [
				[ 	:signal = "borderColorChanged(QColor)" ,
					:slot = "borderColorChangedSlot()" ,
					:event = "borderColorChanged"
				],
				[ 	:signal = "brushChanged()" ,
					:slot = "brushChangedSlot()" ,
					:event = "brushChanged"
				],
				[ 	:signal = "clicked(int)" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "colorChanged(QColor)" ,
					:slot = "colorChangedSlot()" ,
					:event = "colorChanged"
				],
				[ 	:signal = "doubleClicked(int)" ,
					:slot = "doubleClickedSlot()" ,
					:event = "doubleClicked"
				],
				[ 	:signal = "hovered(bool,int)" ,
					:slot = "hoveredSlot()" ,
					:event = "hovered"
				],
				[ 	:signal = "labelBrushChanged()" ,
					:slot = "labelBrushChangedSlot()" ,
					:event = "labelBrushChanged"
				],
				[ 	:signal = "labelChanged()" ,
					:slot = "labelChangedSlot()" ,
					:event = "labelChanged"
				],
				[ 	:signal = "labelColorChanged(QColor)" ,
					:slot = "labelColorChangedSlot()" ,
					:event = "labelColorChanged"
				],
				[ 	:signal = "labelFontChanged()" ,
					:slot = "labelFontChangedSlot()" ,
					:event = "labelFontChanged"
				],
				[ 	:signal = "penChanged()" ,
					:slot = "penChangedSlot()" ,
					:event = "penChanged"
				],
				[ 	:signal = "pressed(int)" ,
					:slot = "pressedSlot()" ,
					:event = "pressed"
				],
				[ 	:signal = "released(int)" ,
					:slot = "releasedSlot()" ,
					:event = "released"
				],
				[ 	:signal = "valueChanged(int)" ,
					:slot = "valueChangedSlot()" ,
					:event = "valueChanged"
				],
				[ 	:signal = "valuesAdded(int,int)" ,
					:slot = "valuesAddedSlot()" ,
					:event = "valuesAdded"
				],
				[ 	:signal = "valuesRemoved(int,int)" ,
					:slot = "valuesRemovedSlot()" ,
					:event = "valuesRemoved"
				]
		]
	]
