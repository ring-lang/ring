aClasses + [
		:name = "GHCandlestickModelMapper" ,
		:realname = "QtCharts::QHCandlestickModelMapper" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "closeColumnChanged()" ,
					:slot = "closeColumnChangedSlot()" ,
					:event = "closeColumnChanged"
				],
				[ 	:signal = "firstSetRowChanged()" ,
					:slot = "firstSetRowChangedSlot()" ,
					:event = "firstSetRowChanged"
				],
				[ 	:signal = "highColumnChanged()" ,
					:slot = "highColumnChangedSlot()" ,
					:event = "highColumnChanged"
				],
				[ 	:signal = "lastSetRowChanged()" ,
					:slot = "lastSetRowChangedSlot()" ,
					:event = "lastSetRowChanged"
				],
				[ 	:signal = "lowColumnChanged()" ,
					:slot = "lowColumnChangedSlot()" ,
					:event = "lowColumnChanged"
				],
				[ 	:signal = "openColumnChanged()" ,
					:slot = "openColumnChangedSlot()" ,
					:event = "openColumnChanged"
				],
				[ 	:signal = "timestampColumnChanged()" ,
					:slot = "timestampColumnChangedSlot()" ,
					:event = "timestampColumnChanged"
				]
		]
	]
