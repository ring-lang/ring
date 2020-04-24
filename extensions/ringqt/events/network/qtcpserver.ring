aClasses +	[	:name = "GTcpServer" ,
			:realname = "QTcpServer" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "acceptError(QAbstractSocket::SocketError)" ,
						:slot = "acceptErrorSlot()" ,
						:event = "acceptError"
					] ,
					[ 	:signal = "newConnection()" ,
						:slot = "newConnectionSlot()" ,
						:event = "newConnection"
					]
				  ]
		] 
