aClasses +	[	:name = "GUdpSocket" ,
			:realname = "QUdpSocket",
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
					[ 	:signal = "stateChanged(QAbstractSocket::SocketState)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					] ,
					[ 	:signal = "readyRead()" ,
						:slot = "readyReadSlot()" ,
						:event = "readyRead"
					]
				  ]
		] 
