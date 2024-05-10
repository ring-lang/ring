RingQt_Update_QMediaPlayer_Class()


func RingQt_Update_QMediaPlayer_Class
	oMedia = new QMediaPlayer
	if ! isMethod(oMedia,:setMedia)
		addMethod(oMedia,:setMedia, func oURL {
			self.setSource(oURL)
		} )
	ok