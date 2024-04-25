aClasses + [
		:name = "GGraphicsScene" ,
		:realname = "QGraphicsScene" ,
		:headerfile = "QtWidgets",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "changed(const QList<QRectF>)" ,
					:slot = "changedSlot()" ,
					:event = "changed"
				],
				[ 	:signal = "focusItemChanged(QGraphicsItem *,QGraphicsItem *,Qt::FocusReason)" ,
					:slot = "focusItemChangedSlot()" ,
					:event = "focusItemChanged"
				],
				[ 	:signal = "sceneRectChanged(const QRectF)" ,
					:slot = "sceneRectChangedSlot()" ,
					:event = "sceneRectChanged"
				],
				[ 	:signal = "selectionChanged()" ,
					:slot = "selectionChangedSlot()" ,
					:event = "selectionChanged"
				]
		]
	]