aClasses +	[	:name = "GAudioInput" ,
			:realname = "QAudioInput",
			:initpara = "const QAudioFormat &",
			:events = [
					[ 	:signal = "stateChanged(QAudio::State)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					] ,
					[ 	:signal = "notify()" ,
						:slot = "notifySlot()" ,
						:event = "notify"
					]
				  ]
		] 
