aClasses +	[	:name = "GSoundEffect" ,
			:realname = "QSoundEffect",
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "categoryChanged()" ,
						:slot = "categoryChangedSlot()" ,
						:event = "categoryChanged"
					] ,
					[ 	:signal = "loadedChanged()" ,
						:slot = "loadedChangedSlot()" ,
						:event = "loadedChanged"
					] ,
					[ 	:signal = "loopCountChanged()" ,
						:slot = "loopCountChangedSlot()" ,
						:event = "loopCountChanged"
					] ,
					[ 	:signal = "loopsRemainingChanged()" ,
						:slot = "loopsRemainingChangedSlot()" ,
						:event = "loopsRemainingChanged"
					] ,
					[ 	:signal = "mutedChanged()" ,
						:slot = "mutedChangedSlot()" ,
						:event = "mutedChanged"
					] ,
					[ 	:signal = "playingChanged()" ,
						:slot = "playingChangedSlot()" ,
						:event = "playingChanged"
					] ,
					[ 	:signal = "sourceChanged()" ,
						:slot = "sourceChangedSlot()" ,
						:event = "sourceChanged"
					] ,
					[ 	:signal = "statusChanged()" ,
						:slot = "statusChangedSlot()" ,
						:event = "statusChanged"
					] ,
					[ 	:signal = "volumeChanged()" ,
						:slot = "volumeChangedSlot()" ,
						:event = "volumeChanged"
					]
				  ]
		] 
