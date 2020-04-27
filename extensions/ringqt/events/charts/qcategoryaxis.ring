aClasses + [
		:name = "GCategoryAxis" ,
		:realname = "QtCharts::QCategoryAxis" ,
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
