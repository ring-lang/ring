aClasses +	[	:name = "GBluetoothServer" ,
			:realname = "QBluetoothServer" ,
			:initpara = "QBluetoothServiceInfo::Protocol x,QObject *",
			:initparaparent = "x,",
			:events = [
					[ 	:signal = "error(QBluetoothServer::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "newConnection()" ,
						:slot = "newConnectionSlot()" ,
						:event = "newConnection"
					]
				]
		]
