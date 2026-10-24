aClasses + [
		:name = "GCandlestickSeries" ,
		:realname = "QtCharts::QCandlestickSeries" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "bodyOutlineVisibilityChanged()" ,
					:slot = "bodyOutlineVisibilityChangedSlot()" ,
					:event = "bodyOutlineVisibilityChanged"
				],
				[ 	:signal = "bodyWidthChanged()" ,
					:slot = "bodyWidthChangedSlot()" ,
					:event = "bodyWidthChanged"
				],
				[ 	:signal = "brushChanged()" ,
					:slot = "brushChangedSlot()" ,
					:event = "brushChanged"
				],
				[ 	:signal = "candlestickSetsAdded(const QList<QCandlestickSet *>)" ,
					:slot = "candlestickSetsAddedSlot()" ,
					:event = "candlestickSetsAdded"
				],
				[ 	:signal = "candlestickSetsRemoved(const QList<QCandlestickSet *>)" ,
					:slot = "candlestickSetsRemovedSlot()" ,
					:event = "candlestickSetsRemoved"
				],
				[ 	:signal = "capsVisibilityChanged()" ,
					:slot = "capsVisibilityChangedSlot()" ,
					:event = "capsVisibilityChanged"
				],
				[ 	:signal = "capsWidthChanged()" ,
					:slot = "capsWidthChangedSlot()" ,
					:event = "capsWidthChanged"
				],
				[ 	:signal = "clicked(QCandlestickSet *)" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "countChanged()" ,
					:slot = "countChangedSlot()" ,
					:event = "countChanged"
				],
				[ 	:signal = "decreasingColorChanged()" ,
					:slot = "decreasingColorChangedSlot()" ,
					:event = "decreasingColorChanged"
				],
				[ 	:signal = "doubleClicked(QCandlestickSet *)" ,
					:slot = "doubleClickedSlot()" ,
					:event = "doubleClicked"
				],
				[ 	:signal = "hovered(bool,QCandlestickSet *)" ,
					:slot = "hoveredSlot()" ,
					:event = "hovered"
				],
				[ 	:signal = "increasingColorChanged()" ,
					:slot = "increasingColorChangedSlot()" ,
					:event = "increasingColorChanged"
				],
				[ 	:signal = "maximumColumnWidthChanged()" ,
					:slot = "maximumColumnWidthChangedSlot()" ,
					:event = "maximumColumnWidthChanged"
				],
				[ 	:signal = "minimumColumnWidthChanged()" ,
					:slot = "minimumColumnWidthChangedSlot()" ,
					:event = "minimumColumnWidthChanged"
				],
				[ 	:signal = "penChanged()" ,
					:slot = "penChangedSlot()" ,
					:event = "penChanged"
				],
				[ 	:signal = "pressed(QCandlestickSet *)" ,
					:slot = "pressedSlot()" ,
					:event = "pressed"
				],
				[ 	:signal = "released(QCandlestickSet *)" ,
					:slot = "releasedSlot()" ,
					:event = "released"
				]
		]
	]
