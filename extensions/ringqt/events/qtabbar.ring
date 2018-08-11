aClasses +	[	:name = "GTabBar" ,
			:realname = "QTabBar" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "currentChanged(int)" ,
						:slot = "currentChangedSlot()" ,
						:event = "currentChanged"
					],
					[ 	:signal = "tabCloseRequested(int)" ,
						:slot = "tabCloseRequestedSlot()" ,
						:event = "tabCloseRequested"
					],
					[ 	:signal = "tabMoved(int,int)" ,
						:slot = "tabMovedSlot()" ,
						:event = "tabMoved"
					]
				]
		]
