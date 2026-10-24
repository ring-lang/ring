aClasses + [
		:name = "GScatterSeries" ,
		:realname = "QtCharts::QScatterSeries" ,
		:headerfile = "QtCharts",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "borderColorChanged(QColor)" ,
					:slot = "borderColorChangedSlot()" ,
					:event = "borderColorChanged"
				],
				[ 	:signal = "colorChanged(QColor)" ,
					:slot = "colorChangedSlot()" ,
					:event = "colorChanged"
				],
				[ 	:signal = "markerShapeChanged(QScatterSeries::MarkerShape)" ,
					:slot = "markerShapeChangedSlot()" ,
					:event = "markerShapeChanged"
				],
				[ 	:signal = "markerSizeChanged(qreal)" ,
					:slot = "markerSizeChangedSlot()" ,
					:event = "markerSizeChanged"
				]
		]
	]