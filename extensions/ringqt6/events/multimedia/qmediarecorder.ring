aClasses +	[	:name = "GMediaRecorder" ,
			:realname = "QMediaRecorder",
			:initpara = "QMediaObject *",
			:events = [
					[ 	:signal = "actualLocationChanged(QUrl)" ,
						:slot = "actualLocationChangedSlot()" ,
						:event = "actualLocationChanged"
					] ,
					[ 	:signal = "durationChanged(qint64)" ,
						:slot = "durationChangedSlot()" ,
						:event = "durationChanged"
					] ,
					[ 	:signal = "error(QMediaRecorder::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					] ,
					[ 	:signal = "metaDataChanged()" ,
						:slot = "metaDataChangedSlot()" ,
						:event = "metaDataChanged"
					] ,
					[ 	:signal = "mutedChanged(bool)" ,
						:slot = "mutedChangedSlot()" ,
						:event = "mutedChanged"
					] ,
					[ 	:signal = "stateChanged(QMediaRecorder::State)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					] ,
					[ 	:signal = "statusChanged(QMediaRecorder::Status)" ,
						:slot = "statusChangedSlot()" ,
						:event = "statusChanged"
					] ,
					[ 	:signal = "volumeChanged(qreal)" ,
						:slot = "volumeChangedSlot()" ,
						:event = "volumeChanged"
					]
				  ]
		] 
