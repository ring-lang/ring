aClasses + [
		:name = "GColorDialog" ,
		:realname = "QColorDialog" ,
		:initpara = "QWidget *",
		:events = [
				[ 	:signal = "colorSelected(const QColor)" ,
					:slot = "colorSelectedSlot()" ,
					:event = "colorSelected"
				],
				[ 	:signal = "currentColorChanged(const QColor)" ,
					:slot = "currentColorChangedSlot()" ,
					:event = "currentColorChanged"
				]
		]
	]
