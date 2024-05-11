RingQt_Update_QMediaPlayer_Class()


func RingQt_Update_QMediaPlayer_Class

	oMedia = new QMediaPlayer

	if ! isMethod(oMedia,:setMedia)
		addMethod(oMedia,:setMedia, func oURL {
			self.setSource(oURL)
		} )
	ok

	if ! isMethod(oMedia,:setVolume)
		addMethod(oMedia,:setVolume, func nVolume {
			oAudio = audioOutput()
			if isNULL(oAudio.pObject)
				oAudio = new QAudioOutput()
				self.setAudioOutput(oAudio)
			ok
			oAudio.setVolume(nVolume/100)
		} )
	ok

	if ! isMethod(oMedia,:isMuted)
		addMethod(oMedia,:isMuted, func  {
			oAudio = audioOutput()
			if isNULL(oAudio.pObject)
				oAudio = new QAudioOutput()
				self.setAudioOutput(oAudio)
			ok
			return oAudio.isMuted()
		} )
	ok

	if ! isMethod(oMedia,:setMuted)
		addMethod(oMedia,:setMuted, func lMuted {
			oAudio = audioOutput()
			if isNULL(oAudio.pObject)
				oAudio = new QAudioOutput()
				self.setAudioOutput(oAudio)
			ok
			oAudio.setMuted(lMuted)
		} )
	ok
