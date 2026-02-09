aClasses +	[	:name = "GNetworkConfigurationManager" ,
			:realname = "QNetworkConfigurationManager" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "configurationAdded(QNetworkConfiguration)" ,
						:slot = "configurationAddedSlot()" ,
						:event = "configurationAdded"
					] ,
					[ 	:signal = "configurationChanged(QNetworkConfiguration)" ,
						:slot = "configurationChangedSlot()" ,
						:event = "configurationChanged"
					] ,
					[ 	:signal = "configurationRemoved(QNetworkConfiguration)" ,
						:slot = "configurationRemovedSlot()" ,
						:event = "configurationRemoved"
					] ,
					[ 	:signal = "onlineStateChanged(bool)" ,
						:slot = "onlineStateChangedSlot()" ,
						:event = "onlineStateChanged"
					] ,
					[ 	:signal = "updateCompleted()" ,
						:slot = "updateCompletedSlot()" ,
						:event = "updateCompleted"
					]
				  ]
		] 
