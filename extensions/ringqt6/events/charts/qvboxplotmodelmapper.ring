aClasses + [
		:name = "GVBoxPlotModelMapper" ,
		:realname = "QtCharts::QVBoxPlotModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "firstBoxSetColumnChanged()" ,
					:slot = "firstBoxSetColumnChangedSlot()" ,
					:event = "firstBoxSetColumnChanged"
				],
				[ 	:signal = "firstRowChanged()" ,
					:slot = "firstRowChangedSlot()" ,
					:event = "firstRowChanged"
				],
				[ 	:signal = "lastBoxSetColumnChanged()" ,
					:slot = "lastBoxSetColumnChangedSlot()" ,
					:event = "lastBoxSetColumnChanged"
				],
				[ 	:signal = "modelReplaced()" ,
					:slot = "modelReplacedSlot()" ,
					:event = "modelReplaced"
				],
				[ 	:signal = "rowCountChanged()" ,
					:slot = "rowCountChangedSlot()" ,
					:event = "rowCountChanged"
				],
				[ 	:signal = "seriesReplaced()" ,
					:slot = "seriesReplacedSlot()" ,
					:event = "seriesReplaced"
				]
		]
	]