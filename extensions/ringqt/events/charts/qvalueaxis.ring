aClasses + [
		:name = "GValueAxis" ,
		:realname = "QtCharts::QValueAxis" ,
		:headerfile = "QtCharts",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
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
				[ 	:signal = "tickAnchorChanged(qreal)" ,
					:slot = "tickAnchorChangedSlot()" ,
					:event = "tickAnchorChanged"
				],
				[ 	:signal = "tickCountChanged(int)" ,
					:slot = "tickCountChangedSlot()" ,
					:event = "tickCountChanged"
				],
				[ 	:signal = "tickIntervalChanged(qreal)" ,
					:slot = "tickIntervalChangedSlot()" ,
					:event = "tickIntervalChanged"
				],
				[ 	:signal = "tickTypeChanged(QValueAxis::TickType)" ,
					:slot = "tickTypeChangedSlot()" ,
					:event = "tickTypeChanged"
				]
		]
	]