aClasses +	[	:name = "GStackedLayout" ,
			:realname = "QStackedLayout" ,
			:events = [
					[ 	:signal = "currentChanged(int)" ,
						:slot = "currentChangedSlot()" ,
						:event = "currentChanged"
					] ,
					[ 	:signal = "widgetRemoved(int)" ,
						:slot = "widgetRemovedSlot()" ,
						:event = "widgetRemoved"
					]
				  ]
		] 
