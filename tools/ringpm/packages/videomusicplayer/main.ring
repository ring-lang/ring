func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "VideoMusicPlayer Package"
	? copy("=",C_LINESIZE)
	? "VideoMusicPlayer package for the Ring programming language"
	? "See the folder : ring/applications/videomusicplayer"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/videomusicplayer")
	system("ring AA-Video-Music-Player.ring")
	chdir(cDir)