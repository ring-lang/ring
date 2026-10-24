aClasses +	[	:name = "GSerialPort" ,
			:realname = "QSerialPort" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "baudRateChanged(qint32,QSerialPort::Directions)" ,
						:slot = "baudRateChangedSlot()" ,
						:event = "baudRateChanged"
					],
					[ 	:signal = "breakEnabledChanged(bool)" ,
						:slot = "breakEnabledChangedSlot()" ,
						:event = "breakEnabledChanged"
					],
					[ 	:signal = "dataBitsChanged(QSerialPort::DataBits)" ,
						:slot = "dataBitsChangedSlot()" ,
						:event = "dataBitsChanged"
					],
					[ 	:signal = "dataTerminalReadyChanged(bool)" ,
						:slot = "dataTerminalReadyChangedSlot()" ,
						:event = "dataTerminalReadyChanged"
					],
					[ 	:signal = "error(QSerialPort::SerialPortError)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "flowControlChanged(QSerialPort::FlowControl)" ,
						:slot = "flowControlChangedSlot()" ,
						:event = "flowControlChanged"
					],
					[ 	:signal = "parityChanged(QSerialPort::Parity)" ,
						:slot = "parityChangedSlot()" ,
						:event = "parityChanged"
					],
					[ 	:signal = "requestToSendChanged(bool)" ,
						:slot = "requestToSendChangedSlot()" ,
						:event = "requestToSendChanged"
					],
					[ 	:signal = "stopBitsChanged(QSerialPort::StopBits)" ,
						:slot = "stopBitsChangedSlot()" ,
						:event = "stopBitsChanged"
					]
			]
		]
