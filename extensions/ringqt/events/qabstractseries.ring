aClasses + [
		:name = "GAbstractSeries" ,
		:realname = "QtCharts::QAbstractSeries" ,
		:initpara = "QtCharts::QAbstractSeriesPrivate &",
		:events = [
				[ 	:signal = "nameChanged()" ,
					:slot = "nameChangedSlot()" ,
					:event = "nameChanged"
				],
				[ 	:signal = "opacityChanged()" ,
					:slot = "opacityChangedSlot()" ,
					:event = "opacityChanged"
				],
				[ 	:signal = "useOpenGLChanged()" ,
					:slot = "useOpenGLChangedSlot()" ,
					:event = "useOpenGLChanged"
				],
				[ 	:signal = "visibleChanged()" ,
					:slot = "visibleChangedSlot()" ,
					:event = "visibleChanged"
				]
		]
	]
