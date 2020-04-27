aClasses + [
		:name = "GHBarModelMapper" ,
		:realname = "QtCharts::QHBarModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "columnCountChanged()" ,
					:slot = "columnCountChangedSlot()" ,
					:event = "columnCountChanged"
				],
				[ 	:signal = "firstBarSetRowChanged()" ,
					:slot = "firstBarSetRowChangedSlot()" ,
					:event = "firstBarSetRowChanged"
				],
				[ 	:signal = "firstColumnChanged()" ,
					:slot = "firstColumnChangedSlot()" ,
					:event = "firstColumnChanged"
				],
				[ 	:signal = "lastBarSetRowChanged()" ,
					:slot = "lastBarSetRowChangedSlot()" ,
					:event = "lastBarSetRowChanged"
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
