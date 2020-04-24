aClasses + [
		:name = "GTextToSpeech" ,
		:realname = "QTextToSpeech" ,
		:initpara = "QObject *",
		:events = [
				[ 	:signal = "localeChanged(const QLocale)" ,
					:slot = "localeChangedSlot()" ,
					:event = "localeChanged"
				],
				[ 	:signal = "pitchChanged(double)" ,
					:slot = "pitchChangedSlot()" ,
					:event = "pitchChanged"
				],
				[ 	:signal = "rateChanged(double)" ,
					:slot = "rateChangedSlot()" ,
					:event = "rateChanged"
				],
				[ 	:signal = "stateChanged(QTextToSpeech::State)" ,
					:slot = "stateChangedSlot()" ,
					:event = "stateChanged"
				],
				[ 	:signal = "voiceChanged(const QVoice)" ,
					:slot = "voiceChangedSlot()" ,
					:event = "voiceChanged"
				],
				[ 	:signal = "volumeChanged(double)" ,
					:slot = "volumeChangedSlot()" ,
					:event = "volumeChanged"
				]
		]
	]
