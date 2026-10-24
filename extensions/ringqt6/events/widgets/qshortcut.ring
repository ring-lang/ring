aClasses +	[	:name = "GShortcut" ,
			:realname = "QShortcut" ,
			:useqobject = True ,
			:CustomCodeAfterInclude = "#include <QWidget>" ,
			:events = [
					[ 	:signal = "activated()" ,
						:slot = "activatedSlot()" ,
						:event = "activated"
					] ,
					[ 	:signal = "activatedAmbiguously()" ,
						:slot = "activatedAmbiguouslySlot()" ,
						:event = "activatedAmbiguously"
					]
				  ]
		]
