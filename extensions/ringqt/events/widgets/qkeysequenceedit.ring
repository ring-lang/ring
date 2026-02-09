aClasses +	[	:name = "GKeySequenceEdit" ,
			:realname = "QKeySequenceEdit" ,
			:events = [
					[ 	:signal = "editingFinished()" ,
						:slot = "editingFinishedSlot()" ,
						:event = "editingFinished"
					] ,
					[ 	:signal = "keySequenceChanged(QKeySequence)" ,
						:slot = "keySequenceChangedSlot()" ,
						:event = "keySequenceChanged"
					]
				  ]
		] 
