aClasses +	[	:name = "GDrag" ,
			:realname = "QDrag" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "actionChanged(Qt::DropAction)" ,
						:slot = "actionChangedSlot()" ,
						:event = "actionChanged"
					],
					[ 	:signal = "targetChanged(QObject *)" ,
						:slot = "targetChangedSlot()" ,
						:event = "targetChanged"
					]
			]
		]
