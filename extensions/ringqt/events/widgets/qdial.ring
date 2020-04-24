aClasses +	[	:name = "GDial" ,
			:realname = "QDial" ,
			:events = [
					[ 	:signal = "actionTriggered(int)" ,
						:slot = "actionTriggeredSlot()" ,
						:event = "actionTriggered"
					] ,
					[ 	:signal = "rangeChanged(int,int)" ,
						:slot = "rangeChangedSlot()" ,
						:event = "rangeChanged"
					] ,
					[ 	:signal = "sliderMoved(int)" ,
						:slot = "sliderMovedSlot()" ,
						:event = "sliderMoved"
					] ,
					[ 	:signal = "sliderPressed()" ,
						:slot = "sliderPressedSlot()" ,
						:event = "sliderPressed"
					] ,
					[ 	:signal = "sliderReleased()" ,
						:slot = "sliderReleasedSlot()" ,
						:event = "sliderReleased"
					] ,
					[ 	:signal = "valueChanged(int)" ,
						:slot = "valueChangedSlot()" ,
						:event = "valueChanged"
					]
				  ]
		] 
