aClasses + [
		:name = "GGraphicsWidget" ,
		:realname = "QGraphicsWidget" ,
		:headerfile = "",
		:initpara = "QGraphicsItem *x,Qt::WindowFlags ",
		:initparaparent = "x,",
		:events = [
				[ 	:signal = "geometryChanged()" ,
					:slot = "geometryChangedSlot()" ,
					:event = "geometryChanged"
				],
				[ 	:signal = "layoutChanged()" ,
					:slot = "layoutChangedSlot()" ,
					:event = "layoutChanged"
				]
		]
	]