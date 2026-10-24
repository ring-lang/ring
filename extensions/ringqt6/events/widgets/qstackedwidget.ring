aClasses +	[	:name = "GStackedWidget" ,
			:realname = "QStackedWidget" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "currentChanged(int)" ,
						:slot = "currentChangedSlot()" ,
						:event = "currentChanged"
					],
					[ 	:signal = "widgetRemoved(int)" ,
						:slot = "widgetRemovedSlot()" ,
						:event = "widgetRemoved"
					]
				]
		]
