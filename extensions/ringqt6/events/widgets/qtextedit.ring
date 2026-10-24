aClasses +	[	:name = "GTextEdit" ,
			:realname = "QTextEdit" ,
			:events = [
					[ 	:signal = "copyAvailable(bool)" ,
						:slot = "copyAvailableSlot()" ,
						:event = "copyAvailable"
					] ,
					[ 	:signal = "currentCharFormatChanged(QTextCharFormat)" ,
						:slot = "currentCharFormatChangedSlot()" ,
						:event = "currentCharFormatChanged"
					] ,
					[ 	:signal = "cursorPositionChanged()" ,
						:slot = "cursorPositionChangedSlot()" ,
						:event = "cursorPositionChanged"
					] ,
					[ 	:signal = "redoAvailable(bool)" ,
						:slot = "redoAvailableSlot()" ,
						:event = "redoAvailable"
					] ,
					[ 	:signal = "selectionChanged()" ,
						:slot = "selectionChanged()" ,
						:event = "selectionChanged"
					] ,
					[ 	:signal = "textChanged()" ,
						:slot = "textChangedSlot()" ,
						:event = "textChanged"
					] ,
					[ 	:signal = "undoAvailable(bool)" ,
						:slot = "undoAvailableSlot()" ,
						:event = "undoAvailable"
					]
				  ]
		] 
