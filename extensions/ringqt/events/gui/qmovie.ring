aClasses + [
		:name = "GMovie" ,
		:realname = "QMovie" ,
		:headerfile = "QtGui",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "error(QImageReader::ImageReaderError)" ,
					:slot = "errorSlot()" ,
					:event = "error"
				],
				[ 	:signal = "finished()" ,
					:slot = "finishedSlot()" ,
					:event = "finished"
				],
				[ 	:signal = "frameChanged(int)" ,
					:slot = "frameChangedSlot()" ,
					:event = "frameChanged"
				],
				[ 	:signal = "resized(const QSize)" ,
					:slot = "resizedSlot()" ,
					:event = "resized"
				],
				[ 	:signal = "started()" ,
					:slot = "startedSlot()" ,
					:event = "started"
				],
				[ 	:signal = "stateChanged(QMovie::MovieState)" ,
					:slot = "stateChangedSlot()" ,
					:event = "stateChanged"
				],
				[ 	:signal = "updated(const QRect)" ,
					:slot = "updatedSlot()" ,
					:event = "updated"
				]
		]
	]