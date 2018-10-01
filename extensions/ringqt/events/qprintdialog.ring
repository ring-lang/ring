aClasses + [
		:name = "GPrintDialog" ,
		:realname = "QPrintDialog" ,
		:initpara = "QPrinter *,QWidget *",
		:events = [
				[ 	:signal = "accepted(QPrinter *)" ,
					:slot = "acceptedSlot()" ,
					:event = "accepted"
				]
		]
	]
