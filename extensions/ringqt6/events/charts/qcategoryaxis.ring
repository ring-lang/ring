aClasses + [
		:name = "GCategoryAxis" ,
		:realname = "QCategoryAxis" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "categoriesChanged()" ,
					:slot = "categoriesChangedSlot()" ,
					:event = "categoriesChanged"
				],
				[ 	:signal = "labelsPositionChanged(QCategoryAxis::AxisLabelsPosition)" ,
					:slot = "labelsPositionChangedSlot()" ,
					:event = "labelsPositionChanged"
				]
		]
	]
