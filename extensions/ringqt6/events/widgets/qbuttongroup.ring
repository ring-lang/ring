aClasses +	[	:name = "GButtonGroup" ,
			:realname = "QButtonGroup" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "buttonClicked(int)" ,
						:slot = "buttonClickedSlot()" ,
						:event = "buttonClicked"
					] ,
					[ 	:signal = "buttonPressed(int)" ,
						:slot = "buttonPressedSlot()" ,
						:event = "buttonPressed"
					] ,
					[ 	:signal = "buttonReleased(int)" ,
						:slot = "buttonReleasedSlot()" ,
						:event = "buttonReleased"
					]
				  ]
		] 
