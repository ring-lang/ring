aClasses +	[	:name = "GPlainTextEdit" ,
			:realname = "QPlainTextEdit" ,
			:events = [
					[ 	:signal = "blockCountChanged(int)" ,
						:slot = "blockCountChangedSlot()" ,
						:event = "blockCountChanged"
					] ,
					[ 	:signal = "copyAvailable(bool)" ,
						:slot = "copyAvailableSlot()" ,
						:event = "copyAvailable"
					] ,
					[ 	:signal = "cursorPositionChanged()" ,
						:slot = "cursorPositionChangedSlot()" ,
						:event = "cursorPositionChanged"
					] ,
					[ 	:signal = "modificationChanged(bool)" ,
						:slot = "modificationChangedSlot()" ,
						:event = "modificationChanged"
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
					],
					[ 	:signal = "updateRequest(const QRect, int)" ,
						:slot = "updateRequestSlot()" ,
						:event = "updateRequest"
					]
				  ]
		] 
