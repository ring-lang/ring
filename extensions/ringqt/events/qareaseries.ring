aClasses + [
		:name = "GAreaSeries" ,
		:realname = "QtCharts::QAreaSeries" ,
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "borderColorChanged(QColor)" ,
					:slot = "borderColorChangedSlot()" ,
					:event = "borderColorChanged"
				],
				[ 	:signal = "clicked(const QPointF)" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "colorChanged(QColor)" ,
					:slot = "colorChangedSlot()" ,
					:event = "colorChanged"
				],
				[ 	:signal = "doubleClicked(const QPointF)" ,
					:slot = "doubleClickedSlot()" ,
					:event = "doubleClicked"
				],
				[ 	:signal = "hovered(const QPointF,bool)" ,
					:slot = "hoveredSlot()" ,
					:event = "hovered"
				],
				[ 	:signal = "pointLabelsClippingChanged(bool)" ,
					:slot = "pointLabelsClippingChangedSlot()" ,
					:event = "pointLabelsClippingChanged"
				],
				[ 	:signal = "pointLabelsColorChanged(const QColor)" ,
					:slot = "pointLabelsColorChangedSlot()" ,
					:event = "pointLabelsColorChanged"
				],
				[ 	:signal = "pointLabelsFontChanged(const QFont)" ,
					:slot = "pointLabelsFontChangedSlot()" ,
					:event = "pointLabelsFontChanged"
				],
				[ 	:signal = "pointLabelsFormatChanged(const QString)" ,
					:slot = "pointLabelsFormatChangedSlot()" ,
					:event = "pointLabelsFormatChanged"
				],
				[ 	:signal = "pointLabelsVisibilityChanged(bool)" ,
					:slot = "pointLabelsVisibilityChangedSlot()" ,
					:event = "pointLabelsVisibilityChanged"
				],
				[ 	:signal = "pressed(const QPointF)" ,
					:slot = "pressedSlot()" ,
					:event = "pressed"
				],
				[ 	:signal = "released(const QPointF)" ,
					:slot = "releasedSlot()" ,
					:event = "released"
				]
		]
	]
