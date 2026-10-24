aClasses +	[	:name = "GAudioProbe" ,
			:realname = "QAudioProbe",
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "audioBufferProbed(QAudioBuffer)" ,
						:slot = "audioBufferProbedSlot()" ,
						:event = "audioBufferProbed"
					] ,
					[ 	:signal = "flush()" ,
						:slot = "flushSlot()" ,
						:event = "flush"
					]
				  ]
		] 
