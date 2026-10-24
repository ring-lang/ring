aClasses +	[	:name = "GCheckBox" ,
			:realname = "QCheckBox" ,
			:events = [
					[ 	:signal = "stateChanged(int)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					] ,
					[ 	:signal = "clicked(bool)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					] ,
					[ 	:signal = "pressed()" ,
						:slot = "pressedSlot()" ,
						:event = "pressed"
					] ,
					[ 	:signal = "released()" ,
						:slot = "releasedSlot()" ,
						:event = "released"
					] ,
					[ 	:signal = "toggled(bool)" ,
						:slot = "toggledSlot()" ,
						:event = "toggled"
					]
				  ]
		] 
