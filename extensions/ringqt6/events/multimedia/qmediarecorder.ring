aClasses +	[	:name = "GMediaRecorder" ,
			:realname = "QMediaRecorder",
			:useqobject = True ,
			:events = [
					[ 	:signal = "actualLocationChanged(QUrl)" ,
						:slot = "actualLocationChangedSlot()" ,
						:event = "actualLocationChanged"
					] ,
					[ 	:signal = "durationChanged(qint64)" ,
						:slot = "durationChangedSlot()" ,
						:event = "durationChanged"
					] ,
					[ 	:signal = "recorderStateChanged(QMediaRecorder::RecorderState)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					] ,
					[ 	:signal = "errorOccurred(QMediaRecorder::Error,const QString &)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					]
				  ]
		]
