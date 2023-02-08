# 2023, Mahmoud Fayed

C_DATA_FILE  = 1
C_DATA_IMAGE = 2
C_DATA_TEX   = 3

resources = new resources

Class Resources 

	aData = []	#	[Image File, Image Data, Texture]

	func Image cImage
		if len(aData) > 0
			for aList in aData 
				if aList[C_DATA_FILE] = cImage 
					unloadImage(aList[C_DATA_IMAGE])
					aList[C_DATA_IMAGE] = loadImage(cImage)
					unloadtexture(aList[C_DATA_TEX])
					aList[C_DATA_TEX] =  LoadTextureFromImage(aList[C_DATA_IMAGE]) 
					return aList[C_DATA_IMAGE]
				ok
			next 
		ok
		oImage = loadImage(cImage)
		oTex = LoadTextureFromImage(oImage)
		aData + [cImage,oImage,oTex]
		return oImage

	func Texture oImage
		if len(aData) > 0
			for aList in aData 
				if aList[C_DATA_IMAGE].oData = oImage.oData
					unLoadTexture(aList[C_DATA_TEX])
					aList[C_DATA_TEX] = LoadTextureFromImage(oImage)
					return aList[C_DATA_TEX] 
				ok
			next
		ok
