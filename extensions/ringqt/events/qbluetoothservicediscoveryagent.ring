aClasses +	[	:name = "GBluetoothServiceDiscoveryAgent" ,
			:realname = "QBluetoothServiceDiscoveryAgent" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "canceled()" ,
						:slot = "canceledSlot()" ,
						:event = "canceled"
					],
					[ 	:signal = "error(QBluetoothServiceDiscoveryAgent::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "finished()" ,
						:slot = "finishedSlot()" ,
						:event = "finished"
					],
					[ 	:signal = "serviceDiscovered(const QBluetoothServiceInfo)" ,
						:slot = "serviceDiscoveredSlot()" ,
						:event = "serviceDiscovered"
					]
				]
		]
