aClasses +	[	:name = "GTextBrowser" ,
			:realname = "QTextBrowser" ,
			:initpara = "QWidget *",
			:events = [
					[ 	:signal = "anchorClicked(const QUrl)" ,
						:slot = "anchorClickedSlot()" ,
						:event = "anchorClicked"
					],
					[ 	:signal = "backwardAvailable(bool)" ,
						:slot = "backwardAvailableSlot()" ,
						:event = "backwardAvailable"
					],
					[ 	:signal = "forwardAvailable(bool)" ,
						:slot = "forwardAvailableSlot()" ,
						:event = "forwardAvailable"
					],
					[ 	:signal = "highlighted(const QString)" ,
						:slot = "highlightedSlot()" ,
						:event = "highlighted"
					],
					[ 	:signal = "historyChanged()" ,
						:slot = "historyChangedSlot()" ,
						:event = "historyChanged"
					],
					[ 	:signal = "sourceChanged(const QUrl)" ,
						:slot = "sourceChangedSlot()" ,
						:event = "sourceChanged"
					]
				]
		]
