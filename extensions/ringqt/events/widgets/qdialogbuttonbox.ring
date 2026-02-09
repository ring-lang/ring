aClasses +	[	:name = "GDialogButtonBox" ,
			:realname = "QDialogButtonBox" ,
			:events = [
					[ 	:signal = "accepted()" ,
						:slot = "acceptedSlot()" ,
						:event = "accepted"
					] ,
					[ 	:signal = "rejected()" ,
						:slot = "rejectedSlot()" ,
						:event = "rejected"
					] ,
					[ 	:signal = "clicked(QAbstractButton *)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					] ,
					[ 	:signal = "helpRequested()" ,
						:slot = "helpRequestedSlot()" ,
						:event = "helpRequested"
					]
				  ]
		] 
