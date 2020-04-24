aClasses +	[	:name = "GWebView" ,
			:realname = "QWebView" ,
			:events = [
					[ 	:signal = "loadFinished(bool)" ,
						:slot = "loadFinishedSlot()" ,
						:event = "loadFinished"
					] ,
					[ 	:signal = "loadProgress(int)" ,
						:slot = "loadProgressSlot()" ,
						:event = "loadProgress"
					] ,
					[ 	:signal = "loadStarted()" ,
						:slot = "loadStartedSlot()" ,
						:event = "loadStarted"
					] ,
					[ 	:signal = "selectionChanged()" ,
						:slot = "selectionChangedSlot()" ,
						:event = "selectionChanged"
					] ,					
					[ 	:signal = "titleChanged(QString)" ,
						:slot = "titleChangedSlot()" ,
						:event = "titleChanged"
					] ,
					[ 	:signal = "urlChanged(QUrl)" ,
						:slot = "urlChangedSlot()" ,
						:event = "urlChanged"
					]
				  ]
		] 
