aClasses +	[	:name = "GTableWidget" ,
			:realname = "QTableWidget" ,
			:events = [
					[ 	:signal = "cellActivated(int,int)" ,
						:slot = "cellActivatedSlot()" ,
						:event = "cellActivated"
					] ,
					[ 	:signal = "cellChanged(int,int)" ,
						:slot = "cellChangedSlot()" ,
						:event = "cellChanged"
					] ,
					[ 	:signal = "cellClicked(int,int)" ,
						:slot = "cellClickedSlot()" ,
						:event = "cellClicked"
					] ,
					[ 	:signal = "cellDoubleClicked(int,int)" ,
						:slot = "cellDoubleClickedSlot()" ,
						:event = "cellDoubleClicked"
					] ,
					[ 	:signal = "cellEntered(int,int)" ,
						:slot = "cellEnteredSlot()" ,
						:event = "cellEntered"
					] ,
					[ 	:signal = "cellPressed(int,int)" ,
						:slot = "cellPressedSlot()" ,
						:event = "cellPressed"
					] ,
					[ 	:signal = "currentCellChanged(int,int,int,int)" ,
						:slot = "currentCellChangedSlot()" ,
						:event = "currentCellChanged"
					] ,
					[ 	:signal = "currentItemChanged(QTableWidgetItem *,QTableWidgetItem *)" ,
						:slot = "currentItemChangedSlot()" ,
						:event = "currentItemChanged"
					] ,
					[ 	:signal = "itemActivated(QTableWidgetItem *)" ,
						:slot = "itemActivatedSlot()" ,
						:event = "itemActivated"
					] ,
					[ 	:signal = "itemChanged(QTableWidgetItem *)" ,
						:slot = "itemChangedSlot()" ,
						:event = "itemChanged"
					] ,
					[ 	:signal = "itemClicked(QTableWidgetItem *)" ,
						:slot = "itemClickedSlot()" ,
						:event = "itemClicked"
					] ,
					[ 	:signal = "itemDoubleClicked(QTableWidgetItem *)" ,
						:slot = "itemDoubleClickedSlot()" ,
						:event = "itemDoubleClicked"
					] ,
					[ 	:signal = "itemEntered(QTableWidgetItem *)" ,
						:slot = "itemEnteredSlot()" ,
						:event = "itemEntered"
					] ,
					[ 	:signal = "itemPressed(QTableWidgetItem *)" ,
						:slot = "itemPressedSlot()" ,
						:event = "itemPressed"
					] ,
					[ 	:signal = "itemSelectionChanged()" ,
						:slot = "itemSelectionChangedSlot()" ,
						:event = "itemSelectionChanged"
					]
				  ]
		] 
