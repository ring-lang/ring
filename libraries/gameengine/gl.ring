load "gl_allegro.ring"

func util_fexists cFileName

	return isAndroid() or fexists(cFileName)
