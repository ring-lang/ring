aClasses +	[	:name = "GHeaderView" ,
			:initpara = "Qt::Orientation x, QWidget *",
			:initparaparent = "x,",
			:realname = "QHeaderView" ,
			:events = [
					[ 	:signal = "geometriesChanged()" ,
						:slot = "geometriesChangedSlot()" ,
						:event = "geometriesChanged"
					] ,
					[ 	:signal = "sectionClicked(int)" ,
						:slot = "sectionClickedSlot()" ,
						:event = "sectionClicked",
						:slotparaconnect = "int",
						:slotparafunction = "int p1",
						:slotparacode = SlotParaGetNumber()
					],
					[ 	:signal = "sectionCountChanged(int, int)" ,
						:slot = "sectionCountChangedSlot()" ,
						:event = "sectionCountChanged"
					] ,			
					[ 	:signal = "sectionDoubleClicked(int)" ,
						:slot = "sectionDoubleClickedSlot()" ,
						:event = "sectionDoubleClicked"
					] ,			
					[ 	:signal = "sectionEntered(int)" ,
						:slot = "sectionEnteredSlot()" ,
						:event = "sectionEntered"
					] ,			
					[ 	:signal = "sectionHandleDoubleClicked(int)" ,
						:slot = "sectionHandleDoubleClickedSlot()" ,
						:event = "sectionHandleDoubleClicked"
					] ,		
					[ 	:signal = "sectionMoved(int, int, int)" ,
						:slot = "sectionMovedSlot()" ,
						:event = "sectionMoved"
					] ,		
					[ 	:signal = "sectionPressed(int)" ,
						:slot = "sectionPressedSlot()" ,
						:event = "sectionPressed"
					] ,		
					[ 	:signal = "sectionResized(int, int, int)" ,
						:slot = "sectionResizedSlot()" ,
						:event = "sectionResized"
					] ,		
					[ 	:signal = "sortIndicatorChanged(int, Qt::SortOrder)" ,
						:slot = "sortIndicatorChangedSlot()" ,
						:event = "sortIndicatorChanged"
					] 		
			  ]
		] 
