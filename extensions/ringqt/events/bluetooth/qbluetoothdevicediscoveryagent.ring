aClasses +	[	:name = "GBluetoothDeviceDiscoveryAgent" ,
			:realname = "QBluetoothDeviceDiscoveryAgent" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "canceled()" ,
						:slot = "canceledSlot()" ,
						:event = "canceled"
					],
					[ 	:signal = "deviceDiscovered(const QBluetoothDeviceInfo)" ,
						:slot = "deviceDiscoveredSlot()" ,
						:event = "deviceDiscovered"
					],
					[ 	:signal = "error(QBluetoothDeviceDiscoveryAgent::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "finished()" ,
						:slot = "finishedSlot()" ,
						:event = "finished"
					]
				]
		]
