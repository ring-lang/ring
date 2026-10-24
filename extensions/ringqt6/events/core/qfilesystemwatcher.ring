aClasses +	[	:name = "GFileSystemWatcher" ,
			:realname = "QFileSystemWatcher" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "directoryChanged(QString)" ,
						:slot = "directoryChangedSlot()" ,
						:event = "directoryChanged"
					] ,
					[ 	:signal = "fileChanged(QString)" ,
						:slot = "fileChangedSlot()" ,
						:event = "fileChanged"
					]
				  ]
		] 
