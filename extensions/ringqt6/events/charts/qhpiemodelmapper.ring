aClasses + [
		:name = "GHPieModelMapper" ,
		:realname = "QtCharts::QHPieModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "columnCountChanged()" ,
					:slot = "columnCountChangedSlot()" ,
					:event = "columnCountChanged"
				],
				[ 	:signal = "firstColumnChanged()" ,
					:slot = "firstColumnChangedSlot()" ,
					:event = "firstColumnChanged"
				],
				[ 	:signal = "labelsRowChanged()" ,
					:slot = "labelsRowChangedSlot()" ,
					:event = "labelsRowChanged"
				],
				[ 	:signal = "modelReplaced()" ,
					:slot = "modelReplacedSlot()" ,
					:event = "modelReplaced"
				],
				[ 	:signal = "seriesReplaced()" ,
					:slot = "seriesReplacedSlot()" ,
					:event = "seriesReplaced"
				],
				[ 	:signal = "valuesRowChanged()" ,
					:slot = "valuesRowChangedSlot()" ,
					:event = "valuesRowChanged"
				]
		]
	]
