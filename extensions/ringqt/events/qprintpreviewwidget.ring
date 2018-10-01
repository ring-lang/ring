aClasses + [
		:name = "GPrintPreviewWidget" ,
		:realname = "QPrintPreviewWidget" ,
		:initpara = "QPrinter *",
		:events = [
				[ 	:signal = "paintRequested(QPrinter *)" ,
					:slot = "paintRequestedSlot()" ,
					:event = "paintRequested"
				],
				[ 	:signal = "previewChanged()" ,
					:slot = "previewChangedSlot()" ,
					:event = "previewChanged"
				]
		]
	]
