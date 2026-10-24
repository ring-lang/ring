aClasses + [
		:name = "GBarCategoryAxis" ,
		:realname = "QtCharts::QBarCategoryAxis" ,
		:headerfile = "QtCharts",
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "categoriesChanged()" ,
					:slot = "categoriesChangedSlot()" ,
					:event = "categoriesChanged"
				],
				[ 	:signal = "countChanged()" ,
					:slot = "countChangedSlot()" ,
					:event = "countChanged"
				],
				[ 	:signal = "maxChanged(const QString)" ,
					:slot = "maxChangedSlot()" ,
					:event = "maxChanged"
				],
				[ 	:signal = "minChanged(const QString)" ,
					:slot = "minChangedSlot()" ,
					:event = "minChanged"
				],
				[ 	:signal = "rangeChanged(const QString,const QString)" ,
					:slot = "rangeChangedSlot()" ,
					:event = "rangeChanged"
				]
		]
	]
