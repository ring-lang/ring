aClasses + [
		:name = "GFontDialog" ,
		:realname = "QFontDialog" ,
		:headerfile = "",
		:initpara = "QWidget * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "currentFontChanged(const QFont)" ,
					:slot = "currentFontChangedSlot()" ,
					:event = "currentFontChanged"
				],
				[ 	:signal = "fontSelected(const QFont)" ,
					:slot = "fontSelectedSlot()" ,
					:event = "fontSelected"
				]
		]
	]
