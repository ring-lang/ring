aClasses + [
		:name = "GAbstractSeries" ,
		:realname = "QAbstractSeries" ,
		:initpara = "QAbstractSeriesPrivate &",
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
