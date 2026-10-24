aClasses +	[	:name = "GProcess" ,
			:realname = "QProcess" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "readyReadStandardError()" ,
						:slot = "readyReadStandardErrorSlot()" ,
						:event = "readyReadStandardError"
					] ,
					[ 	:signal = "readyReadStandardOutput()" ,
						:slot = "readyReadStandardOutputSlot()" ,
						:event = "readyReadStandardOutput"
					] 
				  ]
		]
