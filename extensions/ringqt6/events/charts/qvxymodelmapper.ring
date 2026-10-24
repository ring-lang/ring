aClasses + [
		:name = "GVXYModelMapper" ,
		:realname = "QtCharts::QVXYModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "firstRowChanged()" ,
					:slot = "firstRowChangedSlot()" ,
					:event = "firstRowChanged"
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
				[ 	:signal = "xColumnChanged()" ,
					:slot = "xColumnChangedSlot()" ,
					:event = "xColumnChanged"
				],
				[ 	:signal = "yColumnChanged()" ,
					:slot = "yColumnChangedSlot()" ,
					:event = "yColumnChanged"
				]
		]
	]