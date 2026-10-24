aClasses + [
		:name = "GLegendMarker" ,
		:realname = "QtCharts::QLegendMarker" ,
		:initpara = "QtCharts::QLegendMarkerPrivate &",
		:headerfile = "QtCharts",
		:events = [
				[ 	:signal = "brushChanged()" ,
					:slot = "brushChangedSlot()" ,
					:event = "brushChanged"
				],
				[ 	:signal = "clicked()" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "fontChanged()" ,
					:slot = "fontChangedSlot()" ,
					:event = "fontChanged"
				],
				[ 	:signal = "hovered(bool)" ,
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
				[ 	:signal = "penChanged()" ,
					:slot = "penChangedSlot()" ,
					:event = "penChanged"
				],
				[ 	:signal = "shapeChanged()" ,
					:slot = "shapeChangedSlot()" ,
					:event = "shapeChanged"
				],
				[ 	:signal = "visibleChanged()" ,
					:slot = "visibleChangedSlot()" ,
					:event = "visibleChanged"
				]
		]
	]