aClasses +	[	:name = "GListWidget" ,
			:realname = "QListWidget" ,
			:events = [
					[ 	:signal = "currentItemChanged(QListWidgetItem*,QListWidgetItem*)" ,
						:slot = "currentItemChangedSlot()" ,
						:event = "currentItemChanged"
					] ,
					[ 	:signal = "currentRowChanged(int)" ,
						:slot = "currentRowChangedSlot()" ,
						:event = "currentRowChanged"
					] ,
					[ 	:signal = "currentTextChanged(QString)" ,
						:slot = "currentTextChangedSlot()" ,
						:event = "currentTextChanged"
					] ,
					[ 	:signal = "itemActivated(QListWidgetItem*)" ,
						:slot = "itemActivatedSlot()" ,
						:event = "itemActivated"
					] ,
					[ 	:signal = "itemChanged(QListWidgetItem*)" ,
						:slot = "itemChangedSlot()" ,
						:event = "itemChanged"
					] ,
					[ 	:signal = "itemClicked(QListWidgetItem*)" ,
						:slot = "itemClickedSlot()" ,
						:event = "itemClicked"
					] ,
					[ 	:signal = "itemDoubleClicked(QListWidgetItem*)" ,
						:slot = "itemDoubleClickedSlot()" ,
						:event = "itemDoubleClicked"
					] ,
					[ 	:signal = "itemEntered(QListWidgetItem*)" ,
						:slot = "itemEnteredSlot()" ,
						:event = "itemEntered"
					] ,
					[ 	:signal = "itemPressed(QListWidgetItem*)" ,
						:slot = "itemPressedSlot()" ,
						:event = "itemPressed"
					] ,
					[ 	:signal = "itemSelectionChanged()" ,
						:slot = "itemSelectionChangedSlot()" ,
						:event = "itemSelectionChanged"
					]
				  ]
		] 
