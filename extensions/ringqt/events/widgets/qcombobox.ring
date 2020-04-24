aClasses +	[	:name = "GComboBox" ,
			:realname = "QComboBox" ,
			:events = [
					[ 	:signal = "activated(int)" ,
						:slot = "activatedSlot()" ,
						:event = "activated"
					] ,
					[ 	:signal = "currentIndexChanged(int)" ,
						:slot = "currentIndexChangedSlot()" ,
						:event = "currentIndexChanged"
					] ,
					[ 	:signal = "editTextChanged(QString)" ,
						:slot = "editTextChangedSlot()" ,
						:event = "editTextChanged"
					] ,
					[ 	:signal = "highlighted(int)" ,
						:slot = "highlightedSlot()" ,
						:event = "highlighted"
					]
				  ]
		] 
