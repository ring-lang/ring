aClasses +	[	:name = "GSslSocket" ,
			:realname = "QSslSocket",
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "encrypted()" ,
						:slot = "encryptedSlot()" ,
						:event = "encrypted"
					] ,
					[ 	:signal = "encryptedBytesWritten(qint64)" ,
						:slot = "encryptedBytesWrittenSlot()" ,
						:event = "encryptedBytesWritten"
					] ,
					[ 	:signal = "modeChanged(QSslSocket::SslMode)" ,
						:slot = "modeChangedSlot()" ,
						:event = "modeChanged"
					] ,
					[ 	:signal = "peerVerifyError(QSslError)" ,
						:slot = "peerVerifyErrorSlot()" ,
						:event = "peerVerifyError"
					] ,
					[ 	:signal = "sslErrors(QList<QSslError>)" ,
						:slot = "sslErrorsSlot()" ,
						:event = "sslErrors"
					]
				  ]
		] 
