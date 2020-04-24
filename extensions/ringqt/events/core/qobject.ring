aClasses +	[	:name = "GTcpSocket" ,
			:realname = "QTcpSocket" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "connected()" ,
						:slot = "connectedSlot()" ,
						:event = "connected"
					] ,
					[ 	:signal = "disconnected()" ,
						:slot = "disconnectedSlot()" ,
						:event = "disconnected"
					] ,
					[ 	:signal = "error(QAbstractSocket::SocketError)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					] ,
					[ 	:signal = "hostFound()" ,
						:slot = "hostFoundSlot()" ,
						:event = "hostFound"
					] ,
					[ 	:signal = "proxyAuthenticationRequired(QNetworkProxy,QAuthenticator *)" ,
						:slot = "proxyAuthenticationRequiredSlot()" ,
						:event = "proxyAuthenticationRequired"
					] ,
					[ 	:signal = "stateChanged(QAbstractSocket::SocketState)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					] ,
					[ 	:signal = "aboutToClose()" ,
						:slot = "aboutToCloseSlot()" ,
						:event = "aboutToClose"
					] ,
					[ 	:signal = "bytesWritten(qint64)" ,
						:slot = "bytesWrittenSlot()" ,
						:event = "bytesWritten"
					] ,
					[ 	:signal = "readChannelFinished()" ,
						:slot = "readChannelFinishedSlot()" ,
						:event = "readChannelFinished"
					] ,
					[ 	:signal = "readyRead()" ,
						:slot = "readyReadSlot()" ,
						:event = "readyRead"
					]
				  ]
		]
