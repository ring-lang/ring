aClasses +	[	:name = "GColorDialog" ,
			:realname = "QColorDialog" ,
			:events = [
					[ 	:signal = "colorSelected(QColor)" ,
						:slot = "colorSelectedSlot()" ,
						:event = "colorSelected"
					] ,
					[ 	:signal = "currentColorChanged(QColor)" ,
						:slot = "currentColorChangedSlot()" ,
						:event = "currentColorChanged"
					]
				  ]
		]
