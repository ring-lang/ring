# 2023, Mahmoud Fayed

C_DATA_FILE  = 1
C_DATA_IMAGE = 2
C_DATA_TEX   = 3

resources = new resources

Class Resources 

	aData = []	#	[Image File, Image Data, Texture]

	func Image cImage
		nMax = len(aData)
		if nMax > 0
			for t=1 to nMax 
				if aData[t][C_DATA_FILE] = cImage 
					unloadImage(aData[t][C_DATA_IMAGE].oData)
					aData[t][C_DATA_IMAGE] = loadImage(cImage)
					unloadtexture(aData[t][C_DATA_TEX])
					aData[t][C_DATA_TEX] =  LoadTextureFromImage(aData[t][C_DATA_IMAGE]) 
					return aData[t][C_DATA_IMAGE]
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
