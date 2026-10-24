aClasses + [
		:name = "GVBarModelMapper" ,
		:realname = "QtCharts::QVBarModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "firstBarSetColumnChanged()" ,
					:slot = "firstBarSetColumnChangedSlot()" ,
					:event = "firstBarSetColumnChanged"
				],
				[ 	:signal = "firstRowChanged()" ,
					:slot = "firstRowChangedSlot()" ,
					:event = "firstRowChanged"
				],
				[ 	:signal = "lastBarSetColumnChanged()" ,
					:slot = "lastBarSetColumnChangedSlot()" ,
					:event = "lastBarSetColumnChanged"
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