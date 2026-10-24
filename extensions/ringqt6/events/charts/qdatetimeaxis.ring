aClasses + [
		:name = "GDateTimeAxis" ,
		:realname = "QtCharts::QDateTimeAxis" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "formatChanged(QString)" ,
					:slot = "formatChangedSlot()" ,
					:event = "formatChanged"
				],
				[ 	:signal = "maxChanged(QDateTime)" ,
					:slot = "maxChangedSlot()" ,
					:event = "maxChanged"
				],
				[ 	:signal = "minChanged(QDateTime)" ,
					:slot = "minChangedSlot()" ,
					:event = "minChanged"
				],
				[ 	:signal = "rangeChanged(QDateTime,QDateTime)" ,
					:slot = "rangeChangedSlot()" ,
					:event = "rangeChanged"
				],
				[ 	:signal = "tickCountChanged(int)" ,
					:slot = "tickCountChangedSlot()" ,
					:event = "tickCountChanged"
				]
		]
	]
