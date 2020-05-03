aClasses + [
		:name = "GVCandlestickModelMapper" ,
		:realname = "QtCharts::QVCandlestickModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "closeRowChanged()" ,
					:slot = "closeRowChangedSlot()" ,
					:event = "closeRowChanged"
				],
				[ 	:signal = "firstSetColumnChanged()" ,
					:slot = "firstSetColumnChangedSlot()" ,
					:event = "firstSetColumnChanged"
				],
				[ 	:signal = "highRowChanged()" ,
					:slot = "highRowChangedSlot()" ,
					:event = "highRowChanged"
				],
				[ 	:signal = "lastSetColumnChanged()" ,
					:slot = "lastSetColumnChangedSlot()" ,
					:event = "lastSetColumnChanged"
				],
				[ 	:signal = "lowRowChanged()" ,
					:slot = "lowRowChangedSlot()" ,
					:event = "lowRowChanged"
				],
				[ 	:signal = "openRowChanged()" ,
					:slot = "openRowChangedSlot()" ,
					:event = "openRowChanged"
				],
				[ 	:signal = "timestampRowChanged()" ,
					:slot = "timestampRowChangedSlot()" ,
					:event = "timestampRowChanged"
				]
		]
	]