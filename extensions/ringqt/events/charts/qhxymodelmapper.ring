aClasses + [
		:name = "GHXYModelMapper" ,
		:realname = "QtCharts::QHXYModelMapper" ,
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
				[ 	:signal = "modelReplaced()" ,
					:slot = "modelReplacedSlot()" ,
					:event = "modelReplaced"
				],
				[ 	:signal = "seriesReplaced()" ,
					:slot = "seriesReplacedSlot()" ,
					:event = "seriesReplaced"
				],
				[ 	:signal = "xRowChanged()" ,
					:slot = "xRowChangedSlot()" ,
					:event = "xRowChanged"
				],
				[ 	:signal = "yRowChanged()" ,
					:slot = "yRowChangedSlot()" ,
					:event = "yRowChanged"
				]
		]
	]
