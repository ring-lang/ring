aClasses + [
		:name = "GLogValueAxis" ,
		:realname = "QtCharts::QLogValueAxis" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "baseChanged(qreal)" ,
					:slot = "baseChangedSlot()" ,
					:event = "baseChanged"
				],
				[ 	:signal = "labelFormatChanged(const QString)" ,
					:slot = "labelFormatChangedSlot()" ,
					:event = "labelFormatChanged"
				],
				[ 	:signal = "maxChanged(qreal)" ,
					:slot = "maxChangedSlot()" ,
					:event = "maxChanged"
				],
				[ 	:signal = "minChanged(qreal)" ,
					:slot = "minChangedSlot()" ,
					:event = "minChanged"
				],
				[ 	:signal = "minorTickCountChanged(int)" ,
					:slot = "minorTickCountChangedSlot()" ,
					:event = "minorTickCountChanged"
				],
				[ 	:signal = "rangeChanged(qreal,qreal)" ,
					:slot = "rangeChangedSlot()" ,
					:event = "rangeChanged"
				],
				[ 	:signal = "tickCountChanged(int)" ,
					:slot = "tickCountChangedSlot()" ,
					:event = "tickCountChanged"
				]
		]
	]