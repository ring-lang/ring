aClasses + [
		:name = "GVPieModelMapper" ,
		:realname = "QtCharts::QVPieModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "firstRowChanged()" ,
					:slot = "firstRowChangedSlot()" ,
					:event = "firstRowChanged"
				],
				[ 	:signal = "labelsColumnChanged()" ,
					:slot = "labelsColumnChangedSlot()" ,
					:event = "labelsColumnChanged"
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
				],
				[ 	:signal = "valuesColumnChanged()" ,
					:slot = "valuesColumnChangedSlot()" ,
					:event = "valuesColumnChanged"
				]
		]
	]