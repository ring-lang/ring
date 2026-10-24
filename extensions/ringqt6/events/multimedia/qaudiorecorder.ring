aClasses +	[	:name = "GAudioRecorder" ,
			:realname = "QAudioRecorder",
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "audioInputChanged(QString)" ,
						:slot = "audioInputChangedSlot()" ,
						:event = "audioInputChanged"
					] ,
					[ 	:signal = "availableAudioInputsChanged()" ,
						:slot = "availableAudioInputsChangedSlot()" ,
						:event = "availableAudioInputsChanged"
					]
				  ]
		] 
