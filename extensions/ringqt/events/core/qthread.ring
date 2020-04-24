aClasses +	[	:name = "GThread" ,
			:realname = "QThread" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "started()" ,
						:slot = "startedSlot()" ,
						:event = "Started",
						:thread = True
					] ,
					[ 	:signal = "finished()" ,
						:slot = "finishedSlot()" ,
						:event = "Finished",
						:thread = True
					] 
				  ]
		]
