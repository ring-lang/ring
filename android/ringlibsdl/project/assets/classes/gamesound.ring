Class Sound from gameobject

	file sample  csoundfile sampleid
	playing = false
	type = 0
	once = false
	func setfile cfilename
		sample = gl_load_sample(cfilename)
		csoundfile = cfilename

	func playSound
		if not playing
			sampleid = gl_new_glib_sample_id()
			if once
				gl_play_sample(sample, 1.0, 0.0,1.0,GL_PLAYMODE_ONCE,sampleid)	
			else
				gl_play_sample(sample, 1.0, 0.0,1.0,GL_PLAYMODE_LOOP,sampleid)
			ok
			playing = true
		ok

	func delete
		if playing 
			playing = false
			gl_destroy_glib_sample_id(sampleid)
			gl_destroy_sample(sample)	
		ok
	func braceend
		playsound()
