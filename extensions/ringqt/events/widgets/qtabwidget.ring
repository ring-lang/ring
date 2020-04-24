aClasses +	[	:name = "GTabWidget" ,
			:realname = "QTabWidget" ,
			:events = [
					[ 	:signal = "currentChanged(int)" ,
						:slot = "currentChangedSlot()" ,
						:event = "currentChanged"
					] ,
					[ 	:signal = "tabCloseRequested(int)" ,
						:slot = "tabCloseRequestedSlot()" ,
						:slotparaconnect = "int",
						:slotparafunction = "int p1",
						:slotparacode = SlotParaGetNumber(),
						:event = "tabCloseRequested"
					]
				  ]
		] 
