aClasses + [
		:name = "GCandlestickModelMapper" ,
		:realname = "QtCharts::QCandlestickModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
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
