aClasses +	[	:name = "GBluetoothTransferReply" ,
			:realname = "QBluetoothTransferReply" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "error(QBluetoothTransferReply::TransferError)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "finished(QBluetoothTransferReply *)" ,
						:slot = "finishedSlot()" ,
						:event = "finished"
					],
					[ 	:signal = "transferProgress(qint64,qint64)" ,
						:slot = "transferProgressSlot()" ,
						:event = "transferProgress"
					]
				]
		]
