aClasses + [
		:name = "GHBoxPlotModelMapper" ,
		:realname = "QtCharts::QHBoxPlotModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "columnCountChanged()" ,
					:slot = "columnCountChangedSlot()" ,
					:event = "columnCountChanged"
				],
				[ 	:signal = "firstBoxSetRowChanged()" ,
					:slot = "firstBoxSetRowChangedSlot()" ,
					:event = "firstBoxSetRowChanged"
				],
				[ 	:signal = "firstColumnChanged()" ,
					:slot = "firstColumnChangedSlot()" ,
					:event = "firstColumnChanged"
				],
				[ 	:signal = "lastBoxSetRowChanged()" ,
					:slot = "lastBoxSetRowChangedSlot()" ,
					:event = "lastBoxSetRowChanged"
				],
				[ 	:signal = "modelReplaced()" ,
					:slot = "modelReplacedSlot()" ,
					:event = "modelReplaced"
				],
				[ 	:signal = "seriesReplaced()" ,
					:slot = "seriesReplacedSlot()" ,
					:event = "seriesReplaced"
				]
		]
	]
