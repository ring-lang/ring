aClasses + [
		:name = "GXYSeries" ,
		:realname = "QtCharts::QXYSeries" ,
		:headerfile = "QtCharts",
		:initpara = "QtCharts::QXYSeriesPrivate &",
		:events = [
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
				[ 	:signal = "penChanged(const QPen)" ,
					:slot = "penChangedSlot()" ,
					:event = "penChanged"
				],
				[ 	:signal = "pointAdded(int)" ,
					:slot = "pointAddedSlot()" ,
					:event = "pointAdded"
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
				[ 	:signal = "pointRemoved(int)" ,
					:slot = "pointRemovedSlot()" ,
					:event = "pointRemoved"
				],
				[ 	:signal = "pointReplaced(int)" ,
					:slot = "pointReplacedSlot()" ,
					:event = "pointReplaced"
				],
				[ 	:signal = "pointsRemoved(int,int)" ,
					:slot = "pointsRemovedSlot()" ,
					:event = "pointsRemoved"
				],
				[ 	:signal = "pointsReplaced()" ,
					:slot = "pointsReplacedSlot()" ,
					:event = "pointsReplaced"
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