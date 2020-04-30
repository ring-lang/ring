aClasses + [
		:name = "GChart" ,
		:realname = "QtCharts::QChart" ,
		:headerfile = "QtCharts",
		:initpara = "QGraphicsItem *x,Qt::WindowFlags ",
		:initparaparent = "x,",
		:events = [
				[ 	:signal = "plotAreaChanged(const QRectF)" ,
					:slot = "plotAreaChangedSlot()" ,
					:event = "plotAreaChanged"
				]
		]
	]