aClasses + [
		:name = "GGraphicsTextItem" ,
		:realname = "QGraphicsTextItem" ,
		:headerfile = "",
		:initpara = "QGraphicsItem * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "linkActivated(const QString)" ,
					:slot = "linkActivatedSlot()" ,
					:event = "linkActivated"
				],
				[ 	:signal = "linkHovered(const QString)" ,
					:slot = "linkHoveredSlot()" ,
					:event = "linkHovered"
				]
		]
	]