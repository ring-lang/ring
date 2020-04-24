aClasses +	[	:name = "GTreeWidget" ,
			:realname = "QTreeWidget" ,
			:events = [
					[ 	:signal = "collapsed(QModelIndex)" ,
						:slot = "collapsedSlot()" ,
						:event = "collapsed"
					] ,
					[ 	:signal = "expanded(QModelIndex)" ,
						:slot = "expandedSlot()" ,
						:event = "expanded"
					] ,
					[ 	:signal = "activated(QModelIndex)" ,
						:slot = "activatedSlot()" ,
						:event = "activated"
					] ,
					[ 	:signal = "clicked(QModelIndex)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					] ,
					[ 	:signal = "doubleClicked(QModelIndex)" ,
						:slot = "doubleClickedSlot()" ,
						:event = "doubleClicked"
					] ,
					[ 	:signal = "entered(QModelIndex)" ,
						:slot = "enteredSlot()" ,
						:event = "entered"
					] ,
					[ 	:signal = "pressed(QModelIndex)" ,
						:slot = "pressedSlot()" ,
						:event = "pressed"
					] ,
					[ 	:signal = "viewportEntered()" ,
						:slot = "viewportEnteredSlot()" ,
						:event = "viewportEntered"
					] ,
					[ 	:signal = "currentItemChanged(QTreeWidgetItem *,QTreeWidgetItem *)" ,
						:slot = "currentItemChangedSlot()" ,
						:event = "currentItemChanged"
					] ,
					[ 	:signal = "itemActivated(QTreeWidgetItem *,int)" ,
						:slot = "itemActivatedSlot()" ,
						:event = "itemActivated"
					] ,
					[ 	:signal = "itemChanged(QTreeWidgetItem *,int)" ,
						:slot = "itemChangedSlot()" ,
						:event = "itemChanged"
					] ,
					[ 	:signal = "itemClicked(QTreeWidgetItem *,int)" ,
						:slot = "itemClickedSlot()" ,
						:event = "itemClicked"
					] ,
					[ 	:signal = "itemCollapsed(QTreeWidgetItem *)" ,
						:slot = "itemCollapsedSlot()" ,
						:event = "itemCollapsed"
					] ,
					[ 	:signal = "itemDoubleClicked(QTreeWidgetItem * ,int)" ,
						:slot = "itemDoubleClickedSlot()" ,
						:event = "itemDoubleClicked"
					] ,
					[ 	:signal = "itemEntered(QTreeWidgetItem * ,int)" ,
						:slot = "itemEnteredSlot()" ,
						:event = "itemEntered"
					] ,
					[ 	:signal = "itemExpanded(QTreeWidgetItem *)" ,
						:slot = "itemExpandedSlot()" ,
						:event = "itemExpanded"
					] ,
					[ 	:signal = "itemPressed(QTreeWidgetItem * ,int)" ,
						:slot = "itemPressedSlot()" ,
						:event = "itemPressed"
					] ,
					[ 	:signal = "itemSelectionChanged()" ,
						:slot = "itemSelectionChangedSlot()" ,
						:event = "itemSelectionChanged"
					]
				  ]
		] 
