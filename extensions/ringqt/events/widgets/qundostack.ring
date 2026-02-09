aClasses +	[	:name = "GUndoStack" ,
			:realname = "QUndoStack" ,
			:events = [
					[ 	:signal = "canRedoChanged(bool)" ,
						:slot = "canRedoChangedSlot()" ,
						:event = "canRedoChanged"
					] ,
					[ 	:signal = "canUndoChanged(bool)" ,
						:slot = "canUndoChangedSlot()" ,
						:event = "canUndoChanged"
					] ,
					[ 	:signal = "cleanChanged(bool)" ,
						:slot = "cleanChangedSlot()" ,
						:event = "cleanChanged"
					] ,
					[ 	:signal = "indexChanged(int)" ,
						:slot = "indexChangedSlot()" ,
						:event = "indexChanged"
					] ,
					[ 	:signal = "redoTextChanged(QString)" ,
						:slot = "redoTextChangedSlot()" ,
						:event = "redoTextChanged"
					] ,
					[ 	:signal = "undoTextChanged(QString)" ,
						:slot = "undoTextChangedSlot()" ,
						:event = "undoTextChanged"
					]
				  ]
		] 
