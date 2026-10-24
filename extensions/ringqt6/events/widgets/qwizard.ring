aClasses +	[	:name = "GWizard" ,
			:realname = "QWizard" ,
			:events = [
					[ 	:signal = "currentIdChanged(int)" ,
						:slot = "currentIdChangedSlot()" ,
						:event = "currentIdChanged"
					] ,
					[ 	:signal = "pageAdded(int)" ,
						:slot = "pageAddedSlot()" ,
						:event = "pageAdded"
					] ,
					[ 	:signal = "pageRemoved(int)" ,
						:slot = "pageRemovedSlot()" ,
						:event = "pageRemoved"
					]
				  ]
		] 
