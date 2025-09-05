load "gl_libsdl.ring"

func util_fexists cFileName

	return isAndroid() or fexists(cFileName)