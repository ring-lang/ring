aClasses +	[	:name = "GBluetoothSocket" ,
			:realname = "QBluetoothSocket" ,
			:initpara = "QBluetoothServiceInfo::Protocol x,QObject *",
			:initparaparent = "x,",
			:events = [
					[ 	:signal = "connected()" ,
						:slot = "connectedSlot()" ,
						:event = "connected"
					],
					[ 	:signal = "disconnected()" ,
						:slot = "disconnectedSlot()" ,
						:event = "disconnected"
					],
					[ 	:signal = "error(QBluetoothSocket::SocketError)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "stateChanged(QBluetoothSocket::SocketState)" ,
						:slot = "stateChangedSlot()" ,
						:event = "stateChanged"
					]
				]
		]
