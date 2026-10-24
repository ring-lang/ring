aClasses +	[	:name = "GVideoWidget" ,
			:realname = "QVideoWidget" ,
			:events = [
					[ 	:signal = "brightnessChanged(int)" ,
						:slot = "brightnessChangedSlot()" ,
						:event = "brightnessChanged"
					] ,
					[ 	:signal = "contrastChanged(int)" ,
						:slot = "contrastChangedSlot()" ,
						:event = "contrastChanged"
					] ,
					[ 	:signal = "fullScreenChanged(bool)" ,
						:slot = "fullScreenChangedSlot()" ,
						:event = "fullScreenChanged"
					] ,
					[ 	:signal = "hueChanged(int)" ,
						:slot = "hueChangedSlot()" ,
						:event = "hueChanged"
					] ,
					[ 	:signal = "saturationChanged(int)" ,
						:slot = "saturationChangedSlot()" ,
						:event = "saturationChanged"
					]
				  ]
		] 
