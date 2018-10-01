aClasses + [
		:name = "GPrintPreviewDialog" ,
		:realname = "QPrintPreviewDialog" ,
			:initpara = "QPrinter *",
		:events = [
				[ 	:signal = "paintRequested(QPrinter *)" ,
					:slot = "paintRequestedSlot()" ,
					:event = "paintRequested"
				]
		]
	]
