aClasses +	[	:name = "GGeoPositionInfoSource" ,
			:realname = "QGeoPositionInfoSource" ,
			:initpara = "QObject *",
			:events = [
					[ 	:signal = "error(QGeoPositionInfoSource::Error)" ,
						:slot = "errorSlot()" ,
						:event = "error"
					],
					[ 	:signal = "positionUpdated(const QGeoPositionInfo)" ,
						:slot = "positionUpdatedSlot()" ,
						:event = "positionUpdated"
					],
					[ 	:signal = "updateTimeout()" ,
						:slot = "updateTimeoutSlot()" ,
						:event = "updateTimeout"
					]
			]
		]
	    
