aClasses + [
		:name = "GAbstractBarSeries" ,
		:realname = "QtCharts::QAbstractBarSeries" ,
		:initpara = "QtCharts::QAbstractBarSeriesPrivate &",
		:events = [
				[ 	:signal = "barsetsAdded(QList<QBarSet *>)" ,
					:slot = "barsetsAddedSlot()" ,
					:event = "barsetsAdded"
				],
				[ 	:signal = "barsetsRemoved(QList<QBarSet *>)" ,
					:slot = "barsetsRemovedSlot()" ,
					:event = "barsetsRemoved"
				],
				[ 	:signal = "clicked(int,QBarSet *)" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "countChanged()" ,
					:slot = "countChangedSlot()" ,
					:event = "countChanged"
				],
				[ 	:signal = "doubleClicked(int,QBarSet *)" ,
					:slot = "doubleClickedSlot()" ,
					:event = "doubleClicked"
				],
				[ 	:signal = "hovered(bool,int,QBarSet *)" ,
					:slot = "hoveredSlot()" ,
					:event = "hovered"
				],
				[ 	:signal = "labelsAngleChanged(qreal)" ,
					:slot = "labelsAngleChangedSlot()" ,
					:event = "labelsAngleChanged"
				],
				[ 	:signal = "labelsFormatChanged(const QString)" ,
					:slot = "labelsFormatChangedSlot()" ,
					:event = "labelsFormatChanged"
				],
				[ 	:signal = "labelsPositionChanged(QAbstractBarSeries::LabelsPosition)" ,
					:slot = "labelsPositionChangedSlot()" ,
					:event = "labelsPositionChanged"
				],
				[ 	:signal = "labelsPrecisionChanged(int)" ,
					:slot = "labelsPrecisionChangedSlot()" ,
					:event = "labelsPrecisionChanged"
				],
				[ 	:signal = "labelsVisibleChanged()" ,
					:slot = "labelsVisibleChangedSlot()" ,
					:event = "labelsVisibleChanged"
				],
				[ 	:signal = "pressed(int,QBarSet *)" ,
					:slot = "pressedSlot()" ,
					:event = "pressed"
				],
				[ 	:signal = "released(int,QBarSet *)" ,
					:slot = "releasedSlot()" ,
					:event = "released"
				]
		]
	]
