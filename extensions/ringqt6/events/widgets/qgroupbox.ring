aClasses + [
		:name = "GGroupBox" ,
		:realname = "QGroupBox" ,
		:headerfile = "",
		:initpara = "QWidget * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "clicked(bool checked =)" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "toggled(bool)" ,
					:slot = "toggledSlot()" ,
					:event = "toggled"
				]
		]
	]