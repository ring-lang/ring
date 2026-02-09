aClasses +	[	:name = "GVideoProbe" ,
			:realname = "QVideoProbe",
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "videoFrameProbed(QVideoFrame)" ,
						:slot = "videoFrameProbedSlot()" ,
						:event = "videoFrameProbed"
					] ,
					[ 	:signal = "flush()" ,
						:slot = "flushSlot()" ,
						:event = "flush"
					]
				  ]
		] 
