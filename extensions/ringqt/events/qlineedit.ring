aClasses +	[	:name = "GLineEdit" ,
			:realname = "QLineEdit" ,
			:events = [
					[ 	:signal = "textChanged(QString)" ,
						:slot = "textChangedSlot()" ,
						:event = "TextChanged"
					] ,
					[ 	:signal = "cursorPositionChanged(int,int)" ,
						:slot = "cursorPositionChangedSlot()" ,
						:event = "cursorPositionChanged"
					] ,
					[ 	:signal = "editingFinished()" ,
						:slot = "editingFinishedSlot()" ,
						:event = "editingFinished"
					] ,
					[ 	:signal = "returnPressed()" ,
						:slot = "returnPressedSlot()" ,
						:event = "returnPressed"
					] ,
					[ 	:signal = "selectionChanged()" ,
						:slot = "selectionChangedSlot()" ,
						:event = "selectionChanged"
					] ,
					[ 	:signal = "textEdited(QString)" ,
						:slot = "textEditedSlot()" ,
						:event = "textEdited"
					]
				  ]
		] 
