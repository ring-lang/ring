aClasses +	[	:name = "GNetworkAccessManager" ,
			:realname = "QNetworkAccessManager" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "finished(QNetworkReply*)" ,
						:slot = "finishedSlot()" ,
						:event = "finished",
						:slotparaconnect = "QNetworkReply*",
						:slotparafunction = "QNetworkReply *p1",
						:slotparacode = SlotParaGetPointer("QNetworkReply *")
					] 
				  ]
		]
