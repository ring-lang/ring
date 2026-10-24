aClasses +	[	:name = "GBluetoothLocalDevice" ,
			:realname = "QBluetoothLocalDevice" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "deviceConnected(const QBluetoothAddress)" ,
						:slot = "deviceConnectedSlot()" ,
						:event = "deviceConnected"
					],
					[ 	:signal = "deviceDisconnected(const QBluetoothAddress)" ,
						:slot = "deviceDisconnectedSlot()" ,
						:event = "deviceDisconnected"
					],
					[ 	:signal = "error(QBluetoothLocalDevice::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "hostModeStateChanged(QBluetoothLocalDevice::HostMode)" ,
						:slot = "hostModeStateChangedSlot()" ,
						:event = "hostModeStateChanged"
					],
					[ 	:signal = "pairingDisplayConfirmation(const QBluetoothAddress,QString)" ,
						:slot = "pairingDisplayConfirmationSlot()" ,
						:event = "pairingDisplayConfirmation"
					],
					[ 	:signal = "pairingDisplayPinCode(const QBluetoothAddress,QString)" ,
						:slot = "pairingDisplayPinCodeSlot()" ,
						:event = "pairingDisplayPinCode"
					],
					[ 	:signal = "pairingFinished(const QBluetoothAddress,QBluetoothLocalDevice::Pairing)" ,
						:slot = "pairingFinishedSlot()" ,
						:event = "pairingFinished"
					]
				]
		]
