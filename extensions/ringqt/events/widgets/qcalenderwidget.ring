aClasses +	[	:name = "GCalendarWidget" ,
			:realname = "QCalendarWidget" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "activated(const QDate)" ,
						:slot = "activatedSlot()" ,
						:event = "activated"
					],
					[ 	:signal = "clicked(const QDate)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					],
					[ 	:signal = "currentPageChanged(int,int)" ,
						:slot = "currentPageChangedSlot()" ,
						:event = "currentPageChanged"
					],
					[ 	:signal = "selectionChanged()" ,
						:slot = "selectionChangedSlot()" ,
						:event = "selectionChanged"
					]
				]
		]
