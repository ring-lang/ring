aClasses +	[	:name = "GToolButton" ,
			:realname = "QToolButton" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "triggered(QAction *)" ,
						:slot = "triggeredSlot()" ,
						:event = "triggered"
					],
					[ 	:signal = "clicked()" ,
						:slot = "clickedSlot()" ,
						:event = "Click"
					]
				  ]
		]
