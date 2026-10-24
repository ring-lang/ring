aClasses +	[	:name = "GAction" ,
			:realname = "QAction" ,
			:useqobject = True,
			:CustomCodeAfterInclude = "#include <QWidget>" ,
			:events = [
					[ 	:signal = "triggered()" ,
						:slot = "clickedSlot()" ,
						:event = "Click"
					]
				  ]
		]
