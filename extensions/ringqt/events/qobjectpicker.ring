aClasses + [
		:name = "GObjectPicker" ,
		:realname = "Qt3DRender::QObjectPicker" ,
		:initpara = "Qt3DCore::QNode *",
		:events = [
				[ 	:signal = "clicked(Qt3DRender::QPickEvent *)" ,
					:slot = "clickedSlot()" ,
					:event = "clicked"
				],
				[ 	:signal = "containsMouseChanged(bool)" ,
					:slot = "containsMouseChangedSlot()" ,
					:event = "containsMouseChanged"
				],
				[ 	:signal = "dragEnabledChanged(bool)" ,
					:slot = "dragEnabledChangedSlot()" ,
					:event = "dragEnabledChanged"
				],
				[ 	:signal = "entered()" ,
					:slot = "enteredSlot()" ,
					:event = "entered"
				],
				[ 	:signal = "exited()" ,
					:slot = "exitedSlot()" ,
					:event = "exited"
				],
				[ 	:signal = "hoverEnabledChanged(bool)" ,
					:slot = "hoverEnabledChangedSlot()" ,
					:event = "hoverEnabledChanged"
				],
				[ 	:signal = "moved(Qt3DRender::QPickEvent *)" ,
					:slot = "movedSlot()" ,
					:event = "moved"
				],
				[ 	:signal = "pressed(Qt3DRender::QPickEvent *)" ,
					:slot = "pressedSlot()" ,
					:event = "pressed"
				],
				[ 	:signal = "pressedChanged(bool)" ,
					:slot = "pressedChangedSlot()" ,
					:event = "pressedChanged"
				],
				[ 	:signal = "released(Qt3DRender::QPickEvent *)" ,
					:slot = "releasedSlot()" ,
					:event = "released"
				]
		]
	]
