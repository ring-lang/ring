aClasses +	[	:name = "GDateTimeEdit" ,
			:realname = "QDateTimeEdit" ,
			:events = [
					[ 	:signal = "dateChanged(QDate)" ,
						:slot = "dateChangedSlot()" ,
						:event = "dateChanged"
					],
					[ 	:signal = "dateTimeChanged(QDateTime)" ,
						:slot = "dateTimeChangedSlot()" ,
						:event = "dateTimeChanged"
					],
					[ 	:signal = "timeChanged(QTime)" ,
						:slot = "timeChangedSlot()" ,
						:event = "timeChanged"
					]
				  ]
		] 
